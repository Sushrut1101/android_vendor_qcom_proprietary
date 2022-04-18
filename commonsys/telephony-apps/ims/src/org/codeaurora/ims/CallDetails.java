/*
Copyright (c) 2015, 2019 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package org.codeaurora.ims;

import java.util.Arrays;
import java.util.Map;
import java.util.Map.Entry;

import android.os.Parcel;
import android.os.Parcelable;
import org.codeaurora.ims.QtiCallConstants;
import org.codeaurora.ims.MultiIdentityLineInfo;
import vendor.qti.hardware.radio.ims.V1_0.RttMode;

/**
 * CallDetails class takes care of all the additional details like call type and
 * domain needed for IMS calls. This class is not relevant for non-IMS calls
 */
public class CallDetails {

    /*
     * Type of the call based on the media type and the direction of the media.
     */

    public static final int CALL_TYPE_VOICE = 0; /*
                                                  * Phone.CALL_TYPE_VOICE /*
                                                  * Voice call-audio in both
                                                  * directions
                                                  */

    public static final int CALL_TYPE_VT_TX = 1; /*
                                                  * Phone.CALL_TYPE_VT_TX; PS
                                                  * Video telephony call: one
                                                  * way TX video, two way audio
                                                  */

    public static final int CALL_TYPE_VT_RX = 2; /*
                                                  * Phone.CALL_TYPE_VT_RX Video
                                                  * telephony call: one way RX
                                                  * video, two way audio
                                                  */

    public static final int CALL_TYPE_VT = 3; /*
                                               * Phone.CALL_TYPE_VT; Video
                                               * telephony call: two way video,
                                               * two way audio
                                               */

    public static final int CALL_TYPE_VT_NODIR = 4; /*
                                                     * Phone.CALL_TYPE_VT_NODIR;
                                                     * Video telephony call: no
                                                     * direction, two way audio,
                                                     * intermediate state in a
                                                     * video call till video
                                                     * link is setup
                                                     */

    public static final int CALL_TYPE_SMS = 5; /*
                                                * Phone.CALL_TYPE_SMS;SMS Type
                                                */

    public static final int CALL_TYPE_VT_PAUSE = 6; /*
                                                     * Indicates that video is paused;
                                                     * This is an internal call type.
                                                     * The type is used by TeleService and
                                                     * InCallUI only. See CALL_TYPE_VT_RESUME
                                                     */

    public static final int CALL_TYPE_VT_RESUME = 7; /*
                                                      * This is an internal call
                                                      * type. VT_RESUME call
                                                      * type is used to send
                                                      * unpause request to
                                                      * TeleService.
                                                      */

    public static final int CALL_TYPE_UNKNOWN = 10; /*
                                                     * Phone.CALL_TYPE_UNKNOWN;
                                                     * Unknown Call type, may be
                                                     * used for answering call
                                                     * with same call type as
                                                     * incoming call. This is
                                                     * only for telephony, not
                                                     * meant to be passed to RIL
                                                     */

    public static final int CALL_DOMAIN_UNKNOWN = 11; /*
                                                       * Phone.CALL_DOMAIN_UNKNOWN
                                                       * ; Unknown domain. Sent
                                                       * by RIL when modem has
                                                       * not yet selected a
                                                       * domain for a call
                                                       */

    // enum CallType
    public static final int CALL_TYPE_CS_VS_TX = 21;   /* VS no lipsync augmented with CS */
    public static final int CALL_TYPE_CS_VS_RX = 22;   /* VS no lipsync augmented with CS */

    /* VS no lipsync with optional one way PS audio */
    public static final int CALL_TYPE_PS_VS_TX = 23;

    /* VS no lipsync with optional one way PS audio */
    public static final int CALL_TYPE_PS_VS_RX = 24;

    /* This is to handle when IMS is not registered */
    public static final int CALL_TYPE_UT = 25;


    public static final int CALL_DOMAIN_CS = 1; /*
                                                 * Phone.CALL_DOMAIN_CS; Circuit
                                                 * switched domain
                                                 */
    public static final int CALL_DOMAIN_PS = 2; /*
                                                 * Phone.CALL_DOMAIN_PS; Packet
                                                 * switched domain
                                                 */
    public static final int CALL_DOMAIN_AUTOMATIC = 3; /*
                                                        * Phone.
                                                        * CALL_DOMAIN_AUTOMATIC;
                                                        * Automatic domain. Sent
                                                        * by Android to indicate
                                                        * that the domain for a
                                                        * new call should be
                                                        * selected by modem
                                                        */
    public static final int CALL_DOMAIN_NOT_SET = 4; /*
                                                      * Phone.CALL_DOMAIN_NOT_SET
                                                      * ; Init value used
                                                      * internally by telephony
                                                      * until domain is set
                                                      */

    public static final int CALL_RESTRICT_CAUSE_NONE = 0; /*
                                                           * Default cause, not
                                                           * restricted
                                                           */
    public static final int CALL_RESTRICT_CAUSE_RAT = 1; /*
                                                          * Service not
                                                          * supported by RAT
                                                          */
    public static final int CALL_RESTRICT_CAUSE_DISABLED = 2; /*
                                                               * Service
                                                               * disabled
                                                               */

    public static final int VIDEO_PAUSE_STATE_PAUSED = 1; /*
                                                           * Indicates that
                                                           * video is paused;
                                                           */

    public static final int VIDEO_PAUSE_STATE_RESUMED = 2; /*
                                                            * Indicates that
                                                            * video is resumed;
                                                            */

    public static final int MEDIA_ID_UNKNOWN = -1; /*
                                                    * Indicates that media id is unknown.
                                                    */

    public static final int CAUSE_CODE_UNSPECIFIED = 0; /*
                                                         * session modification cause is unknown
                                                         */

    // enum CallSubstate
    public static final int CALL_SUBSTATE_NONE = 0;
    public static final int CALL_SUBSTATE_AUDIO_CONNECTED_SUSPENDED = 1;
    public static final int CALL_SUBSTATE_VIDEO_CONNECTED_SUSPENDED = 2;
    public static final int CALL_SUBSTATE_AVP_RETRY = 4;
    public static final int CALL_SUBSTATE_MEDIA_PAUSED = 8;

    // enum RingBackTone
    public static final int RINGBACK_TONE_STOP = 0;
    public static final int RINGBACK_TONE_START = 1;

    // enum Tty_Mode_Type
    public static final int TTY_MODE_OFF = 0;
    public static final int TTY_MODE_FULL = 1;
    public static final int TTY_MODE_HCO = 2;
    public static final int TTY_MODE_VCO = 3;

    public static final String EXTRAS_IS_CONFERENCE_URI = "isConferenceUri";
    public static final String EXTRAS_PARENT_CALL_ID = "parentCallId";
    public static final String EXTRAS_HANDOVER_INFORMATION = "handoverInfo";
    public static final String EXTRAS_CODEC = "Codec";
    public static final int EXTRA_TYPE_LTE_TO_IWLAN_HO_FAIL = 1;

    public int call_type;
    public int call_domain;
    public int callsubstate = QtiCallConstants.CALL_SUBSTATE_NONE;
    public int callMediaId = MEDIA_ID_UNKNOWN;
    public String[] extras;
    private int mVideoPauseState = VIDEO_PAUSE_STATE_RESUMED;
    private boolean mIsCallPull = false;

    public ServiceStatus[] localAbility;
    public ServiceStatus[] peerAbility;
    public int causeCode = CAUSE_CODE_UNSPECIFIED;
    public int rttMode = RttMode.RTT_MODE_DISABLED;
    public String sipAlternateUri;
    private MultiIdentityLineInfo mLineInfo;

    public CallDetails() {
        call_type = CALL_TYPE_UNKNOWN;
        call_domain = CALL_DOMAIN_NOT_SET;
        extras = null;
    }

    public CallDetails(int callType, int callDomain, String[] extraparams) {
        this( callType, callDomain, extraparams, null);
    }

    public CallDetails(int callType, int callDomain, String[] extraparams,
            MultiIdentityLineInfo info) {
        call_type = callType;
        call_domain = callDomain;
        extras = extraparams;
        mLineInfo = info;
    }

    public CallDetails(CallDetails srcCall) {
        if (srcCall != null) {
            call_type = srcCall.call_type;
            call_domain = srcCall.call_domain;
            callsubstate = srcCall.callsubstate;
            callMediaId = srcCall.callMediaId;
            extras = srcCall.extras;
            localAbility = srcCall.localAbility;
            peerAbility = srcCall.peerAbility;
            causeCode = srcCall.causeCode;
            rttMode = srcCall.rttMode;
            mLineInfo = srcCall.mLineInfo;
        }
    }

    public boolean update(CallDetails update) {
        boolean hasChanged = false;
        if (update == null) {
            return false;
        }
        if (call_type != update.call_type) {
            call_type = update.call_type;
            causeCode = update.causeCode;
            hasChanged = true;
        }
        if (call_domain != update.call_domain) {
            call_domain = update.call_domain;
            hasChanged = true;
        }
        if (callsubstate != update.callsubstate) {
            callsubstate = update.callsubstate;
            hasChanged = true;
        }
        if (rttMode != update.rttMode) {
            rttMode = update.rttMode;
            hasChanged = true;
        }

        if (sipAlternateUri != update.sipAlternateUri) {
            sipAlternateUri = update.sipAlternateUri;
            hasChanged = true;
        }

        localAbility = update.localAbility;
        peerAbility = update.peerAbility;

        for (int i = 0; update.extras != null && i < update.extras.length; i++) {
            String[] currKeyValuePair = update.extras[i].split("=");
            if(currKeyValuePair.length == 2) {
                String oldVal = getValueForKeyFromExtras(extras, currKeyValuePair[0]);
                if (oldVal != null) { //Extra exists
                    if (!oldVal.equals(currKeyValuePair[1])) {
                        extras = setValueForKeyInExtras(extras, currKeyValuePair[0],
                                    currKeyValuePair[1]);
                        hasChanged = true;
                    }
                } else { //New extra
                    hasChanged = true;
                    addExtra(update.extras[i]);
                }
            }
        }
        setVideoPauseState(update.getVideoPauseState());
        return hasChanged;
    }

    public void setExtras(String[] extraparams) {
        extras = extraparams;
    }

    public void addExtra(String extra) {
        if (extras != null) {
            extras = Arrays.copyOf(extras, extras.length + 1);
            extras [extras.length-1] = new String(extra);
        }
    }

    public void setCallPull(boolean value) {
        mIsCallPull = value;
    }

    public boolean getCallPull() {
        return mIsCallPull;
    }

    public static String[] getExtrasFromMap(Map<String, String> newExtras) {
        String[] extras = null;

        if (newExtras == null) {
            return null;
        }

        // TODO: Merge new extras into extras. For now, just serialize and set
        // them
        extras = new String[newExtras.size()];

        if (extras != null) {
            int i = 0;
            for (Entry<String, String> entry : newExtras.entrySet()) {
                extras[i] = "" + entry.getKey() + "=" + entry.getValue();
            }
        }
        return extras;
    }

    public void setExtrasFromMap(Map<String, String> newExtras) {
        this.extras = getExtrasFromMap(newExtras);
    }

    public void setVideoPauseState(int videoPauseState) {
        // Validate and set the new video pause state.
        switch (videoPauseState) {
            case VIDEO_PAUSE_STATE_RESUMED:
            case VIDEO_PAUSE_STATE_PAUSED:
                mVideoPauseState = videoPauseState;
        }
    }

    public int getVideoPauseState() {
        return mVideoPauseState;
    }

    public String getValueForKeyFromExtras(String[] extras, String key) {
        for (int i = 0; extras != null && i < extras.length; i++) {
            if (extras[i] != null) {
                String[] currKey = extras[i].split("=");
                if (currKey.length == 2 && currKey[0].equals(key)) {
                    return currKey[1];
                }
            }
        }
        return null;
    }

    public String[] setValueForKeyInExtras(String[] extras, String key, String value) {
        if (extras != null) {
            for (int i = 0; extras != null && i < extras.length; i++) {
                if (extras[i] != null) {
                    String[] currKey = extras[i].split("=");
                    if (currKey.length == 2 && currKey[0].equals(key)) {
                        extras[i] = key + "=" + value;
                        break;
                    }
                }
            }
        }
        return extras;
    }

    /**
     * Convenience method, returns true if media id is valid, false otherwise.
     */
    public boolean hasMediaIdValid() {
        return callMediaId != MEDIA_ID_UNKNOWN && callMediaId >= 0;
    }

    public void setRttMode(int mode) {
        rttMode = mode;
    }

    public int getRttMode() {
        return rttMode;
    }

    public MultiIdentityLineInfo getMultiIdentityLineInfo() {
        return mLineInfo;
    }

    public boolean isRadioTech5G() {
        if (localAbility == null) {
            return false;
        }
        for (ServiceStatus srv : localAbility) {
            //Check the ServiceStatus for the correct call type only
            if (srv != null && srv.type == call_type) {
                return srv.isRadioTech5G();
            }
        }
        return false;
    }

    /**
     * @return string representation.
     */
    @Override
    public String toString() {
        String extrasResult = "", localSrvAbility = "", peerSrvAbility = "";
        if (extras != null) {
            for (String s : extras) {
                extrasResult += s;
            }
        }

        if (localAbility != null) {
            for (ServiceStatus srv : localAbility) {
                if (srv != null) {
                    localSrvAbility += "isValid = " + srv.isValid + " type = "
                            + srv.type + " status = " + srv.status + " rttMode = " + rttMode;
                    if (srv.accessTechStatus != null) {
                        for(ServiceStatus.StatusForAccessTech at : srv.accessTechStatus) {
                                localSrvAbility += " accTechStatus " + at;
                        }
                    }
                }
            }
        }

        if (peerAbility != null) {
            for (ServiceStatus srv : peerAbility) {
                if (srv != null) {
                    peerSrvAbility += "isValid = " + srv.isValid + " type = "
                            + srv.type + " status = " + srv.status + " rttMode = " + rttMode;
                    if (srv.accessTechStatus != null) {
                        for(ServiceStatus.StatusForAccessTech at : srv.accessTechStatus) {
                                peerSrvAbility += " accTechStatus " + at;
                        }
                    }
                }
            }
        }

        return (" " + call_type
                + " " + call_domain
                //+ " " + extrasResult
                + " callSubState " + callsubstate
                + " videoPauseState" + mVideoPauseState
                + " mediaId" + callMediaId
                + " Rtt mode " + rttMode
                + " Local Ability " + localSrvAbility
                + " Peer Ability " + peerSrvAbility
                + " Cause code " + causeCode
                + " sipAlternateUri " + sipAlternateUri
                + ", " + mLineInfo);

    }
}
