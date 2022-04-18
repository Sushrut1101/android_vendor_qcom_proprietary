/*===========================================================================

  Copyright (c) 2012-2016, 2109 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

#ifndef __THERMAL_CONFIG_H__
#define __THERMAL_CONFIG_H__

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include "devices_manager.h"
#include "sensors_manager.h"

#define SAMPLING_MS_DEFAULT  (5000U)
#ifdef SENSORS_8960
#define SAMPLING_MS_MINIMUM  (100U)
#else
#define SAMPLING_MS_MINIMUM  (2U)
#endif

/* Below few macros are duplicated in
   server/thermal_lib_common.h */
#define THRESHOLDS_MAX       (12U)
#define ACTIONS_MAX          (32U)
#define INTEGERS_MAX         (4U)
#define MAX_ALGO_DESC        (32U)
#define LOAD_VIRTUAL_FLAG    (1U)
#define LOAD_ALL_FLAG        (0U)
#define PRINT_TO_INFO        (0U)
#define PRINT_TO_STDOUT      (1U)

#define MAX_NUM_SENSOR 8
#define MAX_MITIGATION_LEVEL 12

enum algo_type {
	UNKNOWN_ALGO_TYPE = -1,
	MONITOR_ALGO_TYPE = 0,
	PID_ALGO_TYPE,
	SS_ALGO_TYPE,
	TB_ALGO_TYPE,
	EQUILIBRIUM_TYPE,
	VIRTUAL_SENSOR_TYPE,
	BWLM_ALGO_TYPE,
	STEP_WISE_ALGO_TYPE,
	ALGO_IDX_MAX,
};

struct action_t {
	char device[DEVICES_MAX_NAME_LEN];
	int  info;
	int  device_idx;
};

struct threshold_t {
	int lvl_trig;
	int lvl_clr;
	struct action_t actions[ACTIONS_MAX];
	uint32_t num_actions;
};

struct pid_setting {
	char sensor[MAX_SENSOR_NAME_LEN];
	char device[DEVICES_MAX_NAME_LEN];
	int  override;
	uint32_t sampling_period_ms;
	int  i_samples;
	int  set_point;
	int  set_point_clr;
	int  units_per_C;
	float freq_scale;
	float p_const;
	float i_const;
	float d_const;
	float err_weight;
};

struct tm_setting {
	char    sensor[MAX_SENSOR_NAME_LEN];
	uint32_t sampling_period_ms;
	uint32_t  num_thresholds;
	int     override;
	uint8_t descending_thresh;
	struct  threshold_t t[THRESHOLDS_MAX];

	/* internal counters used during config parsing */
	uint32_t _n_thresholds;
	uint32_t _n_to_clear;
	uint32_t _n_actions;
	uint32_t _n_action_info;
};

struct bwlm_threshold_t {
	uint64_t ib_trig;
	uint64_t ib_clr;
	uint64_t ab_trig[MAX_NUM_SENSOR];
	uint64_t ab_clr[MAX_NUM_SENSOR];
	uint64_t utilize_trig;
	uint64_t utilize_clr;
	struct action_t actions[ACTIONS_MAX];
	uint32_t num_actions;
};

enum bus_type {
	UNKNOWN_BUS_TYPE,
	BIMC_BUS_TYPE,
	MAX_BUS_TYPE,
};

struct bwlm_setting {
	char    sensor_list[MAX_NUM_SENSOR][MAX_SENSOR_NAME_LEN];
	enum bus_type bus;
	uint32_t num_sensors;
	uint32_t num_thresholds;
	struct  bwlm_threshold_t t[THRESHOLDS_MAX];

	/* internal counters used during config parsing */
	uint32_t _n_thresholds;
	uint32_t _n_to_clear;
	uint32_t _n_actions;
	uint32_t _n_action_info;
};

struct ss_setting {
	char sensor[MAX_SENSOR_NAME_LEN];
	char device[DEVICES_MAX_NAME_LEN];
	int  override;
	uint32_t  sampling_period_ms;
	int  set_point;
	int  set_point_clr;
	int  time_constant;
	int  device_mtgn_max_limit;
	int  device_perf_floor;
};

struct tb_setting {
	char           sensor[MAX_SENSOR_NAME_LEN];
	char           device[DEVICES_MAX_NAME_LEN];
	int            override;
	uint32_t       sampling_period_ms;
	int            set_point;
	int            set_point_clr;
	int            time_constant;
	float          up_loop_gain;
	float          down_loop_gain;
	float          auto_penalty;
	float          auto_reward;
	float          temp_scale_factor;
	float          freq_scale_factor;
	int            quadratic_reward;
	int            quadratic_penalty;
	int            use_timeout;
	int            timeout;
	int            unified_rail;
};

struct equilibrium_setting {
	char   **sensor_list;
	uint8_t  list_cnt;
	uint8_t  list_size;
	#ifdef ENABLE_OLD_PARSER
	char    *sensor;
	#else
	char     sensor[MAX_SENSOR_NAME_LEN];
	#endif
	uint32_t sensor_delta;
	uint32_t sampling_period_ms;
	uint32_t temp_range;
	int      max_temp;
	int      offset;
	uint32_t      long_sampling_period_ms;
	uint32_t      long_sampling_cnt;
	uint32_t      long_sample_range;
	uint32_t      pre_cal_delay_ms;
	uint32_t      sampling_list[INTEGERS_MAX];
	uint32_t      temp_range_list[INTEGERS_MAX];
};

enum math_type {
	MATH_WEIGHT = 0,
	MATH_MIN = 1,
	MATH_MAX = 2,
	MATH_SUM = 3
};

struct virtual_setting {
	char **trip_sensor_list;
	uint8_t trip_cnt;
	uint8_t logic_cnt;
	char **trip_sensor_logic;
	char **sensor_list;
	/* Keeps track of number of sensors in sensor_list */
	uint8_t list_cnt;
	/* Keeps track of number of allocated sensors in sensor_list */
	uint8_t list_size;
	uint32_t  num_thresholds;
	uint32_t descending_thresh;
	uint32_t tracks_low;
	struct  threshold_t t[THRESHOLDS_MAX];
	uint32_t sampling_period_ms;
	int *weight_list;
	uint32_t weight_cnt;
	uint32_t weight_size;
	enum math_type math_type;
	uint32_t trip_equal_logic;
	uint32_t trip_always_mon;
};

struct step_wise_setting {
	int step_zone_num;
};

union algo_data {
	struct pid_setting pid;
	struct tm_setting tm;
	struct ss_setting ss;
	struct tb_setting tb;
	struct equilibrium_setting eq;
	struct virtual_setting v;
	struct bwlm_setting bwlm;
	struct step_wise_setting step;
};

struct setting_info {
	char desc[MAX_ALGO_DESC];
	int algo_type;
	uint8_t disable;
	uint8_t err_disable;
	uint8_t dynamic;  /* dynamic != 0 if allocated using malloc. */
	struct setting_info *next;
	union algo_data data;
};

struct thermal_setting_t {
	uint32_t sample_period_ms;
	struct setting_info *list;
};

void init_settings(struct thermal_setting_t *settings);
#ifdef ENABLE_OLD_PARSER
int  load_config(struct thermal_setting_t *settings, const char *pFName);
#else
int  load_config(struct thermal_setting_t *settings, const char *pFName, int flag);
#endif
void add_setting(struct thermal_setting_t *settings, struct setting_info *info);
void print_setting(struct setting_info *setting);
void print_settings(struct thermal_setting_t *settings);

#endif  /* __THERMAL_CONFIG_H__ */
