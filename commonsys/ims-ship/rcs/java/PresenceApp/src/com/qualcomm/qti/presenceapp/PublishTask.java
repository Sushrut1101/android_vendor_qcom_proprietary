/*************************************************************************
 Copyright (c)2017 Qualcomm Technologies, Inc.  All Rights Reserved.
 Qualcomm Technologies Proprietary and Confidential.
*************************************************************************/

package com.qualcomm.qti.presenceapp;

import android.app.ProgressDialog;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.os.Looper;
import android.os.RemoteException;
import android.util.Log;
import android.widget.Toast;

import com.android.ims.internal.uce.presence.*;
import com.qualcomm.qti.presenceapp.R;
import com.android.ims.internal.uce.common.CapInfo;
import com.android.ims.internal.uce.common.StatusCode;

public class PublishTask extends AsyncTask<Boolean, Integer, Integer> {

    public int audioSupported;
    public int videoSupported = 0;
    final String TAG = "PublishTask ";
    Context mContext;
    ProgressDialog dialog;
    PublishTask me;
    Boolean manualPublish = false;
    PresCapInfo pMyCapInfo = null;
    CapInfo cdInfo = new CapInfo();

    public PublishTask() {
        mContext = AppGlobalState.getMainActivityContext();
        me = this;
        ContactInfo.firstPublish = true;
    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
    }

    private void initProgressBar() {
        mContext = AppGlobalState.getMainActivityContext();
        dialog = new ProgressDialog(mContext);
        dialog.setMessage("API Request in progress...");
        dialog.setCancelable(false);
        dialog.show();
    }

    @Override
    protected Integer doInBackground(Boolean... params) {

        manualPublish = params[0];
        Log.d(TAG, "doInBackground(), Thread=" +
                Thread.currentThread().getName());

        if (Looper.myLooper() == null) {
            Looper.prepare();
        }
        return sendPublishRequest();
    }

    private int sendPublishRequest() {
        Log.d(TAG, "sendPublishRequest");


        if(AppGlobalState.isCustomFTEnabled()) {
            String[] exFeatureTags = AppGlobalState.GetCustomFT();
            String[] exServiceDesc = AppGlobalState.GetCustomFTSvcDesc();
            String[] exServiceId = AppGlobalState.GetCustomFTSvcID();
            for(int i = 0; i< 3 ; i++) {
                Log.d("PRESENCE_UI", "sendPublishRequest :exFeatureTags [" + exFeatureTags[i] + "]");
                Log.d("PRESENCE_UI", "sendPublishRequest :exServiceDesc [" + exServiceDesc[i] + "]");
                Log.d("PRESENCE_UI", "sendPublishRequest :exServiceId [" + exServiceId[i] + "]");
                PresServiceInfo pServuceInfo = new PresServiceInfo();
                pServuceInfo.setServiceDesc(exServiceDesc[i]);
                pServuceInfo.setServiceId(exServiceId[i]);
                pServuceInfo.setServiceVer("1.0");
                try
                {
                    StatusCode status = AppGlobalState.getPresenceService().setNewFeatureTag(AppGlobalState.getPresenceSerrviceHandle(),
                                                                                             exFeatureTags[i],pServuceInfo,
                                                                                             AppGlobalState.getpUserData());
                    Log.d("PRESENCE_UI", "sendPublishRequest : status "+status.getStatusCode());
                } catch (Exception e)
                {
                    e.printStackTrace();
                    Log.d("PRESENCE_UI", "sendPublishRequest :Unable to set Feature tag");
                }
            }
        }
        pMyCapInfo = new PresCapInfo();

        SharedPreferences setting = getSharedPrefHandle(AppGlobalState.IMS_PRESENCE_MY_INFO);

        String myNum = setting.getString(
                mContext.getString(R.string.myNumtext), "");
        String uri1 = setting.getString(
                mContext.getString(R.string.uri1text), "");
        String uri2 = setting.getString(
                mContext.getString(R.string.uri2text), "");

        int statusValue = 0;
        if (!ContactInfo.networkTypeLTE || !ContactInfo.vopsEnabled) {
            statusValue = 0; // CLOSED
            Log.d("PRESENCE_UI", TAG+"CLOSED statusValue ==" + statusValue);
        } else {
            statusValue = 1;
            Log.d("PRESENCE_UI", TAG+"statusValue ==" + statusValue);
        }

        String description = setting.getString(
                mContext.getString(R.string.descriptiontext), "");
        String ver = setting.getString(
                mContext.getString(R.string.vertext), "");
        String serviceId = setting.getString(
                mContext.getString(R.string.serviceIdtext), "");

         audioSupported = 1;
         videoSupported = 0;

        SharedPreferences preferences = mContext.getSharedPreferences(
                "ImsPresencePrefMyInfo", mContext.MODE_PRIVATE);

        SharedPreferences presencePref = mContext.getSharedPreferences(
                "presencedata", Context.MODE_PRIVATE);

        SharedPreferences.Editor editor = preferences.edit();

        boolean vt_chk = presencePref.getBoolean("VT_KEY", false);
        Log.d(TAG, "vt_chk :"+vt_chk);

        Log.d("PRESENCE_UI", TAG+"Settings.isVt_calling_enabled =" + Settings.isVt_calling_enabled);
        Log.d("PRESENCE_UI", TAG+"Settings.isMobile_data_enabled =" + Settings.isMobile_data_enabled);

        if(((Settings.isVt_calling_enabled && Settings.isMobile_data_enabled) ||
          (Settings.isVt_calling_enabled && ContactInfo.networkTypeIWLAN) &&
                  AppGlobalState.getOperatorMode() != AppGlobalState.ATT_MODE)){

               Log.d("PRESENCE_UI", TAG+"Video is supported 1 and DATA is ON from NV");
               videoSupported = 1;
               editor.putString("Description", "VoLTE Voice and Video Service");
               description = "VoLTE Voice and Video Service";

           } else {
               Log.d("PRESENCE_UI",
                       "Video is not supported and DATA is OFF from NV");
               videoSupported = 0;
               editor.putString("Description", "VoLTE Service");
               description = "VoLTE Service";
        }

        editor.commit();
//ATT
     if(AppGlobalState.getOperatorMode() == AppGlobalState.ATT_MODE)
        {
            Log.d(TAG, "AppGlobalState.ATT_MODE : vt_chk :"+vt_chk);
      Log.d(TAG, "ContactInfo.networkTypeLTE:"+ContactInfo.networkTypeLTE);
            Log.d(TAG, "ContactInfo.vopsEnabled:"+ContactInfo.vopsEnabled);
            Log.d(TAG, "ContactInfo.networkTypeIWLAN:"+ContactInfo.networkTypeIWLAN);

            if ( ((ContactInfo.networkTypeLTE && ContactInfo.vopsEnabled) || (!ContactInfo.networkTypeLTE && !ContactInfo.vopsEnabled && ContactInfo.networkTypeIWLAN) ) && Settings.isVt_calling_enabled)
            {
                audioSupported = 1;
                videoSupported = 1;
            } else {
                audioSupported = 0;
                videoSupported = 0;
            }
            //incase if mobile data is disabled and vt is enabled, then video tuple should not go in publish request
           if(!Settings.isMobile_data_enabled)
                videoSupported = 0;
        }

//TMO/VZW
if(AppGlobalState.getOperatorMode() != AppGlobalState.ATT_MODE)
        {
        Log.d(TAG, "OPERATOR_MODE:"+AppGlobalState.getOperatorMode());

        Log.d(TAG, "ContactInfo.networkTypeLTE:"+ContactInfo.networkTypeLTE);
        Log.d(TAG, "ContactInfo.vopsEnabled:"+ContactInfo.vopsEnabled);
        Log.d(TAG, "ContactInfo.networkTypeIWLAN:"+ContactInfo.networkTypeIWLAN);


        if ((ContactInfo.networkTypeLTE && ContactInfo.vopsEnabled) || ContactInfo.networkTypeIWLAN)
        {
          audioSupported = 1;
        }

        if ((!ContactInfo.networkTypeLTE || !ContactInfo.vopsEnabled) && !ContactInfo.networkTypeIWLAN)
        {
          audioSupported = 0;
          videoSupported = 0;
        }
  }
        Log.d(TAG, "audioSupported:"+audioSupported);
        Log.d(TAG, "videoSupported:"+videoSupported);

        String myNumUri = uri1 + myNum + uri2;

        Log.d("PRESENCE_UI", TAG+"statusValue 2 ==" + statusValue);

        Log.d("PRESENCE_UI", TAG+"myNumUri = " + myNumUri + " description = " + description + " ver = "
                + ver +
                " serviceId=" + serviceId + " audioSupported =  " + audioSupported
                + " videoSupported=  " + videoSupported);


        cdInfo.setIpVoiceSupported(((audioSupported ==0) ?false: true));
        cdInfo.setIpVideoSupported(((videoSupported == 0) ?false:true));
        //hard code these for now ----------------
        //FTs as part of GSMA spec 7.0 enabled for TMO & VZW
        if(AppGlobalState.getOperatorMode() != AppGlobalState.ATT_MODE)
        {
          cdInfo.setGeoSmsSupported(true);
          cdInfo.setCallComposerSupported(true);
          cdInfo.setPostCallSupported(true);
          cdInfo.setSharedMapSupported(true);
          cdInfo.setSharedSketchSupported(true);
        }

        if(AppGlobalState.getOperatorMode() == AppGlobalState.TMO_MODE)
        {
          cdInfo.setChatbotSupported(true);
          cdInfo.setChatbotRoleSupported(true);
        }
        //end hardcoded feature tags -----------

        Log.d("PRESENCE_UI", TAG+"myNumUri is filled");
        if (myNumUri.length() > 0)
        {
            pMyCapInfo.setContactUri(myNumUri);
        }


        if(!manualPublish) {
          Log.d("PRESENCE_UI", TAG+"invokeCDOptionsOnPublish()");
          invokeCDOptionsOnPublish();
        }

        pMyCapInfo.setCapInfo(cdInfo);

            try
            {
                if(AppGlobalState.getPresenceService() != null)
                {
                    Log.d("PRESENCE_UI", TAG+"PublishTask : sendPublishRequest : AppGlobalState.getPresenceSerrviceHandle() "+AppGlobalState.getPresenceSerrviceHandle());
                    Log.d("PRESENCE_UI", TAG+"PublishTask : sendPublishRequest : pMyCapInfo "+pMyCapInfo.getContactUri());
          //Log.d("PRESENCE_UI", TAG+"PublishTask : sendPublishRequest : pMyCapInfo "+pMyCapInfo.getca);
                    RequestInfo requestinfoObject = new RequestInfo();
                    requestinfoObject.URI = new String[1];
                    requestinfoObject.URI[0] = pMyCapInfo.getContactUri();
                    requestinfoObject.userData = AppGlobalState.getpUserDataValue();
                    AppGlobalState.requestinfo.add(requestinfoObject);
                    if(AppGlobalState.isCustomFTEnabled()) {
                        cdInfo.setExts(AppGlobalState.GetCustomFT());
                    }
                    pMyCapInfo.setCapInfo(cdInfo);

                    StatusCode status = AppGlobalState.getPresenceService().publishMyCap(AppGlobalState.getPresenceSerrviceHandle(), pMyCapInfo, AppGlobalState.getpUserData());

                    Log.d("PRESENCE_UI", TAG+"manualPublish:"+manualPublish);



                    Log.d("PRESENCE_UI", TAG+"PublishTask : sendPublishRequest : status "+status.getStatusCode());
                    return status.getStatusCode();
                }
                else
                {
                    Log.d("PRESENCE_UI","getPresenceService null");
                    Log.d("PRESENCE_UI", TAG+"PublishTask : sendPublishRequest ");
                    return -1;
                }
            } catch (RemoteException e) {
                e.printStackTrace();
                Log.d("PRESENCE_UI", TAG+"RemoteException, Dont sent PUBLISH");
                return -2;
            } catch (Exception e) {
                Log.d("PRESENCE_UI", TAG+"Exception, Dont sent PUBLISH");
                return -3;
            }
    }


    private void invokeCDOptionsOnPublish() {

        SharedPreferences presencePref = mContext.getSharedPreferences(
                    "presencedata", Context.MODE_PRIVATE);

        try {

             Log.d("PRESENCE_UI", TAG+"AppGlobalState.getCdService():"+AppGlobalState.getCdService());

            if (AppGlobalState.getCdService() != null) {

                cdInfo = AppGlobalState.GetCdInfo();

                boolean ftSupported = presencePref.getBoolean("FT_KEY", false);
                boolean chatSupported = presencePref.getBoolean("CHAT_KEY",
                        false);
                boolean ftThumbnailSupported = presencePref.getBoolean(
                        "FT_THUMB_KEY", false);
                boolean ftSnFSupported = presencePref.getBoolean("FT_SNF_KEY",
                        false);
                boolean ipmeSupported = presencePref.getBoolean("IPME_KEY",
                        false);
                boolean presenceSupported = presencePref.getBoolean("PRESENCE_KEY",
                        false);
                boolean ftHttpSupported = presencePref.getBoolean("FT_HTTP_KEY",false);

                /* Hardcoding for now */
                boolean chatbotSupported = true;
                boolean chatbotRoleSupported = true;
                boolean geoSmsSupported = true;
                boolean callComposerSupported = true;
                boolean postCallSupported = true;
                boolean sharedMapSupported = true;
                boolean sharedSketchSupported = true;

                Log.d("PRESENCE_UI", TAG + "ftThumbnailSupported ="
                        + ftThumbnailSupported);
                Log.d("PRESENCE_UI", TAG + "ftSnFSupported =" + ftSnFSupported);
                Log.d("PRESENCE_UI", TAG + "ftSupported =" + ftSupported);
                Log.d("PRESENCE_UI", TAG + "chatSupported =" + chatSupported);
                Log.d("PRESENCE_UI", TAG + "ipmeSupported =" + ipmeSupported);
                Log.d("PRESENCE_UI", TAG + "ftHttpSupported =" + ftHttpSupported);

                Log.d("PRESENCE_UI", TAG + "audioSupported =" + audioSupported);
                Log.d("PRESENCE_UI", TAG + "videoSupported =" + videoSupported);
                if(AppGlobalState.getOperatorMode() != AppGlobalState.ATT_MODE)
                {
                  Log.d("PRESENCE_UI", TAG + "geoSmsSupported =" + geoSmsSupported);
                  Log.d("PRESENCE_UI", TAG + "callComposerSupported =" + callComposerSupported);
                  Log.d("PRESENCE_UI", TAG + "postCallSupported =" + postCallSupported);
                  Log.d("PRESENCE_UI", TAG + "sharedMapSupported =" + sharedMapSupported);
                  Log.d("PRESENCE_UI", TAG + "sharedSketchSupported =" + sharedSketchSupported);
                }
                Log.d("PRESENCE_UI",
                        "OPERATOR MODE :" + AppGlobalState.getOperatorMode());
                Log.d("PRESENCE_UI", TAG + "isMobileDataEnabled:"
                        + Settings.isMobile_data_enabled);

              //TMO MODE
                if(AppGlobalState.getOperatorMode() == AppGlobalState.TMO_MODE) {
                   Log.d("PRESENCE_UI", TAG + "chatbotSupported =" + chatbotSupported);
                   Log.d("PRESENCE_UI", TAG + "chatbotRoleSupported =" + chatbotRoleSupported);
                   if (Settings.isMobile_data_enabled || ContactInfo.networkTypeIWLAN) {

                         cdInfo.setFtSupported(ftSupported);
                         cdInfo.setFtThumbSupported(ftThumbnailSupported);
                         cdInfo.setFtSnFSupported(ftSnFSupported);
                         cdInfo.setFtHttpSupported(ftSupported);

                         cdInfo.setImSupported(chatSupported);
                         cdInfo.setFullSnFGroupChatSupported(chatSupported);

                         cdInfo.setSmSupported(ipmeSupported);

                         cdInfo.setGeoSmsSupported(geoSmsSupported);
                         cdInfo.setCallComposerSupported(callComposerSupported);
                         cdInfo.setPostCallSupported(postCallSupported);
                         cdInfo.setSharedMapSupported(sharedMapSupported);
                         cdInfo.setSharedSketchSupported(sharedSketchSupported);
                         cdInfo.setChatbotSupported(chatbotSupported);
                         cdInfo.setChatbotRoleSupported(chatbotRoleSupported);
                         Log.d("PRESENCE_UI", TAG+"Set for TMO:cdinfo data :" + "FT,FT_HTTP:"+ftSupported+";FT_THUMB:"+ftThumbnailSupported
                                                          +";FT_SNF:"+ftSnFSupported+";CHAT_IM,GroupChat:"+chatSupported+";CHAT_SM:"+ipmeSupported
                                                          +";CHATBOT:"+chatbotSupported+";CHATBOT_ROLE:"+chatbotRoleSupported+";GEO_SMS:"
                                                          +geoSmsSupported+";CALL_COMPOSER:"+callComposerSupported+";POST_CALL:"+postCallSupported
                                                          +";SHARED_MAP:"+sharedMapSupported+";SHARED_SKETCH:"+sharedSketchSupported);
                   } else {
                         cdInfo.setFtSupported(false);
                         cdInfo.setFtThumbSupported(false);
                         cdInfo.setFtSnFSupported(false);
                         cdInfo.setFtHttpSupported(false);
                         cdInfo.setImSupported(false);
                         cdInfo.setFullSnFGroupChatSupported(false);

                         cdInfo.setSmSupported(false);
                         cdInfo.setGeoSmsSupported(false);
                         cdInfo.setCallComposerSupported(false);
                         cdInfo.setPostCallSupported(false);
                         cdInfo.setSharedMapSupported(false);
                         cdInfo.setSharedSketchSupported(false);
                         cdInfo.setChatbotSupported(false);
                         cdInfo.setChatbotRoleSupported(false);
                         Log.d("PRESENCE_UI", TAG+"Reset :cdinfo data:" + "FT,FT_SNF,FT_THUMB,FT_HTTP:false;CHAT_IMS,GroupChat,IPME:false"+
                                                                          "CHATBOT, CHATBOT_ROLE:false;GEO_SMS,CALL_COMPOSER,POST_CALL:false"+
                                                                          "SHARED_MAP, SHARED_SKETCH:false");
                   }
                }


                // VZW MODE
                if (AppGlobalState.getOperatorMode() == AppGlobalState.VZW_MODE) {
                    if (Settings.isMobile_data_enabled || ContactInfo.networkTypeIWLAN) {

                        cdInfo.setFtSupported(ftSupported);

                        cdInfo.setImSupported(chatSupported);
                        cdInfo.setFullSnFGroupChatSupported(chatSupported);
                        cdInfo.setCdViaPresenceSupported(true);
                        cdInfo.setGeoSmsSupported(geoSmsSupported);
                        cdInfo.setCallComposerSupported(callComposerSupported);
                        cdInfo.setPostCallSupported(postCallSupported);
                        cdInfo.setSharedMapSupported(sharedMapSupported);
                        cdInfo.setSharedSketchSupported(sharedSketchSupported);

                        Log.d("PRESENCE_UI", TAG + "Set for VZW:cdinfo data:"
                                + "FT:" + ftSupported + ";CHAT_IMS,GroupChat"
                                + chatSupported + ";GEO_SMS:"
                                + geoSmsSupported+";CALL_COMPOSER:"
                                + callComposerSupported+";POST_CALL:"
                                + postCallSupported+";SHARED_MAP:"
                                + sharedMapSupported+";SHARED_SKETCH:"
                                + sharedSketchSupported);
                    } else {
                        cdInfo.setFtSupported(false);
                        cdInfo.setImSupported(false);
                        cdInfo.setFullSnFGroupChatSupported(false);
                        cdInfo.setCdViaPresenceSupported(false);
                        cdInfo.setGeoSmsSupported(false);
                        cdInfo.setCallComposerSupported(false);
                        cdInfo.setPostCallSupported(false);
                        cdInfo.setSharedMapSupported(false);
                        cdInfo.setSharedSketchSupported(false);

                        Log.d("PRESENCE_UI", TAG + "Reset :cdinfo data:"
                                + "FT:false;CHAT_IMS,GroupChat-false, Presence-false"
                                + "GEO_SMS,CALL_COMPOSER,POST_CALL:false"
                                + "SHARED_MAP, SHARED_SKETCH:false");
                    }
                }

                // ATT MODE
                if (AppGlobalState.getOperatorMode() == AppGlobalState.ATT_MODE) {

                    if (Settings.isMobile_data_enabled || ContactInfo.networkTypeIWLAN) {
                        if (ipmeSupported) {

                            cdInfo.setFtSupported(true);
                            cdInfo.setImSupported(true);
                            cdInfo.setSmSupported(true);
                            cdInfo.setFtHttpSupported(true);

                            Log.d("PRESENCE_UI", TAG
                                    + "Set for ATT:cdinfo data:" + "FT/FTHTTP:"
                                    + ipmeSupported + ";CHAT_IMS,IPME-"
                                    + ipmeSupported);

                        } else {
                            cdInfo.setFtSupported(false);
                            cdInfo.setImSupported(false);
                            cdInfo.setSmSupported(false);
                            cdInfo.setFtHttpSupported(false);

                            Log.d("PRESENCE_UI", TAG
                                    + "Reset for ATT:cdinfo data:" + "FT:false"
                                    + ";CHAT_IMS,IPME-false");
                        }

                    }
                    cdInfo.setCdViaPresenceSupported(presenceSupported);
                }

                if(!AppGlobalState.isCdByOption()) {
                 cdInfo.setIpVoiceSupported((audioSupported == 0) ? false : true);
                 cdInfo.setIpVideoSupported((videoSupported == 0) ? false : true);
                }

                if(AppGlobalState.isCustomFTEnabled()) {
                    cdInfo.setExts(AppGlobalState.GetCustomFT());
                }
                AppGlobalState.getCdService().setMyInfo(
                        AppGlobalState.getCdServiceHandle(), cdInfo, AppGlobalState.getpUserData());

                Log.d("PRESENCE_UI", TAG+" ListenerHandler.errorSipHandle:"+ListenerHandler.errorSipHandle);

                if(ListenerHandler.errorSipHandle) {
                   ListenerHandler.errorSipHandle = false;
                  cdInfo.setIpVoiceSupported((audioSupported == 0) ? false : true);
                  cdInfo.setIpVideoSupported((videoSupported == 0) ? false : true);
                }

            } else {
                Log.d("PRESENCE_UI", "MainActivity : getCdService : NULL");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    private SharedPreferences getSharedPrefHandle(String imsPresencePref) {
        SharedPreferences settings = mContext.getSharedPreferences(imsPresencePref, 0);

        return settings;
    }

    @Override
    protected void onPostExecute(Integer result) {
        super.onPostExecute(result);
        Log.d(TAG, "onPostExecute(), Thread=" + Thread.currentThread().getName());
        Toast.makeText(mContext, "Publish Rich Result =" +
                    result, Toast.LENGTH_SHORT).show();

    }
}
