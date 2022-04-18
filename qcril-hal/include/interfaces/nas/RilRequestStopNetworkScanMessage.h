/******************************************************************************
#  Copyright (c) 2018 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#******************************************************************************/
#pragma once
#include "framework/add_message_id.h"
#include "interfaces/QcRilRequestMessage.h"

/* Request to stop the network scan
   @Receiver: NasModule
   */

class RilRequestStopNetworkScanMessage : public QcRilRequestMessage,
    public add_message_id<RilRequestStopNetworkScanMessage> {
public:
    static constexpr const char *MESSAGE_NAME = "RIL_REQUEST_STOP_NETWORK_SCAN";

    RilRequestStopNetworkScanMessage() = delete;
    ~RilRequestStopNetworkScanMessage() {}

    inline RilRequestStopNetworkScanMessage(std::shared_ptr<MessageContext> context)
        : QcRilRequestMessage(get_class_message_id(), context) {
      mName = MESSAGE_NAME;
    }
};
