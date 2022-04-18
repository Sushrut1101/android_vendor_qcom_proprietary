/*
 * Copyright (c) 2015-2016, 2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 */

package org.codeaurora.ims;

import android.app.ActivityManager;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.os.Bundle;
import android.os.PersistableBundle;
import android.os.UserHandle;
import android.telephony.ims.feature.ImsFeature;
import android.telephony.CarrierConfigManager;
import android.telephony.SubscriptionInfo;
import android.telephony.SubscriptionManager;

import com.android.internal.telephony.IccCardConstants;
import com.android.internal.telephony.PhoneConstants;
import com.qualcomm.ims.utils.Log;

import java.util.List;

/**
 * This ImsServiceStateReceiver is generic class which is used to handle
 * ims service state and do required process.
 */
public class ImsServiceStateReceiver extends BroadcastReceiver {
    private static final String LOG_TAG = "ImsServiceStateReceiver";
    //This flag will be set to false during initialization.
    private boolean mShowHDIcon = true;
    private boolean mShowVOLTEIcon = false;

    private ImsServiceSub mServiceSub;
    private Context mContext;
    private int mPhoneId = SubscriptionManager.INVALID_PHONE_INDEX;

    private NotificationManager mNotificationMgr = null;

    //Unique number to show HD icon on notification bar
    private static final int IMS_HD_ICON = 1000;
    private static String CHANNEL_ID = "ims_services_channel_";
    private static final String SHOW_HD_ICON = "config_update_service_status";
    private static final String SHOW_VOLTE_ICON = "config_update_volte_icon";

    public ImsServiceStateReceiver(ImsServiceSub serviceSub, Context context, int phoneId) {
        mServiceSub = serviceSub;
        mContext = context;
        mPhoneId = phoneId;
    }

    public void updateHDIcon(boolean isVideoCapable, boolean isVoiceCapable) {
        Log.i(LOG_TAG, "updateHDIcon isVideo : " + isVideoCapable + " isVoice : " +
                isVoiceCapable + " phoneId: " + mPhoneId + " show HD Icon: " + mShowHDIcon);
        if (ImsCallUtils.isCarrierOneSupported()) {
            return;
        }

        if (mServiceSub.getFeatureState() == ImsFeature.STATE_READY) {
            if (shallShowHDIcon()) {
                showHDIcon(isVideoCapable || isVoiceCapable);
            } else {
                // Remove the HD icon during phone process crash/SIM Remove.
                showHDIcon(false);
            }
        } else {
            // Remove the HD icon if featureState is not STATE_READY
            showHDIcon(false);
        }
    }

    public static void overrideNotificationAppName(Context context, Notification.Builder n) {
        final Bundle extras = new Bundle();
        extras.putString(Notification.EXTRA_SUBSTITUTE_APP_NAME,
                context.getResources().getString(R.string.hd_icon_header_app_name));
        n.addExtras(extras);
    }

    private void showHDIcon(boolean showHDIcon) {
        if (mShowHDIcon == showHDIcon) return;

        if (mNotificationMgr == null) {
            try {
                mNotificationMgr = (NotificationManager) mContext.createPackageContextAsUser(
                        mContext.getPackageName(), 0, UserHandle.of(ActivityManager.
                        getCurrentUser())).getSystemService(Context.NOTIFICATION_SERVICE);
            } catch (PackageManager.NameNotFoundException e) {
                Log.w(LOG_TAG, "showHDIcon Package name not found: " + e.getMessage());
            }
        }

        if (mNotificationMgr == null) {
            Log.e(LOG_TAG, "showHDIcon unable to show HD icon due to NotificationManager is null");
            return;
        }

        mShowHDIcon = showHDIcon;
        if (mShowHDIcon) {
            NotificationChannel channel = mNotificationMgr.
                getNotificationChannel(CHANNEL_ID + mPhoneId);
            if (channel == null) {
                CharSequence name = mContext.getResources().getString(R.string.ims_channel_name);
                int importance = NotificationManager.IMPORTANCE_LOW;
                channel = new NotificationChannel(CHANNEL_ID + mPhoneId, name, importance);
                mNotificationMgr.createNotificationChannel(channel);
            }
            Notification.Builder builder = new Notification.Builder(mContext);
            builder.setChannelId(channel.getId());
            if (mShowVOLTEIcon) {
                builder.setContentTitle(mContext.getResources().getString(
                        R.string.device_is_volte_capable,
                        mPhoneId + 1));
                builder.setSmallIcon(R.drawable.volte_icon);
            } else {
                builder.setContentTitle(mContext.getResources().getString(
                        R.string.device_is_hd_capable,
                        mPhoneId + 1));
                builder.setSmallIcon(R.drawable.ims_state);
            }
            builder.setShowWhen(false);
            overrideNotificationAppName(mContext, builder);
            Notification notification = builder.build();
            notification.flags |= Notification.FLAG_NO_CLEAR;
            mNotificationMgr.notify(IMS_HD_ICON + mPhoneId, notification);
        } else {
            mNotificationMgr.cancel(IMS_HD_ICON + mPhoneId);
        }
    }

    private boolean shallShowHDIcon() {
        boolean showHDIcon = false;
        SubscriptionManager subManager = (SubscriptionManager) mContext.getSystemService(
                Context.TELEPHONY_SUBSCRIPTION_SERVICE);
        if (subManager == null) {
            Log.i(LOG_TAG, "shallShowHDIcon SubscriptionManager is null");
            return showHDIcon;
        }

        SubscriptionInfo subInfo = subManager.getActiveSubscriptionInfoForSimSlotIndex(mPhoneId);
        if (subInfo == null) {
            Log.i(LOG_TAG, "shallShowHDIcon SubscriptionInfo is null");
            return showHDIcon;
        }

        int subId = subInfo.getSubscriptionId();

        if (!subManager.isActiveSubscriptionId(subId)) {
            Log.i(LOG_TAG, "shallShowHDIcon subId is not active");
            return showHDIcon;
        }
        CarrierConfigManager mgr = (CarrierConfigManager) mContext.getSystemService(
                Context.CARRIER_CONFIG_SERVICE);
        PersistableBundle b = null;
        if (mgr != null) {
            b = mgr.getConfigForSubId(subId);
        }
        if (b != null) {
            showHDIcon = b.getBoolean(SHOW_HD_ICON, false);
            mShowVOLTEIcon = b.getBoolean(SHOW_VOLTE_ICON, false);
        }
        Log.i(LOG_TAG, "shallShowHDIcon config showHDIcon : " + showHDIcon +
                " phoneId : " + mPhoneId);
        return showHDIcon;
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        if (Intent.ACTION_SIM_STATE_CHANGED.equals(intent.getAction())) {
            String simStatus = intent.getStringExtra(IccCardConstants.INTENT_KEY_ICC_STATE);
            int phoneId = intent.getIntExtra(PhoneConstants.PHONE_KEY,
                    SubscriptionManager.INVALID_SUBSCRIPTION_ID);
            Log.d(LOG_TAG, "SimStateReceiver phoneId : " + phoneId + " simStatus : " +
                    simStatus);
            if (phoneId == mPhoneId && IccCardConstants.INTENT_VALUE_ICC_LOADED.
                    equals(simStatus)) {
                updateHDIcon(mServiceSub.isVideoSupported(), mServiceSub.isVoiceSupported());
                //Update latest known UT value to framework as the UT be reset when IMS
                //capabilities come earlier than carrier config sometimes at boot time.
                mServiceSub.onIccLoaded();
            }
        } else if (intent != null && intent.getAction()
                .equals(CarrierConfigManager.ACTION_CARRIER_CONFIG_CHANGED)) {
            int phoneId = intent.getIntExtra(CarrierConfigManager.EXTRA_SLOT_INDEX,
                    SubscriptionManager.INVALID_PHONE_INDEX);
            Log.d(LOG_TAG, "received carrier config change, phoneId : " + phoneId);
            if (phoneId == mPhoneId) {
                updateHDIcon(mServiceSub.isVideoSupported(), mServiceSub.isVoiceSupported());
            }
        }
    }
}
