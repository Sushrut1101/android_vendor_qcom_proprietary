/*===========================================================================

  Copyright (c) 2010-2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //depot/asic/sandbox/users/micheleb/ril/qcril_uim_card.c#6 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
02/05/18   nr      New IMPI SimLock category changes
11/23/15   vr      Fix num_slots and num_app limits not verified
09/15/15   vdc     Fix silent pin verification during MSSR
08/04/15   vdc     Check for slot info before register for refresh
03/02/15   yt      Support for external UICC power up/down request
11/07/14   bcho    handling of deactivation failure modified
11/06/14   hh      Added QCRIL_EVT_CM_CARD_APP_STATUS_CHANGED card status
10/27/14   at      Support for graceful UICC Voltage supply deactivation
10/17/14   vdc     Check for slot info before updating session state
08/12/14   bcho    Support for ISIM app to ATEL restored
06/17/14   at      Fix in sending events upon initial status change inds
06/10/14   tl      Removed array structures for slot specific parameters
06/05/14   tl      Add support for recovery indication
05/05/14   ar      Fix critical KW errors
03/31/14   tl      Send pre-init notification to client for manual app selection
03/27/14   vdc     Translate ISIM app state to Ready after PIN state check
01/21/14   at      Added support for getSelectResponse()
01/22/14   yt      Perform silent PIN verification after Airplane mode ON-OFF
01/17/14   at      Changed the feature checks for RIL_REQUEST_SIM_GET_ATR
01/17/14   at      Updated function definition for change prov session cb
01/09/14   yt      Perform silent PIN verification on SAP disconnect
12/11/13   at      Switch to new QCCI framework
09/30/13   yt      Check if card status in indication is invalid
09/10/13   yt      Clear encrypted PIN data at card error
08/22/13   yt      Correctly update number of apps in case of legacy card ind
08/12/13   at      Added support for Long APDU indication
07/10/13   at      Support for clearing proactive cmd cache on card error
05/01/13   yt      Check value of slot before using as index
04/22/13   yt      Silent PIN verification support for multi SIM
04/17/13   yt      Fix critical KW errors
03/19/13   yt      Translate ISIM app state to Ready from Detected
03/15/13   yt      Report SIM_STATUS only after finishing silent PIN verify
02/20/13   yt      Compare with tertiary session index for change in SUB 3
02/07/13   yt      Support for third SIM card slot
01/14/13   yt      Fix critical KW errors
12/19/12   at      Move to newer qcril_event_queue API
12/11/12   at      Support of ISIM App type to Android Telephony
11/27/12   at      Move an older QMI_UIM API to newer QCCI based one
09/21/12   at      Clear the provisioning app's global session state
09/04/12   nk      Reduced log level of some logs from error to info
05/21/12   at      Sending error for get sim status when card is un-init
05/15/12   at      Support for card status validity TLV
04/13/12   at      Explicit check for the first card status indication
04/09/12   at      Added support for RIL_REQUEST_SIM_GET_ATR
03/22/12   at      Replacing malloc()/free() with qcril_malloc()/qcril_free()
03/20/12   tl      Transition to QCCI
11/30/11   at      Send CM_UPDATE_FDN_STATUS based on correct RILD instance;
                   Made get fdn status asynchrounous
10/17/11   yt      Fixed Klocwork warnings
09/30/11   yt      Added support for ISIM Refresh
08/23/11   at      Update prov session global on card status indication;
                   Ignore change prov session based on prov session global
08/14/11   at      Fix for updation of global when changing a prov session
07/26/11   at      Update error code in change prov session callback
06/29/11   yt      Updated check for slot before sending FDN update to CM
06/26/11   at      Removed RIL_CARDSTATE_NOT_INITIALIZED mapping
06/16/11   at      Moved qcril_uim_convert_scws_slot_id to qcril_uim_util.c
06/10/11   yt      Handle QMI indication for absent card
06/10/11   at      Change for  sending QCRIL_CARD_STATUS_ABSENT
06/07/11   yt      Update QCRIL_CM with FDN status at power up
05/06/11   at      Skipped sending QCRIL_EVT_PBM_CARD_ERROR
04/25/11   at      Added function call qcril_scws_card_error()
04/12/11   at      Update QCRIL SIM state properly for no card on power-up
04/11/11   yt      Support for modem restart and silent PIN1 verification
03/24/11   at      Extra checks for card_error to handle airplane mode
03/22/11   at      Support for ril.h v6
02/03/11   at      Converting to RIL_APPSTATE_PUK when App state is blocked
01/11/11   at      Moved refresh functions to qcril_uim_refresh.c
01/18/11   at      Removed slot id parameter from all requests
12/03/10   at      Added qcril_uim_card_status_mutex for protection between
                   Android FW request and modem indications
11/30/10   at      Changes in refresh unsol notification based on new ril i/f
11/12/10   at      Added support for UIM queue implementation
10/06/10   at      Support for handling instance_id passed in requests
09/21/10   at      Send UPIN state as PIN1 state until UI supports UPIN
09/16/10   at      Sending RIL_CARDSTATE_NOT_INITIALIZED for DSDS feature and
                   resetting prov related global data on card error
08/26/10   at      Changes for new subscription activation interface
08/19/10   at      Updated handling for refresh indications
07/23/10   mib     Fixed number of apps for second slot
07/02/10   at      Get Label support
05/13/10   at      Clean up for merging with mainline
04/25/10   at      Added handling for card status indications from QMI_UIM
04/13/10   mib     Initial version
===========================================================================*/

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/

#if defined (FEATURE_QCRIL_UIM_QMI)

#include "telephony/ril.h"
#include "IxErrno.h"
#include "qcrili.h"
#include "qcril_arb.h"
#include "qcril_log.h"
#include "qcril_reqlist.h"
#include "qcril_uim.h"
#include "qcril_uim_util.h"
#include "qcril_uim_queue.h"
#include "qcril_uim_card.h"
#include "qcril_uim_security.h"
#include "qcril_uim_refresh.h"
#include "qcril_uim_restart.h"
#include "qcril_uim_file.h"
#include "qcril_uim_qcci.h"
#include "qcril_scws.h"
#include "qcril_uim_lpa.h"
#include "qcril_uim_sap.h"
#include "util_timer.h"
#include <string.h>
#include <pthread.h>


/*===========================================================================

                               GLOBAL VARIABLES

===========================================================================*/
/* -----------------------------------------------------------------------------
   STRUCT:      QCRIL_UIM_CARD_STATE_CHECK_TYPE

   DESCRIPTION:
     Stores the info needed during the interested card state transtions
-------------------------------------------------------------------------------*/
typedef struct
{
  uint32            timer_id;
  struct timeval    state_check_timer;
} qcril_uim_card_state_check_type;

/* Global for card state check. Note that threshold timer is for 1 sec 500 msecs */
static qcril_uim_card_state_check_type  qcril_uim_card_state_check =
                                          {0, {1, 500000}};

static pthread_mutex_t    qcril_uim_card_status_mutex = PTHREAD_MUTEX_INITIALIZER;
extern void qtiGetAtrResponse(RIL_Token token, RIL_Errno error, char *buf, int bufLen);
extern void SecureElementhandleCardStateChange(qmi_uim_card_state_type card_state);
extern void SecureElementhandleRecovery();
/*===========================================================================

                               INTERNAL FUNCTIONS

===========================================================================*/

/*===========================================================================

  FUNCTION:  qcril_uim_send_get_label

===========================================================================*/
/*!
    @brief
    Issues the QMI command for fetching label for an App.

    @return
    result_code of the QMI call.
*/
/*=========================================================================*/
static int qcril_uim_send_get_label
(
  qmi_client_type                           qmi_handle,
  uint8                                     slot_index,
  qmi_uim_rsp_data_type                  *  qmi_rsp_data_ptr,
  const char                             *  qmi_aid_ptr,
  unsigned char                             qmi_aid_len
)
{
  qcril_modem_id_e_type modem_id          = QCRIL_MAX_MODEM_ID - 1;
  int result_code                         = QMI_INTERNAL_ERR;
  qmi_uim_get_label_params_type           get_label_params;

  memset(&get_label_params, 0, sizeof(qmi_uim_get_label_params_type));

  if (qmi_aid_len <= 0)
  {
    QCRIL_LOG_DEBUG( "Application's aid len <= 0 %d \n", (int)qmi_aid_len);
    return result_code;
  }

  switch (slot_index)
  {
    case 0:
      get_label_params.app_info.slot = QMI_UIM_SLOT_1;
      break;
    case 1:
      get_label_params.app_info.slot = QMI_UIM_SLOT_2;
      break;
    case 2:
      get_label_params.app_info.slot = QMI_UIM_SLOT_3;
      break;
    default:
      QCRIL_LOG_ERROR( "Invalid slot for qcril_uim_send_get_label: %d,\n",
                       slot_index);
      return result_code;
  }

  get_label_params.app_info.aid.data_len = qmi_aid_len;
  get_label_params.app_info.aid.data_ptr = (unsigned char *)qmi_aid_ptr;

  QCRIL_LOG_QMI( modem_id, "qmi_uim_service", "get label" );
  result_code = qcril_qmi_uim_get_label(qmi_handle,
                                        &get_label_params,
                                        NULL,
                                        NULL,
                                        qmi_rsp_data_ptr);
  if(result_code < 0)
  {
    QCRIL_LOG_ERROR( "Error for qcril_qmi_uim_get_label, result_code: %d, qmi_err_code: 0x%X\n",
                     result_code, qmi_rsp_data_ptr->qmi_err_code);
  }
  return result_code;
} /* qcril_uim_send_get_label */


/*=========================================================================

  FUNCTION:  qcril_uim_get_prov_session_state

===========================================================================*/
/*!
    @brief
    returns the state of passed session type from QCRIL uim globals.

    @return
    result_code
*/
/*=========================================================================*/
static int qcril_uim_get_prov_session_state
(
  qmi_uim_session_type                 session_type,
  qcril_uim_prov_session_state_type  * session_state_ptr /*!< Output parameter */
)
{
  int result_code = QMI_NO_ERR;

  /* Sanity check */
  if (session_state_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    return QMI_INTERNAL_ERR;
  }

  switch(session_type)
  {
    case QMI_UIM_SESSION_TYPE_PRI_GW_PROV:
      *session_state_ptr = qcril_uim.prov_session_info.session_state_gw_indexes[0];
      break;
    case QMI_UIM_SESSION_TYPE_PRI_1X_PROV:
      *session_state_ptr = qcril_uim.prov_session_info.session_state_1x_indexes[0];
      break;
    case QMI_UIM_SESSION_TYPE_SEC_GW_PROV:
      *session_state_ptr = qcril_uim.prov_session_info.session_state_gw_indexes[1];
      break;
    case QMI_UIM_SESSION_TYPE_SEC_1X_PROV:
      *session_state_ptr = qcril_uim.prov_session_info.session_state_1x_indexes[1];
      break;
    case QMI_UIM_SESSION_TYPE_TER_GW_PROV:
      *session_state_ptr = qcril_uim.prov_session_info.session_state_gw_indexes[2];
      break;
    case QMI_UIM_SESSION_TYPE_TER_1X_PROV:
      *session_state_ptr = qcril_uim.prov_session_info.session_state_1x_indexes[2];
      break;
    default:
      QCRIL_LOG_ERROR( "%s\n", "Unsupported session type!" )
      result_code = QMI_INTERNAL_ERR;
      break;
  }
  return result_code;
} /* qcril_uim_get_prov_session_state */


/*=========================================================================

  FUNCTION:  qcril_uim_update_prov_session_type

===========================================================================*/
/*!
    @brief
    Updates the global provisioning session status type based on the passed
    session type.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_update_prov_session_type
(
  qmi_uim_session_type                  session_type,
  qcril_uim_prov_session_state_type     session_state
)
{
  QCRIL_LOG_DEBUG("New session state, session_type:%d, session_state:%d \n",
                  (int)session_type, (int)session_state);

  switch(session_type)
  {
    case QMI_UIM_SESSION_TYPE_PRI_GW_PROV:
      qcril_uim.prov_session_info.session_state_gw_indexes[0] = session_state;
      break;
    case QMI_UIM_SESSION_TYPE_PRI_1X_PROV:
      qcril_uim.prov_session_info.session_state_1x_indexes[0] = session_state;
      break;
    case QMI_UIM_SESSION_TYPE_SEC_GW_PROV:
      qcril_uim.prov_session_info.session_state_gw_indexes[1] = session_state;
      break;
    case QMI_UIM_SESSION_TYPE_SEC_1X_PROV:
      qcril_uim.prov_session_info.session_state_1x_indexes[1] = session_state;
      break;
    case QMI_UIM_SESSION_TYPE_TER_GW_PROV:
      qcril_uim.prov_session_info.session_state_gw_indexes[2] = session_state;
      break;
    case QMI_UIM_SESSION_TYPE_TER_1X_PROV:
      qcril_uim.prov_session_info.session_state_1x_indexes[2] = session_state;
      break;
    default:
      QCRIL_LOG_ERROR( "%s\n", "Unsupported session type!" )
      break;
  }
} /* qcril_uim_update_prov_session_type */


/*===========================================================================

  FUNCTION:  qcril_uim_find_prov_session_type

===========================================================================*/
/*!
    @brief
    Updates the passed provisioning session parameter with the session type
    and also the session state pointer with the right state by checking the
    app type and previous state respectively.

    @return
    RIL_Errno error code
*/
/*=========================================================================*/
static RIL_Errno qcril_uim_find_prov_session_type
(
  qmi_uim_change_prov_session_params_type     * session_params_ptr,
  qmi_uim_app_type                              app_type,
  RIL_SubscriptionType                          RIL_sub_type,
  qcril_subs_mode_pref                          subs_mode_pref,
  RIL_UiccSubActStatus                          act_status
)
{
  qcril_uim_prov_session_state_type  check_prov_state = QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED;
  qcril_uim_prov_session_state_type  next_prov_state  = QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED;

  if (session_params_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  QCRIL_LOG_INFO( "app_type: %d, RIL_sub_type: %d, subs_mode_pref: %d\n",
                  app_type,
                  RIL_sub_type,
                  subs_mode_pref);

  QCRIL_LOG_DEBUG("Original session states, GW_PRI:%d, GW_SEC:%d, GW_TER:%d, 1X_PRI:%d, 1X_SEC:%d, 1X_TER:%d\n",
                  qcril_uim.prov_session_info.session_state_gw_indexes[0],
                  qcril_uim.prov_session_info.session_state_gw_indexes[1],
                  qcril_uim.prov_session_info.session_state_gw_indexes[2],
                  qcril_uim.prov_session_info.session_state_1x_indexes[0],
                  qcril_uim.prov_session_info.session_state_1x_indexes[1],
                  qcril_uim.prov_session_info.session_state_1x_indexes[2]);

  /* Check app type */
  if ((app_type != QMI_UIM_APP_SIM) &&
      (app_type != QMI_UIM_APP_USIM) &&
      (app_type != QMI_UIM_APP_RUIM) &&
      (app_type != QMI_UIM_APP_CSIM))
  {
    QCRIL_LOG_ERROR("Invalid app_type: 0x%x", app_type);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  if (act_status == RIL_UICC_SUBSCRIPTION_ACTIVATE)
  {
    check_prov_state = QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED;
    next_prov_state  = QCRIL_UIM_PROV_SESSION_ACTIVATION_IN_PROGRESS;
  }
  else if(act_status == RIL_UICC_SUBSCRIPTION_DEACTIVATE)
  {
    check_prov_state = QCRIL_UIM_PROV_SESSION_ACTIVATED;
    next_prov_state  = QCRIL_UIM_PROV_SESSION_DEACTIVATION_IN_PROGESS;
  }

  /* Check conditions for respective session types */
  if (((app_type == QMI_UIM_APP_SIM) || (app_type == QMI_UIM_APP_USIM)) &&
      (subs_mode_pref == QCRIL_SUBS_MODE_GW))
  {
    if ((RIL_sub_type == RIL_SUBSCRIPTION_1) &&
        (qcril_uim.prov_session_info.session_state_gw_indexes[0] == check_prov_state))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_PRI_GW_PROV;
      qcril_uim_update_prov_session_type(session_params_ptr->session_type,
                                         next_prov_state);
      return RIL_E_SUCCESS;
    }
    else if ((RIL_sub_type == RIL_SUBSCRIPTION_2) &&
             (qcril_uim.prov_session_info.session_state_gw_indexes[1] == check_prov_state))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_SEC_GW_PROV;
      qcril_uim_update_prov_session_type(session_params_ptr->session_type,
                                         next_prov_state);
      return RIL_E_SUCCESS;
    }
    else if ((RIL_sub_type == RIL_SUBSCRIPTION_3) &&
             (qcril_uim.prov_session_info.session_state_gw_indexes[2] == check_prov_state))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_TER_GW_PROV;
      qcril_uim_update_prov_session_type(session_params_ptr->session_type,
                                         next_prov_state);
      return RIL_E_SUCCESS;
    }
    else
    {
      QCRIL_LOG_ERROR("Cannot Activate RIL_sub_type: %d\n", RIL_sub_type);
      return RIL_E_SUBSCRIPTION_NOT_SUPPORTED;
    }
  }
  else if (((app_type == QMI_UIM_APP_RUIM) || (app_type == QMI_UIM_APP_CSIM)) &&
           (subs_mode_pref == QCRIL_SUBS_MODE_1X))
  {
    if ((RIL_sub_type == RIL_SUBSCRIPTION_1) &&
        (qcril_uim.prov_session_info.session_state_1x_indexes[0] == check_prov_state))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_PRI_1X_PROV;
      qcril_uim_update_prov_session_type(session_params_ptr->session_type,
                                         next_prov_state);
      return RIL_E_SUCCESS;
    }
    else if ((RIL_sub_type == RIL_SUBSCRIPTION_2) &&
             (qcril_uim.prov_session_info.session_state_1x_indexes[1] == check_prov_state))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_SEC_1X_PROV;
      qcril_uim_update_prov_session_type(session_params_ptr->session_type,
                                         next_prov_state);
      return RIL_E_SUCCESS;
    }
    else if ((RIL_sub_type == RIL_SUBSCRIPTION_3) &&
             (qcril_uim.prov_session_info.session_state_1x_indexes[2] == check_prov_state))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_TER_1X_PROV;
      qcril_uim_update_prov_session_type(session_params_ptr->session_type,
                                         next_prov_state);
      return RIL_E_SUCCESS;
    }
    else
    {
      QCRIL_LOG_ERROR("Cannot Activate RIL_sub_type: %d\n", RIL_sub_type);
      return RIL_E_SUBSCRIPTION_NOT_SUPPORTED;
    }
  }
  /* Only in case of mismatch of app type & mode pref */
  QCRIL_LOG_ERROR("Unsupported case, app_type: %d, subs_mode_pref:%d \n",
                  app_type, subs_mode_pref);
  return RIL_E_SUBSCRIPTION_NOT_SUPPORTED;
} /* qcril_uim_find_prov_session_type */


/*===========================================================================

  FUNCTION:  qcril_uim_ignore_change_subscription

===========================================================================*/
/*!
    @brief
    Checks if change prov session request can be ignored. It can be ignored
    only on scenarios where the request was for activation & the prov app is
    already activated and vice-versa.

    @return
    RIL_Errno error code
*/
/*=========================================================================*/
static RIL_Errno qcril_uim_ignore_change_subscription
(
  const qcril_uicc_subs_info_type             * RIL_uicc_subs_info_ptr,
  qmi_uim_change_prov_session_params_type     * session_params_ptr
)
{
  int RIL_slot          = 0;
  int RIL_app_index     = 0;
  uint16 prov_app_index = QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE;

  /* Sanity checks */
  if ((RIL_uicc_subs_info_ptr == NULL) || (session_params_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  RIL_slot = RIL_uicc_subs_info_ptr->uicc_subs_info.slot;
  RIL_app_index = RIL_uicc_subs_info_ptr->uicc_subs_info.app_index;

  /* Check slot number */
  if (RIL_slot >= QMI_UIM_MAX_CARD_COUNT ||
      RIL_slot < 0)
  {
    QCRIL_LOG_ERROR("Invalid slot value: 0x%x", RIL_slot);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  /* Check app index */
  if ((RIL_app_index < 0) || (RIL_app_index >= QMI_UIM_MAX_APP_PER_CARD_COUNT))
  {
    QCRIL_LOG_ERROR("Invalid app index: 0x%x", RIL_app_index);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  /* Verify card status */
  if (qcril_uim.card_status.card[RIL_slot].card_state != QMI_UIM_CARD_STATE_PRESENT)
  {
    QCRIL_LOG_ERROR("%s", "Card is not present");
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  /* Find prov app index */
  prov_app_index = ((RIL_slot & 0xFF) << 8) | (RIL_app_index & 0xFF);

  /* Now check if we need to proceed with incoming request */
  if ((RIL_uicc_subs_info_ptr->subs_mode_pref == QCRIL_SUBS_MODE_GW) &&
      (RIL_uicc_subs_info_ptr->uicc_subs_info.sub_type == RIL_SUBSCRIPTION_1))
  {
    if (((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_ACTIVATE) &&
         (qcril_uim.prov_session_info.session_state_gw_indexes[0] == QCRIL_UIM_PROV_SESSION_ACTIVATED) &&
         (prov_app_index == qcril_uim.card_status.index_gw_pri_prov)) ||
        ((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_DEACTIVATE) &&
        (qcril_uim.prov_session_info.session_state_gw_indexes[0] == QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED)))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_PRI_GW_PROV;
      return RIL_E_SUCCESS;
    }
  }
  else if ((RIL_uicc_subs_info_ptr->subs_mode_pref == QCRIL_SUBS_MODE_1X) &&
           (RIL_uicc_subs_info_ptr->uicc_subs_info.sub_type == RIL_SUBSCRIPTION_1))
  {
    if (((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_ACTIVATE) &&
         (qcril_uim.prov_session_info.session_state_1x_indexes[0] == QCRIL_UIM_PROV_SESSION_ACTIVATED) &&
         (prov_app_index == qcril_uim.card_status.index_1x_pri_prov)) ||
        ((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_DEACTIVATE) &&
        (qcril_uim.prov_session_info.session_state_1x_indexes[0] == QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED)))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_PRI_1X_PROV;
      return RIL_E_SUCCESS;
    }
  }
  else if ((RIL_uicc_subs_info_ptr->subs_mode_pref == QCRIL_SUBS_MODE_GW) &&
           (RIL_uicc_subs_info_ptr->uicc_subs_info.sub_type == RIL_SUBSCRIPTION_2))
  {
    if (((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_ACTIVATE) &&
         (qcril_uim.prov_session_info.session_state_gw_indexes[1] == QCRIL_UIM_PROV_SESSION_ACTIVATED) &&
         (prov_app_index == qcril_uim.card_status.index_gw_sec_prov)) ||
        ((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_DEACTIVATE) &&
        (qcril_uim.prov_session_info.session_state_gw_indexes[1] == QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED)))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_SEC_GW_PROV;
      return RIL_E_SUCCESS;
    }
  }
  else if ((RIL_uicc_subs_info_ptr->subs_mode_pref == QCRIL_SUBS_MODE_1X) &&
           (RIL_uicc_subs_info_ptr->uicc_subs_info.sub_type == RIL_SUBSCRIPTION_2))
  {
    if (((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_ACTIVATE) &&
         (qcril_uim.prov_session_info.session_state_1x_indexes[1] == QCRIL_UIM_PROV_SESSION_ACTIVATED) &&
         (prov_app_index == qcril_uim.card_status.index_1x_sec_prov)) ||
        ((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_DEACTIVATE) &&
        (qcril_uim.prov_session_info.session_state_1x_indexes[1] == QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED)))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_SEC_1X_PROV;
      return RIL_E_SUCCESS;
    }
  }
  else if ((RIL_uicc_subs_info_ptr->subs_mode_pref == QCRIL_SUBS_MODE_GW) &&
           (RIL_uicc_subs_info_ptr->uicc_subs_info.sub_type == RIL_SUBSCRIPTION_3))
  {
    if (((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_ACTIVATE) &&
         (qcril_uim.prov_session_info.session_state_gw_indexes[2] == QCRIL_UIM_PROV_SESSION_ACTIVATED) &&
         (prov_app_index == qcril_uim.card_status.index_gw_ter_prov)) ||
        ((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_DEACTIVATE) &&
        (qcril_uim.prov_session_info.session_state_gw_indexes[2] == QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED)))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_TER_GW_PROV;
      return RIL_E_SUCCESS;
    }
  }
  else if ((RIL_uicc_subs_info_ptr->subs_mode_pref == QCRIL_SUBS_MODE_1X) &&
           (RIL_uicc_subs_info_ptr->uicc_subs_info.sub_type == RIL_SUBSCRIPTION_3))
  {
    if (((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_ACTIVATE) &&
         (qcril_uim.prov_session_info.session_state_1x_indexes[2] == QCRIL_UIM_PROV_SESSION_ACTIVATED) &&
         (prov_app_index == qcril_uim.card_status.index_1x_ter_prov)) ||
        ((RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_DEACTIVATE) &&
        (qcril_uim.prov_session_info.session_state_1x_indexes[2] == QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED)))
    {
      session_params_ptr->session_type = QMI_UIM_SESSION_TYPE_TER_1X_PROV;
      return RIL_E_SUCCESS;
    }
  }

  QCRIL_LOG_DEBUG("Couldnt match session info: GW_PRI:%d, GW_SEC:%d, GW_TER:%d, 1X_PRI:%d, 1X_SEC:%d, 1X_TER:%d\n",
                  qcril_uim.prov_session_info.session_state_gw_indexes[0],
                  qcril_uim.prov_session_info.session_state_gw_indexes[1],
                  qcril_uim.prov_session_info.session_state_gw_indexes[2],
                  qcril_uim.prov_session_info.session_state_1x_indexes[0],
                  qcril_uim.prov_session_info.session_state_1x_indexes[1],
                  qcril_uim.prov_session_info.session_state_1x_indexes[2]);

  return QCRIL_UIM_RIL_E_INTERNAL_ERR;
} /* qcril_uim_ignore_change_subscription */


/*===========================================================================

  FUNCTION:  qcril_uim_fill_change_session_params

===========================================================================*/
/*!
    @brief
    Updates the passed provisioning session parameters by checking the input
    QCRIL request with our global data. Main paramters to be looked for are
    session_type and aid since aid is not passed by the RIL interface.

    @return
    RIL_Errno error code
*/
/*=========================================================================*/
static RIL_Errno qcril_uim_fill_change_session_params
(
  const qcril_uicc_subs_info_type             * RIL_uicc_subs_info_ptr,
  qmi_uim_change_prov_session_params_type     * session_params_ptr
)
{
  int              RIL_slot      = 0;
  int              RIL_app_index = 0;
  qmi_uim_app_type app_type      = QMI_UIM_APP_UNKNOWN;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  /* Sanity checks */
  if ((RIL_uicc_subs_info_ptr == NULL) || (session_params_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  /* Verify request type */
  if (RIL_uicc_subs_info_ptr->uicc_subs_info.act_status != RIL_UICC_SUBSCRIPTION_ACTIVATE &&
      RIL_uicc_subs_info_ptr->uicc_subs_info.act_status != RIL_UICC_SUBSCRIPTION_DEACTIVATE)
  {
    QCRIL_LOG_ERROR("Invalid Activation status request : 0x%x",
                                RIL_uicc_subs_info_ptr->uicc_subs_info.act_status);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  RIL_slot = RIL_uicc_subs_info_ptr->uicc_subs_info.slot;
  RIL_app_index = RIL_uicc_subs_info_ptr->uicc_subs_info.app_index;

  /* Check slot number */
  if (RIL_slot >= QMI_UIM_MAX_CARD_COUNT ||
      RIL_slot < 0)
  {
    QCRIL_LOG_ERROR("Invalid slot value: 0x%x", RIL_slot);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  /* Check app index */
  if ((RIL_app_index < 0) || (RIL_app_index >= QMI_UIM_MAX_APP_PER_CARD_COUNT))
  {
    QCRIL_LOG_ERROR("Invalid app index: 0x%x", RIL_app_index);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  /* Verify card status */
  if (qcril_uim.card_status.card[RIL_slot].card_state != QMI_UIM_CARD_STATE_PRESENT)
  {
    QCRIL_LOG_ERROR("%s", "Card is not present");
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  /* During an activation request, we expect that it is currently not activated
     on any application, hence we cannot check card_status.index_gw_pri_prov or
     Deactivation received before card status indication with app activation info */
  app_type = qcril_uim.card_status.card[RIL_slot].application[RIL_app_index].app_type;

  if (RIL_uicc_subs_info_ptr->uicc_subs_info.act_status == RIL_UICC_SUBSCRIPTION_ACTIVATE)
  {
    uint8 aid_len = qcril_uim.card_status.card[RIL_slot].application[RIL_app_index].aid_len;

    /* For activation request, we need to send the aid & slot also */
    if (RIL_slot == 0)
    {
      session_params_ptr->app_info.slot = QMI_UIM_SLOT_1;
    }
    else if (RIL_slot == 1)
    {
      session_params_ptr->app_info.slot = QMI_UIM_SLOT_2;
    }
    else
    {
      session_params_ptr->app_info.slot = QMI_UIM_SLOT_3;
    }

    if ((aid_len > 0) && (aid_len <= QMI_UIM_MAX_AID_LEN))
    {
      /* We pass AID only if requested to accomodate SIM/RUIM app_type */
      session_params_ptr->app_info.aid.data_ptr =
          (unsigned char*)qcril_uim.card_status.card[RIL_slot].application[RIL_app_index].aid_value;
      session_params_ptr->app_info.aid.data_len = aid_len;
    }
  }

  return qcril_uim_find_prov_session_type(session_params_ptr, app_type,
                                          RIL_uicc_subs_info_ptr->uicc_subs_info.sub_type,
                                          RIL_uicc_subs_info_ptr->subs_mode_pref,
                                          RIL_uicc_subs_info_ptr->uicc_subs_info.act_status);
} /* qcril_uim_fill_change_session_params */


/*===========================================================================

  FUNCTION:  qcril_uim_update_prov_app_index

===========================================================================*/
/*!
    @brief
    Checks if the passed provisioning app index belongs to the input slot
    requested for. If yes, respective index variables - GSM/UMTS or CDMA of
    RIL_CardStatus_v6 are updated based on the type of the provisioning app.

    @return
    None.

*/
/*=========================================================================*/
static void qcril_uim_update_prov_app_index
(
  unsigned short        input_index,
  uint8                 input_slot,
  RIL_CardStatus_v6   * ril_card_status_ptr,
  qmi_uim_session_type  session_type
)
{
  uint8 prov_app_index = QCRIL_UIM_INVALID_APP_INDEX_VALUE;
  uint8 prov_app_slot  = QCRIL_UIM_INVALID_SLOT_INDEX_VALUE;

  if (ril_card_status_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "NULL ril_card_status_ptr, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  prov_app_index = input_index & 0xFF;
  prov_app_slot  = (input_index >> 8) & 0xFF;

  /* Check if the passed prov app's slot matches with the card index */
  if ((input_slot == prov_app_slot) &&
      (prov_app_index < RIL_CARD_MAX_APPS))
  {
    switch(session_type)
    {
      case QMI_UIM_SESSION_TYPE_PRI_GW_PROV:
      case QMI_UIM_SESSION_TYPE_SEC_GW_PROV:
      case QMI_UIM_SESSION_TYPE_TER_GW_PROV:
        ril_card_status_ptr->gsm_umts_subscription_app_index = prov_app_index;
        break;

      case QMI_UIM_SESSION_TYPE_PRI_1X_PROV:
      case QMI_UIM_SESSION_TYPE_SEC_1X_PROV:
      case QMI_UIM_SESSION_TYPE_TER_1X_PROV:
        ril_card_status_ptr->cdma_subscription_app_index = prov_app_index;
        break;

      default:
        QCRIL_LOG_DEBUG( "Unsupported prov_app_type - %d \n", session_type);
        break;
    }
  }
} /* qcril_uim_update_prov_app_index */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_card_state

===========================================================================*/
/*!
    @brief
    Converts a qmi_uim_card_state_type to RIL_CardState. Mapped RIL_CardState
    is updated in the passed pointer.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_convert_card_state
(
  RIL_CardState             * ril_card_state_ptr,
  qmi_uim_card_state_type     qmi_card_state,
  qmi_uim_card_error_type     qmi_card_error
)
{
  if (ril_card_state_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  switch(qmi_card_state)
  {
    case QMI_UIM_CARD_STATE_ABSENT:
    case QMI_UIM_CARD_STATE_UNKNOWN:
      *ril_card_state_ptr = RIL_CARDSTATE_ABSENT;
      break;

    case QMI_UIM_CARD_STATE_PRESENT:
      *ril_card_state_ptr = RIL_CARDSTATE_PRESENT;
      break;

    case QMI_UIM_CARD_STATE_ERROR:
      if ((qmi_card_error == QMI_UIM_CARD_ERROR_NO_ATR_RECEIVED) ||
          (qmi_card_error == QMI_UIM_CARD_ERROR_UNKNOWN_REMOVED) ||
          (qmi_card_error == QMI_UIM_CARD_ERROR_POWER_DOWN))
      {
        *ril_card_state_ptr = RIL_CARDSTATE_ABSENT;
      }
      else
      {
        *ril_card_state_ptr = RIL_CARDSTATE_ERROR;
      }
      break;

    default:
      *ril_card_state_ptr = RIL_CARDSTATE_ERROR;
      break;
  }
} /* qcril_uim_convert_card_state */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_pin_state

===========================================================================*/
/*!
    @brief
    Converts a qmi_uim_pin_status_type to RIL_PinState. Mapped RIL_PinState
    is updated in the passed pointer.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_convert_pin_state
(
  RIL_PinState              * ril_pin_state_ptr,
  qmi_uim_pin_status_type     qmi_pin_state
)
{
  if (ril_pin_state_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  switch(qmi_pin_state)
  {
    case QMI_UIM_PIN_STATE_ENABLED_NOT_VERIFIED:
      *ril_pin_state_ptr = RIL_PINSTATE_ENABLED_NOT_VERIFIED;
      break;

    case QMI_UIM_PIN_STATE_ENABLED_VERIFIED:
      *ril_pin_state_ptr = RIL_PINSTATE_ENABLED_VERIFIED;
      break;

    case QMI_UIM_PIN_STATE_DISABLED:
      *ril_pin_state_ptr = RIL_PINSTATE_DISABLED;
      break;

    case QMI_UIM_PIN_STATE_BLOCKED:
      *ril_pin_state_ptr = RIL_PINSTATE_ENABLED_BLOCKED;
      break;

    case QMI_UIM_PIN_STATE_PERM_BLOCKED:
      *ril_pin_state_ptr = RIL_PINSTATE_ENABLED_PERM_BLOCKED;
      break;

    case QMI_UIM_PIN_STATE_UNKNOWN:
    default:
      *ril_pin_state_ptr = RIL_PINSTATE_UNKNOWN;
      break;
  }
} /* qcril_uim_convert_pin_state */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_app_type

===========================================================================*/
/*!
    @brief
    Converts a qmi_uim_app_type to RIL_AppType. Mapped RIL_AppType
    is updated in the passed pointer.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_convert_app_type
(
  RIL_AppType               * ril_app_type_ptr,
  qmi_uim_app_type            qmi_app_type
)
{
  if (ril_app_type_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  switch(qmi_app_type)
  {
    case QMI_UIM_APP_SIM:
      *ril_app_type_ptr = RIL_APPTYPE_SIM;
      break;

    case QMI_UIM_APP_USIM:
      *ril_app_type_ptr = RIL_APPTYPE_USIM;
      break;

    case QMI_UIM_APP_RUIM:
      *ril_app_type_ptr = RIL_APPTYPE_RUIM;
      break;

    case QMI_UIM_APP_CSIM:
      *ril_app_type_ptr = RIL_APPTYPE_CSIM;
      break;

    case QMI_UIM_APP_ISIM:
      *ril_app_type_ptr = RIL_APPTYPE_ISIM;
      break;

    case QMI_UIM_APP_UNKNOWN:
    default:
      *ril_app_type_ptr = RIL_APPTYPE_UNKNOWN;
      break;
  }
} /* qcril_uim_convert_app_type */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_app_state_to_ril

===========================================================================*/
/*!
    @brief
    Converts a qmi_uim_app_state_type to RIL_AppState. Mapped RIL_AppState
    is updated in the passed pointer.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_convert_app_state_to_ril
(
  RIL_AppState              * ril_app_state_ptr,
  qmi_uim_app_state_type      qmi_app_state
)
{
  if (ril_app_state_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  switch(qmi_app_state)
  {
    case QMI_UIM_APP_STATE_UNKNOWN:
      *ril_app_state_ptr = RIL_APPSTATE_UNKNOWN;
      break;

    case QMI_UIM_APP_STATE_DETECTED:
      *ril_app_state_ptr = RIL_APPSTATE_DETECTED;
      break;

    case QMI_UIM_APP_STATE_PIN_REQUIRED:
      *ril_app_state_ptr = RIL_APPSTATE_PIN;
      break;

    case QMI_UIM_APP_STATE_PUK1_REQUIRED:
    case QMI_UIM_APP_STATE_BLOCKED:
      *ril_app_state_ptr = RIL_APPSTATE_PUK;
      break;

    case QMI_UIM_APP_STATE_PERSO:
      *ril_app_state_ptr = RIL_APPSTATE_SUBSCRIPTION_PERSO;
      break;

    case QMI_UIM_APP_STATE_ILLEGAL:
      *ril_app_state_ptr = RIL_APPSTATE_ILLEGAL;
      break;

    case QMI_UIM_APP_STATE_READY:
      *ril_app_state_ptr = RIL_APPSTATE_READY;
      break;

    default:
      *ril_app_state_ptr = RIL_APPSTATE_UNKNOWN;
      break;
  }
} /* qcril_uim_convert_app_state_to_ril */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_app_state_to_qcril

===========================================================================*/
/*!
    @brief
    Converts a qmi_uim_app_state_type to qcril_sim_state_e_type. Mapped
    qcril_sim_state_e_type is updated in the passed pointer.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_convert_app_state_to_qcril
(
  qcril_sim_state_e_type    * qcril_sim_state_ptr,
  qmi_uim_app_state_type      qmi_app_state
)
{
  if (qcril_sim_state_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  switch(qmi_app_state)
  {
    case QMI_UIM_APP_STATE_PIN_REQUIRED:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_PIN;
      break;

    case QMI_UIM_APP_STATE_PUK1_REQUIRED:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_PUK;
      break;

    case QMI_UIM_APP_STATE_PERSO:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_NETWORK_PERSONALIZATION;
      break;

    case QMI_UIM_APP_STATE_BLOCKED:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_ABSENT;
      break;

    case QMI_UIM_APP_STATE_ILLEGAL:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_ILLEGAL;
      break;

    case QMI_UIM_APP_STATE_READY:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_READY;
      break;

    case QMI_UIM_APP_STATE_UNKNOWN:
    case QMI_UIM_APP_STATE_DETECTED:
    default:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_NOT_READY;
      break;
  }
} /* qcril_uim_convert_app_state_to_qcril */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_perso_state_to_qcril

===========================================================================*/
/*!
    @brief
    Converts a qmi_uim_app_state_type to qcril_sim_state_e_type. Mapped
    qcril_sim_state_e_type is updated in the passed pointer.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_convert_perso_state_to_qcril
(
  qcril_sim_state_e_type    * qcril_sim_state_ptr,
  qmi_uim_perso_state_type    qmi_perso_state
)
{
  if (qcril_sim_state_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  switch(qmi_perso_state)
  {
    case QMI_UIM_PERSO_STATE_IN_PROGRESS:
      /* No change to sim state */
      break;

    case QMI_UIM_PERSO_STATE_READY:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_READY;
      break;

    /* Todo - check if there is any other code for other feature ids */
    case QMI_UIM_PERSO_STATE_CODE_REQUIRED:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_NETWORK_PERSONALIZATION;
      break;

    case QMI_UIM_PERSO_STATE_PUK_REQUIRED:
    case QMI_UIM_PERSO_STATE_PERM_BLOCKED:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_ABSENT;
      break;

    case QMI_UIM_PERSO_STATE_UNKNOWN:
    default:
      *qcril_sim_state_ptr = QCRIL_SIM_STATE_NOT_READY;
      break;
  }
} /* qcril_uim_convert_perso_state_to_qcril */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_perso_state_code_required

===========================================================================*/
/*!
    @brief
    Converts qmi_uim_perso_feature_id_type to RIL_PersoSubstate for the
    cases where the codes for personalization codes are needed.

    @return
    Mapped RIL_PersoSubstate.
*/
/*=========================================================================*/
static RIL_PersoSubstate qcril_uim_convert_perso_state_code_required
(
  qmi_uim_perso_feature_status_type   qmi_perso_feature_status
)
{
  RIL_PersoSubstate   perso_substate = RIL_PERSOSUBSTATE_UNKNOWN;

  switch(qmi_perso_feature_status)
  {
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_NW:
      perso_substate = RIL_PERSOSUBSTATE_SIM_NETWORK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_NS:
      perso_substate = RIL_PERSOSUBSTATE_SIM_NETWORK_SUBSET;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SP:
      perso_substate = RIL_PERSOSUBSTATE_SIM_SERVICE_PROVIDER;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_CP:
      perso_substate = RIL_PERSOSUBSTATE_SIM_CORPORATE;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SPN:
      perso_substate = RIL_PERSOSUBSTATE_SIM_SPN;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SP_EHPLMN:
      perso_substate = RIL_PERSOSUBSTATE_SIM_SP_EHPLMN;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_ICCID:
      perso_substate = RIL_PERSOSUBSTATE_SIM_ICCID;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_IMPI:
      perso_substate = RIL_PERSOSUBSTATE_SIM_IMPI;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SIM:
      perso_substate = RIL_PERSOSUBSTATE_SIM_SIM;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_NS_SP:
      perso_substate = RIL_PERSOSUBSTATE_SIM_NS_SP;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_NW1:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_NETWORK1;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_NW2:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_NETWORK2;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_HRPD:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_HRPD;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_SP:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_SERVICE_PROVIDER;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_CP:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_CORPORATE;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_RUIM:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_RUIM;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_UNKNOWN:
    default:
      perso_substate = RIL_PERSOSUBSTATE_UNKNOWN;
      break;
  }
  return perso_substate;
} /* qcril_uim_convert_perso_state_code_required */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_perso_state_puk_required

===========================================================================*/
/*!
    @brief
    Converts qmi_uim_perso_feature_id_type to RIL_PersoSubstate for the
    cases where PUK for personalization codes are needed.

    @return
    Mapped RIL_PersoSubstate.
*/
/*=========================================================================*/
static RIL_PersoSubstate qcril_uim_convert_perso_state_puk_required
(
  qmi_uim_perso_feature_status_type   qmi_perso_feature_status
)
{
  RIL_PersoSubstate   perso_substate = RIL_PERSOSUBSTATE_UNKNOWN;

  switch(qmi_perso_feature_status)
  {
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_NW:
      perso_substate = RIL_PERSOSUBSTATE_SIM_NETWORK_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_NS:
      perso_substate = RIL_PERSOSUBSTATE_SIM_NETWORK_SUBSET_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SP:
      perso_substate = RIL_PERSOSUBSTATE_SIM_SERVICE_PROVIDER_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_CP:
      perso_substate = RIL_PERSOSUBSTATE_SIM_CORPORATE_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SPN:
      perso_substate = RIL_PERSOSUBSTATE_SIM_SPN_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SP_EHPLMN:
      perso_substate = RIL_PERSOSUBSTATE_SIM_SP_EHPLMN_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_ICCID:
      perso_substate = RIL_PERSOSUBSTATE_SIM_ICCID_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_IMPI:
      perso_substate = RIL_PERSOSUBSTATE_SIM_IMPI_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SIM:
      perso_substate = RIL_PERSOSUBSTATE_SIM_SIM_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_NS_SP:
      perso_substate = RIL_PERSOSUBSTATE_SIM_NS_SP_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_NW1:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_NETWORK1_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_NW2:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_NETWORK2_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_HRPD:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_HRPD_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_SP:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_SERVICE_PROVIDER_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_CP:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_CORPORATE_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_RUIM:
      perso_substate = RIL_PERSOSUBSTATE_RUIM_RUIM_PUK;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_UNKNOWN:
    default:
      perso_substate = RIL_PERSOSUBSTATE_UNKNOWN;
      break;
  }
  return perso_substate;
} /* qcril_uim_convert_perso_state_puk_required */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_perso_feature_status_to_perso_feature_id

===========================================================================*/
/*!
    @brief
    Converts personalization feature status to personalization feature ID

    @return
    None
*/
/*=========================================================================*/
static boolean qcril_uim_convert_perso_feature_status_to_perso_feature_id
(
  qmi_uim_perso_feature_status_type   perso_feature_status,
  qmi_uim_perso_feature_id_type      *perso_feature_id_ptr
)
{
  boolean status = TRUE;

  if(perso_feature_id_ptr == NULL)
  {
    return FALSE;
  }

  switch(perso_feature_status)
  {
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_NW:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_NW;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_NS:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_NS;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SP:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_SP;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_CP:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_CP;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SIM:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_SIM;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_NW1:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_1X_NW1;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_NW2:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_1X_NW2;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_HRPD:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_1X_HRPD;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_SP:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_1X_SP;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_1X_CP:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_1X_CP;
      break;
     case QMI_UIM_PERSO_FEATURE_STATUS_1X_RUIM:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_1X_RUIM;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SPN:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_SPN;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_SP_EHPLMN:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_SP_EHPLMN;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_ICCID:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_ICCID;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_IMPI:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_IMPI;
      break;
    case QMI_UIM_PERSO_FEATURE_STATUS_GW_NS_SP:
      *perso_feature_id_ptr = QMI_UIM_PERSO_FEATURE_GW_NS_SP;
      break;
    default:
      status = FALSE;
      break;
  }

  return status;
} /* qcril_uim_convert_perso_feature_status_to_perso_feature_id */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_perso_state_all

===========================================================================*/
/*!
    @brief
    Converts a qmi_uim_app_state_type to RIL_PersoSubstate. Mapped
    RIL_PersoSubstate is updated in the passed pointer.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_convert_perso_state_all
(
  RIL_PersoSubstate                 * ril_perso_substate_ptr,
  qmi_uim_perso_state_type            qmi_perso_state,
  qmi_uim_perso_feature_status_type   qmi_perso_feature_status
)
{
  uint8                                  i                 = 0;
  int                                    ret    = 0;
  qmi_uim_get_configuration_params_type  get_config_params;
  qmi_uim_rsp_data_type                  rsp_data;

  memset(&get_config_params, 0x00, sizeof(get_config_params));
  memset(&rsp_data, 0x00, sizeof(rsp_data));

  if (ril_perso_substate_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  switch(qmi_perso_state)
  {
    case QMI_UIM_PERSO_STATE_IN_PROGRESS:
      *ril_perso_substate_ptr = RIL_PERSOSUBSTATE_IN_PROGRESS;
      break;

    case QMI_UIM_PERSO_STATE_READY:
      *ril_perso_substate_ptr = RIL_PERSOSUBSTATE_READY;
      break;

    case QMI_UIM_PERSO_STATE_CODE_REQUIRED:
    case QMI_UIM_PERSO_STATE_PUK_REQUIRED:
    case QMI_UIM_PERSO_STATE_PERM_BLOCKED:
      get_config_params.perso_status = QMI_UIM_TRUE;
      ret = qcril_qmi_uim_get_configuration(qcril_uim.qmi_handle,
                                            &get_config_params,
                                            NULL,
                                            NULL,
                                            &rsp_data);
      if (ret == QMI_NO_ERR)
      {
        boolean                       perso_convert_status = FALSE;
        qmi_uim_perso_feature_id_type perso_feature_id     = QMI_UIM_PERSO_FEATURE_GW_NW;

        perso_convert_status = qcril_uim_convert_perso_feature_status_to_perso_feature_id(
                                 qmi_perso_feature_status,
                                 &perso_feature_id);
        if(perso_convert_status)
        {
          /* If control key is not present then send perso status as SIM_RSU.
             This makes sure to not show the SIMLOCK pop up on UI asking control key */
          for(i = 0; i < QMI_UIM_MAX_PERSO_FEATURES; i++)
          {
            if(rsp_data.rsp_data.get_configuration_rsp.perso_status[i].feature == perso_feature_id)
            {
              if (!rsp_data.rsp_data.get_configuration_rsp.perso_status[i].ck_present)
              {
                *ril_perso_substate_ptr = RIL_PERSOSUBSTATE_SIM_RSU;
                return;
              }
              break;
            }
          }
        }
      }

      if(qmi_perso_state == QMI_UIM_PERSO_STATE_CODE_REQUIRED)
      {
        *ril_perso_substate_ptr =
          qcril_uim_convert_perso_state_code_required(qmi_perso_feature_status);
      }
      else
      {
        *ril_perso_substate_ptr =
          qcril_uim_convert_perso_state_puk_required(qmi_perso_feature_status);
      }
      break;

    case QMI_UIM_PERSO_STATE_UNKNOWN:
    default:
      *ril_perso_substate_ptr = RIL_PERSOSUBSTATE_UNKNOWN;
      break;
  }
} /* qcril_uim_convert_perso_state_all */


/*===========================================================================

  FUNCTION:  qcril_uim_add_aid_info

===========================================================================*/
/*!
    @brief
    Updates the passed RIL AID pointer with AID data if it has been received
    from QMI, does nothing otherwise.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_add_aid_info
(
  char             ** ril_aid_ptr,
  const char       *  qmi_aid_ptr,
  unsigned char       qmi_aid_len
)
{
  if ((ril_aid_ptr == NULL) || (qmi_aid_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  /* Convert the AID in hex to a null terminated ASCII string
     The function qcril_uim_alloc_bin_to_hexstring will perform the allocation & data conversion */
  *ril_aid_ptr = qcril_uim_alloc_bin_to_hexstring((const uint8*)qmi_aid_ptr,
                                                  qmi_aid_len);

  if (*ril_aid_ptr == NULL)
  {
    QCRIL_LOG_ERROR( "%s", "Unable to allocate aid_ptr\n");
  }
} /* qcril_uim_add_aid_info */


/*===========================================================================

  FUNCTION:  qcril_uim_add_label_info

===========================================================================*/
/*!
    @brief
    Updates the passed RIL Label pointer with label data if it has been
    received from QMI, does nothing otherwise.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_add_label_info
(
  char                              ** ril_label_ptr,
  qmi_uim_get_label_rsp_type         * qmi_label_rsp_ptr
)
{
  int i = 0;

  /* Sanity check */
  if ((ril_label_ptr == NULL) ||
      (qmi_label_rsp_ptr == NULL) ||
      (qmi_label_rsp_ptr->label_len > QMI_UIM_MAX_LABEL_LEN))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  /* Print label */
  QCRIL_LOG_DEBUG("%s", "Raw label value:\n");
  for (i = 0; i < qmi_label_rsp_ptr->label_len ; i++)
  {
    QCRIL_LOG_DEBUG(" 0X%x", qmi_label_rsp_ptr->label_value[i]);
  }

  /* Convert the Label in hex to a null terminated ASCII string
     The function qcril_uim_alloc_bin_to_hexstring will perform the allocation & data conversion */
  *ril_label_ptr = qcril_uim_alloc_bin_to_hexstring((const uint8*)qmi_label_rsp_ptr->label_value,
                                                     qmi_label_rsp_ptr->label_len);

  if (*ril_label_ptr == NULL)
  {
    QCRIL_LOG_ERROR( "%s", "Unable to allocate label_ptr\n");
  }
} /* qcril_uim_add_label_info */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_pin1_replaced_state

===========================================================================*/
/*!
    @brief
    Updates the passed pointer to indicate if PIN1 is replaced with UPIN.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_convert_pin1_replaced_state
(
  int              * ril_pin1_replaced_ptr,
  unsigned char      qmi_univ_pin
)
{
  if (ril_pin1_replaced_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  if(qmi_univ_pin == 0)
  {
    *ril_pin1_replaced_ptr = 0;
  }
  else if(qmi_univ_pin == 1)
  {
    *ril_pin1_replaced_ptr = 1;
  }
} /* qcril_uim_convert_pin1_replaced_state */


/*===========================================================================

  FUNCTION:  qcril_uim_free_aid_and_label_info

===========================================================================*/
/*!
    @brief
    Frees the memory allocated for aid and label data that was allocated as
    part of qcril_uim_add_aid_info and qcril_uim_add_label_info respectively.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_free_aid_and_label_info
(
  RIL_CardStatus_v6      * ril_card_status_ptr
)
{
  int app_index = 0;
  int max_apps = 0;

  if (ril_card_status_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  QCRIL_LOG_INFO( "%s\n", "Freeing AID & label buffers" );

  max_apps = (ril_card_status_ptr->num_applications <= RIL_CARD_MAX_APPS)
               ? ril_card_status_ptr->num_applications : RIL_CARD_MAX_APPS;

  /* Loop through all the apps and free buffers allocated */
  for (app_index = 0; app_index < max_apps; app_index++)
  {
    if(ril_card_status_ptr->applications[app_index].aid_ptr != NULL)
    {
      qcril_free(ril_card_status_ptr->applications[app_index].aid_ptr);
      ril_card_status_ptr->applications[app_index].aid_ptr = NULL;
      QCRIL_LOG_DEBUG("Freed AID pointer, app[%d] \n", app_index);
    }
    if(ril_card_status_ptr->applications[app_index].app_label_ptr != NULL)
    {
      qcril_free(ril_card_status_ptr->applications[app_index].app_label_ptr);
      ril_card_status_ptr->applications[app_index].app_label_ptr = NULL;
      QCRIL_LOG_DEBUG("Freed Label pointer, app[%d] \n", app_index);
    }
  }
} /* qcril_uim_free_aid_and_label_info */


/*===========================================================================

  FUNCTION:  qcril_uim_construct_card_status

===========================================================================*/
/*!
    @brief
    Constructs the RIL card status from our internal QMI card status type.
    Also, an appropriate card state name is filled.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_construct_card_status
(
  RIL_CardStatus_v6                 * ril_card_status_ptr,
  const qmi_uim_card_status_type    * card_status_ptr,
  uint8                               slot
)
{
  int                   app_index  = 0;
  int                   max_apps   = 0;
  uint8                 isim_index = QCRIL_UIM_INVALID_APP_INDEX_VALUE;
  qmi_uim_rsp_data_type get_label_rsp;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  if ((ril_card_status_ptr == NULL) || (card_status_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  memset(ril_card_status_ptr, 0, sizeof(RIL_CardStatus_v6));
  memset(&get_label_rsp, 0, sizeof(qmi_uim_rsp_data_type));

  if(slot >= QMI_UIM_MAX_CARD_COUNT)
  {
    QCRIL_LOG_ERROR("Invalid slot index 0x%x", slot);
    return;
  }

  /* Update Card state */
  qcril_uim_convert_card_state(&ril_card_status_ptr->card_state,
                               card_status_ptr->card[slot].card_state,
                               card_status_ptr->card[slot].card_error);
  /* Update UPIN state */
  qcril_uim_convert_pin_state(&ril_card_status_ptr->universal_pin_state,
                              card_status_ptr->card[slot].upin_state);

  /* Init App indexes */
  ril_card_status_ptr->gsm_umts_subscription_app_index = -1;
  ril_card_status_ptr->cdma_subscription_app_index     = -1;
  ril_card_status_ptr->ims_subscription_app_index      = -1;

  /* Update App indexes */
  qcril_uim_update_prov_app_index(card_status_ptr->index_gw_pri_prov, slot,
                                  ril_card_status_ptr, QMI_UIM_SESSION_TYPE_PRI_GW_PROV);
  qcril_uim_update_prov_app_index(card_status_ptr->index_gw_sec_prov, slot,
                                  ril_card_status_ptr, QMI_UIM_SESSION_TYPE_SEC_GW_PROV);
  qcril_uim_update_prov_app_index(card_status_ptr->index_gw_ter_prov, slot,
                                  ril_card_status_ptr, QMI_UIM_SESSION_TYPE_TER_GW_PROV);
  qcril_uim_update_prov_app_index(card_status_ptr->index_1x_pri_prov, slot,
                                  ril_card_status_ptr, QMI_UIM_SESSION_TYPE_PRI_1X_PROV);
  qcril_uim_update_prov_app_index(card_status_ptr->index_1x_sec_prov, slot,
                                  ril_card_status_ptr, QMI_UIM_SESSION_TYPE_SEC_1X_PROV);
  qcril_uim_update_prov_app_index(card_status_ptr->index_1x_ter_prov, slot,
                                  ril_card_status_ptr, QMI_UIM_SESSION_TYPE_TER_1X_PROV);

  /* Update ISIM index if applicable */
  if ((qcril_uim_extract_isim_index(&isim_index, slot) == RIL_E_SUCCESS) &&
      (isim_index < RIL_CARD_MAX_APPS))
  {
    ril_card_status_ptr->ims_subscription_app_index = isim_index;
  }

  max_apps = (card_status_ptr->card[slot].num_app <= RIL_CARD_MAX_APPS)
              ? card_status_ptr->card[slot].num_app : RIL_CARD_MAX_APPS;

  ril_card_status_ptr->num_applications = max_apps;

  for (app_index = 0; app_index < max_apps; app_index++)
  {
    qcril_uim_convert_app_type(&ril_card_status_ptr->applications[app_index].app_type,
                               card_status_ptr->card[slot].application[app_index].app_type);
    qcril_uim_convert_app_state_to_ril(&ril_card_status_ptr->applications[app_index].app_state,
                                       card_status_ptr->card[slot].application[app_index].app_state);

    /* Move the ISIM app state to Ready if the following conditions satisfy:
       1) App state is DETECTED
       2) PIN1 state is either DISABLED or ENABLED & VERIFIED */
    if ((card_status_ptr->card[slot].application[app_index].app_type == QMI_UIM_APP_ISIM) &&
        (card_status_ptr->card[slot].application[app_index].app_state == QMI_UIM_APP_STATE_DETECTED) &&
        ((card_status_ptr->card[slot].application[app_index].pin1_state == QMI_UIM_PIN_STATE_DISABLED) ||
         (card_status_ptr->card[slot].application[app_index].pin1_state == QMI_UIM_PIN_STATE_ENABLED_VERIFIED)))
    {
      ril_card_status_ptr->applications[app_index].app_state = RIL_APPSTATE_READY;
    }
    qcril_uim_convert_perso_state_all(&ril_card_status_ptr->applications[app_index].perso_substate,
                                      card_status_ptr->card[slot].application[app_index].perso_state,
                                      card_status_ptr->card[slot].application[app_index].perso_feature);

    if (card_status_ptr->card[slot].application[app_index].aid_len <= QMI_UIM_MAX_AID_LEN)
    {
      qcril_uim_add_aid_info(&ril_card_status_ptr->applications[app_index].aid_ptr,
                             card_status_ptr->card[slot].application[app_index].aid_value,
                             card_status_ptr->card[slot].application[app_index].aid_len);
    }
    /* Note - Sync QMI call for fetching app_label_ptr data, supposed to be fetched
     *        directly from QMI cache */
    if (qcril_uim_send_get_label(qcril_uim.qmi_handle, slot,
                                 &get_label_rsp,
                                 card_status_ptr->card[slot].application[app_index].aid_value,
                                 card_status_ptr->card[slot].application[app_index].aid_len) == QMI_NO_ERR)
    {
      qcril_uim_add_label_info(&ril_card_status_ptr->applications[app_index].app_label_ptr,
                               &get_label_rsp.rsp_data.get_label_rsp);
    }
    qcril_uim_convert_pin1_replaced_state(&ril_card_status_ptr->applications[app_index].pin1_replaced,
                                          card_status_ptr->card[slot].application[app_index].univ_pin);
    qcril_uim_convert_pin_state(&ril_card_status_ptr->applications[app_index].pin1,
                                card_status_ptr->card[slot].application[app_index].pin1_state);
#ifdef FEATURE_QCRIL_UIM_QMI_UPIN
    /* Workaround to send state of UPIN in PIN1 variable if UPIN is enabled,
       until UI support for UPIN is available */
    if (card_status_ptr->card[slot].application[app_index].univ_pin == QCRIL_UIM_UPIN_STATE_REPLACES_PIN1)
    {
      /* App's PIN1 is replaced by UPIN */
      qcril_uim_convert_pin_state(&ril_card_status_ptr->applications[app_index].pin1,
                                  card_status_ptr->card[slot].upin_state);
    }
#endif /* FEATURE_QCRIL_UIM_QMI_UPIN */
    qcril_uim_convert_pin_state(&ril_card_status_ptr->applications[app_index].pin2,
                                card_status_ptr->card[slot].application[app_index].pin2_state);
  }
} /* qcril_uim_construct_card_status */


/*===========================================================================

  FUNCTION:  qcril_uim_update_gstk_card_event

===========================================================================*/
/*!
    @brief
    Update QCRIL GSTK with card error/absent status.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_update_gstk_card_event
(
  qcril_instance_id_e_type instance_id,
  qcril_modem_id_e_type    modem_id,
  int                      slot
)
{
  /* Send event to QCRIL_GSTK with slot index as the payload*/
  if (qcril_process_event(instance_id,
                          modem_id,
                          QCRIL_EVT_GSTK_QMI_NOTIFY_CARD_ERROR,
                          (void *) &slot,
                          sizeof(slot),
                          (RIL_Token) QCRIL_TOKEN_ID_INTERNAL) != E_SUCCESS)
  {
    QCRIL_LOG_ERROR("QCRIL_EVT_GSTK_QMI_NOTIFY_CARD_ERROR failed for slot_index: 0x%x",
                    slot);
  }
} /* qcril_uim_update_gstk_card_event() */


/*===========================================================================

  FUNCTION:  qcril_uim_update_cm_card_status

===========================================================================*/
/*!
    @brief
    Update QCRIL(CM) card status per UIM card state.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_update_cm_card_status
(
  qcril_instance_id_e_type instance_id,
  qcril_modem_id_e_type    modem_id,
  int                      slot,
  qcril_card_status_e_type new_card_status
)
{
  qcril_card_info_type card_info;

  card_info.slot = slot;
  card_info.status = new_card_status;

  if (qcril_process_event( instance_id,
                           modem_id,
                           QCRIL_EVT_CM_CARD_STATUS_UPDATED,
                           (void *) &card_info,
                           sizeof( card_info ),
                           (RIL_Token) QCRIL_TOKEN_ID_INTERNAL ) != E_SUCCESS )
  {
    QCRIL_LOG_ERROR( "Slot %d CM_CARD_STATUS_UPDATED Failed!\n", slot )
  }
} /* qcril_uim_update_cm_card_status() */


/*===========================================================================

  FUNCTION:  qcril_uim_update_pbm_card_event

===========================================================================*/
/*!
    @brief
    Update QCRIL(PBM) card event per MMGSDI card state.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_update_pbm_card_event
(
  qcril_instance_id_e_type instance_id,
  qcril_modem_id_e_type    modem_id,
  int                      slot,
  qcril_evt_e_type         pbm_card_event
)
{
  uint8 i = instance_id;

  switch (pbm_card_event)
  {
    case QCRIL_EVT_PBM_CARD_INSERTED:
    case QCRIL_EVT_PBM_CARD_ERROR:
    case QCRIL_EVT_PBM_CARD_INIT_COMPLETED:
      if ( ril_to_uim_is_dsds_enabled() || ril_to_uim_is_tsts_enabled() )
      { /* DSDS case */
        for ( i = 0; i < QCRIL_ARB_MAX_INSTANCES; i++ )
        {
          if ( qcril_process_event( i, modem_id,
                                    pbm_card_event,
                                    (void *) &slot,
                                    sizeof( slot ),
                                    (RIL_Token)QCRIL_TOKEN_ID_INTERNAL) != E_SUCCESS )
          {
            QCRIL_LOG_ERROR( "PBM_HANDLE_CARD %d processing Failed!\n", pbm_card_event );
          }
        }
      }
      else
      {  /* non DSDS/TSTS case */
        if ( qcril_process_event( i, modem_id,
                                  pbm_card_event,
                                  (void *) &slot,
                                  sizeof( slot ),
                                  (RIL_Token)QCRIL_TOKEN_ID_INTERNAL) != E_SUCCESS )
        {
          QCRIL_LOG_ERROR( "PBM_HANDLE_CARD %d processing Failed!\n", pbm_card_event );
        }
      }
      break;

    default:
      break;
  }
} /* qcril_uim_update_pbm_card_event() */


/*===========================================================================

  FUNCTION:  qcril_uim_update_cm_fdn_status

===========================================================================*/
/*!
    @brief
    Gets FDN status from card so that QCRIL(CM) can be updated at power up.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_update_cm_fdn_status
(
  qcril_modem_id_e_type    modem_id,
  int                      slot,
  qmi_uim_session_type     session_type
)
{
  qmi_uim_get_service_status_params_type    service_status_params;
  qcril_instance_id_e_type                  instance_id = QCRIL_DEFAULT_INSTANCE_ID;
  RIL_Token                                 token = (RIL_Token)QCRIL_TOKEN_ID_INTERNAL;
  uint8                                     slot_index = 0;
  uint8                                     app_index = 0;
  qcril_uim_original_request_type         * callback_request_ptr = NULL;
#ifndef FEATURE_QCRIL_UIM_QMI_SIMIO_ASYNC_CALL
  qcril_uim_callback_params_type            callback_params;
#endif /* FEATURE_QCRIL_UIM_QMI_SIMIO_ASYNC_CALL */

  if(qcril_uim_extract_index(&app_index, &slot_index, session_type) == RIL_E_SUCCESS)
  {
    if(slot_index != slot)
    {
      QCRIL_LOG_DEBUG("session_type (0x%x) and slot (0x%x) do not match",
                      session_type, slot);
      return;
    }
  }

  memset(&service_status_params, 0, sizeof(qmi_uim_get_service_status_params_type));

  service_status_params.mask = QMI_UIM_CAPS_MASK_SERVICE_FDN;
  service_status_params.session_info.session_type = session_type;

/* Find the correct RILD instance */
#ifdef FEATURE_QCRIL_UIM_QMI_RPC_QCRIL
#ifdef FEATURE_QCRIL_DSDS
  if (qcril_arb_lookup_instance_id_from_session_type(session_type,
                                                     &instance_id) != E_SUCCESS)
  {
    QCRIL_LOG_ERROR( "%s", "qcril_instance_id lookup failed!\n");
  }
#else
  QCRIL_LOG_INFO( "%s\n", "Using QCRIL_DEFAULT_INSTANCE_ID");
#endif
#else
  instance_id = qmi_ril_get_process_instance_id();
#endif

  QCRIL_LOG_DEBUG("instance_id: %d, slot: %d", instance_id, slot);

  /* Allocate original request, it is freed in qmi_uim_callback */
  callback_request_ptr = qcril_uim_allocate_orig_request(instance_id,
                                                         modem_id,
                                                         token,
                                                         QCRIL_EVT_CM_UPDATE_FDN_STATUS,
                                                         session_type);
  if (callback_request_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "error allocating memory for callback_request_ptr!");
    return;
  }

  QCRIL_LOG_DEBUG("%s","Request FDN status from card");
#ifdef FEATURE_QCRIL_UIM_QMI_SIMIO_ASYNC_CALL
  if (qcril_uim_queue_send_request(QCRIL_UIM_REQUEST_GET_FDN,
                                   qcril_uim.qmi_handle,
                                   &service_status_params,
                                   qmi_uim_callback,
                                   (void*)callback_request_ptr) >= 0)
  {
    return;
  }
#else
  memset(&callback_params, 0, sizeof(qcril_uim_callback_params_type));

  if (qcril_qmi_uim_get_service_status(qcril_uim.qmi_handle,
                                       &service_status_params,
                                       NULL,
                                       (void*)callback_request_ptr,
                                       &callback_params.qmi_rsp_data) >= 0)
  {
    callback_params.orig_req_data = callback_request_ptr;
    qcril_uim_get_fdn_status_resp(&callback_params);
    return;
  }
#endif /* FEATURE_QCRIL_UIM_QMI_SIMIO_ASYNC_CALL */

  /* On error condition, clean up any original request if allocated */
  if (callback_request_ptr)
  {
    qcril_free(callback_request_ptr);
    callback_request_ptr = NULL;
  }

} /* qcril_uim_update_cm_fdn_status */


/*===========================================================================

  FUNCTION:  qcril_uim_card_state_timer_cb

===========================================================================*/
/*!
    @brief
    Timer callback for the threshold time that was specified. If this timer
    expires, it means that ATEL didnt call the get_sim_status after the unsol
    was sent. Since this is the max QCRIL UIM can wait, we need to fetch the
    latest card status from the modem & proceed as normal.

    @return
    None
*/
/*=========================================================================*/
static void qcril_uim_card_state_timer_cb
(
  void   * param_ptr
)
{
  int    qmi_err_code = 0;

  (void) param_ptr;

  /* Get card status to get the latest card info */
  QCRIL_LOG_INFO("%s", "card state check timer expired");

  /* Clean up timer info before returning */
  qcril_uim_card_state_check.timer_id = 0;

  /* Get card status to get the latest status */
  qmi_err_code = qcril_qmi_uim_get_card_status(qcril_uim.qmi_handle,
                                               qmi_uim_card_init_callback,
                                               NULL,
                                               NULL);
  if (qmi_err_code != QMI_NO_ERR)
  {
    QCRIL_LOG_ERROR( "Get card status failed, qmi_err_code: 0x%x\n", qmi_err_code);
  }
} /* qcril_uim_card_state_timer_cb */


/*===========================================================================

  FUNCTION:  qcril_uim_skip_card_indication

===========================================================================*/
/*!
    @brief
    This function checks the card state transition from/to error/absent and
    present. If the new state is:
    * If new status is Card Error or absent, we setup a timed callback
    * If the next transition is card present, we check if the timer is still
      running (below the threshold) Timer is running if ATEL has not read
      the status or it hasnt expired. If so, we skip processing that indication.
      The idea is that we want to make sure that ATEL get a chance to get the
      card error/absent status within the reasonable threshold that we set of
      500 msecs. When the timer expires or soon after the card error/absent is
      read by ATEL, we issue a qmi get card status & send the UNSOL to ATEL.
      The side effect of this approach is that potentially QCRIL could have stale
      data for a max time period of 500 msecs.

    @return
    TRUE - if indication needs to be skipped
    FALSE - if indication needs to be stored
*/
/*=========================================================================*/
static boolean qcril_uim_skip_card_indication
(
  const qmi_uim_card_status_type * old_status_ptr,
  const qmi_uim_card_status_type * new_status_ptr,
  uint8                            slot
)
{
  /* Sanity checks */
  if ((old_status_ptr == NULL) ||
      (new_status_ptr == NULL) ||
      (slot >= QMI_UIM_MAX_CARD_COUNT))
  {
    return FALSE;
  }

  /* If card state is same and time is running, we need to skip this indication.
     Upon timer expiration, new card status is retrieved */
  if (old_status_ptr->card[slot].card_state == new_status_ptr->card[slot].card_state)
  {
    if (qcril_uim_card_state_check.timer_id != 0)
    {
      return TRUE;
    }
    return FALSE;
  }

  /* We are interested only in transition from error/absent to present & vice versa.
     Nothing needed for any other transitions, e.g. - unknown to error/absent/present */
  if ((new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ERROR ||
       new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ABSENT) &&
      (old_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_PRESENT))
  {
    /* For card present to error/absent transition, we need to setup timer to
       ensure that ATEL has a chance to retrieve card error status before the
       card present indication is received from modem */
    if (qcril_uim_card_state_check.timer_id == 0)
    {
      int timer_ret = -1;

      QCRIL_LOG_INFO("%s", "Setting up card state check timer");
      timer_ret = qcril_setup_timed_callback(qmi_ril_get_process_instance_id(),
                                             QCRIL_DEFAULT_MODEM_ID,
                                             qcril_uim_card_state_timer_cb,
                                             &qcril_uim_card_state_check.state_check_timer,
                                             &qcril_uim_card_state_check.timer_id);
      if (timer_ret != 0)
      {
        QCRIL_LOG_ERROR("Timer setup failed, timer_ret: 0x%x ", timer_ret);
        qcril_uim_card_state_check.timer_id = 0;
      }
    }
  }
  else if ((new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_PRESENT) &&
           (old_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ERROR ||
            old_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ABSENT))
  {
    /* For card error/absent to present transition, check if timer is running.
       If timer is running, it means there was no get sim status request from
       ATEL and this IND should be skipped for this transition */
    if (qcril_uim_card_state_check.timer_id != 0)
    {
      return TRUE;
    }
  }
  return FALSE;
} /* qcril_uim_skip_card_indication */


/*===========================================================================

  FUNCTION:  qcril_mmgsdi_has_card_status_changed

===========================================================================*/
/*!
    @brief
    Based on the indication received, this function checks what part of card
    status has changed and returns accordingly.

    @return
    TRUE - if changed
    FALSE - if not changed
*/
/*=========================================================================*/
static boolean qcril_uim_has_card_status_changed
(
  const qmi_uim_card_status_type * card_status_ptr,
  const qmi_uim_card_status_type * status_change_ind_ptr,
  uint8                            slot
)
{
  int i = 0;

  /* Sanity checks */
  if ((card_status_ptr == NULL) || (status_change_ind_ptr == NULL) ||
      (slot >= QMI_UIM_MAX_CARD_COUNT))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return FALSE;
  }

  if (card_status_ptr->index_gw_pri_prov != status_change_ind_ptr->index_gw_pri_prov)
  {
    QCRIL_LOG_DEBUG("GW primary index changed: 0x%x -> 0x%x\n",
                    card_status_ptr->index_gw_pri_prov,
                    status_change_ind_ptr->index_gw_pri_prov);
    if ((slot == ((status_change_ind_ptr->index_gw_pri_prov >> 8) & 0xFF)) ||
        (slot == ((card_status_ptr->index_gw_pri_prov >> 8) & 0xFF)))
    {
      return TRUE;
    }
  }

  if (card_status_ptr->index_1x_pri_prov != status_change_ind_ptr->index_1x_pri_prov)
  {
    QCRIL_LOG_DEBUG("1X primary index changed: 0x%x -> 0x%x\n",
                    card_status_ptr->index_1x_pri_prov,
                    status_change_ind_ptr->index_1x_pri_prov);
    if ((slot == ((status_change_ind_ptr->index_1x_pri_prov >> 8) & 0xFF)) ||
        (slot == ((card_status_ptr->index_1x_pri_prov >> 8) & 0xFF)))
    {
      return TRUE;
    }
  }

  if (card_status_ptr->index_gw_sec_prov != status_change_ind_ptr->index_gw_sec_prov)
  {
    QCRIL_LOG_DEBUG("GW secondary index changed: 0x%x -> 0x%x\n",
                    card_status_ptr->index_gw_sec_prov,
                    status_change_ind_ptr->index_gw_sec_prov);
    if ((slot == ((status_change_ind_ptr->index_gw_sec_prov >> 8) & 0xFF)) ||
        (slot == ((card_status_ptr->index_gw_sec_prov >> 8) & 0xFF)))
    {
      return TRUE;
    }
  }

  if (card_status_ptr->index_1x_sec_prov != status_change_ind_ptr->index_1x_sec_prov)
  {
    QCRIL_LOG_DEBUG("1X secondary index changed: 0x%x -> 0x%x\n",
                    card_status_ptr->index_1x_sec_prov,
                    status_change_ind_ptr->index_1x_sec_prov);
    if ((slot == ((status_change_ind_ptr->index_1x_sec_prov >> 8) & 0xFF)) ||
        (slot == ((card_status_ptr->index_1x_sec_prov >> 8) & 0xFF)))
    {
      return TRUE;
    }
  }

  if (status_change_ind_ptr->card_status_type == QMI_UIM_EXTENDED_CARD_STATUS_TYPE &&
      card_status_ptr->index_gw_ter_prov != status_change_ind_ptr->index_gw_ter_prov)
  {
    QCRIL_LOG_DEBUG("GW tertiary index changed: 0x%x -> 0x%x\n",
                    card_status_ptr->index_gw_ter_prov,
                    status_change_ind_ptr->index_gw_ter_prov);
    if ((slot == ((status_change_ind_ptr->index_gw_ter_prov >> 8) & 0xFF)) ||
        (slot == ((card_status_ptr->index_gw_ter_prov >> 8) & 0xFF)))
    {
      return TRUE;
    }
  }

  if (status_change_ind_ptr->card_status_type == QMI_UIM_EXTENDED_CARD_STATUS_TYPE &&
      card_status_ptr->index_1x_ter_prov != status_change_ind_ptr->index_1x_ter_prov)
  {
    QCRIL_LOG_DEBUG("1X tertiary index changed: 0x%x -> 0x%x\n",
                    card_status_ptr->index_1x_ter_prov,
                    status_change_ind_ptr->index_1x_ter_prov);
    if ((slot == ((status_change_ind_ptr->index_1x_ter_prov >> 8) & 0xFF)) ||
        (slot == ((card_status_ptr->index_1x_ter_prov >> 8) & 0xFF)))
    {
      return TRUE;
    }
  }

  if (card_status_ptr->card[slot].card_state != status_change_ind_ptr->card[slot].card_state)
  {
    QCRIL_LOG_DEBUG("card state changed: 0x%x -> 0x%x\n",
                    card_status_ptr->card[slot].card_state,
                    status_change_ind_ptr->card[slot].card_state);
    return TRUE;
  }

  if ((card_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ERROR) &&
      (card_status_ptr->card[slot].card_error != status_change_ind_ptr->card[slot].card_error))
  {
    QCRIL_LOG_DEBUG("card error changed: 0x%x -> 0x%x\n",
                    card_status_ptr->card[slot].card_error,
                    status_change_ind_ptr->card[slot].card_error);
    return TRUE;
  }

  if (card_status_ptr->card[slot].upin_state != status_change_ind_ptr->card[slot].upin_state)
  {
    QCRIL_LOG_DEBUG("UPIN state changed: 0x%x -> 0x%x\n",
                    card_status_ptr->card[slot].upin_state,
                    status_change_ind_ptr->card[slot].upin_state);
    return TRUE;
  }

  if (card_status_ptr->card[slot].upin_num_retries != status_change_ind_ptr->card[slot].upin_num_retries)
  {
    QCRIL_LOG_DEBUG("UPIN retries changed: 0x%x -> 0x%x\n",
                    card_status_ptr->card[slot].upin_num_retries,
                    status_change_ind_ptr->card[slot].upin_num_retries);
    return TRUE;
  }

  if (card_status_ptr->card[slot].upuk_num_retries != status_change_ind_ptr->card[slot].upuk_num_retries)
  {
    QCRIL_LOG_DEBUG("UPUK retries changed: 0x%x -> 0x%x\n",
                    card_status_ptr->card[slot].upuk_num_retries,
                    status_change_ind_ptr->card[slot].upuk_num_retries);
    return TRUE;
  }

  if (card_status_ptr->card[slot].num_app != status_change_ind_ptr->card[slot].num_app)
  {
    QCRIL_LOG_DEBUG("Number of applications changed: 0x%x -> 0x%x\n",
                    card_status_ptr->card[slot].num_app,
                    status_change_ind_ptr->card[slot].num_app);
    return TRUE;
  }

  for (i = 0; i < status_change_ind_ptr->card[slot].num_app &&
              i < QMI_UIM_MAX_APP_PER_CARD_COUNT; i++)
  {
    if (card_status_ptr->card[slot].application[i].app_type !=
        status_change_ind_ptr->card[slot].application[i].app_type)
    {
      QCRIL_LOG_DEBUG("App type changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].app_type,
                      status_change_ind_ptr->card[slot].application[i].app_type);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].app_state !=
        status_change_ind_ptr->card[slot].application[i].app_state)
    {
      QCRIL_LOG_DEBUG("App state changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].app_state,
                      status_change_ind_ptr->card[slot].application[i].app_state);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].perso_state !=
        status_change_ind_ptr->card[slot].application[i].perso_state)
    {
      QCRIL_LOG_DEBUG("Perso state changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].perso_state,
                      status_change_ind_ptr->card[slot].application[i].perso_state);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].perso_feature !=
        status_change_ind_ptr->card[slot].application[i].perso_feature)
    {
      QCRIL_LOG_DEBUG("Perso feature changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].perso_feature,
                      status_change_ind_ptr->card[slot].application[i].perso_feature);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].perso_retries !=
        status_change_ind_ptr->card[slot].application[i].perso_retries)
    {
      QCRIL_LOG_DEBUG("Perso retries changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].perso_retries,
                      status_change_ind_ptr->card[slot].application[i].perso_retries);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].perso_unblock_retries !=
        status_change_ind_ptr->card[slot].application[i].perso_unblock_retries)
    {
      QCRIL_LOG_DEBUG("Perso unblock retries changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].perso_unblock_retries,
                      status_change_ind_ptr->card[slot].application[i].perso_unblock_retries);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].aid_len !=
        status_change_ind_ptr->card[slot].application[i].aid_len)
    {
      QCRIL_LOG_DEBUG("App AID len changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].aid_len,
                      status_change_ind_ptr->card[slot].application[i].aid_len);
      return TRUE;
    }

    if (status_change_ind_ptr->card[slot].application[i].aid_len <= QMI_UIM_MAX_AID_LEN &&
        memcmp(card_status_ptr->card[slot].application[i].aid_value,
               status_change_ind_ptr->card[slot].application[i].aid_value,
               status_change_ind_ptr->card[slot].application[i].aid_len) != 0)
    {
      QCRIL_LOG_DEBUG("%s", "App AID value changed\n");
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].univ_pin !=
        status_change_ind_ptr->card[slot].application[i].univ_pin)
    {
      QCRIL_LOG_DEBUG("Upin flag changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].univ_pin,
                      status_change_ind_ptr->card[slot].application[i].univ_pin);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].pin1_state !=
        status_change_ind_ptr->card[slot].application[i].pin1_state)
    {
      QCRIL_LOG_DEBUG("PIN1 changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].pin1_state,
                      status_change_ind_ptr->card[slot].application[i].pin1_state);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].pin1_num_retries !=
        status_change_ind_ptr->card[slot].application[i].pin1_num_retries)
    {
      QCRIL_LOG_DEBUG("PIN1 retries changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].pin1_num_retries,
                      status_change_ind_ptr->card[slot].application[i].pin1_num_retries);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].puk1_num_retries !=
        status_change_ind_ptr->card[slot].application[i].puk1_num_retries)
    {
      QCRIL_LOG_DEBUG("PUK1 retries changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].puk1_num_retries,
                      status_change_ind_ptr->card[slot].application[i].puk1_num_retries);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].pin2_state !=
        status_change_ind_ptr->card[slot].application[i].pin2_state)
    {
      QCRIL_LOG_DEBUG("PIN2 changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].pin2_state,
                      status_change_ind_ptr->card[slot].application[i].pin2_state);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].pin2_num_retries !=
        status_change_ind_ptr->card[slot].application[i].pin2_num_retries)
    {
      QCRIL_LOG_DEBUG("PIN2 retries changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].pin2_num_retries,
                      status_change_ind_ptr->card[slot].application[i].pin2_num_retries);
      return TRUE;
    }

    if (card_status_ptr->card[slot].application[i].puk2_num_retries !=
        status_change_ind_ptr->card[slot].application[i].puk2_num_retries)
    {
      QCRIL_LOG_DEBUG("PUK2 retries changed: 0x%x -> 0x%x\n",
                      card_status_ptr->card[slot].application[i].puk2_num_retries,
                      status_change_ind_ptr->card[slot].application[i].puk2_num_retries);
      return TRUE;
    }
  }

  QCRIL_LOG_DEBUG("%s", "No card change\n");

  return FALSE;
} /* qcril_uim_has_card_status_changed */


/*===========================================================================

  FUNCTION:  qcril_uim_handle_card_state_change

===========================================================================*/
/*!
    @brief


    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_handle_card_state_change
(
  qcril_instance_id_e_type         instance_id,
  qcril_modem_id_e_type            modem_id,
  uint8                            slot,
  const qmi_uim_card_status_type * old_status_ptr,
  const qmi_uim_card_status_type * new_status_ptr,
  qcril_request_return_type      * const ret_ptr /*!< Output parameter */
)
{
  qcril_sim_state_e_type      new_sim_state     = QCRIL_SIM_STATE_CARD_ERROR;
  qcril_scws_slot_enum_type   scws_slot_id_type = QCRIL_SCWS_SLOT_1;
  qcril_card_status_e_type    qcril_card_state  = QCRIL_CARD_STATUS_UP;
  uint8                       instance_slot     = qmi_ril_get_sim_slot();

  if ((old_status_ptr == NULL) ||
      (new_status_ptr == NULL) ||
      (ret_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s","Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  QCRIL_LOG_DEBUG("Card status: 0x%x -> 0x%x\n",
                  old_status_ptr->card[slot].card_state,
                  new_status_ptr->card[slot].card_state);

  /* clean up cached LPA profiles */
  if (instance_slot == slot)
  {
    qcril_uim_lpa_cleanup_cached_iccids();

    SecureElementhandleCardStateChange(new_status_ptr->card[slot].card_state);
  }

  qcril_uim_sap_process_card_status(new_status_ptr->card[slot].card_state,
                                    new_status_ptr->card[slot].card_error,
                                    slot);

  if (new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_PRESENT)
  {

#ifndef QMI_RIL_UTF
    uint8 iccid_len = QCRIL_UIM_ICCID_LEN;
    uint8 iccid_data[QCRIL_UIM_ICCID_LEN];

    memset(iccid_data, 0x00, sizeof(iccid_data));
#endif /* QMI_RIL_UTF */

    if (instance_slot == slot)
    {
      clock_gettime(CLOCK_MONOTONIC, &qcril_uim.card_inserted_time);
    }

    QCRIL_LOG_INFO("qcril_uim.card_inserted_time tv_sec:0x%x, tv_nsec:0x%x",
                        qcril_uim.card_inserted_time.tv_sec,
                        qcril_uim.card_inserted_time.tv_nsec);

    qcril_uim_update_cm_card_status(instance_id,
                                    modem_id,
                                    slot,
                                    qcril_card_state);
    qcril_uim_update_pbm_card_event(instance_id,
                                    modem_id,
                                    slot,
                                    QCRIL_EVT_PBM_CARD_INSERTED);

#ifndef QMI_RIL_UTF
    if(slot == qcril_uim_instance_id_to_slot(instance_id))
    {
      qcril_uim.card_iccid_info.iccid_len = 0;

      if((RIL_E_SUCCESS == qcril_uim_read_iccid(slot,
                                                iccid_data,
                                                &iccid_len)) &&
         (iccid_len > 0) &&
         (iccid_len <= QCRIL_UIM_ICCID_LEN))
      {
        /* Copy ICCID into card cache */
        memcpy(qcril_uim.card_iccid_info.iccid_data,
               iccid_data,
               iccid_len);
        qcril_uim.card_iccid_info.iccid_len = iccid_len;
      }
    }
#endif /* QMI_RIL_UTF */
  }

  if (new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ERROR ||
      new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ABSENT)
  {
    /* Send internal QCRIL events */
    qcril_uim_update_pbm_card_event(instance_id,
                                    modem_id,
                                    slot,
                                    QCRIL_EVT_PBM_CARD_ERROR);

    /* Based on card_error, update qcril_card_state */
    if (new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ERROR &&
        new_status_ptr->card[slot].card_error == QMI_UIM_CARD_ERROR_POWER_DOWN)
    {
      qcril_card_state = QCRIL_CARD_STATUS_DOWN;
    }
    else if (new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ABSENT ||
             (new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ERROR &&
              ((new_status_ptr->card[slot].card_error == QMI_UIM_CARD_ERROR_NO_ATR_RECEIVED) ||
               (new_status_ptr->card[slot].card_error == QMI_UIM_CARD_ERROR_UNKNOWN_REMOVED) ||
               (new_status_ptr->card[slot].card_error == QMI_UIM_CARD_ERROR_POWER_DOWN)) ))
    {
      qcril_card_state = QCRIL_CARD_STATUS_ABSENT;
    }
    else
    {
      qcril_card_state = QCRIL_CARD_STATUS_NOT_ACCESSIBLE;
    }

    qcril_uim_update_cm_card_status(instance_id,
                                    modem_id,
                                    slot,
                                    qcril_card_state);

    qcril_uim_update_gstk_card_event(instance_id,
                                     modem_id,
                                     slot);

    if (instance_slot == slot)
    {
      /* Cleanup refresh data */
      qcril_uim_cleanup_refresh_info();

      /* clear ARA-M delay cache info */
      qcril_uim_cleanup_ara_m_delay_cache_info();

      /* Clean up Long APDU info, if any */
      qcril_uim_cleanup_long_apdu_info();

      /* Clean up select response info, if any */
      qcril_uim_cleanup_select_response_info();

      /* Update the flag for silent PIN verification so that PIN1 can be silently
         verified after SAP is disconnected. */
      if (new_status_ptr->card[slot].card_error == QMI_UIM_CARD_ERROR_SAP_CONNECTED &&
          qmi_ril_is_feature_supported(QMI_RIL_FEATURE_SAP_SILENT_PIN_VERIFY))
      {
        qcril_uim.silent_pin_verify_reqd = TRUE;
      }

      /* Update SCWS agent */
      if (qcril_uim_convert_slot_id_to_scws_slot_id(slot, &scws_slot_id_type))
      {
        qcril_scws_card_error(scws_slot_id_type);
      }
    }

    if(slot == qcril_uim_instance_id_to_slot(instance_id))
    {
      /* Reset ICCID data and length */
      memset(&qcril_uim.card_iccid_info, 0x00, sizeof(qcril_uim.card_iccid_info));
    }

    /* Check to see if card_state is "Absent" */
    if (new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ABSENT ||
        (new_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ERROR &&
         ((new_status_ptr->card[slot].card_error == QMI_UIM_CARD_ERROR_NO_ATR_RECEIVED) ||
          (new_status_ptr->card[slot].card_error == QMI_UIM_CARD_ERROR_UNKNOWN_REMOVED) ||
          (new_status_ptr->card[slot].card_error == QMI_UIM_CARD_ERROR_POWER_DOWN)) ))
    {
      QCRIL_LOG_INFO("Setting QMI_UIM_CARD_STATE_ABSENT, card_error: %d, Slot: %d \n",
                     new_status_ptr->card[slot].card_error, slot);
      new_sim_state = QCRIL_SIM_STATE_ABSENT;

      /* Clear encrypted PIN1 data in cases of card error except when the card
         was powered down. QCRIL is supposed to retain the encrypted PIN1 data
         to silently verify PIN1 after airplane mode ON-OFF. */
      if (new_status_ptr->card[slot].card_error != QMI_UIM_CARD_ERROR_POWER_DOWN)
      {
        qcril_uim_clear_encrypted_pin_after_card_reset((uint8)slot);
      }

      /* Upon card power down, update the flag for silent PIN verification so
         that PIN1 can be silently verified after the card is powered up. */
      if (instance_slot == slot &&
          new_status_ptr->card[slot].card_error == QMI_UIM_CARD_ERROR_POWER_DOWN &&
          qmi_ril_is_feature_supported(QMI_RIL_FEATURE_SAP_SILENT_PIN_VERIFY))
      {
        qcril_uim.silent_pin_verify_reqd = TRUE;
      }

      /* Update internal QCRIL states if QCRIL_SIM_STATE_ABSENT on power up.
         Note that on DSDS config, this transition cannot be handled in this layer */
      if (!ril_to_uim_is_dsds_enabled() &&
          !ril_to_uim_is_tsts_enabled() &&
          (old_status_ptr->card[slot].card_state == QMI_UIM_CARD_STATE_ABSENT))
      {
        ret_ptr->pri_gw_sim_state_changed   = TRUE;
        ret_ptr->pri_cdma_sim_state_changed = TRUE;
        ret_ptr->sec_gw_sim_state_changed   = TRUE;
        ret_ptr->sec_cdma_sim_state_changed = TRUE;
        ret_ptr->ter_gw_sim_state_changed   = TRUE;
        ret_ptr->ter_cdma_sim_state_changed = TRUE;
        ret_ptr->next_pri_gw_sim_state      = new_sim_state;
        ret_ptr->next_pri_cdma_sim_state    = new_sim_state;
        ret_ptr->next_sec_gw_sim_state      = new_sim_state;
        ret_ptr->next_sec_cdma_sim_state    = new_sim_state;
        ret_ptr->next_ter_gw_sim_state      = new_sim_state;
        ret_ptr->next_ter_cdma_sim_state    = new_sim_state;
        return;
      }
    }

    /* Check which app type's state to update */
    if ((slot == ((old_status_ptr->index_gw_pri_prov >> 8) & 0xFF)) &&
        ((old_status_ptr->index_gw_pri_prov & 0xFF) < QMI_UIM_MAX_APP_PER_CARD_COUNT))
    {
      /* Means there was a GW session before the card error in this slot */
      ret_ptr->pri_gw_sim_state_changed = TRUE;
      ret_ptr->next_pri_gw_sim_state = new_sim_state;
      if ( ril_to_uim_is_dsds_enabled() || ril_to_uim_is_tsts_enabled())
      {
        /* Clear the prov related global data on card error */
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_PRI_GW_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
    }
    if ((slot == ((old_status_ptr->index_1x_pri_prov >> 8) & 0xFF)) &&
        ((old_status_ptr->index_1x_pri_prov & 0xFF) < QMI_UIM_MAX_APP_PER_CARD_COUNT))
    {
      /* Means there was a 1x session before the card error in this slot */
      ret_ptr->pri_cdma_sim_state_changed = TRUE;
      ret_ptr->next_pri_cdma_sim_state = new_sim_state;
      if ( ril_to_uim_is_dsds_enabled() || ril_to_uim_is_tsts_enabled())
      {
        /* Clear the prov related global data on card error */
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_PRI_1X_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
    }
    if ((slot == ((old_status_ptr->index_gw_sec_prov >> 8) & 0xFF)) &&
        ((old_status_ptr->index_gw_sec_prov & 0xFF) < QMI_UIM_MAX_APP_PER_CARD_COUNT))
    {
      /* Means there was a GW session before the card error in this slot */
      ret_ptr->sec_gw_sim_state_changed = TRUE;
      ret_ptr->next_sec_gw_sim_state = new_sim_state;
      if ( ril_to_uim_is_dsds_enabled() || ril_to_uim_is_tsts_enabled())
      {
        /* Clear the prov related global data on card error */
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_SEC_GW_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
    }
    if ((slot == ((old_status_ptr->index_1x_sec_prov >> 8) & 0xFF)) &&
        ((old_status_ptr->index_1x_sec_prov & 0xFF) < QMI_UIM_MAX_APP_PER_CARD_COUNT))
    {
      /* Means there was a 1x session before the card error in this slot */
      ret_ptr->sec_cdma_sim_state_changed = TRUE;
      ret_ptr->next_sec_cdma_sim_state = new_sim_state;
      if ( ril_to_uim_is_dsds_enabled() || ril_to_uim_is_tsts_enabled())
      {
        /* Clear the prov related global data on card error */
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_SEC_1X_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
    }
    if ((slot == ((old_status_ptr->index_gw_ter_prov >> 8) & 0xFF)) &&
        ((old_status_ptr->index_gw_ter_prov & 0xFF) < QMI_UIM_MAX_APP_PER_CARD_COUNT))
    {
      /* Means there was a GW session before the card error in this slot */
      ret_ptr->ter_gw_sim_state_changed = TRUE;
      ret_ptr->next_ter_gw_sim_state = new_sim_state;
      if ( ril_to_uim_is_tsts_enabled() )
      {
        /* Clear the prov related global data on card error */
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_TER_GW_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
    }
    if ((slot == ((old_status_ptr->index_1x_ter_prov >> 8) & 0xFF)) &&
        ((old_status_ptr->index_1x_ter_prov & 0xFF) < QMI_UIM_MAX_APP_PER_CARD_COUNT))
    {
      /* Means there was a 1x session before the card error in this slot */
      ret_ptr->ter_cdma_sim_state_changed = TRUE;
      ret_ptr->next_ter_cdma_sim_state = new_sim_state;
      if ( ril_to_uim_is_tsts_enabled() )
      {
        /* Clear the prov related global data on card error */
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_TER_1X_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
    }
  }
}/* qcril_uim_handle_card_state_change */


/*===========================================================================

  FUNCTION:  qcril_uim_is_prov_app

===========================================================================*/
/*!
    @brief


    @return
    None.
*/
/*=========================================================================*/
static boolean qcril_uim_is_prov_app
(
  unsigned short      index_prov_app,
  int                 i,
  int                 j
)
{
  if((i == ((index_prov_app >> 8) & 0xFF)) &&
     (j == (index_prov_app & 0xFF)))
  {
    return TRUE;
  }
  return FALSE;
} /* qcril_uim_is_prov_app */


/*===========================================================================

  FUNCTION:  qcril_uim_handle_app_state_change

===========================================================================*/
/*!
    @brief


    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_handle_app_state_change
(
  qcril_instance_id_e_type              instance_id,
  qcril_modem_id_e_type                 modem_id,
  const qmi_uim_card_status_type      * new_status_ptr,
  int                                   card_index,
  int                                   app_index,
  qcril_request_return_type           * const ret_ptr, /*!< Output parameter */
  uint8                                 slot
)
{
  boolean                   app_status_changed = FALSE;
  qcril_sim_state_e_type    new_sim_state      = QCRIL_SIM_STATE_ABSENT;
  qmi_uim_session_type      session_type       = QMI_UIM_SESSION_TYPE_PRI_GW_PROV;
  qcril_card_app_info_type  card_app_info;

  /* Sanity checks */
  if ((new_status_ptr == NULL) || (ret_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  qcril_uim_convert_app_state_to_qcril(&new_sim_state,
                                       new_status_ptr->card[card_index].application[app_index].app_state);

  /* This covers case where PIN1 is replaced by UPIN also */
  if(qcril_uim_is_prov_app(new_status_ptr->index_gw_pri_prov, card_index, app_index) &&
     (slot == ((new_status_ptr->index_gw_pri_prov >> 8) & 0xFF)))
  {
    app_status_changed = TRUE;
    ret_ptr->pri_gw_sim_state_changed = TRUE;
    ret_ptr->next_pri_gw_sim_state = new_sim_state;
    session_type = QMI_UIM_SESSION_TYPE_PRI_GW_PROV;
    if (qcril_uim.prov_session_info.session_state_gw_indexes[0] != QCRIL_UIM_PROV_SESSION_ACTIVATED)
    {
      qcril_uim_update_prov_session_type(session_type, QCRIL_UIM_PROV_SESSION_ACTIVATED);
    }
  }
  else if(qcril_uim_is_prov_app(new_status_ptr->index_1x_pri_prov, card_index, app_index) &&
          (slot == ((new_status_ptr->index_1x_pri_prov >> 8) & 0xFF)))
  {
    app_status_changed = TRUE;
    ret_ptr->pri_cdma_sim_state_changed = TRUE;
    ret_ptr->next_pri_cdma_sim_state = new_sim_state;
    session_type = QMI_UIM_SESSION_TYPE_PRI_1X_PROV;
    if (qcril_uim.prov_session_info.session_state_1x_indexes[0] != QCRIL_UIM_PROV_SESSION_ACTIVATED)
    {
      qcril_uim_update_prov_session_type(session_type, QCRIL_UIM_PROV_SESSION_ACTIVATED);
    }
  }
  else if(qcril_uim_is_prov_app(new_status_ptr->index_gw_sec_prov, card_index, app_index) &&
          (slot == ((new_status_ptr->index_gw_sec_prov >> 8) & 0xFF)))
  {
    app_status_changed = TRUE;
    ret_ptr->sec_gw_sim_state_changed = TRUE;
    ret_ptr->next_sec_gw_sim_state = new_sim_state;
    session_type = QMI_UIM_SESSION_TYPE_SEC_GW_PROV;
    if (qcril_uim.prov_session_info.session_state_gw_indexes[1] != QCRIL_UIM_PROV_SESSION_ACTIVATED)
    {
      qcril_uim_update_prov_session_type(session_type, QCRIL_UIM_PROV_SESSION_ACTIVATED);
    }
  }
  else if(qcril_uim_is_prov_app(new_status_ptr->index_1x_sec_prov, card_index, app_index) &&
          (slot == ((new_status_ptr->index_1x_sec_prov >> 8) & 0xFF)))
  {
    app_status_changed = TRUE;
    ret_ptr->sec_cdma_sim_state_changed = TRUE;
    ret_ptr->next_sec_cdma_sim_state = new_sim_state;
    session_type = QMI_UIM_SESSION_TYPE_SEC_1X_PROV;
    if (qcril_uim.prov_session_info.session_state_1x_indexes[1] != QCRIL_UIM_PROV_SESSION_ACTIVATED)
    {
      qcril_uim_update_prov_session_type(session_type, QCRIL_UIM_PROV_SESSION_ACTIVATED);
    }
  }
  else if(qcril_uim_is_prov_app(new_status_ptr->index_gw_ter_prov, card_index, app_index) &&
          (slot == ((new_status_ptr->index_gw_ter_prov >> 8) & 0xFF)))
  {
    app_status_changed = TRUE;
    ret_ptr->ter_gw_sim_state_changed = TRUE;
    ret_ptr->next_ter_gw_sim_state = new_sim_state;
    session_type = QMI_UIM_SESSION_TYPE_TER_GW_PROV;
    if (qcril_uim.prov_session_info.session_state_gw_indexes[2] != QCRIL_UIM_PROV_SESSION_ACTIVATED)
    {
      qcril_uim_update_prov_session_type(session_type, QCRIL_UIM_PROV_SESSION_ACTIVATED);
    }
  }
  else if(qcril_uim_is_prov_app(new_status_ptr->index_1x_ter_prov, card_index, app_index) &&
          (slot == ((new_status_ptr->index_1x_ter_prov >> 8) & 0xFF)))
  {
    app_status_changed = TRUE;
    ret_ptr->ter_cdma_sim_state_changed = TRUE;
    ret_ptr->next_ter_cdma_sim_state = new_sim_state;
    session_type = QMI_UIM_SESSION_TYPE_TER_1X_PROV;
    if (qcril_uim.prov_session_info.session_state_1x_indexes[2] != QCRIL_UIM_PROV_SESSION_ACTIVATED)
    {
      qcril_uim_update_prov_session_type(session_type, QCRIL_UIM_PROV_SESSION_ACTIVATED);
    }
  }

  /* Update ret_ptr if provision app status changes */
  if(app_status_changed)
  {
    /* PBM event is sent only for QCRIL_SIM_STATE_READY, nothing to send for any other cases
       got from the above conversion in qcril_uim_convert_app_state_to_qcril() */
    if(new_sim_state == QCRIL_SIM_STATE_READY)
    {
      qcril_uim_update_pbm_card_event(instance_id,
                                      modem_id,
                                      card_index,
                                      QCRIL_EVT_PBM_CARD_INIT_COMPLETED);

      qcril_uim_update_cm_fdn_status(modem_id, card_index, session_type);
    }
  }

  /* Send QCRIL_EVT_CM_CARD_APP_STATUS_CHANGE */
  memset(&card_app_info, 0x00, sizeof(card_app_info));
  card_app_info.slot      = card_index;
  card_app_info.app_type  = new_status_ptr->card[card_index].application[app_index].app_type;
  card_app_info.app_state = new_status_ptr->card[card_index].application[app_index].app_state;
  if (new_status_ptr->card[card_index].application[app_index].aid_len <= sizeof(card_app_info.aid_value))
  {
    card_app_info.aid_len = new_status_ptr->card[card_index].application[app_index].aid_len;
  }
  else
  {
    card_app_info.aid_len = sizeof(card_app_info.aid_value);
  }

  memcpy(card_app_info.aid_value,
         new_status_ptr->card[card_index].application[app_index].aid_value,
         card_app_info.aid_len);
  (void)qcril_event_queue(instance_id,
                          modem_id,
                          QCRIL_DATA_ON_STACK,
                          QCRIL_EVT_CM_CARD_APP_STATUS_CHANGED,
                          (void *)&card_app_info,
                          sizeof(card_app_info),
                          (RIL_Token)QCRIL_TOKEN_ID_INTERNAL);

} /* qcril_uim_handle_app_state_change */


/*===========================================================================

  FUNCTION:  qcril_uim_handle_perso_state_change

===========================================================================*/
/*!
    @brief


    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_handle_perso_state_change
(
  const qmi_uim_card_status_type   * new_status_ptr,
  int                                card_index,
  int                                app_index,
  qcril_request_return_type        * const ret_ptr /*!< Output parameter */
)
{
  qcril_sim_state_e_type      new_sim_state         = QCRIL_SIM_STATE_NOT_READY;
  RIL_PersoSubstate           new_perso_substate    = RIL_PERSOSUBSTATE_UNKNOWN;

  /* Sanity checks */
  if ((new_status_ptr == NULL) || (ret_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  /* Get the QCRIL sim state */
  qcril_uim_convert_perso_state_to_qcril(&new_sim_state,
                                         new_status_ptr->card[card_index].application[app_index].perso_state);

  /* Get the RIL perso substate */
  qcril_uim_convert_perso_state_all(&new_perso_substate,
                                    new_status_ptr->card[card_index].application[app_index].perso_state,
                                    new_status_ptr->card[card_index].application[app_index].perso_feature);

  /* Perso is tied to only the primary provisioning app */
  if(new_sim_state != QCRIL_SIM_STATE_NOT_READY)
  {
    if(qcril_uim_is_prov_app(new_status_ptr->index_gw_pri_prov, card_index, app_index))
    {
      ret_ptr->pri_gw_sim_state_changed = TRUE;
      ret_ptr->next_pri_gw_sim_state = new_sim_state;
    }
    else if(qcril_uim_is_prov_app(new_status_ptr->index_1x_pri_prov, card_index, app_index))
    {
      ret_ptr->pri_cdma_sim_state_changed = TRUE;
      ret_ptr->next_pri_cdma_sim_state = new_sim_state;
    }
    else if(qcril_uim_is_prov_app(new_status_ptr->index_gw_sec_prov, card_index, app_index))
    {
      ret_ptr->sec_gw_sim_state_changed = TRUE;
      ret_ptr->next_sec_gw_sim_state = new_sim_state;
    }
    else if(qcril_uim_is_prov_app(new_status_ptr->index_1x_sec_prov, card_index, app_index))
    {
      ret_ptr->sec_cdma_sim_state_changed = TRUE;
      ret_ptr->next_sec_cdma_sim_state = new_sim_state;
    }
    else if(qcril_uim_is_prov_app(new_status_ptr->index_gw_ter_prov, card_index, app_index))
    {
      ret_ptr->ter_gw_sim_state_changed = TRUE;
      ret_ptr->next_ter_gw_sim_state = new_sim_state;
    }
    else if(qcril_uim_is_prov_app(new_status_ptr->index_1x_ter_prov, card_index, app_index))
    {
      ret_ptr->ter_cdma_sim_state_changed = TRUE;
      ret_ptr->next_ter_cdma_sim_state = new_sim_state;
    }
  }
} /* qcril_uim_handle_perso_state_change */


/*===========================================================================

  FUNCTION:  qcril_uim_handle_prov_index_state_change

===========================================================================*/
/*!
    @brief


    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_handle_prov_index_state_change
(
  const qmi_uim_card_status_type   * old_status_ptr,
  const qmi_uim_card_status_type   * new_status_ptr
)
{
  /* Sanity checks */
  if ((old_status_ptr == NULL) || (new_status_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  if (!ril_to_uim_is_dsds_enabled() &&
      !ril_to_uim_is_tsts_enabled())
  {
    /* No change needed */
    return;
  }

  /* Clear the respective prov app's global session state */
  if ((old_status_ptr->index_gw_pri_prov != new_status_ptr->index_gw_pri_prov) &&
      (new_status_ptr->index_gw_pri_prov == QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE) &&
      (qcril_uim.prov_session_info.session_state_gw_indexes[0] != QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED))
  {
    /* Clear the prov related global data on card error */
    qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_PRI_GW_PROV,
                                       QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
  }

  if ((old_status_ptr->index_1x_pri_prov != new_status_ptr->index_1x_pri_prov) &&
      (new_status_ptr->index_1x_pri_prov == QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE) &&
      (qcril_uim.prov_session_info.session_state_1x_indexes[0] != QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED))
  {
    /* Clear the prov related global data on card error */
    qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_PRI_1X_PROV,
                                       QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
  }

  if ((old_status_ptr->index_gw_sec_prov != new_status_ptr->index_gw_sec_prov) &&
      (new_status_ptr->index_gw_sec_prov == QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE) &&
      (qcril_uim.prov_session_info.session_state_gw_indexes[1] != QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED))
  {
    /* Clear the prov related global data on card error */
    qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_SEC_GW_PROV,
                                       QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
  }

  if ((old_status_ptr->index_1x_sec_prov != new_status_ptr->index_1x_sec_prov) &&
      (new_status_ptr->index_1x_sec_prov == QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE) &&
      (qcril_uim.prov_session_info.session_state_1x_indexes[1] != QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED))
  {
    /* Clear the prov related global data on card error */
    qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_SEC_1X_PROV,
                                       QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
  }

  if ((old_status_ptr->index_gw_ter_prov != new_status_ptr->index_gw_ter_prov) &&
      (new_status_ptr->index_gw_ter_prov == QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE) &&
      (qcril_uim.prov_session_info.session_state_gw_indexes[2] != QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED))
  {
    /* Clear the prov related global data on card error */
    qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_TER_GW_PROV,
                                       QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
  }

  if ((old_status_ptr->index_1x_ter_prov != new_status_ptr->index_1x_ter_prov) &&
      (new_status_ptr->index_1x_ter_prov == QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE) &&
      (qcril_uim.prov_session_info.session_state_1x_indexes[2] != QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED))
  {
    /* Clear the prov related global data on card error */
    qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_TER_1X_PROV,
                                       QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
  }
} /* qcril_uim_handle_prov_index_state_change */


/*===========================================================================

  FUNCTION:  qcril_uim_send_card_status_events

===========================================================================*/
/*!
    @brief
    Based on the indication received, this function checks only specific
    fields for the  card status change, updates the new card status to global,
    updates ret_ptr and sends card events to necessary internal QCRIL clients.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_send_card_status_events
(
  qcril_instance_id_e_type         instance_id,
  qcril_modem_id_e_type            modem_id,
  const qmi_uim_card_status_type * old_status_ptr,
  const qmi_uim_card_status_type * new_status_ptr,
  const qmi_uim_bool_type        * card_status_invalid_ptr,
  qcril_request_return_type      * const ret_ptr, /*!< Output parameter */
  uint8                            slot
)
{
  uint8                   i                   = 0;
  uint8                   j                   = 0;

  /* Sanity checks */
  if ((old_status_ptr == NULL) || (new_status_ptr == NULL) || (ret_ptr == NULL) ||
      (card_status_invalid_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  /* This check covers a corner case where modem might deactivate only the provisioning
     session indices. In such cases, we need to update the session state for DSDS */
  qcril_uim_handle_prov_index_state_change(old_status_ptr,
                                           new_status_ptr);

  for (i = 0; i < new_status_ptr->num_slots && i < QMI_UIM_MAX_CARD_COUNT; i++)
  {
    if (card_status_invalid_ptr[i] == QMI_UIM_TRUE)
    {
      continue;
    }

    if ((old_status_ptr->card[i].card_state != new_status_ptr->card[i].card_state) ||
        ((new_status_ptr->card[i].card_state == QMI_UIM_CARD_STATE_ERROR) &&
         (old_status_ptr->card[i].card_error != new_status_ptr->card[i].card_error)))
    {
      qcril_uim_handle_card_state_change(instance_id,
                                         modem_id,
                                         i,
                                         old_status_ptr,
                                         new_status_ptr,
                                         ret_ptr);
    }

    for (j = 0; j < new_status_ptr->card[i].num_app &&
                j < QMI_UIM_MAX_APP_PER_CARD_COUNT; j++)
    {
      if (old_status_ptr->card[i].application[j].app_state !=
          new_status_ptr->card[i].application[j].app_state)
      {
        qcril_uim_handle_app_state_change(instance_id,
                                          modem_id,
                                          new_status_ptr,
                                          i,
                                          j,
                                          ret_ptr,
                                          slot);
      }

      if (new_status_ptr->card[i].application[j].app_state == QMI_UIM_APP_STATE_PERSO)
      {
        if ((old_status_ptr->card[i].application[j].perso_state !=
             new_status_ptr->card[i].application[j].perso_state) ||
            (old_status_ptr->card[i].application[j].perso_feature !=
             new_status_ptr->card[i].application[j].perso_feature))
        {
          qcril_uim_handle_perso_state_change(new_status_ptr, i, j, ret_ptr);
        }
      }
    }
  }
} /* qcril_uim_send_card_status_events */


/*===========================================================================

  FUNCTION:  qcril_uim_copy_card_status

===========================================================================*/
/*!
    @brief
    Copies the new card status to the global.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_copy_card_status
(
  qmi_uim_card_status_type          * out_ptr,
  const qmi_uim_card_status_type    * in_ptr,
  uint16                              size
)
{
  if ((out_ptr == NULL) || (in_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  if (in_ptr->card_status_type == QMI_UIM_EXTENDED_CARD_STATUS_TYPE)
  {
    memcpy(out_ptr, in_ptr, size);
  }
  else
  {
    /* In case of legacy card status indication, copy only primary and
       secondary provisioning session indices and info for up to 2 cards. */
    uint8 i = 0;
    uint8 j = 0;

    out_ptr->index_gw_pri_prov = in_ptr->index_gw_pri_prov;
    out_ptr->index_1x_pri_prov = in_ptr->index_1x_pri_prov;
    out_ptr->index_gw_sec_prov = in_ptr->index_gw_sec_prov;
    out_ptr->index_1x_sec_prov = in_ptr->index_1x_sec_prov;
    /* Ensure that the new num_slots doesn't overwrite a value previously
       updated by extended card status indication.  */
    if (out_ptr->num_slots <= QMI_UIM_LEGACY_MAX_CARD_COUNT ||
        in_ptr->num_slots != QMI_UIM_LEGACY_MAX_CARD_COUNT)
    {
      out_ptr->num_slots = in_ptr->num_slots;
    }
    for (i = 0; i < in_ptr->num_slots && i < QMI_UIM_MAX_CARD_COUNT; i++)
    {
      out_ptr->card[i].card_state = in_ptr->card[i].card_state;
      out_ptr->card[i].upin_state = in_ptr->card[i].upin_state;
      out_ptr->card[i].upin_num_retries = in_ptr->card[i].upin_num_retries;
      out_ptr->card[i].upuk_num_retries = in_ptr->card[i].upuk_num_retries;
      out_ptr->card[i].card_error = in_ptr->card[i].card_error;
      /* Ensure that the new num_app doesn't overwrite a value previously
         updated by extended card status indication. */
      if (out_ptr->card[i].num_app <= QMI_UIM_LEGACY_MAX_APP_PER_CARD_COUNT ||
          in_ptr->card[i].num_app != QMI_UIM_LEGACY_MAX_APP_PER_CARD_COUNT)
      {
        out_ptr->card[i].num_app = in_ptr->card[i].num_app;
      }
      for (j = 0; (j < in_ptr->card[i].num_app) &&
                  (j < QMI_UIM_MAX_APP_PER_CARD_COUNT); j++)
      {
        out_ptr->card[i].application[j].app_type =
          in_ptr->card[i].application[j].app_type;
        out_ptr->card[i].application[j].app_state =
          in_ptr->card[i].application[j].app_state;
        out_ptr->card[i].application[j].perso_state =
          in_ptr->card[i].application[j].perso_state;
        out_ptr->card[i].application[j].perso_feature =
          in_ptr->card[i].application[j].perso_feature;
        out_ptr->card[i].application[j].perso_retries =
          in_ptr->card[i].application[j].perso_retries;
        out_ptr->card[i].application[j].perso_unblock_retries =
          in_ptr->card[i].application[j].perso_unblock_retries;
        out_ptr->card[i].application[j].aid_len = MIN(QMI_UIM_MAX_AID_LEN,
                                    in_ptr->card[i].application[j].aid_len);
        memcpy(out_ptr->card[i].application[j].aid_value,
               in_ptr->card[i].application[j].aid_value,
               out_ptr->card[i].application[j].aid_len);
        out_ptr->card[i].application[j].univ_pin =
          in_ptr->card[i].application[j].univ_pin;
        out_ptr->card[i].application[j].pin1_state =
          in_ptr->card[i].application[j].pin1_state;
        out_ptr->card[i].application[j].pin1_num_retries =
          in_ptr->card[i].application[j].pin1_num_retries;
        out_ptr->card[i].application[j].puk1_num_retries =
          in_ptr->card[i].application[j].puk1_num_retries;
        out_ptr->card[i].application[j].pin2_state =
          in_ptr->card[i].application[j].pin2_state;
        out_ptr->card[i].application[j].pin2_num_retries =
          in_ptr->card[i].application[j].pin2_num_retries;
        out_ptr->card[i].application[j].puk2_num_retries =
          in_ptr->card[i].application[j].puk2_num_retries;
      }
    }
  }
} /* qcril_uim_copy_card_status */


/*===========================================================================

  FUNCTION:  qcril_uim_init_card_status

===========================================================================*/
/*!
    @brief
    Initializes the global card status structure.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_init_card_status
(
  qmi_uim_card_status_type  * card_status_ptr
)
{
  int i = 0;
  int j = 0;

  if (card_status_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  memset(card_status_ptr, 0, sizeof(qmi_uim_card_status_type));

  /* Initialize non-zero init params */
  card_status_ptr->index_gw_pri_prov = QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE;
  card_status_ptr->index_1x_pri_prov = QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE;
  card_status_ptr->index_gw_sec_prov = QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE;
  card_status_ptr->index_1x_sec_prov = QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE;
  card_status_ptr->index_gw_ter_prov = QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE;
  card_status_ptr->index_1x_ter_prov = QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE;

  for (i=0; i<QMI_UIM_MAX_CARD_COUNT ; i++)
  {
    card_status_ptr->card[i].card_state = QMI_UIM_CARD_STATE_UNKNOWN;
    card_status_ptr->card[i].upin_state = QMI_UIM_PIN_STATE_UNKNOWN;
    card_status_ptr->card[i].card_error = QMI_UIM_CARD_ERROR_UNKNOWN;
    for (j=0; j<QMI_UIM_MAX_APP_PER_CARD_COUNT; j++)
    {
      card_status_ptr->card[i].application[j].app_type = QMI_UIM_APP_UNKNOWN;
      card_status_ptr->card[i].application[j].app_state = QMI_UIM_APP_STATE_UNKNOWN;
      card_status_ptr->card[i].application[j].perso_state = QMI_UIM_PERSO_STATE_UNKNOWN;
      card_status_ptr->card[i].application[j].perso_feature = QMI_UIM_PERSO_FEATURE_STATUS_UNKNOWN;
      card_status_ptr->card[i].application[j].pin1_state = QMI_UIM_PIN_STATE_UNKNOWN;
      card_status_ptr->card[i].application[j].pin2_state = QMI_UIM_PIN_STATE_UNKNOWN;
    }
  }
} /* qcril_uim_init_card_status */


/*===========================================================================

  FUNCTION:  qcril_uim_print_card_status

===========================================================================*/
/*!
    @brief
    Prints relevant card status information from the global structure.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_print_card_status
(
  const qmi_uim_card_status_type  * card_status_ptr
)
{
  int i = 0;
  int j = 0;
  int k = 0;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  if (card_status_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  /* Todo Add verbose strings for these types */
  QCRIL_LOG_DEBUG("Index of GW primary prov: 0X%x \n", card_status_ptr->index_gw_pri_prov);
  QCRIL_LOG_DEBUG("Index of 1X primary prov: 0X%x \n", card_status_ptr->index_1x_pri_prov);
  QCRIL_LOG_DEBUG("Index of GW secondary prov: 0X%x \n", card_status_ptr->index_gw_sec_prov);
  QCRIL_LOG_DEBUG("Index of 1X secondary prov: 0X%x \n", card_status_ptr->index_1x_sec_prov);
  QCRIL_LOG_DEBUG("Index of GW tertiary prov: 0X%x \n", card_status_ptr->index_gw_ter_prov);
  QCRIL_LOG_DEBUG("Index of 1X tertiary prov: 0X%x \n", card_status_ptr->index_1x_ter_prov);

  QCRIL_LOG_DEBUG("Number of slots: %d \n", card_status_ptr->num_slots);

  for (i = 0; i < card_status_ptr->num_slots && i < QMI_UIM_MAX_CARD_COUNT; i++)
  {
    QCRIL_LOG_DEBUG("card[%d].card_state: %d \n", i, card_status_ptr->card[i].card_state);
    QCRIL_LOG_DEBUG("card[%d].upin_state: %d \n", i, card_status_ptr->card[i].upin_state);
    QCRIL_LOG_DEBUG("card[%d].upin_num_retries: %d \n", i, card_status_ptr->card[i].upin_num_retries);
    QCRIL_LOG_DEBUG("card[%d].upuk_num_retries: %d \n", i, card_status_ptr->card[i].upuk_num_retries);
    QCRIL_LOG_DEBUG("card[%d].card_error: %d \n", i, card_status_ptr->card[i].card_error);

    QCRIL_LOG_DEBUG("Number of apps: %d \n", card_status_ptr->card[i].num_app);

    for (j = 0; j < card_status_ptr->card[i].num_app &&
                j < QMI_UIM_MAX_APP_PER_CARD_COUNT; j++)
    {
      QCRIL_LOG_DEBUG("card[%d].application[%d].app_type: %d \n", i, j,
                      card_status_ptr->card[i].application[j].app_type);
      QCRIL_LOG_DEBUG("card[%d].application[%d].app_state: %d \n", i, j,
                      card_status_ptr->card[i].application[j].app_state);
      QCRIL_LOG_DEBUG("card[%d].application[%d].perso_state: %d \n", i, j,
                      card_status_ptr->card[i].application[j].perso_state);
      QCRIL_LOG_DEBUG("card[%d].application[%d].perso_feature: %d \n", i, j,
                      card_status_ptr->card[i].application[j].perso_feature);
      QCRIL_LOG_DEBUG("card[%d].application[%d].perso_retries: %d \n", i, j,
                      card_status_ptr->card[i].application[j].perso_retries);
      QCRIL_LOG_DEBUG("card[%d].application[%d].perso_unblock_retries: %d \n", i, j,
                      card_status_ptr->card[i].application[j].perso_unblock_retries);
      QCRIL_LOG_DEBUG("card[%d].application[%d].aid_len: %d \n", i, j,
                      card_status_ptr->card[i].application[j].aid_len);
      QCRIL_LOG_DEBUG("card[%d].application[%d].aid_value: ", i);
      for (k = 0; k < QMI_UIM_MAX_AID_LEN &&
                  k < card_status_ptr->card[i].application[j].aid_len ; k++)
      {
        QCRIL_LOG_DEBUG(" 0X%x", card_status_ptr->card[i].application[j].aid_value[k]);
      }
      QCRIL_LOG_DEBUG("\ncard[%d].application[%d].univ_pin: %d \n", i, j,
                      card_status_ptr->card[i].application[j].univ_pin);
      QCRIL_LOG_DEBUG("card[%d].application[%d].pin1_state: %d \n", i, j,
                      card_status_ptr->card[i].application[j].pin1_state);
      QCRIL_LOG_DEBUG("card[%d].application[%d].pin1_num_retries: %d \n", i, j,
                      card_status_ptr->card[i].application[j].pin1_num_retries);
      QCRIL_LOG_DEBUG("card[%d].application[%d].puk1_num_retries: %d \n", i, j,
                      card_status_ptr->card[i].application[j].puk1_num_retries);
      QCRIL_LOG_DEBUG("card[%d].application[%d].pin2_state: %d \n", i, j,
                      card_status_ptr->card[i].application[j].pin2_state);
      QCRIL_LOG_DEBUG("card[%d].application[%d].pin2_num_retries: %d \n", i, j,
                      card_status_ptr->card[i].application[j].pin2_num_retries);
      QCRIL_LOG_DEBUG("card[%d].application[%d].puk2_num_retries: %d \n", i, j,
                      card_status_ptr->card[i].application[j].puk2_num_retries);
    }
  }
} /* qcril_uim_print_card_status */


/*=========================================================================

  FUNCTION:  qcril_uim_voltage_supply_resp

===========================================================================*/
/*!
    @brief
    Processes the response for voltage supply command.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_voltage_supply_resp
(
  const qcril_uim_callback_params_type * const params_ptr
)
{
  RIL_Token                         token;
  RIL_Errno                         ril_err;
  qcril_uim_original_request_type * original_request_ptr = NULL;

  /* Sanity checks */
  if (params_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  /* Retrieve original request */
  original_request_ptr = (qcril_uim_original_request_type*)params_ptr->orig_req_data;
  if (original_request_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  ril_err = qcril_uim_convert_err_value(params_ptr->qmi_rsp_data.qmi_err_code);
  token   = original_request_ptr->token;

  QCRIL_LOG_DEBUG( "qcril_uim_voltage_supply_resp: token=%d qmi_err_code=%d \n",
                    qcril_log_get_token_id(token),
                    params_ptr->qmi_rsp_data.qmi_err_code );

  /* Send the response */
  qcril_uim_response(original_request_ptr->instance_id,
                     token,
                     ril_err,
                     NULL,
                     0,
                     TRUE,
                     NULL);

  /* Free memory allocated originally in the request */
  qcril_free(original_request_ptr);
  original_request_ptr = NULL;
} /* qcril_uim_voltage_supply_resp */


/*=========================================================================

  FUNCTION:  qcril_uim_get_atr_resp

===========================================================================*/
/*!
    @brief
    Processes the response for get ATR command.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_get_atr_resp
(
  const qcril_uim_callback_params_type * const params_ptr
)
{
  RIL_Token                         token;
  RIL_Errno                         ril_err;
  int                               atr_len = 0;
  char                            * atr_ptr = NULL;
  qcril_uim_original_request_type * original_request_ptr = NULL;

  /* Sanity checks */
  if (params_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  /* Retrieve original request */
  original_request_ptr = (qcril_uim_original_request_type*)params_ptr->orig_req_data;
  if (original_request_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  ril_err = qcril_uim_convert_err_value(params_ptr->qmi_rsp_data.qmi_err_code);
  token   = original_request_ptr->token;

  QCRIL_LOG_DEBUG( "qcril_uim_get_atr_resp: token=%d qmi_err_code=%d \n",
                    qcril_log_get_token_id(token),
                    params_ptr->qmi_rsp_data.qmi_err_code );

  if (ril_err == RIL_E_SUCCESS)
  {
    /* Convert the raw ATR bytes to a null terminated ASCII string
     The function qcril_uim_alloc_bin_to_hexstring will perform the allocation & data conversion */
     atr_ptr = qcril_uim_alloc_bin_to_hexstring(
                 (const uint8*)params_ptr->qmi_rsp_data.rsp_data.get_atr_rsp.atr_response.data_ptr,
                 (uint16)params_ptr->qmi_rsp_data.rsp_data.get_atr_rsp.atr_response.data_len);

     /* Update the length */
     if (atr_ptr != NULL)
     {
       atr_len = strlen(atr_ptr);
     }
     else
     {
       ril_err = QCRIL_UIM_RIL_E_NO_MEMORY;
     }
  }

  QCRIL_LOG_DEBUG( "ATR Response: %s\n", atr_ptr != NULL ? atr_ptr : "NULL");

#if defined(RIL_REQUEST_SIM_QUERY_ATR) || defined (RIL_REQUEST_SIM_GET_ATR)
  qcril_uim_response(original_request_ptr->instance_id,
                     token,
                     ril_err,
                     atr_ptr,
                     atr_len,
                     TRUE,
                     NULL);
#else
  qtiGetAtrResponse(token, ril_err, atr_ptr, atr_len);
#endif /* #if defined(RIL_REQUEST_SIM_QUERY_ATR) || defined (RIL_REQUEST_SIM_GET_ATR) */

  if (atr_ptr)
  {
    qcril_free(atr_ptr);
    atr_ptr = NULL;
  }

  /* Free memory allocated originally in the request */
  qcril_free(original_request_ptr);
  original_request_ptr = NULL;

} /* qcril_uim_get_atr_resp */


/*=========================================================================

  FUNCTION:  qcril_uim_power_resp

===========================================================================*/
/*!
    @brief
    Processes the response for power up/down command.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_power_resp
(
  const qcril_uim_callback_params_type * const params_ptr
)
{
  RIL_Token                         token;
  RIL_Errno                         ril_err;
  qcril_uim_original_request_type * original_request_ptr = NULL;

  /* Sanity checks */
  if (params_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  /* Retrieve original request */
  original_request_ptr = (qcril_uim_original_request_type*)params_ptr->orig_req_data;
  if (original_request_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    return;
  }

  /* Need to respond only to the power request sent via OEMHook */
  if (original_request_ptr->request_id != QCRIL_EVT_HOOK_UICC_POWER_REQ &&
      original_request_ptr->request_id != QCRIL_EVT_HOOK_SLOT_CARD_POWER_REQ &&
      original_request_ptr->request_id != RIL_REQUEST_SET_SIM_CARD_POWER)
  {
    return;
  }

  ril_err = qcril_uim_convert_err_value(params_ptr->qmi_rsp_data.qmi_err_code);
  token   = original_request_ptr->token;

  QCRIL_LOG_DEBUG( "qcril_uim_power_resp: token=%d qmi_err_code=%d \n",
                    qcril_log_get_token_id(token),
                    params_ptr->qmi_rsp_data.qmi_err_code );

  /* Send the response, Actual response will be in payload */
  if (original_request_ptr->request_id == QCRIL_EVT_HOOK_SLOT_CARD_POWER_REQ)
  {
    RIL_SlotCardPowerResp  power_rsp;

    power_rsp.slot_id = original_request_ptr->data.slot_id;
    power_rsp.ril_err = ril_err;
    qcril_uim_response(original_request_ptr->instance_id,
                       token,
                       RIL_E_SUCCESS,
                       &power_rsp,
                       sizeof(RIL_SlotCardPowerResp),
                       TRUE,
                       NULL);
  }
  else
  {
    qcril_uim_response(original_request_ptr->instance_id,
                       token,
                       ril_err,
                       NULL,
                       0,
                       TRUE,
                       NULL);
  }

  /* Free memory allocated originally in the request */
  qcril_free(original_request_ptr);
  original_request_ptr = NULL;
} /* qcril_uim_power_resp */


/*=========================================================================

  FUNCTION:  qcril_uim_change_prov_session_callback

===========================================================================*/
/*!
    @brief
    Callback for the change provisioning session. It sends an event to
    QCRIL(CM) regarding the status of the activate/deactivate command along
    with the session type.

    @return
    None
*/
/*=========================================================================*/
static void qcril_uim_change_prov_session_callback
(
  qmi_uim_rsp_data_type        * rsp_data,
  void                         * user_data
)
{
  qcril_instance_id_e_type                        instance_id;
  qcril_modem_id_e_type                           modem_id;
  qcril_provision_info_type                       provision_info;
  qcril_uim_original_request_type               * original_request_ptr = NULL;
  qcril_uim_prov_session_state_type               session_state;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  /* Sanity checks */
  if ((rsp_data == NULL) || (user_data == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  memset(&provision_info, 0x00, sizeof(qcril_provision_info_type));

  /* Retrieve the original request */
  original_request_ptr = (qcril_uim_original_request_type*)user_data;
  instance_id = original_request_ptr->instance_id;
  modem_id = original_request_ptr->modem_id;

  /* Verify certain parameters */
  if ((instance_id      >= QCRIL_MAX_INSTANCE_ID) ||
      (modem_id         >= QCRIL_MAX_MODEM_ID) ||
      (rsp_data->rsp_id != QMI_UIM_SRVC_CHANGE_PROV_SESSION_RSP_MSG))
  {
    QCRIL_LOG_ERROR("Invalid values, instance_id: 0x%x, modem_id: 0x%x, rsp_id: 0x%x, ",
                     instance_id, modem_id, rsp_data->rsp_id);
    QCRIL_ASSERT(0);
    return;
  }

  /* Proceed to check pending requests in the queue, if any */
  qcril_uim_queue_complete_request();

  QCRIL_LOG_DEBUG( "qcril_uim_change_prov_session_callback: instance_id=%d, modem_id =%d, event=%d, qmi_err_code=%d \n",
                   instance_id,
                   modem_id,
                   original_request_ptr->data.qcril_evt,
                   rsp_data->qmi_err_code);

  /* Update info being sent to QCRIL_CM */
  provision_info.status = (rsp_data->qmi_err_code == 0) ? QCRIL_PROVISION_STATUS_SUCCESS : QCRIL_PROVISION_STATUS_FAILURE;
  provision_info.err_code = qcril_uim_convert_err_value(rsp_data->qmi_err_code);
  provision_info.session_type = original_request_ptr->session_type;

  /* Change the global session type appropriately */
  if (original_request_ptr->data.qcril_evt == QCRIL_EVT_CM_ACTIVATE_PROVISION_STATUS)
  {
    if (provision_info.status == QCRIL_PROVISION_STATUS_SUCCESS)
    {
      qcril_uim_update_prov_session_type(provision_info.session_type,
                                         QCRIL_UIM_PROV_SESSION_ACTIVATED);
    }
    else if (provision_info.status == QCRIL_PROVISION_STATUS_FAILURE)
    {
      qcril_uim_update_prov_session_type(provision_info.session_type,
                                         QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
    }
    else
    {
      QCRIL_LOG_ERROR( "Invalid provision_info status mapping: %d\n",
                       provision_info.status )
    }
  }
  else if (original_request_ptr->data.qcril_evt == QCRIL_EVT_CM_DEACTIVATE_PROVISION_STATUS)
  {
    if (provision_info.status == QCRIL_PROVISION_STATUS_SUCCESS)
    {
      qcril_uim_update_prov_session_type(provision_info.session_type,
                                         QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
    }
    else if (provision_info.status == QCRIL_PROVISION_STATUS_FAILURE)
    {
      if((qcril_uim_get_prov_session_state(provision_info.session_type,
                                           &session_state) == QMI_NO_ERR) &&
         (session_state == QCRIL_UIM_PROV_SESSION_DEACTIVATION_IN_PROGESS))
      {
        qcril_uim_update_prov_session_type(provision_info.session_type,
                                           QCRIL_UIM_PROV_SESSION_ACTIVATED);
      }
    }
    else
    {
      QCRIL_LOG_ERROR( "Invalid provision_info status mapping: %d\n",
                       provision_info.status )
    }
  }

  /* Send response to QCRIL_CM */
  if (qcril_process_event(instance_id,
                          modem_id,
                          original_request_ptr->data.qcril_evt,
                          (void *)&provision_info,
                          sizeof(provision_info),
                          (RIL_Token)QCRIL_TOKEN_ID_INTERNAL ) != E_SUCCESS )
  {
    QCRIL_LOG_ERROR( "RID %d MID %d Processing subcription evt failed!\n", instance_id, modem_id )
  }

  /* Free memory allocated originally in the request */
  qcril_free(original_request_ptr);
  original_request_ptr = NULL;
} /* qcril_uim_change_prov_session_callback */


/*===========================================================================

  FUNCTION:  qcril_uim_process_status_change_ind

===========================================================================*/
/*!
    @brief
    Main function for processing QMI card status changed indication. Based
    on the indication received, if needed, it updates the global card status,
    ret_ptr and sends card events internal to QCRIL (CM & PBM).

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_process_status_change_ind
(
  const qcril_uim_indication_params_type  * ind_param_ptr,
  qcril_request_return_type               * const ret_ptr /*!< Output parameter */
)
{
  qcril_unsol_resp_params_type      unsol_resp;
  qmi_uim_card_status_type        * status_change_ind_ptr = NULL;
  uint8                             instance_id           = 0;
  RIL_Errno                         verify_status         = QCRIL_UIM_RIL_E_INTERNAL_ERR;
  qmi_uim_bool_type               * card_status_invalid   = NULL;
  uint8                             slot                  = 0;
  boolean                           allow_indication      = FALSE;
  uint8                             i                     = 0;
  boolean                           status_changed        = FALSE;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  if ((ind_param_ptr == NULL) || (ret_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid inputs, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  instance_id           = ind_param_ptr->instance_id;
  status_change_ind_ptr = (qmi_uim_card_status_type*)&ind_param_ptr->ind_data.status_change_ind;
  if (status_change_ind_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, NULL status_change_ind_ptr");
    QCRIL_ASSERT(0);
    return;
  }

  card_status_invalid = (qmi_uim_bool_type *)ind_param_ptr->ind_data.status_change_ind.card_status_validity.card_status_invalid;

  QCRIL_LOG_INFO( "curr modem state 0x%x, curr pri GW sim state 0x%x, curr pri CDMA sim state 0x%x, curr sec GW sim state 0x%x, curr sec CDMA sim state 0x%x, curr ter GW sim state 0x%x, curr ter CDMA sim state 0x%x\n",
                  ret_ptr->next_modem_state,
                  ret_ptr->next_pri_gw_sim_state,
                  ret_ptr->next_pri_cdma_sim_state,
                  ret_ptr->next_sec_gw_sim_state,
                  ret_ptr->next_sec_cdma_sim_state,
                  ret_ptr->next_ter_gw_sim_state,
                  ret_ptr->next_ter_cdma_sim_state);

  slot = qcril_uim_instance_id_to_slot(instance_id);
  if (slot >= QMI_UIM_MAX_CARD_COUNT)
  {
    QCRIL_LOG_ERROR("Invalid slot 0x%x", slot);
    return;
  }

#ifndef QMI_RIL_UTF
  /* Below event is not supported in RIL UT */
  /* Card state change notification is sent with oem hook message with slot id and
     card state. The oem hook message will be sent only when there is card state
     change not for the APP state change. One unsol message for each slot, same
     indication will come on other slots also, check only slot 0 */
  if (slot == 0)
  {
    for (i = 0; i < status_change_ind_ptr->num_slots && i < QMI_UIM_MAX_CARD_COUNT; i++)
    {
      /* Determine change in card status only if it is not invalid */
      if ((card_status_invalid == NULL || !card_status_invalid[i]) &&
          qcril_uim.card_status.card[i].card_state != status_change_ind_ptr->card[i].card_state &&
          status_change_ind_ptr->card[i].card_state != QMI_UIM_CARD_STATE_UNKNOWN)
      {
        RIL_SlotCardState  card_state;

        QCRIL_LOG_INFO("QCRIL_EVT_HOOK_UNSOL_CARD_STATE_CHANGE_IND");
        card_state.slot_id = i;
        card_state.card_state = (RIL_CardState) status_change_ind_ptr->card[i].card_state;
        qcril_hook_unsol_response(QCRIL_DEFAULT_INSTANCE_ID,
                                  (int) QCRIL_EVT_HOOK_UNSOL_CARD_STATE_CHANGE_IND,
                                  (char *)&card_state,
                                  sizeof(card_state));
      }
    }
  }

  /* send card status change indication internally event to QCRIL */
  (void)qcril_event_queue(ind_param_ptr->instance_id,
                          ind_param_ptr->modem_id,
                          QCRIL_DATA_ON_STACK,
                          QCRIL_EVT_CM_CARD_STATUS_CHANGE_IND,
                          NULL,
                          0,
                          (RIL_Token)QCRIL_TOKEN_ID_INTERNAL);
#endif /* QMI_RIL_UTF */

  /* Determine change in card status only if it is not invalid */
  if (card_status_invalid == NULL || !card_status_invalid[slot])
  {
    boolean skip_copy = FALSE;

    status_changed = qcril_uim_has_card_status_changed(&qcril_uim.card_status,
                                                       status_change_ind_ptr,
                                                       slot);

    if (status_changed)
    {
      /* Check the card state transition to see if we need to skip the card
         status copy & posting of internal events & UNSOL to ATEL */
      skip_copy = qcril_uim_skip_card_indication(&qcril_uim.card_status,
                                                 status_change_ind_ptr,
                                                 slot);
      if (skip_copy)
      {
        status_changed = FALSE;
        QCRIL_LOG_INFO("Skipping UNSOL for slot_id 0x%x", slot);
      }
      else
      {
        qcril_uim_send_card_status_events(ind_param_ptr->instance_id,
                                          ind_param_ptr->modem_id,
                                          &qcril_uim.card_status,
                                          status_change_ind_ptr,
                                          card_status_invalid,
                                          ret_ptr,
                                          slot);
      }
    }
    /* Note on the card status mutex: We are currently limiting this mutex enforcement
       to only this modem indication and the request for card status from FW. */
    QCRIL_MUTEX_LOCK(&qcril_uim_card_status_mutex, "qcril_uim_card_status_mutex");

    /* Update global card status */
    if (!skip_copy)
    {
      qcril_uim_copy_card_status(&qcril_uim.card_status,
                                 status_change_ind_ptr,
                                 sizeof(qmi_uim_card_status_type));
    }

    QCRIL_MUTEX_UNLOCK(&qcril_uim_card_status_mutex, "qcril_uim_card_status_mutex");
  }
  else
  {
    QCRIL_LOG_ERROR("card status invalid for slot 0x%x", slot);
  }

  if (status_changed)
  {
    uint8 session_slot  = 0;
    uint8 session_index = 0;

    if(qcril_uim.silent_pin_verify_reqd &&
       qcril_uim.card_status.card[slot].card_state == QMI_UIM_CARD_STATE_PRESENT)
    {
      verify_status = qcril_uim_try_pin1_verification(slot);

      /* For Multi-SIM manual app selection the client must be notified when the card
         is present to manually select the application. This notification should only
         be sent once, when all provisioning applications on the card are still in
         detected state and the provisioning indices are not set. */
      if (ril_to_uim_is_dsds_enabled() || ril_to_uim_is_tsts_enabled())
      {
        for (i = 0; i < QMI_UIM_MAX_APP_PER_CARD_COUNT; i++)
        {
          /* If any provisioning application on the card has made it past app state detected,
             then the indication to notify the client to manually select has already been sent. */
          if (qcril_uim.card_status.card[slot].application[i].app_state > QMI_UIM_APP_STATE_DETECTED &&
              qcril_uim_is_prov_app_type(qcril_uim.card_status.card[slot].application[i].app_type))
          {
            allow_indication = FALSE;
            break;
          }

          if (qcril_uim.card_status.card[slot].application[i].app_state == QMI_UIM_APP_STATE_DETECTED &&
              qcril_uim_is_prov_app_type(qcril_uim.card_status.card[slot].application[i].app_type) &&
              !qcril_uim_is_prov_app_activated(slot,
                                               qcril_uim.card_status.card[slot].application[i].app_type,
                                               qcril_uim.card_status.card[slot].application[i].aid_len,
                                               qcril_uim.card_status.card[slot].application[i].aid_value))
          {
            allow_indication = TRUE;
          }
        }
      }
    }
    qcril_uim_check_silent_pin_verify_in_progress(slot);

    /* Register for refresh if the slot derived from RIL instance and the
       slot derived from session index matches */
    if((qcril_uim_extract_index(&session_index,
                                &session_slot,
                                QMI_UIM_SESSION_TYPE_PRI_GW_PROV) == RIL_E_SUCCESS) &&
       (slot == session_slot))
    {
      qcril_uim_refresh_register(QMI_UIM_SESSION_TYPE_PRI_GW_PROV);
    }

    if((qcril_uim_extract_index(&session_index,
                                &session_slot,
                                QMI_UIM_SESSION_TYPE_PRI_1X_PROV) == RIL_E_SUCCESS) &&
       (slot == session_slot))
    {
      qcril_uim_refresh_register(QMI_UIM_SESSION_TYPE_PRI_1X_PROV);
    }

#ifdef FEATURE_QCRIL_UIM_ISIM_REFRESH
    if(slot == 0)
    {
      qcril_uim_refresh_register_isim(QMI_UIM_SLOT_1);
    }
#endif /* FEATURE_QCRIL_UIM_ISIM_REFRESH */

#ifndef QMI_RIL_UTF
    qcril_uim_refresh_register_card_session(slot);
#endif /* QMI_RIL_UTF */

    if ( ril_to_uim_is_dsds_enabled() || ril_to_uim_is_tsts_enabled())
    {
      /* Register for refresh if the slot derived from RIL instance and the
         slot derived from session index matches */
      if((qcril_uim_extract_index(&session_index,
                                  &session_slot,
                                  QMI_UIM_SESSION_TYPE_SEC_GW_PROV) == RIL_E_SUCCESS) &&
         (slot == session_slot))
      {
        qcril_uim_refresh_register(QMI_UIM_SESSION_TYPE_SEC_GW_PROV);
      }

      if((qcril_uim_extract_index(&session_index,
                                  &session_slot,
                                  QMI_UIM_SESSION_TYPE_SEC_1X_PROV) == RIL_E_SUCCESS) &&
         (slot == session_slot))
      {
        qcril_uim_refresh_register(QMI_UIM_SESSION_TYPE_SEC_1X_PROV);
      }

#ifdef FEATURE_QCRIL_UIM_ISIM_REFRESH
      if(slot == 1)
      {
        qcril_uim_refresh_register_isim(QMI_UIM_SLOT_2);
      }
#endif /* FEATURE_QCRIL_UIM_ISIM_REFRESH */

      if (ril_to_uim_is_tsts_enabled())
      {
        /* Register for refresh if the slot derived from RIL instance and the
           slot derived from session index matches */
        if((qcril_uim_extract_index(&session_index,
                                    &session_slot,
                                    QMI_UIM_SESSION_TYPE_TER_GW_PROV) == RIL_E_SUCCESS) &&
           (slot == session_slot))
        {
          qcril_uim_refresh_register(QMI_UIM_SESSION_TYPE_TER_GW_PROV);
        }

        if((qcril_uim_extract_index(&session_index,
                                    &session_slot,
                                    QMI_UIM_SESSION_TYPE_TER_1X_PROV) == RIL_E_SUCCESS) &&
           (slot == session_slot))
        {
          qcril_uim_refresh_register(QMI_UIM_SESSION_TYPE_TER_1X_PROV);
        }

#ifdef FEATURE_QCRIL_UIM_ISIM_REFRESH
        if(slot == 2)
        {
          qcril_uim_refresh_register_isim(QMI_UIM_SLOT_3);
        }
#endif /* FEATURE_QCRIL_UIM_ISIM_REFRESH */
      }
    }

    if ((verify_status != RIL_E_SUCCESS &&
         qcril_uim.pin1_info[0].silent_verify_in_progress == FALSE &&
         qcril_uim.pin1_info[1].silent_verify_in_progress == FALSE) ||
         allow_indication )
    {
      /* Send unsolicited response to framework */
      qcril_default_unsol_resp_params(instance_id,
                                      RIL_UNSOL_RESPONSE_SIM_STATUS_CHANGED,
                                      &unsol_resp);
      qcril_send_unsol_response(&unsol_resp);
    }
  }

  qcril_uim_print_card_status(&qcril_uim.card_status);

  QCRIL_LOG_INFO( " new modem state 0x%x, new pri GW sim state 0x%x, new pri CDMA sim state 0x%x, new sec GW sim state 0x%x, new sec CDMA sim state 0x%x, new ter GW sim state 0x%x, new ter CDMA sim state 0x%x\n",
                  ret_ptr->next_modem_state,
                  ret_ptr->next_pri_gw_sim_state,
                  ret_ptr->next_pri_cdma_sim_state,
                  ret_ptr->next_sec_gw_sim_state,
                  ret_ptr->next_sec_cdma_sim_state,
                  ret_ptr->next_ter_gw_sim_state,
                  ret_ptr->next_ter_cdma_sim_state);

} /* qcril_uim_process_status_change_ind */


/*=========================================================================

  FUNCTION:  qcril_uim_process_change_subscription

===========================================================================*/
/*!
    @brief
    Processes the subscription activation/deactivation requests from QCRIL.
    called as a result of QCRIL_EVT_INTERNAL_MMGSDI_ACTIVATE_SUB or
    QCRIL_EVT_INTERNAL_MMGSDI_DEACTIVATE_SUB.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_process_change_subscription
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr /*!< Output parameter */
)
{
  qcril_instance_id_e_type                  instance_id;
  qcril_modem_id_e_type                     modem_id ;
  int                                       res       = 0;
  const qcril_uicc_subs_info_type         * ril_uicc_subs_info_ptr = NULL;
  qmi_uim_change_prov_session_params_type   change_session_params;
  qcril_provision_info_type                 provision_info;
  qcril_uim_prov_session_info_type          orig_session_info;
  qcril_evt_e_type                          prov_evt = QCRIL_EVT_NONE;
  qcril_uim_original_request_type         * original_request_ptr = NULL;

  /* Sanity checks */
  if ((params_ptr == NULL) ||
      (ret_ptr == NULL) ||
      (params_ptr->data == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  instance_id = params_ptr->instance_id;
  modem_id = params_ptr->modem_id;
  if ((instance_id >= QCRIL_MAX_INSTANCE_ID) ||
      (modem_id    >= QCRIL_MAX_MODEM_ID))
  {
    QCRIL_LOG_ERROR("Invalid values, instance_id: 0x%x, modem_id: 0x%x",
                     instance_id, modem_id);
    QCRIL_ASSERT(0);
    return;
  }

  memset(&change_session_params, 0,
         sizeof(qmi_uim_change_prov_session_params_type));
  memset(&provision_info, 0, sizeof(qcril_provision_info_type));
  memset(&orig_session_info, 0, sizeof(qcril_uim_prov_session_info_type));

  /* Cast input info */
  ril_uicc_subs_info_ptr = (const qcril_uicc_subs_info_type *)params_ptr->data;

  QCRIL_LOG_INFO( "qcril_uim_process_change_subscription: RID: 0x%x, MID:0x%x, slot: 0x%x, app_index: 0x%x, sub_type: 0x%x, act_status: 0x%x\n",
                  instance_id,
                  modem_id,
                  ril_uicc_subs_info_ptr->uicc_subs_info.slot,
                  ril_uicc_subs_info_ptr->uicc_subs_info.app_index,
                  (int)ril_uicc_subs_info_ptr->uicc_subs_info.sub_type,
                  (int)ril_uicc_subs_info_ptr->uicc_subs_info.act_status );

  /* Fill in the backup data */
  provision_info.status  = QCRIL_PROVISION_STATUS_FAILURE;
  if(params_ptr->event_id == QCRIL_EVT_INTERNAL_MMGSDI_ACTIVATE_SUBS)
  {
    prov_evt = QCRIL_EVT_CM_ACTIVATE_PROVISION_STATUS;
  }
  else if(params_ptr->event_id == QCRIL_EVT_INTERNAL_MMGSDI_DEACTIVATE_SUBS)
  {
    prov_evt = QCRIL_EVT_CM_DEACTIVATE_PROVISION_STATUS;
  }

  memcpy(&orig_session_info, &qcril_uim.prov_session_info,
         sizeof(qcril_uim_prov_session_info_type));

  /* Ignore requests if already activated/deactivated and send SUCCESS */
  if (qcril_uim_ignore_change_subscription(ril_uicc_subs_info_ptr,
                                           &change_session_params) == RIL_E_SUCCESS)
  {
    provision_info.err_code      = RIL_E_SUCCESS;
    provision_info.status        = QCRIL_PROVISION_STATUS_SUCCESS;
    provision_info.session_type  = change_session_params.session_type;
    goto send_resp;
  }

  /* Fill the aid, session type, activation type */
  provision_info.err_code = qcril_uim_fill_change_session_params(ril_uicc_subs_info_ptr,
                                                                 &change_session_params);
  if (provision_info.err_code != RIL_E_SUCCESS)
  {
    goto send_resp;
  }

  /* Allocate original request */
  original_request_ptr = qcril_uim_allocate_orig_request(params_ptr->instance_id,
                                                         params_ptr->modem_id,
                                                         (RIL_Token)params_ptr->t,
                                                         0,
                                                         change_session_params.session_type);
  if (original_request_ptr == NULL)
  {
    goto send_resp;
  }

  /* Update other parameters */
  original_request_ptr->data.qcril_evt  = prov_evt;

  /* Activation type */
  switch (ril_uicc_subs_info_ptr->uicc_subs_info.act_status)
  {
    case RIL_UICC_SUBSCRIPTION_ACTIVATE:
      change_session_params.activation_type = QMI_UIM_SESSION_ACTIVATE;
      break;
    case RIL_UICC_SUBSCRIPTION_DEACTIVATE:
      change_session_params.activation_type = QMI_UIM_SESSION_DEACTIVATE;
      break;
    default:
      /* Invalid activation type */
      QCRIL_LOG_ERROR( " Invalid activation type in RIL Request ID 0x%x\n",
                       ril_uicc_subs_info_ptr->uicc_subs_info.act_status);
      goto send_resp;
  }

  /* Provisioning session in progress, update QCRIL(CM) on the session type */
  if ( prov_evt == QCRIL_EVT_CM_ACTIVATE_PROVISION_STATUS )
  {
    provision_info.status  = QCRIL_PROVISION_STATUS_IN_PROGRESS;
    provision_info.session_type = change_session_params.session_type;
    (void)qcril_event_queue( params_ptr->instance_id, params_ptr->modem_id, QCRIL_DATA_ON_STACK,
                             prov_evt, (void *) &provision_info, sizeof( qcril_provision_info_type ),
                             (RIL_Token) QCRIL_TOKEN_ID_INTERNAL );
  }

  QCRIL_LOG_QMI( params_ptr->modem_id, "qmi_uim_service", "change provisioning session" );
  res = qcril_uim_queue_send_request(QCRIL_UIM_REQUEST_CHANGE_PROV_SESSION,
                                     qcril_uim.qmi_handle,
                                     &change_session_params,
                                     qcril_uim_change_prov_session_callback,
                                     (void*)original_request_ptr);
  if (res >= 0)
  {
    return;
  }

send_resp:
  /* revert our global provisioning app session state */
  memcpy(&qcril_uim.prov_session_info, &orig_session_info,
         sizeof(qcril_uim_prov_session_info_type));

  /* session_type must be ignored on failure */
  if (qcril_process_event(params_ptr->instance_id,
                          params_ptr->modem_id,
                          prov_evt,
                          (void *)&provision_info,
                          sizeof(provision_info),
                          (RIL_Token)QCRIL_TOKEN_ID_INTERNAL ) != E_SUCCESS )
  {
    QCRIL_LOG_ERROR( "%s\n", "change provisioning session failed!" );
  }

  if (original_request_ptr)
  {
    qcril_free(original_request_ptr);
    original_request_ptr = NULL;
  }
} /* qcril_uim_process_change_subscription */


/*=========================================================================

  FUNCTION:  qcril_uim_process_power_down

===========================================================================*/
/*!
    @brief
    Process the power down request.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_process_power_down
(
  qcril_instance_id_e_type          instance_id,
  qcril_modem_id_e_type             modem_id,
  int                               slot
)
{
  qmi_uim_power_down_params_type    params;
  qcril_card_status_e_type          new_card_status = QCRIL_CARD_STATUS_POWERDOWN_FAILED;
  qcril_uim_original_request_type * original_request_ptr = NULL;

  /* Sanity Check */
  if ((slot < 0) ||
      (slot >= QMI_UIM_MAX_CARD_COUNT))
  {
    QCRIL_LOG_ERROR("Invalid value, slot: 0x%x", slot);
    QCRIL_ASSERT(0);
    return;
  }

  memset(&params, 0, sizeof(qmi_uim_power_down_params_type));
  switch ( slot )
  {
    case 0:
      params.slot = QMI_UIM_SLOT_1;
      break;

    case 1:
      params.slot = QMI_UIM_SLOT_2;
      break;

    case 2:
      params.slot = QMI_UIM_SLOT_3;
      break;

    default:
      QCRIL_LOG_ERROR( "Invalid slot %d\n", slot )
      goto send_pdown_error;
  }

  /* Allocate original request */
  original_request_ptr = qcril_uim_allocate_orig_request(instance_id,
                                                         modem_id,
                                                         NULL,
                                                         0,
                                                         0);
  if (original_request_ptr != NULL)
  {
    if (qcril_uim_queue_send_request(QCRIL_UIM_REQUEST_POWER_DOWN,
                                     qcril_uim.qmi_handle,
                                     &params,
                                     qmi_uim_callback,
                                     (void*)original_request_ptr) >= 0)
    {
      return;
    }
  }

send_pdown_error:
  /* Card PowerDown Failure, tell QCRIL that Card Mode PowerDown failure */
  if ( qcril_process_event(instance_id,
                           modem_id,
                           QCRIL_EVT_CM_CARD_STATUS_UPDATED,
                           (void *)&new_card_status,
                           sizeof(new_card_status),
                           (RIL_Token)QCRIL_TOKEN_ID_INTERNAL ) != E_SUCCESS )
  {
    QCRIL_LOG_ERROR( "%s\n", "CM_CARD_STATUS_UPDATED Failed!" )
  }
} /* qcril_uim_process_power_down */


/*=========================================================================

  FUNCTION:  qcril_uim_process_power_up

===========================================================================*/
/*!
    @brief
    Process the power up request.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_process_power_up
(
  qcril_instance_id_e_type          instance_id,
  qcril_modem_id_e_type             modem_id,
  int                               slot
)
{
  qmi_uim_power_up_params_type      params;
  qcril_card_status_e_type          new_card_status = QCRIL_CARD_STATUS_POWERUP_FAILED;
  qcril_uim_original_request_type * original_request_ptr = NULL;

  /* Sanity Check */
  if ((slot < 0) ||
      (slot >= QMI_UIM_MAX_CARD_COUNT))
  {
    QCRIL_LOG_ERROR("Invalid value, slot: 0x%x", slot);
    QCRIL_ASSERT(0);
    return;
  }

  memset(&params, 0, sizeof(qmi_uim_power_up_params_type));
  switch ( slot )
  {
    case 0:
      params.slot = QMI_UIM_SLOT_1;
      break;

    case 1:
      params.slot = QMI_UIM_SLOT_2;
      break;

    case 2:
      params.slot = QMI_UIM_SLOT_3;
      break;

    default:
      QCRIL_LOG_ERROR( "Invalid slot %d\n", slot )
      goto send_pup_error;
  }

  /* Allocate original request */
  original_request_ptr = qcril_uim_allocate_orig_request(instance_id,
                                                         modem_id,
                                                         NULL,
                                                         0,
                                                         0);
  if (original_request_ptr != NULL)
  {
    if (qcril_uim_queue_send_request(QCRIL_UIM_REQUEST_POWER_UP,
                                     qcril_uim.qmi_handle,
                                     &params,
                                     qmi_uim_callback,
                                     (void*)original_request_ptr) >= 0)
    {
      return;
    }
  }

send_pup_error:
  /* Card PowerDown Failure, tell QCRIL that Card Mode PowerDown failure */
  if ( qcril_process_event(instance_id,
                           modem_id,
                           QCRIL_EVT_CM_CARD_STATUS_UPDATED,
                           (void *)&new_card_status,
                           sizeof(new_card_status),
                           (RIL_Token)QCRIL_TOKEN_ID_INTERNAL ) != E_SUCCESS )
  {
    QCRIL_LOG_ERROR( "%s\n", "CM_CARD_STATUS_UPDATED Failed!" )
  }
} /* qcril_uim_process_power_up */


/*=========================================================================

  FUNCTION:  qcril_uim_process_get_atr

===========================================================================*/
/*!
    @brief
     Handles RIL_REQUEST_SIM_GET_ATR and QCRIL_EVT_HOOK_SLOT_GET_ATR_REQ
     request from QCRIL.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_request_get_atr
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr /*!< Output parameter */
)
{
  qcril_modem_id_e_type             modem_id             = QCRIL_MAX_MODEM_ID - 1;
  int                             * in_ptr       = NULL;
  qcril_uim_original_request_type * original_request_ptr = NULL;
  qmi_uim_get_atr_params_type       get_atr_params;
  RIL_Errno                         err                  = QCRIL_UIM_RIL_E_INTERNAL_ERR;

  /* Sanity check */
  if ((params_ptr == NULL) ||
      (ret_ptr    == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    return;
  }

  /* Add entry to ReqList */
  QCRIL_UIM_ADD_ENTRY_TO_REQUEST_LIST(params_ptr);

  in_ptr = (int*)params_ptr->data;

  /* Return with error if AID was not provided */
  if (in_ptr == NULL)
  {
    QCRIL_LOG_ERROR( "%s", "NULL input pointer slot \n");
    if(params_ptr->event_id == QCRIL_EVT_HOOK_SLOT_GET_ATR_REQ)
    {
      QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
      return;
    }
    else
    {
      err = QCRIL_UIM_RIL_E_INTERNAL_ERR;
      goto get_atr_error;
    }
  }

  QCRIL_LOG_INFO( "qcril_uim_process_get_atr(slot: %d)\n", *in_ptr);

  memset(&get_atr_params, 0, sizeof(qmi_uim_get_atr_params_type));

  switch ( *in_ptr )
  {
    case 0:
      get_atr_params.slot = QMI_UIM_SLOT_1;
      break;

    case 1:
      get_atr_params.slot = QMI_UIM_SLOT_2;
      break;

    case 2:
      get_atr_params.slot = QMI_UIM_SLOT_3;
      break;

    default:
      QCRIL_LOG_ERROR( "Invalid slot %d\n", *in_ptr )
      err = QCRIL_UIM_RIL_E_INVALID_ARGUMENTS;
      goto get_atr_error;
  }

  /* Allocate original request */
  original_request_ptr = qcril_uim_allocate_orig_request(params_ptr->instance_id,
                                                         modem_id,
                                                         params_ptr->t,
                                                         params_ptr->event_id,
                                                         0);

  if (original_request_ptr != NULL)
  {
    if (qcril_uim_queue_send_request(QCRIL_UIM_REQUEST_GET_ATR,
                                     qcril_uim.qmi_handle,
                                     &get_atr_params,
                                     qmi_uim_callback,
                                     (void*)original_request_ptr) >= 0)
    {
      return;
    }
    else
    {
      err = QCRIL_UIM_RIL_E_MODEM_ERR;
    }
  }
  else
  {
    err = QCRIL_UIM_RIL_E_NO_MEMORY;
  }

get_atr_error:
#if defined(RIL_REQUEST_SIM_QUERY_ATR) || defined (RIL_REQUEST_SIM_GET_ATR)
  qcril_uim_response(params_ptr->instance_id, params_ptr->t, err,
         NULL, 0, TRUE, "error in qcril_uim_request_get_atr");
#else
  qtiGetAtrResponse(params_ptr->t, err, NULL, 0);
#endif /* #if defined(RIL_REQUEST_SIM_QUERY_ATR) || defined (RIL_REQUEST_SIM_GET_ATR) */


  /* Clean up any original request if allocated */
  if (original_request_ptr)
  {
    qcril_free(original_request_ptr);
    original_request_ptr = NULL;
  }
} /* qcril_uim_request_get_atr */

/*===========================================================================

                               QCRIL INTERFACE FUNCTIONS

===========================================================================*/

/*===========================================================================

  FUNCTION:  qcril_uim_request_get_sim_status

===========================================================================*/
/*!
    @brief
    Handles RIL_REQUEST_GET_SIM_STATUS request from the framework

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_request_get_sim_status
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr /*!< Output parameter */
)
{
  RIL_CardStatus_v6          ril_card_status;
  qcril_instance_id_e_type   instance_id;
  int                        slot       = QCRIL_UIM_INVALID_SLOT_INDEX_VALUE;
  RIL_Errno                  ril_err    = QCRIL_UIM_RIL_E_INTERNAL_ERR;
  void                     * rsp_ptr    = NULL;
  size_t                     rsp_len    = 0;
  RIL_CardState              card_state = RIL_CARDSTATE_ABSENT;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  /* Sanity check */
  if ((params_ptr == NULL) ||
      (ret_ptr    == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  instance_id = params_ptr->instance_id;
  if (instance_id >= QCRIL_MAX_INSTANCE_ID)
  {
    QCRIL_LOG_ERROR("Invalid value, instance_id: 0x%x", instance_id);
    QCRIL_ASSERT(0);
    return;
  }

  /* Find slot info */
  if(params_ptr->event_id == QCRIL_EVT_HOOK_SLOT_GET_CARD_STATE_REQ)
  {
    if(params_ptr->data == NULL)
    {
      QCRIL_LOG_ERROR("Invalid value, instance_id: 0x%x", instance_id);
      QCRIL_ASSERT(0);
      return;
    }
    slot = *((int *)params_ptr->data);
  }
  else
  {
    slot = qcril_uim_instance_id_to_slot(instance_id);
  }

  memset(&ril_card_status, 0, sizeof(RIL_CardStatus_v6));

  /* Add entry to ReqList */
  QCRIL_UIM_ADD_ENTRY_TO_REQUEST_LIST(params_ptr);

  if (slot >= QMI_UIM_MAX_CARD_COUNT)
  {
    QCRIL_LOG_ERROR("Invalid value, slot: 0x%x", slot);
    qcril_uim_response(params_ptr->instance_id, params_ptr->t, QCRIL_UIM_RIL_E_INTERNAL_ERR,
                       NULL, 0, TRUE, "Invalid slot in qcril_uim_card_status");
    return;
  }

  QCRIL_MUTEX_LOCK(&qcril_uim_card_status_mutex, "qcril_uim_card_status_mutex");

  if (qcril_uim.card_status.card[slot].card_state == QMI_UIM_CARD_STATE_UNKNOWN)
  {
    /* For an un-init card state, send an error */
    QCRIL_LOG_ERROR( "Card status is unknown for slot: 0x%x,\n", slot);
    ril_err = QCRIL_UIM_RIL_E_INVALID_SIM_STATE;
  }
  else if (qcril_uim.pin1_info[0].silent_verify_in_progress ||
           qcril_uim.pin1_info[1].silent_verify_in_progress)
  {
    /* Send an error if PIN1 state is not yet updated after silent PIN1
       verification */
    QCRIL_LOG_ERROR("%s", "PIN1 state not updated after silent verification");
    ril_err = QCRIL_UIM_RIL_E_INVALID_SIM_STATE;
  }
  /* If silent pin verification is required and pin state is
     ENABLED_NOT_VERIFIED then do not send card status */
  else if(qcril_uim.silent_pin_verify_reqd &&
          qcril_uim_is_silent_pin_verification_needed(slot))
  {
    QCRIL_LOG_ERROR("%s", "Silent PIN verification is in progress")
    ril_err = QCRIL_UIM_RIL_E_INVALID_SIM_STATE;
  }
  else
  {
    if(params_ptr->event_id == QCRIL_EVT_HOOK_SLOT_GET_CARD_STATE_REQ)
    {
      qcril_uim_convert_card_state(&card_state,
                                   qcril_uim.card_status.card[slot].card_state,
                                   qcril_uim.card_status.card[slot].card_error);
      rsp_ptr = &card_state;
      rsp_len = sizeof(card_state);
    }
    else
    {
      /* Construct RIL_CardStatus_v6 and log string */
      qcril_uim_construct_card_status(&ril_card_status,
                                      &qcril_uim.card_status,
                                      slot);
      rsp_ptr = &ril_card_status;
      rsp_len = sizeof(ril_card_status);
    }
    ril_err = RIL_E_SUCCESS;
  }

  QCRIL_MUTEX_UNLOCK(&qcril_uim_card_status_mutex, "qcril_uim_card_status_mutex");

  /* Send the response */
  qcril_uim_response( instance_id,
                      params_ptr->t,
                      ril_err,
                      rsp_ptr,
                      rsp_len,
                      TRUE,
                      NULL );

  /* We need to clear the timer if it is running because we block the incoming new
     card status INDs until ATEL successfully reads the card status. Also QCRIL
     needs to fetch latest card status from modem that we might have skipped */
  if ((ril_err == RIL_E_SUCCESS) && (qcril_uim_card_state_check.timer_id != 0))
  {
    int  qmi_err_code = QMI_NO_ERR;

    qcril_uim_cancel_card_state_check_timer();

    /* Send card status to get the latest status */
    qmi_err_code = qcril_qmi_uim_get_card_status(qcril_uim.qmi_handle,
                                                 qmi_uim_card_init_callback,
                                                 NULL,
                                                 NULL);
    if (qmi_err_code != QMI_NO_ERR)
    {
      QCRIL_LOG_ERROR( "Get card status failed, qmi_err_code: 0x%x\n", qmi_err_code);
    }
  }

  /* Free up any allocated memory for AID & Label info */
  qcril_uim_free_aid_and_label_info(&ril_card_status);

} /* qcril_uim_request_get_sim_status */

/*===========================================================================

  FUNCTION:  qcril_uim_direct_get_card_status

===========================================================================*/
/*!
    @brief
    Returns card status from UIM RIL cache

    @return
    None
*/
/*=========================================================================*/
RIL_Errno qcril_uim_direct_get_card_status
(
  uint8                      slot,
  RIL_CardStatus_v6        * ril_card_status
)
{
  RIL_Errno                  ret;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  if (ril_card_status == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, NULL ril_card_statusd");
    QCRIL_ASSERT(0);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  if (slot >= QMI_UIM_MAX_CARD_COUNT)
  {
    QCRIL_LOG_ERROR("Invalid value, slot: 0x%x", slot);
    QCRIL_ASSERT(0);
    return QCRIL_UIM_RIL_E_INTERNAL_ERR;
  }

  memset(ril_card_status, 0, sizeof(*ril_card_status));

  QCRIL_MUTEX_LOCK(&qcril_uim_card_status_mutex, "qcril_uim_card_status_mutex");

  if (qcril_uim.card_status.card[slot].card_state == QMI_UIM_CARD_STATE_UNKNOWN)
  {
    /* For an un-init card state, send an error */
    QCRIL_LOG_ERROR( "Card status is unknown for slot: 0x%x,\n", slot);
    ret = QCRIL_UIM_RIL_E_INVALID_SIM_STATE;
  }
  else
  {
    /* Construct RIL_CardStatus_v6 and log string */
    qcril_uim_construct_card_status(ril_card_status,
                                    &qcril_uim.card_status,
                                    slot);
    ret = RIL_E_SUCCESS;
  }
  QCRIL_MUTEX_UNLOCK(&qcril_uim_card_status_mutex, "qcril_uim_card_status_mutex");

  return ret;
}  /* qcril_uim_direct_get_card_status */


/*===========================================================================

  FUNCTION:  qcril_uim_process_recovery_ind

===========================================================================*/
/*!
    @brief
    Main function for processing QMI recovery complete indication.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_process_recovery_ind
(
  const qcril_uim_indication_params_type  * ind_param_ptr,
  qcril_request_return_type               * const ret_ptr /*!< Output parameter */
)
{
  qcril_unsol_resp_params_type      unsol_resp;
  qmi_uim_slot_type                 slot = QMI_UIM_SLOT_1;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  if ((ind_param_ptr == NULL) || (ret_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid inputs, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  memset(&unsol_resp, 0x00, sizeof(unsol_resp));

  switch ( qcril_uim_instance_id_to_slot(ind_param_ptr->instance_id) )
  {
    case 0:
      slot = QMI_UIM_SLOT_1;
      break;

    case 1:
      slot = QMI_UIM_SLOT_2;
      break;

    case 2:
      slot = QMI_UIM_SLOT_3;
      break;

    default:
      QCRIL_LOG_ERROR("Invalid instance 0x%x", ind_param_ptr->instance_id);
      return;
  }

  if (slot != ind_param_ptr->ind_data.recovery_ind.slot)
  {
    return;
  }

  SecureElementhandleRecovery();

#ifdef RIL_UNSOL_SIM_INTERNAL_RESET
  /* Send unsolicited response to framework */
  qcril_default_unsol_resp_params(ind_param_ptr->instance_id,
                                  (int) RIL_UNSOL_SIM_INTERNAL_RESET,
                                  &unsol_resp);
  qcril_send_unsol_response(&unsol_resp);
#endif /* RIL_UNSOL_SIM_INTERNAL_RESET */
} /* qcril_uim_process_recovery_ind */


/*===========================================================================

  FUNCTION:  qcril_uim_process_supply_voltage_ind

===========================================================================*/
/*!
    @brief
    Main function for processing QMI supply voltage indication.
    Note that the data type for QCRIL_EVT_HOOK_UNSOL_UICC_VOLTAGE_STATUS is
    RIL_UiccVoltageStatus

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_process_supply_voltage_ind
(
  const qcril_uim_indication_params_type  * ind_param_ptr,
  qcril_request_return_type               * const ret_ptr /*!< Output parameter */
)
{
  qmi_uim_slot_type                 slot           = QMI_UIM_SLOT_1;
  RIL_UiccVoltageStatus             voltage_status = UICC_VOLTAGE_START_ACTIVATION;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  if ((ind_param_ptr == NULL) || (ret_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid inputs, cannot proceed");
    QCRIL_ASSERT(0);
    return;
  }

  QCRIL_LOG_INFO( "slot: 0x%x, vcc_command: 0x%x\n",
                  ind_param_ptr->ind_data.supply_voltage_ind.slot,
                  ind_param_ptr->ind_data.supply_voltage_ind.vcc_command);

  switch ( qcril_uim_instance_id_to_slot(ind_param_ptr->instance_id) )
  {
    case 0:
      slot = QMI_UIM_SLOT_1;
      break;

    case 1:
      slot = QMI_UIM_SLOT_2;
      break;

    case 2:
      slot = QMI_UIM_SLOT_3;
      break;

    default:
      QCRIL_LOG_ERROR("Invalid instance 0x%x", ind_param_ptr->instance_id);
      return;
  }

  /* We send an ACK from QCRIL direclty only for this condition: different slot
     than RILD instance & the vcc status is deactivate. Otherwise we send the UNSOL
     and expect the client to respond with an ACK */
  if ((slot != ind_param_ptr->ind_data.supply_voltage_ind.slot) &&
      (ind_param_ptr->ind_data.supply_voltage_ind.vcc_command == QMI_UIM_VCC_START_DEACTIVATION))
  {
    int                                ret = -1;
    qmi_uim_rsp_data_type              rsp_data;
    qmi_uim_supply_voltage_params_type vcc_params;

    memset(&rsp_data, 0x00, sizeof(qmi_uim_rsp_data_type));
    memset(&vcc_params, 0x00, sizeof(qmi_uim_supply_voltage_params_type));

    vcc_params.slot = ind_param_ptr->ind_data.supply_voltage_ind.slot;

    ret = qcril_qmi_uim_supply_voltage(qcril_uim.qmi_handle,
                                       &vcc_params,
                                       NULL,
                                       NULL,
                                       &rsp_data);
    if (ret < 0)
    {
      QCRIL_LOG_ERROR("Error for qcril_qmi_uim_supply_voltage, ret: 0x%x", ret);
    }
    return;
  }

  /* Map the status */
  switch (ind_param_ptr->ind_data.supply_voltage_ind.vcc_command)
  {
    case QMI_UIM_VCC_ACTIVATED:
      voltage_status = UICC_VOLTAGE_ACTIVATED;
      break;

    case QMI_UIM_VCC_START_DEACTIVATION:
      voltage_status = UICC_VOLTAGE_START_DEACTIVATION;
      break;

    default:
      QCRIL_LOG_ERROR("Unsupported vcc status 0x%x",
                      ind_param_ptr->ind_data.supply_voltage_ind.vcc_command);
      return;
  }

  /* Send OEMHook unsolicited response to framework */
  qcril_hook_unsol_response(ind_param_ptr->instance_id,
                            (int) QCRIL_EVT_HOOK_UNSOL_UICC_VOLTAGE_STATUS,
                            (void *) &voltage_status,
                            sizeof(RIL_UiccVoltageStatus));

} /* qcril_uim_process_supply_voltage_ind */


/*=========================================================================

  FUNCTION:  qcril_uim_request_voltage_status

===========================================================================*/
/*!
    @brief
     Handles QCRIL_EVT_HOOK_UICC_VOLTAGE_STATUS_REQ request from QCRIL.
     Note that both the request & response have no data payload.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_request_voltage_status
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr /*!< Output parameter */
)
{
  qcril_uim_original_request_type    * original_req_ptr         = NULL;
  qmi_uim_supply_voltage_params_type   voltage_params;
  RIL_Errno                            ril_err                  = QCRIL_UIM_RIL_E_INTERNAL_ERR;

  /* Sanity check */
  if ((params_ptr == NULL) || (ret_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot proceed");
    return;
  }

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  /* Add entry to ReqList */
  QCRIL_UIM_ADD_ENTRY_TO_REQUEST_LIST(params_ptr);

  memset(&voltage_params, 0, sizeof(qmi_uim_supply_voltage_params_type));

  /* Find slot info */
  if ( ril_to_uim_is_tsts_enabled() && (params_ptr->instance_id == QCRIL_THIRD_INSTANCE_ID) )
  {
    voltage_params.slot = QMI_UIM_SLOT_3;
  }
  else if ( (ril_to_uim_is_tsts_enabled() || ril_to_uim_is_dsds_enabled()) &&
            (params_ptr->instance_id == QCRIL_SECOND_INSTANCE_ID) )
  {
    voltage_params.slot = QMI_UIM_SLOT_2;
  }
  else if (params_ptr->instance_id == QCRIL_DEFAULT_INSTANCE_ID)
  {
    voltage_params.slot = QMI_UIM_SLOT_1;
  }
  else
  {
    QCRIL_LOG_ERROR( " Invalid instance_id in input: 0x%x\n", params_ptr->instance_id);
    ril_err = QCRIL_UIM_RIL_E_INTERNAL_ERR;
    goto voltage_status_error;
  }

  /* Allocate original request */
  original_req_ptr = qcril_uim_allocate_orig_request(params_ptr->instance_id,
                                                     QCRIL_MAX_MODEM_ID - 1,
                                                     params_ptr->t,
                                                     params_ptr->event_id,
                                                     0);

  if (original_req_ptr != NULL)
  {
    if (qcril_uim_queue_send_request(QCRIL_UIM_REQUEST_SUPPLY_VOLTAGE,
                                     qcril_uim.qmi_handle,
                                     &voltage_params,
                                     qmi_uim_callback,
                                     (void*)original_req_ptr) >= 0)
    {
      return;
    }
    else
    {
      ril_err = QCRIL_UIM_RIL_E_MODEM_ERR;
    }
  }
  else
  {
    ril_err = QCRIL_UIM_RIL_E_NO_MEMORY;
  }

voltage_status_error:
  qcril_uim_response(params_ptr->instance_id, params_ptr->t, ril_err,
                       NULL, 0, TRUE, "error in qcril_uim_request_voltage_status");

  /* Clean up any original request if allocated */
  if (original_req_ptr)
  {
    qcril_free(original_req_ptr);
    original_req_ptr = NULL;
  }
} /* qcril_uim_request_voltage_status */


/*=========================================================================

  FUNCTION:  qcril_uim_request_uicc_power

===========================================================================*/
void qcril_uim_request_uicc_power
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr /*!< Output parameter */
)
{
  qmi_uim_slot_type                 slot_id;
  RIL_UiccPower                     power_req           = RIL_UICC_POWER_DOWN;
  qcril_uim_original_request_type * original_req_ptr    = NULL;
  RIL_SlotCardPower               * slot_power_req_ptr  = NULL;
  RIL_Errno                         err                 = QCRIL_UIM_RIL_E_INTERNAL_ERR;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  if ((params_ptr == NULL) || (ret_ptr == NULL))
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot process request");
    return;
  }

  if (params_ptr->event_id == QCRIL_EVT_HOOK_SLOT_CARD_POWER_REQ &&
      params_ptr->data == NULL)
  {
    QCRIL_LOG_ERROR("%s", "Invalid input, cannot process request");
    return;
  }

  /* Add entry to ReqList */
  QCRIL_UIM_ADD_ENTRY_TO_REQUEST_LIST(params_ptr);

  if(params_ptr->event_id == QCRIL_EVT_HOOK_SLOT_CARD_POWER_REQ)
  {
    uint8       req_slot_id = 0;

    slot_power_req_ptr  = (RIL_SlotCardPower *)params_ptr->data;
    req_slot_id         = slot_power_req_ptr->slot_id;
    switch(req_slot_id)
    {
      case 0:
        slot_id = QMI_UIM_SLOT_1;
        break;
      case 1:
        slot_id = QMI_UIM_SLOT_2;
        break;
      case 2:
        slot_id = QMI_UIM_SLOT_3;
        break;
      default:
        QCRIL_LOG_ERROR( " Invalid slot_id in input: 0x%x\n", req_slot_id);
        goto send_power_req_error;
    }
    power_req = slot_power_req_ptr->card_power;
  }
  else
  {
    if (params_ptr->data == NULL)
    {
      err = QCRIL_UIM_RIL_E_INVALID_ARGUMENTS;
      goto send_power_req_error;
    }

    /* Find slot info */
    if ( ril_to_uim_is_tsts_enabled() && (params_ptr->instance_id == QCRIL_THIRD_INSTANCE_ID) )
    {
      slot_id = QMI_UIM_SLOT_3;
    }
    else if ( (ril_to_uim_is_tsts_enabled() || ril_to_uim_is_dsds_enabled()) &&
              (params_ptr->instance_id == QCRIL_SECOND_INSTANCE_ID) )
    {
      slot_id = QMI_UIM_SLOT_2;
    }
    else if (params_ptr->instance_id == QCRIL_DEFAULT_INSTANCE_ID)
    {
      slot_id = QMI_UIM_SLOT_1;
    }
    else
    {
      QCRIL_LOG_ERROR( " Invalid instance_id in input: 0x%x\n", params_ptr->instance_id);
      goto send_power_req_error;
    }

    power_req = *((RIL_UiccPower *)params_ptr->data);
  }

  /* Allocate original request */
  original_req_ptr = qcril_uim_allocate_orig_request(params_ptr->instance_id,
                                                     QCRIL_MAX_MODEM_ID - 1,
                                                     params_ptr->t,
                                                     params_ptr->event_id,
                                                     0);
  if (original_req_ptr == NULL)
  {
    err = QCRIL_UIM_RIL_E_NO_MEMORY;
    goto send_power_req_error;
  }

  if(params_ptr->event_id == QCRIL_EVT_HOOK_SLOT_CARD_POWER_REQ)
  {
    original_req_ptr->data.slot_id = slot_power_req_ptr->slot_id;
  }

  if (power_req == RIL_UICC_POWER_DOWN)
  {
    qmi_uim_power_down_params_type power_down_params;

    memset(&power_down_params, 0x00, sizeof(power_down_params));
    power_down_params.slot = slot_id;

    if (qcril_uim_queue_send_request(QCRIL_UIM_REQUEST_POWER_DOWN,
                                     qcril_uim.qmi_handle,
                                     &power_down_params,
                                     qmi_uim_callback,
                                     (void*)original_req_ptr) >= 0)
    {
      return;
    }
    err = QCRIL_UIM_RIL_E_MODEM_ERR;
  }
  else if (power_req == RIL_UICC_POWER_UP ||
           power_req == RIL_UICC_POWER_UP_PASS_THRU)
  {
    qmi_uim_power_up_params_type power_up_params;

    power_up_params.mode = QMI_UIM_CARD_MODE_TELECOM_CARD;
    power_up_params.slot = slot_id;

    if (power_req == RIL_UICC_POWER_UP_PASS_THRU)
    {
      power_up_params.mode = QMI_UIM_CARD_MODE_NON_TELECOM_CARD;
    }

    if (qcril_uim_queue_send_request(QCRIL_UIM_REQUEST_POWER_UP,
                                     qcril_uim.qmi_handle,
                                     &power_up_params,
                                     qmi_uim_callback,
                                     (void*)original_req_ptr) >= 0)
    {
      return;
    }
    err = QCRIL_UIM_RIL_E_MODEM_ERR;
  }
  else
  {
    err = QCRIL_UIM_RIL_E_INVALID_ARGUMENTS;
  }

send_power_req_error:
  if(params_ptr->event_id == QCRIL_EVT_HOOK_SLOT_CARD_POWER_REQ)
  {
    RIL_SlotCardPowerResp  power_rsp;

    power_rsp.slot_id = slot_power_req_ptr->slot_id;
    power_rsp.ril_err = err;
    qcril_uim_response(params_ptr->instance_id, params_ptr->t, RIL_E_SUCCESS,
                       &power_rsp, sizeof(RIL_SlotCardPowerResp),
                       TRUE, "error in qcril_uim_request_uicc_power");
  }
  else
  {
    qcril_uim_response(params_ptr->instance_id, params_ptr->t, err,
                       NULL, 0, TRUE, "error in qcril_uim_request_uicc_power");
  }

  /* Clean up any original request if allocated */
  if (original_req_ptr)
  {
    qcril_free(original_req_ptr);
    original_req_ptr = NULL;
  }
} /* qcril_uim_request_uicc_power */


/*=========================================================================

  FUNCTION:  qcril_uim_cancel_card_state_check_timer

===========================================================================*/
/*!
    @brief
    Cancels the card state check timer

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_cancel_card_state_check_timer
(
  void
)
{
  if (qcril_uim_card_state_check.timer_id != 0)
  {
    QCRIL_LOG_INFO("%s", "Cancelling card state check timer");
    qcril_cancel_timed_callback((void *)(uintptr_t) qcril_uim_card_state_check.timer_id);
    qcril_uim_card_state_check.timer_id = 0;
  }
} /* qcril_uim_cancel_card_state_check_timer */


#endif /* defined (FEATURE_QCRIL_UIM_QMI) */
