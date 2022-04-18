/*=============================================================================

    netmgr_sm_int.c

Description:
  This file contains the machine generated source file for the state machine
  specified in the file:
  ./netmgr_sm.stm

=============================================================================*/

/*===========================================================================

  Copyright (c) 2017, 2019 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/


/* Include STM compiler generated external and internal header files */
#include "netmgr_sm_ext.h"
#include "netmgr_sm_int.h"

/* Include INPUT_DEF_FILE specified files */
#include <netmgr_sm.h>

/* Begin machine generated internal source for state machine array: NETMGR_SM[] */

#ifndef STM_DATA_STRUCTURES_ONLY
/* Transition table */
static const stm_transition_fn_t
  NETMGR_SM_transitions[ NETMGR_SM_NUM_STATES * NETMGR_SM_NUM_INPUTS ] =
{
  /* Transition functions for state NETMGR_STATE_DOWN */
  netmgr_sm_modem_is_msg,    /* NETMGR_INITED_EV */
  netmgr_sm_modem_is_msg,    /* NETMGR_MODEM_IS_EV */
  netmgr_sm_modem_oos_msg,    /* NETMGR_MODEM_OOS_EV */
  netmgr_sm_dispatch_kif_msg,    /* NETMGR_KIF_MSG_CMD */
  netmgr_sm_dispatch_qmi_msg,    /* NETMGR_QMI_MSG_CMD */
  netmgr_sm_modem_reset_msg,    /* NETMGR_RESET_MSG_CMD */
  NULL,    /* NETMGR_WDS_CONNECTED_EV */
  NULL,    /* NETMGR_WDS_DISCONNECTED_EV */
  NULL,    /* NETMGR_QOS_DELETE_EV */
  NULL,    /* NETMGR_QOS_ACTIVATE_EV */
  NULL,    /* NETMGR_QOS_SUSPEND_EV */
  NULL,    /* NETMGR_KIF_OPENED_EV */
  NULL,    /* NETMGR_KIF_CLOSED_EV */
  NULL,    /* NETMGR_KIF_CONFIGURED_EV */
  NULL,    /* NETMGR_KIF_RECONFIGURED_EV */
  NULL,    /* NETMGR_QOS_FLOCNTRL_EV */
  NULL,    /* NETMGR_WLAN_OPENED_EV */
  NULL,    /* NETMGR_WLAN_CLOSED_EV */
  NULL,    /* NETMGR_QOS_MODIFY_EV */
  NULL,    /* NETMGR_QOS_REBIND_EV */

  /* Transition functions for state NETMGR_STATE_INITED */
  NULL,    /* NETMGR_INITED_EV */
  NULL,    /* NETMGR_MODEM_IS_EV */
  netmgr_sm_modem_oos_msg,    /* NETMGR_MODEM_OOS_EV */
  netmgr_sm_dispatch_kif_msg,    /* NETMGR_KIF_MSG_CMD */
  netmgr_sm_dispatch_qmi_msg,    /* NETMGR_QMI_MSG_CMD */
  netmgr_sm_modem_reset_msg,    /* NETMGR_RESET_MSG_CMD */
  netmgr_sm_modem_connected,    /* NETMGR_WDS_CONNECTED_EV */
  netmgr_sm_modem_disconnected_in_inited,    /* NETMGR_WDS_DISCONNECTED_EV */
  netmgr_sm_qos_delete,    /* NETMGR_QOS_DELETE_EV */
  netmgr_sm_qos_activate,    /* NETMGR_QOS_ACTIVATE_EV */
  netmgr_sm_qos_suspend,    /* NETMGR_QOS_SUSPEND_EV */
  NULL,    /* NETMGR_KIF_OPENED_EV */
  NULL,    /* NETMGR_KIF_CLOSED_EV */
  NULL,    /* NETMGR_KIF_CONFIGURED_EV */
  NULL,    /* NETMGR_KIF_RECONFIGURED_EV */
  NULL,    /* NETMGR_QOS_FLOCNTRL_EV */
  NULL,    /* NETMGR_WLAN_OPENED_EV */
  NULL,    /* NETMGR_WLAN_CLOSED_EV */
  NULL,    /* NETMGR_QOS_MODIFY_EV */
  netmgr_sm_qos_rebind,    /* NETMGR_QOS_REBIND_EV */

  /* Transition functions for state NETMGR_STATE_COMING_UP */
  NULL,    /* NETMGR_INITED_EV */
  NULL,    /* NETMGR_MODEM_IS_EV */
  netmgr_sm_modem_oos_msg,    /* NETMGR_MODEM_OOS_EV */
  netmgr_sm_dispatch_kif_msg,    /* NETMGR_KIF_MSG_CMD */
  netmgr_sm_dispatch_qmi_msg,    /* NETMGR_QMI_MSG_CMD */
  netmgr_sm_modem_reset_msg,    /* NETMGR_RESET_MSG_CMD */
  netmgr_sm_repost_modem_connected,    /* NETMGR_WDS_CONNECTED_EV */
  netmgr_sm_modem_disconnected,    /* NETMGR_WDS_DISCONNECTED_EV */
  NULL,    /* NETMGR_QOS_DELETE_EV */
  netmgr_sm_qos_activate,    /* NETMGR_QOS_ACTIVATE_EV */
  netmgr_sm_qos_suspend,    /* NETMGR_QOS_SUSPEND_EV */
  netmgr_sm_kif_opened,    /* NETMGR_KIF_OPENED_EV */
  netmgr_sm_kif_closed,    /* NETMGR_KIF_CLOSED_EV */
  NULL,    /* NETMGR_KIF_CONFIGURED_EV */
  NULL,    /* NETMGR_KIF_RECONFIGURED_EV */
  NULL,    /* NETMGR_QOS_FLOCNTRL_EV */
  NULL,    /* NETMGR_WLAN_OPENED_EV */
  NULL,    /* NETMGR_WLAN_CLOSED_EV */
  NULL,    /* NETMGR_QOS_MODIFY_EV */
  netmgr_sm_qos_rebind,    /* NETMGR_QOS_REBIND_EV */

  /* Transition functions for state NETMGR_STATE_CONFIGURING */
  NULL,    /* NETMGR_INITED_EV */
  NULL,    /* NETMGR_MODEM_IS_EV */
  netmgr_sm_modem_oos_msg,    /* NETMGR_MODEM_OOS_EV */
  netmgr_sm_dispatch_kif_msg,    /* NETMGR_KIF_MSG_CMD */
  netmgr_sm_dispatch_qmi_msg,    /* NETMGR_QMI_MSG_CMD */
  netmgr_sm_modem_reset_msg,    /* NETMGR_RESET_MSG_CMD */
  netmgr_sm_repost_modem_connected,    /* NETMGR_WDS_CONNECTED_EV */
  netmgr_sm_modem_disconnected,    /* NETMGR_WDS_DISCONNECTED_EV */
  NULL,    /* NETMGR_QOS_DELETE_EV */
  netmgr_sm_qos_activate,    /* NETMGR_QOS_ACTIVATE_EV */
  netmgr_sm_qos_suspend,    /* NETMGR_QOS_SUSPEND_EV */
  NULL,    /* NETMGR_KIF_OPENED_EV */
  netmgr_sm_kif_closed,    /* NETMGR_KIF_CLOSED_EV */
  netmgr_sm_kif_configured,    /* NETMGR_KIF_CONFIGURED_EV */
  NULL,    /* NETMGR_KIF_RECONFIGURED_EV */
  NULL,    /* NETMGR_QOS_FLOCNTRL_EV */
  NULL,    /* NETMGR_WLAN_OPENED_EV */
  NULL,    /* NETMGR_WLAN_CLOSED_EV */
  NULL,    /* NETMGR_QOS_MODIFY_EV */
  netmgr_sm_qos_rebind,    /* NETMGR_QOS_REBIND_EV */

  /* Transition functions for state NETMGR_STATE_RECONFIGURING */
  NULL,    /* NETMGR_INITED_EV */
  NULL,    /* NETMGR_MODEM_IS_EV */
  netmgr_sm_modem_oos_msg,    /* NETMGR_MODEM_OOS_EV */
  netmgr_sm_dispatch_kif_msg,    /* NETMGR_KIF_MSG_CMD */
  netmgr_sm_dispatch_qmi_msg,    /* NETMGR_QMI_MSG_CMD */
  netmgr_sm_modem_reset_msg,    /* NETMGR_RESET_MSG_CMD */
  netmgr_sm_modem_reconfig,    /* NETMGR_WDS_CONNECTED_EV */
  netmgr_sm_modem_disconnected,    /* NETMGR_WDS_DISCONNECTED_EV */
  NULL,    /* NETMGR_QOS_DELETE_EV */
  netmgr_sm_qos_activate,    /* NETMGR_QOS_ACTIVATE_EV */
  netmgr_sm_qos_suspend,    /* NETMGR_QOS_SUSPEND_EV */
  NULL,    /* NETMGR_KIF_OPENED_EV */
  netmgr_sm_kif_closed,    /* NETMGR_KIF_CLOSED_EV */
  NULL,    /* NETMGR_KIF_CONFIGURED_EV */
  netmgr_sm_kif_configured,    /* NETMGR_KIF_RECONFIGURED_EV */
  netmgr_sm_qos_flow_control,    /* NETMGR_QOS_FLOCNTRL_EV */
  netmgr_sm_wlan_opened,    /* NETMGR_WLAN_OPENED_EV */
  netmgr_sm_wlan_closed,    /* NETMGR_WLAN_CLOSED_EV */
  NULL,    /* NETMGR_QOS_MODIFY_EV */
  netmgr_sm_qos_rebind,    /* NETMGR_QOS_REBIND_EV */

  /* Transition functions for state NETMGR_STATE_UP */
  NULL,    /* NETMGR_INITED_EV */
  NULL,    /* NETMGR_MODEM_IS_EV */
  netmgr_sm_modem_oos_msg,    /* NETMGR_MODEM_OOS_EV */
  netmgr_sm_dispatch_kif_msg,    /* NETMGR_KIF_MSG_CMD */
  netmgr_sm_dispatch_qmi_msg,    /* NETMGR_QMI_MSG_CMD */
  netmgr_sm_modem_reset_msg,    /* NETMGR_RESET_MSG_CMD */
  netmgr_sm_modem_reconfig,    /* NETMGR_WDS_CONNECTED_EV */
  netmgr_sm_modem_disconnected,    /* NETMGR_WDS_DISCONNECTED_EV */
  netmgr_sm_qos_delete,    /* NETMGR_QOS_DELETE_EV */
  netmgr_sm_qos_activate,    /* NETMGR_QOS_ACTIVATE_EV */
  netmgr_sm_qos_suspend,    /* NETMGR_QOS_SUSPEND_EV */
  netmgr_sm_kif_opened,    /* NETMGR_KIF_OPENED_EV */
  netmgr_sm_kif_closed,    /* NETMGR_KIF_CLOSED_EV */
  NULL,    /* NETMGR_KIF_CONFIGURED_EV */
  NULL,    /* NETMGR_KIF_RECONFIGURED_EV */
  netmgr_sm_qos_flow_control,    /* NETMGR_QOS_FLOCNTRL_EV */
  netmgr_sm_wlan_opened,    /* NETMGR_WLAN_OPENED_EV */
  netmgr_sm_wlan_closed,    /* NETMGR_WLAN_CLOSED_EV */
  netmgr_sm_qos_modify,    /* NETMGR_QOS_MODIFY_EV */
  netmgr_sm_qos_rebind,    /* NETMGR_QOS_REBIND_EV */

  /* Transition functions for state NETMGR_STATE_GOING_DOWN */
  NULL,    /* NETMGR_INITED_EV */
  NULL,    /* NETMGR_MODEM_IS_EV */
  netmgr_sm_modem_oos_msg,    /* NETMGR_MODEM_OOS_EV */
  netmgr_sm_dispatch_kif_msg,    /* NETMGR_KIF_MSG_CMD */
  netmgr_sm_dispatch_qmi_msg,    /* NETMGR_QMI_MSG_CMD */
  netmgr_sm_modem_reset_msg,    /* NETMGR_RESET_MSG_CMD */
  netmgr_sm_modem_connected_while_going_down,    /* NETMGR_WDS_CONNECTED_EV */
  NULL,    /* NETMGR_WDS_DISCONNECTED_EV */
  netmgr_sm_qos_delete,    /* NETMGR_QOS_DELETE_EV */
  NULL,    /* NETMGR_QOS_ACTIVATE_EV */
  NULL,    /* NETMGR_QOS_SUSPEND_EV */
  netmgr_sm_kif_opened_while_going_down,    /* NETMGR_KIF_OPENED_EV */
  netmgr_sm_kif_closed,    /* NETMGR_KIF_CLOSED_EV */
  NULL,    /* NETMGR_KIF_CONFIGURED_EV */
  NULL,    /* NETMGR_KIF_RECONFIGURED_EV */
  NULL,    /* NETMGR_QOS_FLOCNTRL_EV */
  NULL,    /* NETMGR_WLAN_OPENED_EV */
  NULL,    /* NETMGR_WLAN_CLOSED_EV */
  NULL,    /* NETMGR_QOS_MODIFY_EV */
  NULL,    /* NETMGR_QOS_REBIND_EV */

  /* Transition functions for state NETMGR_STATE_GOING_DOWN_TO_COME_UP */
  NULL,    /* NETMGR_INITED_EV */
  NULL,    /* NETMGR_MODEM_IS_EV */
  netmgr_sm_modem_oos_msg,    /* NETMGR_MODEM_OOS_EV */
  netmgr_sm_dispatch_kif_msg,    /* NETMGR_KIF_MSG_CMD */
  netmgr_sm_dispatch_qmi_msg,    /* NETMGR_QMI_MSG_CMD */
  netmgr_sm_modem_reset_msg,    /* NETMGR_RESET_MSG_CMD */
  netmgr_sm_repost_modem_connected,    /* NETMGR_WDS_CONNECTED_EV */
  netmgr_sm_modem_disconnected,    /* NETMGR_WDS_DISCONNECTED_EV */
  netmgr_sm_qos_delete,    /* NETMGR_QOS_DELETE_EV */
  NULL,    /* NETMGR_QOS_ACTIVATE_EV */
  NULL,    /* NETMGR_QOS_SUSPEND_EV */
  netmgr_sm_kif_opened_while_going_down,    /* NETMGR_KIF_OPENED_EV */
  netmgr_sm_kif_down_to_come_up,    /* NETMGR_KIF_CLOSED_EV */
  NULL,    /* NETMGR_KIF_CONFIGURED_EV */
  NULL,    /* NETMGR_KIF_RECONFIGURED_EV */
  NULL,    /* NETMGR_QOS_FLOCNTRL_EV */
  NULL,    /* NETMGR_WLAN_OPENED_EV */
  NULL,    /* NETMGR_WLAN_CLOSED_EV */
  NULL,    /* NETMGR_QOS_MODIFY_EV */
  NULL,    /* NETMGR_QOS_REBIND_EV */

};
#endif /* !STM_DATA_STRUCTURES_ONLY */

/* State { name, entry, exit, child SM } table */
static const stm_state_map_t
  NETMGR_SM_states[ NETMGR_SM_NUM_STATES ] =
{
  {"NETMGR_STATE_DOWN",
#ifndef STM_DATA_STRUCTURES_ONLY
    netmgr_sm_state_down_entry, netmgr_sm_state_down_exit,
#else /* STM_DATA_STRUCTURES_ONLY */
    NULL, NULL,
#endif /* STM_DATA_STRUCTURES_ONLY */
    NULL},
  {"NETMGR_STATE_INITED",
#ifndef STM_DATA_STRUCTURES_ONLY
    netmgr_sm_state_inited_entry, netmgr_sm_state_inited_exit,
#else /* STM_DATA_STRUCTURES_ONLY */
    NULL, NULL,
#endif /* STM_DATA_STRUCTURES_ONLY */
    NULL},
  {"NETMGR_STATE_COMING_UP",
#ifndef STM_DATA_STRUCTURES_ONLY
    netmgr_sm_state_comingup_entry, netmgr_sm_state_comingup_exit,
#else /* STM_DATA_STRUCTURES_ONLY */
    NULL, NULL,
#endif /* STM_DATA_STRUCTURES_ONLY */
    NULL},
  {"NETMGR_STATE_CONFIGURING",
#ifndef STM_DATA_STRUCTURES_ONLY
    netmgr_sm_state_configuring_entry, netmgr_sm_state_configuring_exit,
#else /* STM_DATA_STRUCTURES_ONLY */
    NULL, NULL,
#endif /* STM_DATA_STRUCTURES_ONLY */
    NULL},
  {"NETMGR_STATE_RECONFIGURING",
#ifndef STM_DATA_STRUCTURES_ONLY
    netmgr_sm_state_reconfiguring_entry, netmgr_sm_state_reconfiguring_exit,
#else /* STM_DATA_STRUCTURES_ONLY */
    NULL, NULL,
#endif /* STM_DATA_STRUCTURES_ONLY */
    NULL},
  {"NETMGR_STATE_UP",
#ifndef STM_DATA_STRUCTURES_ONLY
    netmgr_sm_state_up_entry, netmgr_sm_state_up_exit,
#else /* STM_DATA_STRUCTURES_ONLY */
    NULL, NULL,
#endif /* STM_DATA_STRUCTURES_ONLY */
    NULL},
  {"NETMGR_STATE_GOING_DOWN",
#ifndef STM_DATA_STRUCTURES_ONLY
    netmgr_sm_state_goingdown_entry, netmgr_sm_state_goingdown_exit,
#else /* STM_DATA_STRUCTURES_ONLY */
    NULL, NULL,
#endif /* STM_DATA_STRUCTURES_ONLY */
    NULL},
  {"NETMGR_STATE_GOING_DOWN_TO_COME_UP",
#ifndef STM_DATA_STRUCTURES_ONLY
    netmgr_sm_state_goingdowntocomeup_entry, netmgr_sm_state_goingdowntocomeup_exit,
#else /* STM_DATA_STRUCTURES_ONLY */
    NULL, NULL,
#endif /* STM_DATA_STRUCTURES_ONLY */
    NULL},
};

/* Input { name, value } table */
static const stm_input_map_t
  NETMGR_SM_inputs[ NETMGR_SM_NUM_INPUTS ] =
{
  { "NETMGR_INITED_EV" , (stm_input_t) NETMGR_INITED_EV },
  { "NETMGR_MODEM_IS_EV" , (stm_input_t) NETMGR_MODEM_IS_EV },
  { "NETMGR_MODEM_OOS_EV" , (stm_input_t) NETMGR_MODEM_OOS_EV },
  { "NETMGR_KIF_MSG_CMD" , (stm_input_t) NETMGR_KIF_MSG_CMD },
  { "NETMGR_QMI_MSG_CMD" , (stm_input_t) NETMGR_QMI_MSG_CMD },
  { "NETMGR_RESET_MSG_CMD" , (stm_input_t) NETMGR_RESET_MSG_CMD },
  { "NETMGR_WDS_CONNECTED_EV" , (stm_input_t) NETMGR_WDS_CONNECTED_EV },
  { "NETMGR_WDS_DISCONNECTED_EV" , (stm_input_t) NETMGR_WDS_DISCONNECTED_EV },
  { "NETMGR_QOS_DELETE_EV" , (stm_input_t) NETMGR_QOS_DELETE_EV },
  { "NETMGR_QOS_ACTIVATE_EV" , (stm_input_t) NETMGR_QOS_ACTIVATE_EV },
  { "NETMGR_QOS_SUSPEND_EV" , (stm_input_t) NETMGR_QOS_SUSPEND_EV },
  { "NETMGR_KIF_OPENED_EV" , (stm_input_t) NETMGR_KIF_OPENED_EV },
  { "NETMGR_KIF_CLOSED_EV" , (stm_input_t) NETMGR_KIF_CLOSED_EV },
  { "NETMGR_KIF_CONFIGURED_EV" , (stm_input_t) NETMGR_KIF_CONFIGURED_EV },
  { "NETMGR_KIF_RECONFIGURED_EV" , (stm_input_t) NETMGR_KIF_RECONFIGURED_EV },
  { "NETMGR_QOS_FLOCNTRL_EV" , (stm_input_t) NETMGR_QOS_FLOCNTRL_EV },
  { "NETMGR_WLAN_OPENED_EV" , (stm_input_t) NETMGR_WLAN_OPENED_EV },
  { "NETMGR_WLAN_CLOSED_EV" , (stm_input_t) NETMGR_WLAN_CLOSED_EV },
  { "NETMGR_QOS_MODIFY_EV" , (stm_input_t) NETMGR_QOS_MODIFY_EV },
  { "NETMGR_QOS_REBIND_EV" , (stm_input_t) NETMGR_QOS_REBIND_EV },
};


/* Constant all-instance state machine data */
static const stm_state_machine_constdata_t NETMGR_SM_constdata =
{
  NETMGR_SM_NUM_INSTANCES, /* number of state machine instances */
  NETMGR_SM_NUM_STATES, /* number of states */
  NETMGR_SM_states, /* array of state mappings */
  NETMGR_SM_NUM_INPUTS, /* number of inputs */
  NETMGR_SM_inputs, /* array of input mappings */
#ifndef STM_DATA_STRUCTURES_ONLY
  NETMGR_SM_transitions, /* array of transition function mappings */
  netmgr_sm_entry, /* state machine entry function */
  netmgr_sm_exit, /* state machine exit function */
  netmgr_sm_error_hook, /* state machine error hook function */
  netmgr_sm_debug_hook, /* state machine debug hook function */
  NETMGR_STATE_DOWN /* state machine initial state */
#else /* STM_DATA_STRUCTURES_ONLY */
  NULL, /* array of transition function mappings */
  NULL, /* state machine entry function */
  NULL, /* state machine exit function */
  NULL, /* state machine error hook function */
  NULL, /* state machine debug hook function */
  0 /* state machine initial state */
#endif /* STM_DATA_STRUCTURES_ONLY */
};

/* Constant per-instance state machine data */
static const stm_state_machine_perinst_constdata_t
  NETMGR_SM_perinst_constdata[ NETMGR_SM_NUM_INSTANCES ] =
{
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[0]", /* state machine name */
    0x44271596, /* state machine unique ID (md5("NETMGR_SM[0]") & 0xFFFFFFFF) */
    0  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[1]", /* state machine name */
    0xc8d6ffd9, /* state machine unique ID (md5("NETMGR_SM[1]") & 0xFFFFFFFF) */
    1  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[2]", /* state machine name */
    0x4bc06da2, /* state machine unique ID (md5("NETMGR_SM[2]") & 0xFFFFFFFF) */
    2  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[3]", /* state machine name */
    0xad6fc688, /* state machine unique ID (md5("NETMGR_SM[3]") & 0xFFFFFFFF) */
    3  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[4]", /* state machine name */
    0x392d818b, /* state machine unique ID (md5("NETMGR_SM[4]") & 0xFFFFFFFF) */
    4  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[5]", /* state machine name */
    0x97aeb583, /* state machine unique ID (md5("NETMGR_SM[5]") & 0xFFFFFFFF) */
    5  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[6]", /* state machine name */
    0x396bebe3, /* state machine unique ID (md5("NETMGR_SM[6]") & 0xFFFFFFFF) */
    6  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[7]", /* state machine name */
    0xa3c457aa, /* state machine unique ID (md5("NETMGR_SM[7]") & 0xFFFFFFFF) */
    7  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[8]", /* state machine name */
    0x0dd549f9, /* state machine unique ID (md5("NETMGR_SM[8]") & 0xFFFFFFFF) */
    8  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[9]", /* state machine name */
    0x50a92935, /* state machine unique ID (md5("NETMGR_SM[9]") & 0xFFFFFFFF) */
    9  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[10]", /* state machine name */
    0xa0f3a0ed, /* state machine unique ID (md5("NETMGR_SM[10]") & 0xFFFFFFFF) */
    10  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[11]", /* state machine name */
    0x626b55d0, /* state machine unique ID (md5("NETMGR_SM[11]") & 0xFFFFFFFF) */
    11  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[12]", /* state machine name */
    0x000576f1, /* state machine unique ID (md5("NETMGR_SM[12]") & 0xFFFFFFFF) */
    12  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[13]", /* state machine name */
    0x47ba20be, /* state machine unique ID (md5("NETMGR_SM[13]") & 0xFFFFFFFF) */
    13  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[14]", /* state machine name */
    0x912ae3eb, /* state machine unique ID (md5("NETMGR_SM[14]") & 0xFFFFFFFF) */
    14  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[15]", /* state machine name */
    0xf2cd2bea, /* state machine unique ID (md5("NETMGR_SM[15]") & 0xFFFFFFFF) */
    15  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[16]", /* state machine name */
    0x994fd171, /* state machine unique ID (md5("NETMGR_SM[16]") & 0xFFFFFFFF) */
    16  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[17]", /* state machine name */
    0x548cce2f, /* state machine unique ID (md5("NETMGR_SM[17]") & 0xFFFFFFFF) */
    17  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[18]", /* state machine name */
    0x121f1b57, /* state machine unique ID (md5("NETMGR_SM[18]") & 0xFFFFFFFF) */
    18  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[19]", /* state machine name */
    0x28601000, /* state machine unique ID (md5("NETMGR_SM[19]") & 0xFFFFFFFF) */
    19  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[20]", /* state machine name */
    0x36a4de02, /* state machine unique ID (md5("NETMGR_SM[20]") & 0xFFFFFFFF) */
    20  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[21]", /* state machine name */
    0x8b464de5, /* state machine unique ID (md5("NETMGR_SM[21]") & 0xFFFFFFFF) */
    21  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[22]", /* state machine name */
    0x37f45308, /* state machine unique ID (md5("NETMGR_SM[22]") & 0xFFFFFFFF) */
    22  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[23]", /* state machine name */
    0x2a5bde6a, /* state machine unique ID (md5("NETMGR_SM[23]") & 0xFFFFFFFF) */
    23  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[24]", /* state machine name */
    0xa9b21a14, /* state machine unique ID (md5("NETMGR_SM[24]") & 0xFFFFFFFF) */
    24  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[25]", /* state machine name */
    0x09077fb5, /* state machine unique ID (md5("NETMGR_SM[25]") & 0xFFFFFFFF) */
    25  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[26]", /* state machine name */
    0x8325b4ad, /* state machine unique ID (md5("NETMGR_SM[26]") & 0xFFFFFFFF) */
    26  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[27]", /* state machine name */
    0x9bed4957, /* state machine unique ID (md5("NETMGR_SM[27]") & 0xFFFFFFFF) */
    27  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[28]", /* state machine name */
    0x30290bb0, /* state machine unique ID (md5("NETMGR_SM[28]") & 0xFFFFFFFF) */
    28  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[29]", /* state machine name */
    0xb30e9292, /* state machine unique ID (md5("NETMGR_SM[29]") & 0xFFFFFFFF) */
    29  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[30]", /* state machine name */
    0xbc61b434, /* state machine unique ID (md5("NETMGR_SM[30]") & 0xFFFFFFFF) */
    30  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[31]", /* state machine name */
    0x8e6be16e, /* state machine unique ID (md5("NETMGR_SM[31]") & 0xFFFFFFFF) */
    31  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[32]", /* state machine name */
    0xa5098781, /* state machine unique ID (md5("NETMGR_SM[32]") & 0xFFFFFFFF) */
    32  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[33]", /* state machine name */
    0x1c2babe0, /* state machine unique ID (md5("NETMGR_SM[33]") & 0xFFFFFFFF) */
    33  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[34]", /* state machine name */
    0x3b32144b, /* state machine unique ID (md5("NETMGR_SM[34]") & 0xFFFFFFFF) */
    34  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[35]", /* state machine name */
    0x540bf82b, /* state machine unique ID (md5("NETMGR_SM[35]") & 0xFFFFFFFF) */
    35  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[36]", /* state machine name */
    0x8f6bd802, /* state machine unique ID (md5("NETMGR_SM[36]") & 0xFFFFFFFF) */
    36  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[37]", /* state machine name */
    0xa56a0e20, /* state machine unique ID (md5("NETMGR_SM[37]") & 0xFFFFFFFF) */
    37  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[38]", /* state machine name */
    0xa08ee80c, /* state machine unique ID (md5("NETMGR_SM[38]") & 0xFFFFFFFF) */
    38  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[39]", /* state machine name */
    0x27964a70, /* state machine unique ID (md5("NETMGR_SM[39]") & 0xFFFFFFFF) */
    39  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[40]", /* state machine name */
    0xd15a8a46, /* state machine unique ID (md5("NETMGR_SM[40]") & 0xFFFFFFFF) */
    40  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[41]", /* state machine name */
    0xb08c6903, /* state machine unique ID (md5("NETMGR_SM[41]") & 0xFFFFFFFF) */
    41  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[42]", /* state machine name */
    0x7ff0b0b0, /* state machine unique ID (md5("NETMGR_SM[42]") & 0xFFFFFFFF) */
    42  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[43]", /* state machine name */
    0x9abf6b22, /* state machine unique ID (md5("NETMGR_SM[43]") & 0xFFFFFFFF) */
    43  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[44]", /* state machine name */
    0xb1b93025, /* state machine unique ID (md5("NETMGR_SM[44]") & 0xFFFFFFFF) */
    44  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[45]", /* state machine name */
    0x9e8f59ee, /* state machine unique ID (md5("NETMGR_SM[45]") & 0xFFFFFFFF) */
    45  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[46]", /* state machine name */
    0xf50d2ad9, /* state machine unique ID (md5("NETMGR_SM[46]") & 0xFFFFFFFF) */
    46  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[47]", /* state machine name */
    0xf0ae3a30, /* state machine unique ID (md5("NETMGR_SM[47]") & 0xFFFFFFFF) */
    47  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[48]", /* state machine name */
    0x757e0230, /* state machine unique ID (md5("NETMGR_SM[48]") & 0xFFFFFFFF) */
    48  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[49]", /* state machine name */
    0xea7ccdca, /* state machine unique ID (md5("NETMGR_SM[49]") & 0xFFFFFFFF) */
    49  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[50]", /* state machine name */
    0x709296fa, /* state machine unique ID (md5("NETMGR_SM[50]") & 0xFFFFFFFF) */
    50  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[51]", /* state machine name */
    0xb243bee7, /* state machine unique ID (md5("NETMGR_SM[51]") & 0xFFFFFFFF) */
    51  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[52]", /* state machine name */
    0xbb77f3fc, /* state machine unique ID (md5("NETMGR_SM[52]") & 0xFFFFFFFF) */
    52  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[53]", /* state machine name */
    0x3863dff3, /* state machine unique ID (md5("NETMGR_SM[53]") & 0xFFFFFFFF) */
    53  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[54]", /* state machine name */
    0xedf81fc8, /* state machine unique ID (md5("NETMGR_SM[54]") & 0xFFFFFFFF) */
    54  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[55]", /* state machine name */
    0xab064f79, /* state machine unique ID (md5("NETMGR_SM[55]") & 0xFFFFFFFF) */
    55  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[56]", /* state machine name */
    0x98723bf7, /* state machine unique ID (md5("NETMGR_SM[56]") & 0xFFFFFFFF) */
    56  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[57]", /* state machine name */
    0x66878af6, /* state machine unique ID (md5("NETMGR_SM[57]") & 0xFFFFFFFF) */
    57  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[58]", /* state machine name */
    0xe6713b24, /* state machine unique ID (md5("NETMGR_SM[58]") & 0xFFFFFFFF) */
    58  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[59]", /* state machine name */
    0x290b06d5, /* state machine unique ID (md5("NETMGR_SM[59]") & 0xFFFFFFFF) */
    59  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[60]", /* state machine name */
    0xd7d4aad4, /* state machine unique ID (md5("NETMGR_SM[60]") & 0xFFFFFFFF) */
    60  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[61]", /* state machine name */
    0x8f3216be, /* state machine unique ID (md5("NETMGR_SM[61]") & 0xFFFFFFFF) */
    61  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[62]", /* state machine name */
    0x04a2b4f6, /* state machine unique ID (md5("NETMGR_SM[62]") & 0xFFFFFFFF) */
    62  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[63]", /* state machine name */
    0x0b1987fd, /* state machine unique ID (md5("NETMGR_SM[63]") & 0xFFFFFFFF) */
    63  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[64]", /* state machine name */
    0x4b285c46, /* state machine unique ID (md5("NETMGR_SM[64]") & 0xFFFFFFFF) */
    64  /* this state machine instance */
  },
  {
    &NETMGR_SM_constdata, /* state machine constant data */
    "NETMGR_SM[65]", /* state machine name */
    0x83133940, /* state machine unique ID (md5("NETMGR_SM[65]") & 0xFFFFFFFF) */
    65  /* this state machine instance */
  },
};

/* State machine instance array definition */
stm_state_machine_t
  NETMGR_SM[ NETMGR_SM_NUM_INSTANCES ] =
{
  {
    &NETMGR_SM_perinst_constdata[ 0 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 1 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 2 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 3 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 4 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 5 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 6 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 7 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 8 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 9 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 10 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 11 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 12 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 13 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 14 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 15 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 16 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 17 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 18 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 19 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 20 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 21 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 22 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 23 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 24 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 25 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 26 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 27 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 28 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 29 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 30 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 31 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 32 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 33 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 34 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 35 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 36 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 37 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 38 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 39 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 40 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 41 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 42 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 43 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 44 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 45 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 46 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 47 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 48 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 49 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 50 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 51 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 52 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 53 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 54 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 55 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 56 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 57 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 58 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 59 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 60 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 61 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 62 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 63 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 64 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
  {
    &NETMGR_SM_perinst_constdata[ 65 ], /* per instance constant data array */
    STM_DEACTIVATED_STATE, /* current state */
    -1, /* current input index */
    NULL, /* calling SM instance */
    FALSE, /* propagate input to parent */
    FALSE, /* locked flag */
    NULL, /* user defined per-instance data */
    0, /* user defined debug mask */
  },
};

#ifndef STM_DATA_STRUCTURES_ONLY
/* User called 'reset' routine.  Should never be needed, but can be used to
   effect a complete reset of all a given state machine's instances. */
void NETMGR_SM_reset(void)
{
  uint32 idx;
  void **tricky;

  /* Reset all the child SMs (if any) */
  

  /* Reset the parent */
  for( idx = 0; idx < NETMGR_SM_NUM_INSTANCES; idx++)
  {
    tricky = (void **)&NETMGR_SM[ idx ].pi_const_data; /* sleight of hand to assign to const ptr below */
    *tricky = (void *)&NETMGR_SM_perinst_constdata[ idx ]; /* per instance constant data array */
    NETMGR_SM[ idx ].current_state = STM_DEACTIVATED_STATE; /* current state */
    NETMGR_SM[ idx ].curr_input_index = -1; /* current input index */
    NETMGR_SM[ idx ].propagate_input = FALSE; /* propagate input to parent */
    NETMGR_SM[ idx ].is_locked = FALSE; /* locked flag */
    NETMGR_SM[ idx ].user_data = NULL; /* user defined per-instance data */
    NETMGR_SM[ idx ].debug_mask = 0; /* user defined debug mask */
  }

}
#endif /* !STM_DATA_STRUCTURES_ONLY */

/* End machine generated internal source for state machine array: NETMGR_SM[] */


