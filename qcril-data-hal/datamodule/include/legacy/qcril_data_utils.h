/*!
  @file
  qcril_data_utils.h

  @brief
  Handles utility functions of RIL requests for DATA services.

*/

/*===========================================================================
    Copyright (c) 2011-2016 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

when       who     what, where, why
--------   ---     ----------------------------------------------------------
10/17/11   sy     Initial version

===========================================================================*/

#ifndef QCRIL_DATA_UTILS_H
#define QCRIL_DATA_UTILS_H

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include "qcril_data_defs.h"
#include "qcril_data.h"

/*===========================================================================

                   INTERNAL DEFINITIONS AND TYPES

===========================================================================*/
#define CALL_ID_INVALID           (-1)
#define QCRIL_DATA_HNDL_INVALID   (NULL)
#define QCRIL_DSI_HNDL_INVALID    (NULL)
#define QCRIL_INVALID_PROFILE_ID  (-1)
#define QCRIL_INVALID_BEARER_ID   (-1)

#define QCRIL_DATA_INVALID_TIMERID      (0)

#define QCRIL_DATA_INVALID_INSTANCE_ID  (QCRIL_MAX_INSTANCE_ID)
#define QCRIL_DATA_INVALID_MODEM_ID     (0xFFFFFFFF)

/* Error codes */
#define SUCCESS  (0)
#define FAILURE  (-1)

#ifdef FEATURE_DATA_EMBMS

#define QCRIL_DATA_EMBMS_ERROR_NONE                    0
#define QCRIL_DATA_EMBMS_ERROR_UNKNOWN                 1
#define QCRIL_DATA_EMBMS_ERROR_ALREADY_DONE            2
#define QCRIL_DATA_EMBMS_ERROR_NOT_ALLOWED             3
#define QCRIL_DATA_EMBMS_ERROR_MISSING_CONTROL_INFO    4
#define QCRIL_DATA_EMBMS_ERROR_MISSING_TMGI            5
#define QCRIL_DATA_EMBMS_ERROR_MCAST_OOC               6
#define QCRIL_DATA_EMBMS_ERROR_UCAST_OOS               7
#define QCRIL_DATA_EMBMS_ERROR_FREQUENCY_CONFLICT      8
#define QCRIL_DATA_EMBMS_ERROR_MAX_TMGI_ALREADY_ACTIVE 9
#define QCRIL_DATA_EMBMS_SUCCESS_RADIO_TUNE_IN_PROGRESS_UCAST_IDLE 100
#define QCRIL_DATA_EMBMS_SUCCESS_RADIO_TUNE_IN_PROGRESS_UCAST_CONNECTED 101
#endif /* FEATUER_DATA_EMBMS */


#define QCRIL_DATA_IS_DATA_SYS_STATUS_RAT_MASK_3GPP2_1X_DO(nw,rat,so) ((nw == WDS_SYS_NETWORK_3GPP2_V01) &&                                            \
                                                                       ((rat == QMI_WDS_MASK_RAT_CDMA_1X_V01) ||                                                                  \
                                                                        ((rat == QMI_WDS_MASK_RAT_EVDO_REVA_V01) && (so != QMI_WDS_MASK_SO_EVDO_REVA_EMPA_EHRPD_V01)) ||  \
                                                                        ((rat == QMI_WDS_MASK_RAT_EVDO_REVB_V01) && ((so != QMI_WDS_MASK_SO_EVDO_REVB_EMPA_EHRPD_V01)     \
                                                                                                    && (so != QMI_WDS_MASK_SO_EVDO_REVB_MMPA_EHRPD_V01)))))

#define QCRIL_DATA_IS_DATA_SYS_STATUS_RAT_MASK_3GPP2_EHRPD(nw,rat,so) ((nw == WDS_SYS_NETWORK_3GPP2_V01) &&                                             \
                                                                       ((rat == QMI_WDS_MASK_RAT_EHRPD_V01) ||                                                                \
                                                                        ((rat == QMI_WDS_MASK_RAT_EVDO_REVA_V01) && (so == QMI_WDS_MASK_SO_EVDO_REVA_EMPA_EHRPD_V01)) ||   \
                                                                        ((rat == QMI_WDS_MASK_RAT_EVDO_REVB_V01) && ((so == QMI_WDS_MASK_SO_EVDO_REVB_EMPA_EHRPD_V01)      \
                                                                                                     || (so == QMI_WDS_MASK_SO_EVDO_REVB_MMPA_EHRPD_V01)))))

/*===========================================================================

                         GLOBAL VARIABLES

===========================================================================*/

extern qcril_data_call_info_tbl_type info_tbl[ MAX_CONCURRENT_UMTS_DATA_CALLS ];

/* Table containing the state for handling dsi callbacks */
extern qcril_data_dsi_cb_tbl_type dsi_cb_tbl[ MAX_CONCURRENT_UMTS_DATA_CALLS ];

typedef struct qcril_data_ce_map_s
{
  int ril_data_ce_code;
  int qmi_data_ce_code;
  dsi_ce_reason_type_t reason_category;
} qcril_data_ce_map;

extern qcril_data_ce_map qcril_data_ce_map_tbl[];

#ifdef FEATURE_DATA_EMBMS
typedef struct qcril_data_embms_status_s
{
  int ril_embms_status_code;
  int qmi_embms_status_code;
}qcril_data_embms_status_map;

extern qcril_data_embms_status_map qcril_data_embms_status_map_tbl[];
#endif

/*===========================================================================

                    INTERNAL FUNCTION PROTOTYPES

===========================================================================*/

/*===========================================================================

                    EXTERNAL FUNCTION PROTOTYPES

===========================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

void qcril_data_cleanup_call_state
(
  qcril_data_call_info_tbl_type *info_tbl_ptr
);

void qcril_data_update_dsi_cb_tbl_entry
(
  qcril_data_dsi_cb_tbl_type *dsi_cb_tbl_ptr,
  qcril_instance_id_e_type   instance_id,
  qcril_modem_id_e_type      modem_id,
  RIL_Token                  pend_tok,
  dsi_hndl_t                 dsi_hndl,
  qcril_data_call_info_tbl_type *info_tbl_ptr
);

void qcril_data_clear_dsi_cb_tbl_entry
(
  qcril_data_dsi_cb_tbl_type *dsi_cb_tbl_ptr
);

void qcril_data_util_update_call_state
(
  qcril_data_call_info_tbl_type *info_tbl_ptr,
  int call_state,
  int status
);

void qcril_data_util_update_partial_retry_enabled_flag
(
   void
);

void qcril_data_util_update_max_partial_retry_timeout
(
  void
);

#if (QCRIL_RIL_VERSION >= 6)
boolean qcril_data_util_get_dual_ip_call_status
(
  qcril_data_call_info_tbl_type  *info_tbl_ptr,
  int                            *err_code
);
#endif

int qcril_data_get_ril_ce_code
(
  dsi_ce_reason_t * dsi_ce_reasion,
  int * ril_ce_code
);

#ifdef FEATURE_DATA_EMBMS
int qcril_data_utils_embms_copy_tmgi_list
(
  wds_embms_tmgi_type_v01 **tmgi_list_ptr_to,
  wds_embms_tmgi_type_v01  *tmgi_list_ptr_from,
  unsigned char            len
);
int qcril_data_utils_embms_get_ril_status_code
(
  int   qmi_status,
  int * ril_status
);

#endif /* FEATURE_DATA_EMBMS */

void qcril_data_util_stop_timer
(
  timer_t *timer_id
);

void qcril_data_util_disarm_timer
(
  timer_t  *timer_id
);

int qcril_data_get_ifindex
(
  const char * dev, int * ifindex
);

const char *
qcril_data_util_get_ril_tech_string
(
  qcril_data_ril_radio_tech_t  ril_tech
);

const char *
qcril_data_util_get_dsi_bearer_tech_string
(
  dsi_data_bearer_tech_t  dsi_bearer_tech
);

void qcril_data_get_active_call_list
(
  void                 **response,
  size_t                *response_len
);

int
qcril_data_util_is_partial_retry_allowed
(
  qcril_data_call_info_tbl_type  *info_tbl_ptr
);

void qcril_data_util_schedule_partial_retry_attempt
(
  qcril_data_call_info_tbl_type  *info_tbl_ptr,
  boolean                        check_teth_state,
  boolean                        check_ce_reason
);

void qcril_data_util_reinitiate_partial_retry
(
  boolean  check_teth_state,
  boolean  check_ce_reason
);

boolean qcril_data_util_data_sys_status_changed
(
  wds_data_system_status_type_v01 *curr_sys_status,
  wds_data_system_status_type_v01 *new_sys_status
);

boolean qcril_data_util_is_new_rat_1x_ehrpd
(
  wds_data_system_status_type_v01 *new_sys_status,
  wds_sys_network_info_type_v01  **nw_info
);

/*===========================================================================*/
/*!
    @brief
    Query UL/DL bearer type using QMI
*/
/*=========================================================================*/
int qcril_data_util_query_bearer_type
(
  qcril_data_call_info_tbl_type  *info_tbl_ptr,
  qmi_client_type qmi_wds_hndl,
  int16_t bearerId
);

/*===========================================================================*/
/*!
    @brief
    Register QMI WDS indication for extended IP config and data bearer type
    when data is connected per PDN and query to update whenever there is change
    in extended IP config or UL/DL bearer type
*/
/*=========================================================================*/
void qcril_data_util_register_ind_data_params
(
  qcril_data_call_info_tbl_type  *info_tbl_ptr,
  qmi_client_type qmi_wds_hndl
);

void qcril_data_util_register_ind_and_query_data_params
(
  qcril_data_call_info_tbl_type  *info_tbl_ptr
);

int qcril_data_get_dsi_ip_version
(
  dsi_hndl_t dsi_hndl
);

void qcril_data_util_fill_pcscf_addr
(
  qcril_data_call_info_tbl_type *info_tbl_ptr
);

boolean qcril_data_util_is_ce_failure_permanent
(
  int  ril_ce_reason
);

#if (QCRIL_RIL_VERSION >= 15)
void qcril_data_ma_ka_send_unsol(uint32_t handle,
  RIL_KeepaliveStatusCode status_code);

void qcrili_data_ma_ka_cleanup(const int cid);

void qcril_data_ma_ka_send_succ_resp(
  uint32_t handle,
  RIL_Token t,
  qcril_evt_e_type request_type,
  qcril_data_ma_ka_status_t status
  );
#endif /* (QCRIL_RIL_VERSION >= 15) */

#ifdef __cplusplus
}
#endif
#endif /* QCRIL_DATA_UTILS_H */
