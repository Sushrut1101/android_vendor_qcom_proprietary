/******************************************************************************
#  Copyright (c) 2018 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#******************************************************************************/
#pragma once
#include <framework/add_message_id.h>
#include <interfaces/QcRilRequestMessage.h>
#include <interfaces/voice/QcRilRequestHangupMessage.h>
#include <interfaces/voice/voice.h>
#include <optional>

/*
 * Request to hangup a call
 *
 * Response:
 *   errorCode    : Valid error codes
 *   responseData : nullptr
 */
class QcRilRequestCsHangupMessage : public QcRilRequestHangupMessage,
                                    public add_message_id<QcRilRequestCsHangupMessage> {
 public:
  static constexpr const char *MESSAGE_NAME = "QcRilRequestCsHangupMessage";

  QcRilRequestCsHangupMessage() = delete;

  ~QcRilRequestCsHangupMessage() {}

  inline QcRilRequestCsHangupMessage(std::shared_ptr<MessageContext> context)
      : QcRilRequestHangupMessage(get_class_message_id(), context) {
    mName = MESSAGE_NAME;
  }

#if 0
  virtual string dump() {
    return QcRilRequestAnswerMessage::dump();
  }
#endif
};
