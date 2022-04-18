/******************************************************************************
#  Copyright (c) 2012, 2017 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#******************************************************************************/

/*!
  @file
  qcril_qmi_pil_monitor.h

  @brief

*/


#ifndef QCRIL_QMI_PIL_MONITOR_H
#define QCRIL_QMI_PIL_MONITOR_H

#ifdef  __cplusplus
extern "C" {
#endif

typedef enum
{
    QCRIL_QMI_PIL_STATE_MIN = -1,
    QCRIL_QMI_PIL_STATE_OFFLINE,
    QCRIL_QMI_PIL_STATE_ONLINE,
    QCRIL_QMI_PIL_STATE_UNKNOWN,
    QCRIL_QMI_PIL_STATE_MAX
} qcril_qmi_pil_state_type;

typedef struct {
    qcril_qmi_pil_state_type state;
} qcril_qmi_pil_state;

#define QCRIL_QMI_PIL_MONITOR_MAX_FDS       2
#define QCRIL_QMI_PIL_MONITOR_MAX_BUF_SIZE  256
#define QCRIL_QMI_PIL_DEVICE_FILE_NAME_SIZE 50
#define QCRIL_QMI_PIL_DEVICE_DIR            "/sys/bus/msm_subsys/devices"
#define QCRIL_QMI_PIL_DEVICE_DIR_SUBSTR     "subsys"
#define QCRIL_QMI_PIL_DEVICE_NAME_FILE      "name"
#define QCRIL_QMI_PIL_DEVICE_STATE_FILE     "state"

#define QCRIL_PIL_ADSP_DEVICE_NAME          "adsp"
#define QCRIL_PIL_BG_DEVICE_NAME            "bg-wear"

typedef void (*qcril_qmi_pil_state_change_hdlr)(const qcril_qmi_pil_state* cur_state);

int qcril_qmi_pil_init_monitor();
int qcril_qmi_pil_register_for_state_change(qcril_qmi_pil_state_change_hdlr hdlr);
int qcril_qmi_pil_deregister_for_state_change(qcril_qmi_pil_state_change_hdlr hdlr);
const qcril_qmi_pil_state* qcril_qmi_pil_get_pil_state();

#ifdef  __cplusplus
}
#endif

#endif /* QCRIL_QMI_PIL_MONITOR_H */
