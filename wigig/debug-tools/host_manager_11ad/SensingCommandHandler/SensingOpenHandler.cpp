/*
* Copyright (c) 2019 Qualcomm Technologies, Inc.
* All Rights Reserved.
* Confidential and Proprietary - Qualcomm Technologies, Inc.
*/

#include "SensingOpenHandler.h"
#include "SensingService.h"
#include "DebugLogger.h"

void SensingOpenHandler::HandleRequest(const SensingOpenRequest& jsonRequest, JsonBasicResponse& jsonResponse)
{
    LOG_DEBUG << "Sensing open request" << std::endl;

    const JsonValueBoxed<bool> autoRecoveryBoxed = jsonRequest.GetAutoRecovery();
    if (autoRecoveryBoxed.GetState() != JsonValueState::JSON_VALUE_PROVIDED)
    {
        const char* errStr = "'AutoRecovery' parameter is required";
        LOG_ERROR << "Failed to open Sensing: " << errStr << std::endl;
        jsonResponse.Fail(errStr);
        return;
    }

    const auto openRes = SensingService::GetInstance().OpenSensing(autoRecoveryBoxed);
    if (!openRes)
    {
        jsonResponse.Fail(openRes.GetStatusMessage());
    }
}
