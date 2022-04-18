/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2015 - 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
package com.qualcomm.location.izat;

import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.IBinder;
import android.os.ServiceManager;
import android.util.Log;

import com.qti.wwandbprovider.IWWANDBProvider;
import com.qualcomm.location.izat.flp.FlpServiceProvider;
import com.qti.flp.IFlpService;
import com.qti.flp.ITestService;
import com.qualcomm.location.izat.geofence.GeofenceServiceProvider;
import com.qti.geofence.IGeofenceService;
import com.qualcomm.location.izat.debugreport.DebugReportService;
import com.qti.debugreport.IDebugReportService;
import com.qti.izat.IIzatService;
import com.qti.wifidbreceiver.IWiFiDBReceiver;
import com.qualcomm.location.izat.wifidbreceiver.WiFiDBReceiver;
import com.qti.wwandbreceiver.IWWANDBReceiver;
import com.qualcomm.location.izat.wwandbprovider.WWANDBProvider;
import com.qualcomm.location.izat.wwandbreceiver.WWANDBReceiver;
import com.qti.gnssconfig.IGnssConfigService;
import com.qualcomm.location.izat.gnssconfig.GnssConfigService;
import com.qti.wifidbprovider.IWiFiDBProvider;
import com.qualcomm.location.izat.wifidbprovider.WiFiDBProvider;

public class IzatService extends Service {
    private static final String TAG = "IzatService";
    private static final String Service_Version = "7.2.1";
    private static final boolean VERBOSE = Log.isLoggable(TAG, Log.VERBOSE);
    private static final String IZAT_SERVICE_NAME = "com.qualcomm.location.izat.IzatService";
    private static final String ACCESS_FINE_LOCATION =
            android.Manifest.permission.ACCESS_FINE_LOCATION;
    private static final String GTPWIFI_PERMISSION = "com.qualcomm.permission.ACCESS_GTPWIFI_API";
    private static final String GTPWWAN_PERMISSION = "com.qualcomm.permission.ACCESS_GTPWWAN_API";
    private static final String GTPWIFI_CROWDSOURCING_PERMISSION =
            "com.qualcomm.permission.ACCESS_GTPWIFI_CROWDSOURCING_API";
    private static final String GTPWWAN_CROWDSOURCING_PERMISSION =
            "com.qualcomm.permission.ACCESS_GTPWWAN_CROWDSOURCING_API";
    private Context mContext;

    @Override
    public void onCreate() {
        if (VERBOSE) {
            Log.d(TAG, "onCreate");
        }
        mContext = this;
        // register izat service on entry
        if (ServiceManager.getService(IZAT_SERVICE_NAME) == null) {
            Log.d(TAG, "register Izat service on entry");
            ServiceManager.addService(IZAT_SERVICE_NAME, mBinder.asBinder());
        }
    }

    @Override
    public IBinder onBind(Intent intent) {
        if (VERBOSE) {
            Log.d(TAG, "onBind");
        }
        if ("com.qualcomm.location.izat.IzatService".equals(intent.getAction())) {
            if (VERBOSE) {
                Log.d(TAG, "Got a binding request.");
            }
            return mBinder;
        } else {
            return null;
        }
    }

    /* Remote binder */
    private final IIzatService.Stub mBinder = new IIzatService.Stub() {
        public IFlpService getFlpService() {
            if (mContext.checkCallingPermission(ACCESS_FINE_LOCATION) !=
                    PackageManager.PERMISSION_GRANTED) {
                throw new SecurityException("Requires ACCESS_FINE_LOCATION permission");
            }
            FlpServiceProvider flpServiceProvider =
                FlpServiceProvider.getInstance(mContext);
            if (null == flpServiceProvider) {
                return null;
            }
            return flpServiceProvider.getFlpBinder();
        }
        public ITestService getTestService() {
            FlpServiceProvider flpServiceProvider =
                FlpServiceProvider.getInstance(mContext);
            if (null == flpServiceProvider) {
                return null;
            }
            return flpServiceProvider.getFlpTestingBinder();
        }
        public IGeofenceService getGeofenceService() {
            if (mContext.checkCallingPermission(ACCESS_FINE_LOCATION) !=
                    PackageManager.PERMISSION_GRANTED) {
                throw new SecurityException("Requires ACCESS_FINE_LOCATION permission");
            }
            GeofenceServiceProvider geofenceServiceProvider =
                GeofenceServiceProvider.getInstance(mContext);
            if (null == geofenceServiceProvider) {
                return null;
            }
            return geofenceServiceProvider.getGeofenceBinder();
        }
        public String getVersion() {
            return Service_Version;
        }
        public IDebugReportService getDebugReportService() {
            DebugReportService debugReportService =
                DebugReportService.getInstance(mContext);
            if (null == debugReportService) {
                return null;
            }
            return debugReportService.getDebugReportBinder();
        }
        public IWiFiDBReceiver getWiFiDBReceiver() {
            if (mContext.checkCallingPermission(GTPWIFI_PERMISSION) !=
                    PackageManager.PERMISSION_GRANTED) {
                throw new SecurityException("Requires ACCESS_GTPWIFI_API permission");
            }
            WiFiDBReceiver wifiDBReceiver = WiFiDBReceiver.getInstance(mContext);
            return wifiDBReceiver.getWiFiDBReceiverBinder();
        }
        public IWWANDBReceiver getWWANDBReceiver() {
            if (mContext.checkCallingPermission(GTPWWAN_PERMISSION) !=
                    PackageManager.PERMISSION_GRANTED) {
                throw new SecurityException("Requires ACCESS_GTPWWAN_API permission");
            }
            WWANDBReceiver wwanDBReceiver = WWANDBReceiver.getInstance(mContext);
            return wwanDBReceiver.getWWANDBReceiverBinder();
        }
        public IGnssConfigService getGnssConfigService() {
            GnssConfigService gnssConfigService =
                    GnssConfigService.getInstance(mContext);
            if (null == gnssConfigService) {
                return null;
            }
            return gnssConfigService.getGnssConfigBinder();
        }
        public IWiFiDBProvider getWiFiDBProvider() {
            if (mContext.checkCallingPermission(GTPWIFI_CROWDSOURCING_PERMISSION) !=
                    PackageManager.PERMISSION_GRANTED) {
                throw new SecurityException("Requires ACCESS_GTPWIFI_CROWDSOURCING_API permission");
            }
            WiFiDBProvider wifiDBProvider = WiFiDBProvider.getInstance(mContext);
            return wifiDBProvider.getWiFiDBProviderBinder();
        }
        public IWWANDBProvider getWWANDBProvider() {
            if (mContext.checkCallingPermission(GTPWWAN_CROWDSOURCING_PERMISSION) !=
                    PackageManager.PERMISSION_GRANTED) {
                throw new SecurityException("Requires GTPWWAN_CROWDSOURCING_PERMISSION permission");
            }
            WWANDBProvider wwanDBProvider = WWANDBProvider.getInstance(mContext);
            return wwanDBProvider.getWWANDBProviderBinder();
        }
    };
}
