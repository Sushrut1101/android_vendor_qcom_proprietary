/*
 * mdm_helper: A module to monitor modem activities on fusion devices
 *
 * Copyright (C) 2014 Qualcomm Technologies, Inc. All rights reserved.
 *                    Qualcomm Technologies Proprietary/GTDR
 *
 * All data and information contained in or disclosed by this document is
 * confidential and proprietary information of Qualcomm Technologies, Inc. and all
 * rights therein are expressly reserved.  By accepting this material the
 * recipient agrees that this material and the information contained therein
 * is held in confidence and in trust and will not be used, copied, reproduced
 * in whole or in part, nor its contents revealed in any manner to others
 * without the express written permission of Qualcomm Technologies, Inc.
 *
 *  mdm_helper.h : Header file needed by mdm_helper.c
 */

#ifndef MDM_HELPER_PRIVATE_H
#define MDM_HELPER_PRIVATE_H

#define RET_SUCCESS 0
#define RET_FAILED 1
#define RET_RETRY 2
#ifdef MDM_HELPER_PROXY
#define LOG_TAG "mdm_helper_proxy"
#else
#define LOG_TAG "mdm_helper"
#endif
#define LOG_NIDEBUG 0
#define MDM_NAME_LEN 40
#define EXTRA_DATA_MAX_LEN 60
#define DEBUG_MODE_PROPERTY "persist.mdm_boot_debug"
#define LINK_HSIC "HSIC"
#define LINK_UART "UART"
#ifndef LINK_PCIE
	#define LINK_PCIE "PCIe"
#endif
#define LINK_HSIC_PCIE	"HSIC+PCIe"
#include <log/log.h>

//Definitions being used for boot fail action mechanism
#ifdef ESOC_BOOT_FAIL_ACTION
#define BOOT_FAIL_PROPERTY "persist.vendor.mdm_helper.fail_action"
extern char boot_fail_property_string[PROPERTY_VALUE_MAX];
extern char boot_fail_property_string_copy[PROPERTY_VALUE_MAX];
extern char *token, *saveptr;
#endif

typedef enum MdmRequiredAction {
	MDM_REQUIRED_ACTION_NONE = 0,
	MDM_REQUIRED_ACTION_NORMAL_BOOT,
	MDM_REQUIRED_ACTION_RAMDUMPS,
	MDM_REQUIRED_ACTION_SHUTDOWN,
	MDM_REQUIRED_ACTION_RETRY
} MdmRequiredAction;

struct mdm_helper_drv;
struct mdm_device;

struct mdm_helper_ops{
	int (*power_up)(struct mdm_device *dev);
	int (*sahara)(struct mdm_device *dev);
	int (*shutdown)(struct mdm_device *dev);
	int (*monitor)(struct mdm_device *dev);
	int (*reboot)(struct mdm_device *dev);
	int (*prep_for_ramdumps)(struct mdm_device *dev);
	int (*collect_ramdumps)(struct mdm_device *dev);
	int (*post_ramdump_collect)(struct mdm_device *dev);
	int (*failure_cleanup)(struct mdm_device *dev);
	int (*standalone_mode)(struct mdm_device *dev, char *argv[]);
};

struct mdm_device {
	char mdm_name[MDM_NAME_LEN];
	char mdm_port[MDM_NAME_LEN];
	char mdm_link[MDM_NAME_LEN];
	char esoc_node[MDM_NAME_LEN];
	int device_descriptor;
	MdmRequiredAction required_action;
	char ram_dump_path[MDM_NAME_LEN];
	char images_path[MDM_NAME_LEN];
	struct mdm_helper_ops ops;
	void* private_data;
	char mdm_link_extra_data[EXTRA_DATA_MAX_LEN];
};

struct mdm_helper_drv {
	char *baseband_name;
	char *platform_name;
	int num_modems;
	struct mdm_device *dev;
};
#endif
