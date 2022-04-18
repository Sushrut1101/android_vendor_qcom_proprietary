/*
 * Copyright (c) 2012-2013, 2015-2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Not a Contribution, Apache license notifications and license are retained
 * for attribution purposes only.
 *
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.qti.qualcomm.deviceinfo;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.res.Resources;
import android.content.SharedPreferences;
import android.os.AsyncResult;
import android.os.Binder;
import android.os.Build;
import android.os.Bundle;
import android.os.IBinder;
import android.os.Handler;
import android.os.Message;
import android.os.ServiceManager;
import android.os.RemoteException;
import android.os.SystemProperties;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceScreen;
import android.preference.PreferenceManager;
import android.telephony.CellLocation;
import android.telephony.TelephonyManager;
import android.telephony.cdma.CdmaCellLocation;
import android.telephony.SubscriptionManager;
import android.text.TextUtils;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

import com.android.internal.telephony.Phone;
import com.android.internal.telephony.IccCard;
import com.android.internal.telephony.uicc.IccUtils;
import com.android.internal.telephony.PhoneFactory;
import com.android.internal.telephony.TelephonyProperties;
import com.android.internal.telephony.uicc.IccConstants;
import com.android.internal.telephony.uicc.IccFileHandler;
import com.android.internal.telephony.uicc.IccRecords;
import com.android.internal.telephony.uicc.UiccController;
import com.android.internal.telephony.PhoneConstants;

import com.qualcomm.qti.qtisystemservice.ISystemService;

import org.codeaurora.internal.IExtTelephony;

/**
 * Display the following information # Battery Strength : TODO # Uptime # Awake
 * Time # XMPP/buzz/tickle status : TODO
 */
public class DeviceInfo extends PreferenceActivity {

    private static final String KEY_DEVICE_MODEL = "device_model";
    private static final String KEY_HW_VERSION = "hardware_version";
    private static final String KEY_MEID = "meid_number";
    private static final String KEY_ESN = "esn_number";
    private static final String KEY_BASEBAND_VERSION = "baseband_version";
    private static final String KEY_PRL_VERSION = "prl_version";
    private static final String KEY_ANDROID_VERSION = "android_version";
    private static final String KEY_SOFTWARE_VERSION = "software_version";
    private static final String KEY_PHONE_NUMBER = "number";
    private static final String KEY_IMSI = "imsi";
    private static final String KEY_UIM_ID = "uim_id";
    private static final String KEY_SID_NUMBER = "sid_number";
    private static final String KEY_NID_NUMBER = "nid_number";
    private static final String KEY_EPRL_NUMBER = "eprl_number";
    private static final String KEY_MSPL_NUMBER = "mspl_number";
    private static final String KEY_MLPL_NUMBER = "mlpl_number";
    private static final String KEY_ICCID_NUMBER = "iccid_number";
    private static final String KEY_IMEI_NUMBER_1 = "imei_number_1";
    private static final String KEY_IMEI_NUMBER_2 = "imei_number_2";
    private static final String KEY_META_VERSION = "meta_info";

    private static final String SP_MEID = "sp_meid";

    // Please get these values from IccConstants
    // CDMA RUIM file ids from 3GPP2 C.S0023-0
    // RUIM EF stores the (up to) 56-bit electronic identification
    // number (ID) unique to the R-UIM. (Removable UIM_ID)
    static final int EF_RUIM_ID = 0x6f31;

    // 3GPP2 C.S0065
    static final int EF_CSIM_PRL = 0x6F30;

    // C.S0074-Av1.0 Section 4
    static final int EF_CSIM_MLPL = 0x4F20;
    static final int EF_CSIM_MSPL = 0x4F21;
    //End of IccConstants value

    private Phone mPhone = null;
    private static String mUnknown = null;

    private static final String FILENAME_MSV = "/sys/board_properties/soc/msv";
    private static final String SYSTEM_SERVICE_PACKAGE = "com.qualcomm.qti.qtisystemservice";

    private ObtainIdHandler mHandler = new ObtainIdHandler();
    private IExtTelephony mExtTelephony = IExtTelephony.Stub.
            asInterface(ServiceManager.getService("extphone"));
    private SharedPreferences mSharedPreferences;
    private String mMetaInfo;
    private String mModel;

    private final ServiceConnection mSystemServiceConnection = new ServiceConnection() {

        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            ISystemService systemService = ISystemService.Stub.asInterface(service);
            if (systemService != null) {
                try {
                    mMetaInfo = systemService.getMetaInfo();
                    // get device model
                    if (!TextUtils.isEmpty(mMetaInfo)) {
                        String[] metaArray = mMetaInfo.split("\\.");
                        if (metaArray.length > 0) {
                            mModel = metaArray[0];
                        }
                    }
                } catch (RemoteException e) {
                }
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        DeviceInfo.this.setSummaryText(KEY_SOFTWARE_VERSION, mMetaInfo);
                        DeviceInfo.this.setSummaryText(KEY_DEVICE_MODEL, mModel);
                    }
                });
            }
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
        }
    };

    private class ObtainIdHandler extends Handler {
        private static final int MESSAGE_GET_EF_RUIM = 1;
        private static final int MESSAGE_GET_EF_PRL = 2;
        private static final int MESSAGE_GET_EF_MSPL = 3;
        private static final int MESSAGE_GET_EF_MLPL = 4;
        private static final int MESSAGE_GET_DEVICE_IDENTITY = 5;
        //RUIM ID is 8 bytes data
        private static final int NUM_BYTES_RUIM_ID = 8;
        //True PRL ID is x bytes data
        private static final int NUM_BYTES_PRL_ID = 4;
        //MSPL ID is x bytes data
        private static final int NUM_BYTES_MSPL_ID =5;
        //MLPL ID is 8 bytes data
        private static final int NUM_BYTES_MLPL_ID = 5;

        public void handleMessage(Message msg) {
            switch (msg.what) {
                case MESSAGE_GET_EF_RUIM:
                    handleGetEFRuim(msg);
                    break;
                case MESSAGE_GET_EF_PRL:
                    handleGetEFPrl(msg);
                    break;
                case MESSAGE_GET_EF_MSPL:
                    handleGetEFMspl(msg);
                    break;
                case MESSAGE_GET_EF_MLPL:
                    handleGetEFMlpl(msg);
                    break;
                case MESSAGE_GET_DEVICE_IDENTITY:
                    handleGetDeviceIdentity(msg);
                    break;
            }
        }

        private void handleGetEFRuim(Message msg) {
            AsyncResult ar = (AsyncResult) msg.obj;
            byte[] data = (byte[])ar.result;
            if (ar.exception == null) {
                //for RUIM ID data, the first byte represent the num bytes of valid data. From
                //the second byte to num+1 byte, it is valid RUIM ID data. And the second
                //byte is the lowest-order byte, the num+1 byte is highest-order
                int numOfBytes = data[0];
                if (numOfBytes < NUM_BYTES_RUIM_ID) {
                    byte[] decodeData = new byte[numOfBytes];
                    for (int i = 0; i < numOfBytes; i++) {
                        decodeData[i] = data[numOfBytes - i];
                    }
                    String ruimid = IccUtils.bytesToHexString(decodeData);
                    setSummaryText(KEY_UIM_ID, ruimid);
                }
            }
        }

        private void handleGetEFPrl(Message msg) {
            AsyncResult ar = (AsyncResult) msg.obj;
            byte[] data = (byte[]) ar.result;
            if (ar.exception == null) {
                if (data.length > NUM_BYTES_PRL_ID - 1) {
                    int prlId = ((data[2] & 0xFF) << 8) | (data[3] & 0xFF);
                    setSummaryText(KEY_PRL_VERSION, String.valueOf(prlId));
                }
            }
        }

        private void handleGetEFMspl(Message msg) {
            AsyncResult ar = (AsyncResult) msg.obj;
            byte[] data = (byte[])ar.result;
            if (ar.exception == null) {
                if (data.length > NUM_BYTES_MSPL_ID -1) {
                    int msplId = ((data[3] & 0xFF) << 8 ) | (data[4] & 0xFF);
                    setSummaryText(KEY_MSPL_NUMBER, String.valueOf(msplId));
                }
            }
        }

        private void handleGetEFMlpl(Message msg) {
            AsyncResult ar = (AsyncResult) msg.obj;
            byte[] data = (byte[])ar.result;
            if (ar.exception == null) {
                if (data.length > NUM_BYTES_MLPL_ID - 1) {
                    int mlplId = ((data[3] & 0xFF) << 8) | (data[4] & 0xFF);
                    setSummaryText(KEY_MLPL_NUMBER, String.valueOf(mlplId));
                }
            }
        }

        private void handleGetDeviceIdentity(Message msg) {
            AsyncResult ar = (AsyncResult) msg.obj;
            if (ar.exception == null) {
                String[] respId = (String[])ar.result;
                setSummaryText(KEY_MEID, respId[3]);
                // Need clear calling identity due to run in phone wiht system uid
                final long token = Binder.clearCallingIdentity();
                mSharedPreferences.edit().putString(SP_MEID, respId[3]).apply();
            }
        }

        public void GetRuimId() {
            UiccController controller = UiccController.getInstance();
            if (controller != null && mPhone != null) {
                IccFileHandler fh = controller.getIccFileHandler(mPhone.getPhoneId(), UiccController.APP_FAM_3GPP2);
                if (fh != null) {
                    //fh.loadEFTransparent(IccConstants.EF_RUIM_ID, NUM_BYTES_RUIM_ID,
                    fh.loadEFTransparent(EF_RUIM_ID, NUM_BYTES_RUIM_ID,
                            mHandler.obtainMessage(ObtainIdHandler.MESSAGE_GET_EF_RUIM));
                }
            }
        }

        public void getPrlVersion() {
            UiccController controller = UiccController.getInstance();
            if (controller != null && mPhone != null) {
                IccFileHandler fh = controller.getIccFileHandler(mPhone.getPhoneId(), UiccController.APP_FAM_3GPP2);
                if (fh != null) {
                    //fh.loadEFTransparent(IccConstants.EF_CSIM_PRL, NUM_BYTES_PRL_ID,
                    fh.loadEFTransparent(EF_CSIM_PRL, NUM_BYTES_PRL_ID,
                            mHandler.obtainMessage(ObtainIdHandler.MESSAGE_GET_EF_PRL));
                }
            }
        }

        public void getMsplVersion() {
            UiccController controller = UiccController.getInstance();
            if (controller != null && mPhone != null) {
                IccFileHandler fh = controller.getIccFileHandler(mPhone.getPhoneId(), UiccController.APP_FAM_3GPP2);
                if (fh != null) {
                    //fh.loadEFTransparent(IccConstants.EF_CSIM_MSPL, NUM_BYTES_MSPL_ID,
                    fh.loadEFTransparent(EF_CSIM_MSPL, NUM_BYTES_MSPL_ID,
                            mHandler.obtainMessage(ObtainIdHandler.MESSAGE_GET_EF_MSPL));
                }
            }
        }

        public void getMlplVersion() {
            UiccController controller = UiccController.getInstance();
            if (controller != null && mPhone != null) {
                IccFileHandler fh = controller.getIccFileHandler(mPhone.getPhoneId(), UiccController.APP_FAM_3GPP2);
                if (fh != null) {
                    //fh.loadEFTransparent(IccConstants.EF_CSIM_MLPL, NUM_BYTES_MLPL_ID,
                    fh.loadEFTransparent(EF_CSIM_MLPL, NUM_BYTES_MLPL_ID,
                            mHandler.obtainMessage(ObtainIdHandler.MESSAGE_GET_EF_MLPL));
                }
            }
        }

        public String getBasebandVersionForPhone(int phoneId, String defaultVal) {
            if (SubscriptionManager.isValidPhoneId(phoneId)) {
                return TelephonyManager.getDefault().getBasebandVersionForPhone(phoneId);
            }
            return defaultVal;
        }

        public void getDeviceIdentity() {
            if (mPhone != null) {
                mPhone.mCi.getDeviceIdentity(obtainMessage(MESSAGE_GET_DEVICE_IDENTITY));
            }
        }

    }

    @Override
    protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        addPreferencesFromResource(R.xml.device_info);

        bindService(new Intent().setComponent(new ComponentName(SYSTEM_SERVICE_PACKAGE,
                SYSTEM_SERVICE_PACKAGE + ".SystemService")),
                mSystemServiceConnection, Context.BIND_AUTO_CREATE);

        mSharedPreferences = PreferenceManager.getDefaultSharedPreferences(this);

        int phoneId = getCdmaPhoneId();
        if (phoneId != Integer.MAX_VALUE) {
            mPhone = PhoneFactory.getPhone(phoneId);
        }

        if (mUnknown == null) {
            mUnknown = getResources().getString(R.string.device_info_unknown);
        }

        setPreferenceSummary();
    }


    private int getCdmaPhoneId() {
        int phoneId = Integer.MAX_VALUE;
        try {
            if (mExtTelephony != null) {
                phoneId = mExtTelephony.getPrimaryStackPhoneId();
            }
        } catch (RemoteException ex) {
            int numPhone = TelephonyManager.getDefault().getPhoneCount();
            for (int i=0; i<numPhone; i++) {
                Phone phone = PhoneFactory.getPhone(i);
                if (phone.getPhoneType() == TelephonyManager.PHONE_TYPE_CDMA) {
                    phoneId = i;
                    break;
                }
            }
        }
        return phoneId;
    }

    private void setPreferenceSummary() {

        final PreferenceScreen prefSet = getPreferenceScreen();
        // get hardware
        String hwVersion = SystemProperties.get("ro.hw_version", mUnknown);
        if (TextUtils.isEmpty(hwVersion) || hwVersion.equals(mUnknown)) {
            hwVersion = "PVT2.0";
        }
        setSummaryText(KEY_HW_VERSION, hwVersion);

        // get android version
        setSummaryText(KEY_ANDROID_VERSION, Build.VERSION.RELEASE);

        // get my phone number
        if (mPhone != null) {
            // get baseband version
            String basebandVersion =
                    mHandler.getBasebandVersionForPhone(mPhone.getPhoneId(), null);
            setSummaryText(KEY_BASEBAND_VERSION, basebandVersion);

            // get MEID
            setSummaryText(KEY_MEID, getMeid());

            // get ESN
            setSummaryText(KEY_ESN, mPhone.getEsn());

            // get PRL version
            mHandler.getPrlVersion();

            // get IMSI
            String imsi = mPhone.getSubscriberId();
            if (imsi == null || imsi.length() == 0) {
                IccCard card = mPhone.getIccCard();
                if (card != null) {
                    IccRecords record = card.getIccRecords();
                    if (record != null) {
                        imsi = record.getIMSI();
                    }
                }
            }
            setSummaryText(KEY_IMSI, imsi);

            // get UIM ID
            mHandler.GetRuimId();

            // get EPrl number
            setSummaryText(KEY_EPRL_NUMBER, mPhone.getCdmaPrlVersion());

            // get Mspl number
            mHandler.getMsplVersion();

            // get Mlpl number
            mHandler.getMlplVersion();

            // get NID and SID
            CellLocation cellLocation = mPhone.getCellLocation();
            if (cellLocation != null && cellLocation instanceof CdmaCellLocation) {
                CdmaCellLocation cdmaCellLoc = (CdmaCellLocation)cellLocation;
                setSummaryText(KEY_SID_NUMBER, cdmaCellLoc.getSystemId() + "");
                setSummaryText(KEY_NID_NUMBER, cdmaCellLoc.getNetworkId() + "");
            }

            // get iccid
            setSummaryText(KEY_ICCID_NUMBER, mPhone.getFullIccSerialNumber());

            //get imei
            int numPhone = TelephonyManager.getDefault().getPhoneCount();
            for (int i = 0; i < PhoneConstants.MAX_PHONE_COUNT_DUAL_SIM; i++) {
                Phone phone = PhoneFactory.getPhone(i);
                String imei = null;
                if (i < numPhone) {
                    if (phone != null) {
                        imei = phone.getImei();
                    }
                    switch (i) {
                        case PhoneConstants.SUB1:
                             setSummaryText(KEY_IMEI_NUMBER_1, imei);
                        case PhoneConstants.SUB2:
                            setSummaryText(KEY_IMEI_NUMBER_2, imei);
                    }
                } else {
                    removePreference(KEY_IMEI_NUMBER_2, prefSet);
                }
            }
        }
    }

    private void setSummaryText(String preferenceKey, String value) {
        Preference preference = findPreference(preferenceKey);
        if (preference == null)
            return;

        if (TextUtils.isEmpty(value))
            preference.setSummary(mUnknown);
        else
            preference.setSummary(value);
    }

    private void removePreference(String preferenceKey, PreferenceScreen prefSet) {
        Preference preference = findPreference(preferenceKey);
        if (preference == null)
            return;

        prefSet.removePreference(preference);
    }

    /**
     * Returns " (ENGINEERING)" if the msv file has a zero value, else returns
     * "".
     *
     * @return a string to append to the model number description.
     */
    private static String getMsvSuffix() {
        // Production devices should have a non-zero value. If we can't read it,
        // assume it's a
        // production device so that we don't accidentally show that it's an
        // ENGINEERING device.
        try {
            String msv = readLine(FILENAME_MSV);
            // Parse as a hex number. If it evaluates to a zero, then it's an
            // engineering build.
            if (Long.parseLong(msv, 16) == 0) {
                return " (ENGINEERING)";
            }
        } catch (IOException ioe) {
            // Fail quietly, as the file may not exist on some devices.
        } catch (NumberFormatException nfe) {
            // Fail quietly, returning empty string should be sufficient
        }
        return "";
    }

    /**
     * Reads a line from the specified file.
     *
     * @param filename
     *            the file to read from
     * @return the first line, if any.
     * @throws IOException
     *             if the file couldn't be read
     */
    protected static String readLine(String filename) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filename),
                256);
        try {
            return reader.readLine();
        } finally {
            reader.close();
        }
    }

    protected static String readFile(String filePath) throws IOException {
        InputStreamReader inputStreamReader = new InputStreamReader(
                new FileInputStream(filePath), "UTF-8");
        StringBuilder stringBuilder = new StringBuilder();
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
        String line;
        while((line = bufferedReader.readLine()) != null) {
            stringBuilder.append(line);
            stringBuilder.append('\n');
        }
        bufferedReader.close();
        return stringBuilder.toString();
    }

    private String getMeid() {
        String meid = mSharedPreferences.getString(SP_MEID, "");
        if (invalidMeid(meid)) {
            if (mPhone != null) {
                meid = mPhone.getMeid();
                if (invalidMeid(meid)) {
                    meid = null;
                    mHandler.getDeviceIdentity();
                } else {
                    mSharedPreferences.edit().putString(SP_MEID, meid).apply();
                }
            }
        }
        return meid;
    }

    private boolean invalidMeid(String meid) {
        return TextUtils.isEmpty(meid) || meid.equals("0")
                || meid.startsWith("00000000");
    }

    @Override
    public void onDestroy() {
        super.onDestroy();

        unbindService(mSystemServiceConnection);
    }
}
