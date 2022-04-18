/******************************************************************************

                        QTI_RMNET_DPM.C

******************************************************************************/

/******************************************************************************

  @file    qti_rmnet_dpm.c
  @brief   Tethering Interface module for Data Port Mapper interaction.


  DESCRIPTION
  This file has functions which interact with DPM QMI service for
  RMNET tethering.

  ---------------------------------------------------------------------------
  Copyright (c) 2013-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------


******************************************************************************/


/******************************************************************************

                      EDIT HISTORY FOR FILE

when       who        what, where, why
--------   ---        -------------------------------------------------------
12/9/13    sb         Add port mapper functionality. Modem interface file interaction

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <asm/types.h>
#include <fcntl.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#include "qti.h"
#include "data_common_v01.h"
#include "data_port_mapper_v01.h"
#include "qmi_client_instance_defs.h"

static  qti_rmnet_param        * rmnet_state_config = NULL;
static  qti_dpl_param          * dpl_state_config = NULL;
qmi_client_os_params           qti_dpm_os_params;
qmi_idl_service_object_type    qti_dpm_service_object;
qmi_client_os_params           qti_dpm_os_params_init;
extern                         boolean is_ssr_in_progress;
extern                         boolean is_fusion_target;
extern unsigned int            dpm_qti_sockfd;

/*===========================================================================
                               FUNCTION DEFINITIONS
=========================================================================*/

/*===========================================================================

FUNCTION DPM_CLIENT_INIT()

DESCRIPTION
  Initializes a DPM QMI client

DEPENDENCIES
  None.

RETURN VALUE
  QTI_SUCCESS on success
  QTI_FAILURE on failure


SIDE EFFECTS
  None

=========================================================================*/

int dpm_client_init()
{

  qmi_client_error_type   qmi_error, qmi_err_code = QMI_NO_ERR;
  boolean                 dpm_client_inited = false;
  int                     clientRetry = 0;
  int                     ret_val;

/*-----------------------------------------------------------------------------
  Deregister QMUXD ports since we want the client init request to go over IPC router
------------------------------------------------------------------------------*/
  qmi_cci_qmux_xport_unregister(QMI_CLIENT_QMUX_RMNET_INSTANCE_0);
  qmi_cci_qmux_xport_unregister(QMI_CLIENT_QMUX_RMNET_USB_INSTANCE_0);
  qmi_cci_qmux_xport_unregister(QMI_CLIENT_QMUX_RMNET_SMUX_INSTANCE_0);
  qmi_cci_qmux_xport_unregister(QMI_CLIENT_QMUX_RMNET_MHI_INSTANCE_0);

  if (rmnet_state_config->qti_dpm_handle > 0)
  {
    LOG_MSG_INFO1("Already DPM client inited : %d", rmnet_state_config->qti_dpm_handle, 0, 0);
    return QTI_SUCCESS;
  }
/*-----------------------------------------------------------------------------
  Client init
------------------------------------------------------------------------------*/
  while (clientRetry < QTI_QMI_CLIENT_MAX_RETRY)
  {
    qmi_error = qmi_client_init_instance(qti_dpm_service_object,
                                         QMI_CLIENT_INSTANCE_ANY,
                                         NULL,
                                         NULL,
                                         &qti_dpm_os_params,
                                         QTI_QMI_MSG_TIMEOUT_VALUE,
                                         &(rmnet_state_config->qti_dpm_handle));

    if (qmi_error != QMI_NO_ERR)
    {
      LOG_MSG_ERROR("Can not init DPM client %d", qmi_error, 0, 0);
      clientRetry++;
      continue;
    }
    LOG_MSG_INFO1(" DPM client inited %d", rmnet_state_config->qti_dpm_handle, 0, 0);
    dpl_state_config->qti_dpm_handle = rmnet_state_config->qti_dpm_handle;
    dpm_client_inited = true;
    break;
  }

  if ( clientRetry == QTI_QMI_CLIENT_MAX_RETRY )
  {
    LOG_MSG_ERROR("Can not init DPM client even after %d  attempts ",
                  QTI_QMI_CLIENT_MAX_RETRY, 0, 0);
    return QTI_FAILURE;
  }

  qti_rmnet_process_modem_in_service();

/*-------------------------------------------------------------------------
  On boot up since QTI comes up a bit late when compared to USB driver,
  we may miss the 0 byte data from USB. So in order to handle those cases
  query the DPL state in peripheral driver by processing it like a reset.
--------------------------------------------------------------------------*/
  ret_val = qti_dpl_process_ph_reset();
  if (ret_val != QTI_SUCCESS)
    LOG_MSG_ERROR("DPL DPM Init check failed", 0, 0, 0);


  return QTI_SUCCESS;
}

/*===========================================================================

FUNCTION QTI_DPM_INIT()

DESCRIPTION
  Initializes a DPM service object and register
  for service indication callback.

DEPENDENCIES
  None.

RETURN VALUE
  QTI_SUCCESS on success
  QTI_FAILURE on failure


SIDE EFFECTS
  None

=========================================================================*/

int qti_dpm_init
(
   qti_rmnet_param       * rmnet_state,
   qti_dpl_param         * dpl_state
)
{
  qmi_client_error_type                                  qmi_error, qmi_err_code = QMI_NO_ERR;
  int ret;
/*---------------------------------------------------------------------------*/

  if(rmnet_state == NULL || dpl_state == NULL)
  {
    LOG_MSG_ERROR("RmNet/DPL state not valid", 0, 0, 0);
    return QTI_FAILURE;
  }

  LOG_MSG_INFO1("qti_dpm_init()", 0, 0, 0);

/*-----------------------------------------------------------------------------
  Static pointer to QTI RmNet config and DPL config
------------------------------------------------------------------------------*/
  rmnet_state_config = rmnet_state;
  dpl_state_config = dpl_state;

/*-----------------------------------------------------------------------------
  Get the service object
------------------------------------------------------------------------------*/
  qti_dpm_service_object = dpm_get_service_object_v01();
  if (qti_dpm_service_object == NULL)
  {
    LOG_MSG_ERROR("QTI DPM service object not available",
                   0, 0, 0);
    return QTI_FAILURE;
  }

  memset(&qti_dpm_os_params, 0, sizeof(qmi_client_os_params));

  (void) qmi_client_notifier_init(qti_dpm_service_object,
                                  &qti_dpm_os_params_init,
                                  &dpm_notifier);

  (void) qmi_client_register_notify_cb(dpm_notifier,
                                       dpm_service_available_cb,
                                       (void *)NULL);

  LOG_MSG_INFO1("Successful DPM service registration", 0, 0, 0);

  return QTI_SUCCESS;
}


/*===========================================================================

FUNCTION QTI_RMNET_DPM_PORT_OPEN()

DESCRIPTION
  Opens the USB tethered SMD port using DPM port open request

DEPENDENCIES
  None.

RETURN VALUE
  QTI_SUCCESS on success
  QTI_FAILURE on failure


SIDE EFFECTS
  None

=========================================================================*/

int qti_rmnet_dpm_port_open()
{
  dpm_open_port_req_msg_v01    qti_dpm_port_open_req_msg;
  dpm_open_port_resp_msg_v01   qti_dpm_port_open_resp_msg;
  qmi_client_error_type        qmi_error;
  int                          ret_val;
  char                         command[MAX_COMMAND_STR_LEN];

/*--------------------------------------------------------------------------*/
  LOG_MSG_INFO1("qti_rmnet_dpm_port_open Entry", 0, 0, 0);
  if(rmnet_state_config == NULL)
  {
    LOG_MSG_ERROR("RmNet state not valid", 0, 0, 0);
    return QTI_FAILURE;
  }

  memset(&qti_dpm_port_open_req_msg,
         0,
         sizeof(dpm_open_port_req_msg_v01));

  memset(&qti_dpm_port_open_resp_msg,
         0,
         sizeof(dpm_open_port_resp_msg_v01));

  ret_val = qti_rmnet_ph_get_ep_info();
  if (ret_val != QTI_SUCCESS)
  {
    LOG_MSG_ERROR("Failed to get EP info", 0, 0, 0);
    return QTI_FAILURE;
  }

/*----------------------------------------------------------------------------
  Do a close of ports before open since DPM service does not close ports
  if clients go away/get killed. This may lead to ports being open from
  previous iterations as well and hence was added for graceful cleanup
  and restart.
-----------------------------------------------------------------------------*/
  ret_val = qti_rmnet_dpm_port_close();
  if (ret_val != QTI_SUCCESS)
  {
    LOG_MSG_ERROR("Failed to perform a DPM close before a DPM open", 0, 0, 0);
  }

  sleep(ONE_SEC);
/*----------------------------------------------------------------------------
  Populate the fields for an open request
-----------------------------------------------------------------------------*/

  qti_dpm_port_open_req_msg.control_port_list_valid = TRUE;
  qti_dpm_port_open_req_msg.control_port_list_len = 1;
  strlcpy((char *)qti_dpm_port_open_req_msg.control_port_list[0].port_name,
          USB_TETHERED_SMD_CH,
          strlen(USB_TETHERED_SMD_CH)+1);
  qti_dpm_port_open_req_msg.control_port_list[0].default_ep_id.ep_type =
       (data_ep_type_enum_v01)(rmnet_state_config->ep_info.ph_ep_info.ep_type);
  qti_dpm_port_open_req_msg.control_port_list[0].default_ep_id.iface_id =
       rmnet_state_config->ep_info.ph_ep_info.peripheral_iface_id;

  qti_dpm_port_open_req_msg.hardware_data_port_list_valid = TRUE;
  qti_dpm_port_open_req_msg.hardware_data_port_list_len = 1;
  qti_dpm_port_open_req_msg.hardware_data_port_list[0].ep_id.ep_type =
                  (data_ep_type_enum_v01)(rmnet_state_config->ep_info.ph_ep_info.ep_type);
  qti_dpm_port_open_req_msg.hardware_data_port_list[0].ep_id.iface_id =
    rmnet_state_config->ep_info.ph_ep_info.peripheral_iface_id;

  qti_dpm_port_open_req_msg.hardware_data_port_list[0].hardware_ep_pair.consumer_pipe_num =
    rmnet_state_config->ep_info.ipa_ep_pair.consumer_pipe_num;

  qti_dpm_port_open_req_msg.hardware_data_port_list[0].hardware_ep_pair.producer_pipe_num =
    rmnet_state_config->ep_info.ipa_ep_pair.producer_pipe_num;

  qti_dpm_port_open_req_msg.data_port_buffer_info_list_valid = TRUE;
  qti_dpm_port_open_req_msg.data_port_buffer_info_list_len = 1;
  qti_dpm_port_open_req_msg.data_port_buffer_info_list[0].ep_id.ep_type =
                  (data_ep_type_enum_v01)(rmnet_state_config->ep_info.ph_ep_info.ep_type);
  qti_dpm_port_open_req_msg.data_port_buffer_info_list[0].ep_id.iface_id =
    rmnet_state_config->ep_info.ph_ep_info.peripheral_iface_id;
  qti_dpm_port_open_req_msg.data_port_buffer_info_list[0].ul_fifo_size =
    rmnet_state_config->data_buf_info.epout_total_buf_len;
  qti_dpm_port_open_req_msg.data_port_buffer_info_list[0].dl_buf_size =
    rmnet_state_config->data_buf_info.epin_buf_len;
  qti_dpm_port_open_req_msg.data_port_buffer_info_list[0].dl_fifo_size =
    rmnet_state_config->data_buf_info.epin_total_buf_len;


  snprintf(command, sizeof(command), "echo QTI Sending to modem  SMD channel %s, Peripheral type %d, peripheral id %d, ipa consumer EP %d, ipa producer EP %d > /dev/kmsg",
           qti_dpm_port_open_req_msg.control_port_list[0].port_name,
           rmnet_state_config->ep_info.ph_ep_info.ep_type,
           rmnet_state_config->ep_info.ph_ep_info.peripheral_iface_id,
           rmnet_state_config->ep_info.ipa_ep_pair.consumer_pipe_num,
           rmnet_state_config->ep_info.ipa_ep_pair.producer_pipe_num);
  ds_system_call(command,strlen(command));

  LOG_MSG_INFO1_6("Sending to modem  SMD channel %s, Peripheral type %d, peripheral id %d, ipa consumer EP %d, ipa producer EP %d",
                 qti_dpm_port_open_req_msg.control_port_list[0].port_name,
                 rmnet_state_config->ep_info.ph_ep_info.ep_type,
                 rmnet_state_config->ep_info.ph_ep_info.peripheral_iface_id,
                 rmnet_state_config->ep_info.ipa_ep_pair.consumer_pipe_num,
                 rmnet_state_config->ep_info.ipa_ep_pair.producer_pipe_num, 0);
  LOG_MSG_INFO1_6("Sending to modem  SMD channel ul fifo size %d, dl fifo size %d, dl buf size %d\n",
                  rmnet_state_config->data_buf_info.epout_total_buf_len,
                  rmnet_state_config->data_buf_info.epin_total_buf_len,
                  rmnet_state_config->data_buf_info.epin_buf_len,0,0,0);

  qmi_error = qmi_client_send_msg_sync(rmnet_state_config->qti_dpm_handle,
                                       QMI_DPM_OPEN_PORT_REQ_V01,
                                       &qti_dpm_port_open_req_msg,
                                       sizeof(dpm_open_port_req_msg_v01),
                                       &qti_dpm_port_open_resp_msg,
                                       sizeof(dpm_open_port_resp_msg_v01),
                                       QTI_QMI_MSG_TIMEOUT_VALUE);

  LOG_MSG_INFO1("qmi_client_send_msg_sync(dpm_port_open): error %d result %d",
                qmi_error,
                qti_dpm_port_open_resp_msg.resp.result,
                0);

  if ((qmi_error != QMI_NO_ERR) ||
      (qti_dpm_port_open_resp_msg.resp.result != QMI_NO_ERR))
  {
    LOG_MSG_ERROR( "Cannot open port %d : %d",
        qmi_error, qti_dpm_port_open_resp_msg.resp.error,0);
    return QTI_FAILURE;
  }

  LOG_MSG_INFO1( "DPM port opened", 0, 0, 0);
  ds_system_call("echo QTI:USB tethered modem SMD port opened > /dev/kmsg",
                 strlen("echo QTI:USB tethered modem SMD port opened > /dev/kmsg"));

  return QTI_SUCCESS;
}

/*===========================================================================

FUNCTION QTI_RMNET_DPM_PORT_CLOSE()

DESCRIPTION
  Closes the USB tethered SMD port using DPM port close request

DEPENDENCIES
  None.

RETURN VALUE
  QTI_SUCCESS on success
  QTI_FAILURE on failure


SIDE EFFECTS
  None

=========================================================================*/


int qti_rmnet_dpm_port_close()
{
  dpm_close_port_req_msg_v01    qti_dpm_port_close_req_msg;
  dpm_close_port_resp_msg_v01   qti_dpm_port_close_resp_msg;
  qmi_client_error_type        qmi_error;

/*--------------------------------------------------------------------------*/

  if(rmnet_state_config == NULL)
  {
    LOG_MSG_ERROR("RmNet state not valid", 0, 0, 0);
    return QTI_FAILURE;
  }
  LOG_MSG_INFO1("qti_rmnet_dpm_port_close Entry", 0, 0, 0);

  memset(&qti_dpm_port_close_req_msg,
         0,
         sizeof(dpm_close_port_req_msg_v01));

  memset(&qti_dpm_port_close_resp_msg,
         0,
         sizeof(dpm_close_port_resp_msg_v01));


  qti_dpm_port_close_req_msg.control_port_list_valid = TRUE;
  qti_dpm_port_close_req_msg.control_port_list_len = 1;
  strlcpy(qti_dpm_port_close_req_msg.control_port_list[0].port_name,
          USB_TETHERED_SMD_CH,
          strlen(USB_TETHERED_SMD_CH)+1);


  qti_dpm_port_close_req_msg.data_port_list_valid = TRUE;
  qti_dpm_port_close_req_msg.data_port_list_len = 1;
  qti_dpm_port_close_req_msg.data_port_list[0].ep_type =
      (data_ep_type_enum_v01)(rmnet_state_config->ep_info.ph_ep_info.ep_type);
  qti_dpm_port_close_req_msg.data_port_list[0].iface_id =
    rmnet_state_config->ep_info.ph_ep_info.peripheral_iface_id;

  qmi_error = qmi_client_send_msg_sync(rmnet_state_config->qti_dpm_handle,
                                       QMI_DPM_CLOSE_PORT_REQ_V01,
                                       &qti_dpm_port_close_req_msg,
                                       sizeof(dpm_close_port_req_msg_v01),
                                       &qti_dpm_port_close_resp_msg,
                                       sizeof(dpm_close_port_resp_msg_v01),
                                       QTI_QMI_MSG_TIMEOUT_VALUE);

  LOG_MSG_INFO1("qmi_client_send_msg_sync(dpm_port_close): error %d result %d",
                qmi_error,
                qti_dpm_port_close_resp_msg.resp.result,
                0);

  if ((qmi_error != QMI_NO_ERR) ||
      (qti_dpm_port_close_resp_msg.resp.result != QMI_NO_ERR))
  {
    LOG_MSG_ERROR( "Cannot close port %d : %d",
        qmi_error, qti_dpm_port_close_resp_msg.resp.error,0);
    return QTI_FAILURE;
  }

  LOG_MSG_INFO1( "DPM port closed", 0, 0, 0);

  return QTI_SUCCESS;
}


/*===========================================================================

FUNCTION QTI_RMNET_DPM_RELEASE()

DESCRIPTION
  Releases a DPM QMI client

DEPENDENCIES
  None.

RETURN VALUE
  QTI_SUCCESS on success
  QTI_FAILURE on failure


SIDE EFFECTS
  None

=========================================================================*/

int qti_rmnet_dpm_release()
{
  qmi_client_error_type                 qmi_error;

/*------------------------------------------------------------------------*/

  if(rmnet_state_config == NULL)
  {
    LOG_MSG_ERROR("RmNet state not valid", 0, 0, 0);
    return QTI_FAILURE;
  }

  LOG_MSG_INFO1("qti_rmnet_dpm_release Entry", 0, 0, 0);

  qmi_error = qmi_client_release(rmnet_state_config->qti_dpm_handle);
  if (qmi_error != QMI_NO_ERR)
  {
    LOG_MSG_ERROR("Can not release DPM client %d", qmi_error, 0, 0);
    return QTI_FAILURE;
  }
  rmnet_state_config->qti_dpm_handle = NULL;
  LOG_MSG_INFO1("Successfully deregistered DPM client", 0, 0, 0);

  return QTI_SUCCESS;
}


/*===========================================================================
  FUNCTION qti_rmnet_dpm_process_msg
=============================================================================
@brief
  This function is to send the message to serve socket

@input

@return
  void

@note

- Dependencies
- None

- Side Effects
- None
===========================================================================*/
void qti_rmnet_dpm_process_msg(qti_event_e event)
{
  qti_event_t event_buf;
  int numBytes=0, len=0;
  struct sockaddr_un cmd_qti;

  if (event == QTI_DPM_INIT_EVENT) {
    LOG_MSG_INFO1("Sending QTI_DPM_INIT_EVENT event to main context",0,0,0);
  }
  else if (event == QTI_RMNET_DPM_MODEM_NOT_IN_SERVICE_EVENT) {
    LOG_MSG_INFO1("Sending QTI_RMNET_DPM_MODEM_NOT_IN_SERVICE_EVENT "
                  "event to main context",0,0,0);
  }
  cmd_qti.sun_family = AF_UNIX;
  strlcpy(cmd_qti.sun_path, DEV_SOC_QTI_DPM_UDS_FILE, sizeof(DEV_SOC_QTI_DPM_UDS_FILE));
  len = strlen(cmd_qti.sun_path) + sizeof(cmd_qti.sun_family);
  event_buf.event = event;

  if ((numBytes = sendto(dpm_qti_sockfd, (void *)&event_buf, sizeof(qti_event_t), 0,
          (struct sockaddr *)&cmd_qti, len)) == -1)
  {
    LOG_MSG_ERROR("Failed to send the event info. to server socket errno:%d", errno, 0, 0);
    return;
  }
  LOG_MSG_INFO1("Successfully sent the event info. to server socket", 0, 0, 0);

  return;
}

/*===========================================================================

FUNCTION DPM_SERVICE_AVAILABLE_CB()

DESCRIPTION
  This function is invoked by dpm, to notify QTI when service is available.

DEPENDENCIES
  None.

RETURN VALUE

SIDE EFFECTS
  None

=========================================================================*/
void dpm_service_available_cb
(
   __attribute__((unused)) qmi_client_type user_handle,
   __attribute__((unused)) qmi_idl_service_object_type service_obj,
   __attribute__((unused)) qmi_client_notify_event_type service_event,
   __attribute__((unused)) void *notify_cb_data
)
{
  LOG_MSG_INFO1("dpm_service_available_cb \n",0, 0, 0);
/*--------------------------------------------------------------------------
  Post modem in service/modem not in service event
-------------------------------------------------------------------------*/

  if(service_event == QMI_CLIENT_SERVICE_COUNT_INC)
  {
    LOG_MSG_ERROR("DPM_INIT",0,0,0);
    qti_rmnet_dpm_process_msg(QTI_DPM_INIT_EVENT);
  }
  else if(service_event == QMI_CLIENT_SERVICE_COUNT_DEC)
  {
    LOG_MSG_ERROR("DPM_MODEM_NOT_IN_SERVICE",0,0,0);
    qti_rmnet_dpm_process_msg(QTI_RMNET_DPM_MODEM_NOT_IN_SERVICE_EVENT);
  }
  return;
}

/*===========================================================================

FUNCTION QTI_DPL_DPM_PORT_OPEN()

DESCRIPTION
  Opens the USB tethered DPL port using DPM port open request

DEPENDENCIES
  None.

RETURN VALUE
  QTI_SUCCESS on success
  QTI_FAILURE on failure


SIDE EFFECTS
  None

=========================================================================*/

int qti_dpl_dpm_port_open()
{
  dpm_open_port_req_msg_v01    qti_dpm_port_open_req_msg;
  dpm_open_port_resp_msg_v01   qti_dpm_port_open_resp_msg;
  qmi_client_error_type        qmi_error;
  int                          ret_val;
  char                         command[MAX_COMMAND_STR_LEN];

/*--------------------------------------------------------------------------*/

  if(dpl_state_config == NULL)
  {
    LOG_MSG_ERROR("DPL state not valid", 0, 0, 0);
    return QTI_FAILURE;
  }

  memset(&qti_dpm_port_open_req_msg,
         0,
         sizeof(dpm_open_port_req_msg_v01));

  memset(&qti_dpm_port_open_resp_msg,
         0,
         sizeof(dpm_open_port_resp_msg_v01));
/*-----------------------------------------------------------------------------
  Get the DPL USB/IPA EP info
------------------------------------------------------------------------------*/
  ret_val = qti_dpl_ph_get_ep_info();
  if (ret_val != QTI_SUCCESS)
  {
    LOG_MSG_ERROR("Failed to get EP info", 0, 0, 0);
    return QTI_FAILURE;
  }

/*-----------------------------------------------------------------------------
  Populate the DPM port open message
------------------------------------------------------------------------------*/
  qti_dpm_port_open_req_msg.hardware_data_port_list_valid = TRUE;
  qti_dpm_port_open_req_msg.hardware_data_port_list_len = 1;
  qti_dpm_port_open_req_msg.hardware_data_port_list[0].ep_id.ep_type =
                  (data_ep_type_enum_v01)(dpl_state_config->ep_info.ph_ep_info.ep_type);
  qti_dpm_port_open_req_msg.hardware_data_port_list[0].ep_id.iface_id =
    dpl_state_config->ep_info.ph_ep_info.peripheral_iface_id;

  qti_dpm_port_open_req_msg.hardware_data_port_list[0].hardware_ep_pair.consumer_pipe_num =
    dpl_state_config->ep_info.ipa_ep_pair.consumer_pipe_num;

  qti_dpm_port_open_req_msg.hardware_data_port_list[0].hardware_ep_pair.producer_pipe_num =
    dpl_state_config->ep_info.ipa_ep_pair.producer_pipe_num;

  snprintf(command, sizeof(command), "echo QTI Sending to modem  Peripheral type %d, peripheral id %d, ipa consumer EP %d, ipa producer EP %d > /dev/kmsg",
           dpl_state_config->ep_info.ph_ep_info.ep_type,
           dpl_state_config->ep_info.ph_ep_info.peripheral_iface_id,
           dpl_state_config->ep_info.ipa_ep_pair.consumer_pipe_num,
           dpl_state_config->ep_info.ipa_ep_pair.producer_pipe_num);
  ds_system_call(command,strlen(command));

  LOG_MSG_INFO1_6("Sending to modem  Peripheral type %d, peripheral id %d, ipa consumer EP %d, ipa producer EP %d",
                 dpl_state_config->ep_info.ph_ep_info.ep_type,
                 dpl_state_config->ep_info.ph_ep_info.peripheral_iface_id,
                 dpl_state_config->ep_info.ipa_ep_pair.consumer_pipe_num,
                 dpl_state_config->ep_info.ipa_ep_pair.producer_pipe_num, 0, 0);
/*-----------------------------------------------------------------------------
  Send the DPM port open QMI message
------------------------------------------------------------------------------*/
  qmi_error = qmi_client_send_msg_sync(dpl_state_config->qti_dpm_handle,
                                       QMI_DPM_OPEN_PORT_REQ_V01,
                                       &qti_dpm_port_open_req_msg,
                                       sizeof(dpm_open_port_req_msg_v01),
                                       &qti_dpm_port_open_resp_msg,
                                       sizeof(dpm_open_port_resp_msg_v01),
                                       QTI_QMI_MSG_TIMEOUT_VALUE);

  LOG_MSG_INFO1("qmi_client_send_msg_sync(dpm_port_open): error %d result %d",
                qmi_error,
                qti_dpm_port_open_resp_msg.resp.result,
                0);

  if ((qmi_error != QMI_NO_ERR) ||
      (qti_dpm_port_open_resp_msg.resp.result != QMI_NO_ERR))
  {
    LOG_MSG_ERROR( "Cannot open DPL port %d : %d",
        qmi_error, qti_dpm_port_open_resp_msg.resp.error,0);
    return QTI_FAILURE;
  }

  LOG_MSG_INFO1( "DPL port opened", 0, 0, 0);

  return QTI_SUCCESS;
}

/*===========================================================================

FUNCTION QTI_DPL_DPM_PORT_CLOSE()

DESCRIPTION
  Closes the USB tethered SMD port using DPM port close request

DEPENDENCIES
  None.

RETURN VALUE
  QTI_SUCCESS on success
  QTI_FAILURE on failure


SIDE EFFECTS
  None

=========================================================================*/


int qti_dpl_dpm_port_close()
{
  dpm_close_port_req_msg_v01    qti_dpm_port_close_req_msg;
  dpm_close_port_resp_msg_v01   qti_dpm_port_close_resp_msg;
  qmi_client_error_type         qmi_error;

/*--------------------------------------------------------------------------*/

  if(dpl_state_config == NULL)
  {
    LOG_MSG_ERROR("RmNet state not valid", 0, 0, 0);
    return QTI_FAILURE;
  }

  memset(&qti_dpm_port_close_req_msg,
         0,
         sizeof(dpm_close_port_req_msg_v01));

  memset(&qti_dpm_port_close_resp_msg,
         0,
         sizeof(dpm_close_port_resp_msg_v01));

/*-----------------------------------------------------------------------------
  Populate the DPM port close QMI message
------------------------------------------------------------------------------*/
  qti_dpm_port_close_req_msg.data_port_list_valid = TRUE;
  qti_dpm_port_close_req_msg.data_port_list_len = 1;
  qti_dpm_port_close_req_msg.data_port_list[0].ep_type =
      (data_ep_type_enum_v01)(dpl_state_config->ep_info.ph_ep_info.ep_type);
  qti_dpm_port_close_req_msg.data_port_list[0].iface_id =
    dpl_state_config->ep_info.ph_ep_info.peripheral_iface_id;
/*-----------------------------------------------------------------------------
  Send the QMI message
------------------------------------------------------------------------------*/
  qmi_error = qmi_client_send_msg_sync(dpl_state_config->qti_dpm_handle,
                                       QMI_DPM_CLOSE_PORT_REQ_V01,
                                       &qti_dpm_port_close_req_msg,
                                       sizeof(dpm_close_port_req_msg_v01),
                                       &qti_dpm_port_close_resp_msg,
                                       sizeof(dpm_close_port_resp_msg_v01),
                                       QTI_QMI_MSG_TIMEOUT_VALUE);

  LOG_MSG_INFO1("qmi_client_send_msg_sync(dpm_port_close): error %d result %d",
                qmi_error,
                qti_dpm_port_close_resp_msg.resp.result,
                0);

  if ((qmi_error != QMI_NO_ERR) ||
      (qti_dpm_port_close_resp_msg.resp.result != QMI_NO_ERR))
  {
    LOG_MSG_ERROR( "Cannot close port %d : %d",
        qmi_error, qti_dpm_port_close_resp_msg.resp.error,0);
    return QTI_FAILURE;
  }

  LOG_MSG_INFO1( "DPL port closed", 0, 0, 0);

  return QTI_SUCCESS;
}

