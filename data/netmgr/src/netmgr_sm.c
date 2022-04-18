/******************************************************************************

                        N E T M G R _ S M . C

******************************************************************************/

/******************************************************************************

  @file    netmgr_sm.c
  @brief   Network Manager state machine implementation

  DESCRIPTION
  Implementation of NetMgr's state machine.

******************************************************************************/
/*===========================================================================

  Copyright (c) 2010-2019 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

/*===========================================================================
                              INCLUDE FILES
===========================================================================*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h> /* open, read */

#include "netmgr_qmi.h"
#include "netmgr_util.h"
#include "netmgr_defs.h"
#include "netmgr_main.h"
#include "netmgr_exec.h"
#include "netmgr_platform.h"
#include "netmgr_cb.h"
#include "netmgr_kif_cb.h"
#include "netmgr_qmi.h"
#include "netmgr_rmnet.h"

#ifdef FEATURE_DATA_IWLAN
#include "netmgr_iwlan_client.h"
#endif

/*===========================================================================
                              FORWARD DECLARATIONS
===========================================================================*/


/*===========================================================================
                     LOCAL DEFINITIONS AND DECLARATIONS
===========================================================================*/

/*===========================================================================

         STM COMPILER GENERATED PROTOTYPES AND DATA STRUCTURES

===========================================================================*/

/* Include STM compiler generated internal data structure file */
#include "netmgr_sm_int.h"

#define NETMGR_EXEC_MAX_CMD_REPOST_LIMIT  (10)
#define NETMGR_EXEC_REPOST_STEP_MICROSECS (5000)
#define NETMGR_EXEC_MICROSECS_PER_SEC     (1000000)

/*===========================================================================

                         LOCAL VARIABLES

===========================================================================*/


/*! @brief Structure for state-machine per-instance local variables
*/
typedef struct
{
  int   internal_var;  /*!< My internal variable */
  void *internal_ptr;  /*!< My internal pointer */
} netmgr_sm_stub_instance_type;

/*! @brief All variables internal to module netmgr_sm_stub.c
*/
typedef struct
{
  /*! My array of per-instance internal variables. */
  netmgr_sm_stub_instance_type instance[ 3 ];
} netmgr_sm_stub_type;


/*===========================================================================

                 STATE MACHINE: NETMGR_SM

===========================================================================*/

/*===========================================================================

  STATE MACHINE ENTRY FUNCTION:  netmgr_sm_entry

===========================================================================*/
/*!
    @brief
    Entry function for state machine NETMGR_SM

    @detail
    Called upon activation of this state machine, with optional
    user-passed payload pointer parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_entry
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_NULL_CHECK( sm );

} /* netmgr_sm_entry() */


/*===========================================================================

  STATE MACHINE EXIT FUNCTION:  netmgr_sm_exit

===========================================================================*/
/*!
    @brief
    Exit function for state machine NETMGR_SM

    @detail
    Called upon deactivation of this state machine, with optional
    user-passed payload pointer parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_exit
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_NULL_CHECK( sm );
} /* netmgr_sm_exit() */


/*===========================================================================

  STATE MACHINE ERROR HOOK FUNCTION: netmgr_sm_error_hook

===========================================================================*/
void netmgr_sm_error_hook
(
  stm_status_t error,
  const char *filename,
  uint32 line,
  struct stm_state_machine_s *sm
)
{
  STM_UNUSED( error );
  STM_UNUSED( filename );
  STM_UNUSED( line );
  STM_UNUSED( sm );

  /* STUB */
  return;
}


/*===========================================================================

  STATE MACHINE DEBUG HOOK FUNCTION:  netmgr_sm_debug_hook

===========================================================================*/
void netmgr_sm_debug_hook
(
  stm_debug_event_t debug_event,
  struct stm_state_machine_s *sm,
  stm_state_t state_info,
  void *payload
)
{
  STM_UNUSED( payload );

  if( netmgr_main_cfg.debug ) {
    /* NOTE: the ENTRY/EXIT states seem reversed here but that is due
     * to STM2 providing the prev/next state value respectively. The
     * ordering here seems to make more sense. */
    switch( debug_event ) {
      case STM_STATE_EXIT_FN:
        netmgr_log_med("netmgr_sm_debug_hook: enter state %s\n",
                       stm_get_state_name(sm, state_info));
        break;
      case STM_STATE_ENTRY_FN:
        netmgr_log_med("netmgr_sm_debug_hook: exit state %s\n",
                       stm_get_state_name(sm, state_info));
        break;
      default:
        break;
    }
  }
  return;
}



/*===========================================================================

     (State Machine: NETMGR_SM)
     STATE ENTRY/EXIT/TRANSITION FUNCTIONS: NETMGR_STATE_DOWN

===========================================================================*/

/*===========================================================================

  STATE ENTRY FUNCTION:  netmgr_sm_state_down_entry

===========================================================================*/
/*!
    @brief
    Entry function for state machine NETMGR_SM,
    state NETMGR_STATE_DOWN

    @detail
    Called upon entry into this state of the state machine, with optional
    user-passed payload pointer parameter.  The prior state of the state
    machine is also passed as the prev_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_down_entry
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         prev_state,  /*!< Previous state */
  void                *payload     /*!< Payload pointer */
)
{

  NETMGR_LOG_FUNC_ENTRY;

  STM_UNUSED( sm );
  STM_UNUSED( prev_state );
  STM_UNUSED( payload );

  NETMGR_LOG_FUNC_EXIT;

} /* netmgr_sm_state_down_entry() */


/*===========================================================================

  STATE EXIT FUNCTION:  netmgr_sm_state_down_exit

===========================================================================*/
/*!
    @brief
    Exit function for state machine NETMGR_SM,
    state NETMGR_STATE_DOWN

    @detail
    Called upon exit of this state of the state machine, with optional
    user-passed payload pointer parameter.  The impending state of the state
    machine is also passed as the next_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_down_exit
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         next_state,  /*!< Next state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( next_state );
  STM_UNUSED( sm );

  netmgr_exec_cmd_t * cmd_buf = NULL;

  NETMGR_LOG_FUNC_ENTRY

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  if(cmd_buf)
  {
    netmgr_log_low("sm_state_down_exit on link %d\n",
                      cmd_buf->data.link);

#ifdef FEATURE_DATA_IWLAN
  /*
     Create iwlan client if LBO link moves out of down state when
     in NSWO mode. For regular modes, create the same when last reverse link
     moves of out down state only during NETMGR initialization or during
     IN service handling
   */
    if( ( (NSWO_ONLY == netmgr_main_get_iwlan_enabled()
           && NETMGR_IS_REV_IP_LOCAL_BRK_OUT_LINK(cmd_buf->data.link))
        ||
           NETMGR_KIF_IS_MAX_REV_RMNET_LINK(cmd_buf->data.link)
         )
       &&
        ( (cmd_buf->data.type == NETMGR_INITED_EV) ||
          (cmd_buf->data.type == NETMGR_MODEM_IS_EV) )
       )
    {
      if (netmgr_main_cfg.iwlan_client_enable)
      {
        if (NETMGR_SUCCESS != netmgrIwlanClientInit())
        {
          netmgr_log_err("Error in registering for WLAN events!");
        }
        else
        {
          netmgr_log_high("netmgrIwlanClientInit success");
        }
      }
    }
#endif
  }

NETMGR_LOG_FUNC_EXIT

} /* netmgr_sm_state_down_exit() */

/*===========================================================================

  STATE EXIT FUNCTION:  netmgr_sm_state_inited_entry

===========================================================================*/
/*!
    @brief
    Entry function for state machine NETMGR_SM,
    state NETMGR_STATE_INITED

    @detail
    Called upon entry of this state of the state machine, with optional
    user-passed payload pointer parameter. The prior state of the state
    machine is also passed as the prev_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_inited_entry
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t          prev_state, /*!< Prev State */
  void                *payload     /*!< Payload pointer */
)
{
  netmgr_exec_cmd_t * cmd_buf = NULL;
  netmgr_nl_event_info_t * event_info = NULL;
  const char *link_name;

  STM_UNUSED( sm );

  /* Verify program initialized */
  if( !netmgr_main_cfg.initialized ) {
    netmgr_log_err("netmgr initialization incomplete!\n");
    NETMGR_ABORT("netmgr initialization incomplete!");
  }

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Check for initialization state */
  if( NETMGR_STATE_DOWN != prev_state ||
      /* if netmgrd was restarted, below check is TRUE */
      ( NETMGR_KIF_LINK_POWERUP_STATE_UP ==
        netmgr_kif_get_link_powerup_state(cmd_buf->data.link))
    )
  {
    /* Send the config status for a reverse Rmnet link */
#ifdef FEATURE_DATA_IWLAN
    if (NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link))
    {
      int ip_family, config_status;

      if (NETMGR_SUCCESS != netmgr_qmi_retrieve_rev_ip_config_status(cmd_buf->data.link, &ip_family, &config_status))
      {
        netmgr_log_med("netmgr_sm_state_inited_entry: failed to get rev IP config status for link=%d, ignoring\n",
                       cmd_buf->data.link);
      }
      else
      {
        netmgr_qmi_send_rev_ip_config_complete(NETMGR_QMI_IWLAN_CALL_CLEANUP,
                                               cmd_buf->data.link,
                                               ip_family,
                                               config_status);
      }
    }
#endif /* FEATURE_DATA_IWLAN */

    /* Reset the QMI link WDS data for forward links. For rev links, we arrive
     * at inited state only after performing kif close. For ESP rekey scenarios,
     * this qmi cfg data may cause race condition as we cleared info in kif close
     * and fresh data written in callback is being resetted here.*/
    if(!NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link))
    {
      netmgr_qmi_reset_link_wds_data(cmd_buf->data.link);
    }

    /* reset link_powerup state to DOWN */
    netmgr_kif_set_link_powerup_state(cmd_buf->data.link,
                                      NETMGR_KIF_LINK_POWERUP_STATE_DOWN);

    link_name = netmgr_kif_get_name(cmd_buf->data.link);
    if (NULL == link_name)
    {
      netmgr_log_err("%s(): unable to determine name for link=%d\n",
                      __func__, cmd_buf->data.link);
    }
    else
    {
      /* Post event indication to clients */
      event_info = netmgr_malloc( sizeof(netmgr_nl_event_info_t) );
      if( NULL == event_info ) {
        netmgr_log_err("failed to allocate event buffer!\n");
      } else {
        memset( event_info, 0x0, sizeof(netmgr_nl_event_info_t) );
        event_info->event = NET_PLATFORM_DOWN_EV;
        event_info->link = cmd_buf->data.link;
        event_info->param_mask |= NETMGR_EVT_PARAM_LINK;
        strlcpy( event_info->dev_name,
                 link_name,
                 sizeof(event_info->dev_name) );
        event_info->param_mask |= NETMGR_EVT_PARAM_DEVNAME;
        event_info->cmd_data.modem_subs_id = netmgr_qmi_cfg.links[event_info->link].modem_subs_id;
        event_info->param_mask |= NETMGR_EVT_PARAM_CMD_DATA;
        if( NETMGR_SUCCESS != netmgr_kif_send_event_msg( event_info ) ) {
          netmgr_log_err("failed on kif_send_event DOWN\n");
        }

        netmgr_free( event_info );
      }
    }
#if defined(FEATURE_DS_LINUX_ANDROID) && !defined(NETMGR_OFFTARGET)
    netmgr_util_wakelock_release();
#endif

  }
} /* netmgr_sm_state_inited_entry() */

/*===========================================================================

  STATE EXIT FUNCTION:  netmgr_sm_state_inited_exit

===========================================================================*/
/*!
    @brief
    Exit function for state machine NETMGR_SM,
    state NETMGR_STATE_INITED

    @detail
    Called upon exit of this state of the state machine, with optional
    user-passed payload pointer parameter. The prior state of the state
    machine is also passed as the prev_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_inited_exit
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         next_state,  /*!< Next state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( next_state );
  STM_UNUSED( sm );

} /* netmgr_sm_state_inited_exit() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_modem_connected

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_DOWN,
    upon receiving input NETMGR_WDS_CONNECTED_EV

    @detail
    Called upon receipt of input NETMGR_WDS_CONNECTED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_modem_connected
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  netmgr_log_med("Recvd NETMGR_WDS_CONNECTED_EV on link=%d\n",
                 cmd_buf->data.link);

  if (0 != cmd_buf->repost_count) {
    netmgr_log_err("ignoring stale modem connect indication on link=%d\n",
                   cmd_buf->data.link);
    goto bail;
  }

#if defined(FEATURE_DATA_LINUX_LE) && defined(FEATURE_DATA_LINUX_EMBMS_ODU)
  if( WDS_TECHNOLOGY_NAME_EMBMS_V01 == netmgr_qmi_wds_get_tech_name(cmd_buf->data.link) )
  {
    netmgr_kif_ipa_ioctl_set_dev_name(netmgr_kif_get_name(cmd_buf->data.link));
  }
#endif

  /* Initiate KIF interface open process */
  if( NETMGR_SUCCESS !=
      netmgr_kif_iface_open( (uint8)cmd_buf->data.link,
                             cmd_buf->data.info.connect_msg.addr_info_ptr,
                             NULL, NULL ) ) {
    netmgr_log_err("failed on kif_iface_open\n");

    /* Force platform interface to close */
    (void)netmgr_kif_iface_close( (uint8)cmd_buf->data.link,
                                  cmd_buf->data.info.connect_msg.addr_info_ptr,
                                  TRUE );
    next_state = NETMGR_STATE_INITED;
  }
  else {
    /* Intial Modem interface connect, transition to COMING_UP state */
    next_state = NETMGR_STATE_COMING_UP;
  }

bail:
  /* Release heap memory allocated in QMI module */
  if (NULL != cmd_buf
      && NULL != cmd_buf->data.info.connect_msg.addr_info_ptr)
  {
    ds_free( cmd_buf->data.info.connect_msg.addr_info_ptr );
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_modem_connected() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_modem_disconnected_in_inited

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_INITED,
    upon receiving input NETMGR_WDS_DISCONNECTED_EV

    @detail
    Called upon receipt of input NETMGR_WDS_DISCONNECTED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_modem_disconnected_in_inited
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

#ifdef FEATURE_DATA_IWLAN
  if (NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    /* We don't expect NETMGR_WDS_DISCONNECTED_EV for reverse links in NETMGR_STATE_INITED
     * Hoever if we do receive it we need to send a config complete event with CLEANUP so that
     * all previous transactions are cleaned up and the state machine moves back to a working
     * condition */

     /* Send CLEANUP command for V4 */
     netmgr_qmi_send_rev_ip_config_complete(NETMGR_QMI_IWLAN_CALL_CLEANUP,
                                            cmd_buf->data.link,
                                            AF_INET,
                                            NETMGR_SUCCESS);

     /* Send CLEANUP command for V6 */
     netmgr_qmi_send_rev_ip_config_complete(NETMGR_QMI_IWLAN_CALL_CLEANUP,
                                            cmd_buf->data.link,
                                            AF_INET6,
                                            NETMGR_SUCCESS);
  }
#endif /* FEATURE_DATA_IWLAN */

  /* Getting NETMGR_WDS_DISCONNECTED event in INITED state should keep the state
   * machine in inited state */
  next_state = NETMGR_STATE_INITED;

  /* Release heap memory allocated in QMI module */
  if (NULL != cmd_buf
      && NULL != cmd_buf->data.info.connect_msg.addr_info_ptr)
  {
    ds_free( cmd_buf->data.info.connect_msg.addr_info_ptr );
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_modem_connected() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_modem_connected_while_going_down

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_GOING_DOWN,
    upon receiving input NETMGR_WDS_CONNECTED_EV

    @detail
    Called upon receipt of input NETMGR_WDS_CONNECTED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_modem_connected_while_going_down
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

#ifdef FEATURE_DATA_IWLAN
  if (NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    /* The reverse Rmnet link would be kept in the UP state as long as there's an
       associated forward Rmnet (i.e with same address configuration). In such a
       case we can configure the address and directly transition the reverse Rmnet
       SM to UP state */
    if (NETMGR_LINK_MAX != netmgr_qmi_iwlan_get_link_assoc(cmd_buf->data.link))
    {
      /* Initiate KIF interface configuration process */
      if( NETMGR_SUCCESS !=
          netmgr_kif_iface_configure( (uint8)cmd_buf->data.link,
                                      netmgr_qmi_get_ip_addr_type_first_conn_clnt( cmd_buf->data.link ) ) )
      {
        netmgr_log_err("failed on kif_iface_configure\n");

        /* Force platform interface to close */
        (void)netmgr_kif_iface_close( (uint8)cmd_buf->data.link, NULL, TRUE );
        next_state = NETMGR_STATE_INITED;
      }
      else
      {
        next_state = NETMGR_STATE_UP;

        /* During rekey scenario, reverse rmnet address are purged and reconfigured. Since we
           are directly assigning the addresses on the interface without waiting for RTM_NEWADDR
           it is safe to assume that address configuration has completed at this sateg. We can
           safely release the wakelock */
#if defined(FEATURE_DS_LINUX_ANDROID) && !defined(NETMGR_OFFTARGET)
        netmgr_util_wakelock_release();
#endif
      }
    }
    else
    {
      if(cmd_buf->repost_count == 0 )
      {
        /*  Modem interface connect while going down,
            transition to GOING_DOWN_TO_COME_UP state
            This is a valid connected ev coming from modem */
        next_state = NETMGR_STATE_GOING_DOWN_TO_COME_UP;
      }
      /* else {
         This event is being reposted locally from netmgr
         Ignore this connected ev when in going down state
      } */
    }
  }
  else
#endif /* FEATURE_DATA_IWLAN */
  {
    if( 0 == cmd_buf->repost_count)
    {
      /*  Modem interface connect while going down,
          transition to GOING_DOWN_TO_COME_UP state.
          This is a valid connected ev coming from modem */
      next_state = NETMGR_STATE_GOING_DOWN_TO_COME_UP;
    }
    /* else {
       This event is being reposted locally from netmgr
       Ignore this connected ev when in going down state
    } */
  }

  /* Release heap memory allocated in QMI module */
  if (NULL != cmd_buf
      && NULL != cmd_buf->data.info.connect_msg.addr_info_ptr)
  {
    ds_free( cmd_buf->data.info.connect_msg.addr_info_ptr );
    cmd_buf->data.info.connect_msg.addr_info_ptr = NULL;
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_modem_connected_while_going_down() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_dispatch_kif_msg

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_DOWN,
    upon receiving input NETMGR_KIF_MSG_CMD

    @detail
    Called upon receipt of input NETMGR_KIF_MSG_CMD, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_dispatch_kif_msg
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Post message to the KIF module for local processing */
  if( NETMGR_SUCCESS !=
      netmgr_kif_dispatch( &cmd_buf->cmd,
                           &cmd_buf->data.info.kif_msg ) ) {
    netmgr_log_err("kif dispatch failed\n");
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_dispatch_kif_msg() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_dispatch_qmi_msg

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_DOWN,
    upon receiving input NETMGR_QMI_MSG_CMD

    @detail
    Called upon receipt of input NETMGR_QMI_MSG_CMD, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_dispatch_qmi_msg
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Post message to the QMI module for local processing */
  if( NETMGR_SUCCESS !=
      netmgr_qmi_dispatch( &cmd_buf->cmd,
                           (void*)&cmd_buf->data.info.qmi_msg ) ) {
    netmgr_log_err("failed on qmi_dispatch\n");
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_dispatch_qmi_msg() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_modem_oos_msg

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_DOWN,
    upon receiving input NETMGR_MODEM_OOS_EV

    @detail
    Called upon receipt of input NETMGR_MODEM_OOS_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_modem_oos_msg
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;
  int link_num;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  link_num = cmd_buf->data.link;

  if ((link_num < 0) || (link_num >= netmgr_main_cfg.max_links_in_total)) {
    netmgr_log_err("invalid link num: %d", link_num);
    NETMGR_LOG_FUNC_EXIT;
    return( next_state );
  }

  /* perform kif clean-up */
  if (NETMGR_SUCCESS != netmgr_kif_out_of_service(link_num))
  {
    netmgr_log_err("failed to execute kif out_of_service\n");
  }

  /* release qmi clients */
  if (NETMGR_SUCCESS != netmgr_qmi_out_of_service(link_num))
  {
    netmgr_log_err("failed to execute qmi out_of_service\n");
  }

  /* Disable on-demand links so that when back in-service they arent created */
  if (netmgr_qmi_cfg.link_array[link_num].on_demand) {
    netmgr_qmi_cfg.link_array[link_num].on_demand = FALSE;
    netmgr_qmi_cfg.link_array[link_num].enabled = FALSE;
    next_state = STM_DEACTIVATED_STATE;
  }
  else
  {
    next_state = NETMGR_STATE_DOWN;
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_modem_oos_msg() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_modem_is_msg

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_DOWN,
    upon receiving input NETMGR_MODEM_IS_EV

    @detail
    Called upon receipt of input NETMGR_MODEM_IS_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_modem_is_msg
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;
  int ret_code = NETMGR_FAILURE;
  int link_num;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  link_num = cmd_buf->data.link;

  netmgr_log_med("%s(): configuring link %d w/ type %d", __func__,
                 link_num, cmd_buf->data.type);

  if (NETMGR_MODEM_OOS_STATE == NETMGR_GET_MODEM_SSR_STATE()) {
      netmgr_log_err("%s(): Rcvd OOS, skip trying to init link %d",
                     __func__, link_num);
      goto bail;
  }

  if (netmgr_main_cfg.dynamic_link_creation)
  {
    if(NETMGR_SUCCESS != netmgr_rmnet_configure_embedded_link(link_num))
    {
      netmgr_log_err("failed to configure embedded link %d", link_num);
      goto bail;
    }

    if(NETMGR_SUCCESS != netmgr_rmnet_change_embedded_link(link_num))
    {
      netmgr_log_err("failed to change embedded link %d", link_num);
      goto bail;
    }
  }

  /* reset qmi module */
  if( NETMGR_SUCCESS != netmgr_qmi_reset(link_num) ) {
    netmgr_log_err("failed on qmi_reset\n");
    goto bail;
  }

  /* Note: we intentionally do not reset kif when modem is out
   * of service, because doing so seems to cause err_fatal on the
   * modem side. Moving this operation when modem is resumed, however
   * seems to be working */
  /* reset kif ifaces */
  if( NETMGR_SUCCESS != netmgr_kif_reset(link_num, cmd_buf->data.type) ) {
    netmgr_log_err("failed on kif_reset\n");
    goto bail;
  }

  next_state = NETMGR_STATE_INITED;
  ret_code = NETMGR_SUCCESS;

  netmgr_log_med("%s(): successfully configured link %d", __func__, link_num);

bail:
  cmd_buf->data.ret_code = ret_code;

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_modem_is_msg() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_modem_reset_msg

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_DOWN,
    upon receiving input NETMGR_RESET_MSG_CMD

    @detail
    Called upon receipt of input NETMGR_RESET_MSG_CMD, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_modem_reset_msg
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Reset each modoule */
  if( NETMGR_SUCCESS != netmgr_qmi_reset(cmd_buf->data.link) ) {
    netmgr_log_err("failed on qmi_reset\n");
  }
  if( NETMGR_SUCCESS != netmgr_kif_reset(cmd_buf->data.link, cmd_buf->data.type) ) {
    netmgr_log_err("failed on kif_reset\n");
  }
#ifdef NETMGR_QOS_ENABLED
  if( netmgr_main_get_qos_enabled() &&
      !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    if( NETMGR_SUCCESS != netmgr_tc_reset(cmd_buf->data.link) ) {
      netmgr_log_err("failed on tc_reset\n");
    }
  }
#endif

  next_state = NETMGR_STATE_INITED;

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_modem_reset_msg() */


/*===========================================================================

     (State Machine: NETMGR_SM)
     STATE ENTRY/EXIT/TRANSITION FUNCTIONS: NETMGR_STATE_COMING_UP

===========================================================================*/

/*===========================================================================

  STATE ENTRY FUNCTION:  netmgr_sm_state_comingup_entry

===========================================================================*/
/*!
    @brief
    Entry function for state machine NETMGR_SM,
    state NETMGR_STATE_COMING_UP

    @detail
    Called upon entry into this state of the state machine, with optional
    user-passed payload pointer parameter.  The prior state of the state
    machine is also passed as the prev_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_comingup_entry
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         prev_state,  /*!< Previous state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( prev_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
} /* netmgr_sm_state_comingup_entry() */


/*===========================================================================

  STATE EXIT FUNCTION:  netmgr_sm_state_comingup_exit

===========================================================================*/
/*!
    @brief
    Exit function for state machine NETMGR_SM,
    state NETMGR_STATE_COMING_UP

    @detail
    Called upon exit of this state of the state machine, with optional
    user-passed payload pointer parameter.  The impending state of the state
    machine is also passed as the next_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_comingup_exit
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         next_state,  /*!< Next state */
  void                *payload     /*!< Payload pointer */
)
{
  NETMGR_LOG_FUNC_ENTRY;

  STM_UNUSED( sm );
  STM_UNUSED( next_state );
  STM_UNUSED( payload );

  NETMGR_LOG_FUNC_EXIT;
  return;

} /* netmgr_sm_state_comingup_exit() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_modem_disconnected

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_COMING_UP,
    upon receiving input NETMGR_WDS_DISCONNECTED_EV

    @detail
    Called upon receipt of input NETMGR_WDS_DISCONNECTED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_modem_disconnected
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Initiate KIF interface close process */
  if( NETMGR_SUCCESS !=
      netmgr_kif_iface_close( (uint8)cmd_buf->data.link,
                              cmd_buf->data.info.disconnect_msg.addr_info_ptr,
                              cmd_buf->data.info.disconnect_msg.teardown_iface ) ) {
    netmgr_log_err("failed on kif_iface_close\n");

    next_state = NETMGR_STATE_INITED;
  }
  else {
    /* For some cases, leave interface state unchanged on disconnect;
     * otherwise trigger teardown. */
    if( cmd_buf->data.info.disconnect_msg.teardown_iface )
    {
      next_state = NETMGR_STATE_GOING_DOWN;
    }
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_modem_disconnected() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_kif_opened

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_COMING_UP,
    upon receiving input NETMGR_KIF_OPENED_EV

    @detail
    Called upon receipt of input NETMGR_KIF_OPENED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_kif_opened
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;
  wds_technology_name_enum_v01 tech_type = WDS_TECHNOLOGY_NAME_ENUM_MIN_ENUM_VAL_V01;

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  tech_type = netmgr_qmi_wds_get_tech_name(cmd_buf->data.link);

  /* skip iface config if tech name is EMBMS */
  if( WDS_TECHNOLOGY_NAME_EMBMS_V01 == tech_type )
  {
    next_state = NETMGR_STATE_UP;
    /* IPv6 is normally enabled based on WDS indications only.
     * For EMBMS, no additional address configuration is needed,
     * so this does not have to go through entire state machine.
     * Enable IPv6 here so that interface can listen for multicast
     * IPv6 packets.
     */
    netmgr_kif_enable_ipv6((uint8)cmd_buf->data.link);
    netmgr_l2s_msg(netmgr_l2s_invalid_link, "EMBMS enabled");
  }
  else
  {
    /* Initiate KIF interface configuration process */
    if( NETMGR_SUCCESS !=
        netmgr_kif_iface_configure( (uint8)cmd_buf->data.link,
                                    netmgr_qmi_get_ip_addr_type_first_conn_clnt( cmd_buf->data.link ) ) ) {
      netmgr_log_err("failed on kif_iface_configure\n");

      /* Force platform interface to close */
      (void)netmgr_kif_iface_close( (uint8)cmd_buf->data.link, NULL, TRUE );
      next_state = NETMGR_STATE_INITED;
    }
    else if ( NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) ) {
      /* Local breakout reverse rmnet link is not assigned any ip address so we
         can directly move it to up state after returning from kif_iface_configure

         For other reverse rmnets also we don't rely on SLACC for address configuration
         since we are manually assigning the address on the interface. We don't need to
         wait for NEWADDR event to move the SM to UP state */
      next_state = NETMGR_STATE_UP;
      if (WDS_TECHNOLOGY_NAME_WLAN_LOCAL_BRKOUT_V01 == tech_type) {
        netmgr_l2s_msg(netmgr_l2s_invalid_link, "Local break-out enabled");
      }

#if defined(FEATURE_DS_LINUX_ANDROID) && !defined(NETMGR_OFFTARGET)
      /* Link configuration for LBO interface is complete, release wakelock */
      netmgr_util_wakelock_release();
#endif
    }
    else {
      next_state = NETMGR_STATE_CONFIGURING;
    }
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_kif_opened() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_kif_opened_while_going_down

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_GOING_DOWN_TO_COME_UP,
    upon receiving input NETMGR_KIF_OPENED_EV

    @detail
    Called upon receipt of input NETMGR_KIF_OPENED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_kif_opened_while_going_down
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Force platform interface to close */
  (void)netmgr_kif_iface_close( (uint8)cmd_buf->data.link, NULL, TRUE );

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_kif_opened_while_going_down() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_kif_closed

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_COMING_UP,
    upon receiving input NETMGR_KIF_CLOSED_EV

    @detail
    Called upon receipt of input NETMGR_KIF_CLOSED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_kif_closed
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;
  int i;

  wds_technology_name_enum_v01 tech_type = WDS_TECHNOLOGY_NAME_ENUM_MIN_ENUM_VAL_V01;
  netmgr_qmi_qos_flow_info_t qos_flow;

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_UNUSED( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  tech_type = netmgr_qmi_wds_get_tech_name(cmd_buf->data.link);

#ifdef NETMGR_QOS_ENABLED
  if( netmgr_main_get_qos_enabled() &&
      !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    /* Initiate Traffic Control root flow delete process */
    memset(&qos_flow, 0, sizeof(qos_flow));
    qos_flow.flow_id = NETMGR_QMI_PRIMARY_FLOW_ID; // ip_ver not used
    if (NETMGR_SUCCESS !=
        netmgr_tc_flow_delete(cmd_buf->data.link, &qos_flow))
    {
      netmgr_log_err("failed on tc_flow_delete\n");
    }

    /*Delete the cached qos flows and filters*/
    for (i =0 ; i < NETMGR_QOS_MAX_FLOW_FILTER; i++)
    {
      if (netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i])
      {
        free(netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i]);
        netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i] = NULL;
      }
    }

  }
#endif /* NETMGR_QOS_ENABLED */

  /* We might get a NETMGR_KIF_CLOSED_EV on the link before OOS_EV is received depending
     on when global rmnet cleanup happens. After CLOSED_EV is processed the link moves to
     inited state where we cleanup all the WDS state for that link. However the WDS state
     information is used for reverse rmnet rule cleanups. Hence we need to call the
     kif_out_of_reset function here */
  if ((NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link)
        && NETMGR_STATE_UP == stm_get_state(&NETMGR_SM[cmd_buf->data.link]))
      || WDS_TECHNOLOGY_NAME_MODEM_LINK_LOCAL_V01 == tech_type)
  {
    if (NETMGR_SUCCESS != netmgr_kif_out_of_service(cmd_buf->data.link))
    {
      netmgr_log_err("failed to execute kif out_of_service\n");
      goto bail;
    }
  }

  next_state = NETMGR_STATE_INITED;

bail:
  NETMGR_LOG_FUNC_EXIT;
  return( next_state );
} /* netmgr_sm_kif_closed() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_kif_down_to_come_up

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_COMING_UP,
    upon receiving input NETMGR_KIF_CLOSED_EV

    @detail
    Called upon receipt of input NETMGR_KIF_CLOSED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_kif_down_to_come_up
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;
  netmgr_address_info_t * addr_info = NULL;
  netmgr_address_set_t * addr_info_ptr = NULL;
  netmgr_ip_addr_t ip_type = NETMGR_IP_ADDR_INVALID;
  netmgr_qmi_qos_flow_info_t qos_flow;

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_UNUSED( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

#ifdef NETMGR_QOS_ENABLED
  if( netmgr_main_get_qos_enabled() &&
      !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    /* Initiate Traffic Control root flow delete process */
    memset(&qos_flow, 0, sizeof(qos_flow));
    qos_flow.flow_id = NETMGR_QMI_PRIMARY_FLOW_ID; // ip_ver not used
    if (NETMGR_SUCCESS !=
        netmgr_tc_flow_delete(cmd_buf->data.link, &qos_flow))
    {
      netmgr_log_err("failed on tc_flow_delete\n");
    }
  }
#endif /* NETMGR_QOS_ENABLED */

#ifdef FEATURE_DATA_IWLAN
    if (NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link))
    {
      int ip_family, config_status;

      if (NETMGR_SUCCESS != netmgr_qmi_retrieve_rev_ip_config_status(cmd_buf->data.link, &ip_family, &config_status))
      {
        netmgr_log_med("netmgr_sm_state_inited_entry: failed to get rev IP config status for link=%d, ignoring\n",
                       cmd_buf->data.link);
      }
      else
      {
        netmgr_qmi_send_rev_ip_config_complete(NETMGR_QMI_IWLAN_CALL_CLEANUP,
                                               cmd_buf->data.link,
                                               ip_family,
                                               config_status);
      }
    }
#endif /* FEATURE_DATA_IWLAN */

  cmd_buf = (netmgr_exec_cmd_t *)payload;
  addr_info = netmgr_qmi_get_addr_info(cmd_buf->data.link);

  ip_type = netmgr_qmi_get_ip_addr_type_first_conn_clnt( cmd_buf->data.link );
  switch(ip_type)
  {
    case NETMGR_IPV4_ADDR:
      addr_info_ptr = &addr_info->ipv4;
      break;

    case NETMGR_IPV6_ADDR:
      addr_info_ptr = &addr_info->ipv6;
      break;

    default:
      netmgr_log_err("First conn client not set to valid family. defaulting to V4\n");
      addr_info_ptr = &addr_info->ipv4;
      break;
  }

  if (NULL == addr_info)
  {
    netmgr_log_err("failed to get addr_info\n");
    next_state = NETMGR_STATE_DOWN;
  }
  /* Initiate KIF interface open process */
  else if( NETMGR_SUCCESS !=
      netmgr_kif_iface_open( (uint8)cmd_buf->data.link,
                             addr_info_ptr,
                             NULL, NULL ) ) {
    netmgr_log_err("failed on kif_iface_open\n");

    /* Force platform interface to close */
    (void)netmgr_kif_iface_close( (uint8)cmd_buf->data.link,
                                  addr_info_ptr,
                                  TRUE );
    next_state = NETMGR_STATE_DOWN;
  }
  else
  {
    next_state = NETMGR_STATE_COMING_UP;
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );
} /* netmgr_sm_kif_down_to_come_up() */

/*===========================================================================

     (State Machine: NETMGR_SM)
     STATE ENTRY/EXIT/TRANSITION FUNCTIONS: NETMGR_STATE_CONFIGURING

===========================================================================*/

/*===========================================================================

  STATE ENTRY FUNCTION:  netmgr_sm_state_configuring_entry

===========================================================================*/
/*!
    @brief
    Entry function for state machine NETMGR_SM,
    state NETMGR_STATE_CONFIGURING

    @detail
    Called upon entry into this state of the state machine, with optional
    user-passed payload pointer parameter.  The prior state of the state
    machine is also passed as the prev_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_configuring_entry
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         prev_state,  /*!< Previous state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( prev_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
} /* netmgr_sm_state_configuring_entry() */


/*===========================================================================

  STATE EXIT FUNCTION:  netmgr_sm_state_configuring_exit

===========================================================================*/
/*!
    @brief
    Exit function for state machine NETMGR_SM,
    state NETMGR_STATE_CONFIGURING

    @detail
    Called upon exit of this state of the state machine, with optional
    user-passed payload pointer parameter.  The impending state of the state
    machine is also passed as the next_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_configuring_exit
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         next_state,  /*!< Next state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( next_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
} /* netmgr_sm_state_configuring_exit() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_repost_modem_connected

===========================================================================*/
/*!
    @brief

    @detail
    Called upon receipt of input NETMGR_WDS_CONNECTED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_repost_modem_connected
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf;
  netmgr_exec_cmd_t * new_cmd;
  unsigned int repost_delay = 0;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  if( cmd_buf->repost_count < NETMGR_EXEC_MAX_CMD_REPOST_LIMIT )
  {
    new_cmd = netmgr_exec_get_cmd();
    NETMGR_ASSERT(new_cmd);

    new_cmd->data = cmd_buf->data;
    new_cmd->repost_count = cmd_buf->repost_count + 1;

    /* Use exponential back off starting with NETMGR_EXEC_REPOST_STEP_MICROSECS */
    repost_delay = (unsigned int)((1 << cmd_buf->repost_count) * NETMGR_EXEC_REPOST_STEP_MICROSECS);

    /* Limit the max repost_delay to 1 second */
    repost_delay = (repost_delay > NETMGR_EXEC_MICROSECS_PER_SEC) ?
                   NETMGR_EXEC_MICROSECS_PER_SEC :
                   repost_delay;

    netmgr_log_med("Reposting connect event on link[%d] repost_count[%d] repost_delay[%u] usec\n",
                   cmd_buf->data.link,
                   cmd_buf->repost_count,
                   repost_delay);

    usleep(repost_delay);

    if( NETMGR_SUCCESS != netmgr_exec_put_cmd( new_cmd ) ) {
      NETMGR_ABORT("netmgr_sm_repost_modem_connected: failed to put commmand\n");
      if (NULL != new_cmd
          && NULL != new_cmd->data.info.connect_msg.addr_info_ptr)
      {
        ds_free( new_cmd->data.info.connect_msg.addr_info_ptr );
      }
      netmgr_exec_release_cmd(new_cmd);
    }
  }
  else
  {
    if (NULL != cmd_buf
        && NULL != cmd_buf->data.info.connect_msg.addr_info_ptr)
    {
      ds_free( cmd_buf->data.info.connect_msg.addr_info_ptr );
      cmd_buf->data.info.connect_msg.addr_info_ptr = NULL;
    }
  }

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );
} /* netmgr_sm_repost_modem_connected() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_kif_configured

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_CONFIGURING,
    upon receiving input NETMGR_KIF_CONFIGURED_EV

    @detail
    Called upon receipt of input NETMGR_KIF_CONFIGURED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_kif_configured
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

#ifdef NETMGR_QOS_ENABLED
  if( netmgr_main_get_qos_enabled() &&
      !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    {
      int i = 0;

      netmgr_log_med("activating cached flows");

      for (i =0; i < NETMGR_QOS_MAX_FLOW_FILTER; i++)
      {
        if (netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i] != NULL)
        {
          /* Initiate Traffic Control flow create process */
          if( NETMGR_SUCCESS !=
              netmgr_tc_flow_activate( cmd_buf->data.link,
                                       netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i] ) )
          {
            netmgr_log_err("failed on tc_flow_activate\n");
          }
          free(netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i]);
          netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i] = NULL;
        }
      }
    }
  }
#endif /* NETMGR_QOS_ENABLED */

#if defined(FEATURE_DS_LINUX_ANDROID) && !defined(NETMGR_OFFTARGET)
  /* For iWLAN data calls we would have acquired a wakelock at the time of receiving the indication
     After the interface is configured and moved to UP state we need to release the wakelock */
  netmgr_util_wakelock_release();
#endif

  next_state = NETMGR_STATE_UP;

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_kif_configured() */


/*===========================================================================

     (State Machine: NETMGR_SM)
     STATE ENTRY/EXIT/TRANSITION FUNCTIONS: NETMGR_STATE_RECONFIGURING

===========================================================================*/

/*===========================================================================

  STATE ENTRY FUNCTION:  netmgr_sm_state_reconfiguring_entry

===========================================================================*/
/*!
    @brief
    Entry function for state machine NETMGR_SM,
    state NETMGR_STATE_RECONFIGURING

    @detail
    Called upon entry into this state of the state machine, with optional
    user-passed payload pointer parameter.  The prior state of the state
    machine is also passed as the prev_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_reconfiguring_entry
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         prev_state,  /*!< Previous state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( prev_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
} /* netmgr_sm_state_reconfiguring_entry() */


/*===========================================================================

  STATE EXIT FUNCTION:  netmgr_sm_state_reconfiguring_exit

===========================================================================*/
/*!
    @brief
    Exit function for state machine NETMGR_SM,
    state NETMGR_STATE_RECONFIGURING

    @detail
    Called upon exit of this state of the state machine, with optional
    user-passed payload pointer parameter.  The impending state of the state
    machine is also passed as the next_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_reconfiguring_exit
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         next_state,  /*!< Next state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( next_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
} /* netmgr_sm_state_reconfiguring_exit() */


/*===========================================================================

     (State Machine: NETMGR_SM)
     STATE ENTRY/EXIT/TRANSITION FUNCTIONS: NETMGR_STATE_UP

===========================================================================*/

/*===========================================================================

  STATE ENTRY FUNCTION:  netmgr_sm_state_up_entry

===========================================================================*/
/*!
    @brief
    Entry function for state machine NETMGR_SM,
    state NETMGR_STATE_UP

    @detail
    Called upon entry into this state of the state machine, with optional
    user-passed payload pointer parameter.  The prior state of the state
    machine is also passed as the prev_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_up_entry
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         prev_state,  /*!< Previous state */
  void                *payload     /*!< Payload pointer */
)
{
  netmgr_exec_cmd_t * cmd_buf = NULL;
  netmgr_nl_events_t event = NET_PLATFORM_INVALID_EV;
  netmgr_nl_event_info_t * event_info = NULL;
  netmgr_address_set_t * modem_addr_ptr = NULL;
  netmgr_nl_addr_info_t * nl_addr_ptr = NULL;
  const char *dev_name = NULL;
  boolean xlat_state = FALSE;

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;
  modem_addr_ptr = cmd_buf->data.info.connect_msg.addr_info_ptr;
  nl_addr_ptr = &cmd_buf->data.info.connect_msg.nlmsg_info.addr_info;

  dev_name = netmgr_kif_get_name(cmd_buf->data.link);
  if(dev_name == NULL)
  {
    netmgr_log_err("%s(): unable to determine name for link=%d\n",
                    __func__, cmd_buf->data.link);
    goto bail;
  }

  event = (NETMGR_STATE_RECONFIGURING == prev_state)?
          NET_PLATFORM_RECONFIGURED_EV :  NET_PLATFORM_UP_EV;

  /* Post event indication to clients */
  event_info = netmgr_malloc( sizeof(netmgr_nl_event_info_t) );
  if( NULL == event_info ) {
    netmgr_log_err("failed to allocate event buffer!\n");
  } else {
    memset( event_info, 0x0, sizeof(netmgr_nl_event_info_t) );
    event_info->event = event;
    event_info->link = cmd_buf->data.link;
    event_info->param_mask |= NETMGR_EVT_PARAM_LINK;
    strlcpy( event_info->dev_name,
             dev_name,
             sizeof(event_info->dev_name) );
    event_info->param_mask |= NETMGR_EVT_PARAM_DEVNAME;

    /* Populate address elements */
    if( modem_addr_ptr )
    {
      if( NETMGR_IP_ANY_ADDR != modem_addr_ptr->gateway.type ) {
        NETMGR_CONV_TO_SOCKADDR( &modem_addr_ptr->gateway, &event_info->gtwy_info.ip_addr );
        event_info->gtwy_info.mask = modem_addr_ptr->gw_mask;
        event_info->param_mask |= NETMGR_EVT_PARAM_GTWYINFO;
      }

      if( NETMGR_IP_ANY_ADDR != modem_addr_ptr->dns_primary.type ) {
        NETMGR_CONV_TO_SOCKADDR( &modem_addr_ptr->dns_primary, &event_info->dnsp_addr );
        event_info->param_mask |= NETMGR_EVT_PARAM_DNSPADDR;
      }

      if( NETMGR_IP_ANY_ADDR != modem_addr_ptr->dns_secondary.type ) {
        NETMGR_CONV_TO_SOCKADDR( &modem_addr_ptr->dns_secondary, &event_info->dnss_addr );
        event_info->param_mask |= NETMGR_EVT_PARAM_DNSSADDR;
      }

      if( NETMGR_NLA_PARAM_PREFIXADDR & nl_addr_ptr->attr_info.param_mask ) {
        memcpy( &event_info->addr_info.addr.ip_addr,
                &nl_addr_ptr->attr_info.prefix_addr,
                sizeof(event_info->addr_info.addr.ip_addr) );
        event_info->addr_info.addr.mask = (unsigned int)ds_get_num_bits_set_count(modem_addr_ptr->if_mask);
        event_info->param_mask |= NETMGR_EVT_PARAM_IPADDR;
      }
      if( NETMGR_NLA_PARAM_CACHEINFO & nl_addr_ptr->attr_info.param_mask ) {
        memcpy( &event_info->addr_info.cache_info,
                &nl_addr_ptr->attr_info.cache_info,
                sizeof(event_info->addr_info.cache_info) );
        event_info->param_mask |= NETMGR_EVT_PARAM_CACHE;
      }

      event_info->mtu = netmgr_kif_get_mtu(cmd_buf->data.link);
      event_info->param_mask |= NETMGR_EVT_PARAM_MTU;

      event_info->cmd_data.modem_subs_id = netmgr_qmi_cfg.links[event_info->link].modem_subs_id;
      event_info->param_mask |= NETMGR_EVT_PARAM_CMD_DATA;
#ifdef FEATURE_DATA_IWLAN
      if( NETMGR_NLA_PARAM_PREFIXADDR & nl_addr_ptr->attr_info.param_mask ) {
        (void)netmgr_qmi_iwlan_update_link_assoc(cmd_buf->data.link, NULL);
      }
#endif /* FEATURE_DATA_IWLAN */

      xlat_state = netmgr_qmi_get_xlat_state(cmd_buf->data.link);
      if (TRUE == xlat_state)
      {
        netmgr_kif_ifioctl_set_xlat_dev_info(netmgr_main_cfg.phys_net_dev,
                                             dev_name);
      }
    }

    if( NETMGR_SUCCESS != netmgr_kif_send_event_msg( event_info ) ) {
      netmgr_log_err("failed on kif_send_event UP\n");
    }

    netmgr_free( event_info );
  }

bail:
  NETMGR_LOG_FUNC_EXIT;
} /* netmgr_sm_state_up_entry() */


/*===========================================================================

  STATE EXIT FUNCTION:  netmgr_sm_state_up_exit

===========================================================================*/
/*!
    @brief
    Exit function for state machine NETMGR_SM,
    state NETMGR_STATE_UP

    @detail
    Called upon exit of this state of the state machine, with optional
    user-passed payload pointer parameter.  The impending state of the state
    machine is also passed as the next_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_up_exit
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         next_state,  /*!< Next state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( next_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
} /* netmgr_sm_state_up_exit() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_modem_reconfig

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_UP,
    upon receiving input NETMGR_WDS_CONNECTED_EV

    @detail
    Called upon receipt of input NETMGR_WDS_CONNECTED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_modem_reconfig
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf;

  NETMGR_LOG_FUNC_ENTRY;

  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Initiate KIF interface reconfiguration process */
  if( NETMGR_SUCCESS !=
      netmgr_kif_iface_reconfigure( (uint8)cmd_buf->data.link,
                                    cmd_buf->data.info.connect_msg.addr_info_ptr ) ) {
    netmgr_log_err("failed on kif_iface_configure\n");

    /* Force platform interface to close */
    (void)netmgr_kif_iface_close( (uint8)cmd_buf->data.link, NULL, TRUE );
    next_state = NETMGR_STATE_INITED;
  }
#ifdef FEATURE_DATA_IWLAN
  /* Local breakout reverse rmnet link is not assigned any ip address so we
     can directly move it to up state after returning from kif_iface_configure

     For other reverse rmnets also we don't rely on SLACC for address configuration
     since we are manually assigning the address on the interface. We don't need to
     wait for NEWADDR event to move the SM to UP state */
  else if ( NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) ) {
    next_state = NETMGR_STATE_UP;
  }
#endif
  else {
    /* Reconfiguration due to Modem interface address change,
     * transition to RECONFIGURING state */
    next_state = NETMGR_STATE_RECONFIGURING;
  }

  /* Release heap memory allocated in QMI module */
  ds_free( cmd_buf->data.info.connect_msg.addr_info_ptr );

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );

} /* netmgr_sm_modem_reconfig() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_qos_activate

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_UP,
    upon receiving input NETMGR_QOS_ACTIVATE_EV

    @detail
    Called upon receipt of input NETMGR_QOS_ACTIVATE_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_qos_activate
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
#ifdef NETMGR_QOS_ENABLED
  netmgr_exec_cmd_t * cmd_buf = NULL;
  netmgr_nl_event_info_t * event_info = NULL;
  int i =0;
  const char *dev_name = NULL;
  NETMGR_LOG_FUNC_ENTRY;

  STM_UNUSED( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Special handling where QOS_ACTIVATE event comes very soon
   * after WDS_CONNECTED. In this case we store the flow and filter
   * spec and configure them later when the kernel interface is UP
   * and running.
   */
  if (sm->current_state == NETMGR_STATE_COMING_UP ||
        sm->current_state == NETMGR_STATE_INITED ||
        sm->current_state == NETMGR_STATE_CONFIGURING ||
        sm->current_state == NETMGR_STATE_RECONFIGURING)
  {
    for (i = 0; i < NETMGR_QOS_MAX_FLOW_FILTER; i++)
    {
      if (netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i] == NULL)
      {

        netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i] =
          malloc(sizeof(netmgr_qmi_qos_flow_info_t));

        if (!netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i])
        {
          netmgr_log_err( "Cannot allocate memory for storing QOS flow\n");
          return next_state;
        }

        memcpy(netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i],
               &cmd_buf->data.info.qos_flow,
               sizeof(netmgr_qmi_qos_flow_info_t));

       break;
      }

    }
    if (i == NETMGR_QOS_MAX_FLOW_FILTER)
    {
      netmgr_log_err( "Cache limit reached for storing qos_flow. "
                      "flow will not be activated.\n");
    }

    return next_state;
  }

  dev_name = netmgr_kif_get_name(cmd_buf->data.link);

  if( netmgr_main_get_qos_enabled() &&
     !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    /* Initiate Traffic Control flow create process */
    if( NETMGR_SUCCESS !=
        netmgr_tc_flow_activate( cmd_buf->data.link,
                                 &cmd_buf->data.info.qos_flow ) ) {
      netmgr_log_err("failed on tc_flow_create\n");
    }
    else if(NULL == dev_name) {
      netmgr_log_err("%s(): unable to determine name for link=%d\n",
                      __func__, cmd_buf->data.link);
    }
    else {
      /* Post event indication to clients */
      event_info = netmgr_malloc( sizeof(netmgr_nl_event_info_t) );
      if( NULL == event_info ) {
        netmgr_log_err("failed to allocate event buffer!\n");
      } else {
        memset( event_info, 0x0, sizeof(netmgr_nl_event_info_t) );
        event_info->event = NET_PLATFORM_FLOW_ACTIVATED_EV;
        event_info->link = cmd_buf->data.link;
        event_info->flow_info.flow_id =  (unsigned int)cmd_buf->data.info.qos_flow.flow_id;
        event_info->flow_info.flow_type =  cmd_buf->data.info.qos_flow.flow_type;
        event_info->param_mask |= ( NETMGR_EVT_PARAM_LINK | NETMGR_EVT_PARAM_FLOWINFO );
        strlcpy( event_info->dev_name,
                 dev_name,
                 sizeof(event_info->dev_name) );
        event_info->param_mask |= NETMGR_EVT_PARAM_DEVNAME;

        if( NETMGR_SUCCESS !=
            netmgr_kif_send_event_msg( event_info ) ) {
          netmgr_log_err("failed on kif_send_event ACTIVATED\n");
        }

        netmgr_free( event_info );
      }
    }
  }

  NETMGR_LOG_FUNC_EXIT;
#else
  STM_UNUSED( sm );
  STM_UNUSED( payload );
#endif /* NETMGR_QOS_ENABLED */
  return( next_state );

} /* netmgr_sm_qos_activate() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_qos_modify

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_UP,
    upon receiving input NETMGR_QOS_MODIFY_EV

    @detail
    Called upon receipt of input NETMGR_QOS_MODIFY_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_qos_modify
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
#ifdef NETMGR_QOS_ENABLED
  netmgr_exec_cmd_t * cmd_buf = NULL;
  netmgr_nl_event_info_t * event_info = NULL;
  const char *dev_name = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  STM_UNUSED( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  if( netmgr_main_get_qos_enabled() &&
      !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    /* Initiate Traffic Control flow modify process */
    if( NETMGR_SUCCESS !=
        netmgr_tc_flow_modify(cmd_buf->data.link,
                              &cmd_buf->data.info.qos_flow))
    {
      netmgr_exec_cmd_t * new_cmd = NULL;

      netmgr_log_err("failed on tc_flow_modify, post command to "
                      "executive to delete\n");

      new_cmd = netmgr_exec_get_cmd();
      NETMGR_ASSERT(new_cmd);

      new_cmd->data.type = NETMGR_QOS_DELETE_EV;
      new_cmd->data.link = cmd_buf->data.link;
      new_cmd->data.info.qos_flow.flow_id = cmd_buf->data.info.qos_flow.flow_id;
      new_cmd->data.info.qos_flow.ip_ver = cmd_buf->data.info.qos_flow.ip_ver;

      if (NETMGR_SUCCESS != netmgr_exec_put_cmd(new_cmd))
      {
        NETMGR_ABORT("failed to put command");
        netmgr_exec_release_cmd(new_cmd);
      }
    }
    else if(NULL == (dev_name = netmgr_kif_get_name(cmd_buf->data.link))) {
      netmgr_log_err("%s(): unable to determine name for link=%d\n",
                      __func__, cmd_buf->data.link);
    }
    else
    {
      /* Post event indication to clients */
      event_info = netmgr_malloc( sizeof(netmgr_nl_event_info_t) );
      if( NULL == event_info ) {
        netmgr_log_err("failed to allocate event buffer!\n");
      } else {
        memset( event_info, 0x0, sizeof(netmgr_nl_event_info_t) );
        event_info->event = NET_PLATFORM_FLOW_MODIFIED_EV;
        event_info->link = cmd_buf->data.link;
        event_info->flow_info.flow_id =  (unsigned int) cmd_buf->data.info.qos_flow.flow_id;
        event_info->flow_info.flow_type =  cmd_buf->data.info.qos_flow.flow_type;
        event_info->param_mask |= ( NETMGR_EVT_PARAM_LINK | NETMGR_EVT_PARAM_FLOWINFO );
        strlcpy( event_info->dev_name,
                 dev_name,
                 sizeof(event_info->dev_name) );
        event_info->param_mask |= NETMGR_EVT_PARAM_DEVNAME;

        if( NETMGR_SUCCESS !=
            netmgr_kif_send_event_msg( event_info ) ) {
          netmgr_log_err("failed on kif_send_event MODIFIED\n");
        }

        netmgr_free( event_info );
      }
    }
  }

  NETMGR_LOG_FUNC_EXIT;
#else
  STM_UNUSED( sm );
  STM_UNUSED( payload );
#endif /* NETMGR_QOS_ENABLED */

  return next_state;

} /* netmgr_sm_qos_modify() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_qos_delete

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_UP,
    upon receiving input NETMGR_QOS_DELETE_EV

    @detail
    Called upon receipt of input NETMGR_QOS_DELETE_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_qos_delete
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
#ifdef NETMGR_QOS_ENABLED
  netmgr_exec_cmd_t * cmd_buf = NULL;
  netmgr_nl_event_info_t * event_info = NULL;
  const char * dev_name = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  STM_UNUSED( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  if( netmgr_main_get_qos_enabled() &&
      !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) &&
      !NETMGR_IS_DEFAULT_FLOW(cmd_buf->data.info.qos_flow.flow_id) )
  {
    /* Initiate Traffic Control flow delete process */
    if( NETMGR_SUCCESS !=
        netmgr_tc_flow_delete( cmd_buf->data.link,
                               &cmd_buf->data.info.qos_flow) )
    {
      netmgr_log_err("failed on tc_flow_delete\n");
    }
    else if(NULL == (dev_name = netmgr_kif_get_name(cmd_buf->data.link))) {
      netmgr_log_err("%s(): unable to determine name for link=%d\n",
                      __func__, cmd_buf->data.link);
    }
    else
    {
      /* Post event indication to clients */
      event_info = netmgr_malloc( sizeof(netmgr_nl_event_info_t) );
      if( NULL == event_info ) {
        netmgr_log_err("failed to allocate event buffer!\n");
      } else {
        memset( event_info, 0x0, sizeof(netmgr_nl_event_info_t) );
        event_info->event = NET_PLATFORM_FLOW_DELETED_EV;
        event_info->link = cmd_buf->data.link;
        event_info->flow_info.flow_id =  (unsigned int)cmd_buf->data.info.qos_flow.flow_id;
        event_info->flow_info.flow_type =  cmd_buf->data.info.qos_flow.flow_type;
        event_info->param_mask |= ( NETMGR_EVT_PARAM_LINK | NETMGR_EVT_PARAM_FLOWINFO );
        strlcpy( event_info->dev_name,
                 dev_name,
                 sizeof(event_info->dev_name) );
        event_info->param_mask |= NETMGR_EVT_PARAM_DEVNAME;

        if( NETMGR_SUCCESS !=
            netmgr_kif_send_event_msg( event_info ) ) {
          netmgr_log_err("failed on kif_send_event DELETED\n");
        }

        netmgr_free( event_info );
      }
    }
  }

  NETMGR_LOG_FUNC_EXIT;
#else
  STM_UNUSED( sm );
  STM_UNUSED( payload );
#endif /* NETMGR_QOS_ENABLED */
  return( next_state );

} /* netmgr_sm_qos_delete() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_qos_suspend

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_UP,
    upon receiving input NETMGR_QOS_SUSPEND_EV

    @detail
    Called upon receipt of input NETMGR_QOS_SUSPEND_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_qos_suspend
(
 stm_state_machine_t *sm,         /*!< State Machine instance pointer */
 void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
#ifdef NETMGR_QOS_ENABLED
  netmgr_exec_cmd_t * cmd_buf = NULL;
  netmgr_nl_event_info_t * event_info = NULL;
  int i;
  const char *dev_name = NULL;
  NETMGR_LOG_FUNC_ENTRY;

  STM_UNUSED( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Special handling where QOS_SUSPEND event comes very soon
   * after WDS_CONNECTED. In this case we store the flow and filter
   * spec and configure them later when the kernel interface is UP
   * and running.
   */
  if (sm->current_state == NETMGR_STATE_COMING_UP ||
        sm->current_state == NETMGR_STATE_INITED ||
        sm->current_state == NETMGR_STATE_CONFIGURING ||
        sm->current_state == NETMGR_STATE_RECONFIGURING)
  {
    for (i = 0; i < NETMGR_QOS_MAX_FLOW_FILTER; i++)
    {
      if (netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i] == NULL)
      {

        netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i] =
          malloc(sizeof(netmgr_qmi_qos_flow_info_t));

        if (!netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i])
        {
          netmgr_log_err( "Cannot allocate memory for storing QOS flow\n");
          return next_state;
        }

        memcpy(netmgr_qmi_cfg.links[cmd_buf->data.link].qos_info.qos_flows[i],
               &cmd_buf->data.info.qos_flow,
               sizeof(netmgr_qmi_qos_flow_info_t));

       break;
      }

    }
    if (i == NETMGR_QOS_MAX_FLOW_FILTER)
    {
      netmgr_log_err( "Cache limit reached for storing qos_flow. "
                      "flow will not be activated.\n");
    }

    return next_state;
  }


  if( netmgr_main_get_qos_enabled() &&
      !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    /* Initiate Traffic Control flow suspend process */
    if( NETMGR_SUCCESS !=
        netmgr_tc_flow_suspend(cmd_buf->data.link,
                               &cmd_buf->data.info.qos_flow))
    {
      netmgr_log_err("failed on tc_flow_suspend\n");
    }
    else if(NULL == (dev_name = netmgr_kif_get_name(cmd_buf->data.link)))
    {
      netmgr_log_err("%s(): unable to determine name for link=%d\n",
                      __func__, cmd_buf->data.link);
    }
    else
    {
      /* Post event indication to clients */
      event_info = netmgr_malloc(sizeof(netmgr_nl_event_info_t));

      if (!event_info)
      {
        netmgr_log_err("failed to allocate event buffer!\n");
      }
      else
      {
        memset(event_info, 0x0, sizeof(netmgr_nl_event_info_t));
        event_info->event = NET_PLATFORM_FLOW_SUSPENDED_EV;
        event_info->link = cmd_buf->data.link;
        event_info->flow_info.flow_id = (unsigned int)cmd_buf->data.info.qos_flow.flow_id;
        event_info->flow_info.flow_type =  cmd_buf->data.info.qos_flow.flow_type;
        event_info->param_mask |= NETMGR_EVT_PARAM_LINK | NETMGR_EVT_PARAM_FLOWINFO;
        strlcpy( event_info->dev_name,
                 dev_name,
                 sizeof(event_info->dev_name) );
        event_info->param_mask |= NETMGR_EVT_PARAM_DEVNAME;

        if (NETMGR_SUCCESS != netmgr_kif_send_event_msg(event_info))
        {
          netmgr_log_err("failed on kif_send_event SUSPENDED\n");
        }

        netmgr_free(event_info);
      }
    }
  }

  NETMGR_LOG_FUNC_EXIT;
#else
  STM_UNUSED( sm );
  STM_UNUSED( payload );
#endif /* NETMGR_QOS_ENABLED */

  return next_state;
} /* netmgr_sm_qos_suspend() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_qos_flow_control

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_UP,
    upon receiving input NETMGR_QOS_FLOCNTRL_EV

    @detail
    Called upon receipt of input NETMGR_QOS_FLOCNTRL_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_qos_flow_control
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
#ifdef NETMGR_QOS_ENABLED
  netmgr_exec_cmd_t * cmd_buf = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  STM_UNUSED( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  if( netmgr_main_get_qos_enabled() &&
      !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    /* Initiate Traffic Control flow control process */
    if( NETMGR_SUCCESS !=
        netmgr_tc_flow_control(cmd_buf->data.link,
                               &cmd_buf->data.info.qos_flow,
                               cmd_buf->data.info.qos_flow.state))
    {
      netmgr_log_err("failed on tc_flow_control\n");
    }
  }

  NETMGR_LOG_FUNC_EXIT;
#else
  STM_UNUSED( sm );
  STM_UNUSED( payload );
#endif /* NETMGR_QOS_ENABLED */

  return next_state;
} /* netmgr_sm_qos_flow_control() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_qos_rebind

===========================================================================*/
/*!
    @brief
    Transition function for state machine NETMGR_SM,
    state NETMGR_STATE_UP,
    upon receiving input NETMGR_QOS_REBIND_EV

    @detail
    Called upon receipt of input NETMGR_QOS_REBIND_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_qos_rebind
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
#ifdef NETMGR_QOS_ENABLED
  netmgr_exec_cmd_t * cmd_buf = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  STM_UNUSED( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  if( netmgr_main_get_qos_enabled() &&
      !NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link) )
  {
    /* Initiate Traffic Control flow rebind process */
    if( NETMGR_SUCCESS !=
        netmgr_tc_flow_rebind(cmd_buf->data.link,
                               &cmd_buf->data.info.qos_flow))
    {
      netmgr_log_err("failed on tc_flow_rebind\n");
    }
  }

  NETMGR_LOG_FUNC_EXIT;
#else
  STM_UNUSED( sm );
  STM_UNUSED( payload );
#endif /* NETMGR_QOS_ENABLED */

  return next_state;
} /* netmgr_sm_qos_flow_rebind() */


/*===========================================================================

     (State Machine: NETMGR_SM)
     STATE ENTRY/EXIT/TRANSITION FUNCTIONS: NETMGR_STATE_GOING_DOWN

===========================================================================*/

/*===========================================================================

  STATE ENTRY FUNCTION:  netmgr_sm_state_goingdown_entry

===========================================================================*/
/*!
    @brief
    Entry function for state machine NETMGR_SM,
    state NETMGR_STATE_GOING_DOWN

    @detail
    Called upon entry into this state of the state machine, with optional
    user-passed payload pointer parameter.  The prior state of the state
    machine is also passed as the prev_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_goingdown_entry
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         prev_state,  /*!< Previous state */
  void                *payload     /*!< Payload pointer */
)
{
#ifdef FEATURE_DATA_IWLAN
  netmgr_exec_cmd_t * cmd_buf = NULL;
  STM_UNUSED( prev_state );

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* When a forward Rmnet interface is going down, bring down the corresponding
     reverse Rmnet as well (if it's still UP) */
  if (!NETMGR_KIF_IS_REV_RMNET_LINK(cmd_buf->data.link))
  {
    int rev_link;

    /* If the forward link is associated with a valid reverse link and
       reverse link had already been disconnected, inititae a teardown */
    if (NETMGR_LINK_MAX != (rev_link = netmgr_qmi_iwlan_get_link_assoc(cmd_buf->data.link)))
    {
      netmgr_log_med("netmgr_sm_state_goingdown_entry: link=%d going down, bringing down associated rev_link=%d\n",
                     cmd_buf->data.link,
                     rev_link);
      (void)netmgr_qmi_iwlan_clear_link_assoc(cmd_buf->data.link, rev_link);
      if (NETMGR_STATE_GOING_DOWN == stm_get_state(&NETMGR_SM[rev_link]))
      {
        netmgr_kif_iface_close((uint8)rev_link, NULL, TRUE);
      }
    }
  }
#else
  STM_UNUSED( payload );
  STM_UNUSED( prev_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
#endif /* FEATURE_DATA_IWLAN */
} /* netmgr_sm_state_goingdown_entry() */


/*===========================================================================

  STATE EXIT FUNCTION:  netmgr_sm_state_goingdown_exit

===========================================================================*/
/*!
    @brief
    Exit function for state machine NETMGR_SM,
    state NETMGR_STATE_GOING_DOWN

    @detail
    Called upon exit of this state of the state machine, with optional
    user-passed payload pointer parameter.  The impending state of the state
    machine is also passed as the next_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_goingdown_exit
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         next_state,  /*!< Next state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( next_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
} /* netmgr_sm_state_goingdown_exit() */

/*===========================================================================

     (State Machine: NETMGR_SM)
     STATE ENTRY/EXIT/TRANSITION FUNCTIONS: NETMGR_STATE_GOING_DOWN_TO_COME_UP

===========================================================================*/

/*===========================================================================

  STATE ENTRY FUNCTION:  netmgr_sm_state_goingdowntocomeup_entry

===========================================================================*/
/*!
    @brief
    Entry function for state machine NETMGR_SM,
    state NETMGR_STATE_GOING_DOWN_TO_COME_UP

    @detail
    Called upon entry into this state of the state machine, with optional
    user-passed payload pointer parameter.  The prior state of the state
    machine is also passed as the prev_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_goingdowntocomeup_entry
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         prev_state,  /*!< Previous state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( prev_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
} /* netmgr_sm_state_goingdowntocomeup_entry() */


/*===========================================================================

  STATE EXIT FUNCTION:  netmgr_sm_state_goingdowntocomeup_exit

===========================================================================*/
/*!
    @brief
    Exit function for state machine NETMGR_SM,
    state NETMGR_STATE_GOING_DOWN_TO_COME_UP

    @detail
    Called upon exit of this state of the state machine, with optional
    user-passed payload pointer parameter.  The impending state of the state
    machine is also passed as the next_state parameter.

    @return
    None

*/
/*=========================================================================*/
void netmgr_sm_state_goingdowntocomeup_exit
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  stm_state_t         next_state,  /*!< Next state */
  void                *payload     /*!< Payload pointer */
)
{
  STM_UNUSED( payload );
  STM_UNUSED( next_state );
  /* Ensure that the state machine instance pointer passed is valid */
  STM_NULL_CHECK( sm );
} /* netmgr_sm_state_goingdowntocomeup_exit() */

/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_wlan_opened

===========================================================================*/
/*!
    @brief
    Function to handle the NETMGR_WLAN_OPENED_EV when WLAN interface
    comes up

    @detail
    Called upon receipt of input NETMGR_WLAN_OPENED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_wlan_opened
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

#if defined(FEATURE_DS_LINUX_ANDROID) && !defined(NETMGR_OFFTARGET)
  netmgr_util_wakelock_acquire();
#endif

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Initiate KIF interface configuration process */
  if( NETMGR_SUCCESS !=
      netmgr_kif_wlan_open( (uint8)cmd_buf->data.link ) ) {
    netmgr_log_err("failed on wlan_open\n");
  }

#if defined(FEATURE_DS_LINUX_ANDROID) && !defined(NETMGR_OFFTARGET)
  netmgr_util_wakelock_release();
#endif

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );
} /* netmgr_sm_wlan_opened() */


/*===========================================================================

  TRANSITION FUNCTION:  netmgr_sm_wlan_closed

===========================================================================*/
/*!
    @brief
    Function to handle the NETMGR_WLAN_CLOSED_EV when WLAN interface
    goes down

    @detail
    Called upon receipt of input NETMGR_KIF_CLOSED_EV, with optional
    user-passed payload pointer.

    @return
    Returns the next state that the state machine should transition to
    upon receipt of the input.  This state must be a valid state for this
    state machine.

*/
/*=========================================================================*/
stm_state_t netmgr_sm_wlan_closed
(
  stm_state_machine_t *sm,         /*!< State Machine instance pointer */
  void                *payload     /*!< Payload pointer */
)
{
  stm_state_t next_state = STM_SAME_STATE; /* Default 'next' state */
  netmgr_exec_cmd_t * cmd_buf = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  STM_NULL_CHECK( sm );
  STM_NULL_CHECK( payload );

#if defined(FEATURE_DS_LINUX_ANDROID) && !defined(NETMGR_OFFTARGET)
  netmgr_util_wakelock_acquire();
#endif

  cmd_buf = (netmgr_exec_cmd_t *)payload;

  /* Initiate KIF interface configuration process */
  if( NETMGR_SUCCESS !=
      netmgr_kif_wlan_close( (uint8)cmd_buf->data.link ) ) {
    netmgr_log_err("failed on wlan_close\n");
  }

#if defined(FEATURE_DS_LINUX_ANDROID) && !defined(NETMGR_OFFTARGET)
  netmgr_util_wakelock_release();
#endif

  NETMGR_LOG_FUNC_EXIT;
  return( next_state );
} /* netmgr_sm_wlan_closed() */


