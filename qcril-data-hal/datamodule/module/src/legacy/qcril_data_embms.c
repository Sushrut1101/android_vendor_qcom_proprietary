/*!
  @file
  qcril_data_embms.c

  @brief
  Handles RIL EMBMS requests for DATA services.

*/

/*===========================================================================
    Copyright (c) 2011-2015, 2019 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //linux/pkgs/proprietary/qc-ril/main/source/qcril_data.c#17 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
10/17/11   sy     Initial version

===========================================================================*/

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#ifdef FEATURE_DATA_EMBMS

#ifdef QCRIL_DATA_OFFTARGET
#include <netinet/in.h>
#include <errno.h>
#endif

#include "qdp.h"
#include "qcril_data.h"
#include "qcril_data_defs.h"
#include "qmi_embms_v01.h"
#include "qcril_data_utils.h"
#include "qcril_reqlist.h"
#include "DataModuleMutex.h"


/*===========================================================================

                   INTERNAL DEFINITIONS AND TYPES

===========================================================================*/
#define SESSION_ID_INVALID 0

/*===========================================================================

                    INTERNAL FUNCTION PROTOTYPES

===========================================================================*/
#if 0
static inline int qcril_data_get_ril_embms_tmgi_deactivated_code
(
  dsi_embms_tmgi_deactivate_reason_type_t *dsi_embms_tmgi_deactive_reason,
  int                                     *ril_embms_tmgi_deactive_code
);
#endif

/*===========================================================================

                    EXTERNAL FUNCTION PROTOTYPES

===========================================================================*/
extern void qcril_data_net_cb(
  dsi_hndl_t         dsi_hndl,
  void               *user_data,
  dsi_net_evt_t      net_evt,
  dsi_evt_payload_t  *payload
);

/*=========================================================================
  FUNCTION:  qcril_data_get_ril_embms_tmgi_deactivated_code

===========================================================================*/
/*!
    @brief
    gets ril TMGI deactivated code given qmi deactivated reason code
    Currently, it converts every type of qmi deactivated reason code into
    generic failure. Future enhancement will include the conversion from a
    table mapping.

    @return
    FAILURE - if bad params received
    SUCCESS - other wise (must return valid RIL cause code)
*/
/*=========================================================================*/
#if 0
static inline int qcril_data_get_ril_embms_tmgi_deactivated_code
(
  dsi_embms_tmgi_deactivate_reason_type_t *dsi_embms_tmgi_deactive_reason,
  int                                     *ril_embms_tmgi_deactive_code
)
{
  if(NULL == dsi_embms_tmgi_deactive_reason ||
     NULL == ril_embms_tmgi_deactive_code)
  {
    return FAILURE;
  }

  /* Return Generic failure until error code type is defined in upper layer */
  *ril_embms_tmgi_deactive_code = RIL_E_GENERIC_FAILURE;
  return SUCCESS;
}
#endif

/*===========================================================================

  FUNCTION:  qcril_data_embms_enable_data_req

===========================================================================*/
/*!
    @brief

    Handles QCRIL_EVT_QMI_RIL_EMBMS_ENABLE_DATA_REQ.

    @pre Before calling, INFO_TBL_MUTEX must not be locked by the calling thread

    @return

    None on Success, Generic failure response on Failure
*/
/*=========================================================================*/
void qcril_data_embms_enable_data_req
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
)
{
  qcril_instance_id_e_type        instance_id;
  qcril_modem_id_e_type           modem_id;
  int                             i;
  char                            tmp_apn[ DS_CALL_INFO_APN_MAX_LEN + 1 ];
  qcril_embms_enable_response_payload_type enable_response;
  dsi_call_param_value_t          ipfamily_info;

  RIL_Errno ril_req_res = RIL_E_GENERIC_FAILURE;

  QCRIL_LOG_INFO( "%s", "qcril_data_embms_enable_data_req entered" );

  /* validate input parameter */
  if ( ( NULL == params_ptr ) || ( NULL == ret_ptr ) )
  {
    QCRIL_LOG_ERROR( "BAD input, params_ptr [%p], ret_ptr [%p]",
                     (unsigned int *)params_ptr, (unsigned int *)ret_ptr);
    goto bail;
  }

  instance_id = params_ptr->instance_id;
  modem_id = params_ptr->modem_id;

  if (instance_id >= QCRIL_MAX_INSTANCE_ID ||
      modem_id >= QCRIL_MAX_MODEM_ID)
  {
    QCRIL_LOG_ERROR("BAD iput, instance_id [%d], modem_id [%d]", instance_id, modem_id);
    goto bail;
  }

  /* input parameter is good, proceed... */
  QCRIL_DATA_MUTEX_LOCK(INFO_TBL_MUTEX);

  do
  {
    for( i = 0; i < MAX_CONCURRENT_UMTS_DATA_CALLS; i++ )
    {
      if( !VALIDATE_LOCAL_DATA_OBJ( (&info_tbl[i]) ) )
      {
        break;
      }
    }/* for() */

    QCRIL_LOG_DEBUG( "found free info_tbl at index [%d]", i);

    if ( i == MAX_CONCURRENT_UMTS_DATA_CALLS )
    {
      QCRIL_LOG_ERROR( "%s", "no free info_tbl entry" );
      break;
    }

    /* The corresponding dsi_cb_tbl entry should have already been
       cleaned up. But, perform cleanup just in case */
    qcril_data_clear_dsi_cb_tbl_entry(&dsi_cb_tbl[i]);

    /* Free the memory for call_params if it hasn't been freed */
    if (NULL != info_tbl[i].call_params)
    {
      free(info_tbl[i].call_params);
      info_tbl[i].call_params = NULL;
    }

    /* Allocate CID, copy APN and other call params */
    info_tbl[i].info_flg    = FALSE; /* mark call_info and dev_name as invalid */
    info_tbl[i].index       = i;
    info_tbl[i].cid         = i;

    tmp_apn[0] = '\0';
    strlcpy( info_tbl[i].call_info.apn, tmp_apn , sizeof(info_tbl[i].call_info.apn));
    info_tbl[i].instance_id = instance_id;
    info_tbl[i].modem_id    = modem_id;
    info_tbl[i].pend_tok    = params_ptr->t;
    info_tbl[i].pend_req    = QCRIL_EVT_QMI_RIL_EMBMS_ENABLE_DATA_REQ;
    QCRIL_LOG_INFO( "DEBUG:  %s step %d - info_tbl_ptr->pend_tok[0x%x] "
                    "info_tbl_ptr->pend_req[0x%X]",
                    __func__, 0, info_tbl[i].pend_tok, info_tbl[i].pend_req );
    info_tbl[i].qmi_wds_hndl = QCRIL_DATA_HNDL_INVALID;
    info_tbl[i].dsi_hndl    = (void *)QCRIL_DATA_HNDL_INVALID;
    info_tbl[i].qdp_umts_profile_id = QCRIL_INVALID_PROFILE_ID;
    info_tbl[i].qdp_cdma_profile_id = QCRIL_INVALID_PROFILE_ID;
    info_tbl[i].self        = &info_tbl[i];

    /* store default call fail error */
    info_tbl[i].call_info.inactiveReason = PDP_FAIL_ERROR_UNSPECIFIED;

    /*Must destroy the list when disable API is implemented.*/
    list_init(&info_tbl[i].embms_txns_list);

    if ( ( info_tbl[i].dsi_hndl =
           dsi_get_data_srvc_hndl( qcril_data_net_cb,
                                 ( void *)&dsi_cb_tbl[i] ) ) == NULL )
    {
      QCRIL_LOG_ERROR( "%s", "unable to get dsi hndl" );
      break;
    }

    /* Update the dsi_cb_tbl[] entry with the required state information */
    qcril_data_update_dsi_cb_tbl_entry(&dsi_cb_tbl[i],
                                       instance_id,
                                       modem_id,
                                       params_ptr->t,
                                       info_tbl[i].dsi_hndl,
                                       &info_tbl[i]);

    QCRIL_LOG_DEBUG("info_tbl[%d] has reserved dsi_hndl[0x%x]",
                     i, info_tbl[i].dsi_hndl);

    QCRIL_DS_LOG_DBG_MEM( "dsi_hndl", info_tbl[i].dsi_hndl );

    /* Currently RIL does not specify any IP family preference for
     * making an embms call. However within the qdi library we need
     * an IP family preference for calls to go through. Hence
     * defaulting this to V4.
     */
    ipfamily_info.buf_val = NULL;
    ipfamily_info.num_val = DSI_IP_VERSION_4;

    info_tbl[i].dsi_ip_version = ipfamily_info.num_val;

    if ( dsi_set_data_call_param( info_tbl[i].dsi_hndl,
                                  DSI_CALL_INFO_IP_VERSION,
                                  &ipfamily_info ) != DSI_SUCCESS )
    {
      QCRIL_LOG_ERROR( "%s", "Unable to set ip version preference" );
      break;
    }

    if ( ( dsi_embms_enable( info_tbl[i].dsi_hndl ) ) != DSI_SUCCESS )
    {
      QCRIL_LOG_ERROR( "unable to enable EMBMS, index [%d]", info_tbl[i].index );
      QCRIL_DS_LOG_DBG_MEM( "dsi_hndl", info_tbl[i].dsi_hndl );

      memset ( &enable_response, 0, sizeof( enable_response ) );
      enable_response.call_id        = 0;
      enable_response.cause          = RIL_E_GENERIC_FAILURE;
      enable_response.resp_code      = QCRIL_DATA_EMBMS_ERROR_UNKNOWN;

/*
      qcril_event_queue( instance_id,
                         modem_id,
                         QCRIL_DATA_ON_STACK,
                         QCRIL_EVT_QMI_RIL_EMBMS_ENABLE_DATA_CON,
                         (void *) &enable_response,
                         sizeof( enable_response ),
                         (RIL_Token) QCRIL_TOKEN_ID_INTERNAL );
*/
      qcril_data_embms_enable_data_con(&enable_response);

      break;
    }
    ril_req_res = RIL_E_SUCCESS;
  }while(FALSE);

  if (RIL_E_SUCCESS != ril_req_res)
  {
    /* clean up if we had reserved an info tbl entry */
    if (i < MAX_CONCURRENT_UMTS_DATA_CALLS)
    {
      if (VALIDATE_LOCAL_DATA_OBJ(&info_tbl[i]) && info_tbl[i].dsi_hndl)
      {
        qcril_data_cleanup_call_state(&info_tbl[i]);
      }

      if (VALIDATE_LOCAL_DATA_OBJ(&info_tbl[i]) &&
          info_tbl[i].pend_tok == params_ptr->t)
      {
        if (info_tbl[i].qdp_umts_profile_id != QCRIL_INVALID_PROFILE_ID)
        {
          QCRIL_LOG_DEBUG("releasing QDP profile id [%d]",
                        info_tbl[i].qdp_umts_profile_id);
          qdp_profile_release(info_tbl[i].qdp_umts_profile_id);
        }
        if (info_tbl[i].qdp_cdma_profile_id != QCRIL_INVALID_PROFILE_ID)
        {
          QCRIL_LOG_DEBUG("releasing QDP profile id [%d]",
                           info_tbl[i].qdp_cdma_profile_id);
          qdp_profile_release(info_tbl[i].qdp_cdma_profile_id);
        }
      }
    }/* i < MAX_CONCURRENT_UMTS_DATA_CALLS */
  }/* RIL_E_SUCCESS != ril_req_res */

  QCRIL_DATA_MUTEX_UNLOCK(INFO_TBL_MUTEX);

bail:
  QCRIL_LOG_INFO( "qcril_data_embms_enable_data_req completed %d", (int) ril_req_res );
}

/*===========================================================================

  FUNCTION:  qcril_data_embms_activate_tmgi

===========================================================================*/
/*!
    @brief

    Handles QCRIL_EVT_HOOK_EMBMS_ACTIVATE_TMGI.

    @pre Before calling, INFO_TBL_MUTEX must not be locked by the calling thread

    @return

    None on Success, Generic failure response on Failure
*/
/*=========================================================================*/
void qcril_data_embms_activate_tmgi
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
)
{
  QCRIL_LOG_INFO( "%s", "qcril_data_embms_activate_tmgi entered" );
  (void)(ret_ptr);
  if(params_ptr != NULL)
  {
    QCRIL_LOG_INFO("%s","dispatching ActivateEmbms Message");
    activate_embms_request_msg(params_ptr);
  }
}

/*===========================================================================

  FUNCTION:  qcril_data_embms_deactivate_tmgi

===========================================================================*/
/*!
    @brief

    Handles QCRIL_EVT_HOOK_EMBMS_DEACTIVATE_TMGI.

    @pre Before calling, INFO_TBL_MUTEX must not be locked by the calling thread

    @return

    None on Success, Generic failure response on Failure
*/
/*=========================================================================*/
void qcril_data_embms_deactivate_tmgi
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
)
{
  QCRIL_LOG_INFO( "%s", "qcril_data_embms_deactivate_tmgi entered" );
  (void)(ret_ptr);
  if(params_ptr != NULL)
  {
    QCRIL_LOG_INFO("%s","dispatching deactivateEmbms Message");
    deactivate_embms_request_msg(params_ptr);
  }
}
/*===========================================================================

  FUNCTION:  qcril_data_embms_activate_deactivate_tmgi

===========================================================================*/
/*!
    @brief

    Handles QCRIL_EVT_HOOK_EMBMS_ACTIVATE_DEACTIVATE_TMGI

    @pre Before calling, INFO_TBL_MUTEX must not be locked by the calling thread

    @return

    None on Success, Generic failure response on Failure
*/
/*=========================================================================*/
void qcril_data_embms_activate_deactivate_tmgi
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
)
{
  QCRIL_LOG_INFO( "%s", "qcril_data_embms_act_deactivate_tmgi entered" );
  (void)(ret_ptr);
  if(params_ptr != NULL)
  {
    QCRIL_LOG_INFO("%s","dispatching activateDeactivateEmbms Message");
    activate_deactivate_embms_request_msg(params_ptr);
  }
}
/*===========================================================================

  FUNCTION:  qcril_data_embms_get_available_tmgi

===========================================================================*/
/*!
    @brief

    Handles QCRIL_EVT_HOOK_EMBMS_GET_AVAILABLE_TMGI.

    @pre Before calling, INFO_TBL_MUTEX must not be locked by the calling thread

    @return

    None on Success, Generic failure response on Failure
*/
/*=========================================================================*/
void qcril_data_embms_get_available_tmgi
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
)
{
  QCRIL_LOG_INFO( "%s", "qcril_data_embms_get_available_tmgi entered" );
  (void)(ret_ptr);
  if(params_ptr != NULL)
  {
    QCRIL_LOG_INFO("%s","dispatching getAvailableTmgi Message");
    embms_get_available_tmgi_msg(params_ptr);
  }
}

/*===========================================================================

  FUNCTION:  qcril_data_embms_get_active_tmgi

===========================================================================*/
/*!
    @brief

    Handles QCRIL_EVT_HOOK_EMBMS_GET_ACTIVE_TMGI.

    @pre Before calling, INFO_TBL_MUTEX must not be locked by the calling thread

    @return

    None on Success, Generic failure response on Failure
*/
/*=========================================================================*/
void qcril_data_embms_get_active_tmgi
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
)
{
  QCRIL_LOG_INFO( "%s", "qcril_data_embms_get_active_tmgi entered" );
  (void)(ret_ptr);
  if(params_ptr != NULL)
  {
    QCRIL_LOG_INFO("%s","dispatching getActiveTmgi Message");
    embms_get_active_tmgi_msg(params_ptr);
  }
}

/*===========================================================================

  FUNCTION:  qcril_data_embms_content_desc_update

===========================================================================*/
/*!
    @brief

    Handles QCRIL_EVT_HOOK_EMBMS_CONTENT_DESC_UPDATE.

    @pre Before calling, INFO_TBL_MUTEX must not be locked by the calling thread

    @return

    None on Success, Generic failure response on Failure
*/
/*=========================================================================*/
void qcril_data_embms_content_desc_update
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
)
{
  QCRIL_LOG_INFO( "%s", "qcril_data_embms_content_desc_update entered" );
  (void)(ret_ptr);
  if(params_ptr != NULL)
  {
    QCRIL_LOG_INFO("%s","dispatching contentDescUpdate Message");
    embms_content_desc_update_msg(params_ptr);
  }
}

/*===========================================================================

  FUNCTION:  qcril_data_embms_send_interested_list

===========================================================================*/
/*!
    @brief

    Handles QCRIL_EVT_HOOK_EMBMS_SEND_INTERESTED_TMGI_LIST.

    @pre Before calling, INFO_TBL_MUTEX must not be locked by the calling thread

    @return

    None on Success, Generic failure response on Failure
*/
/*=========================================================================*/
void qcril_data_embms_send_interested_list
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
)
{
  QCRIL_LOG_INFO( "%s", "qcril_data_embms_send_interested_list entered" );
  (void)(ret_ptr);
  if(params_ptr != NULL)
  {
    QCRIL_LOG_INFO("%s","dispatching sendInterestedList Message");
    embms_send_interested_list(params_ptr);
  }
}

/*===========================================================================

  FUNCTION:  qcril_data_is_embms_active

===========================================================================*/
/*!
    @brief
    Checks if an eMBMS call is active already

    @pre
    None

    @return
    TRUE if eMBMS call is active, FALSE if not
*/
/*=========================================================================*/
int qcril_data_is_embms_active
(
  void
)
{
  uint32_t             i;
  dsi_call_tech_type call_tech;

  QCRIL_LOG_INFO( "%s", "qcril_data_is_embms_active entered" );

  QCRIL_DATA_MUTEX_LOCK(INFO_TBL_MUTEX);

  do
  {
    for( i = 0; i < MAX_CONCURRENT_UMTS_DATA_CALLS; i++ )
    {
      if( VALIDATE_LOCAL_DATA_OBJ(&info_tbl[i]) &&
          (DSI_SUCCESS == dsi_get_call_tech(info_tbl[i].dsi_hndl, &call_tech)) &&
          (call_tech == DSI_EXT_TECH_EMBMS) )
      {
        QCRIL_LOG_DEBUG("Found an existing EMBMS call [%d] ID",info_tbl[i].cid);
        QCRIL_DATA_MUTEX_UNLOCK(INFO_TBL_MUTEX);
        QCRIL_LOG_INFO( "%s", "qcril_data_is_embms_active completed" );
        return TRUE;
      }
    }
  }while ( FALSE );

  QCRIL_DATA_MUTEX_UNLOCK(INFO_TBL_MUTEX);

  QCRIL_LOG_INFO( "%s", "qcril_data_is_embms_active completed" );
  return FALSE;
}

/*===========================================================================
  FUNCTION:  qcril_data_handle_embms_events

===========================================================================*/
/*!
    @brief
    Handles embms events. This is an internal function.

    @pre Before calling, INFO_TBL_MUTEX must not be locked by the calling thread

    @return
    None.
*/
/*=========================================================================*/
void
qcril_data_handle_embms_events
(
  qcril_instance_id_e_type       instance_id,
  qcril_data_call_info_tbl_type *info_tbl_ptr,
  qcril_data_event_data_t       *evt_info_ptr
)
{

  embms_activate_tmgi_resp_msg_v01             activate_response;
  embms_deactivate_tmgi_resp_msg_v01           deactivate_response;
  qcril_request_resp_params_type               resp;
  embms_unsol_active_tmgi_ind_msg_v01          active_indication;

  qcril_data_embms_tmgi_requests_type  *tmgi_txn;

  QCRIL_DS_ASSERT( evt_info_ptr != NULL, "validate pend RIL Token" );
  QCRIL_DS_ASSERT( info_tbl_ptr != NULL, "validate pend RIL Token" );

  QCRIL_LOG_DEBUG("%s", "qcril_data_handle_embms_events: ENTRY");

  QCRIL_LOG_DEBUG("%s", "Print Transaction List and its entries");

  if (DSI_NET_TMGI_ACTIVATED == evt_info_ptr->evt ||
      DSI_NET_TMGI_DEACTIVATED == evt_info_ptr->evt ||
      DSI_NET_TMGI_ACTIVATED_DEACTIVATED == evt_info_ptr->evt)
  {
     for ( tmgi_txn = (qcril_data_embms_tmgi_requests_type *) list_peek_front (&info_tbl_ptr->embms_txns_list);
           tmgi_txn != NULL;
           tmgi_txn  = (qcril_data_embms_tmgi_requests_type *)
                       list_peek_next (&info_tbl_ptr->embms_txns_list, &(tmgi_txn->link)))
     {
       QCRIL_LOG_DEBUG(" request:%s, and token:%d, TMGI:%x%x%x%x%x%x DEACT_TMGI:%x%x%x%x%x%x into the transactions list",
                       qcril_log_lookup_event_name(tmgi_txn->pend_req),
                       qcril_log_get_token_id(tmgi_txn->pend_tok ),
                       tmgi_txn->tmgi[0],
                       tmgi_txn->tmgi[1],
                       tmgi_txn->tmgi[2],
                       tmgi_txn->tmgi[3],
                       tmgi_txn->tmgi[4],
                       tmgi_txn->tmgi[5],
                       tmgi_txn->deact_tmgi[0],
                       tmgi_txn->deact_tmgi[1],
                       tmgi_txn->deact_tmgi[2],
                       tmgi_txn->deact_tmgi[3],
                       tmgi_txn->deact_tmgi[4],
                       tmgi_txn->deact_tmgi[5]);

     }

       QCRIL_LOG_DEBUG("Processing Activate TMGI received from modem :%x%x%x%x%x%x",
                     evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi[0],
                     evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi[1],
                     evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi[2],
                     evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi[3],
                     evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi[4],
                     evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi[5]);
       QCRIL_LOG_DEBUG("Processing Deactivate TMGI received from modem :%x%x%x%x%x%x",
                     evt_info_ptr->payload.embms_info.embms_deact_info.tmgi.tmgi[0],
                     evt_info_ptr->payload.embms_info.embms_deact_info.tmgi.tmgi[1],
                     evt_info_ptr->payload.embms_info.embms_deact_info.tmgi.tmgi[2],
                     evt_info_ptr->payload.embms_info.embms_deact_info.tmgi.tmgi[3],
                     evt_info_ptr->payload.embms_info.embms_deact_info.tmgi.tmgi[4],
                     evt_info_ptr->payload.embms_info.embms_deact_info.tmgi.tmgi[5]);
       QCRIL_LOG_DEBUG("Processing Act Deact TMGI received from modem ACTIVATE:%x%x%x%x%x%x",
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.act_tmgi.tmgi[0],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.act_tmgi.tmgi[1],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.act_tmgi.tmgi[2],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.act_tmgi.tmgi[3],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.act_tmgi.tmgi[4],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.act_tmgi.tmgi[5]);
       QCRIL_LOG_DEBUG("Processing Act Deact TMGI received from modem DEACTIVATE:%x%x%x%x%x%x",
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.deact_tmgi.tmgi[0],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.deact_tmgi.tmgi[1],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.deact_tmgi.tmgi[2],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.deact_tmgi.tmgi[3],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.deact_tmgi.tmgi[4],
                     evt_info_ptr->payload.embms_info.embms_act_deact_info.deact_tmgi.tmgi[5]);
  }
  /* Matching Algorithm Assumption: Indication responses
  ** for requests are gaurenteed to be received in order sent.
  */
  switch(evt_info_ptr->evt)
  {
    case DSI_NET_SAI_LIST_CHANGED:
    {
      embms_unsol_sai_ind_msg_v01  sai_indication;
      unsigned int list_index;
      unsigned int freq_index;
      unsigned int camped_index;
      unsigned int avail_index;

      unsigned short  list_len;
      unsigned char   sai_size = 0;
      unsigned short  camped_sai_list_size = 0;
      unsigned short  available_sai_list_size = 0;

      QCRIL_LOG_INFO(">>>DSI_NET_SAI_LIST_CHANGED: START>>> cid [%d],"
                     "index [%d]",
                     info_tbl_ptr->cid,
                     info_tbl_ptr->index);

      list_len = evt_info_ptr->payload.embms_info.embms_sai_info.freq_sai_list_len;
      if(evt_info_ptr->payload.embms_info.embms_sai_info.freq_sai_list_valid != TRUE)
      {
        QCRIL_LOG_ERROR("invalid sai_list, Drop SAI_LIST indication:%d", list_len);
        goto err_ret;
      }

      /* validate number of freqencies */
      list_len = (unsigned short)((list_len > QMI_WDS_EMBMS_FREQ_SAI_MAX_V01)?
                                  QMI_WDS_EMBMS_FREQ_SAI_MAX_V01: list_len);

      /* calculate the size for arrays */
      for (list_index = 0; list_index < list_len; list_index ++)
      {
        sai_size = evt_info_ptr->payload.embms_info.embms_sai_info.freq_sai_list[list_index].sai_list_len;
        /* validate sai_size */
        if (sai_size > QMI_WDS_EMBMS_SAI_LIST_MAX_V01)
        {
          QCRIL_LOG_ERROR("sai_list_len_per_freq is invalid, Drop SAI_LIST indication:%d", sai_size);
          goto err_ret;
        }

        available_sai_list_size = (unsigned short) (available_sai_list_size + sai_size);
        if (TRUE == evt_info_ptr->payload.embms_info.embms_sai_info.freq_sai_list[list_index].is_serving_frequency)
        {
          camped_sai_list_size = (unsigned short) (camped_sai_list_size + sai_size);
        }
      }

      memset(&sai_indication, 0, sizeof(sai_indication));
      sai_indication.available_sai_list_len = available_sai_list_size;
      sai_indication.camped_sai_list_len = camped_sai_list_size;
      sai_indication.num_of_sai_per_group_len = list_len;

      /* validate available_sai_list_len */
      if (sai_indication.available_sai_list_len > SAI_MAX_V01)
      {
        QCRIL_LOG_ERROR(" Oversize available_sai_list_len, Drop SAI_LIST indication:%d",
                        sai_indication.available_sai_list_len);
        goto err_ret;
      }
      /* validate camped_sai_list_len */
      if (sai_indication.camped_sai_list_len > SAI_PER_FREQ_MAX_V01)
      {
        QCRIL_LOG_ERROR(" Oversize camped_sai_list_len, Drop SAI_LIST indication:%d",
                        sai_indication.camped_sai_list_len);
        goto err_ret;
      }
      /* validate num_of_sai_per_group_len */
      if (sai_indication.num_of_sai_per_group_len > FREQ_MAX_V01)
      {
        QCRIL_LOG_ERROR(" Oversize num_of_sai_per_group_len, Drop SAI_LIST indication:%d",
                        sai_indication.num_of_sai_per_group_len);
        goto err_ret;
      }

      camped_index = avail_index = 0;
      for (list_index = 0; list_index < sai_indication.num_of_sai_per_group_len; list_index ++)
      {
        sai_size = evt_info_ptr->payload.embms_info.embms_sai_info.freq_sai_list[list_index].sai_list_len;
        for(freq_index = 0; freq_index < sai_size; freq_index++)
        {
          sai_indication.available_sai_list[ avail_index ++ ] =
              evt_info_ptr->payload.embms_info.embms_sai_info.freq_sai_list[list_index].sai_list[freq_index];
          if(TRUE == evt_info_ptr->payload.embms_info.embms_sai_info.freq_sai_list[list_index].is_serving_frequency)
          {
            sai_indication.camped_sai_list[ camped_index ++ ] =
              evt_info_ptr->payload.embms_info.embms_sai_info.freq_sai_list[list_index].sai_list[freq_index];
          }
        }
        sai_indication.num_of_sai_per_group[list_index] = sai_size;
      }

      if(evt_info_ptr->payload.embms_info.embms_sai_info.tranx_id_valid)
      {
        sai_indication.dbg_trace_id = evt_info_ptr->payload.embms_info.embms_sai_info.tranx_id;
      }

      QCRIL_LOG_INFO( "EMBMS SAI list indication, available_sai_list_len: [%d],"
                      "camped_sai_list_len: [%d],"
                      "num_of_sai_per_group_len: [%d],"
                      "dbg_trace_id: [%d]",
                      sai_indication.available_sai_list_len,
                      sai_indication.camped_sai_list_len,
                      sai_indication.num_of_sai_per_group_len,
                      sai_indication.dbg_trace_id);

      unsigned int i;
      for (i = 0; i < sai_indication.available_sai_list_len; i++)
      {
         QCRIL_LOG_INFO("available_sai_list:%d", sai_indication.available_sai_list[i]);
      }
      for (i = 0; i < sai_indication.camped_sai_list_len; i++)
      {
         QCRIL_LOG_INFO("camped_sai_list:%d", sai_indication.camped_sai_list[i]);
      }
      for (i = 0; i < sai_indication.num_of_sai_per_group_len; i++)
      {
         QCRIL_LOG_INFO("num_of_sai_per_group:%d", sai_indication.num_of_sai_per_group[i]);
      }
      qcril_hook_unsol_response(instance_id,
                                QCRIL_EVT_HOOK_EMBMS_UNSOL_SAI_LIST,
                                (char*)&sai_indication,
                                sizeof(sai_indication));
    }
    break;

    case DSI_NET_TMGI_LIST_CHANGED:
    {
      QCRIL_LOG_INFO( ">>>DSI_NET_TMGI_LIST_CHANGED: START>>> cid [%d],"
                      "index [%d], list indication type [%d]",
                        info_tbl_ptr->cid,
                        info_tbl_ptr->index,
                        evt_info_ptr->payload.embms_info.embms_list_info.tmgi_list.list_type);

      if(evt_info_ptr->payload.embms_info.embms_list_info.tmgi_list_valid != TRUE)
      {
        QCRIL_LOG_ERROR( "invalid tmgi_list, Dropping TMGI list indication" );
        goto err_ret;
      }

      switch(evt_info_ptr->payload.embms_info.embms_list_info.tmgi_list.list_type)
      {
        case WDS_EMBMS_TMGI_LIST_ACTIVE_V01:
          {

            int index = 0;

            memset(&active_indication, 0, sizeof(active_indication));
            active_indication.tmgi_info_len =
              evt_info_ptr->payload.embms_info.embms_list_info.tmgi_list.tmgi_list_len;

            /* validate tmgi_info_len */
            if(active_indication.tmgi_info_len > NUMBER_MAX_V01)
            {
              QCRIL_LOG_ERROR( "Oversize tmgi_info_len, Dropping TMGI list indication:%d",
                                 active_indication.tmgi_info_len );
              goto err_ret;
            }

            for (index = 0; index < (int)active_indication.tmgi_info_len; index++)
            {
              active_indication.tmgi_info[index].tmgi_len = TMGI_LENGTH_MAX_V01;
              memcpy(&(active_indication.tmgi_info[index].tmgi),
                     &(evt_info_ptr->payload.embms_info.embms_list_info.tmgi_list.tmgi_list[index].tmgi),
                     TMGI_LENGTH_MAX_V01);
            }

            if(evt_info_ptr->payload.embms_info.embms_list_info.tranx_id_valid)
            {
              active_indication.dbg_trace_id =
                evt_info_ptr->payload.embms_info.embms_list_info.tranx_id;
            }

            QCRIL_LOG_INFO( "EMBMS ACTIVE list ind debug_id [%d], num TMGI's [%d]",
                            active_indication.dbg_trace_id, active_indication.tmgi_info_len);

            qcril_hook_unsol_response(instance_id,
                                      QCRIL_EVT_HOOK_EMBMS_UNSOL_ACTIVE_TMGI,
                                      (char*)&active_indication,
                                      sizeof(active_indication));
          }
          break;

        case WDS_EMBMS_TMGI_LIST_OOS_WARNING_V01:
          {
            int index = 0;
            embms_unsol_oos_warning_ind_msg_v01   oos_warning_ind;

            memset(&oos_warning_ind, 0, sizeof(oos_warning_ind));

            oos_warning_ind.tmgi_info_len =
              evt_info_ptr->payload.embms_info.embms_list_info.tmgi_list.tmgi_list_len;

            /* validate tmgi_info_len */
            if(oos_warning_ind.tmgi_info_len > NUMBER_MAX_V01)
            {
              QCRIL_LOG_ERROR( "Oversize tmgi_info_len, Dropping TMGI list indication:%d",
                                 oos_warning_ind.tmgi_info_len );
              goto err_ret;
            }

            for (index = 0; index < (int)oos_warning_ind.tmgi_info_len; index++)
            {
              oos_warning_ind.tmgi_info[index].tmgi_len = TMGI_LENGTH_MAX_V01;
              memcpy(&(oos_warning_ind.tmgi_info[index].tmgi),
                     &(evt_info_ptr->payload.embms_info.embms_list_info.tmgi_list.tmgi_list[index].tmgi),
                     TMGI_LENGTH_MAX_V01);
            }

            if(evt_info_ptr->payload.embms_info.embms_list_info.tranx_id_valid)
            {
              oos_warning_ind.dbg_trace_id =
                evt_info_ptr->payload.embms_info.embms_list_info.tranx_id;
            }
            oos_warning_ind.reason = evt_info_ptr->payload.embms_info.embms_list_info.warn_reason;

            QCRIL_LOG_INFO( "EMBMS OOS warning ind [%d], debug_id [%d] num TMGI's [%d]",
                            oos_warning_ind.reason,
                            oos_warning_ind.dbg_trace_id,
                            oos_warning_ind.tmgi_info_len);

            qcril_hook_unsol_response(instance_id,
                                      QCRIL_EVT_HOOK_EMBMS_UNSOL_OSS_WARNING,
                                      (char*)&oos_warning_ind,
                                      sizeof(oos_warning_ind));
          }
          break;

        case WDS_EMBMS_TMGI_LIST_AVAILABLE_V01:
          {
            embms_unsol_available_tmgi_ind_msg_v01 available_tmgi_list;
            int index = 0;

            memset(&available_tmgi_list, 0, sizeof(available_tmgi_list));
            available_tmgi_list.tmgi_info_len =
              evt_info_ptr->payload.embms_info.embms_list_info.tmgi_list.tmgi_list_len;

            /* validate tmgi_info_len */
            if(available_tmgi_list.tmgi_info_len > NUMBER_MAX_V01)
            {
              QCRIL_LOG_ERROR( "Oversize tmgi_info_len, Dropping TMGI list indication:%d",
                                 available_tmgi_list.tmgi_info_len );
              goto err_ret;
            }

            for (index = 0; index < (int)available_tmgi_list.tmgi_info_len; index++)
            {
              available_tmgi_list.tmgi_info[index].tmgi_len = TMGI_LENGTH_MAX_V01;
              memcpy(&(available_tmgi_list.tmgi_info[index].tmgi),
                     &(evt_info_ptr->payload.embms_info.embms_list_info.tmgi_list.tmgi_list[index].tmgi),
                     TMGI_LENGTH_MAX_V01);
            }

            if(evt_info_ptr->payload.embms_info.embms_list_info.tranx_id_valid)
            {
              available_tmgi_list.dbg_trace_id = evt_info_ptr->payload.embms_info.embms_list_info.tranx_id;
            }

            QCRIL_LOG_INFO( "EMBMS AVAILABLE list ind debug_id [%d], num TMGI's [%d]",
                            available_tmgi_list.dbg_trace_id, available_tmgi_list.tmgi_info_len);

            qcril_hook_unsol_response(instance_id,
                                      QCRIL_EVT_HOOK_EMBMS_UNSOL_AVAILABLE_TMGI,
                                      (char*)&available_tmgi_list,
                                      sizeof(available_tmgi_list));
          }
          break;

        default:
          break;
      }
    }
    break;

    case DSI_NET_TMGI_DEACTIVATED:
    {
      /* When this event arrives, we extract the first node from
      ** the pending request list, which has matching TMGI. Then
      ** based on what the pending request was, we process the event
      ** as a success or a failure response.
      */
      qcril_data_embms_tmgi_requests_type  *txn;

      QCRIL_LOG_INFO( ">>>DSI_NET_TMGI_DEACTIVATED: START>>> cid [%d], index [%d]",
                      info_tbl_ptr->cid, info_tbl_ptr->index );

      for (txn  = (qcril_data_embms_tmgi_requests_type *) list_peek_front (&info_tbl_ptr->embms_txns_list);
           txn != NULL;
           txn  = (qcril_data_embms_tmgi_requests_type *)
                    list_peek_next (&info_tbl_ptr->embms_txns_list, &(txn->link)))
      {
        if (txn->pend_req == QCRIL_EVT_HOOK_EMBMS_DEACTIVATE_TMGI)
        {
          QCRIL_LOG_DEBUG( "%s", "DEACTIVATED EVENT, TMGI match occured");
          if ((memcmp(txn->deact_tmgi,
                      evt_info_ptr->payload.embms_info.embms_deact_info.tmgi.tmgi,
                      QCRIL_DATA_EMBMS_TMGI_LEN)) == 0)
          {
            QCRIL_LOG_DEBUG( "%s", "DEACTIVATED EVENT, pending request match occured");

            /* prepare response deactivate_resp */
            memset ( &deactivate_response, 0, sizeof( deactivate_response ) );
            deactivate_response.call_id_valid   = TRUE;
            deactivate_response.call_id         = info_tbl_ptr->cid;
            deactivate_response.tmgi_info_valid = TRUE;
            deactivate_response.tmgi_info.tmgi_len = TMGI_LENGTH_MAX_V01;
            memcpy(&(deactivate_response.tmgi_info.tmgi[0]),
                   evt_info_ptr->payload.embms_info.embms_deact_info.tmgi.tmgi,
                   TMGI_LENGTH_MAX_V01);

            if(evt_info_ptr->payload.embms_info.embms_deact_info.tranx_id_valid)
            {
              deactivate_response.dbg_trace_id = evt_info_ptr->payload.embms_info.embms_deact_info.tranx_id;
            }
            qcril_default_request_resp_params( instance_id,
                                               txn->pend_tok,
                                               QCRIL_EVT_HOOK_EMBMS_DEACTIVATE_TMGI,
                                               RIL_E_SUCCESS,/* revisit on error code */
                                               &resp );

            list_pop_item( &info_tbl_ptr->embms_txns_list, &txn->link );
            QCRIL_DATA_RELEASE_STORAGE( txn );
            QCRIL_LOG_DEBUG( "%s", "deleted tmgi txn");

            resp.resp_pkt = &deactivate_response;
            resp.resp_len = sizeof( deactivate_response );
            qcril_send_request_response( &resp );
            goto ret;
          }/* if(txn->pend_req == QCRIL_EVT_HOOK_EMBMS_DEACTIVATE_TMGI) */
        }/* if(memcmp(deactivate_tmgi_list)*/
        else if(txn->pend_req == QCRIL_EVT_HOOK_EMBMS_ACTIVATE_TMGI)
        {
          QCRIL_LOG_DEBUG("%s", "DEACTIVATED_EVENT, TMGI match occured");
          if((memcmp(txn->tmgi,
              evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi,
              QCRIL_DATA_EMBMS_TMGI_LEN)) == 0)
          {
            QCRIL_LOG_DEBUG("%s", "DEACTIVATED EVENT, pending activate request match occured");
            QCRIL_LOG_DEBUG( "%s", "Request to Activate TMGI failed");
            memset (&activate_response, 0, sizeof( activate_response));
            activate_response.call_id_valid = TRUE;
            activate_response.call_id       = info_tbl_ptr->cid;
            activate_response.tmgi_info_valid = TRUE;
            activate_response.tmgi_info.tmgi_len = TMGI_LENGTH_MAX_V01;
            memcpy(&(activate_response.tmgi_info.tmgi[0]),
                   evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi,
                   TMGI_LENGTH_MAX_V01);

            if(evt_info_ptr->payload.embms_info.embms_act_info.tranx_id_valid)
            {
              activate_response.dbg_trace_id = evt_info_ptr->payload.embms_info.embms_act_info.tranx_id;
            }
            if(SUCCESS != qcril_data_utils_embms_get_ril_status_code(
              (int)evt_info_ptr->payload.embms_info.embms_act_info.activate_status,
              (int *)&activate_response.resp_code))
            {
              QCRIL_LOG_ERROR("%s", "Unable to get activate error status code ");
              activate_response.resp_code = QCRIL_DATA_EMBMS_ERROR_UNKNOWN;
            }
            qcril_default_request_resp_params( instance_id,
                                               txn->pend_tok,
                                               QCRIL_EVT_HOOK_EMBMS_ACTIVATE_TMGI,
                                               RIL_E_GENERIC_FAILURE,/* revisit on error code */
                                               &resp );
            list_pop_item( &info_tbl_ptr->embms_txns_list, &txn->link );
            QCRIL_DATA_RELEASE_STORAGE( txn );
            QCRIL_LOG_DEBUG( "%s", "deleted tmgi txn");

            resp.resp_pkt = &activate_response;
            resp.resp_len = sizeof( activate_response );

            qcril_send_request_response( &resp );
            goto ret;
          }/* if(txn->pend_req == QCRIL_EVT_HOOK_EMBMS_ACTIVATE_TMGI */
        }/* if(memcmp tmgi_list) */
      }/* for */

      QCRIL_LOG_ERROR("%s", "Processed DSI_NET_TMGI_DEACTIVATED, "
                      "TMGI not found, Dropping Indication");
      goto err_ret;
    }
    break;

    case DSI_NET_TMGI_ACTIVATED_DEACTIVATED:
    {
      qcril_data_embms_tmgi_requests_type *txn;
      embms_activate_deactivate_tmgi_resp_msg_v01 act_deact_resp;
      RIL_Errno err_no = RIL_E_SUCCESS;

      QCRIL_LOG_INFO( ">>>DSI_NET_TMGI_ACTIVATED_DEACTIVATED: START>>> cid [%d], index [%d]",
                      info_tbl_ptr->cid, info_tbl_ptr->index);

      txn = (qcril_data_embms_tmgi_requests_type *) list_peek_front (&info_tbl_ptr->embms_txns_list);

      while(txn != NULL)
      {
        if((memcmp(txn->tmgi,
                   evt_info_ptr->payload.embms_info.embms_act_deact_info.act_tmgi.tmgi,
                   QCRIL_DATA_EMBMS_TMGI_LEN) == 0) &&
           (memcmp(txn->deact_tmgi,
                   evt_info_ptr->payload.embms_info.embms_act_deact_info.deact_tmgi.tmgi,
                   QCRIL_DATA_EMBMS_TMGI_LEN) == 0)
           )
        {
          QCRIL_LOG_DEBUG("%s", "ACTIVATED_DEACTIVATED EVENT, TMGI match occured");
          if(txn->pend_req == QCRIL_EVT_HOOK_EMBMS_ACTIVATE_DEACTIVATE_TMGI)
          {
            QCRIL_LOG_DEBUG("%s", "ACTIVATED_DEACTIVATED EVENT, Pending request matched");

            /* prepare activate_deactivate response */
            memset(&act_deact_resp, 0, sizeof(act_deact_resp));
            act_deact_resp.call_id_valid = TRUE;
            act_deact_resp.call_id = info_tbl_ptr->cid;

            act_deact_resp.act_tmgi_info_valid = TRUE;
            act_deact_resp.act_tmgi_info.tmgi_len = TMGI_LENGTH_MAX_V01;
            memcpy(&act_deact_resp.act_tmgi_info.tmgi[0],
                   evt_info_ptr->payload.embms_info.embms_act_deact_info.act_tmgi.tmgi,
                   TMGI_LENGTH_MAX_V01);
            act_deact_resp.deact_tmgi_info_valid = TRUE;
            act_deact_resp.deact_tmgi_info.tmgi_len = TMGI_LENGTH_MAX_V01;
            memcpy(&act_deact_resp.deact_tmgi_info.tmgi[0],
                   evt_info_ptr->payload.embms_info.embms_act_deact_info.deact_tmgi.tmgi,
                   TMGI_LENGTH_MAX_V01);

            if(evt_info_ptr->payload.embms_info.embms_act_deact_info.tranx_id_valid ==  TRUE)
            {
              act_deact_resp.dbg_trace_id = evt_info_ptr->payload.embms_info.embms_act_deact_info.tranx_id;
            }

            if((WDS_TMGI_ACTIVATE_SUCCESS_V01 ==
                evt_info_ptr->payload.embms_info.embms_act_deact_info.act_status) &&
               (WDS_TMGI_DEACTIVATE_SUCCESS_V01 ==
                evt_info_ptr->payload.embms_info.embms_act_deact_info.deact_status)
               )
            {
              err_no = RIL_E_SUCCESS;
            }
            else
            {
              if(SUCCESS != qcril_data_utils_embms_get_ril_status_code(
                evt_info_ptr->payload.embms_info.embms_act_deact_info.act_status,
                (int *)&act_deact_resp.act_resp_code))
              {
                QCRIL_LOG_ERROR("%s", "Unable to get activate error status code ");
                act_deact_resp.act_resp_code = QCRIL_DATA_EMBMS_ERROR_UNKNOWN;
              }
              err_no = RIL_E_GENERIC_FAILURE;
            }

            qcril_default_request_resp_params(instance_id,
                                              txn->pend_tok,
                                              QCRIL_EVT_HOOK_EMBMS_ACTIVATE_DEACTIVATE_TMGI,
                                              err_no,
                                              &resp);
            list_pop_item( &info_tbl_ptr->embms_txns_list, &txn->link );
            QCRIL_DATA_RELEASE_STORAGE( txn );
            QCRIL_LOG_DEBUG( "%s", "deleted tmgi txn");

            resp.resp_pkt = &act_deact_resp;
            resp.resp_len = sizeof( act_deact_resp );
            qcril_send_request_response( &resp );

            goto ret;

          }/* pend_req == QCRIL_EVT_HOOK_EMBMS_ACTIVATE_DEACTIVATE_TMGI*/
        }/* memcpy */

        txn  = (qcril_data_embms_tmgi_requests_type *)
                    list_peek_next (&info_tbl_ptr->embms_txns_list, &(txn->link));
      }/* while */
      QCRIL_LOG_ERROR("%s", "Processed DSI_NET_TMGI_ACTIVATED_DEACTIVATED, "
                      "TMGI not found, Dropping Indication");
      goto err_ret;
    }
    break;

    case DSI_NET_TMGI_ACTIVATED:
    {
      qcril_data_embms_tmgi_requests_type  *txn;

      QCRIL_LOG_INFO( ">>>DSI_NET_TMGI_ACTIVATED: START>>> cid [%d], index [%d]",
                      info_tbl_ptr->cid, info_tbl_ptr->index );

      txn  = (qcril_data_embms_tmgi_requests_type *) list_peek_front (&info_tbl_ptr->embms_txns_list);

      while(txn != NULL)
      {
        if ((memcmp(txn->tmgi,
                   evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi,
                   QCRIL_DATA_EMBMS_TMGI_LEN)) == 0)
        {
          QCRIL_LOG_DEBUG( "%s", "ACTIVATED EVENT, TMGI match occured");
          if (txn->pend_req == QCRIL_EVT_HOOK_EMBMS_ACTIVATE_TMGI)
          {
            QCRIL_LOG_DEBUG( "%s", "ACTIVATED EVENT, Pending request matched");
            /* prepare activate response */
            memset ( &activate_response, 0, sizeof( activate_response ) );
            activate_response.call_id_valid   = TRUE;
            activate_response.call_id         = info_tbl_ptr->cid;
            activate_response.tmgi_info_valid = TRUE;
            activate_response.tmgi_info.tmgi_len = TMGI_LENGTH_MAX_V01;
            memcpy(&activate_response.tmgi_info.tmgi[0],
                   evt_info_ptr->payload.embms_info.embms_act_info.tmgi.tmgi,
                   TMGI_LENGTH_MAX_V01);
            if(evt_info_ptr->payload.embms_info.embms_act_info.tranx_id_valid == TRUE)
            {
              activate_response.dbg_trace_id =
                evt_info_ptr->payload.embms_info.embms_act_info.tranx_id;
            }
            qcril_default_request_resp_params( instance_id,
                                               txn->pend_tok,
                                               QCRIL_EVT_HOOK_EMBMS_ACTIVATE_TMGI,
                                               RIL_E_SUCCESS,/* revisit on error code */
                                               &resp );

            list_pop_item( &info_tbl_ptr->embms_txns_list, &txn->link );
            QCRIL_DATA_RELEASE_STORAGE( txn );
            QCRIL_LOG_DEBUG( "%s", "deleted tmgi txn");

            resp.resp_pkt = &activate_response;
            resp.resp_len = sizeof( activate_response );
            qcril_send_request_response( &resp );

            goto ret;
          }
          else if (txn->pend_req == QCRIL_EVT_HOOK_EMBMS_DEACTIVATE_TMGI)
          {

            QCRIL_LOG_ERROR( "%s", "Activated received when expecting a "
                                   "deactivated indication, Dropping Indication");
            break;
          }
        }
        txn  = (qcril_data_embms_tmgi_requests_type *)
                    list_peek_next (&info_tbl_ptr->embms_txns_list, &(txn->link));
      }
      QCRIL_LOG_ERROR("%s", "Processed DSI_NET_TMGI_ACTIVATED, "
                      "TMGI not found, Dropping Indication");
      goto err_ret;
    }
    break;

    case DSI_NET_CONTENT_DESC_CONTROL:
    {
      embms_unsol_content_desc_update_per_obj_ind_msg_v01 content_desc_ctrl_ind;

      QCRIL_LOG_INFO(">>>DSI_NET_CONTENT_DESC_CONTROL: START>>> cid [%d],"
                     "index [%d]",
                     info_tbl_ptr->cid,
                     info_tbl_ptr->index);

      memset(&content_desc_ctrl_ind, 0, sizeof(content_desc_ctrl_ind));

      memcpy(&(content_desc_ctrl_ind.tmgi_info.tmgi),
             &(evt_info_ptr->payload.embms_info.embms_content_desc_info.tmgi.tmgi),
             TMGI_LENGTH_MAX_V01);

      content_desc_ctrl_ind.tmgi_info.tmgi_len = TMGI_LENGTH_MAX_V01;
      if(evt_info_ptr->payload.embms_info.embms_content_desc_info.tranx_id_valid)
      {
        content_desc_ctrl_ind.dbg_trace_id = evt_info_ptr->payload.embms_info.embms_content_desc_info.tranx_id;
      }

      if (evt_info_ptr->payload.embms_info.embms_content_desc_info.content_control_valid)
      {
        content_desc_ctrl_ind.per_object_content_ctrl_valid = TRUE;
        content_desc_ctrl_ind.per_object_content_ctrl =
            evt_info_ptr->payload.embms_info.embms_content_desc_info.content_control;
      }
      if (evt_info_ptr->payload.embms_info.embms_content_desc_info.status_control_valid)
      {
        content_desc_ctrl_ind.per_object_status_ctrl_valid = TRUE;
        content_desc_ctrl_ind.per_object_status_ctrl =
            evt_info_ptr->payload.embms_info.embms_content_desc_info.status_control;
      }

      QCRIL_LOG_INFO( "EMBMS content desc control indication, "
                      "status_control: [%d], valid: [%d]"
                      "content_control: [%d], valid: [%d]"
                      "dbg_trace_id: [%d]"
                      "tmgi_list: %d:[%X,%X,%X,%X,%X,%X]",
                      content_desc_ctrl_ind.per_object_status_ctrl,
                        content_desc_ctrl_ind.per_object_status_ctrl_valid,
                      content_desc_ctrl_ind.per_object_content_ctrl,
                        content_desc_ctrl_ind.per_object_content_ctrl_valid,
                      content_desc_ctrl_ind.dbg_trace_id,
                      content_desc_ctrl_ind.tmgi_info.tmgi_len,
                      content_desc_ctrl_ind.tmgi_info.tmgi[0],
                      content_desc_ctrl_ind.tmgi_info.tmgi[1],
                      content_desc_ctrl_ind.tmgi_info.tmgi[2],
                      content_desc_ctrl_ind.tmgi_info.tmgi[3],
                      content_desc_ctrl_ind.tmgi_info.tmgi[4],
                      content_desc_ctrl_ind.tmgi_info.tmgi[5]);

      qcril_hook_unsol_response(instance_id,
                                QCRIL_EVT_HOOK_EMBMS_UNSOL_CONTENT_DESC_CONTROL,
                                (char*)&content_desc_ctrl_ind,
                                sizeof(content_desc_ctrl_ind));
    }
    break;

    case DSI_NET_TMGI_SERVICE_INTERESTED:
    {
      embms_unsol_get_interested_tmgi_list_req_msg_v01 get_interested_tmgi_list;

      QCRIL_LOG_INFO(">>>DSI_NET_TMGI_SERVICE_INTERESTED: START>>> cid [%d],"
                     "index [%d]",
                     info_tbl_ptr->cid,
                     info_tbl_ptr->index);

      memset(&get_interested_tmgi_list, 0, sizeof(get_interested_tmgi_list));

      if(evt_info_ptr->payload.embms_info.embms_svc_interest_info.tranx_id_valid)
      {
        get_interested_tmgi_list.dbg_trace_id =
            evt_info_ptr->payload.embms_info.embms_svc_interest_info.tranx_id;
      }

      QCRIL_LOG_INFO("EMBMS get interested TMGI list, dbg_trace_id: [%d]",
                     get_interested_tmgi_list.dbg_trace_id);

      qcril_hook_unsol_response(instance_id,
                                QCRIL_EVT_HOOK_EMBMS_UNSOL_GET_INTERESTED_TMGI_LIST,
                                (char*)&get_interested_tmgi_list,
                                sizeof(get_interested_tmgi_list));
    }
    break;

    default:
      QCRIL_LOG_ERROR("Unknown embms event received [%d]", evt_info_ptr->evt);
      break;

  } /*switch(evt_info_ptr->evt)*/

ret:
  switch(evt_info_ptr->evt)
  {
    case DSI_NET_TMGI_ACTIVATED:
      {
        QCRIL_LOG_INFO( "%s", "<<<DSI_NET_TMGI_ACTIVATED: DONE<<<" );
      }
      break;
    case DSI_NET_TMGI_DEACTIVATED:
      {
        QCRIL_LOG_INFO( "%s", "<<<DSI_NET_TMGI_DEACTIVATED: DONE<<<" );
      }
      break;
    case DSI_NET_TMGI_ACTIVATED_DEACTIVATED:
      {
        QCRIL_LOG_INFO("%s", "<<<DSI_NET_TMGI_ACTIVATED_DEACTIVATED: DONE<<<");
      }
      break;
    case DSI_NET_SAI_LIST_CHANGED:
      {
        QCRIL_LOG_DEBUG("%s", "<<<RIL UNSOL RSP SENT<<<");
        QCRIL_LOG_INFO("%s", "<<<DSI_NET_SAI_LIST_CHANGED: DONE<<<");
      }
      break;
    case DSI_NET_TMGI_LIST_CHANGED:
      {
         QCRIL_LOG_DEBUG( "%s", "<<<RIL UNSOL RSP SENT<<<" );
         QCRIL_LOG_INFO( "%s", "<<<DSI_NET_TMGI_LIST_CHANGED: DONE<<<" );
      }
      break;
    case DSI_NET_CONTENT_DESC_CONTROL:
      {
         QCRIL_LOG_DEBUG( "%s", "<<<RIL UNSOL RSP SENT<<<" );
         QCRIL_LOG_INFO( "%s", "<<<DSI_NET_CONTENT_DESC_CONTROL: DONE<<<" );
      }
      break;
    case DSI_NET_TMGI_SERVICE_INTERESTED:
      {
         QCRIL_LOG_DEBUG( "%s", "<<<RIL UNSOL RSP SENT<<<" );
         QCRIL_LOG_INFO( "%s", "<<<DSI_NET_TMGI_SERVICE_INTERESTED: DONE<<<" );
      }
      break;
    default:
      break;
  }

  QCRIL_LOG_DEBUG("%s", "Print List and its entries");

  if (DSI_NET_TMGI_ACTIVATED == evt_info_ptr->evt ||
      DSI_NET_TMGI_DEACTIVATED == evt_info_ptr->evt ||
      DSI_NET_TMGI_ACTIVATED_DEACTIVATED == evt_info_ptr->evt)
  {
    for (tmgi_txn  = (qcril_data_embms_tmgi_requests_type *) list_peek_front (&info_tbl_ptr->embms_txns_list);
         tmgi_txn != NULL;
         tmgi_txn  = (qcril_data_embms_tmgi_requests_type *)
                      list_peek_next (&info_tbl_ptr->embms_txns_list, &(tmgi_txn->link)))
    {
      QCRIL_LOG_DEBUG(" request:%s, and token:%d, TMGI:%x%x%x%x%x%x DEACT_TMGI:%x%x%x%x%x%x into the transactions list",
                      qcril_log_lookup_event_name(tmgi_txn->pend_req),
                      qcril_log_get_token_id(tmgi_txn->pend_tok ),
                      tmgi_txn->tmgi[0],
                      tmgi_txn->tmgi[1],
                      tmgi_txn->tmgi[2],
                      tmgi_txn->tmgi[3],
                      tmgi_txn->tmgi[4],
                      tmgi_txn->tmgi[5],
                      tmgi_txn->deact_tmgi[0],
                      tmgi_txn->deact_tmgi[1],
                      tmgi_txn->deact_tmgi[2],
                      tmgi_txn->deact_tmgi[3],
                      tmgi_txn->deact_tmgi[4],
                      tmgi_txn->deact_tmgi[5]);
    }
  }

err_ret:
  return;
}


#endif /* FEATURE_DATA_EMBMS */

