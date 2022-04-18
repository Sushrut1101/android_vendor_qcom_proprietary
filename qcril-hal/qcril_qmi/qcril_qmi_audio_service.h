/*!
  @file qcril_qmi_audio_service.h

  @brief qcril qmi - qcril_audio_service

*/

/*===========================================================================

  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

#ifndef QCRIL_QMI_AUDIO_SERVICE_H
#define QCRIL_QMI_AUDIO_SERVICE_H

#include <utils/String8.h>
#include <vendor/qti/hardware/radio/am/1.0/IQcRilAudio.h>
#include <vendor/qti/hardware/radio/am/1.0/types.h>
#include <QtiMutex.h>

using ::android::sp;
using ::android::hardware::hidl_death_recipient;
using ::android::hardware::Return;
using ::vendor::qti::hardware::radio::am::V1_0::AudioError;

namespace vendor {
namespace qti {
namespace hardware {
namespace radio {
namespace am {
namespace V1_0 {
namespace implementation {

class qcril_audio_impl : public IQcRilAudio, public hidl_death_recipient {
    sp<IQcRilAudioCallback> mQcRilAudioCallback;
    qtimutex::QtiSharedMutex mCallbackLock;

    sp<IQcRilAudioCallback> getQcRilAudioCallback();

    Return<void> setCallback(const sp<IQcRilAudioCallback>& cb);
    Return<void> setError(AudioError errorcode);
    void serviceDied(uint64_t,
            const ::android::wp<::android::hidl::base::V1_0::IBase>&);

public:
    qcril_audio_impl();
    ~qcril_audio_impl();
    int setParameters(android::String8 params);
    android::String8 getParameters(android::String8 params);
};


void qcril_audio_register_service(uint32_t simSlot);
int qcril_audio_setParameters(android::String8 params);
android::String8 qcril_audio_getParameters(android::String8 params);

} // implementation
} // V1_0
} // am
} // radio
} // hardware
} // qti
} // vendor
#endif // QCRIL_QMI_AUDIO_SERVICE_H
