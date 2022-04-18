/*********************************************************************
 Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
**********************************************************************/

package com.qualcomm.qti.uceShimService;


import android.os.Parcel;
import android.os.RemoteException;
import android.util.Log;
import android.os.IBinder;
import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.os.ServiceManager;
import android.telephony.SubscriptionManager;
import android.telephony.SubscriptionInfo;
import com.qualcomm.qti.uceservice.V2_0.UceStatus; // or .*
import com.qualcomm.qti.uceservice.V2_0.UceStatusCode;

import com.android.ims.internal.uce.uceservice.IUceService;
import com.android.ims.internal.uce.UceServiceBase;
import com.android.ims.internal.uce.uceservice.IUceListener;
import com.android.ims.internal.uce.presence.IPresenceService;
import com.android.ims.internal.uce.presence.IPresenceListener;
import com.android.ims.internal.uce.options.IOptionsService;
import com.android.ims.internal.uce.options.IOptionsListener;
import com.android.ims.internal.uce.common.*;

import com.qualcomm.qti.presence.PresListener;
import com.qualcomm.qti.options.OptionsListener;

import com.qualcomm.qti.presence.PresService;
import com.qualcomm.qti.options.OptionsService;
import java.util.*;
import android.os.IBinder;
import android.os.IHwBinder;
public class RCSServiceStub extends UceServiceBase { //extend AIDL- IUCEService

    private com.qualcomm.qti.uceservice.V2_0.IUceService mhidlUceService = null;
    private com.qualcomm.qti.uceservice.V2_1.IUceService mhidlUceService_2_1 = null;
    private final String ACCESS_UCE_PRES_SERVICE = Manifest.permission.ACCESS_UCE_PRESENCE_SERVICE;
    private final String ACCESS_UCE_OPTION_SERVICE = Manifest.permission.ACCESS_UCE_OPTIONS_SERVICE;

    private final static String logTAG = "Aidl-shim UceServiceStub";

    private static Map<String, PresService> mPresenceSvcMap = new HashMap<String, PresService>();
    private static Map<String, OptionsService> mOptionsServicMap = new HashMap<String, OptionsService>();

    private String mIccId = null;

    private Context servContext = null;

    public boolean setHidlUceSerice(com.qualcomm.qti.uceservice.V2_0.IUceService hidlService) {
        mhidlUceService = hidlService;
        return (getDefaultIccId());
    }

    public boolean setHidlUceSerice(com.qualcomm.qti.uceservice.V2_1.IUceService hidlService) {
        mhidlUceService_2_1 = hidlService;
        return (getDefaultIccId());
    }

    public boolean startService(IUceListener uceListener)
            throws RemoteException {
        Log.i(logTAG, "RCSStartRCSService Start Service call");
        return true;
    }

    public boolean stopService() throws RemoteException {
        return true;
    }

    public boolean isServiceStarted() throws RemoteException {
        return true;
    }

    private boolean getDefaultIccId() {
        boolean retval = false;
        //check if this is multiSIM.
        SubscriptionManager subMgr =  SubscriptionManager.from(servContext);
        List<SubscriptionInfo> subInfoList = subMgr.getActiveSubscriptionInfoList();
        if (subInfoList != null) {
            if (subInfoList.size() > 1) {
                Log.i(logTAG, "RCSStartRCSService Detected MultiSim");
            }
            if(subInfoList.size() > 0 && (subInfoList.get(0) != null)) {
                mIccId = subInfoList.get(0).getIccId();
                Log.i(logTAG, "getDefaultIccId default mIccId [" + mIccId +"]");
                retval = true;
            }
        }

        return retval;
    }


    protected int onCreateOptionsService(IOptionsListener optionsListener,
                                    UceLong optionsServiceListenerHdl) {
        int serviceHandle = -1;
        if (mIccId == null) {
            Log.i(logTAG, "onCreateOptionsService FAILED ICCID not found");
            return serviceHandle;
        }
        try {
            serviceHandle = onCreateOptionsService(optionsListener,
                                                   optionsServiceListenerHdl,
                                                   mIccId);
        } /*  catch (RemoteException e) {
            Log.d(logTAG, "createPresenceService failed with Exception:" + e);
        }*/  catch (RuntimeException e) {
            Log.d(logTAG, "createPresenceService failed with Exception:" + e);
        }

        return serviceHandle;
    }

    protected int onCreateOptionsService(IOptionsListener optionsListener,
                                      UceLong optionsServiceListenerHdl,
                                      String iccId)  {
       servContext.enforceCallingOrSelfPermission(ACCESS_UCE_OPTION_SERVICE, "open");
       int serviceHandle = -1;
       UceStatus hidlUceStatus = null;
       long hidlOptionsSrvcListenerHdl = 1;

       /* Create the thread and set service handle to -1 */
       UceThreadHandler optionsHandler = new UceThreadHandler();
       optionsHandler.setHandle(serviceHandle);

       boolean bSuspendThread = true;
       OptionsListener hidlOptionLister = new OptionsListener();

       optionsHandler.setThread(Thread.currentThread());
       hidlOptionLister.setAidlOptionsServiceListener(optionsListener);
       hidlOptionLister.setOptionsHandler(optionsHandler);

       hidlOptionsSrvcListenerHdl = optionsServiceListenerHdl.getUceLong();
       try {
           if (mhidlUceService_2_1 != null) {
               hidlUceStatus = mhidlUceService_2_1.createOptionsService(hidlOptionLister,
                                                                hidlOptionsSrvcListenerHdl,
                                                                iccId);
           } else {
               hidlUceStatus = mhidlUceService.createOptionsService(hidlOptionLister,
                                                                    hidlOptionsSrvcListenerHdl,
                                                                    iccId);
           }
       }catch (RemoteException | RuntimeException e) {
            Log.d(logTAG, "createPresenceService failed with Exception:" + e);
            bSuspendThread = false;
       }
       //if createoptionsservice returns any failure, service handle is returned as -1
       if(hidlUceStatus != null && hidlUceStatus.status != UceStatusCode.SUCCESS) {
            Log.d(logTAG, "createOptionsService returning service handle -1, hidlUceStatus: " + hidlUceStatus.status);
            return serviceHandle;
       }
       OptionsService optionsSvc = mOptionsServicMap.get(iccId);
       if ( optionsSvc == null) {
           optionsSvc = new OptionsService();
           mOptionsServicMap.put(iccId, optionsSvc);
       }
       optionsSvc.addHidlListener(hidlOptionLister);

       /* Get the service handle to check whether its already avaiable.
           This is done to avoid calling thread suspend when service handle
           is already available */
       serviceHandle = optionsHandler.getHandle();

       if (bSuspendThread && (serviceHandle == -1)) {
           optionsHandler.suspend();
       }
       if (hidlUceStatus != null && hidlUceStatus.status == 0) {
            serviceHandle = optionsHandler.getHandle();
            optionsSvc.setServiceHandle(serviceHandle);
        }
        OptionsListenerDeathRecipient optionsListenerDeathRecipient =
                  new OptionsListenerDeathRecipient(serviceHandle, optionsListener);
        try{
            optionsListener.asBinder().linkToDeath(optionsListenerDeathRecipient,1);
        }
        catch(RemoteException e){
            Log.i(logTAG, "Caught Exception :" + e);
        }
       return serviceHandle;
    }

    protected void onDestroyOptionsService(int optionsServiceHandle) {
        servContext.enforceCallingOrSelfPermission(ACCESS_UCE_OPTION_SERVICE, "close");
        try {
            if (mhidlUceService_2_1 != null) {
                mhidlUceService_2_1.destroyOptionsService(optionsServiceHandle);
            } else {
                mhidlUceService.destroyOptionsService(optionsServiceHandle);
            }
        } catch (RemoteException | RuntimeException e) {
            Log.d(logTAG, "onDestroyOptionsService failed with Exception:" + e);
        }
    }

    protected int onCreatePresService(
            IPresenceListener pPresServiceListener,
            UceLong pPresServiceListenerHdl) {
        Log.i(logTAG, "onCreatePresService legacy API hit [" + mIccId +"]");
        int serviceHandle = -1;
        if (mIccId == null) {
            Log.i(logTAG, "onCreatePresService FAILED ICCID not found");
            return serviceHandle;
        }
        try {
            serviceHandle = onCreatePresService(pPresServiceListener,
                                                pPresServiceListenerHdl,
                                                mIccId);
        } catch (RuntimeException  e) {
            Log.d(logTAG, "createPresenceService failed with Exception:" + e);
        }

        return serviceHandle;

    }
    protected int onCreatePresService(IPresenceListener presServiceListener,
                                                    UceLong presServiceListenerHdl,
                                                    String iccId)  {
        servContext.enforceCallingOrSelfPermission(ACCESS_UCE_PRES_SERVICE, "open");
        int serviceHandle = -1;
        UceStatus hidlUceStatus = null;
        long hidlPresServiceListenerHdl = -1;
        UceThreadHandler presenceHandler = new UceThreadHandler();
        boolean bSuspendThread = true;
        PresListener hidlPresListener = new PresListener();

        /* Create the thread and set service handle to -1 */
        presenceHandler.setThread(Thread.currentThread());
        presenceHandler.setHandle(serviceHandle);

        hidlPresListener.setAidlPresListener(presServiceListener);
        hidlPresListener.setCreatePresenceHandler(presenceHandler);

        hidlPresServiceListenerHdl = presServiceListenerHdl.getUceLong();
        try {
            if (mhidlUceService_2_1 != null) {
                Log.d(logTAG, "createPresenceService_2_1");
                hidlUceStatus = mhidlUceService_2_1.createPresenceService_2_1(hidlPresListener,
                                                              hidlPresServiceListenerHdl,
                                                              iccId);
            } else {
                Log.d(logTAG, "createPresenceService legacy HAL");
                hidlUceStatus = mhidlUceService.createPresenceService(hidlPresListener,
                                                                  hidlPresServiceListenerHdl,
                                                                  iccId);
            }
        }
        catch (RemoteException | RuntimeException e) {
            Log.d(logTAG, "createPresenceService failed with Exception:" + e);
            bSuspendThread = false;
        }
         //if createpresencesservice returns any failure, service handle is returned as -1
        if(hidlUceStatus != null && hidlUceStatus.status != UceStatusCode.SUCCESS) {
            Log.d(logTAG, "createPresenceService returning service handle -1, hidlUceStatus: " + hidlUceStatus.status);
            return serviceHandle;
        }
        PresService presSvc = mPresenceSvcMap.get(iccId);
        if ( presSvc == null) {
            Log.i(logTAG, "onCreatePresService creating new PresService for [" + mIccId +"]");
            presSvc = new PresService();
            mPresenceSvcMap.put(iccId, presSvc);
        }
        presSvc.addHidlListener(hidlPresListener);

        /* Get the service handle to check whether its already avaiable.
           This is done to avoid calling thread suspend when service handle
           is already available */
        serviceHandle = presenceHandler.getHandle();

        if (bSuspendThread && (serviceHandle == -1)) {
            presenceHandler.suspend();
        }

        if (hidlUceStatus != null && hidlUceStatus.status == 0) {
            serviceHandle = presenceHandler.getHandle();
            presSvc.setServiceHandle(serviceHandle);
        }
        PresenceListenerDeathRecipient presenceListenerDeathRecipient =
                new PresenceListenerDeathRecipient(serviceHandle, presServiceListener);
        try{
            presServiceListener.asBinder().linkToDeath(presenceListenerDeathRecipient, 1);
        }
        catch (RemoteException e){
            Log.i(logTAG, "Caught Exception :" + e);
        }
        return serviceHandle;
    }

    protected void onDestroyPresService(int pPresServiceHdl) {
        servContext.enforceCallingOrSelfPermission(ACCESS_UCE_PRES_SERVICE, "close");
        try {
            if (mhidlUceService_2_1 != null) {
                mhidlUceService_2_1.destroyPresenceService(pPresServiceHdl);
            } else {
                mhidlUceService.destroyPresenceService(pPresServiceHdl);
            }
        }
        catch (RemoteException | RuntimeException e) {
            Log.d(logTAG, "destroyPresenceService failed with Exception:" + e);
        }
    }

    protected IPresenceService onGetPresenceService()  {
        Log.i(logTAG, "onGetPresenceService default mIccId [" + mIccId +"]");
        return onGetPresenceService(mIccId);
    }

    protected IPresenceService onGetPresenceService(String iccId) {
        PresService presService = mPresenceSvcMap.get(iccId);
        if(presService == null) {
            Log.i(logTAG, "onGetPresenceService presService is NULL for [" + mIccId +"]");
        }
        return presService;
    }

    protected IOptionsService onGetOptionsService() {
        return onGetOptionsService(mIccId);
    }
    protected IOptionsService onGetOptionsService (String iccId) {
        return mOptionsServicMap.get(iccId);
    }

    protected boolean onGetServiceStatus()
    {
        Log.i(logTAG, "ServiceStatus isRCSRegistered ["
                + RCSListener.isRCSRegistered + "]");
        return RCSListener.isRCSRegistered;
    }

    public void setServiceStatus( boolean status) {
        RCSListener.isRCSRegistered = status;
        Log.i(logTAG, "ServiceStatus isRCSRegistered ["
                + RCSListener.isRCSRegistered + "]");
    }

    public void SetContext(Context servContext) {
        this.servContext = servContext;

    }
    private class OptionsListenerDeathRecipient implements IBinder.DeathRecipient{
        private IOptionsListener listener = null;
        private int serviceHandle = 0;
        //constructor
        public OptionsListenerDeathRecipient(int serviceHandle, IOptionsListener listener) {
          this.serviceHandle = serviceHandle;
          this.listener = listener;
        }
        @Override
        public void binderDied(){
            Log.i(logTAG, "Options listener died");
            try{
                if (serviceHandle != 0){
                    if (mhidlUceService_2_1 != null) {
                        mhidlUceService_2_1.destroyOptionsService(serviceHandle);
                    } else {
                        mhidlUceService.destroyOptionsService(serviceHandle);
                    }
                }
                if (listener != null){
                    listener.asBinder().unlinkToDeath(this, 1);
                }
            }
            catch(RemoteException e){
                Log.i(logTAG, "Remote exception : " +e);
            }
        }
    };

    private class PresenceListenerDeathRecipient implements IBinder.DeathRecipient{
        private IPresenceListener listener = null;
        private int serviceHandle = 0;
        //constructor
        public PresenceListenerDeathRecipient(int serviceHandle, IPresenceListener listener) {
          this.serviceHandle = serviceHandle;
          this.listener = listener;
        }
        @Override
        public void binderDied(){
            Log.i(logTAG, "Presence listener died");
            try{
                if (serviceHandle != 0){
                    if (mhidlUceService_2_1 != null) {
                        mhidlUceService_2_1.destroyPresenceService(serviceHandle);
                    } else {
                        mhidlUceService.destroyPresenceService(serviceHandle);
                    }
                }
                if (listener != null) {
                    listener.asBinder().unlinkToDeath(this,1);
                }
            }
            catch(RemoteException e){
                Log.i(logTAG, "Remote exception : " +e);
            }
        }
    };

}
