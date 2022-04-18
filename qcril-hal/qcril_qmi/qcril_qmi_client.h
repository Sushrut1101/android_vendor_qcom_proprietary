/******************************************************************************
#  Copyright (c) 2009-2013, 2017 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#******************************************************************************/
/*!
  @file
  qcril_qmi_client.h

  @brief

*/


/*===========================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ----------------------------------------------------------
08/06/10   sk      Initial Changes

===========================================================================*/

#ifndef QCRIL_QMI_CLIENT_H
#define QCRIL_QMI_CLIENT_H

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include "qmi_client_instance_defs.h"

#ifdef QMI_RIL_UTF
#include "qmi_cci_target_ext.h"
#endif

//#include "qmi.h"
//#include "qmi_client.h"
#include "common_v01.h"
#include "voice_service_v02.h"
#include "qcrili.h"
#ifdef __cplusplus
#include <QtiMutex.h>
#endif


/*===========================================================================

                        DEFINITIONS AND TYPES

===========================================================================*/

#ifdef FEATURE_TARGET_GLIBC_x86
   #define QCRIL_QMI_SYNC_REQ_DEF_TIMEOUT                 (1000)
#else
   #define QCRIL_QMI_SYNC_REQ_DEF_TIMEOUT                 (500)
#endif

#define QCRIL_QMI_SYNC_REQ_UNRESTRICTED_TIMEOUT        (30000)

#define MODEM_RESTART_REASON_DEFAULT "Modem Restart"

typedef enum
{
  QCRIL_QMI_CLIENT_FIRST,
  QCRIL_QMI_CLIENT_VOICE = QCRIL_QMI_CLIENT_FIRST,
  QCRIL_QMI_CLIENT_NAS,
  QCRIL_QMI_CLIENT_WMS,
  QCRIL_QMI_CLIENT_WDS,
  QCRIL_QMI_CLIENT_DMS,
  QCRIL_QMI_CLIENT_UIM,
  QCRIL_QMI_CLIENT_PBM,
  QCRIL_QMI_CLIENT_RF_SAR,
  QCRIL_QMI_CLIENT_IMS_VT,
  QCRIL_QMI_CLIENT_IMS_PRESENCE,
  QCRIL_QMI_CLIENT_IMSA,
  QCRIL_QMI_CLIENT_RFPE,
  QCRIL_QMI_CLIENT_IMS_SETTING,
  QCRIL_QMI_CLIENT_PDC,
  QCRIL_QMI_CLIENT_DSD,
  QCRIL_QMI_CLIENT_LTE,
  QCRIL_QMI_CLIENT_LAST,
  QCRIL_QMI_CLIENT_MAX = QCRIL_QMI_CLIENT_LAST
} qcril_qmi_client_e_type;

typedef enum
{
    QCRIL_QMI_SERVICE_NOT_CONNECTED,
    QCRIL_QMI_SERVICE_CONNECTED,
    QCRIL_QMI_SERVICE_NOT_AVAILABLE,
    QCRIL_QMI_SERVICE_AVAILABLE,
    QCRIL_QMI_SERVICE_MAX
} qcril_qmi_service_conection_state;

#ifdef __cplusplus
typedef struct
{
  int qmi_init_handle;
  qmi_idl_service_object_type       service_objects[QCRIL_QMI_CLIENT_MAX];
  qmi_client_type                   qmi_svc_clients[QCRIL_QMI_CLIENT_MAX];
  qmi_client_os_params              os_params[QCRIL_QMI_CLIENT_MAX];
  //qmi_service_version_info          qmi_svc_versions[QCRIL_QMI_CLIENT_MAX];
  qmi_client_recv_msg_async_cb      client_cbs[QCRIL_QMI_CLIENT_MAX];
  qcril_qmi_service_conection_state client_state[QCRIL_QMI_CLIENT_MAX];
  int                               num_of_active_clients;
  int                               max_active_clients;
  qmi_client_type                   notifier[QCRIL_QMI_CLIENT_MAX];
  qtimutex::QtiSharedMutex            cache_lock_mutex;

  int qmi_client_init_complete;

  /* bit array of 32, so that each client can poll for connection state */
  unsigned long qcril_client_conn_state;
} qcril_qmi_client_private_info_type;
#endif

typedef enum
{
    QCRIL_QMI_ERR_CTX_NONE,
    QCRIL_QMI_ERR_CTX_DIAL_TXN,
    QCRIL_QMI_ERR_CTX_DIAL_VIDEO_TXN,
    QCRIL_QMI_ERR_CTX_SEND_SS_TXN,
    QCRIL_QMI_ERR_CTX_SEND_USSD_TXN,
    QCRIL_QMI_ERR_CTX_CELL_LOCATION_TXN,
    QCRIL_QMI_ERR_TOLERATE_NOT_READY,
    QCRIL_QMI_ERR_TOLERATE_NOT_FOUND,
    QCRIL_QMI_ERR_CTX_MNG_IP_TXN,
} qmi_ril_err_context_e_type;

typedef struct
{
  uint8_t                        cc_sups_result_valid;
  voice_cc_sups_result_type_v02* cc_sups_result;

  uint8_t cc_result_type_valid;
  voice_cc_result_type_enum_v02* cc_result_type;
} qmi_ril_err_ctx_ss_resp_data_type;

typedef struct
{
  qmi_client_type                user_handle;
  unsigned long                  msg_id;
  unsigned char                  *data_buf;
  int                            data_buf_len;
  void                           *cb_data;
} qmi_ind_callback_type;

typedef struct
{
  qmi_client_type               user_handle;
  unsigned long                 msg_id;
  void                          *data_buf;
  int                           data_buf_len;
  void                          *cb_data;
  qmi_client_error_type         transp_err;
} qmi_resp_callback_type;

#ifdef __cplusplus
typedef struct
{
   qtimutex::QtiSharedMutex                                   lock_mutex;
   qmi_ril_fw_android_request_kind_execution_overview_type* android_request_kind_info;
   int                                                      in_exec_on_main_thread;
   uint32_t                                                 common_moniker_book;
} qmi_ril_fw_android_request_flow_control_overview_type;

extern qmi_ril_fw_android_request_flow_control_overview_type qmi_ril_fw_android_request_flow_control_overview;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================

                    EXTERNAL FUNCTION PROTOTYPES

===========================================================================*/

RIL_Errno qcril_qmi_client_init( void );

void qcril_qmi_client_release
(
  void
);

RIL_Errno qcril_qmi_client_map_qmi_err_to_ril_err
(
  qmi_error_type_v01 err
);

errno_enum_type qcril_qmi_client_send_msg_async
(
  qcril_qmi_client_e_type        svc_type,
  unsigned long                msg_id,
  void                         *req_c_struct,
  int                          req_c_struct_len,
  void                         *resp_c_struct,
  int                          resp_c_struct_len,
  void                         *resp_cb_data
);

RIL_Errno qcril_qmi_client_send_msg_async_ex
(
  qcril_qmi_client_e_type      svc_type,
  unsigned long                msg_id,
  void                         *req_c_struct,
  int                          req_c_struct_len,
  void                         *resp_c_struct,
  int                          resp_c_struct_len,
  void                         *resp_cb_data
);

errno_enum_type qcril_qmi_client_send_msg_sync
(
  qcril_qmi_client_e_type      svc_type,
  unsigned long                msg_id,
  void                         *req_c_struct,
  int                          req_c_struct_len,
  void                         *resp_c_struct,
  int                          resp_c_struct_len
);

RIL_Errno qcril_qmi_client_send_msg_sync_ex
(
  qcril_qmi_client_e_type      svc_type,
  unsigned long                msg_id,
  void                         *req_c_struct,
  int                          req_c_struct_len,
  void                         *resp_c_struct,
  int                          resp_c_struct_len,
  int                          timeout_msecs
);

qmi_idl_service_object_type qcril_qmi_client_get_service_object
(
  qcril_qmi_client_e_type        svc_type
);

qmi_client_type qcril_qmi_client_get_user_handle
(
  qcril_qmi_client_e_type        svc_type
);

RIL_Errno qcril_qmi_util_convert_qmi_response_codes_to_ril_result(qmi_client_error_type qmi_transport_error, qmi_response_type_v01* qmi_service_response);

RIL_Errno qcril_qmi_util_convert_qmi_response_codes_to_ril_result_ex(qmi_client_error_type qmi_transport_error,
                                                                     qmi_response_type_v01* qmi_service_response,
                                                                     qmi_ril_err_context_e_type context,
                                                                     void* any);

RIL_Errno qcril_qmi_map_internalerr_from_reqlist_new_to_ril_err(IxErrnoType error);

RIL_Errno qcril_qmi_client_dsds_bind_to_subscription( RIL_SubscriptionType sub_num );
RIL_Errno qcril_qmi_client_dsds_cri_client_reinit( RIL_SubscriptionType sub_num );
RIL_Errno qcril_qmi_client_dsds_cri_client_reset();

int qcril_qmi_client_is_available(void);

void qmi_ril_suspending_con_handler
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type *const ret_ptr
);

void qmi_ril_core_final_suspend_handler
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type *const ret_ptr
);

void qmi_ril_core_final_resume_handler
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type *const ret_ptr
);

void qmi_ril_core_pre_resume_handler
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type *const ret_ptr
);

void qmi_ril_resuming_con_handler
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type *const ret_ptr
);

void qcril_qmi_check_if_service_is_up
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
);

void qcril_qmi_handle_event_service_down
(
 const qcril_request_params_type *const params_ptr,
 qcril_request_return_type       *const ret_ptr
);

void qcril_qmi_check_if_ssr_excluded_service_is_up
(
  const qcril_request_params_type *const params_ptr,
  qcril_request_return_type       *const ret_ptr
);

void qcril_qmi_handle_event_ssr_excluded_service_down
(
 const qcril_request_params_type *const params_ptr,
 qcril_request_return_type       *const ret_ptr
);

boolean is_qcril_qmi_client_ready
(
 qcril_qmi_client_e_type svc_type
);

void qmi_ril_wave_modem_status(void);

void qmi_ril_send_modem_restart_notification(char* reason);

void qmi_ril_qmi_client_log_request(
                                    qcril_qmi_client_e_type qmi_service,
                                    int                     message_id,
                                    void*                   message_req_c_struct_payload,
                                    int                     message_req_c_struct_payload_len,
                                    char*                   log_extra
                                    );

void qmi_ril_qmi_client_pre_initialization_init();
void qmi_ril_qmi_client_pre_initialization_acquire();
void qmi_ril_qmi_client_pre_initialization_release();
void qcril_qmi_release_services();
void qcril_qmi_register_for_up_event();

bool qcril_qmi_client_is_client_initialized(qcril_qmi_client_e_type client);

#ifdef __cplusplus
}
#endif
#endif /* QCRIL_QMI_CLIENT_H */
