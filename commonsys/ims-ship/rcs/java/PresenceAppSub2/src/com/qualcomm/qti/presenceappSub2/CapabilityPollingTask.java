/*************************************************************************
 Copyright (c)2017 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
*************************************************************************/

package com.qualcomm.qti.presenceappSub2;

import java.util.ArrayList;

import com.android.ims.internal.uce.common.StatusCode;
import android.app.ProgressDialog;
import android.content.Context;
import android.os.AsyncTask;
import android.os.Looper;
import android.os.RemoteException;
import android.util.Log;
import android.widget.Toast;

public class CapabilityPollingTask extends AsyncTask<Void, Integer, Integer> {

    final String TAG = "PRESENCE_UI2: CapabilityPollingTask";
    static int CAPABILITY_POLLING_ERROR = 5;
    int mContactIndex;
    Context mContext;
    ProgressDialog dialog;
    boolean isBackground = false;

    CapabilityPollingTask me;

    public CapabilityPollingTask() {
    }

    public CapabilityPollingTask(Context appContext, int contactIndex, boolean bg) {

        mContext = appContext;
        mContactIndex = contactIndex;
        me = this;
        isBackground = bg;
        Log.d(TAG, "CapabilityPollingTask : CapabilityPollingTask()");
    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();

        if (!isBackground) {
            initProgressBar();
            Log.d(TAG, "CapabilityPollingTask : CapabilityPollingTask() : isBackground "+isBackground);
        }
    }

    private void initProgressBar() {
        dialog = new ProgressDialog(mContext);
        dialog.setMessage("API Request in progress...");
        dialog.setCancelable(false);

        AppGlobalState.setProgressDialog(dialog);

        dialog.show();
        Log.d(TAG, "CapabilityPollingTask : initProgressBar");
    }

    @Override
    protected Integer doInBackground(Void... params) {
        Log.d(TAG, "doInBackground(), Thread=" +
                Thread.currentThread().getName());

        if (Looper.myLooper() == null) {
            Looper.prepare();
        }

        ArrayList<Contact> contacts = AppGlobalState.getContacts();
    if(contacts != null && contacts.get(mContactIndex) != null && contacts.get(mContactIndex).getPhone() != null){
        String phone = contacts.get(mContactIndex).getPhone();

        if (!phone.isEmpty()) {
            String uri = prepareCompleteUri(phone);

            ArrayList<String> contactList = new ArrayList<String>();
            contactList.add(uri);
            Log.d(TAG, "CapabilityPollingTask : doInBackground");
            return sendSubscribeSimpleRequest(contactList);
        } else
            return CAPABILITY_POLLING_ERROR;
    }
    else{
      return CAPABILITY_POLLING_ERROR;
    }

    }



    private String prepareCompleteUri(String phone) {

        if (AppGlobalState.getOperatorMode() == AppGlobalState.VZW_MODE)
        {
            phone = "tel:" + phone;
        }
        else
        {
            ArrayList<Contact> contacts = AppGlobalState.getContacts();
            phone = contacts.get(mContactIndex).getContactUri();

            if((phone == null) || (phone != null && phone.length() == 0))
            {
                phone = contacts.get(mContactIndex).getResourceUri();

            }
            if(phone != null && phone.length() > 0)
            {
                if(phone.equals("<Not Subscribed>"))
                {
                    if(!contacts.get(mContactIndex).getIndividualContactURI().equals(""))
                    {
                        phone = contacts.get(mContactIndex).getIndividualContactURI();
                    }
                    else
                    {
                        phone = "tel:" + contacts.get(mContactIndex).getPhone();
                    }
                }
            }
            else
            {
                if(!contacts.get(mContactIndex).getIndividualContactURI().equals(""))
                {
                    phone = contacts.get(mContactIndex).getIndividualContactURI();
                }
                else
                {
                    phone = "tel:" + contacts.get(mContactIndex).getPhone();
                }
            }
        }
        return phone;
    }

    private Integer sendSubscribeSimpleRequest(ArrayList<String> contactList) {
        Log.d(TAG, "sendSubscribeSimpleRequest for " + contactList.get(0));

        String [] stringContactList = new String[contactList.size()];
        for(int i=0; i< contactList.size(); i++ )
        {
            stringContactList[i] = contactList.get(i).toString();
        }
        try {
            Log.d(TAG, " aks2 sendSubscribeSimpleRequest 001 ");
            if(AppGlobalState.getPresenceService() != null && AppGlobalState.isCdByOption() == false)
            {
                Log.d(TAG, "CapabilityPollingTask : sendSubscribeSimpleRequest : AppGlobalState.getPresenceSerrviceHandle() "+AppGlobalState.getPresenceSerrviceHandle());
                Log.d(TAG, "CapabilityPollingTask : sendSubscribeSimpleRequest : stringContactList "+stringContactList);
                RequestInfo requestinfoObject = new RequestInfo();
                requestinfoObject.userData = AppGlobalState.getpUserDataValue();
                requestinfoObject.URI = new String[stringContactList.length];
                for(int i =0; i < stringContactList.length; i++ )
                {
                    requestinfoObject.URI[i] = stringContactList[i];
                }
                AppGlobalState.requestinfo.add(requestinfoObject);
                StatusCode status = AppGlobalState.getPresenceService().getContactListCap(AppGlobalState.getPresenceSerrviceHandle(), stringContactList, AppGlobalState.getpUserData());
                Log.d(TAG, "CapabilityPollingTask : sendSubscribeSimpleRequest : status.getStatusCode() "+status.getStatusCode());
                return status.getStatusCode();
            }
            else if(AppGlobalState.getCdService() != null && AppGlobalState.isCdByOption())
            {
                StatusCode status = AppGlobalState.getCdService().getContactCap(AppGlobalState.getCdServiceHandle(), contactList.get(0), AppGlobalState.getpUserData());
                Log.d(TAG, "ListAvailabilityFetchTask : QCDService_RequestCdInfo :  status.getStatusCode() "+ status.getStatusCode());
                return status.getStatusCode();
            }
            else
            {
                Log.d(TAG, "CapabilityPollingTask : sendSubscribeSimpleRequest : AppGlobalState.getPresenceService =  NULL ");
                return -1;
            }
        } catch (RemoteException e) {
            e.printStackTrace();
            return -2;
        } catch (Exception e) {
            e.printStackTrace();
            return -3;
        }
    }

    @Override
    protected void onProgressUpdate(Integer... values) {
        super.onProgressUpdate(values);
    }

    @Override
    protected void onPostExecute(Integer result) {
        super.onPostExecute(result);
        Log.d(TAG, "onPostExecute(), Thread=" +
                Thread.currentThread().getName());

        if (result == 0) { // Success
            updateContactSubscriptionFlag();
            Utility.rescheduleSubcribeTimer(mContactIndex,
                    AppGlobalState.getContacts().get(mContactIndex));
        }

        if (!isBackground) {
            dialog.dismiss();
        }

        if (result == CAPABILITY_POLLING_ERROR)
        {
            Toast.makeText(mContext, "Add Phone number before polling", Toast.LENGTH_SHORT).show();
        } else
            Toast.makeText(mContext, "Subscribe Simple Result =" +
                    result, Toast.LENGTH_SHORT).show();
    }

    private void updateContactSubscriptionFlag() {

        ArrayList<Contact> contacts = AppGlobalState.getContacts();

        Contact temp = contacts.get(mContactIndex);
        temp.setSubscriptionOnFlag(true);
    }
}
