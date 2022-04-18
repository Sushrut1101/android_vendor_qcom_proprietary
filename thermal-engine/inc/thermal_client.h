/*===========================================================================

 Copyright (c) 2013, 2016, 2019 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/
#ifndef __THERMAL_CLIENT_H__
#define __THERMAL_CLIENT_H__

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_ACTIONS  (32)

/* Enum for supported fields */
enum supported_fields {
	UNKNOWN_FIELD = 0x0,
	DISABLE_FIELD = 0x1,
	SAMPLING_FIELD = 0x2,
	POLLING_DELAY_FIELD = SAMPLING_FIELD,
	THRESHOLDS_FIELD = 0x4,
	SET_POINT_FIELD = THRESHOLDS_FIELD,
	THRESHOLDS_CLR_FIELD = 0x8,
	SET_POINT_CLR_FIELD = THRESHOLDS_CLR_FIELD,
	ACTION_INFO_FIELD = 0x10,
	UPPER_LIMIT_FIELD = ACTION_INFO_FIELD,
	LOWER_LIMIT_FIELD = 0x20,
	PASSIVE_DELAY_FIELD = 0x40,
	SUPPORTED_FIELD_MAX = 0x80,
};

enum field_data_type {
	FIELD_INT = 0,
	FIELD_STR,
	FIELD_INT_ARR,
	FIELD_ARR_STR,
	FIELD_ARR_INT_ARR,
	FIELD_MAX
};

struct action_info_data {
	int info[MAX_ACTIONS];
	uint32_t num_actions;
};

struct field_data {
	char *field_name;
	enum field_data_type data_type;
	uint32_t num_data;
	void *data;
};

struct config_instance {
	char *cfg_desc;
	char *algo_type;
	unsigned int fields_mask;  /* mask set by client to request to adjust supported fields */
	uint32_t num_fields;
	struct field_data *fields;
};

int thermal_client_config_query(char *algo_type, struct config_instance **configs);
void thermal_client_config_cleanup(struct config_instance *configs, unsigned int config_size);
int thermal_client_config_set(struct config_instance *configs, unsigned int config_size);

int thermal_client_register_callback(char *client_name, int (*callback)(int , void *, void *), void *data);
int thermal_client_register_report_callback(int (*callback)(char *, void *, void*), void *data);
int thermal_client_request(char *client_name, int req_data);
void thermal_client_unregister_callback(int client_cb_handle);

/* APIs for bandwidth clients to send/clear bandwidth perf levels to thermal-engine */
int thermal_bandwidth_client_request(char *client_name, int req_data);
void thermal_bandwidth_client_cancel_request(char *client_name);

/* Inline API to combine two 15 bit bw inputs into single and return the same */
static inline int thermal_bandwidth_client_merge_input_info(int bw_score, int uc_id)
{
	if (bw_score < 0 || bw_score > 0x7fff ||
		uc_id < 0 || uc_id > 0x7fff)
		return -1;

	return (((uc_id & 0x7fff) << 0x10) | (bw_score & 0x7fff));
}

#ifdef __cplusplus
}
#endif

#endif /* __THERMAL_CLIENT_H__ */
