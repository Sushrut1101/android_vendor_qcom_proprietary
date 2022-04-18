/******************************************************************************

                          N E T M G R _ R M N E T . C

******************************************************************************/

/******************************************************************************

  @file    netmgr_rmnet.h
  @brief   Network Manager RmNet Data configuration

  DESCRIPTION
  Network Manager RmNet Data configuration

******************************************************************************/
/*===========================================================================

  Copyright (c) 2013-2015, 2017-2019 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

/*===========================================================================
                              INCLUDE FILES
===========================================================================*/
#include <stdlib.h>
#include <stdint.h>
#include <linux/rmnet_data.h>       /* RmNet Kernel Constants */
#include <linux/msm_rmnet.h>        /* RmNet Kernel Constants */
#include "netmgr_defs.h"
#include "netmgr_platform.h"
#include "netmgr_util.h"
#include "netmgr_qmi_wda.h"
#include <netmgr_rmnet.h>     /* NetMgr RmNet Constants */
#include "librmnetctl.h"         /* RmNet Configuration Library */
#include <cutils/properties.h>
#include <string.h>
#include <dlfcn.h>
#define NETMGR_PHYS_TXPORT_INIT_RETRIES 120
#define NETMGR_INIT_MAX_RETRY 5
#define NETMGR_INIT_BASE_DELAY_US 100000

uint32_t netmgr_rmnet_data_device_qmi_offset;
int netmgr_vnd_last_flags = 0;

pthread_mutex_t netmgr_rmnet_mutex = PTHREAD_MUTEX_INITIALIZER;

/*===========================================================================
                            LOCAL FUNCTION DEFINITIONS
===========================================================================*/
static int
netmgr_rmnetctl_init
(
  rmnetctl_hndl_t **hndl,
  uint16_t *error_code
)
{
  int rc, retry=0;

  if (!hndl || !error_code)
  {
    netmgr_log_err("%s(): NULL handle/error_code", __func__);
    return RMNETCTL_INVALID_ARG;
  }

  do
  {
    if (retry != 0)
    {
      netmgr_log_med("%s(): Failed to init rmnet handle; waiting and retrying",
                     __func__);
      usleep(NETMGR_INIT_BASE_DELAY_US * retry);
    }
    rc = rmnetctl_init(hndl, error_code);
  } while (rc == RMNETCTL_LIB_ERR
           && *error_code == RMNETCTL_INIT_ERR_BIND
           && retry++ < NETMGR_INIT_MAX_RETRY);

  return rc;
}
/*===========================================================================
                            GLOBAL FUNCTION DEFINITIONS
===========================================================================*/

static int
_netmgr_rmnet_create_muxed_channel
(
  rmnetctl_hndl_t *hndl,
  const char     *phys_dev,
  unsigned int   dev_id,
  unsigned int   mux_id,
  const char     *dev_prefix
)
{
  int rc;
  uint16_t status_code;
  char dev_name[16];

  NETMGR_LOG_FUNC_ENTRY;

  do
  {
    if (dev_prefix)
    {
      rc = rmnet_new_vnd_prefix(hndl,
                                dev_id,
                                &status_code,
                                RMNETCTL_NEW_VND,
                                dev_prefix);
    }
    else
    {
      rc = rmnet_new_vnd(hndl, dev_id, &status_code, RMNETCTL_NEW_VND);
    }
    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed to create virtual device in slot %d [rc:%d][status_code:%d]",
                       __func__, dev_id, rc, status_code);
      break;
    }
    rc = rmnet_get_vnd_name(hndl,
                            dev_id,
                            &status_code,
                            dev_name,
                            sizeof(dev_name));
    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed get name of  device in slot %d [rc:%d][status_code:%d]",
                       __func__, dev_id, rc, status_code);
      break;
    }
    rc = rmnet_set_logical_ep_config(hndl,
                                     (int32_t)mux_id,
                                     RMNET_EPMODE_VND,
                                     phys_dev,
                                     (const char *)&dev_name,
                                     &status_code);
    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed to configure forward flow for rmnet_data%d [rc:%d][status_code:%d]",
                       __func__, mux_id, rc, status_code);
      break;
    }
    rc = rmnet_set_logical_ep_config(hndl,
                                     (int32_t)mux_id,
                                     RMNET_EPMODE_VND,
                                     (const char *)&dev_name,
                                     phys_dev,
                                     &status_code);
    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed to configure reverse flow for rmnet_data%d [rc:%d][status_code:%d]",
                       __func__, mux_id, rc, status_code);
      break;
    }
      netmgr_log_low("%s(): Created new virtual device %s in slot %d attached to %s:%d",
                     __func__, dev_name, dev_id, phys_dev, mux_id);
  } while (0);

  NETMGR_LOG_FUNC_EXIT;
  if (!rc)
    return NETMGR_RMNET_SUCCESS;
  else
    return NETMGR_RMNET_LIB_FAILURE;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_set_feature_flags
===========================================================================*/
/*!
@brief
  Set specific feature flags for ingress and egress

@arg *phys_dev physical device corresponding to a transport to modem
@arg ingress_flags ingress data format bitmask for physical device
@arg egress_flags  egress data format bitmask for physical device
@arg tail_spacing  tail spacing for the packet on the physical device

@return
  int - NETMGR_RMNET_SUCCESS if successful
        NETMGR_RMNET_BAD_ARGS if null/invalid arguments are passed
        NETMGR_RMNET_LIB_FAILURE if failed to configure kernel
*/
/*=========================================================================*/
int
netmgr_rmnet_set_feature_flags
(
  const char        *phys_dev,
  unsigned int      ingress_flags,
  unsigned int      egress_flags,
  uint32_t          tail_spacing
)
{
  rmnetctl_hndl_t *rmnet_cfg_handle;
  uint16_t status_code;
  int rc, result, vdev_loop;
  char dev_name[16];

  NETMGR_LOG_FUNC_ENTRY;

  result = NETMGR_RMNET_SUCCESS;
  if (!phys_dev)
  {
    netmgr_log_err("%s(): Internal error: dev cannot be null!\n", __func__);
    NETMGR_LOG_FUNC_EXIT;
    return NETMGR_RMNET_BAD_ARGS;
  }

  if ((rc = netmgr_rmnetctl_init(&rmnet_cfg_handle, &status_code) != RMNETCTL_SUCCESS))
  {
    netmgr_log_err("%s(): Init config handle failed [rc:%d][status_code:%d]\n",
                   __func__, rc, status_code);
    NETMGR_LOG_FUNC_EXIT;
    return NETMGR_RMNET_LIB_FAILURE;
  }

  if (ingress_flags != (unsigned int)NETMGR_RMNET_NO_FEATURE_FLAGS)
  {
    rc = rmnet_set_link_ingress_data_format_tailspace(rmnet_cfg_handle,
                                                      ingress_flags,
                                                      (uint8_t)tail_spacing,
                                                      phys_dev,
                                                      &status_code);
    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed to set ingress format %d on %s [rc:%d][status_code:%d]\n",
                     __func__, ingress_flags, phys_dev, rc, status_code);
      result = NETMGR_RMNET_LIB_FAILURE;
      goto cleanup;
    }
    netmgr_log_low("%s(): Set ingress format %d on %s\n",
                   __func__, ingress_flags, phys_dev);
  }

  if (egress_flags != (unsigned int)NETMGR_RMNET_NO_FEATURE_FLAGS)
  {
    rc = rmnet_set_link_egress_data_format(rmnet_cfg_handle,
                                           egress_flags,
                                           0,
                                           0,
                                           phys_dev,
                                           &status_code);
    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed to set egress format %d on %s [rc:%d][status_code:%d]\n",
                     __func__, egress_flags, phys_dev, rc, status_code);
      result = NETMGR_RMNET_LIB_FAILURE;
      goto cleanup;
    }
    netmgr_log_low("%s(): Set egress format %d on %s\n",
                   __func__, egress_flags, phys_dev);
  }

cleanup:
  rmnetctl_cleanup(rmnet_cfg_handle);

  NETMGR_LOG_FUNC_EXIT;
  return result;
}

/*===========================================================================
  FUNCTION netmgr_rmnet_update_ul_aggregation
===========================================================================*/
/*!
@brief
  Updates the aggregation parameters on an RmNet Data egress device
  First, egress flags are retrieved. If ul_agg_count is less than or equal to 1,
  then the aggregation flag is removed. Otherwise, the aggregation flag is ORed.
  The new flags and aggregation sizes are then passed up to RmNet Data

@arg *phys_dev physical device corresponding to a transport to modem
@arg ul_agg_count New aggregation packet count
@arg ul_agg_size New aggregation buffer size count

@return
  int - NETMGR_RMNET_SUCCESS if successful
  NETMGR_RMNET_BAD_ARGS if null/invalid arguments are passed
  NETMGR_RMNET_LIB_FAILURE if failed to configure kernel
*/
/*=========================================================================*/
int
netmgr_rmnet_update_ul_aggregation
(
  const char *phys_dev,
  unsigned int ul_agg_count,
  unsigned int ul_agg_size
)
{
  int result, rc;
  rmnetctl_hndl_t *rmnet_cfg_handle;
  uint16_t status_code;
  uint32_t egress_flags;
  uint16_t agg_size;
  uint16_t agg_count;
  uint16_t error_code;

  NETMGR_LOG_FUNC_ENTRY;
  result = NETMGR_RMNET_SUCCESS;

  if (!phys_dev)
  {
    netmgr_log_err("%s(): Internal error: dev cannot be null!\n", __func__);
    NETMGR_LOG_FUNC_EXIT;
    return NETMGR_RMNET_BAD_ARGS;
  }

  if ((rc = netmgr_rmnetctl_init(&rmnet_cfg_handle, &status_code) != RMNETCTL_SUCCESS))
  {
    netmgr_log_err("%s(): Init config handle failed [rc:%d][status_code:%d]\n",
                   __func__, rc, status_code);
    NETMGR_LOG_FUNC_EXIT;
    return NETMGR_RMNET_LIB_FAILURE;
  }

  rc = rmnet_get_link_egress_data_format(rmnet_cfg_handle, phys_dev,
                                         &egress_flags, &agg_size, &agg_count,
                                         &error_code);
  if (rc != RMNETCTL_SUCCESS)
  {
    netmgr_log_err("%s(): rmnet_get_link_egress_data_format failed "
                   "[rc:%d][status_code:%d]\n", __func__, rc, status_code);
    goto cleanup;
  }

  netmgr_log_low("%s(): RmNet returns egress_flags=0x%08X; agg_size=%d, "
                 "agg_count=%d\n", __func__, egress_flags, agg_size, agg_count);

  if (ul_agg_count <= 1)
    egress_flags &= ~RMNET_EGRESS_FORMAT_AGGREGATION;
  else
    egress_flags |= RMNET_EGRESS_FORMAT_AGGREGATION;

  agg_size = ul_agg_size;
  agg_count = ul_agg_count;
  netmgr_log_low("%s(): Updated egress_flags=0x%08X; agg_size=%d, "
                 "agg_count=%d\n", __func__, egress_flags, agg_size, agg_count);

  rc = rmnet_set_link_egress_data_format(rmnet_cfg_handle,
                                         egress_flags,
                                         agg_size,
                                         agg_count,
                                         phys_dev,
                                         &status_code);

  if (rc != RMNETCTL_SUCCESS)
  {
    netmgr_log_err("%s(): rmnet_set_link_egress_data_format failed "
                   "[rc:%d][status_code:%d]\n", __func__, rc, status_code);
    goto cleanup;
  }

cleanup:
  rmnetctl_cleanup(rmnet_cfg_handle);
  NETMGR_LOG_FUNC_EXIT;
  return result;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_create_muxed_channels
===========================================================================*/
/*!
@brief
  Create RmNet Data logical channels

@arg *phys_dev physical device corresponding to a transport to modem
@arg base_rmnet initial virtual RmNet device number
@arg base_mux_id initial mux id to use when tying virtual devices to physical
@arg num_virt_dev Number of virtual devices to create. These typicall correspond
     to logical Mux channels
@arg dev_prefix virtual network device name prefix

@return
  int - NETMGR_RMNET_SUCCESS if successful
        NETMGR_RMNET_BAD_ARGS if null/invalid arguments are passed
        NETMGR_RMNET_LIB_FAILURE if failed to configure kernel
*/
/*=========================================================================*/
int
netmgr_rmnet_create_muxed_channels
(
  const char        *phys_dev,
  unsigned int      base_rmnet,
  unsigned int      base_mux_id,
  unsigned int      num_virt_dev,
  const char        *dev_prefix
)
{
  int rc;
  unsigned int vdev_loop;
  uint16_t status_code;
  rmnetctl_hndl_t *hndl;

  NETMGR_LOG_FUNC_ENTRY;

  /* Input validation */

  if (!phys_dev)
  {
    netmgr_log_err("%s(): Internal error: dev cannot be null!\n", __func__);
    return NETMGR_RMNET_BAD_ARGS;
  }

  if ((0 == num_virt_dev) ||
      ((base_rmnet + num_virt_dev) > netmgr_main_cfg.max_links_in_total))
  {
    netmgr_log_err("%s(): Bad number of virtual devices: %d+%d\n",
                   __func__, base_rmnet, num_virt_dev);
    return NETMGR_RMNET_BAD_ARGS;
  }

  /* Initialize RmNet config handle */

  if ((rc = netmgr_rmnetctl_init(&hndl, &status_code) != RMNETCTL_SUCCESS))
  {
    netmgr_log_err("%s(): Init config handle failed [rc:%d][status_code:%d]\n",
                   __func__, rc, status_code);
    return NETMGR_RMNET_LIB_FAILURE;
  }


  /* Create Virtual Devs configuration */
  for (vdev_loop = 0; vdev_loop < num_virt_dev; vdev_loop ++)
  {
    _netmgr_rmnet_create_muxed_channel(hndl,
                                       phys_dev,
                                       base_rmnet + vdev_loop,
                                       base_mux_id + vdev_loop,
                                       dev_prefix);
  }

  rmnetctl_cleanup(hndl);

  NETMGR_LOG_FUNC_EXIT;
  return NETMGR_RMNET_SUCCESS;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_configure_phys_port
===========================================================================*/
/*!
@brief
  Configure RmNet Data kernel module to associate with physical device

@arg *phys_dev physical device corresponding to a transport to modems
@arg ingress_flags ingress data format bitmask for physical device
@arg egress_flags  egress data format bitmask for physical device

@return
  int - NETMGR_RMNET_SUCCESS if successful
        NETMGR_RMNET_BAD_ARGS if null/invalid arguments are passed
        NETMGR_RMNET_LIB_FAILURE if failed to configure kernel
*/
/*=========================================================================*/
static int
netmgr_rmnet_configure_phys_port
(
  const char        *phys_dev
)
{
  rmnetctl_hndl_t *rmnet_cfg_handle;
  uint16_t status_code;
  int rc, result;

  NETMGR_LOG_FUNC_ENTRY;
  result = NETMGR_RMNET_SUCCESS;
  if (!phys_dev)
  {
    netmgr_log_err("%s(): Internal error: dev cannot be null!\n", __func__);
    return NETMGR_RMNET_BAD_ARGS;
  }

  if ((rc = netmgr_rmnetctl_init(&rmnet_cfg_handle, &status_code) != RMNETCTL_SUCCESS))
  {
    netmgr_log_err("%s(): Init config handle failed [rc:%d][status_code:%d]\n",
                   __func__, rc, status_code);
    return NETMGR_RMNET_LIB_FAILURE;
  }

  rc = rmnet_associate_network_device(rmnet_cfg_handle,
                                      phys_dev,
                                      &status_code,
                                      RMNETCTL_DEVICE_ASSOCIATE);
  if (RMNETCTL_SUCCESS != rc)
  {
    netmgr_log_err("%s(): Failed to associate %s [rc:%d][status_code:%d]\n",
                   __func__, phys_dev, rc, status_code);
    result = NETMGR_RMNET_LIB_FAILURE;
    goto cleanup;
  }
  netmgr_log_low("%s(): Associated device: %s\n", __func__, phys_dev);

cleanup:
  rmnetctl_cleanup(rmnet_cfg_handle);

  NETMGR_LOG_FUNC_EXIT;
  return result;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_query_vnd_name
===========================================================================*/
/*!
@brief
  Query RmNet Data kernel module for the name of a VND

@arg dev_id numerical ID for VND
@arg name buffer to store VND name
@arg name_len length of name buffer in bytes

@return
  int - NETMGR_RMNET_SUCCESS if successful
        NETMGR_RMNET_BAD_ARGS if null/invalid arguments are passed
        NETMGR_RMNET_LIB_FAILURE if failed to configure kernel
*/
/*=========================================================================*/
int
netmgr_rmnet_query_vnd_name
(
  uint32_t  dev_id,
  char     *name,
  uint32_t  name_len
)
{
  rmnetctl_hndl_t *rmnet_cfg_handle;
  uint16_t status_code;
  int rc, rrc;

  NETMGR_LOG_FUNC_ENTRY;

  rrc = NETMGR_RMNET_SUCCESS;

  if (!name)
  {
    netmgr_log_err("%s(): Internal error: name cannot be null!\n", __func__);
    return NETMGR_RMNET_BAD_ARGS;
  }

  if ((rc = netmgr_rmnetctl_init(&rmnet_cfg_handle, &status_code) != RMNETCTL_SUCCESS))
  {
    netmgr_log_err("%s(): Init config handle failed [rc:%d][status_code:%d]\n",
                   __func__, rc, status_code);
    return NETMGR_RMNET_LIB_FAILURE;
  }

  rc = rmnet_get_vnd_name(rmnet_cfg_handle, dev_id, &status_code, name, name_len);
  if (RMNETCTL_SUCCESS != rc)
  {
    netmgr_log_err("%s(): Failed get name of vnd in slot %d [rc:%d][status_code:%d]\n",
                     __func__, dev_id, rc, status_code);
    rrc = NETMGR_RMNET_LIB_FAILURE;
  }

  rmnetctl_cleanup(rmnet_cfg_handle);

  NETMGR_LOG_FUNC_EXIT;
  return rrc;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_convert_rmnet_edf_to_ioctl_edf
===========================================================================*/
/*!
@brief
  Convert RmNet Data format flags to IOCTL format flags (egress)
*/
/*=========================================================================*/
uint32_t
netmgr_rmnet_convert_rmnet_edf_to_ioctl_edf
(
  uint32_t flags
)
{
  uint32_t flags_ioctl = 0;
  if (flags & RMNET_EGRESS_FORMAT_MAP)
    flags_ioctl |= RMNET_IOCTL_EGRESS_FORMAT_MAP;
  if (flags & RMNET_EGRESS_FORMAT_AGGREGATION)
    flags_ioctl |= RMNET_IOCTL_EGRESS_FORMAT_AGGREGATION;
  if (flags & RMNET_EGRESS_FORMAT_MUXING)
    flags_ioctl |= RMNET_IOCTL_EGRESS_FORMAT_MUXING ;
  if ((flags & RMNET_EGRESS_FORMAT_MAP_CKSUMV3) ||
    (flags & RMNET_EGRESS_FORMAT_MAP_CKSUMV4))
    flags_ioctl |= RMNET_IOCTL_EGRESS_FORMAT_CHECKSUM;
  return flags_ioctl;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_convert_rmnet_idf_to_ioctl_idf
===========================================================================*/
/*!
@brief
  Convert RmNet Data format flags to IOCTL format flags (ingress)
*/
/*=========================================================================*/
uint32_t
netmgr_rmnet_convert_rmnet_idf_to_ioctl_idf
(
  uint32_t flags
)
{
  uint32_t flags_ioctl = 0;
  if (flags & RMNET_INGRESS_FORMAT_MAP)
    flags_ioctl |= RMNET_IOCTL_INGRESS_FORMAT_MAP;
  if (flags & RMNET_INGRESS_FORMAT_DEAGGREGATION)
    flags_ioctl |= RMNET_IOCTL_INGRESS_FORMAT_DEAGGREGATION;
  if (flags & RMNET_INGRESS_FORMAT_DEMUXING)
    flags_ioctl |= RMNET_IOCTL_INGRESS_FORMAT_DEMUXING;
  if ((flags & RMNET_INGRESS_FORMAT_MAP_CKSUMV3) ||
    (flags & RMNET_INGRESS_FORMAT_MAP_CKSUMV4))
    flags_ioctl |= RMNET_IOCTL_INGRESS_FORMAT_CHECKSUM;
  return flags_ioctl;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_add_del_flow
===========================================================================*/
/*!
@brief
  Add / Delete a modem flow handle - tc flow handle mapping in the kernel.

@arg link id of the virtual network device to create the link
@arg mdm_flow_hndl modem flow id
@arg tc_flow_hndl tc flow id
@arg set_flow option to add or delete a flow pair mapping

@return
  int - NETMGR_SUCCESS if successful
        NETMGR_FAILURE if the operation fails
*/
/*=========================================================================*/
int
netmgr_rmnet_add_del_flow
(
  int       link,
  uint32_t  mdm_flow_hndl,
  uint32_t  tc_flow_hndl,
  uint8_t   set_flow
)
{
  int rc;
  int result = NETMGR_FAILURE;
  rmnetctl_hndl_t *rmnet_cfg_handle;
  uint16_t status_code;

  NETMGR_LOG_FUNC_ENTRY;

  /* Initialize RmNet config handle */

  if ((rc = netmgr_rmnetctl_init(&rmnet_cfg_handle, &status_code) != RMNETCTL_SUCCESS))
  {
    netmgr_log_err("%s(): Init config handle failed [rc:%d][status_code:%d]\n",
                    __func__, rc, status_code);
    goto error;
  }

  /* Add / Delete Flow handle */

  if ((rc = rmnet_add_del_vnd_tc_flow(rmnet_cfg_handle,
                                      (uint32_t)link,
                                      mdm_flow_hndl,
                                      tc_flow_hndl,
                                      set_flow,
                                      &status_code) != RMNETCTL_SUCCESS))
  {
    if (set_flow == RMNETCTL_ADD_FLOW)
    {
      netmgr_log_err("%s(): Adding flow failed [rc:%d][status_code:%d]\n",
                       __func__, rc, status_code);
    }
    else
    {
      netmgr_log_err("%s(): Deleting flow failed [rc:%d][status_code:%d]\n",
                       __func__, rc, status_code);
    }
    goto error;
  }

  result = NETMGR_SUCCESS;
  if (set_flow == RMNETCTL_ADD_FLOW)
  {
    netmgr_log_low("%s(): %s in link = %d, MAP Flow Handle = %d, TC Flow Handle = %d",
                   __func__,
                   "Added flow in kernel",
                   link,
                   mdm_flow_hndl,
                   tc_flow_hndl);
  }
  else
  {
    netmgr_log_low("%s(): %s in link = %d, MAP Flow Handle = %d, TC Flow Handle = %d",
                     __func__,
                   "Deleted flow in kernel",
                   link,
                   mdm_flow_hndl,
                   tc_flow_hndl);
  }

error:
  rmnetctl_cleanup(rmnet_cfg_handle);
  NETMGR_LOG_FUNC_EXIT;
  return result;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_get_ingress_data_format
===========================================================================*/
/*!
@brief
  Gets the ingress data format for a particular device.

@arg link id of the virtual network device to create the link
@arg flow_id flow id of the modem

@return
  int - NETMGR_SUCCESS if successful
        NETMGR_FAILURE if the operation fails
*/
/*=========================================================================*/
int
netmgr_rmnet_get_ingress_data_format
(
  const char        *phys_dev,
  uint32_t          *ingress_flags
)
{
  int rc;
  int result = NETMGR_FAILURE;
  uint16_t status_code;
  rmnetctl_hndl_t *rmnet_cfg_handle = NULL;

  NETMGR_LOG_FUNC_ENTRY;

  if (!phys_dev || !ingress_flags)
  {
    netmgr_log_err("%s(): Arguments cannot be NULL!\n", __func__);
    goto error;
  }

  /* Initialize RmNet config handle */

  if ((rc = netmgr_rmnetctl_init(&rmnet_cfg_handle, &status_code) != RMNETCTL_SUCCESS))
  {
    netmgr_log_err("%s(): Init config handle failed [rc:%d][status_code:%d]\n",
                   __func__, rc, status_code);
    goto error;
  }

  /* Get the ingress flags */

  if ((rc = rmnet_get_link_ingress_data_format(rmnet_cfg_handle,
                                               phys_dev,
                                               ingress_flags,
                                               &status_code) != RMNETCTL_SUCCESS))
  {
    netmgr_log_err("%s(): Failed to get the flags for deivce %s [rc:%d][status_code:%d]\n",
                   __func__, phys_dev, rc, status_code);
    goto error;
  }

  result = NETMGR_SUCCESS;

error:
  rmnetctl_cleanup(rmnet_cfg_handle);
  NETMGR_LOG_FUNC_EXIT;
  return result;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_get_device_qmi_offset
===========================================================================*/
/*!
@brief
  Gets the netmgr_rmnet_data_device_qmi_offset.

@arg qmi_offset qmi offset of the rmnet data device

@return
  int - NETMGR_SUCCESS if successful
        NETMGR_FAILURE if the operation fails
*/
/*=========================================================================*/
int
netmgr_rmnet_get_device_qmi_offset
(
  uint32_t          *qmi_offset
)
{
  int result = NETMGR_FAILURE;
  NETMGR_LOG_FUNC_ENTRY;

  if (!qmi_offset)
  {
    netmgr_log_err("%s(): Arguments cannot be NULL!\n", __func__);
    goto error;
  }

  *qmi_offset = netmgr_rmnet_data_device_qmi_offset;
  result = NETMGR_SUCCESS;
error:
  NETMGR_LOG_FUNC_EXIT;
  return result;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_set_device_qmi_offset
===========================================================================*/
/*!
@brief
  Sets the netmgr_rmnet_data_device_qmi_offset.

@arg qmi_offset qmi offset to be set for the rmnet data device

@return
  void
*/
/*=========================================================================*/
void
netmgr_rmnet_set_device_qmi_offset
(
  uint32_t          qmi_offset
)
{
  netmgr_rmnet_data_device_qmi_offset = qmi_offset;
}


/*===========================================================================
  FUNCTION  netmgr_rmnet_configure_ep_parameters
===========================================================================*/
/*!
@brief
  Configure ep parameters for IPA based targets

@return
  int - NETMGR_SUCCESS always

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
netmgr_rmnet_configure_ep_params()
{
  int i;

  /* This configuration is specific for IPA transport */
  if(0 != strncmp(NETMGR_PHYS_NET_DEV_RMNET_IPA, netmgr_main_cfg.phys_net_dev,
             sizeof(NETMGR_PHYS_NET_DEV_RMNET_IPA)))
  {
    /* Bail for Non IPA targets */
    netmgr_log_med("%s: Not a IPA target. Ignore ep configuration", __func__);
    return NETMGR_SUCCESS;
  }

  for (i = 0; i < NETMGR_PHYS_TXPORT_INIT_RETRIES; i++)
  {
    if (NETMGR_SUCCESS !=
        netmgr_kif_configure_ep_params(netmgr_main_cfg.phys_net_dev))
    {
      netmgr_log_err("%s: Failed to configure ep parameters for [%s]. Sleeping 1s before retry",
                     __func__, netmgr_main_cfg.phys_net_dev);
      sleep(1);
    }
    else
    {
      netmgr_log_med("%s: ep config completed successfully", __func__);
      break;
    }
  }

  if(i == NETMGR_PHYS_TXPORT_INIT_RETRIES)
  {
    netmgr_log_err("%s: unable to configure ep_id for transport [%s]",
                   __func__, netmgr_main_cfg.phys_net_dev);
  }
  return NETMGR_SUCCESS;
}


/*===========================================================================
  FUNCTION  netmgr_rmnet_configure_embedded_data
===========================================================================*/
/*!
@brief Creates rmnet embedded links with rmnet netlink messages to underlying
       rmnet kernel driver

@return
  int - NETMGR_SUCCESS always

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
netmgr_rmnet_configure_embedded_data
(
  void
)
{
  unsigned int mux_offset;
  int i, rc;
  unsigned int num_data_ports = netmgr_main_cfg.num_data_ports;
  unsigned int num_rev_data_ports = netmgr_main_cfg.num_rev_data_ports;
  netmgr_data_format_t *data_format = &netmgr_main_cfg.data_format;

  NETMGR_LOCK_MUTEX(netmgr_rmnet_mutex);
  for (i = 0; i < NETMGR_PHYS_TXPORT_INIT_RETRIES &&
              NETMGR_GET_MODEM_SSR_STATE() != NETMGR_MODEM_OOS_STATE ; i++)
  {
    if (NETMGR_SUCCESS !=
        netmgr_kif_init_physical_transport(netmgr_main_cfg.phys_net_dev, data_format))
    {
      netmgr_log_err("%s() Failed to init physical transport %s. Sleeping 1s before retry",
                     __func__, netmgr_main_cfg.phys_net_dev);
      sleep(1);
    }
    else
    {
      netmgr_log_med("%s() Successfully init physical transport %s",
                     __func__, netmgr_main_cfg.phys_net_dev);
      break;
    }
  }

  if(NETMGR_GET_MODEM_SSR_STATE() == NETMGR_MODEM_OOS_STATE)
  {
    netmgr_log_med("%s() Debug: Tried to init physical transport in OOS state", __func__);
  }

  mux_offset = NETMGR_RMNET_START;

  rc= netmgr_rmnet_configure_phys_port(netmgr_main_cfg.phys_net_dev);

  if (NETMGR_RMNET_SUCCESS != rc)
  {
    NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
    return NETMGR_SUCCESS;
  }

  rc = netmgr_rmnet_create_muxed_channels (netmgr_main_cfg.phys_net_dev,
                                           mux_offset,
                                           mux_offset + 1,
                                           num_data_ports,
                                           NULL);
  if (NETMGR_RMNET_SUCCESS != rc)
  {
    NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
    return NETMGR_SUCCESS;
  }

#ifdef FEATURE_DATA_IWLAN
  mux_offset = netmgr_main_cfg.rev_mux_offset;
  netmgr_rmnet_create_muxed_channels (netmgr_main_cfg.phys_net_dev,
                                      mux_offset,
                                      mux_offset + 1,
                                      num_rev_data_ports,
                                      NETMGR_MAIN_REV_RMNET_DATA_PREFIX);
#endif /* FEATURE_DATA_IWLAN */
  NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
  return NETMGR_SUCCESS;
}

int
netmgr_rmnet_remove_all_configuration
(
  void
)
{
  char dev_name[16];
  rmnetctl_hndl_t *rmnet_cfg_handle = NULL;
  const char *phys_dev = netmgr_main_cfg.phys_net_dev;
  netmgr_data_format_t *data_format = &netmgr_main_cfg.data_format;
  uint32_t i;
  int rc;
  uint16_t status_code;
  NETMGR_LOG_FUNC_ENTRY;

  /* Initialize RmNet config handle */
  netmgr_log_err("%s(): Triggering reset configs on %s", __func__, phys_dev);

  if ((rc = netmgr_rmnetctl_init(&rmnet_cfg_handle, &status_code) != RMNETCTL_SUCCESS))
  {
    netmgr_log_err("%s(): Init config handle failed [rc:%d][status_code:%d]\n",
                   __func__, rc, status_code);
    goto error;
  }

  for (i = 0; i < (unsigned int)(data_format->num_mux_channels + data_format->num_iwlan_channels); i++)
  {
    memset(dev_name, 0x0, sizeof(dev_name));
    rc = rmnet_get_vnd_name(rmnet_cfg_handle, i, &status_code, dev_name, sizeof(dev_name));
    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed get name of  device in slot %d [rc:%d][status_code:%d]",
                       __func__, i, rc, status_code);
      continue;
    }

    netmgr_log_err("%s(): Cleaning up [%d] %s", __func__, i, dev_name);

    rc = rmnet_unset_logical_ep_config(rmnet_cfg_handle, (int32_t)(i+1), phys_dev, &status_code);

    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed to unset ingress lepc [rc:%d][status_code:%d]",
                       __func__, rc, status_code);
    }
    rc = rmnet_unset_logical_ep_config(rmnet_cfg_handle, -1, dev_name, &status_code);

    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed to unset egress lepc [rc:%d][status_code:%d]",
                       __func__, rc, status_code);
    }

    rc = rmnet_new_vnd(rmnet_cfg_handle, i, &status_code,  RMNETCTL_FREE_VND);
    if (RMNETCTL_SUCCESS != rc)
    {
      netmgr_log_err("%s(): Failed to free vnd %d [rc:%d][status_code:%d]",
                       __func__, i, rc, status_code);
      continue;
    }
  }
  netmgr_log_err("%s(): Unassoc %s", __func__, phys_dev);
  rc = rmnet_associate_network_device(rmnet_cfg_handle,
                                      phys_dev,
                                      &status_code,
                                      RMNETCTL_DEVICE_UNASSOCIATE);

  if (RMNETCTL_SUCCESS != rc)
  {
    netmgr_log_err("%s(): Failed to unassociate dev %s [rc:%d][status_code:%d]",
                       __func__, phys_dev, rc, status_code);
    /* Fall through for cleanup and error handling */
  }
  rmnetctl_cleanup(rmnet_cfg_handle);

error:
  NETMGR_LOG_FUNC_EXIT;

  return (RMNETCTL_SUCCESS == rc ? NETMGR_SUCCESS : NETMGR_FAILURE);
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_configure_embedded_link
===========================================================================*/
/*!
@brief Creates a single rmnet embedded link with RTM_NETLINK messages to
       underlying rmnet kernel driver using librmnetctl library

@param
  int - link_num - number of the link (ex: rmnet_dataX)

@return
  int - NETMGR_SUCCESS if link was created, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
netmgr_rmnet_configure_embedded_link
(
  int link_num
)
{
  int iwlan_link_num;
  int rc = NETMGR_FAILURE;
  uint16_t err = NETMGR_FAILURE;
  rmnetctl_hndl_t *rmnet_cfg_handle = NULL;
  char vnd_name[NETMGR_IF_NAME_MAX_LEN];
  NETMGR_LOCK_MUTEX(netmgr_rmnet_mutex);

  if (rtrmnet_ctl_init(&rmnet_cfg_handle, &err) < 0)
  {
    netmgr_log_err("%s(): Error on rtrmnet lib init ", __func__);
    NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
    return rc;
  }

  if (link_num >=0 && link_num < netmgr_main_cfg.rev_link_start)
  {
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN,"%s%d",
             NETMGR_MAIN_RMNET_DATA_PREFIX, link_num);

    if(rtrmnet_ctl_newvnd(rmnet_cfg_handle, netmgr_main_cfg.phys_net_dev,
                          vnd_name , &err, 1 + link_num, 0) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib init Error code:%d",
                     __func__, err);
      goto bail;
    }
    else
    {
      netmgr_log_med("%s(): rtrmnet created new fwd vnd %d",
                     __func__, link_num);
      rc = NETMGR_SUCCESS;
      goto bail;
    }
  }
  else
  {
    netmgr_log_med("%s(): invalid forward link num %d, maybe iwlan link",
                   __func__, link_num);
  }

#ifdef FEATURE_DATA_IWLAN
  if (link_num >= netmgr_main_cfg.rev_link_start &&
      link_num < netmgr_main_cfg.max_links_in_total)
  {
    iwlan_link_num = link_num - netmgr_main_cfg.rev_link_start;
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN,"%s%d",
             NETMGR_MAIN_REV_RMNET_DATA_PREFIX, iwlan_link_num);

    if(rtrmnet_ctl_newvnd(rmnet_cfg_handle, netmgr_main_cfg.phys_net_dev,
                          vnd_name , &err,
                          netmgr_main_cfg.rev_mux_offset + iwlan_link_num + 1,
                          0) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib init Error code:%d",
                     __func__, err);
      goto bail;
    }
    else
    {
      netmgr_log_med("%s(): rtrmnet created new iwlan vnd %d",
                     __func__, iwlan_link_num);
      rc = NETMGR_SUCCESS;
      goto bail;
    }
  }
  else
  {
    netmgr_log_med("%s(): invalid iwlan link num %d", __func__, link_num);
  }
#endif /* FEATURE_DATA_IWLAN */

bail:
  rtrmnet_ctl_deinit(rmnet_cfg_handle);

  NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
  return rc;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_configure_embedded_links
===========================================================================*/
/*!
@brief Creates rmnet embedded links with RTM_NETLINK messages to underlying
       rmnet kernel driver using librmnetctl library


@return
  int - NETMGR_SUCCESS always

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
netmgr_rmnet_configure_embedded_links
(
  void
)
{
  unsigned int mux_offset;
  unsigned int rev_mux_offset;
  unsigned int num_data_ports = netmgr_main_cfg.num_data_ports;
  unsigned int num_rev_data_ports = netmgr_main_cfg.num_rev_data_ports;
  int i;
  uint16_t err = NETMGR_FAILURE;
  netmgr_data_format_t *data_format = &netmgr_main_cfg.data_format;
  rmnetctl_hndl_t *rmnet_cfg_handle = NULL;
  char vnd_name[NETMGR_IF_NAME_MAX_LEN];
  NETMGR_LOCK_MUTEX(netmgr_rmnet_mutex);


  mux_offset = NETMGR_RMNET_START;
  netmgr_kif_init_physical_transport(netmgr_main_cfg.phys_net_dev, data_format);

  if (rtrmnet_ctl_init(&rmnet_cfg_handle, &err) < 0)
  {
    netmgr_log_err("%s(): Error on rtrmnet lib init ", __func__);
  }

  for (i = mux_offset; i < num_data_ports; i++)
  {
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN,"%s%d",
             NETMGR_MAIN_RMNET_DATA_PREFIX, i);

    if(rtrmnet_ctl_newvnd(rmnet_cfg_handle, netmgr_main_cfg.phys_net_dev,
                          vnd_name , &err, 1 + i, 0) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib init Error code:%d",
                     __func__, err);
    }
    else
    {
      netmgr_log_med("%s(): rtrmnet created new vnd %d", __func__, i);
    }
  }
#ifdef FEATURE_DATA_IWLAN
  rev_mux_offset = netmgr_main_cfg.rev_mux_offset;
  for (i = 0; i < (unsigned char)num_rev_data_ports; i++)
  {
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN, "%s%d",
             NETMGR_MAIN_REV_RMNET_DATA_PREFIX, i);

    if(rtrmnet_ctl_newvnd(rmnet_cfg_handle, netmgr_main_cfg.phys_net_dev,
                          vnd_name , &err, rev_mux_offset + i +1, 0) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib init Error code:%d",
                     __func__, err);
    }
    else
    {
      netmgr_log_med("%s(): rtrmnet created new iwlan vnd %d ", __func__, i);
    }
  }

#endif /* FEATURE_DATA_IWLAN */

  rtrmnet_ctl_deinit(rmnet_cfg_handle);

  NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
  return NETMGR_SUCCESS;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_change_embedded_link
===========================================================================*/
/*!
@brief Changes flag config of an existing link with RTM_NETLINK messages to
       underlying rmnet kernel driver with use of librmnetctl library

@param
  int - link number

@return
  int - NETMGR_SUCCESS always

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
netmgr_rmnet_change_embedded_link
(
  int link_num
)
{
  int iwlan_link_num;
  int flag = 0;
  int rc = NETMGR_FAILURE;
  uint16_t err = NETMGR_FAILURE;
  rmnetctl_hndl_t *rmnet_cfg_handle = NULL;
  char vnd_name[NETMGR_IF_NAME_MAX_LEN];
  NETMGR_LOCK_MUTEX(netmgr_rmnet_mutex);

  flag = netmgr_vnd_last_flags;

  if (rtrmnet_ctl_init(&rmnet_cfg_handle, &err) < 0)
  {
    netmgr_log_err("%s(): Error on rtrmnet lib init ", __func__);
    NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
    return rc;
  }

  if (link_num >=0 && link_num < netmgr_main_cfg.rev_link_start)
  {
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN,"%s%d",
             NETMGR_MAIN_RMNET_DATA_PREFIX, link_num);

    if(rtrmnet_ctl_changevnd(rmnet_cfg_handle, netmgr_main_cfg.phys_net_dev,
                             vnd_name , &err, 1 + link_num, flag) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib changevnd Error code:%d",
                     __func__, err);
      goto bail;
    }
    else
    {
      netmgr_log_high("%s(): rtrmnet changed vnd %d with flag %d",
                      __func__, link_num, flag);
      rc = NETMGR_SUCCESS;
      goto bail;
    }
  }
  else
  {
    netmgr_log_med("%s(): invalid forward link num %d, maybe iwlan link",
                   __func__, link_num);
  }

#ifdef FEATURE_DATA_IWLAN
  if (link_num >= netmgr_main_cfg.rev_link_start &&
      link_num < netmgr_main_cfg.max_links_in_total)
  {
    iwlan_link_num = link_num - netmgr_main_cfg.rev_link_start;
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN,"%s%d",
             NETMGR_MAIN_REV_RMNET_DATA_PREFIX, iwlan_link_num);

    if(rtrmnet_ctl_changevnd(rmnet_cfg_handle, netmgr_main_cfg.phys_net_dev,
                             vnd_name , &err,
                             netmgr_main_cfg.rev_mux_offset + iwlan_link_num + 1,
                             flag) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib changevnd Error code:%d",
                     __func__, err);
      goto bail;
    }
    else
    {
      netmgr_log_high("%s(): rtrmnet changed iwlan vnd %d with flag %d",
                      __func__, link_num, flag);
      rc = NETMGR_SUCCESS;
      goto bail;
    }
  }
  else
  {
    netmgr_log_med("%s(): invalid iwlan link num %d", __func__, link_num);
  }
#endif /* FEATURE_DATA_IWLAN */

bail:
  rtrmnet_ctl_deinit(rmnet_cfg_handle);

  NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
  return rc;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_change_embedded_links
===========================================================================*/
/*!
@brief Changes flag config of an existing link with RTM_NETLINK messages to
       underlying rmnet kernel driver with use of librmnetctl library

@param
  int - flag configuration for links

@return
  int - NETMGR_SUCCESS always

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
netmgr_rmnet_change_embedded_links
(
  int flag
)
{
  unsigned int mux_offset;
  unsigned int rev_mux_offset;
  int i;
  uint16_t err = NETMGR_FAILURE;
  unsigned int num_data_ports = netmgr_main_cfg.num_data_ports;
  unsigned int num_rev_data_ports = netmgr_main_cfg.num_rev_data_ports;
  rmnetctl_hndl_t *rmnet_cfg_handle = NULL;
  char vnd_name[NETMGR_IF_NAME_MAX_LEN];
  NETMGR_LOCK_MUTEX(netmgr_rmnet_mutex);

  netmgr_vnd_last_flags = flag;

  mux_offset = NETMGR_RMNET_START;

  if (rtrmnet_ctl_init(&rmnet_cfg_handle, &err) < 0)
  {
    netmgr_log_err("%s(): Error on rtrmnet lib init ", __func__);
  }
  mux_offset = NETMGR_RMNET_START;

  for (i = mux_offset; i < num_data_ports; i++)
  {
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN,"%s%d",
             NETMGR_MAIN_RMNET_DATA_PREFIX, i);

    if(rtrmnet_ctl_changevnd(rmnet_cfg_handle, netmgr_main_cfg.phys_net_dev,
                             vnd_name , &err, 1 + i, flag) < 0){
      netmgr_log_err("%s(): Error on rtrmnet lib init Error code:%d",
                     __func__, err);
    }
    else {
      netmgr_log_high("%s(): rtrmnet changed vnd %d with flag %d",
                       __func__, i, flag);
    }
  }
#ifdef FEATURE_DATA_IWLAN
  rev_mux_offset = netmgr_main_cfg.rev_mux_offset;
  for (i = 0; i < num_rev_data_ports; i++)
  {
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN, "%s%d",
             NETMGR_MAIN_REV_RMNET_DATA_PREFIX, i);

    if(rtrmnet_ctl_changevnd(rmnet_cfg_handle, netmgr_main_cfg.phys_net_dev,
                             vnd_name , &err, rev_mux_offset + i + 1, flag) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib init Error code:%d", __func__,
                     err);
    }
    else
    {
      netmgr_log_high("%s(): rtrmnet changed iwlan vnd %d with flag %d",
                      __func__, i, flag);
    }
  }

#endif /* FEATURE_DATA_IWLAN */

  rtrmnet_ctl_deinit(rmnet_cfg_handle);

  NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
  return NETMGR_SUCCESS;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_remove_embedded_link
===========================================================================*/
/*!
@brief Removes rmnet embedded link with RTM_NETLINK messages from underlying
       rmnet kernel driver with the help of librmnetctl library

@return
  int - NETMGR_SUCCESS if vnd is removed, NETMGR_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
netmgr_rmnet_remove_embedded_link
(
  int link_num
)
{
  int iwlan_link_num;
  int rc = NETMGR_FAILURE;
  uint16_t err = NETMGR_FAILURE;
  rmnetctl_hndl_t *rmnet_cfg_handle = NULL;
  char vnd_name[NETMGR_IF_NAME_MAX_LEN];
  NETMGR_LOCK_MUTEX(netmgr_rmnet_mutex);

  if (rtrmnet_ctl_init(&rmnet_cfg_handle, &err) < 0)
  {
    netmgr_log_err("%s(): Error on rtrmnet lib init ", __func__);
    NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
    return rc;
  }

  if (link_num >=0 && link_num < netmgr_main_cfg.rev_link_start)
  {
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN,"%s%d",
             NETMGR_MAIN_RMNET_DATA_PREFIX, link_num);

    if (rtrmnet_ctl_delvnd(rmnet_cfg_handle, vnd_name , &err) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib init Error code:%d",
                     __func__, err);
      goto bail;
    }
    else
    {
      netmgr_log_med("%s(): rtrmnet deleted fwd vnd %d",
                     __func__, link_num);
      rc = NETMGR_SUCCESS;
      goto bail;
    }
  }
  else
  {
    netmgr_log_med("%s(): invalid forward link num %d, maybe iwlan link",
                   __func__, link_num);
  }

#ifdef FEATURE_DATA_IWLAN
  if (link_num >= netmgr_main_cfg.rev_link_start &&
      link_num < netmgr_main_cfg.max_links_in_total)
  {
    iwlan_link_num = link_num - netmgr_main_cfg.rev_link_start;
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN,"%s%d",
             NETMGR_MAIN_REV_RMNET_DATA_PREFIX, iwlan_link_num);

    if (rtrmnet_ctl_delvnd(rmnet_cfg_handle, vnd_name , &err) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib delvnd Error code:%d",
                     __func__, err);
      goto bail;
    }
    else
    {
      netmgr_log_med("%s(): rtrmnet deleted iwlan vnd %d",
                     __func__, iwlan_link_num);
      rc = NETMGR_SUCCESS;
      goto bail;
    }
  }
  else
  {
    netmgr_log_med("%s(): invalid iwlan link num %d", __func__, link_num);
  }
#endif /* FEATURE_DATA_IWLAN */

bail:
  rtrmnet_ctl_deinit(rmnet_cfg_handle);

  NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
  return rc;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_remove_embedded_links
===========================================================================*/
/*!
@brief Removes rmnet embedded links with RTM_NETLINK messages from underlying
       rmnet kernel driver with the help of librmnetctl library

@return
  int - NETMGR_SUCCESS always

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int netmgr_rmnet_remove_embedded_links(void)
{
  unsigned int mux_offset;
  int i;
  uint16_t err;
  rmnetctl_hndl_t *rmnet_cfg_handle;
  unsigned int num_data_ports = netmgr_main_cfg.num_data_ports;
  unsigned int num_rev_data_ports = netmgr_main_cfg.num_rev_data_ports;
  char vnd_name[NETMGR_IF_NAME_MAX_LEN];
  NETMGR_LOCK_MUTEX(netmgr_rmnet_mutex);

  mux_offset = NETMGR_RMNET_START;

  if (rtrmnet_ctl_init(&rmnet_cfg_handle, &err) < 0)
  {
    netmgr_log_err("%s(): Error on rtrmnet lib init ", __func__);
  }

  mux_offset = NETMGR_RMNET_START;

  for (i = mux_offset; i < num_data_ports; i++)
  {
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN, "%s%d",
             NETMGR_MAIN_RMNET_DATA_PREFIX, i);

    if (rtrmnet_ctl_delvnd(rmnet_cfg_handle, vnd_name , &err) < 0){
      netmgr_log_err("%s(): Error on rtrmnet lib init Error code:%d",
                     __func__, err);
    }
    else
    {
      netmgr_log_err("%s(): rtrmnet del new vnd %d", __func__, i);
    }
  }
#ifdef FEATURE_DATA_IWLAN
  for (i = 0; i < num_rev_data_ports; i++)
  {
    snprintf(vnd_name, NETMGR_IF_NAME_MAX_LEN, "%s%d",
             NETMGR_MAIN_REV_RMNET_DATA_PREFIX, i);

    if (rtrmnet_ctl_delvnd(rmnet_cfg_handle, vnd_name , &err) < 0)
    {
      netmgr_log_err("%s(): Error on rtrmnet lib init Error code:%d",
                     __func__, err);
    }
    else
    {
      netmgr_log_err("%s(): rtrmnet del new iwlan vnd %d", __func__, i);
    }
  }

#endif /* FEATURE_DATA_IWLAN */

  rtrmnet_ctl_deinit(rmnet_cfg_handle);

  NETMGR_UNLOCK_MUTEX(netmgr_rmnet_mutex);
  return NETMGR_SUCCESS;
}


/*===========================================================================
  FUNCTION  netmgr_rmnet_ext_init
===========================================================================*/
/*!
@brief Init Netmgr rmnet extention

@return
  int - NETMGR_SUCCESS/NETMGR_FAILURE

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/

/* Rmnet ext init flags:
   Bits 0-3: Kernel flow control mode
   Bits 4: QMI power collapse enabled
   Bits 5: Kernel QMAP flow control enabled
*/
#define NETMGR_KFC_MASK 0x0F
#define NETMGR_QPC_MASK 0x10
#define NETMGR_QMAP_MASK 0x20
#define NETMGR_KFC_FLAGS(kfc) ((kfc) & NETMGR_KFC_MASK)
#define NETMGR_QPC_FLAGS(qpc) ((qpc) ? NETMGR_QPC_MASK : 0)
#define NETMGR_QMAP_FLAGS(qmap) ((qmap) ? NETMGR_QMAP_MASK : 0)

#define NETMGR_RMNET_EXT_LIB "libnetmgr_rmnet_ext.so"
#define NETMGR_RMNET_EXT_INIT_FUNC "__netmgr_rmnet_ext_init"
typedef int netmgr_rmnet_ext_init_f(int flags);

int netmgr_rmnet_ext_init()
{
  void *dl_handle = NULL;
  char *err = NULL;
  netmgr_rmnet_ext_init_f *rmnet_ext_init = NULL;
  int flags =0;

  flags = NETMGR_KFC_FLAGS(netmgr_main_cfg.kfc_mode) |
          NETMGR_QPC_FLAGS(netmgr_main_cfg.qmi_pc) |
          NETMGR_QMAP_FLAGS(netmgr_main_cfg.kfc_qmap);

  if (0 == flags)
  {
    return NETMGR_SUCCESS;
  }

  dl_handle = dlopen(NETMGR_RMNET_EXT_LIB, RTLD_NOW);
  if (NULL == dl_handle)
  {
    netmgr_log_err("Can't open %s", NETMGR_RMNET_EXT_LIB);
    goto bail;
  }

  rmnet_ext_init = (netmgr_rmnet_ext_init_f *)
             dlsym(dl_handle, NETMGR_RMNET_EXT_INIT_FUNC);

  if (NULL == rmnet_ext_init)
  {
      err = (char *)dlerror();
      if (err != NULL)
      {
          netmgr_log_err("%s not found in %s: %s",
                  NETMGR_RMNET_EXT_INIT_FUNC, NETMGR_RMNET_EXT_LIB, err);
      }
      goto bail;
  }

  if (NETMGR_SUCCESS != rmnet_ext_init(flags))
  {
    netmgr_log_err("Failed rmnet ext init with flags 0x%x", flags);
    goto bail;
  }

  return NETMGR_SUCCESS;

bail:

  netmgr_main_cfg.kfc_mode = 0;
  netmgr_main_cfg.qmi_pc = 0;
  netmgr_main_cfg.kfc_qmap = 0;

  return NETMGR_FAILURE;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_set_ko_loading_property
===========================================================================*/
/*!
@brief
  Sets android properties to trigger loading of netmgr kernel modules

@param
  prop_name - Name of the property

@param
  prop_value - value to be set in the property
               0 - for disabling
               1 - for enabling

@return
  int - NETMGR_SUCCESS if properties were set correctly
        NETMGR_FAILURE otherwise
*/
/*=========================================================================*/
int netmgr_rmnet_set_ko_loading_property(const char *prop_name, const char *prop_value)
{
  int ret_val = -1;

  if (!prop_name)
  {
    netmgr_log_err("%s(): invalid property name received!", __func__);
    return NETMGR_FAILURE;
  }

  ret_val = property_set(prop_name, prop_value);
  if (ret_val != 0)
  {
    netmgr_log_err("%s(): could not set the property [%s] to [%s]!",
                   __func__, prop_name, prop_value);
    return NETMGR_FAILURE;
  }
  else
  {
    netmgr_log_low("%s(): set the property [%s] to [%s]!", __func__, prop_name, prop_value);
  }

  return NETMGR_SUCCESS;
}

/*===========================================================================
  FUNCTION  netmgr_rmnet_set_shsusr_loading_property
===========================================================================*/
/*!
@brief
  Sets android properties to trigger loading of shsusrd module

@param
  prop_name - Name of the property

@param
  prop_value - value to be set in the property
               0 - for disabling
               1 - for enabling

@return
  int - NETMGR_SUCCESS if properties were set correctly
        NETMGR_FAILURE otherwise
*/
/*=========================================================================*/
int netmgr_rmnet_set_shsusr_loading_property(const char *prop_name,
                                             const char *prop_value)
{
  int ret_val = -1;

  if (!prop_name)
  {
    netmgr_log_err("%s(): invalid property name received!", __func__);
    return NETMGR_FAILURE;
  }

  ret_val = property_set(prop_name, prop_value);
  if (ret_val != 0)
  {
    netmgr_log_err("%s(): could not set the property [%s] to [%s]!",
                   __func__, prop_name, prop_value);
    return NETMGR_FAILURE;
  }
  else
  {
    netmgr_log_low("%s(): set the property [%s] to [%s]!", __func__, prop_name, prop_value);
  }

  return NETMGR_SUCCESS;

}

/*===========================================================================
  FUNCTION netmgr_rmnet_update_embedded_ul_aggregation
===========================================================================*/
/*!
@brief
  Updates the aggregation parameters on an RmNet Data egress device

@arg *phys_dev physical device corresponding to a transport to modem
@arg ul_agg_count New aggregation packet count
@arg ul_agg_size New aggregation buffer size count
@arg ul_agg_time New aggregation time limit in nanoseconds

@return
  int - NETMGR_RMNET_SUCCESS if successful
  NETMGR_RMNET_BAD_ARGS if null/invalid arguments are passed
  NETMGR_RMNET_LIB_FAILURE if failed to configure kernel
*/
/*=========================================================================*/
int
netmgr_rmnet_update_embedded_ul_aggregation
(
  const char *phys_dev,
  unsigned int ul_agg_count,
  unsigned int ul_agg_size,
  unsigned int ul_agg_time,
  unsigned int ul_agg_features
)
{
  int result, rc;
  rmnetctl_hndl_t *rmnet_cfg_handle;
  uint16_t status_code;
  char *vnd_name = NETMGR_MAIN_RMNET_DATA_PREFIX "0";

  NETMGR_LOG_FUNC_ENTRY;
  result = NETMGR_RMNET_SUCCESS;

  if (!phys_dev)
  {
    netmgr_log_err("%s(): Internal error: dev cannot be null!\n", __func__);
    NETMGR_LOG_FUNC_EXIT;
    return NETMGR_RMNET_BAD_ARGS;
  }

  rc = rtrmnet_ctl_init(&rmnet_cfg_handle, &status_code);
  if (rc < 0)
  {
    netmgr_log_err("%s(): rtrmnet handle init failed [rc:%d][status_code:%d]\n",
                   __func__, rc, status_code);
    NETMGR_LOG_FUNC_EXIT;
    return NETMGR_RMNET_LIB_FAILURE;
  }

  netmgr_log_low("%s(): Updated UL agg params: agg_size=%d, agg_count=%d, "
                 "agg_time=%d agg_features=0x%02x\n", __func__, ul_agg_size, ul_agg_count,
                 ul_agg_time, ul_agg_features);

  rc = rtrmnet_set_uplink_aggregation_params(rmnet_cfg_handle, phys_dev,
                                             vnd_name, (uint8_t)ul_agg_count,
                                             (uint16_t)ul_agg_size,
                                             (uint32_t)ul_agg_time,
                                             (uint8_t)ul_agg_features,
                                             &status_code);

  if (rc != RMNETCTL_SUCCESS)
  {
    netmgr_log_err("%s(): rmnet_set_uplink_aggregation_params failed "
                   "[rc:%d][status_code:%d]\n", __func__, rc, status_code);
    result = NETMGR_RMNET_LIB_FAILURE;
  }

  rtrmnet_ctl_deinit(rmnet_cfg_handle);
  NETMGR_LOG_FUNC_EXIT;
  return result;
}
