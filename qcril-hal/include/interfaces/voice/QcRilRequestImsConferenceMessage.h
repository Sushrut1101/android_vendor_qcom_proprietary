/******************************************************************************
#  Copyright (c) 2018 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#******************************************************************************/
#pragma once
#include <framework/add_message_id.h>
#include <interfaces/QcRilRequestMessage.h>

/*
 * Request to make conference call
 *
 * Response:
 *   errorCode    : Valid error codes
 *   responseData : std::shared_ptr<qcril::interfaces::SipErrorInfo>
 */
class QcRilRequestImsConferenceMessage : public QcRilRequestMessage,
                                         public add_message_id<QcRilRequestImsConferenceMessage> {
 public:
  static constexpr const char *MESSAGE_NAME = "QcRilRequestImsConferenceMessage";

  QcRilRequestImsConferenceMessage() = delete;

  ~QcRilRequestImsConferenceMessage() {}

  inline QcRilRequestImsConferenceMessage(std::shared_ptr<MessageContext> context)
      : QcRilRequestMessage(get_class_message_id(), context) {
    mName = MESSAGE_NAME;
  }

  virtual string dump() {
    return QcRilRequestMessage::dump() + "{}";
  }
};
