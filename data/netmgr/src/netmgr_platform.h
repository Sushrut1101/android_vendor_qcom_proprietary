/******************************************************************************

                        N E T M G R _ P L A T F O R M . H

******************************************************************************/

/******************************************************************************

  @file    netmgr_platform.h
  @brief   Network Manager platform layer header file

  DESCRIPTION
  Header file containing definition of NetMgr's platform layer.

******************************************************************************/
/*===========================================================================

  Copyright (c) 2010-2015, 2017-2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

#ifndef __NETMGR_PLATFORM_H__
#define __NETMGR_PLATFORM_H__

#include "ds_cmdq.h"
#include "netmgr_kif.h"
#include "netmgr_qmi.h"
#include "netmgr_sm.h"

/*===========================================================================
                                 TYPE DEFINITIONS
===========================================================================*/

/* QMI Virtual Function Table */
struct qmi_vtbl {
  /* callback to process modem qmi out of service */
  void (*out_of_service)(int);

  /* Callback to initialize the QMI Message Library connection */
  int (*reset)(int  link);

  /* Callback to verify if QMI link is active */
  int (*verify)(int);

  /* Callback to process module internal command */
  int (*dispatch)( ds_cmd_t * cmd,
                   void     * data );

  /* Callback to query QOS parameters for specific flow  */
  int (*qos_get_flow_info)( uint8     connection,
                            uint32    flow_id,
                            uint8   * priority,
                            uint64  * datarate );
};

/* KIF Virtual Function Table */
struct kif_vtbl {
  /* callback to process modem kif out of service */
  void (*out_of_service)(int);

  /* Callback to initialize the Kernel Interface connection */
  int (*reset)(int  link, netmgr_sm_events_t  evt);

  /* Callback to process module internal command */
  int (*dispatch)( ds_cmd_t * cmd,
                   void * data );

  /* Callback to process module internal command */
  int (*send_event)( const netmgr_nl_event_info_t *event_info );

  /* Callback to bringup the Kernel network interface  */
  int (*iface_open)( int  link,
                     netmgr_address_set_t * addr_info_ptr,
                     const netmgr_kif_clntcb_t * clntcb,
                     void *    clnt_hdl );

  /* Callback to teardown the Kernel network interface  */
  int (*iface_close)( int link,
                      netmgr_address_set_t * addr_info_ptr,
                      boolean   teardown_iface );

  /* Callback to perform address configuration on then Kernel network interface  */
  int (*iface_configure)( int link, netmgr_ip_addr_t addr_type );

  /* Callback to perform address reconfiguration on then Kernel network interface  */
  int (*iface_reconfigure)( int link,
                            netmgr_address_set_t * addr_info_ptr );

  /* Callback to manage the Kernel traffic control flow control */
  int (*flow_control)( int       link,
                       void *    data );

  /* Callback to perform link configuration on the Kernel network interface  */
  int (*iface_link_update)( uint8 link );

  int (*wlan_open)( int link );

  int (*wlan_close)( int link );

  /* Callback to disable IPv6 on a given link */
  int (*enable_ipv6)(int link);
};

/* TC Virtual Function Table */
struct tc_vtbl{
  /* Callback to initialize the Traffic Control Library connection */
  int (*reset)( int link );

  /* Callback to activate QoS flow in Traffic Control */
  int (*flow_activate)( int     link,
                        const netmgr_qmi_qos_flow_info_t  *qos_flow );

  /* Callback to change QoS flow parameters in Traffic Control */
  int (*flow_modify)( int       link,
                      const netmgr_qmi_qos_flow_info_t  *qos_flow );

  /* Callback to delete QoS flow in Traffic Control */
  int (*flow_delete)( int      link,
                      const netmgr_qmi_qos_flow_info_t  *qos_flow );

  /* Callback to suspend QoS flow in Traffic Control */
  int (*flow_suspend)( int link,
                       const netmgr_qmi_qos_flow_info_t  *qos_flow );

  /* Callback to enable/disable QoS flow in Traffic Control */
  int (*flow_control)( int link,
                       const netmgr_qmi_qos_flow_info_t  *qos_flow,
                       netmgr_tc_flow_state_t state );

  /* Callback to rebind QoS flow in Traffic Control */
  int (*flow_rebind)( int link,
                      const netmgr_qmi_qos_flow_info_t  *qos_flow );
};

/* Bitmask values for flow_change() */
#define FLOW_CHANGE_MASK_PRIORITY  (1<<0)
#define FLOW_CHANGE_MASK_RATE      (1<<1)

enum netmgr_platform_vtbl {
  NETMGR_PLATFORM_VTBL_QMI,
  NETMGR_PLATFORM_VTBL_KIF,
  NETMGR_PLATFORM_VTBL_TC,
  NETMGR_PLATFORM_VTBL_MAX
};

struct platform_vtbl {
  struct qmi_vtbl  qmi;        /* QMI functions  */
  struct kif_vtbl  kif;        /* KIF functions  */
  struct tc_vtbl   tc;         /* TC functions   */
};




/*===========================================================================
                            GLOBAL FUNCTION DECLARATIONS
===========================================================================*/

/*===========================================================================
  FUNCTION  netmgr_platform_init
===========================================================================*/
/*!
@brief
  Function to initialize platform layer module.

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_platform_init(void);


/*===========================================================================
  FUNCTION  netmgr_platform_register_vtbl
===========================================================================*/
/*!
@brief
  Function to register virtual function table with the Platform layer.
  Use of vtbl will permit different implementations to be registered
  at runtime, support testing.

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_platform_init() must have been previously called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_platform_register_vtbl(
  enum netmgr_platform_vtbl  id,
  void *                     table
);

/*===========================================================================
  FUNCTION  netmgr_qmi_out_of_service
===========================================================================*/
/*!
@brief
  Function to handle modem out_of_service event in QMI module.

@return
  int

@note

  - Dependencies
    - None

  - Side Effects
    - qmi clients will be released
    - qmi links will be reset with default init values
*/
/*=========================================================================*/
int netmgr_qmi_out_of_service ( int link );

/*===========================================================================
  FUNCTION  netmgr_qmi_reset
============================================================================*/
/*!
@brief
  Function to reset connection to QMI Message Library

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_qmi_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_qmi_reset ( int link );

/*===========================================================================
  FUNCTION  netmgr_qmi_verify
===========================================================================*/
/*!
@brief
  Function to verify if the given QMI link is active.

@return
  int

@note

  - Dependencies
    - netmgr_qmi_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_qmi_verify ( int link );

/*===========================================================================
  FUNCTION  netmgr_qmi_dispatch
===========================================================================*/
/*!
@brief
  Function to dispatch asynchronous command for Kernel interface module

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_qmi_dispatch
(
  ds_cmd_t * cmd,
  void     * data
);

/*===========================================================================
  FUNCTION  netmgr_qmi_qos_get_flow_info
===========================================================================*/
/*!
@brief
  Function to query QoS flow info via QMI Message Library

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_qmi_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_qmi_qos_get_flow_info
(
  uint8     connection,
  uint32    flow_id,
  uint8   * priority,
  uint64  * datarate
);

/*===========================================================================
  FUNCTION  netmgr_kif_out_of_service
===========================================================================*/
/*!
@brief
  Function to handle modem out_of_service event in KIF module.

@return
  int

@note

  - Dependencies
    - None

  - Side Effects
    - IPTables cleanup
*/
/*=========================================================================*/
int netmgr_kif_out_of_service ( int link );

/*===========================================================================
  FUNCTION  netmgr_kif_reset
===========================================================================*/
/*!
@brief
  Function to reset connection to Kernel interface module

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_reset ( int link, netmgr_sm_events_t evt_type );


/*===========================================================================
  FUNCTION  netmgr_kif_dispatch
===========================================================================*/
/*!
@brief
  Function to dispatch asynchronous command for Kernel interface module

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_dispatch
(
  ds_cmd_t * cmd,
  void     * data
);

/*===========================================================================
  FUNCTION  netmgr_kif_send_event_msg
===========================================================================*/
/*!
@brief
  Function to send Kernel interface module asynchronous event message.

@return
  int

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_send_event_msg
(
  const netmgr_nl_event_info_t *event_info
);


/*===========================================================================
  FUNCTION  netmgr_kif_iface_open
===========================================================================*/
/*!
@brief
  Function to open the Kernel network interface

@return
  int

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_iface_open ( uint8     link,
                            netmgr_address_set_t * addr_info_ptr,
                            const netmgr_kif_clntcb_t * clntcb,
                            void *    clnt_hdl );

/*===========================================================================
  FUNCTION  netmgr_kif_iface_close
===========================================================================*/
/*!
@brief
  Function to close the Kernel network interface

@return
  int

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_iface_close ( uint8     link,
                             netmgr_address_set_t * addr_info_ptr,
                             boolean   teardown_iface );

/*===========================================================================
  FUNCTION  netmgr_kif_iface_configure
===========================================================================*/
/*!
@brief
  Function to configure address for the Kernel network interface

@return
  int

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_iface_configure ( uint8             link,
                                 netmgr_ip_addr_t  addr_type);

/*===========================================================================
  FUNCTION  netmgr_kif_iface_reconfigure
===========================================================================*/
/*!
@brief
  Function to reconfigure address for the Kernel network interface

@return
  int

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_iface_reconfigure ( uint8     link,
                                   netmgr_address_set_t * addr_info_ptr );

/*===========================================================================
  FUNCTION  netmgr_kif_flow_control
===========================================================================*/
/*!
@brief
  Function to control the state of the Traffic Control qdisc class
  mapped to the specified QoS flow.

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_flow_control ( uint8     connection,
                              void *    data );

/*===========================================================================
  FUNCTION  netmgr_kif_update_link
===========================================================================*/
/*!
@brief
  Function to update the link with the MTU updates recevied from modem
  via extended ip indications

@return
  int

@note
  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/

int netmgr_kif_update_link ( uint8 link );


/*===========================================================================
  FUNCTION  netmgr_tc_reset
===========================================================================*/
/*!
@brief
  Function to reset connection to Traffic Control Library

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_tc_reset ( int link );


/*===========================================================================
  FUNCTION  netmgr_tc_flow_activate
===========================================================================*/
/*!
@brief
  Function to create/resume the Traffic Control objects for a QoS flow.

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_tc_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_tc_flow_activate ( int   link,
                              const netmgr_qmi_qos_flow_info_t  *qos_flow );

/*===========================================================================
  FUNCTION  netmgr_tc_flow_modify
===========================================================================*/
/*!
@brief
  Function to change the Traffic Control object attributes for an
  existing QoS flow.

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_tc_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_tc_flow_modify ( int       link,
                            const netmgr_qmi_qos_flow_info_t  *qos_flow );

/*===========================================================================
  FUNCTION  netmgr_tc_flow_delete
===========================================================================*/
/*!
@brief
  Function to delete the Traffic Control objects for an existing QoS flow.

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_tc_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_tc_flow_delete ( int       link,
                            const netmgr_qmi_qos_flow_info_t  *qos_flow );

/*===========================================================================
  FUNCTION  netmgr_tc_flow_suspend
===========================================================================*/
/*!
@brief
  Function to suspend the Traffic Control objects for an existing QoS flow.

@return
  int - NETMGR_SUCCESS on successful operation, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - netmgr_tc_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_tc_flow_suspend ( int       link,
                             const netmgr_qmi_qos_flow_info_t  *qos_flow );

/*===========================================================================
    FUNCTION  netmgr_tc_flow_control
===========================================================================*/
/*!
@brief
  Function to control the Traffic Control objects for an active QoS flow.

@return
  int

@note

  - Dependencies
    - netmgr_tc_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_tc_flow_control (int link,
                            const netmgr_qmi_qos_flow_info_t  *qos_flow,
                            netmgr_tc_flow_state_t state);

/*===========================================================================
    FUNCTION  netmgr_tc_flow_rebind
===========================================================================*/
/*!
@brief
  Function to control the Traffic Control objects for an active QoS flow.

@return
  int

@note

  - Dependencies
    - netmgr_tc_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_tc_flow_rebind (int link,
                           const netmgr_qmi_qos_flow_info_t  *qos_flow);

/*===========================================================================
  FUNCTION  netmgr_kif_wlan_open
===========================================================================*/
/*!
@brief
  Function to handle WLAN interface open

@return
  int

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_wlan_open ( uint8 link );

/*===========================================================================
  FUNCTION  netmgr_kif_wlan_close
===========================================================================*/
/*!
@brief
  Function to handle WLAN interface close

@return
  int

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_wlan_close ( uint8 link );

/*===========================================================================
  FUNCTION  netmgr_kif_enable_ipv6
===========================================================================*/
/*!
@brief
  Function to enable ipv6 on a link

@return
  int

@note

  - Dependencies
    - netmgr_kif_init() must have been called

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_kif_enable_ipv6(uint8 link);
#endif /* __NETMGR_PLATFORM_H__ */
