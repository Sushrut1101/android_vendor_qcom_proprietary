/*
 * Copyright (c) 2012-2014, Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 *
 * Not a Contribution, Apache license notifications and license are retained
 * for attribution purposes only.
 *
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.qualcomm.simcontacts;

import java.util.ArrayList;
import java.util.HashMap;

import android.accounts.Account;
import android.accounts.AccountManager;
import android.app.Service;
import android.content.AsyncQueryHandler;
import android.content.BroadcastReceiver;
import android.content.ContentProviderClient;
import android.content.ContentProviderOperation;
import android.content.ContentResolver;
import android.content.Context;
import android.content.ContentValues;
import android.content.IContentProvider;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.OperationApplicationException;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.os.RemoteException;
import android.os.SystemClock;
import android.os.SystemProperties;
import android.provider.ContactsContract;
import android.provider.ContactsContract.CommonDataKinds.Email;
import android.provider.ContactsContract.CommonDataKinds.Phone;
import android.provider.ContactsContract.CommonDataKinds.StructuredName;
import android.provider.ContactsContract.Data;
import android.provider.ContactsContract.RawContacts;
import android.provider.ContactsContract.Settings;
import android.telephony.SubscriptionInfo;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import android.util.Log;

import com.android.internal.telephony.PhoneConstants;

public class SimContactsService extends Service {
    private static final String TAG = "SimContactsService";
    private static boolean DBG = true;

    private static final String COLUMN_NAME_NAME = "name";
    private static final String COLUMN_NAME_NUMBER = "number";
    private static final String COLUMN_NAME_EMAIL = "emails";
    private static final String COLUMN_NAME_ANR = "anrs";

    private static final int TIME_OUT_OF_ADD_ACCOUNT = 2 * 1000;

    static final String SIM_DATABASE_SELECTION = RawContacts.ACCOUNT_TYPE + "=?" + " AND " +
            RawContacts.ACCOUNT_NAME + "=?" +
            " AND " + RawContacts.DELETED + "=?";

    public static final String OPERATION = "operation";
    public static final String SIM_STATE = "sim_state";

    public static final int MSG_BOOT_COMPLETE = 1;
    public static final int MSG_SIM_STATE_CHANGED = 2;
    public static final int MSG_SIM_REFRESH = 3;

    /**
     * Maximum number of operations allowed in a batch between yield points.
     */
    private static final int MAX_OPERATIONS_SIZE = 500;

    private static final int QUERY_TOKEN = 0;

    private Context mContext;

    private static int mPhoneCount = 0;
    protected Cursor[] mSimCursor;
    protected QuerySimHandler[] mQuerySimHandler;
    private boolean[] isSimOperationInprocess;
    private AccountManager accountManager;
    private volatile Handler mServiceHandler;
    private HashMap<Integer, Integer> refreshQueue;

    private int[] mSimState;
    private boolean[] mInvalidSubInfo;
    public static final String ACCOUNT_NAME_SIM = "SIM";

    @Override
    public void onCreate() {
        Log.d(TAG, "service onCreate!");
        TelephonyManager tm = (TelephonyManager) getApplicationContext().
                getSystemService(Context.TELEPHONY_SERVICE);
        mPhoneCount = tm.getPhoneCount();
        mContext = getApplicationContext();
        accountManager = AccountManager.get(mContext);
        mQuerySimHandler = new QuerySimHandler[mPhoneCount];
        mSimCursor = new Cursor[mPhoneCount];
        isSimOperationInprocess = new boolean[mPhoneCount];
        mSimState = new int[mPhoneCount];
        refreshQueue = new HashMap<Integer, Integer>();
        mInvalidSubInfo = new boolean[mPhoneCount];
        mServiceHandler = new Handler() {
            @Override
            public void handleMessage(Message msg) {
                Bundle args = (Bundle) msg.obj;
                switch (msg.what) {
                    case MSG_BOOT_COMPLETE:
                        Log.d(TAG, "on boot complete event");
                        for (int i = 0; i < mPhoneCount; i++) {
                            if (!hasIccCard(i)) {
                                handleNoSim(i);
                            }
                        }
                        break;
                    case MSG_SIM_STATE_CHANGED:
                        final int state = args.getInt(SimContactsService.SIM_STATE);
                        int slotId = args.getInt(PhoneConstants.SLOT_KEY,
                        SubscriptionManager.getSlotIndex(SubscriptionManager.
                                getDefaultVoiceSubscriptionId()));
                        Log.d(TAG, "on sim state changed event, state:" +
                              state + ", slot:" + slotId);
                        if (slotId < 0 || slotId >= mPhoneCount) {
                            break;
                        }
                        if (state == mSimState[slotId] && mInvalidSubInfo[slotId] == false) {
                            break;
                        }

                        mSimState[slotId] = state;
                        if (mSimState[slotId] == SimContactsConstants.SIM_STATE_NOT_READY
                            || mSimState[slotId] == SimContactsConstants.SIM_STATE_ERROR) {
                            // To handle card absent/error, hot swap related cases.
                            deleteDatabaseSimContacts(slotId);
                            deleteSimAccount(slotId);
                            break;
                        }
                    case MSG_SIM_REFRESH:
                        Log.d(TAG, "on sim refresh event");
                        int sub = args.getInt(PhoneConstants.SLOT_KEY,SubscriptionManager.
                                getSlotIndex(SubscriptionManager.getDefaultSubscriptionId()));
                        if (mSimState[sub] == SimContactsConstants.SIM_STATE_READY) {
                            if (!isSimOperationInprocess[sub]) {
                                handleSimOp(sub);
                            } else {
                                Log.d(TAG, "queue refresh sim op");
                                refreshQueue.put(sub, MSG_SIM_REFRESH);
                            }
                        } else if (mSimState[sub] == SimContactsConstants.SIM_STATE_ERROR) {
                            handleNoSim(sub);
                        }
                        break;
                }
            }
        };

        for (int i = 0; i < mPhoneCount; i++) {
            mQuerySimHandler[i] =
                    new QuerySimHandler(mContext.getContentResolver(), i);
            isSimOperationInprocess[i] = false;
            mSimState[i] = SimContactsConstants.SIM_STATE_NOT_READY;
            mInvalidSubInfo[i] = false;
        }
    }

    private static String[] getSimAccountDBSelectArgs(int slotId) {
        return new String[] {
                SimContactsConstants.ACCOUNT_TYPE_SIM,
                getSimAccountName(slotId), "0"
        };
    }

    private boolean hasIccCard(int slotId) {
        TelephonyManager tm = (TelephonyManager) mContext.
                getSystemService(Context.TELEPHONY_SERVICE);
        if (!(mPhoneCount > 1)) {
            return tm.hasIccCard();
        } else {
            SubscriptionInfo subInfo = SubscriptionManager.from(mContext)
                    .getActiveSubscriptionInfoForSimSlotIndex(slotId);
            if (subInfo != null) {
                int subId = subInfo.getSubscriptionId();
                return tm.createForSubscriptionId(subId).hasIccCard();
            } else {
                Log.e(TAG, "Invalid slotId" + slotId);
                return false;
            }
        }
    }

    @Override
    public IBinder onBind(Intent intent) {
        Log.d(TAG, "Service bind. Action: " + intent.getAction());
        return null;
    }

    @Override
    public void onStart(Intent intent, int startId) {
        Log.d(TAG, "service onStart!");
        if (intent == null) {
            Log.d(TAG, "service onStart! intent is null");
            return;
        }
        Bundle args = intent.getExtras();

        if (args == null) {
            Log.d(TAG, "service onStart! args is null");
            return;
        }
        if (!mContext.getResources().getBoolean(R.bool.sim_contacts_auto_sync)
                && !SystemProperties.getBoolean(
                        "persist.env.contacts.autosync", false)) {
            Log.d(TAG, "SIM contacts auto-sync is not enabled!");
            return;
        }
        Message msg = mServiceHandler.obtainMessage();

        msg.what = args.getInt(SimContactsService.OPERATION, -1);
        msg.obj = args;
        mServiceHandler.sendMessage(msg);

    }

    private void handleSimOp(int slotId) {
        Log.d(TAG, "handleSimOp() at sub " + slotId);
        deleteDatabaseSimContacts(slotId);
        querySimContacts(slotId);
    }

    private void handleNoSim(int slotId) {
        Log.d(TAG, "handle no sim on sub : " + slotId);
        deleteDatabaseSimContacts(slotId);
        deleteSimAccount(slotId);
    }

    private Account createSimAccountIfNotExist(final int slotId) {
        Account account = null;
        // if account exists. just return it
        if ((account = findAccount(getSimAccountName(slotId),
                SimContactsConstants.ACCOUNT_TYPE_SIM)) != null) {
            Log.d(TAG, "sim account alreay exist on " + slotId);
            return account;
        }

        final Object lock = new Object();

        final BroadcastReceiver accountsChangedReceiver = new BroadcastReceiver() {
            @Override
            public void onReceive(Context context, Intent intent) {
                if (AccountManager.LOGIN_ACCOUNTS_CHANGED_ACTION.equals(intent.getAction())) {
                    synchronized (lock) {
                        if ((findAccount(getSimAccountName(slotId),
                                SimContactsConstants.ACCOUNT_TYPE_SIM)) != null) {
                            lock.notifyAll();
                        }
                    }
                }
            }
        };

        Bundle args = new Bundle();
        args.putString(SimContactsConstants.EXTRA_ACCOUNT_NAME,
                getSimAccountName(slotId));

        // register a receiver to check is the account added
        registerReceiver(accountsChangedReceiver, new IntentFilter(
                AccountManager.LOGIN_ACCOUNTS_CHANGED_ACTION));

        try {
            synchronized (lock) {
                final long endTime = SystemClock.elapsedRealtime() + TIME_OUT_OF_ADD_ACCOUNT;

                // start to add account
                mContext.startService(new Intent(mContext, SimAuthenticateService.class)
                        .putExtras(args));

                // check the result with a timeout
                while ((account = findAccount(getSimAccountName(slotId),
                        SimContactsConstants.ACCOUNT_TYPE_SIM)) == null) {
                    long delay = endTime - SystemClock.elapsedRealtime();
                    if (delay <= 0) {
                        Log.w(TAG, "timed out to add account for sub" + slotId);
                        return null;
                    }
                    try {
                        lock.wait(delay);
                    } catch (InterruptedException e) {
                    }
                }
                updateAccountVisible(getSimAccountName(slotId),
                        SimContactsConstants.ACCOUNT_TYPE_SIM);
                Log.d(TAG, "success to add account for sub" + slotId);
                return account;
            }
        } finally {
            // unregister the receiver
            unregisterReceiver(accountsChangedReceiver);
        }
    }

    private void deleteSimAccount(int slotId) {
        if (findAccount(getSimAccountName(slotId),
                SimContactsConstants.ACCOUNT_TYPE_SIM) != null) {
            accountManager.removeAccount(
                    new Account(getSimAccountName(slotId),
                            SimContactsConstants.ACCOUNT_TYPE_SIM), null, null);
        }
    }

    private Account findAccount(String accountName, String accountType) {
        for (Account account : accountManager.getAccountsByType(accountType)) {
            if (account.name.equals(accountName)) {
                return account;
            }
        }
        return null;
    }

    private void updateAccountVisible(String accountName,String accountType) {
        if (!hasContactsProviderExist()) {
            Log.d(TAG, "contacts content provider not exist");
            return;
        }

        final ContentResolver resolver = mContext.getContentResolver();
        Log.d(TAG, "updateAccountVisible account is " + accountName);
        // only do this when create
        final ContentValues values = new ContentValues();
        values.put(Settings.ACCOUNT_NAME, accountName);
        values.put(Settings.ACCOUNT_TYPE, accountType);
        values.put(Settings.SHOULD_SYNC, 1);
        values.put(Settings.UNGROUPED_VISIBLE, 1);
        resolver.insert(Settings.CONTENT_URI, values);
    }

    private boolean hasContactsProviderExist() {
        ContentProviderClient provider = null;
        try {
            provider = getContentResolver().
                    acquireContentProviderClient(ContactsContract.AUTHORITY);
        } finally {
            if (provider != null) {
                provider.release();
            }
        }
        return provider != null;
    }

    private void querySimContacts(int slotId) {
        Uri uri = null;
        if (!(mPhoneCount > 1)) {
            uri = Uri.parse("content://icc/adn");
        } else {
            SubscriptionInfo subInfo = SubscriptionManager.from(mContext)
                            .getActiveSubscriptionInfoForSimSlotIndex(slotId);
            if (subInfo != null) {
                mInvalidSubInfo[slotId] = false;
                uri = Uri.parse("content://icc/adn/subId/" + subInfo.getSubscriptionId());
           } else {
                mInvalidSubInfo[slotId] = true;
                Log.e(TAG, "Invalid slotId" + slotId);
                return;
            }
        }
        Log.d(TAG, "querySimContacts: starting an async query:" + uri);
        isSimOperationInprocess[slotId] = true;
        mQuerySimHandler[slotId].startQuery(QUERY_TOKEN, null, uri, null, null, null, null);
    }

    private void deleteDatabaseSimContacts(int slotId) {
        if (!hasContactsProviderExist()) {
            Log.d(TAG, "contacts content provider not exist");
            return;
        }

        getContentResolver().delete(ContactsContract.RawContacts.CONTENT_URI,
                SIM_DATABASE_SELECTION, getSimAccountDBSelectArgs(slotId));
        Log.d(TAG, "deleteDatabaseSimContacts");
    }

    private void addAllSimContactsIntoDatabase(int slotId) {
        ImportAllSimContactsThread thread = new ImportAllSimContactsThread(slotId);
        thread.start();
    }

    protected class QuerySimHandler extends AsyncQueryHandler {
        private int mSlotId = 0;

        public QuerySimHandler(ContentResolver cr, int slotId) {
            super(cr);
            mSlotId = slotId;
        }

        public QuerySimHandler(ContentResolver cr) {
            super(cr);
        }

        @Override
        protected void onQueryComplete(int token, Object cookie, Cursor c) {
            mSimCursor[mSlotId] = c;
            addAllSimContactsIntoDatabase(mSlotId);
        }

        @Override
        protected void onInsertComplete(int token, Object cookie,
                Uri uri) {
        }

        @Override
        protected void onUpdateComplete(int token, Object cookie, int result) {
        }

        @Override
        protected void onDeleteComplete(int token, Object cookie, int result) {
        }
    }

    private class ImportAllSimContactsThread extends Thread {
        private int mSlotId = 0;
        private static final int INIT_OPERATIONS_SIZE = 20;

        public ImportAllSimContactsThread(int slotId) {
            super("ImportAllSimContactsThread");
            mSlotId = slotId;
        }

        @Override
        public void run() {
            synchronized (this) {
                try {
                    if (mSimState[mSlotId] == SimContactsConstants.SIM_STATE_ERROR) {
                        Log.e(TAG, "sim state is not ready, can not save sim contacts");
                        return;
                    }

                    Account account = createSimAccountIfNotExist(mSlotId);

                    if (account == null) {
                        Log.e(TAG, "create sim account error on sub" + mSlotId);
                        return;
                    }

                    if (mSimCursor[mSlotId] == null
                            || mSimCursor[mSlotId].isClosed()) {
                        Log.e(TAG,
                                "sim contact cursor is null or closed on sub" + mSlotId);
                        return;
                    } else {
                        Log.d(TAG, " QuerySimHandler onQueryComplete: cursor.count="
                                + mSimCursor[mSlotId].getCount());
                    }

                    final ContentResolver resolver = mContext.getContentResolver();
                    ArrayList<ContentProviderOperation> operationList =
                            new ArrayList<ContentProviderOperation>();
                    int i = 1;
                    int n = i*INIT_OPERATIONS_SIZE;
                    Log.d(TAG, "import contact to account: " + account);
                    mSimCursor[mSlotId].moveToPosition(-1);
                    while (mSimCursor[mSlotId].moveToNext()) {
                        actuallyImportOneSimContact(
                                mSimCursor[mSlotId], resolver, account, operationList);
                        //enlarge batch size dynamic
                        if( n - operationList.size() < 8 ) {
                            try {
                                i = i*2;
                                n = i * INIT_OPERATIONS_SIZE;
                                if (n > MAX_OPERATIONS_SIZE)
                                    n = MAX_OPERATIONS_SIZE;
                                resolver.applyBatch(ContactsContract.AUTHORITY, operationList);
                            } catch (Exception e) {
                                Log.e(TAG, String.format("%s: %s", e.toString(), e.getMessage()));
                            } finally {
                                operationList.clear();
                            }
                        }
                    }

                    if(operationList.size() > 0) {
                        try {
                            resolver.applyBatch(ContactsContract.AUTHORITY, operationList);
                        } catch (Exception e) {
                            Log.e(TAG, String.format("%s: %s", e.toString(), e.getMessage()));
                        } finally {
                            operationList.clear();
                        }
                    }
                    Log.d(TAG, "import contact to account done!");
                } finally {
                    if (mSimCursor[mSlotId] != null
                            && !mSimCursor[mSlotId].isClosed()) {
                        mSimCursor[mSlotId].close();
                        mSimCursor[mSlotId] = null;
                    }
                    isSimOperationInprocess[mSlotId] = false;
                    sendPendingSimRefreshUpdateMsg(mSlotId);
                }
            }
        }
    }

    private static void actuallyImportOneSimContact(
            final Cursor cursor, final ContentResolver resolver, Account account,
            ArrayList<ContentProviderOperation> operationList) {

        final String name = cursor.getString(cursor.getColumnIndex(COLUMN_NAME_NAME));
        final String phoneNumber = cursor.getString(cursor.getColumnIndex(COLUMN_NAME_NUMBER));
        String emailAddresses = null;
        int ref = operationList.size();
        try {
            emailAddresses = cursor.getString(cursor.getColumnIndexOrThrow(COLUMN_NAME_EMAIL));
        } catch (IllegalArgumentException e) {
        }
        String anrs = null;
        try {
            anrs = cursor.getString(cursor.getColumnIndexOrThrow(COLUMN_NAME_ANR));
        } catch (IllegalArgumentException e) {
        }
        if (DBG)
            Log.d(TAG,
                    String.format("name: %s, number: %s, anrs: %s, emails: %s", name, phoneNumber,
                            anrs, emailAddresses));
        final String[] emailAddressArray;
        final String[] anrArray;
        if (!TextUtils.isEmpty(emailAddresses)) {
            emailAddressArray = emailAddresses.split(",");
        } else {
            emailAddressArray = null;
        }
        if (!TextUtils.isEmpty(anrs)) {
            anrArray = anrs.split(":");
        } else {
            anrArray = null;
        }

        ContentProviderOperation.Builder builder =
                ContentProviderOperation.newInsert(RawContacts.CONTENT_URI);
        builder.withValue(RawContacts.AGGREGATION_MODE, RawContacts.AGGREGATION_MODE_DISABLED);
        if (account != null) {
            builder.withValue(RawContacts.ACCOUNT_NAME, account.name);
            builder.withValue(RawContacts.ACCOUNT_TYPE, account.type);
        }
        operationList.add(builder.build());

        if (!TextUtils.isEmpty(name)) {
            builder = ContentProviderOperation.newInsert(Data.CONTENT_URI);
            builder.withValueBackReference(StructuredName.RAW_CONTACT_ID, ref);
            builder.withValue(Data.MIMETYPE, StructuredName.CONTENT_ITEM_TYPE);
            builder.withValue(StructuredName.GIVEN_NAME, name);
            operationList.add(builder.build());
        }

        if (!TextUtils.isEmpty(phoneNumber)) {
            builder = ContentProviderOperation.newInsert(Data.CONTENT_URI);
            builder.withValueBackReference(Phone.RAW_CONTACT_ID, ref);
            builder.withValue(Data.MIMETYPE, Phone.CONTENT_ITEM_TYPE);
            builder.withValue(Phone.TYPE, Phone.TYPE_MOBILE);
            builder.withValue(Phone.NUMBER, phoneNumber);
            builder.withValue(Data.IS_PRIMARY, 1);
            operationList.add(builder.build());
        }

        if (anrArray != null) {
            for (String anr : anrArray) {
                builder = ContentProviderOperation.newInsert(Data.CONTENT_URI);
                builder.withValueBackReference(Phone.RAW_CONTACT_ID, ref);
                builder.withValue(Data.MIMETYPE, Phone.CONTENT_ITEM_TYPE);
                builder.withValue(Phone.TYPE, Phone.TYPE_HOME);
                builder.withValue(Phone.NUMBER, anr);
                // builder.withValue(Data.IS_PRIMARY, 1);
                operationList.add(builder.build());
            }
        }

        if (emailAddressArray != null) {
            for (String emailAddress : emailAddressArray) {
                builder = ContentProviderOperation.newInsert(Data.CONTENT_URI);
                builder.withValueBackReference(Email.RAW_CONTACT_ID, ref);
                builder.withValue(Data.MIMETYPE, Email.CONTENT_ITEM_TYPE);
                builder.withValue(Email.TYPE, Email.TYPE_MOBILE);
                builder.withValue(Email.ADDRESS, emailAddress);
                operationList.add(builder.build());
            }
        }
    }

    private void sendPendingSimRefreshUpdateMsg(int slotId) {
        if (refreshQueue.get(slotId) != null) {
            Log.d(TAG, "send refresh op msg since it is in refreshQueue at sub " + slotId);
            Bundle args = new Bundle();
            args.putInt(PhoneConstants.SLOT_KEY, slotId);
            Message msg = mServiceHandler.obtainMessage();
            msg.what = refreshQueue.get(slotId);
            msg.obj = args;
            mServiceHandler.sendMessage(msg);
            refreshQueue.put(slotId, null);
        }
    }

    public  static String getSimAccountName(int slotId) {
        if (mPhoneCount > 1) {
            return ACCOUNT_NAME_SIM + (slotId + 1);
        } else {
            return ACCOUNT_NAME_SIM;
        }
    }
}
