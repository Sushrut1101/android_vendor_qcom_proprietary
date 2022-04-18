#pragma once

/*===========================================================================

  Copyright (c) 2017, 2019 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

#include "framework/Message.h"
#include <framework/legacy.h>
#include "framework/SolicitedMessage.h"
#include "framework/GenericCallback.h"
#include "framework/add_message_id.h"
#include "DataCommon.h"
#include "framework/message_translator.h"
#include "legacy/qmi_embms_v01.h"
#include <modules/android/RilRequestMessage.h>

namespace rildata {

class RilRequestEmbmsGetActiveTmgiMessage : public SolicitedMessage<generic_callback_payload>,
                                            public add_message_id<RilRequestEmbmsGetActiveTmgiMessage> {
    private:

    legacy_request_payload params;

    public:

    static constexpr const char* MESSAGE_NAME = "HOOK_EMBMS_UNSOL_ACTIVE_TMGI";
    RilRequestEmbmsGetActiveTmgiMessage() = delete;

    RilRequestEmbmsGetActiveTmgiMessage(const qcril_request_params_type &request)
    :SolicitedMessage<generic_callback_payload>(get_class_message_id()),params(request){
        mName = MESSAGE_NAME;
    }
    ~RilRequestEmbmsGetActiveTmgiMessage();

    qcril_request_params_type &get_params() {
          return params.get_params();
    }
    string dump();
};

}//namespace
