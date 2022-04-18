/*
 * Copyright (c) 2016, 2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.callfeaturessetting.cdma.CdmaCallForwardWaiting;

import android.Manifest;
import android.app.AlertDialog;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.preference.Preference;
import android.preference.PreferenceScreen;
import android.preference.PreferenceActivity;
import android.provider.ContactsContract.CommonDataKinds.Phone;
import android.telecom.PhoneAccountHandle;
import android.telecom.TelecomManager;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.MenuItem;

import com.android.internal.telephony.CommandsInterface;
import com.android.internal.telephony.PhoneConstants;
import com.android.internal.telephony.PhoneFactory;

import java.util.ArrayList;
import com.qualcomm.qti.callfeaturessetting.R;

public class CdmaCallWaitingOptions extends PreferenceActivity {
    private static final String LOG_TAG = "CdmaCallWaitingOptions";
    private final boolean DBG = true;

    private static final int CALL_WAITING = 7;
    private static final String BUTTON_CW_ACT_KEY = "button_cw_act_key";
    private static final String BUTTON_CW_DEACT_KEY = "button_cw_deact_key";

    PreferenceScreen prefCWAct;
    PreferenceScreen prefCWDeact;
    private boolean mFirstResume;
    private int mSubId = 0;
    private AlertDialog mMissingPermissionDialog;

    @Override
    protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);

        addPreferencesFromResource(R.xml.callwaiting_cdma_options);

        // getting selected subscription
        mSubId = getIntent().getIntExtra(PhoneConstants.SUBSCRIPTION_KEY,
                SubscriptionManager.DEFAULT_SUBSCRIPTION_ID);
        Log.d(LOG_TAG, "Inside CW options, Getting subscription = " + mSubId);

        PreferenceScreen prefSet = getPreferenceScreen();
        prefCWAct = (PreferenceScreen) prefSet.findPreference(BUTTON_CW_ACT_KEY);
        prefCWDeact = (PreferenceScreen) prefSet.findPreference(BUTTON_CW_DEACT_KEY);

        mFirstResume = true;
    }

    @Override
    public void onResume() {
        super.onResume();
        if (mFirstResume) {
            if ((checkSelfPermission(Manifest.permission.READ_PHONE_STATE)
                        == PackageManager.PERMISSION_GRANTED)
                    && (checkSelfPermission( Manifest.permission.CALL_PHONE)
                        == PackageManager.PERMISSION_GRANTED)) {
                init();
            } else {
                GlobalUtils.requestPhonePermission(this);
            }
        }
    }

    private void init() {
        PhoneAccountHandle accountHandle = GlobalUtils.getPhoneAccountHandle(this, mSubId);
        prefCWAct.getIntent()
            .putExtra(TelecomManager.EXTRA_PHONE_ACCOUNT_HANDLE, accountHandle)
            .setData(Uri.fromParts("tel", GlobalUtils.getActivateNumber
                        (this, mSubId, GlobalUtils.CALL_WAITING), null));
        prefCWAct.setSummary(GlobalUtils.getActivateNumber(this, mSubId, GlobalUtils.
                    CALL_WAITING));

        prefCWDeact.getIntent()
            .putExtra(TelecomManager.EXTRA_PHONE_ACCOUNT_HANDLE, accountHandle)
            .setData(Uri.fromParts("tel", GlobalUtils.getDeactivateNumber
                        (this, mSubId, GlobalUtils.CALL_WAITING), null));
        prefCWDeact.setSummary(GlobalUtils.getDeactivateNumber(this, mSubId, GlobalUtils.
                    CALL_WAITING));
        mFirstResume = false;
    }

    /**
     * Callback received when a permissions request has been completed.
     */
    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions,
            int[] grantResults) {
        switch (requestCode) {
            case GlobalUtils.REQUEST_PHONE_PERMISSIONS:
                if ((grantResults.length == 2)
                        && (grantResults[0] == PackageManager.PERMISSION_GRANTED)
                        && (grantResults[1] == PackageManager.PERMISSION_GRANTED)) {
                    init();
                } else {
                    finish();
                }
                break;
            default:
                super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == android.R.id.home) {
            onBackPressed();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
