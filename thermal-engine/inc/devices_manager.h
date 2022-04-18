/*===========================================================================

  Copyright (c) 2012, 2015, 2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

#ifndef __DEVICES_MANAGER_H__
#define __DEVICES_MANAGER_H__

#include <stdint.h>

#define DEVICES_MAX_NAME_LEN 32
#define DEVICES_MAX_PATH  (128)

#define MAX_UNIT_NAME_SIZE 10
#define UNIT_NAME_VOLTS "mV"
#define UNIT_NAME_FREQ_KHZ "kHz"
#define UNIT_NAME_FREQ_HZ "Hz"
#define UNIT_NAME_LVL "lvl"

typedef struct device_clnt *device_clnt_handle;

/* Device clients types */
enum device_type {
	DEVICE_GENERIC_TYPE = 0,
	/* New types added after this point only. */
	DEVICE_OP_VALUE_TYPE,
	DEVICE_DIRECT_ACTION_TYPE,
	DEVICE_CDEV_TYPE,
	DEVICE_NONE_TYPE,
};

union device_request {
	int value;
	void *data;
};

struct device_lvl_info {
	union device_request lvl;
	int   perf_lvl;
};

struct device_state_info {
	uint8_t request_active;
	struct device_lvl_info current;
	struct device_lvl_info requested;
	struct device_lvl_info current_op;
};

struct device_info {
	char name[DEVICES_MAX_NAME_LEN];
	uint32_t num_of_levels;
	int32_t min_lvl;
	enum device_type dev_type;
	uint8_t max_dev_op_value_valid;
	int max_dev_op_value;
	uint8_t min_dev_op_value_valid;
	int min_dev_op_value;
	uint8_t max_pwr_usage_valid;
	int max_pwr_usage; /* milli watts units */
	int  device_units;
	char device_units_name[MAX_UNIT_NAME_SIZE];
	int cooling_dev_id;
};

typedef void (*device_notify_cb_func) (device_clnt_handle  clnt,
					union device_request *req,
					void *notify_cb_data);

/* Devices Mgr init */
int devices_manager_init(void);

/* Devices release/exit function */
void devices_manager_release(void);

/* Devices client functions */
int devices_manager_get_info(const char *dev_name, struct device_info *info);

/* Devices get list */
int devices_manager_get_list(struct device_info *info_arr, uint32_t *info_arr_len);

/* Get device levels list */
int devices_manager_get_lvl_list(const char *dev_name, struct device_lvl_info *info_arr,
			  uint32_t *info_arr_len);

/* Device register client */
device_clnt_handle devices_manager_reg_clnt(const char *dev_name);

/* Device de-register client */
int devices_manager_dereg_clnt(device_clnt_handle clnt);

/* Get device state info */
int devices_manager_get_state_info(device_clnt_handle clnt,
			   struct device_state_info *info);

/* Device request */
int device_clnt_request(device_clnt_handle clnt, union device_request *req);

/* Device cancel request */
void device_clnt_cancel_request(device_clnt_handle clnt);

/* Device reg notify function */
int devices_manager_reg_notify(device_clnt_handle     clnt,
			device_notify_cb_func  cb_func,
			void                   *notify_cb_data);

struct devices_manager_dev *find_dev(const char *dev_name);
#endif /* __DEVICES_MANAGER_H__ */
