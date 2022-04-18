/*
 * Copyright (c) 2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
/*
 * Copyright (c) 2017-2018, The Linux Foundation. All rights reserved.
 * Not a Contribution
 */
/*
 * Copyright (C) 2016 The Android Open Source Project
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
#ifndef LOC_HIDL_VERSION
#error "LOC_HIDL_VERSION must be set before including this file."
#endif

#include <dlfcn.h>
#include <log_util.h>

namespace vendor {
namespace qti {
namespace gnss {
namespace LOC_HIDL_VERSION {
namespace implementation {

typedef const GnssInterface* (getLocationInterface)();

using ::android::hardware::gnss::V1_0::IAGnssCallback;
sp<IAGnssCallback> LocHidlAGnss::sAGnssCbIface = nullptr;
sp<LocHidlDeathRecipient> LocHidlAGnss::mDeathRecipient = nullptr;

const GnssInterface* LocHidlAGnss::getGnssInterface() {

    ENTRY_LOG();
    static bool getGnssInterfaceFailed = false;
    if (nullptr == mGnssInterface && !getGnssInterfaceFailed) {
        ALOGD("%s]: loading libgnss.so::getGnssInterface ...", __func__);
        getLocationInterface* getter = NULL;
        const char *error = NULL;
        dlerror();
        void *handle = dlopen("libgnss.so", RTLD_NOW);
        if (NULL == handle)  {
            ALOGD("dlopen for libgnss.so failed");
        } else if (NULL != (error = dlerror()))  {
            ALOGD("dlopen for libgnss.so failed, error = %s", error);
        } else {
            getter = (getLocationInterface*)dlsym(handle, "getGnssInterface");
            if ((error = dlerror()) != NULL)  {
                ALOGD("dlsym for libgnss.so::getGnssInterface failed, error = %s", error);
                getter = NULL;
            }
        }

        if (NULL == getter) {
            getGnssInterfaceFailed = true;
        } else {
            mGnssInterface = (const GnssInterface*)(*getter)();
        }
    }
    return mGnssInterface;
}

void LocHidlAGnss::agnssStatusIpV4Cb(AGnssExtStatusIpV4 status){

    if (mDeathRecipient != nullptr && mDeathRecipient->peerDied()) {
        ALOGE("%s] Peer has gone.", __func__);
        return;
    }

    if (sAGnssCbIface == nullptr) {
        ALOGE("AGNSS CB Iface NULL");
        return;
    }
    IAGnssCallback::AGnssStatusIpV4 st = {};

    switch (status.type) {
        case LOC_AGPS_TYPE_SUPL:
            st.type = IAGnssCallback::AGnssType::TYPE_SUPL;
            break;
        case LOC_AGPS_TYPE_C2K:
            st.type = IAGnssCallback::AGnssType::TYPE_C2K;
            break;
        default:
            st.type = (IAGnssCallback::AGnssType)status.type;
            break;
    }

    switch (status.status) {
        case LOC_GPS_REQUEST_AGPS_DATA_CONN:
            st.status = IAGnssCallback::AGnssStatusValue::REQUEST_AGNSS_DATA_CONN;
            break;
        case LOC_GPS_RELEASE_AGPS_DATA_CONN:
            st.status = IAGnssCallback::AGnssStatusValue::RELEASE_AGNSS_DATA_CONN;
            break;
        case LOC_GPS_AGPS_DATA_CONNECTED:
            st.status = IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONNECTED;
            break;
        case LOC_GPS_AGPS_DATA_CONN_DONE:
            st.status = IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_DONE;
            break;
        case LOC_GPS_AGPS_DATA_CONN_FAILED:
            st.status = IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_FAILED;
            break;
        default:
            LOC_LOGE("invalid status: %d", status.status);
            return;
    }
    st.ipV4Addr = status.ipV4Addr;

    auto r = sAGnssCbIface->agnssStatusIpV4Cb(st);
    if (!r.isOk()) {
        LOC_LOGE("%s]: Error from agnssStatusIpV4Cb description=%s",
                __func__, r.description().c_str());
    }
}

// Methods from ::vendor::qti::gnss::V1_0::ILocHidlAGnss follow.
Return<void> LocHidlAGnss::setCallback(
        const sp<::android::hardware::gnss::V1_0::IAGnssCallback>& callback) {
    static uint64_t deathCount = 0;
    FROM_HIDL_CLIENT();

    if(getGnssInterface() == nullptr){
        LOC_LOGE("Null GNSS interface");
        return Void();
    }

    // Register death recipient
    if (mDeathRecipient == nullptr) {
        mDeathRecipient = new LocHidlDeathRecipient([] {
                LOC_LOGE("%s]: IAGnssCallback died.", __func__);
                });
    }
    mDeathRecipient->registerToPeer(callback, deathCount++);

    // Save the interface
    sAGnssCbIface = callback;

    AgpsCbInfo cbInfo = {};
    cbInfo.statusV4Cb = (void*)agnssStatusIpV4Cb;
    cbInfo.atlType = AGPS_ATL_TYPE_WWAN;

    getGnssInterface()->agpsInit(cbInfo);
    return Void();
}

Return<bool> LocHidlAGnss::dataConnOpenExt(const hidl_string& apn,
        ::android::hardware::gnss::V1_0::IAGnss::ApnIpType apnIpType,
        ::android::hardware::gnss::V1_0::IAGnssCallback::AGnssType agnssType) {
    FROM_HIDL_CLIENT();
    if(getGnssInterface() == nullptr ||
            getGnssInterface()->agpsDataConnOpen == NULL){
        ALOGE("%s] Null GNSS interface", __func__);
        return false;
    }

    /* Validate */
    if(apn.empty()){
        ALOGE("%s] Invalid APN", __func__);
        return false;
    }

    ALOGD("%s] dataConnOpen APN name = [%s]", __func__, apn.c_str());

    AGpsBearerType bearerType;
    switch (apnIpType) {
        case ::android::hardware::gnss::V1_0::IAGnss::ApnIpType::IPV4:
            bearerType = AGPS_APN_BEARER_IPV4;
            break;
        case ::android::hardware::gnss::V1_0::IAGnss::ApnIpType::IPV6:
            bearerType = AGPS_APN_BEARER_IPV6;
            break;
        case ::android::hardware::gnss::V1_0::IAGnss::ApnIpType::IPV4V6:
            bearerType = AGPS_APN_BEARER_IPV4V6;
            break;
        default:
            bearerType = AGPS_APN_BEARER_IPV4;
            break;
    }

    getGnssInterface()->agpsDataConnOpen(
            (AGpsExtType)agnssType, apn.c_str(), apn.size(), (int)bearerType);
    return true;
}

Return<bool> LocHidlAGnss::dataConnClosedExt(
        ::android::hardware::gnss::V1_0::IAGnssCallback::AGnssType agnssType) {
    FROM_HIDL_CLIENT();
    if(getGnssInterface() == nullptr ||
            getGnssInterface()->agpsDataConnClosed == NULL){
        ALOGE("Null GNSS interface");
        return false;
    }

    getGnssInterface()->agpsDataConnClosed((AGpsExtType)agnssType);
    return true;
}

Return<bool> LocHidlAGnss::dataConnFailedExt(
        ::android::hardware::gnss::V1_0::IAGnssCallback::AGnssType agnssType) {
    FROM_HIDL_CLIENT();
    if(getGnssInterface() == nullptr ||
            getGnssInterface()->agpsDataConnFailed == NULL){
        ALOGE("Null GNSS interface");
        return false;
    }

    getGnssInterface()->agpsDataConnFailed((AGpsExtType)agnssType);
    return true;
}

// Methods from ::android::hidl::base::V1_0::IBase follow.

}  // namespace implementation
}  // namespace LOC_HIDL_VERSION
}  // namespace gnss
}  // namespace qti
}  // namespace vendor
