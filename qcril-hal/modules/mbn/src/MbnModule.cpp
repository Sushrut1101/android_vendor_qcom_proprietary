/******************************************************************************
#  @file    MbnModule.cpp
#  @brief   Definition for MbnModule Class. Provides interface to read and update
#           mbn.
#
#  ---------------------------------------------------------------------------
#
#  Copyright (c) 2017 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#  ---------------------------------------------------------------------------
#******************************************************************************/

#include <unordered_map>

#include "framework/Dispatcher.h"
#include "framework/Looper.h"
#include "framework/legacy.h"
#include "framework/ModuleLooper.h"
#include "framework/QcrilInitMessage.h"
#include "modules/qmi/ModemEndPointFactory.h"
#include "modules/qmi/QmiSetupRequestCallback.h"
#include "modules/qmi/QmiIndMessage.h"
#include "modules/qmi/QmiPdcSetupRequestCallback.h"
#include "modules/qmi/EndpointStatusIndMessage.h"
#include "modules/mbn/MbnFileUpdateIndication.h"

#include "modules/mbn/MbnModule.h"

//Mbn module instance
static load_module<MbnModule> mbn_module;

MbnModule& getMbnModule() {
    return mbn_module.get_module();
}

MbnModule::MbnModule() : AddPendingMessageList("MbnModule") {
    mName = "MbnModule";
    mReady = false;
    mWaitingForDmsClient = false;
    mDmsEndPointStatus = false;
    using std::placeholders::_1;
    mMessageHandler = {
        HANDLER(QcrilInitMessage,MbnModule::handleRilInit),
        HANDLER(NasFlexMapStatusIndMessage,MbnModule::handleFlexMapStatusIndication),
        HANDLER(MbnFileUpdateIndication,MbnModule::handleFileObserverEvents),
        HANDLER(QcRilRequestSetMbnConfigMessage, MbnModule::handleSetMbnConfig),
        HANDLER(QcRilRequestGetMbnConfigMessage, MbnModule::handleGetMbnConfig),
        HANDLER(QcRilRequestGetAvlMbnConfigMessage, MbnModule::handleGetAvailableMbnConfig),
        HANDLER(QcRilRequestCleanupMbnConfigMessage, MbnModule::handleCleanupMbnConfig),
        HANDLER(QcRilRequestSelectMbnConfigMessage, MbnModule::handleSelectMbnConfig),
        HANDLER(QcRilRequestGetMetaInfoMessage, MbnModule::handleGetMetaInfo),
        HANDLER(QcRilRequestDeactivateMbnConfigMessage, MbnModule::handleDeactivateMbnConfig),
        HANDLER(QcRilRequestValidateMbnConfigMessage, MbnModule::handleValidateMbnConfig),
        #ifndef QMI_RIL_UTF
        HANDLER(QcRilRequestGetQcVersionOfFileMessage, MbnModule::handleGetQcVersionOfFile),
        HANDLER(QcRilRequestGetQcVersionOfConfigMessage, MbnModule::handleGetQcVersionOfConfig),
        HANDLER(QcRilRequestGetOemVersionOfFileMessage, MbnModule::handleGetOemVersionOfFile),
        #endif
        HANDLER(QcRilRequestGetOemVersionOfConfigMessage, MbnModule::handleGetOemVersionOfConfig),
        HANDLER(QcRilRequestActivateMbnConfigMessage, MbnModule::handleActivateMbnConfig),
        HANDLER(QcRilRequestEnableModemUpdateMessage, MbnModule::handleEnableModemUpdate),

        {REG_MSG("PDC_QMI_IND"),std::bind(&MbnModule::handlePdcQmiIndMessage, this, _1)},
        // End Point Status Indication
        {REG_MSG("PDC_ENDPOINT_STATUS_IND"),
        std::bind(&MbnModule::handlePdcEndpointStatusIndMessage, this, _1)},
        {REG_MSG("DMS_ENDPOINT_STATUS_IND"),
             std::bind(&MbnModule::handleDmsEndpointStatusIndMessage, this, _1)},

        //TODO update mMessageHandler to register for MBN messages in next iteration.
    };

    //TODO update mMessageHandler to register for MBN messages .
};

MbnModule::~MbnModule() {

};

void MbnModule::init() {
    Module::init();

}

/*
 * Handle RIl_init request from framework .
 * Connect to Qmi PDC service.
*/
void MbnModule::handleRilInit(std::shared_ptr<Message> msg) {
    Log::getInstance().d("[" + mName + "]: Handling msg = " + msg->dump());
    /* Init QMI services.*/
    //TODO init pdc service only for RILD0
    if (qmi_ril_get_process_instance_id() == QCRIL_DEFAULT_INSTANCE_ID) {
        auto pdcEndPoint = ModemEndPointFactory<PdcModemEndPoint>::getInstance().buildEndPoint();
        QmiPdcSetupRequestCallback qmiPdcSetupCallback("Pdc-MbnModule-Token");
        pdcEndPoint->requestSetup("Client-pdc-Serv-Token", &qmiPdcSetupCallback);
    } else {
        Log::getInstance().d("Connection to PDC service not required for this instance");
        mReady = false;
    }
}

/*
 * Indication from PDC endpoint for the QmiPDCSetupRequest
 * Start the MBN update
*/
void MbnModule::handlePdcEndpointStatusIndMessage(std::shared_ptr<Message> msg) {
    Log::getInstance().d("[" + mName + "]: Handling msg = " + msg->dump());
    std::shared_ptr<EndpointStatusIndMessage> shared_msg(
        std::static_pointer_cast<EndpointStatusIndMessage>(msg));

    if (shared_msg->getState() == ModemEndPoint::State::OPERATIONAL) {
        if(!mReady) {
            if(mDmsEndPointStatus) {
                mWaitingForDmsClient = false;
                //Start hw mbn update
                qcril_qmi_pdc_init();
                qcril_qmi_start_mbn_update();
                mReady = true;
            } else {
                Log::getInstance().d("DMS client is not ready yet");
                mWaitingForDmsClient = true;
            }
        }
    } else {
        mReady = false;
        mWaitingForDmsClient = false;
        mDmsEndPointStatus = false;
    }
}

/*
 * Indication from DMS client when connected to QMI DMS service
 * Start the MBN update if MBNModule is waiting for DMS endpoint status
*/

void MbnModule::handleDmsEndpointStatusIndMessage(std::shared_ptr<Message> msg) {
    Log::getInstance().d("[MbnModule]: Handling msg = " + msg->dump());
    auto shared_msg(std::static_pointer_cast<EndpointStatusIndMessage>(msg));
    if (shared_msg->getState() == ModemEndPoint::State::OPERATIONAL) {
        mDmsEndPointStatus = true;
        if(mWaitingForDmsClient && !mReady) {
            Log::getInstance().d("DMS client is ready. start MBN update ");
            mWaitingForDmsClient = false;
            //Start hw mbn update
            qcril_qmi_pdc_init();
            qcril_qmi_start_mbn_update();
            mReady = true;
        }
    }
}


void MbnModule::handleFlexMapStatusIndication(std::shared_ptr<Message> msg) {
    Log::getInstance().d("[" + mName + "]: Handling msg = " + msg->dump());
    std::shared_ptr<NasFlexMapStatusIndMessage> statusMsg(
      std::static_pointer_cast<NasFlexMapStatusIndMessage>(msg));
    qcril_mbn_sw_modem_switch_state status = processFlexMapStatus(statusMsg->get_flexmap_status());
    //invoke legacy function
    qcril_qmi_sw_mbn_modem_switch(status);
}

void MbnModule::handleFileObserverEvents(std::shared_ptr<Message> msg) {
    Log::getInstance().d("[" + mName + "]: Handling msg = " + msg->dump());
    std::shared_ptr<MbnFileUpdateIndication> statusMsg(
      std::static_pointer_cast<MbnFileUpdateIndication>(msg));

    if(mReady == true) {
        Log::getInstance().d("Module is ready,Start Mbn update");
        qcril_mbn_sw_update_init(FALSE);
    } else {
       Log::getInstance().d("Module is not ready yet ");
    }
}


void MbnModule::handleSetMbnConfig(std::shared_ptr<QcRilRequestSetMbnConfigMessage> msg) {
    qcril_qmi_pdc_set_modem_test_mode(msg);
}

void MbnModule::handleGetMbnConfig(std::shared_ptr<QcRilRequestGetMbnConfigMessage> msg) {
    qcril_qmi_pdc_query_modem_test_mode(msg);
}

void MbnModule::handleGetAvailableMbnConfig(std::shared_ptr<QcRilRequestGetAvlMbnConfigMessage> msg) {
    qcril_qmi_pdc_get_available_configs(msg);
}

void MbnModule::handleCleanupMbnConfig(std::shared_ptr<QcRilRequestCleanupMbnConfigMessage> msg) {
    qcril_qmi_pdc_cleanup_loaded_configs(msg);
}

void MbnModule::handleSelectMbnConfig(std::shared_ptr<QcRilRequestSelectMbnConfigMessage> msg) {
    qcril_qmi_pdc_select_configs(msg);
}

void MbnModule::handleGetMetaInfo(std::shared_ptr<QcRilRequestGetMetaInfoMessage> msg) {
    qcril_qmi_pdc_get_meta_info_of_config(msg);
}

void MbnModule::handleDeactivateMbnConfig(std::shared_ptr<QcRilRequestDeactivateMbnConfigMessage> msg) {
    qcril_qmi_pdc_deactivate_configs(msg);
}

void MbnModule::handleValidateMbnConfig(std::shared_ptr<QcRilRequestValidateMbnConfigMessage> msg) {
    qcril_qmi_pdc_validate_config(msg);
}
#ifndef QMI_RIL_UTF
void MbnModule::handleGetQcVersionOfFile(std::shared_ptr<QcRilRequestGetQcVersionOfFileMessage> msg) {
    qcril_qmi_pdc_get_qc_version_of_file(msg);
}

void MbnModule::handleGetQcVersionOfConfig(std::shared_ptr<QcRilRequestGetQcVersionOfConfigMessage> msg) {
    qcril_qmi_pdc_get_qc_version_of_configid(msg);
}

void MbnModule::handleGetOemVersionOfFile(std::shared_ptr<QcRilRequestGetOemVersionOfFileMessage> msg) {
    qcril_qmi_pdc_get_oem_version_of_file(msg);
}
#endif
void MbnModule::handleGetOemVersionOfConfig(std::shared_ptr<QcRilRequestGetOemVersionOfConfigMessage> msg) {
    qcril_qmi_pdc_get_oem_version_of_configid(msg);
}

void MbnModule::handleActivateMbnConfig(std::shared_ptr<QcRilRequestActivateMbnConfigMessage> msg) {
    qcril_qmi_pdc_activate_configs(msg);
}

void MbnModule::handleEnableModemUpdate(std::shared_ptr<QcRilRequestEnableModemUpdateMessage> msg) {
    qcril_qmi_pdc_enable_modem_update(msg);
}

/*
 * Callback invoked by PDC ModemEndpoint when there is an aysnc response or indication from MPSS
*/
void MbnModule::handlePdcQmiIndMessage(std::shared_ptr<Message> msg) {
    std::shared_ptr<QmiIndMessage> shared_indMsg(std::static_pointer_cast<QmiIndMessage>(msg));
    Log::getInstance().d("[MbnModule]: Handling msg = " + msg->dump());
    QmiIndMsgDataStruct *indData = shared_indMsg->getData();
    if (indData != nullptr) {
        qcril_qmi_pdc_unsol_ind_cb_hndlr(indData->msgId, indData->indData, indData->indSize);
    } else {
        Log::getInstance().d("Unexpected, null data from message");
    }
}


qcril_mbn_sw_modem_switch_state MbnModule::processFlexMapStatus(NasFlexmapState state) {
    qcril_mbn_sw_modem_switch_state flexMapState = QCRIL_MBN_SW_MODEM_SWITCH_STATE_NONE;
    switch(state) {
        case NasFlexmapState::NAS_FLEXMAP_STATE_NONE:
            flexMapState = QCRIL_MBN_SW_MODEM_SWITCH_STATE_NONE;
            break;
        case NasFlexmapState::NAS_FLEXMAP_STATE_START:
            flexMapState = QCRIL_MBN_SW_MODEM_SWITCH_STATE_START;
            break;
        case NasFlexmapState::NAS_FLEXMAP_STATE_APPLY:
            flexMapState = QCRIL_MBN_SW_MODEM_SWITCH_STATE_APPLY;
            break;
        case NasFlexmapState::NAS_FLEXMAP_STATE_FINISH:
            flexMapState = QCRIL_MBN_SW_MODEM_SWITCH_STATE_COMPLETED;
            break;
        default:
          break;
    }

    return flexMapState;
}

#ifdef QMI_RIL_UTF
void MbnModule::qcrilHalPdcModuleCleanup()
{
    std::shared_ptr<PdcModemEndPoint> mPdcModemEndPoint =
                    ModemEndPointFactory<PdcModemEndPoint>::getInstance().buildEndPoint();
    PdcModemEndPointModule* mPdcModemEndPointModule =
                   (PdcModemEndPointModule*)mPdcModemEndPoint->mModule;
    mPdcModemEndPointModule->cleanUpQmiSvcClient();
    mReady = false;
    mWaitingForDmsClient = false;
    mDmsEndPointStatus = false;
}
#endif
