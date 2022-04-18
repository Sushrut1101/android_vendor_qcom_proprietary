/******************************************************************************

     N M _ M D M P R X Y _ M A R K _ P R O V I D E R _ C O M M O N . C

******************************************************************************/

/******************************************************************************

  @file    nm_mdmprxy_mark_provider_common.c
  @brief   Modem proxy plugin

  DESCRIPTION
  Mark Provider common module responsible for managing common state and
  rules shared between different mark providers

******************************************************************************/
/*===========================================================================

  Copyright (c) 2015-2016, 2018-2019 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

/*===========================================================================
                              INCLUDE FILES
===========================================================================*/

#include "netmgr.h"
#include "netmgr_util.h"

#include "nm_mdmprxy.h"
#include "nm_mdmprxy_mark_provider_factory.h"
#include "nm_mdmprxy_mark_provider_common.h"

typedef struct
{
  boolean is_v4_marking_rule_installed;
  boolean is_v6_marking_rule_installed;
  boolean v4_audio_rules_installed;
  boolean v6_audio_rules_installed;
  boolean v4_audio_port_fwding_pref;
  boolean v6_audio_port_fwding_pref;
} nm_mdmprxy_comm_mark_prov_cfg_t;

static nm_mdmprxy_comm_mark_prov_cfg_t  comm_mark_prov_cfg;

#define NM_MDMPRXY_COMMON_GET_MARKING_RULES_INSTALLED(family)          \
  ((AF_INET == family) ?                                               \
   comm_mark_prov_cfg.is_v4_marking_rule_installed :                   \
   comm_mark_prov_cfg.is_v6_marking_rule_installed)

#define NM_MDMPRXY_COMMON_SET_MARKING_RULES_INSTALLED(family, status)  \
  *(((AF_INET == family) ?                                             \
    &comm_mark_prov_cfg.is_v4_marking_rule_installed :                 \
    &comm_mark_prov_cfg.is_v6_marking_rule_installed)) = status

#define NM_MDMPRXY_COMMON_GET_AUDIO_RULES_INSTALLED(family)            \
  ((AF_INET == family) ?                                               \
   comm_mark_prov_cfg.v4_audio_rules_installed :                       \
   comm_mark_prov_cfg.v6_audio_rules_installed)

#define NM_MDMPRXY_COMMON_SET_AUDIO_RULES_INSTALLED(family, status)    \
  *(((AF_INET == family) ?                                             \
    &comm_mark_prov_cfg.v4_audio_rules_installed :                     \
    &comm_mark_prov_cfg.v6_audio_rules_installed)) = status

#define NM_MDMPRXY_COMMON_GET_AUDIO_RULES_INSTALL_PREF(family)         \
  ((AF_INET == family) ?                                               \
   comm_mark_prov_cfg.v4_audio_port_fwding_pref :                      \
   comm_mark_prov_cfg.v6_audio_port_fwding_pref)

#define NM_MDMPRXY_COMMON_SET_AUDIO_RULES_INSTALL_PREF(family, pref)   \
  *(((AF_INET == family) ?                                             \
    &comm_mark_prov_cfg.v4_audio_port_fwding_pref :                    \
    &comm_mark_prov_cfg.v6_audio_port_fwding_pref)) = pref

static const struct nm_mdmprxy_cmd spi_filter_rule_list[] =
{
  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_mngl_pre_spi -p 50 -m esp --espspi 0x%x"
                          " -j MARK --set-mark 0x%x",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_mngl_pre_spi -p 50 -m esp --espspi 0x%x"
                          " -j MARK --set-mark 0x%x",
    nm_mdmprxy_spi_formatter }
};

static const struct nm_mdmprxy_cmd port_fwd_rule_list[] =
{
  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_mngl_pre_ex -p udp --dport %d:%d"
                          " -j MARK --set-mark 0x%x",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_mngl_pre_ex -p udp --dport %d:%d"
                          " -j MARK --set-mark 0x%x",
    nm_mdmprxy_port_fwd_formatter },

  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_mngl_pre_ex -p tcp --dport %d:%d"
                          " -j MARK --set-mark 0x%x",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_mngl_pre_ex -p tcp --dport %d:%d"
                          " -j MARK --set-mark 0x%x",
    nm_mdmprxy_port_fwd_formatter },
};

/* Connection tracking rule to mark icmp packets arriving from reverse rmnet
   The route provider will install a jump rule from PREROUTING chain when
   reverse rmnet interface is brought up */
static const struct nm_mdmprxy_cmd per_iface_conntrack_rule_list[] =
{
  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_icmp_pkt_marker -p %s -i %s"
                    " -m conntrack --ctstate NEW -j CONNMARK --set-mark 0x%x",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_icmp_pkt_marker -p %s -i %s"
                    " -m conntrack --ctstate NEW -j CONNMARK --set-mark 0x%x",
    nm_mdmprxy_conntrack_formatter }
};

/* Common static iptables rules between mark providers */
static const struct nm_mdmprxy_cmd static_rule_list[] =
{
  /* save any packet mark on to the connection (for handling fragmented IPv6 pkts) */
  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_pkt_marker -j CONNMARK --save-mark",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_pkt_marker -j CONNMARK --save-mark",
    nm_mdmprxy_connmark_save_formatter },

  /* mark traffic destined to the standard SIP port to be forwarded to the modem */
  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_pkt_marker -p udp"
      " --dport " TOSTR(NM_MDMPRXY_IMS_SIP_PORT) " -j MARK --set-mark 0x%x",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_pkt_marker -p udp"
      " --dport " TOSTR(NM_MDMPRXY_IMS_SIP_PORT) " -j MARK --set-mark 0x%x",
    nm_mdmprxy_markjump_formatter },

  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_pkt_marker -p tcp"
      " --dport " TOSTR(NM_MDMPRXY_IMS_SIP_PORT) " -j MARK --set-mark 0x%x",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_pkt_marker -p tcp"
      " --dport " TOSTR(NM_MDMPRXY_IMS_SIP_PORT) " -j MARK --set-mark 0x%x",
    nm_mdmprxy_markjump_formatter },

  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_pkt_marker -p udp"
      " --dport " TOSTR(NM_MDMPRXY_SUPL_PORT) " -j MARK --set-mark 0x%x",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_pkt_marker -p udp"
      " --dport " TOSTR(NM_MDMPRXY_SUPL_PORT) " -j MARK --set-mark 0x%x",
    nm_mdmprxy_markjump_formatter },

  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_pkt_marker -j nm_mdmprxy_mngl_pre_ex",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_pkt_marker -j nm_mdmprxy_mngl_pre_ex",
    nm_mdmprxy_basic_formatter },

  /* Insert a jump rule to the SPI matching table from pkt_marker table */
  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_pkt_marker -j nm_mdmprxy_mngl_pre_spi",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_pkt_marker -j nm_mdmprxy_mngl_pre_spi",
    nm_mdmprxy_basic_formatter },

  /* Jump to mark prov chain which hosts the modem port-range rules */
  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_pkt_marker -j nm_mdmprxy_mark_prov_chain",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_pkt_marker -j nm_mdmprxy_mark_prov_chain",
    nm_mdmprxy_basic_formatter },

  /* Jump to chain to apply rules for clamping TCP MSS for outgoing packets */
  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_pkt_marker -j nm_mdmprxy_mngl_pre",
    "%s" NM_MDMPRXY_FLAGS " -t mangle -D nm_mdmprxy_pkt_marker -j nm_mdmprxy_mngl_pre",
    nm_mdmprxy_basic_formatter },

  /* Restore mark on icmp packets originating from modem using connection tracking
     framework to enable pings originiating from modem to be successful */
  { "%s" NM_MDMPRXY_FLAGS " -t mangle -I nm_mdmprxy_pkt_marker -j CONNMARK --restore-mark",
    "%s" NM_MDMPRXY_FLAGS "-t mangle -D nm_mdmprxy_pkt_marker -j CONNMARK --restore-mark",
    nm_mdmprxy_basic_formatter }
};

/* Mark to be used for marking iWLAN packets to be forwarded to the modem */
static uint32_t nm_mdmprxy_common_oem_mark = 0;

/*===========================================================================
  FUNCTION  _nm_mdmprxy_common_mark_prov_remove_portfwd_rule
===========================================================================*/
/*!
@brief
  Removes rules to mark packets in IMS audio range with modem mark

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
static int _nm_mdmprxy_common_mark_prov_remove_portfwd_rule
(
  sa_family_t af,
  int         start
)
{
  int rc = NETMGR_SUCCESS;
  int i;

  struct port_forwarding nfo;

  if (DFS_REMOTE_SOCKET_HANDLING_V1_V01 == nm_mdmprxy_get_dfs_service_version())
  {
    netmgr_log_low("%s(): application specific port-based rules are not installed"
                   " in this configuration", __func__);
    return NETMGR_SUCCESS;
  }

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): unknown IP family!", __func__);
    rc = NETMGR_FAILURE;
    goto bail;
  }

  if (start >= nm_mdmprxy_rules_len(port_fwd_rule_list))
  {
    netmgr_log_err("%s(): Invalid parameter!", __func__);
    rc = NETMGR_FAILURE;
    goto bail;
  }

  if (TRUE == NM_MDMPRXY_COMMON_GET_AUDIO_RULES_INSTALL_PREF(af))
  {
    netmgr_log_med("%s(): Install preference for ip_family[%d] is set to TRUE,"
                   " skipping rule deletion", __func__, af);
    return NETMGR_SUCCESS;
  }

  if (FALSE == NM_MDMPRXY_COMMON_GET_AUDIO_RULES_INSTALLED(af))
  {
    netmgr_log_med("%s(): Audio port range marking rules already removed for ip_family [%d]",
                   __func__, af);
    return NETMGR_SUCCESS;
  }

  memset(&nfo, 0, sizeof(nfo));
  nfo.start_port = NM_MDMPRXY_IMS_AUDIO_PORT_START;
  nfo.end_port   = NM_MDMPRXY_IMS_AUDIO_PORT_END;
  nfo.mark       = nm_mdmprxy_common_oem_mark;

  for (i = start; i >= 0; i--)
  {
    if (!port_fwd_rule_list[i].rule)
    {
      continue;
    }

    rc |= nm_mdmprxy_process_rule(&port_fwd_rule_list[i], NM_MDMPRXY_RUN_ANTIRULE, af, &nfo);
  }

  NM_MDMPRXY_COMMON_SET_AUDIO_RULES_INSTALLED(af, FALSE);

bail:
  return rc;
}

/*===========================================================================
  FUNCTION  _nm_mdmprxy_common_mark_prov_remove_spi_rule
===========================================================================*/
/*!
@brief
  Remove SPI based packet-marking rule in iptables for given family

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
static int _nm_mdmprxy_common_mark_prov_remove_spi_rule
(
  sa_family_t   af,
  unsigned int  spi,
  int           start
)
{
  int i, rc = NETMGR_SUCCESS;
  struct spi_rule_info nfo;

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): unknown IP family!", __func__);
    rc = NETMGR_FAILURE;
    goto bail;
  }

  if (start >= nm_mdmprxy_rules_len(spi_filter_rule_list))
  {
    netmgr_log_err("%s(): Invalid parameter!", __func__);
    rc = NETMGR_FAILURE;
    goto bail;
  }

  memset(&nfo, 0, sizeof(nfo));
  nfo.mark = nm_mdmprxy_common_oem_mark;
  nfo.spi  = (uint32_t) spi;

  for (i = start; i >= 0; i--)
  {
    if (!spi_filter_rule_list[i].rule)
    {
      continue;
    }

    rc |= nm_mdmprxy_process_rule(&spi_filter_rule_list[i],
                                  NM_MDMPRXY_RUN_ANTIRULE, af, &nfo);
  }

bail:
  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_uninstall_static_rules
===========================================================================*/
/*!
@brief
  Helper method to uninstall static iptables rules

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
static int nm_mdmprxy_common_mark_prov_uninstall_static_rules
(
  sa_family_t af,
  int idx
)
{
  int i = 0;
  int rc = NETMGR_SUCCESS;
  struct nm_mdmprxy_iiface_rule_info nfo;

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): Unknown IP family!", __func__);
    return NETMGR_FAILURE;
  }

  memset(&nfo, 0, sizeof(struct nm_mdmprxy_iiface_rule_info));
  nfo.mark = nm_mdmprxy_common_oem_mark;

  for (i = idx; i >= 0; i--)
  {
    rc |= nm_mdmprxy_process_rule(&static_rule_list[i], NM_MDMPRXY_RUN_ANTIRULE,
                                  af, &nfo);
    if (NETMGR_SUCCESS != rc)
    {
      netmgr_log_err("%s() failed to apply rule [%d]", __func__, i);
    }
  }

  if (NETMGR_SUCCESS == rc)
  {
    netmgr_log_low("%s(): Successfully removed marking rules for ip_family [%d]",
                   __func__, af);
    NM_MDMPRXY_COMMON_SET_MARKING_RULES_INSTALLED(af, FALSE);
  }

  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_install_static_rules
===========================================================================*/
/*!
@brief
  Helper method to install static iptables rules

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
static int nm_mdmprxy_common_mark_prov_install_static_rules(sa_family_t af)
{
  int i = 0;
  int rc = NETMGR_SUCCESS;
  int num_rules = nm_mdmprxy_rules_len(static_rule_list);
  struct nm_mdmprxy_iiface_rule_info nfo;

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): Unknown IP family!", __func__);
    return NETMGR_FAILURE;
  }

  memset(&nfo, 0, sizeof(struct nm_mdmprxy_iiface_rule_info));
  nfo.mark = nm_mdmprxy_common_oem_mark;

  for (i = 0; i < num_rules; i++)
  {
    if (!static_rule_list[i].rule)
    {
      continue;
    }

    rc = nm_mdmprxy_process_rule(&static_rule_list[i], NM_MDMPRXY_RUN_RULE,
                                 af, &nfo);
    if (NETMGR_SUCCESS != rc)
    {
      netmgr_log_err("%s(): failed to apply rule [%d]!", __func__, i);
      break;
    }
  }

  if ((NETMGR_SUCCESS != rc) &&
          (i <= (num_rules - 1)))
  {
    netmgr_log_err("%s(): rolling back installed rules!", __func__);
    nm_mdmprxy_common_mark_prov_uninstall_static_rules(af, i);
  }
  else
  {
    netmgr_log_low("%s(): Successfully installed marking rules for ip_family [%d]",
                   __func__, af);
    NM_MDMPRXY_COMMON_SET_MARKING_RULES_INSTALLED(af, TRUE);
  }

  return rc;
}

/*===========================================================================
                             PUBLIC FUNCTIONS
===========================================================================*/

/* TODO: SPI based filter rules are installed or removed depending on
   reverse IP transport filters updated DFS indication. The handler for this
   is inside netmgr core since the QMI clients for reverse rmnet are inside
   the core. Eventually we need to move those DFS clients inside the
   modem_proxy module for better handling */
/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_remove_spi_rule
===========================================================================*/
/*!
@brief
  Remove SPI based packet-marking rule in iptables for given family

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_remove_spi_rule
(
  sa_family_t   af,
  unsigned int  spi
)
{
  int rc = NETMGR_SUCCESS;

  rc |= _nm_mdmprxy_common_mark_prov_remove_spi_rule(af, spi,
                                                     nm_mdmprxy_rules_len(spi_filter_rule_list)-1);

  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_install_spi_rule
===========================================================================*/
/*!
@brief
  Install SPI based packet-marking rule in iptables for given family

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_install_spi_rule
(
  sa_family_t   af,
  unsigned int  spi
)
{
  int i=0, rc = NETMGR_FAILURE;
  struct spi_rule_info nfo;

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): unknown IP family!", __func__);
    goto bail;
  }

  memset(&nfo, 0, sizeof(nfo));
  nfo.mark = nm_mdmprxy_common_oem_mark;
  nfo.spi  = (uint32_t) spi;

  for (i = 0; i < (int) nm_mdmprxy_rules_len(spi_filter_rule_list); i++)
  {
    if (!spi_filter_rule_list[i].rule)
    {
      continue;
    }

    rc = nm_mdmprxy_process_rule(&spi_filter_rule_list[i], NM_MDMPRXY_RUN_RULE, af, &nfo);
    if (NETMGR_SUCCESS != rc)
    {
      netmgr_log_err("%s(): failed to apply rule[%d]", __func__, i);
      goto bail;
    }
  }

  return NETMGR_SUCCESS;

bail:
  (void) _nm_mdmprxy_common_mark_prov_remove_spi_rule(af, spi, i);
  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_remove_portfwd_rule
===========================================================================*/
/*!
@brief
  Removes rules to mark packets in IMS audio range with modem mark

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_remove_portfwd_rule
(
  sa_family_t af,
  boolean     pref
)
{
  int rc = NETMGR_SUCCESS;

  if (DFS_REMOTE_SOCKET_HANDLING_V1_V01 == nm_mdmprxy_get_dfs_service_version())
  {
    netmgr_log_low("%s(): application specific port-based rules are not installed"
                   " in this configuration", __func__);
    return NETMGR_SUCCESS;
  }

  /* IMS can set a preference for installing or removing
     the port-forwarding rule. Based on this preference we
     will install or delete the port-forwarding rule */
  NM_MDMPRXY_COMMON_SET_AUDIO_RULES_INSTALL_PREF(af, pref);

  rc |= _nm_mdmprxy_common_mark_prov_remove_portfwd_rule(af,
                                                         (nm_mdmprxy_rules_len(port_fwd_rule_list) - 1));

  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_install_portfwd_rule
===========================================================================*/
/*!
@brief
  Installs rules to mark packets in IMS audio range with modem mark

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_install_portfwd_rule
(
  sa_family_t af,
  boolean     pref
)
{
  int rc = NETMGR_SUCCESS;
  int i = 0;
  struct port_forwarding nfo;

  if (DFS_REMOTE_SOCKET_HANDLING_V1_V01 == nm_mdmprxy_get_dfs_service_version())
  {
    netmgr_log_low("%s(): application specific port-based rules are not installed"
                   " in this configuration", __func__);
    return NETMGR_SUCCESS;
  }

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): unknown IP family!", __func__);
    goto bail;
  }

  /* IMS can set a preference for installing or removing
     the port-forwarding rule. Based on this preference we
     will install or delete the port-forwarding rule */
  NM_MDMPRXY_COMMON_SET_AUDIO_RULES_INSTALL_PREF(af, pref);

  if (FALSE == NM_MDMPRXY_COMMON_GET_AUDIO_RULES_INSTALL_PREF(af))
  {
    netmgr_log_med("%s(): Install preference for ip_family [%d] is FALSE,"
                   " skipping rule installation", __func__, af);
    return NETMGR_SUCCESS;
  }

  if (TRUE == NM_MDMPRXY_COMMON_GET_AUDIO_RULES_INSTALLED(af))
  {
    netmgr_log_med("%s(): Audio port range marking rules already installed for ip_family [%d]",
                   __func__, af);
    return NETMGR_SUCCESS;
  }

  memset(&nfo, 0, sizeof(nfo));
  nfo.start_port = NM_MDMPRXY_IMS_AUDIO_PORT_START;
  nfo.end_port   = NM_MDMPRXY_IMS_AUDIO_PORT_END;
  nfo.mark       = nm_mdmprxy_common_oem_mark;

  for (i = 0; i < nm_mdmprxy_rules_len(port_fwd_rule_list); i++)
  {
    if (!port_fwd_rule_list[i].rule)
    {
      continue;
    }

    rc = nm_mdmprxy_process_rule(&port_fwd_rule_list[i], NM_MDMPRXY_RUN_RULE, af, &nfo);
    if (NETMGR_SUCCESS != rc)
    {
      netmgr_log_err("%s(): failed to apply rule[%d]", __func__, i);
      rc = NETMGR_FAILURE;
      goto bail;
    }
  }

  NM_MDMPRXY_COMMON_SET_AUDIO_RULES_INSTALLED(af, TRUE);
  return rc;

bail:
  _nm_mdmprxy_common_mark_prov_remove_portfwd_rule(af, i);
  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_query_portfwd_status
===========================================================================*/
/*!
@brief
  Queries port forward status

@return
  Install preference for the given ip family
*/
/*=========================================================================*/
boolean nm_mdmprxy_common_mark_prov_query_portfwd_status(sa_family_t af)
{
  boolean pref = FALSE;
  switch (af)
  {
    case AF_INET:
      pref = comm_mark_prov_cfg.v4_audio_port_fwding_pref;
      netmgr_log_low("%s(): Pref [%d]", __func__, pref);
      break;
    case AF_INET6:
      pref = comm_mark_prov_cfg.v6_audio_port_fwding_pref;
      netmgr_log_low("%s(): Pref [%d]", __func__, pref);
      break;
    default:
      pref = FALSE;
      break;
  }

  return pref;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_install_icmp_rules
===========================================================================*/
/*!
@brief
  Installs iptables connection tracking rules which support ICMP data
  transfer from modem

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_install_icmp_rules
(
  sa_family_t af,
  char* link_name
)
{
  int rc = NETMGR_FAILURE;
  char* proto;

  if (!link_name)
  {
    netmgr_log_err("%s(): Invalid link name", __func__);
    goto bail;
  }

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): Unknown address family", __func__);
    goto bail;
  }

  if (AF_INET == af)
  {
    proto = NM_MDMPRXY_ICMP_PROTO;
  }
  else
  {
    proto = NM_MDMPRXY_ICMP6_PROTO;
  }

  rc = nm_mdmprxy_install_connmark_rules(af, proto, link_name, nm_mdmprxy_common_oem_mark);

bail:
  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_remove_icmp_rules
===========================================================================*/
/*!
@brief
  Removes iptables connection tracking rules which support ICMP data
  transfer from modem

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_remove_icmp_rules
(
  sa_family_t af,
  char* link_name
)
{
  int rc = NETMGR_FAILURE;
  char* proto;

  if (!link_name)
  {
    netmgr_log_err("%s(): Invalid link name", __func__);
    goto bail;
  }

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): Unknown address family", __func__);
    goto bail;
  }

  if (AF_INET == af)
  {
    proto = NM_MDMPRXY_ICMP_PROTO;
  }
  else
  {
    proto = NM_MDMPRXY_ICMP6_PROTO;
  }

  rc = nm_mdmprxy_uninstall_connmark_rules(af, proto, link_name, nm_mdmprxy_common_oem_mark,
                                           nm_mdmprxy_rules_len(per_iface_conntrack_rule_list) - 1);

bail:
  return rc;
}

/* TODO: Till we can fix the global vs per-link handling of SSR within
   netmgr core we need to flush the connmark rules for reverse rmnet
   inside the icmp marking chain completely instead of handling it per
   link. Once the core is fixed we can rely on per-link SSR hanlding within
   the mark provider */
/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_flush_icmp_connmark_rules
===========================================================================*/
/*!
@brief
  Flushes the connection tracking chain for icmp packets

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
static int nm_mdmprxy_common_mark_prov_flush_icmp_connmark_rules(sa_family_t af)
{
  int rc = NETMGR_FAILURE;

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): Unknown address family", __func__);
    goto bail;
  }

  rc = nm_mdmprxy_flush_connmark_rules(af);

bail:
  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_flush_spi_rules
===========================================================================*/
/*!
@brief
  Flushes the spi chain to remove all spi based packet marking rules

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
static int nm_mdmprxy_common_mark_prov_flush_spi_rules(sa_family_t af)
{
  int rc = NETMGR_FAILURE;

  if (AF_INET != af && AF_INET6 != af)
  {
    netmgr_log_err("%s(): Unknown address family", __func__);
    goto bail;
  }

  rc = nm_mdmprxy_flush_spi_rules(af);

bail:
  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_oos_cleanup
===========================================================================*/
/*!
@brief
  Flushes common mark provider chains during OOS

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_oos_cleanup(void)
{
  int rc = NETMGR_FAILURE;

  /* Remove IMS audio port-forwarding rules, set the preference to FALSE
     indicating that we want to remove the rules since this is an SSR OOS
     scenario */
  rc = nm_mdmprxy_common_mark_prov_remove_portfwd_rule(AF_INET, FALSE);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): Failed to remove IPv4 audio port-forwarding rules", __func__);
  }

  rc = nm_mdmprxy_common_mark_prov_remove_portfwd_rule(AF_INET6, FALSE);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): Failed to remove IPv6 audio port-forwarding rules", __func__);
  }

  /* Remove connection tracking rules inside icmp marking chain */
  rc = nm_mdmprxy_common_mark_prov_flush_icmp_connmark_rules(AF_INET);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): failed to remove IPv4 connection marking rules", __func__);
  }

  rc = nm_mdmprxy_common_mark_prov_flush_icmp_connmark_rules(AF_INET6);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): failed to remove IPv6 connection marking rules", __func__);
  }

  /* Remove SPI based packet marking rules */
  rc = nm_mdmprxy_common_mark_prov_flush_spi_rules(AF_INET);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): failed to remove IPv4 SPI marking rules", __func__);
  }

  rc = nm_mdmprxy_common_mark_prov_flush_spi_rules(AF_INET6);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): failed to remove IPv6 SPI marking rules", __func__);
  }

  return NETMGR_SUCCESS;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_netd_oos_hdlr
===========================================================================*/
/*!
@brief
  Handle netd OOS event

@return
  NETMGR_SUCCESS / NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_netd_oos_hdlr(void)
{
  int rc = NETMGR_SUCCESS;
  struct nm_mdmprxy_cmd flush_pkt_marker_rules;

  memset(&flush_pkt_marker_rules, 0, sizeof(struct nm_mdmprxy_cmd));

  flush_pkt_marker_rules.rule = "%s" NM_MDMPRXY_FLAGS " -t mangle -F nm_mdmprxy_pkt_marker";
  flush_pkt_marker_rules.antirule = NULL;
  flush_pkt_marker_rules.formatter = nm_mdmprxy_basic_formatter;

  rc = nm_mdmprxy_process_rule(&flush_pkt_marker_rules, NM_MDMPRXY_RUN_RULE, AF_INET, NULL);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): failed to flush IPv4 pkt marker rules!", __func__);
  }

  rc = nm_mdmprxy_process_rule(&flush_pkt_marker_rules, NM_MDMPRXY_RUN_RULE, AF_INET6, NULL);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): failed to flush IPv6 pkt marker rules!", __func__);
  }

  return rc;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_netd_is_hdlr
===========================================================================*/
/*!
@brief
  Handle netd IS event

@return
  NETMGR_SUCCESS / NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_netd_is_hdlr(uint32_t packet_mark)
{
  int rc = NETMGR_FAILURE;
  int num_rules = nm_mdmprxy_rules_len(static_rule_list);

  if (NM_MDMPRXY_INVALID_PACKET_MARK == packet_mark)
  {
    netmgr_log_err("%s(): invalid packet mark received!", __func__);
    return NETMGR_FAILURE;
  }

  /* Cache the packet mark */
  nm_mdmprxy_common_oem_mark = packet_mark;

  /* Install static rules */
  rc = nm_mdmprxy_common_mark_prov_install_static_rules(AF_INET);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): failed to setup static IPv4 iptables rules!", __func__);
    return NETMGR_FAILURE;
  }

  rc = nm_mdmprxy_common_mark_prov_install_static_rules(AF_INET6);
  if (NETMGR_SUCCESS != rc)
  {
    netmgr_log_err("%s(): failed to setup static IPv6 iptables rules!", __func__);

    /* Cleanup the IPv4 installed rules */
    nm_mdmprxy_common_mark_prov_uninstall_static_rules(AF_INET, num_rules - 1);
    return NETMGR_FAILURE;
  }

  return NETMGR_SUCCESS;
}

/*===========================================================================
  FUNCTION  nm_mdmprxy_common_mark_prov_init
===========================================================================*/
/*!
@brief
  Initialization routine for setting up common mark provider rules and state

@return
  NETMGR_SUCCESS
  NETMGR_FAILURE
*/
/*=========================================================================*/
int nm_mdmprxy_common_mark_prov_init
(
  struct mark_prov_iptables *rulechains,
  uint32_t packet_mark
)
{
  int rc = NETMGR_SUCCESS;

  if (!rulechains)
  {
    netmgr_log_err("%s(): invalid input!", __func__);
    return NETMGR_FAILURE;
  }

  rulechains->per_iface_conntrack_rule_list     = per_iface_conntrack_rule_list;
  rulechains->per_iface_conntrack_rule_list_len
       = (int) nm_mdmprxy_rules_len(per_iface_conntrack_rule_list);

  /* Set the default preference for audio port-forwarding to be TRUE */
  comm_mark_prov_cfg.v4_audio_port_fwding_pref = TRUE;
  comm_mark_prov_cfg.v6_audio_port_fwding_pref = TRUE;

  rc = nm_mdmprxy_common_mark_prov_netd_is_hdlr(packet_mark);
  if (NETMGR_SUCCESS != rc)
  {
    return NETMGR_FAILURE;
  }

  return NETMGR_SUCCESS;
}
