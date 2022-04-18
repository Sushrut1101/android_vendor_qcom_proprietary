#ifndef QCRIL_UIM_SLOT_MAPPING_H
#define QCRIL_UIM_SLOT_MAPPING_H
/*===========================================================================

  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include "modules/uim/UimGetPhysicalSlotMappingRequestMsg.h"
#include "modules/uim/UimSwitchSlotRequestMsg.h"
#include "modules/uim/UimGetSlotStatusRequestMsg.h"
#include "qcril_uim.h"

/*===========================================================================

                               FUNCTIONS

===========================================================================*/

/*=========================================================================

  FUNCTION:  qcril_uim_get_physical_slot_mapping_resp

===========================================================================*/
/*!
    @brief
    Processes the response for physical slot mapping command.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_get_physical_slot_mapping_resp
(
  const qcril_uim_callback_params_type * const params_ptr,
  const std::shared_ptr<UimGetPhysicalSlotMappingRequestMsg>  req_ptr
);

/*=========================================================================

  FUNCTION:  qcril_uim_get_slots_status_resp

===========================================================================*/
/*!
    @brief
    Processes the response for the slot status command.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_get_slots_status_resp
(
  const qcril_uim_callback_params_type * const params_ptr,
  const std::shared_ptr<UimGetSlotStatusRequestMsg> req_ptr
);

/*=========================================================================

  FUNCTION:  qcril_uim_switch_slot_resp

===========================================================================*/
/*!
    @brief
    Processes the response for switch physical slot command.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_switch_slot_resp
(
  const qcril_uim_callback_params_type * const params_ptr,
  const std::shared_ptr<UimSwitchSlotRequestMsg>  req_ptr
);

/*===========================================================================

  FUNCTION:  qcril_uim_process_slot_status_change_ind

===========================================================================*/
/*!
    @brief
    Main function for processing QMI slot status changed indication.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_process_slot_status_change_ind
(
  const qcril_uim_indication_params_type  * ind_param_ptr
);

/*===========================================================================

  FUNCTION:  qcril_uim_request_switch_slot

===========================================================================*/
/*!
    @brief
    Handles QCRIL_EVT_HOOK_SWITCH_SLOT_REQ request from the framework

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_request_switch_slot
(
  const std::shared_ptr<UimSwitchSlotRequestMsg>  req_ptr
);

/*===========================================================================

  FUNCTION:  qcril_uim_request_get_physical_slot_mapping

===========================================================================*/
/*!
    @brief
    Handles QCRIL_EVT_HOOK_GET_PHYSICAL_SLOT_MAPPING_REQ request from the
    framework

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_request_get_physical_slot_mapping
(
  const std::shared_ptr<UimGetPhysicalSlotMappingRequestMsg>  req_ptr
);

/*===========================================================================

  FUNCTION:  qcril_uim_request_get_slots_status

===========================================================================*/
/*!
    @brief
    Handles QCRIL_UIM_REQUEST_GET_SLOT_STATUS request from the
    framework

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_request_get_slots_status
(
  const std::shared_ptr<UimGetSlotStatusRequestMsg> req_ptr
);

#endif /* QCRIL_UIM_SLOT_MAPPING_H */

