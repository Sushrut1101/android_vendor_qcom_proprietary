
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2013, 2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

  2013 Qualcomm Atheros, Inc.

  All Rights Reserved.
  Qualcomm Atheros Confidential and Proprietary.

  Not a Contribution, Apache license notifications and
  license are retained for attribution purposes only.
=============================================================================*/

/*
 * Copyright (C) 2008 The Android Open Source Project
 * Copyright (c) 2011,2012, The Linux Foundation. All rights reserved.
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

package com.qualcomm.location;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.StringReader;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Date;
import java.util.Properties;
import java.util.Map.Entry;
import java.util.Random;

import com.android.internal.telephony.PhoneConstants;
import com.android.internal.telephony.Phone;
import com.android.internal.telephony.PhoneConstants;
import com.android.internal.telephony.TelephonyProperties;
import android.provider.Telephony.Carriers;
import android.database.sqlite.SQLiteException;

import com.qualcomm.location.GpsNetInitiatedHandler;
import com.qualcomm.location.GpsNetInitiatedHandler.GpsNiNotification;

import android.app.PendingIntent;
import android.app.Service;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.database.Cursor;
import android.database.ContentObserver;
import android.location.Location;
import android.location.LocationManager;
import android.location.INetInitiatedListener;
import android.telephony.TelephonyManager;
import android.net.ConnectivityManager;
import android.net.ConnectivityManager.NetworkCallback;
import android.net.NetworkInfo;
import android.net.Network;
import android.net.NetworkRequest;
import android.net.NetworkCapabilities;
import android.net.Uri;
import android.net.LinkProperties;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.IBinder;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Message;
import android.os.PowerManager;
import android.os.ServiceManager;
import android.os.SystemProperties;
import android.provider.Settings;
import android.util.Log;
import android.util.NtpTrustedTime;

import com.qualcomm.location.osagent.OsAgent;
import com.qualcomm.location.izatprovider.IzatProvider;

public class LocationService extends Service implements Handler.Callback {
    private static final String TAG = "LocSvc_java";
    private static boolean DEBUG = Log.isLoggable(TAG, Log.DEBUG);

    //Timeout for ConnectivityManager.requestNetwork
    //The modem timeout is 30 seconds. We'll try to send back a response
    //before it times out
    private static final int NETWORK_REQUEST_TIMEOUT_MS = 1000 * 10;
    //Network states passed from network callback
    private static final int NETWORK_UNAVAILABLE = 0;
    private static final int NETWORK_AVAILABLE   = 1;

    // these need to match GpsApgsStatusValue defines in gps.h
    /** AGPS status event values. */
    private static final int GPS_REQUEST_AGPS_DATA_CONN = 1;
    private static final int GPS_RELEASE_AGPS_DATA_CONN = 2;
    private static final int GPS_AGPS_DATA_CONNECTED = 3;
    private static final int GPS_AGPS_DATA_CONN_DONE = 4;
    private static final int GPS_AGPS_DATA_CONN_FAILED = 5;

    // The GPS_CAPABILITY_* flags must match the values in gps.h
    private static final int GPS_CAPABILITY_SCHEDULING = 0x0000001;
    private static final int GPS_CAPABILITY_MSB = 0x0000002;
    private static final int GPS_CAPABILITY_MSA = 0x0000004;
    private static final int GPS_CAPABILITY_SINGLE_SHOT = 0x0000008;
    private static final int GPS_CAPABILITY_ON_DEMAND_TIME = 0x0000010;

    // Handler messages
    private static final int ENABLE = 2;
    private static final int HANDLE_NETWORK_CALLBACK = 3;
    private static final int INJECT_NTP_TIME = 5;
    private static final int DOWNLOAD_XTRA_DATA = 6;
    private static final int INJECT_NTP_TIME_FINISHED = 10;
    private static final int DOWNLOAD_XTRA_DATA_FINISHED = 11;
    private static final int REPORT_AGPS_STATUS = 12;
    private static final int GET_DEFAULT_APN_FINISHED = 13;

    // OsAgent if IzatProvider is not present
    private static OsAgent mOsAgent;

    // capabilities of the GPS engine
    private int mEngineCapabilities;

    // true if XTRA is supported
    private boolean mSupportsXtra;

    // set to true if the GPS engine does not do on-demand NTP time requests
    private boolean mPeriodicTimeInjection;

    // true if we are enabled, protected by this
    private boolean mEnabled;

    private Context mContext;

    private ConnectivityManager mConnMgr;
    private GpsNetInitiatedHandler mNIHandler;

    private String mDefaultApn;

    private boolean mWifiConnectivity = false;
    private boolean mWwanConnectivity = false;

    // NTP and xtra data download retry times
    private int mNTPRetryTimes = 0;
    private int mXtraDataRetryTimes = 0;

    // Wakelocks
    private final static String WAKELOCK_KEY = "LocationService";
    private PowerManager.WakeLock mWakeLock;

    private Object mLock = new Object();

    private Handler mHandler;

    //This class is used in sendMessage() to indicate whether or not a wakelock
    //is held when sending the message.
    private static class LocSvcMsgObj {
        Object obj;
        boolean wakeLockHeld;
        public LocSvcMsgObj (Object obj, Boolean wakeLock) {
            this.obj = obj;
            this.wakeLockHeld = wakeLock;
        }
    };

    @Override
    public void onCreate() {
        if (DEBUG) {
            Log.d(TAG, "onCreate ");
        }

        mContext = this;

        HandlerThread t = new HandlerThread(LocationService.class.getSimpleName());
        t.start();
        mHandler = new Handler(t.getLooper(), this);

        mNIHandler = new GpsNetInitiatedHandler(mContext, mNetInitiatedListener);

        // Create a wake lock
        PowerManager powerManager = (PowerManager) mContext.getSystemService(Context.POWER_SERVICE);
        mWakeLock = powerManager.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK, WAKELOCK_KEY);
        mWakeLock.setReferenceCounted(true);

        mConnMgr = (ConnectivityManager)mContext.getSystemService(Context.CONNECTIVITY_SERVICE);

        // IzatProvider may have instanced OsAgent previously
        mOsAgent = OsAgent.GetInstance(mContext, t.getLooper(), null);

        enable();

    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    private void sendMessage(int message, int arg1, int arg2, Object obj) {
        // hold a wake lock until this message is delivered
        // note that this assumes the message will not be removed from the queue before
        // it is handled (otherwise the wake lock would be leaked).
        if(DEBUG) {
            Log.d(TAG, "Sending msg: "+ message + " arg1:"+ arg1 +" arg2:"+ arg2);
        }
        mWakeLock.acquire();
        //wakeLockHeld in LocSvcMsgObj is set to true to indicate that
        //a wakelock is held before sending this message
        mHandler.obtainMessage(message, arg1, arg2,
                               new LocSvcMsgObj(obj, true)).sendToTarget();
    }

    private void sendMessage(int message, int arg, Object obj) {
        sendMessage(message, arg, 1, obj);
    }

    @Override
    public boolean handleMessage(Message msg) {
        int message = msg.what;
        LocSvcMsgObj msgObj=null;
        if (msg.obj != null) {
            msgObj = (LocSvcMsgObj)msg.obj;
        }
        switch (message) {
        case ENABLE:
            if (msg.arg1 == 1) {
                handleEnable();
            } else {
                handleDisable();
            }
            break;
        case REPORT_AGPS_STATUS:
            if(msgObj != null) {
                handleReportAgpsStatus((ReportAgpsStatusMessage)msgObj.obj);
            }
            break;
        case HANDLE_NETWORK_CALLBACK:
            if(msgObj != null) {
                handleNetworkCallback(msg.arg1, msg.arg2, (Network)msgObj.obj);
            }
            break;
        case GET_DEFAULT_APN_FINISHED:
            if(msgObj != null) {
                handleAgpsConnOpen((AGpsConnectionInfo)msgObj.obj);
            }
            break;
        }
        // if wakelock was taken for this message, release it
        if((msgObj != null) && (msgObj.wakeLockHeld)) {
            mWakeLock.release();
        }
        return true;
    }

    private void handleNetworkCallback(int state, int connType, Network network) {
        final NetworkInfo info = mConnMgr.getNetworkInfo(network);

        if (DEBUG) {
            Log.d(TAG, "handleNetworkCallback connTyp: "+ connType + " state: " +state+
                  " network:" +network+ " info:" +info);
        }

        AGpsConnectionInfo agpsConnInfo=getAGpsConnectionInfo(connType);
        if (agpsConnInfo != null) {
            if (agpsConnInfo.mState == AGpsConnectionInfo.STATE_OPENING) {
                if(state == NETWORK_UNAVAILABLE) {
                    if (DEBUG) Log.d(TAG, "call native_agps_data_conn_failed");
                    agpsConnInfo.mAPN = null;
                    agpsConnInfo.release(connType, false);
                    agpsConnInfo.mState = AGpsConnectionInfo.STATE_CLOSED;
                } else {
                    if (DEBUG) Log.d(TAG, "run thread to collect agpsConnInfo");
                    agpsConnInfo.mState = AGpsConnectionInfo.STATE_OPEN;

                    final AGpsConnectionInfo agpsConnInfoForApn = new AGpsConnectionInfo(agpsConnInfo);
                    Runnable getApnInfo = new Runnable() {
                        @Override
                        public void run() {
                            agpsConnInfoForApn.getApn(info);
                            agpsConnInfoForApn.getBearerType(info);

                            sendMessage(GET_DEFAULT_APN_FINISHED, 0, agpsConnInfoForApn);
                        }
                    };
                    AsyncTask.THREAD_POOL_EXECUTOR.execute(getApnInfo);
                }
            }
            else if(DEBUG) {
                Log.d(TAG, "agpsConnInfo.mState:"+agpsConnInfo.mState);
            }
        }
    }

    public void enable() {
        sendMessage(ENABLE, 1, null);
    }

    private void handleEnable() {
        if (DEBUG) Log.d(TAG, "handleEnable");

        synchronized (mLock) {
            if (mEnabled) return;
            mEnabled = true;
        }

        boolean enabled = native_init();

        if (enabled) {
            mSupportsXtra = true;
        } else {
            synchronized (mLock) {
                mEnabled = false;
            }
            Log.w(TAG, "Failed to enable location provider");
        }
    }

    public void disable() {
        sendMessage(ENABLE, 0, null);
    }

    private void handleDisable() {
        if (DEBUG) Log.d(TAG, "handleDisable");

        synchronized (mLock) {
            if (!mEnabled) return;
            mEnabled = false;
        }

        // do this before releasing wakelock
        native_cleanup();
    }

    public boolean isEnabled() {
        synchronized (mLock) {
            return mEnabled;
        }
    }

    private boolean hasCapability(int capability) {
        return ((mEngineCapabilities & capability) != 0);
    }

    /**
     * called from native code to inform us what the GPS engine capabilities are
     */
    private void setEngineCapabilities(int capabilities) {
        mEngineCapabilities = capabilities;

        if (!hasCapability(GPS_CAPABILITY_ON_DEMAND_TIME) && !mPeriodicTimeInjection) {
            mPeriodicTimeInjection = true;
            requestUtcTime();
        }
    }

    /**
     * called from native code to update AGPS status
     */
    private void reportAGpsStatus(int type, int apnTypeMask, int status) {
        if (DEBUG) Log.d(TAG, "reportAGpsStatus with type = " + type +
                              " apnTypeMask = " + apnTypeMask +
                              " status = " + status);
        ReportAgpsStatusMessage rasm = new ReportAgpsStatusMessage(type,
                                                                   apnTypeMask,
                                                                   status);

        LocSvcMsgObj obj = new LocSvcMsgObj((Object)rasm, false);
        Message msg = new Message();
        msg.what = REPORT_AGPS_STATUS;
        msg.obj = obj;

        mHandler.sendMessage(msg);
    }

    private void handleReportAgpsStatus(ReportAgpsStatusMessage rasm) {
        int type = rasm.type;
        int apnTypeMask = rasm.apnTypeMask;
        int status = rasm.status;

        if (DEBUG) Log.d(TAG, "handleReportAgpsStatus with type = " + type +
                              " apnTypeMask = " + apnTypeMask +
                              " status = " + status);

        AGpsConnectionInfo agpsConnInfo = getAGpsConnectionInfo(type);
        if (agpsConnInfo == null) {
            if (DEBUG) Log.d(TAG, "reportAGpsStatus agpsConnInfo is null for type "+type);
            // we do not handle this type of connection
            return;
        }

        switch (status) {
            case GPS_REQUEST_AGPS_DATA_CONN:
                if (DEBUG) Log.d(TAG, "GPS_REQUEST_AGPS_DATA_CONN");

                switch (type) {
                case AGpsConnectionInfo.CONNECTION_TYPE_SUPL:
                case AGpsConnectionInfo.CONNECTION_TYPE_C2K:
                case AGpsConnectionInfo.CONNECTION_TYPE_WWAN_ANY:
                case AGpsConnectionInfo.CONNECTION_TYPE_WIFI:
                case AGpsConnectionInfo.CONNECTION_TYPE_SUPL_ES:
                {
                    NetworkInfo info = mConnMgr.getNetworkInfo(agpsConnInfo.getCMConnType());
                    if (DEBUG) Log.d(TAG, "type: "+type);
                    agpsConnInfo.connect(type, apnTypeMask);
                    break;
                }
                default:
                    if (DEBUG) Log.e(TAG, "type == unknown");
                    break;
                }
                break;
            case GPS_RELEASE_AGPS_DATA_CONN: {
                if (DEBUG) Log.d(TAG, "GPS_RELEASE_AGPS_DATA_CONN");

                switch (type) {
                case AGpsConnectionInfo.CONNECTION_TYPE_SUPL:
                case AGpsConnectionInfo.CONNECTION_TYPE_C2K:
                case AGpsConnectionInfo.CONNECTION_TYPE_WWAN_ANY:
                case AGpsConnectionInfo.CONNECTION_TYPE_WIFI:
                case AGpsConnectionInfo.CONNECTION_TYPE_SUPL_ES:
                {
                    if (agpsConnInfo.mState == AGpsConnectionInfo.STATE_CLOSED) {
                        Log.e(TAG, "Release in CLOSED state !");
                    } else {
                        agpsConnInfo.release(type, true);
                        agpsConnInfo.mState = AGpsConnectionInfo.STATE_CLOSED;
                    }
                    break;
                }
                default:
                    if (DEBUG) Log.e(TAG, "GPS_RELEASE_AGPS_DATA_CONN but current network state is unknown!");
                    return;
                }
                break;
            }
            case GPS_AGPS_DATA_CONNECTED:
                if (DEBUG) Log.d(TAG, "GPS_AGPS_DATA_CONNECTED");
                break;
            case GPS_AGPS_DATA_CONN_DONE:
                if (DEBUG) Log.d(TAG, "GPS_AGPS_DATA_CONN_DONE");
                break;
            case GPS_AGPS_DATA_CONN_FAILED:
                if (DEBUG) Log.d(TAG, "GPS_AGPS_DATA_CONN_FAILED");
                break;
        }
    }

    private void handleAgpsConnOpen(AGpsConnectionInfo agpsConnInfo) {
        if (agpsConnInfo == null) {
            if (DEBUG) Log.d(TAG, "handleAgpsConnOpen agpsConnInfo is null");
            return;
        }

        if (DEBUG) {
            Log.d(TAG, "handleAgpsConnOpen mAgpsType: " +agpsConnInfo.mAgpsType+
                " mAPN: " +agpsConnInfo.mAPN+ " mBearerType: " +agpsConnInfo.mBearerType);
        }
        native_agps_data_conn_open(
            agpsConnInfo.mAgpsType,
            agpsConnInfo.mAPN,
            agpsConnInfo.mBearerType);
    }

    //=============================================================
    // NI Client support
    //=============================================================
    private final INetInitiatedListener mNetInitiatedListener = new INetInitiatedListener.Stub() {
        // Sends a response for an NI reqeust to HAL.
        @Override
        public boolean sendNiResponse(int notificationId, int userResponse)
        {
            // TODO Add Permission check

            if (DEBUG) Log.d(TAG, "sendNiResponse, notifId: " + notificationId +
                    ", response: " + userResponse);
            native_send_ni_response(notificationId, userResponse);
            return true;
        }
    };

    // Called by JNI function to report an NI request.
    public void reportNiNotification(
            int notificationId,
            int niType,
            int notifyFlags,
            int timeout,
            int defaultResponse,
            String requestorId,
            String text,
            int requestorIdEncoding,
            int textEncoding,
            String extras,  // Encoded extra data
            boolean esEnabled
        )
    {
        Log.i(TAG, "reportNiNotification: entered");
        Log.i(TAG, "notificationId: " + notificationId +
                ", niType: " + niType +
                ", notifyFlags: " + notifyFlags +
                ", timeout: " + timeout +
                ", defaultResponse: " + defaultResponse);

        Log.i(TAG, "requestorId: " + requestorId +
                ", text: " + text +
                ", requestorIdEncoding: " + requestorIdEncoding +
                ", textEncoding: " + textEncoding);

        GpsNiNotification notification = new GpsNiNotification();

        notification.notificationId = notificationId;
        notification.niType = niType;
        notification.needNotify = (notifyFlags & GpsNetInitiatedHandler.GPS_NI_NEED_NOTIFY) != 0;
        notification.needVerify = (notifyFlags & GpsNetInitiatedHandler.GPS_NI_NEED_VERIFY) != 0;
        notification.privacyOverride = (notifyFlags & GpsNetInitiatedHandler.GPS_NI_PRIVACY_OVERRIDE) != 0;
        notification.timeout = timeout;
        notification.defaultResponse = defaultResponse;
        notification.requestorId = requestorId;
        notification.text = text;
        notification.requestorIdEncoding = requestorIdEncoding;
        notification.textEncoding = textEncoding;

        // Process extras, assuming the format is
        // one of more lines of "key = value"
        Bundle bundle = new Bundle();

        if (extras == null) extras = "";
        Properties extraProp = new Properties();

        try {
            extraProp.load(new StringReader(extras));
        }
        catch (IOException e)
        {
            Log.e(TAG, "reportNiNotification cannot parse extras data: " + extras);
        }

        for (Entry<Object, Object> ent : extraProp.entrySet())
        {
            bundle.putString((String) ent.getKey(), (String) ent.getValue());
        }

        notification.extras = bundle;

        mNIHandler.handleNiNotification(notification, esEnabled);
    }

    /**
     * Called from native code to request utc time info
     */
    private void requestUtcTime() {
        sendMessage(INJECT_NTP_TIME, 0, null);
    }

    private String getDefaultApn() {
        Uri uri = Uri.parse("content://telephony/carriers/preferapn");
        String apn = null;

        try {
            Cursor cursor =
                mContext.getContentResolver().query(uri, new String[] {"apn"},
                                                    null, null, Carriers.DEFAULT_SORT_ORDER);
            if (null != cursor) {
                try {
                    if (cursor.moveToFirst()) {
                        apn = cursor.getString(0);
                    }
                } finally {
                    cursor.close();
                }
            }
        } catch (SQLiteException e) {
            Log.e(TAG, "SQLiteException on mContext.getContentResolver().query");
        } catch (Exception e) {
            Log.e(TAG, "Unknown exception"+e+" on mContext.getContentResolver().query");
        }

        if (apn == null) {
            apn = "dummy-apn";
        }

        if (DEBUG) Log.d(TAG, "getDefaultApn() returns: " + apn);
        return apn;
    }

    private static native void class_init_native();

    private native boolean native_init();
    private native void native_cleanup();

    // XTRA Support
    private native void native_inject_time(long time, long timeReference, int uncertainty);
    private native void native_inject_xtra_data(byte[] data, int length);
    private native int native_request_xtra_server();

    // AGPS Support
    private native void native_agps_data_conn_open(int agpsType, String apn, int bearerType);
    private native void native_agps_data_conn_closed(int agpsType);
    private native void native_agps_data_conn_failed(int agpsType);

    // Network-initiated (NI) Support
    private native void native_send_ni_response(int notificationId, int userResponse);

    // AGPS support
    private native void native_update_network_state(boolean connected, int type,
            boolean roaming, boolean available, String extraInfo, String defaultAPN);

    private static AGpsConnectionInfo[] mAGpsConnections = new AGpsConnectionInfo[4];
    private AGpsConnectionInfo getAGpsConnectionInfo(int connType) {
        if (DEBUG) Log.d(TAG, "getAGpsConnectionInfo connType - "+connType);
        switch (connType)
        {
        case AGpsConnectionInfo.CONNECTION_TYPE_WWAN_ANY:
        case AGpsConnectionInfo.CONNECTION_TYPE_C2K:
            if (null == mAGpsConnections[0])
                mAGpsConnections[0] = new AGpsConnectionInfo(
                        ConnectivityManager.TYPE_MOBILE, connType);
            return mAGpsConnections[0];
        case AGpsConnectionInfo.CONNECTION_TYPE_SUPL:
            if (null == mAGpsConnections[1])
                mAGpsConnections[1] = new AGpsConnectionInfo(
                        ConnectivityManager.TYPE_MOBILE_SUPL, connType);
            return mAGpsConnections[1];
        case AGpsConnectionInfo.CONNECTION_TYPE_WIFI:
            if (null == mAGpsConnections[2])
                mAGpsConnections[2] = new AGpsConnectionInfo(
                        ConnectivityManager.TYPE_WIFI, connType);
            return mAGpsConnections[2];
        case AGpsConnectionInfo.CONNECTION_TYPE_SUPL_ES:
            if (null == mAGpsConnections[3])
                mAGpsConnections[3] = new AGpsConnectionInfo(
                        ConnectivityManager.TYPE_MOBILE_HIPRI, connType);
            return mAGpsConnections[3];
        default:
            return null;
        }
    }

    private final class LocNetworkCallback extends NetworkCallback {
        private int connType;

        @Override
        public void onAvailable(Network network) {
            super.onAvailable(network);
            if (DEBUG) Log.d(TAG, "OnAvailable for: "+ connType);
            sendMessage(HANDLE_NETWORK_CALLBACK, NETWORK_AVAILABLE, connType, network);
        }

        @Override
        public void onUnavailable() {
            super.onUnavailable();
            if (DEBUG) Log.d(TAG, "OnUnavailable for: "+ connType);
            sendMessage(HANDLE_NETWORK_CALLBACK, NETWORK_UNAVAILABLE, connType, null);
        }

        @Override
        public void onLinkPropertiesChanged(Network network, LinkProperties lp) {
            super.onLinkPropertiesChanged(network,lp);
            if (DEBUG) {
                 Log.d(TAG, "onLinkPropertiesChanged type:" + connType +
                       " IPv4:" + lp.isIpv4Provisioned() + "IPv6:" + lp.isIpv6Provisioned());
            }
        }

        public int getConnType() {
            if (DEBUG) Log.d(TAG, "getConnType for: "+ connType);
            return connType;
        }

        public LocNetworkCallback(int type) {
            super();
            connType = type;
            if (DEBUG) Log.d(TAG, "New LocNetworkCallback for: "+ connType);
        }
    };

    private class AGpsConnectionInfo {
        // these need to match AGpsType enum in gps.h
        private static final int CONNECTION_TYPE_ANY = 0;
        private static final int CONNECTION_TYPE_SUPL = 1;
        private static final int CONNECTION_TYPE_C2K = 2;
        private static final int CONNECTION_TYPE_WWAN_ANY = 3;
        private static final int CONNECTION_TYPE_WIFI = 4;
        private static final int CONNECTION_TYPE_SUPL_ES = 5;

        // this must match the definition of gps.h
        private static final int BEARER_INVALID = -1;
        private static final int BEARER_IPV4 = 0;
        private static final int BEARER_IPV6 = 1;
        private static final int BEARER_IPV4V6 = 2;

        // for mState
        private static final int STATE_CLOSED = 0;
        private static final int STATE_OPENING = 1;
        private static final int STATE_OPEN = 2;
        private static final int STATE_KEEP_OPEN = 3;

        // for apnTypeMask
        private static final int APN_TYPE_MASK_DEFAULT =    0x0001;
        private static final int APN_TYPE_MASK_IMS =        0x0002;
        private static final int APN_TYPE_MASK_MMS =        0x0004;
        private static final int APN_TYPE_MASK_DUN =        0x0008;
        private static final int APN_TYPE_MASK_SUPL =       0x0010;
        private static final int APN_TYPE_MASK_HIPRI =      0x0020;
        private static final int APN_TYPE_MASK_FOTA =       0x0040;
        private static final int APN_TYPE_MASK_CBS =        0x0080;
        private static final int APN_TYPE_MASK_IA =         0x0100;
        private static final int APN_TYPE_MASK_EMERGENCY =  0x0200;

        // SUPL vs ANY (which really is non-SUPL)
        private final int mCMConnType;
        private final int mAgpsType;
        private final String mPHConnFeatureStr;
        private String mAPN;
        private int mIPvVerType;
        private int mState;
        private InetAddress mIpAddr;
        private int mBearerType;
        //Callback to send to ConnectivityManager
        private ConnectivityManager.NetworkCallback mNetworkCallback;

        private AGpsConnectionInfo(int connMgrConnType, int agpsType) {
            mCMConnType = connMgrConnType;
            mAgpsType = agpsType;
            if (ConnectivityManager.TYPE_MOBILE_SUPL == connMgrConnType) {
                mPHConnFeatureStr = Phone.FEATURE_ENABLE_SUPL;
            } else {
                mPHConnFeatureStr = Phone.FEATURE_ENABLE_HIPRI;
            }
            mAPN = null;
            mState = STATE_CLOSED;
            mIpAddr = null;
            mBearerType = BEARER_INVALID;
        }
        private AGpsConnectionInfo(AGpsConnectionInfo info) {
            this.mCMConnType = info.mCMConnType;
            this.mAgpsType = info.mAgpsType;
            this.mPHConnFeatureStr = info.mPHConnFeatureStr;
            this.mAPN = info.mAPN;
            this.mIPvVerType = info.mIPvVerType;
            this.mState = info.mState;
            this.mIpAddr = info.mIpAddr;
            this.mBearerType = info.mBearerType;
        }
        private int getAgpsType() {
            return mAgpsType;
        }
        private int getCMConnType() {
            return mCMConnType;
        }
        private InetAddress getIpAddr() {
            return mIpAddr;
        }
        private String getApn(NetworkInfo info) {

            if (info != null) {
                mAPN = info.getExtraInfo();
            }
            if (mAPN == null) {
                /* We use the value we read out from the database. That value itself
                   is default to "dummy-apn" if no value from database. */
                mDefaultApn = getDefaultApn();
                mAPN = mDefaultApn;
            }

            if (DEBUG) Log.d(TAG, "getApn(): " + mAPN);
            return mAPN;
        }
        private int getBearerType(NetworkInfo info) {
            if (mAPN == null) {
                mAPN = getApn(info);
            }
            String ipProtocol = null;
            TelephonyManager phone = (TelephonyManager)
                    mContext.getSystemService(Context.TELEPHONY_SERVICE);

            // get IP protocol here
            int networkType = phone.getNetworkType();
            String selection = null;
            if (TelephonyManager.NETWORK_TYPE_EHRPD == networkType) {
                selection = "apn = '" + mAPN + "'";
                selection += " and type LIKE '%supl%'";
            } else if (TelephonyManager.NETWORK_TYPE_UNKNOWN == networkType) {
                // UNKNOWN means no sim or not camped, so will not have current = 1
                selection = "apn = '" + mAPN + "'";
                selection += " and carrier_enabled = 1";
                if (CONNECTION_TYPE_SUPL_ES == mAgpsType) {
                    selection += " and type LIKE '%emergency%'";
                }
            } else {
                selection = "current = 1";
                selection += " and apn = '" + mAPN + "'";
                selection += " and carrier_enabled = 1";
            }

            try {
                Cursor cursor =
                    mContext.getContentResolver().query(Carriers.CONTENT_URI,
                                                        new String[] {Carriers.PROTOCOL},
                                                        selection, null,
                                                        Carriers.DEFAULT_SORT_ORDER);
                if (null != cursor) {
                    try {
                        if (cursor.moveToFirst()) {
                            ipProtocol = cursor.getString(0);
                        }
                    } finally {
                        cursor.close();
                    }
                }
            } catch (SQLiteException e) {
                Log.e(TAG, "SQLiteException on mContext.getContentResolver().query");
            } catch (Exception e) {
                Log.e(TAG, "Unknown exception"+e+" on mContext.getContentResolver().query");
            }
            Log.d(TAG, "ipProtocol: " + ipProtocol + " apn: " + mAPN +
                  " networkType: " + phone.getNetworkTypeName() + " state: " + mState);

            if (null == ipProtocol) {
                Log.w(TAG, "ipProtocol not found in db, default to ipv4v6");
                mBearerType = BEARER_IPV4V6;
            } else if (ipProtocol.equals("IPV6")) {
                mBearerType = BEARER_IPV6;
            } else if (ipProtocol.equals("IPV4V6")) {
                mBearerType = BEARER_IPV4V6;
            } else if (ipProtocol.equals("IPV4")) {
                mBearerType = BEARER_IPV4;
            } else {
                Log.e(TAG, "ipProtocol value not expected, default to ipv4v6");
                mBearerType = BEARER_IPV4V6;
            }

            return mBearerType;
        }

        private void connect(int connType, int apnTypeMask) {
            final ConnectivityManager connMgr =
                (ConnectivityManager) mContext.getSystemService(Context.CONNECTIVITY_SERVICE);
            if (DEBUG) {
                Log.d(TAG, "connect() type: " + connType + " apnTypeMask:" + apnTypeMask);
            }

            if(mNetworkCallback == null) {
                mNetworkCallback = new LocNetworkCallback(connType);
            }
            NetworkRequest.Builder requestBuilder = new NetworkRequest.Builder();
            requestBuilder.addTransportType(NetworkCapabilities.TRANSPORT_CELLULAR);
            if (((apnTypeMask & APN_TYPE_MASK_DEFAULT) != 0) ||
                ((apnTypeMask & APN_TYPE_MASK_HIPRI) != 0)) {
                requestBuilder.addCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET);
            }
            if ((apnTypeMask & APN_TYPE_MASK_IMS) != 0) {
                requestBuilder.addCapability(NetworkCapabilities.NET_CAPABILITY_IMS);
            }
            if ((apnTypeMask & APN_TYPE_MASK_MMS) != 0) {
                requestBuilder.addCapability(NetworkCapabilities.NET_CAPABILITY_MMS);
            }
            if ((apnTypeMask & APN_TYPE_MASK_DUN) != 0) {
                requestBuilder.addCapability(NetworkCapabilities.NET_CAPABILITY_DUN);
            }
            if ((apnTypeMask & APN_TYPE_MASK_SUPL) != 0) {
                requestBuilder.addCapability(NetworkCapabilities.NET_CAPABILITY_SUPL);
            }
            if ((apnTypeMask & APN_TYPE_MASK_FOTA) != 0) {
                requestBuilder.addCapability(NetworkCapabilities.NET_CAPABILITY_FOTA);
            }
            if ((apnTypeMask & APN_TYPE_MASK_CBS) != 0) {
                requestBuilder.addCapability(NetworkCapabilities.NET_CAPABILITY_CBS);
            }
            if ((apnTypeMask & APN_TYPE_MASK_IA) != 0) {
                requestBuilder.addCapability(NetworkCapabilities.NET_CAPABILITY_IA);
            }
            if ((apnTypeMask & APN_TYPE_MASK_EMERGENCY) != 0) {
                requestBuilder.addCapability(NetworkCapabilities.NET_CAPABILITY_EIMS);
            }
            NetworkRequest request = requestBuilder.build();
            connMgr.requestNetwork(request, mNetworkCallback,
                                   NETWORK_REQUEST_TIMEOUT_MS);
            mState = AGpsConnectionInfo.STATE_OPENING;
        }

        private void release(int connType, boolean success) {
            final ConnectivityManager connMgr =
                (ConnectivityManager) mContext.getSystemService(Context.CONNECTIVITY_SERVICE);
            if (DEBUG) Log.d(TAG, "release() type: "+connType);
            if(mNetworkCallback != null) {
                try {
                    connMgr.unregisterNetworkCallback(mNetworkCallback);
                } catch (IllegalArgumentException e) {
                    Log.e(TAG, "Exception in unregister NetworkCallback !");
                }
                if(success) {
                    native_agps_data_conn_closed(connType);
                }
                else {
                    native_agps_data_conn_failed(connType);
                }
            }
        }
    }

    private class ReportAgpsStatusMessage {
        int type;
        int apnTypeMask;
        int status;

        public ReportAgpsStatusMessage(int type, int apnTypeMask, int status) {
            this.type = type;
            this.apnTypeMask = apnTypeMask;
            this.status = status;
        }
    }

    static {
        System.loadLibrary("locationservice_jni");
        class_init_native();
    }
}
