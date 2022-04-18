/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                        D E V I C E _ M A N A G E M E N T _ S E R V I C E _ V 0 1  . C

GENERAL DESCRIPTION
  This is the file which defines the dms service Data structures.

  Copyright (c) 2006-2019 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.



  $Header$
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.9
   It was generated on: Thu Dec  5 2019 (Spin 0)
   From IDL File: device_management_service_v01.idl */

#include "stdint.h"
#include "qmi_idl_lib_internal.h"
#include "device_management_service_v01.h"
#include "common_v01.h"


/*Type Definitions*/
static const uint8_t dms_ims_capability_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_ims_capability_type_v01, subscription),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_ims_capability_type_v01, enabled),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_battery_lvl_limits_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_battery_lvl_limits_type_v01, battery_lvl_lower_limit),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_battery_lvl_limits_type_v01, battery_lvl_upper_limit),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_power_state_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_power_state_type_v01, power_status),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_power_state_type_v01, battery_lvl),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_pin_status_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_pin_status_type_v01, status),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_status_type_v01, verify_retries_left),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_status_type_v01, unblock_retries_left),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_sensor_policy_cond_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_policy_cond_v01, greater_value),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_policy_cond_v01, lower_value),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_policy_cond_v01, delta_value),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_sensor_policy_config_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_policy_config_v01, sensor_id),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_sensor_policy_config_v01, sensor_policy),
  QMI_DMS_SENSOR_CONFIG_MAX_V01,
  QMI_IDL_OFFSET8(dms_sensor_policy_config_v01, sensor_policy) - QMI_IDL_OFFSET8(dms_sensor_policy_config_v01, sensor_policy_len),
  QMI_IDL_TYPE88(0, 4),
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_policy_config_v01, sensor_batch_cnt),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_policy_config_v01, reporting_interval),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_sensor_sample_data_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_sample_data_v01, sensor_dimension_data),
  QMI_DMS_SENSOR_CONFIG_MAX_V01,
  QMI_IDL_OFFSET8(dms_sensor_sample_data_v01, sensor_dimension_data) - QMI_IDL_OFFSET8(dms_sensor_sample_data_v01, sensor_dimension_data_len),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_sample_data_v01, timestamp),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_sensor_info_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_info_v01, sensor_id),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_sensor_info_v01, sample_list),
  QMI_DMS_MAX_BATCH_SUPPORTED_V01,
  QMI_IDL_OFFSET8(dms_sensor_info_v01, sample_list) - QMI_IDL_OFFSET8(dms_sensor_info_v01, sample_list_len),
  QMI_IDL_TYPE88(0, 6),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_subs_config_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_subs_config_type_v01, max_active),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_subs_config_type_v01, subscription_list),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET8(dms_subs_config_type_v01, subscription_list) - QMI_IDL_OFFSET8(dms_subs_config_type_v01, subscription_list_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_multisim_capability_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_multisim_capability_type_v01, max_subscriptions),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_multisim_capability_type_v01, subscription_config_list),
  QMI_DMS_MAX_CONFIG_LIST_LEN_V01,
  QMI_IDL_OFFSET8(dms_multisim_capability_type_v01, subscription_config_list) - QMI_IDL_OFFSET8(dms_multisim_capability_type_v01, subscription_config_list_len),
  QMI_IDL_TYPE88(0, 8),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_subs_voice_data_capability_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_subs_voice_data_capability_type_v01, subs_voice_data_capability),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_subs_voice_data_capability_type_v01, simul_voice_data_capable),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_current_multisim_capability_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_current_multisim_capability_type_v01, max_subscriptions),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_current_multisim_capability_type_v01, max_active),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_prl_info_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_prl_info_type_v01, prl_version),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_prl_info_type_v01, prl_only),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_prl_info_type_v01, prl_source),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_device_config_list_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_device_config_list_type_v01, subs_cfg_list),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET8(dms_device_config_list_type_v01, subs_cfg_list) - QMI_IDL_OFFSET8(dms_device_config_list_type_v01, subs_cfg_list_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_device_config_capability_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_device_config_capability_type_v01, max_subscriptions),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_device_config_capability_type_v01, max_active),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_device_config_capability_type_v01, device_cfg_list),
  QMI_DMS_MAX_CONFIG_LIST_LEN_V01,
  QMI_IDL_OFFSET8(dms_device_config_capability_type_v01, device_cfg_list) - QMI_IDL_OFFSET8(dms_device_config_capability_type_v01, device_cfg_list_len),
  QMI_IDL_TYPE88(0, 13),
  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_device_config_capability_type_v01, current_config_index),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_device_capabilities_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_capabilities_type_v01, max_tx_channel_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_capabilities_type_v01, max_rx_channel_rate),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_device_capabilities_type_v01, data_service_capability),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_device_capabilities_type_v01, sim_capability),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_device_capabilities_type_v01, radio_if_list),
  QMI_DMS_RADIO_IF_LIST_MAX_V01,
  QMI_IDL_OFFSET8(dms_device_capabilities_type_v01, radio_if_list) - QMI_IDL_OFFSET8(dms_device_capabilities_type_v01, radio_if_list_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_device_rat_rel_info_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_rat_rel_info_v01, subscription),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_rat_rel_info_v01, geran_rel_info),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_rat_rel_info_v01, wcdma_rel_info),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_rat_rel_info_v01, lte_rel_info),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_rat_rel_info_v01, hdrcp_rel_info),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_rat_rel_info_v01, cdma1x_rel_info),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_rat_rel_info_v01, tdscdma_rel_info),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_pin_protection_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_pin_protection_info_type_v01, pin_id),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_protection_info_type_v01, protection_setting_enabled),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_protection_info_type_v01, pin_value),
  QMI_DMS_PIN_VALUE_MAX_V01,
  QMI_IDL_OFFSET8(dms_pin_protection_info_type_v01, pin_value) - QMI_IDL_OFFSET8(dms_pin_protection_info_type_v01, pin_value_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_pin_retries_status_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_retries_status_type_v01, verify_retries_left),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_retries_status_type_v01, unblock_retries_left),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_pin_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_pin_info_type_v01, pin_id),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_info_type_v01, pin_value),
  QMI_DMS_PIN_VALUE_MAX_V01,
  QMI_IDL_OFFSET8(dms_pin_info_type_v01, pin_value) - QMI_IDL_OFFSET8(dms_pin_info_type_v01, pin_value_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_pin_unblock_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_pin_unblock_info_type_v01, unblock_pin_id),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_unblock_info_type_v01, puk_value),
  QMI_DMS_PUK_VALUE_MAX_V01,
  QMI_IDL_OFFSET8(dms_pin_unblock_info_type_v01, puk_value) - QMI_IDL_OFFSET8(dms_pin_unblock_info_type_v01, puk_value_len),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_unblock_info_type_v01, new_pin_value),
  QMI_DMS_PUK_VALUE_MAX_V01,
  QMI_IDL_OFFSET8(dms_pin_unblock_info_type_v01, new_pin_value) - QMI_IDL_OFFSET8(dms_pin_unblock_info_type_v01, new_pin_value_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_pin_change_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_pin_change_info_type_v01, pin_id),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_change_info_type_v01, old_pin_value),
  QMI_DMS_PIN_VALUE_MAX_V01,
  QMI_IDL_OFFSET8(dms_pin_change_info_type_v01, old_pin_value) - QMI_IDL_OFFSET8(dms_pin_change_info_type_v01, old_pin_value_len),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pin_change_info_type_v01, new_pin_value),
  QMI_DMS_PIN_VALUE_MAX_V01,
  QMI_IDL_OFFSET8(dms_pin_change_info_type_v01, new_pin_value) - QMI_IDL_OFFSET8(dms_pin_change_info_type_v01, new_pin_value_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_device_time_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_device_time_type_v01, time_count),
  6,

  QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_device_time_type_v01, time_source),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_activation_code_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_activation_code_type_v01, act_code),
  QMI_DMS_ACTIVATION_CODE_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_manual_act_data_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_manual_act_data_type_v01, spc),
  QMI_DMS_SPC_LEN_V01,

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_manual_act_data_type_v01, sid),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_manual_act_data_type_v01, mdn),
  QMI_DMS_MDN_MAX_V01,

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_manual_act_data_type_v01, min),
  QMI_DMS_MIN_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_mn_ha_key_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_mn_ha_key_type_v01, mn_ha_key),
  QMI_DMS_HA_KEY_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_mn_aaa_key_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_mn_aaa_key_type_v01, mn_aaa_key),
  QMI_DMS_AAA_KEY_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_pref_roaming_list_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_pref_roaming_list_type_v01, prl_total_len),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_FLAGS_FIRST_EXTENDED |  QMI_IDL_FLAGS_SZ_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_FLAGS_ARRAY_LENGTH_ONLY,
  QMI_IDL_OFFSET8(dms_pref_roaming_list_type_v01, prl),
  ((QMI_DMS_PRL_DATA_MAX_V01) & 0xFF), ((QMI_DMS_PRL_DATA_MAX_V01) >> 8),
  QMI_IDL_OFFSET8(dms_pref_roaming_list_type_v01, prl) - QMI_IDL_OFFSET8(dms_pref_roaming_list_type_v01, prl_len),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_pref_roaming_list_type_v01, prl_seg_num),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_FLAGS_FIRST_EXTENDED |  QMI_IDL_FLAGS_SZ_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_FLAGS_ARRAY_DATA_ONLY,
  QMI_IDL_OFFSET8(dms_pref_roaming_list_type_v01, prl),
  ((QMI_DMS_PRL_DATA_MAX_V01) & 0xFF), ((QMI_DMS_PRL_DATA_MAX_V01) >> 8),
  QMI_IDL_OFFSET8(dms_pref_roaming_list_type_v01, prl) - QMI_IDL_OFFSET8(dms_pref_roaming_list_type_v01, prl_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_user_lock_state_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_user_lock_state_info_type_v01, lock_state),

  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_user_lock_state_info_type_v01, lock_code),
  QMI_DMS_LOCK_CODE_LEN_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_user_lock_set_info_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_user_lock_set_info_type_v01, cur_code),
  QMI_DMS_LOCK_CODE_LEN_V01,

  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_user_lock_set_info_type_v01, new_code),
  QMI_DMS_LOCK_CODE_LEN_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_user_data_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_user_data_type_v01, data),
  ((QMI_DMS_USER_DATA_MAX_V01) & 0xFF), ((QMI_DMS_USER_DATA_MAX_V01) >> 8),
  QMI_IDL_OFFSET8(dms_user_data_type_v01, data) - QMI_IDL_OFFSET8(dms_user_data_type_v01, data_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_eri_data_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_eri_data_type_v01, eri_data),
  ((QMI_DMS_ERI_DATA_MAX_V01) & 0xFF), ((QMI_DMS_ERI_DATA_MAX_V01) >> 8),
  QMI_IDL_OFFSET8(dms_eri_data_type_v01, eri_data) - QMI_IDL_OFFSET8(dms_eri_data_type_v01, eri_data_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_facility_state_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_facility_state_info_type_v01, facility_state),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_facility_state_info_type_v01, verify_reties_left),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_facility_state_info_type_v01, unblock_retries_left),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_facility_set_ck_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_facility_set_ck_info_type_v01, facility),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_facility_set_ck_info_type_v01, facility_state),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_facility_set_ck_info_type_v01, facility_ck),
  QMI_DMS_FACILITY_CK_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_facility_unblock_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_facility_unblock_info_type_v01, facility),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_facility_unblock_info_type_v01, facility_unblock_ck),
  QMI_DMS_FACILITY_UNBLOCK_CK_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t dms_image_ver_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_image_ver_type_v01, image_type),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_image_ver_type_v01, image_ver),
  QMI_DMS_IMAGE_VER_LEN_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t tx_mode_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(tx_mode_type_v01, tx_mode_level),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(tx_mode_type_v01, tx_mode_duration),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t modem_tech_active_time_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(modem_tech_active_time_type_v01, modem_power_tech),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(modem_tech_active_time_type_v01, modem_tech_active_time),

  QMI_IDL_FLAG_END_VALUE
};

/*Message Definitions*/
/*
 * dms_reset_req_msg is empty
 * static const uint8_t dms_reset_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_reset_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_reset_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_set_event_report_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_power_state) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_power_state_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_power_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, lvl_limits) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, lvl_limits_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, lvl_limits),
  QMI_IDL_TYPE88(0, 1),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_pin_state) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_pin_state_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_pin_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_activation_state) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_activation_state_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_activation_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_oprt_mode_state) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_oprt_mode_state_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_oprt_mode_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_uim_state) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_uim_state_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_uim_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_wireless_disable_state) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_wireless_disable_state_valid)),
  0x16,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_wireless_disable_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_prl_init) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_prl_init_valid)),
  0x17,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_prl_init),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_cdma_lock_mode) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_cdma_lock_mode_valid)),
  0x18,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_cdma_lock_mode),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_device_multisim_info) - QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_device_multisim_info_valid)),
  0x19,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_event_report_req_msg_v01, report_device_multisim_info)
};

static const uint8_t dms_set_event_report_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_event_report_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_event_report_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, power_state) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, power_state_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, power_state),
  QMI_IDL_TYPE88(0, 2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, pin1_status) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, pin1_status_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, pin1_status),
  QMI_IDL_TYPE88(0, 3),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, pin2_status) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, pin2_status_valid)),
  0x12,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, pin2_status),
  QMI_IDL_TYPE88(0, 3),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, activation_state) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, activation_state_valid)),
  0x13,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, activation_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, operating_mode) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, operating_mode_valid)),
  0x14,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, operating_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, uim_state) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, uim_state_valid)),
  0x15,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, uim_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, wireless_disable_state) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, wireless_disable_state_valid)),
  0x16,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, wireless_disable_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, prl_init) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, prl_init_valid)),
  0x17,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, prl_init),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, cdma_lock_mode_state) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, cdma_lock_mode_state_valid)),
  0x18,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, cdma_lock_mode_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, multisim_capability) - QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, multisim_capability_valid)),
  0x19,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_event_report_ind_msg_v01, multisim_capability),
  QMI_IDL_TYPE88(0, 9),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, current_multisim_capability) - QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, current_multisim_capability_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_event_report_ind_msg_v01, current_multisim_capability),
  QMI_IDL_TYPE88(0, 11),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, current_subscription_capability) - QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, current_subscription_capability_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_event_report_ind_msg_v01, current_subscription_capability),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, current_subscription_capability) - QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, current_subscription_capability_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, subs_voice_data_capability) - QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, subs_voice_data_capability_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_event_report_ind_msg_v01, subs_voice_data_capability),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, subs_voice_data_capability) - QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, subs_voice_data_capability_len),
  QMI_IDL_TYPE88(0, 10),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, max_active_data_subscriptions) - QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, max_active_data_subscriptions_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_event_report_ind_msg_v01, max_active_data_subscriptions),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, prl_info) - QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, prl_info_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_event_report_ind_msg_v01, prl_info),
  QMI_IDL_TYPE88(0, 12),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, device_config_list) - QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, device_config_list_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_event_report_ind_msg_v01, device_config_list),
  QMI_IDL_TYPE88(0, 14),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, explicit_config_index) - QMI_IDL_OFFSET16RELATIVE(dms_event_report_ind_msg_v01, explicit_config_index_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_event_report_ind_msg_v01, explicit_config_index)
};

static const uint8_t dms_indication_register_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_psm_status) - QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_psm_status_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_psm_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_psm_cfg_change) - QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_psm_cfg_change_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_psm_cfg_change),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_ims_capability) - QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_ims_capability_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_ims_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_sensor_status) - QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_sensor_status_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_sensor_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_power_cfg_reqs) - QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_power_cfg_reqs_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_power_cfg_reqs),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_interactive_state_reqs) - QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_interactive_state_reqs_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_indication_register_req_msg_v01, report_interactive_state_reqs)
};

static const uint8_t dms_indication_register_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_indication_register_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_device_cap_req_msg is empty
 * static const uint8_t dms_get_device_cap_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_device_cap_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, device_capabilities),
  QMI_IDL_TYPE88(0, 15),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, device_service_capability) - QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, device_service_capability_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, device_service_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, voice_support_capability) - QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, voice_support_capability_valid)),
  0x11,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, voice_support_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, simul_voice_and_data_capability) - QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, simul_voice_and_data_capability_valid)),
  0x12,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, simul_voice_and_data_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, multisim_capability) - QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, multisim_capability_valid)),
  0x13,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_device_cap_resp_msg_v01, multisim_capability),
  QMI_IDL_TYPE88(0, 9),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, current_multisim_capability) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, current_multisim_capability_valid)),
  0x14,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, current_multisim_capability),
  QMI_IDL_TYPE88(0, 11),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, current_subscription_capability) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, current_subscription_capability_valid)),
  0x15,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, current_subscription_capability),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, current_subscription_capability) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, current_subscription_capability_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, subs_voice_data_capability) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, subs_voice_data_capability_valid)),
  0x16,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, subs_voice_data_capability),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, subs_voice_data_capability) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, subs_voice_data_capability_len),
  QMI_IDL_TYPE88(0, 10),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, subs_device_feature_mode) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, subs_device_feature_mode_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, subs_device_feature_mode),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, subs_device_feature_mode) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, subs_device_feature_mode_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, max_active_data_subscriptions) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, max_active_data_subscriptions_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, max_active_data_subscriptions),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, device_max_subscription_static_capability) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, device_max_subscription_static_capability_valid)),
  0x19,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, device_max_subscription_static_capability),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, device_max_subscription_static_capability) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, device_max_subscription_static_capability_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, device_config_list) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, device_config_list_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, device_config_list),
  QMI_IDL_TYPE88(0, 14),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, explicit_config_index) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, explicit_config_index_valid)),
  0x1B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, explicit_config_index),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, ims_capability) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, ims_capability_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, ims_capability),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, ims_capability) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, ims_capability_len),
  QMI_IDL_TYPE88(0, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, max_ims_instances) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, max_ims_instances_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, max_ims_instances),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, rat_rel_info) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, rat_rel_info_valid)),
  0x1E,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_cap_resp_msg_v01, rat_rel_info),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, rat_rel_info) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_cap_resp_msg_v01, rat_rel_info_len),
  QMI_IDL_TYPE88(0, 16)
};

/*
 * dms_get_device_mfr_req_msg is empty
 * static const uint8_t dms_get_device_mfr_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_device_mfr_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_device_mfr_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_device_mfr_resp_msg_v01, device_manufacturer),
  QMI_DMS_DEVICE_MANUFACTURER_MAX_V01
};

/*
 * dms_get_device_model_id_req_msg is empty
 * static const uint8_t dms_get_device_model_id_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_device_model_id_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_model_id_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 |   QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_device_model_id_resp_msg_v01, device_model_id),
  ((QMI_DMS_DEVICE_MODEL_ID_MAX_V01) & 0xFF), ((QMI_DMS_DEVICE_MODEL_ID_MAX_V01) >> 8)
};

/*
 * dms_get_device_rev_id_req_msg is empty
 * static const uint8_t dms_get_device_rev_id_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_device_rev_id_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_rev_id_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 |   QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_device_rev_id_resp_msg_v01, device_rev_id),
  ((QMI_DMS_DEVICE_REV_ID_MAX_V01) & 0xFF), ((QMI_DMS_DEVICE_REV_ID_MAX_V01) >> 8),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_rev_id_resp_msg_v01, boot_code_rev) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_rev_id_resp_msg_v01, boot_code_rev_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_rev_id_resp_msg_v01, boot_code_rev),
  QMI_DMS_BOOT_CODE_REV_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_device_rev_id_resp_msg_v01, pri_rev) - QMI_IDL_OFFSET16RELATIVE(dms_get_device_rev_id_resp_msg_v01, pri_rev_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_rev_id_resp_msg_v01, pri_rev),
  QMI_DMS_PRI_REV_MAX_V01
};

/*
 * dms_get_msisdn_req_msg is empty
 * static const uint8_t dms_get_msisdn_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_msisdn_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_msisdn_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_msisdn_resp_msg_v01, voice_number),
  QMI_DMS_VOICE_NUMBER_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_msisdn_resp_msg_v01, mobile_id_number) - QMI_IDL_OFFSET8(dms_get_msisdn_resp_msg_v01, mobile_id_number_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_msisdn_resp_msg_v01, mobile_id_number),
  QMI_DMS_MOBILE_ID_NUMBER_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_msisdn_resp_msg_v01, imsi) - QMI_IDL_OFFSET8(dms_get_msisdn_resp_msg_v01, imsi_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_msisdn_resp_msg_v01, imsi),
  QMI_DMS_IMSI_MAX_V01
};

/*
 * dms_get_device_serial_numbers_req_msg is empty
 * static const uint8_t dms_get_device_serial_numbers_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_device_serial_numbers_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, esn) - QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, esn_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, esn),
  QMI_DMS_ESN_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, imei) - QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, imei_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, imei),
  QMI_DMS_IMEI_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, meid) - QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, meid_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, meid),
  QMI_DMS_MEID_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, imeisv_svn) - QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, imeisv_svn_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_device_serial_numbers_resp_msg_v01, imeisv_svn),
  QMI_DMS_IMEISV_MAX_V01
};

/*
 * dms_get_encrypted_device_serial_numbers_req_msg is empty
 * static const uint8_t dms_get_encrypted_device_serial_numbers_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_encrypted_device_serial_numbers_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_encrypted_device_serial_numbers_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_encrypted_device_serial_numbers_resp_msg_v01, esn) - QMI_IDL_OFFSET8(dms_get_encrypted_device_serial_numbers_resp_msg_v01, esn_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_FIRST_EXTENDED |   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_FLAGS_ARRAY_IS_LENGTHLESS |  QMI_IDL_FLAGS_ARRAY_IS_LENGTHLESS,
  QMI_IDL_OFFSET8(dms_get_encrypted_device_serial_numbers_resp_msg_v01, esn),
  QMI_DMS_ENCRYPTED_ESN_MAX_V01,
  QMI_IDL_OFFSET8(dms_get_encrypted_device_serial_numbers_resp_msg_v01, esn) - QMI_IDL_OFFSET8(dms_get_encrypted_device_serial_numbers_resp_msg_v01, esn_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imei) - QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imei_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_FIRST_EXTENDED |   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_FLAGS_ARRAY_IS_LENGTHLESS |  QMI_IDL_FLAGS_ARRAY_IS_LENGTHLESS,
  QMI_IDL_OFFSET16ARRAY(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imei),
  QMI_DMS_ENCRYPTED_IMEI_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imei) - QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imei_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, meid) - QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, meid_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_FIRST_EXTENDED |   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_FLAGS_ARRAY_IS_LENGTHLESS |  QMI_IDL_FLAGS_ARRAY_IS_LENGTHLESS,
  QMI_IDL_OFFSET16ARRAY(dms_get_encrypted_device_serial_numbers_resp_msg_v01, meid),
  QMI_DMS_ENCRYPTED_MEID_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, meid) - QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, meid_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imeisv_svn) - QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imeisv_svn_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_FIRST_EXTENDED |   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_FLAGS_ARRAY_IS_LENGTHLESS |  QMI_IDL_FLAGS_ARRAY_IS_LENGTHLESS,
  QMI_IDL_OFFSET16ARRAY(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imeisv_svn),
  QMI_DMS_ENCRYPTED_IMEISV_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imeisv_svn) - QMI_IDL_OFFSET16RELATIVE(dms_get_encrypted_device_serial_numbers_resp_msg_v01, imeisv_svn_len)
};

/*
 * dms_get_power_state_req_msg is empty
 * static const uint8_t dms_get_power_state_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_power_state_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_power_state_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_power_state_resp_msg_v01, power_state),
  QMI_IDL_TYPE88(0, 2)
};

static const uint8_t dms_uim_set_pin_protection_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_set_pin_protection_req_msg_v01, pin_protection_info),
  QMI_IDL_TYPE88(0, 17)
};

static const uint8_t dms_uim_set_pin_protection_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_set_pin_protection_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_uim_set_pin_protection_resp_msg_v01, pin_retries_status) - QMI_IDL_OFFSET8(dms_uim_set_pin_protection_resp_msg_v01, pin_retries_status_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_set_pin_protection_resp_msg_v01, pin_retries_status),
  QMI_IDL_TYPE88(0, 18)
};

static const uint8_t dms_uim_verify_pin_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_verify_pin_req_msg_v01, pin_info),
  QMI_IDL_TYPE88(0, 19)
};

static const uint8_t dms_uim_verify_pin_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_verify_pin_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_uim_verify_pin_resp_msg_v01, pin_retries_status) - QMI_IDL_OFFSET8(dms_uim_verify_pin_resp_msg_v01, pin_retries_status_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_verify_pin_resp_msg_v01, pin_retries_status),
  QMI_IDL_TYPE88(0, 18)
};

static const uint8_t dms_uim_unblock_pin_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_unblock_pin_req_msg_v01, pin_unblock_info),
  QMI_IDL_TYPE88(0, 20)
};

static const uint8_t dms_uim_unblock_pin_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_unblock_pin_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_uim_unblock_pin_resp_msg_v01, pin_retries_status) - QMI_IDL_OFFSET8(dms_uim_unblock_pin_resp_msg_v01, pin_retries_status_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_unblock_pin_resp_msg_v01, pin_retries_status),
  QMI_IDL_TYPE88(0, 18)
};

static const uint8_t dms_uim_change_pin_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_change_pin_req_msg_v01, pin_change_info),
  QMI_IDL_TYPE88(0, 21)
};

static const uint8_t dms_uim_change_pin_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_change_pin_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_uim_change_pin_resp_msg_v01, pin_retries_status) - QMI_IDL_OFFSET8(dms_uim_change_pin_resp_msg_v01, pin_retries_status_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_change_pin_resp_msg_v01, pin_retries_status),
  QMI_IDL_TYPE88(0, 18)
};

/*
 * dms_uim_get_pin_status_req_msg is empty
 * static const uint8_t dms_uim_get_pin_status_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_uim_get_pin_status_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_get_pin_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_uim_get_pin_status_resp_msg_v01, pin1_status) - QMI_IDL_OFFSET8(dms_uim_get_pin_status_resp_msg_v01, pin1_status_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_get_pin_status_resp_msg_v01, pin1_status),
  QMI_IDL_TYPE88(0, 3),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_uim_get_pin_status_resp_msg_v01, pin2_status) - QMI_IDL_OFFSET8(dms_uim_get_pin_status_resp_msg_v01, pin2_status_valid)),
  0x12,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_get_pin_status_resp_msg_v01, pin2_status),
  QMI_IDL_TYPE88(0, 3)
};

/*
 * dms_get_device_hardware_rev_req_msg is empty
 * static const uint8_t dms_get_device_hardware_rev_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_device_hardware_rev_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_get_device_hardware_rev_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 |   QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_device_hardware_rev_resp_msg_v01, hardware_rev),
  ((QMI_DMS_HARDWARE_REV_MAX_V01) & 0xFF), ((QMI_DMS_HARDWARE_REV_MAX_V01) >> 8)
};

/*
 * dms_get_operating_mode_req_msg is empty
 * static const uint8_t dms_get_operating_mode_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_operating_mode_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_operating_mode_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_get_operating_mode_resp_msg_v01, operating_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_operating_mode_resp_msg_v01, offline_reason) - QMI_IDL_OFFSET8(dms_get_operating_mode_resp_msg_v01, offline_reason_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_get_operating_mode_resp_msg_v01, offline_reason),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_operating_mode_resp_msg_v01, hardware_controlled_mode) - QMI_IDL_OFFSET8(dms_get_operating_mode_resp_msg_v01, hardware_controlled_mode_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_get_operating_mode_resp_msg_v01, hardware_controlled_mode)
};

static const uint8_t dms_set_operating_mode_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_set_operating_mode_req_msg_v01, operating_mode)
};

static const uint8_t dms_set_operating_mode_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_operating_mode_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_time_req_msg is empty
 * static const uint8_t dms_get_time_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_time_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_time_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_time_resp_msg_v01, device_time),
  QMI_IDL_TYPE88(0, 22),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_time_resp_msg_v01, sys_time_in_ms) - QMI_IDL_OFFSET8(dms_get_time_resp_msg_v01, sys_time_in_ms_valid)),
  0x10,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_get_time_resp_msg_v01, sys_time_in_ms),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_time_resp_msg_v01, user_time_in_ms) - QMI_IDL_OFFSET8(dms_get_time_resp_msg_v01, user_time_in_ms_valid)),
  0x11,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_get_time_resp_msg_v01, user_time_in_ms)
};

/*
 * dms_get_prl_ver_req_msg is empty
 * static const uint8_t dms_get_prl_ver_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_prl_ver_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_prl_ver_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_get_prl_ver_resp_msg_v01, prl_version),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_prl_ver_resp_msg_v01, prl_only) - QMI_IDL_OFFSET8(dms_get_prl_ver_resp_msg_v01, prl_only_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_get_prl_ver_resp_msg_v01, prl_only)
};

/*
 * dms_get_activation_state_req_msg is empty
 * static const uint8_t dms_get_activation_state_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_activation_state_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_activation_state_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_get_activation_state_resp_msg_v01, activation_state)
};

static const uint8_t dms_activate_automatic_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_activate_automatic_req_msg_v01, activation_code),
  QMI_IDL_TYPE88(0, 23)
};

static const uint8_t dms_activate_automatic_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_activate_automatic_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_activate_manual_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, activation_data),
  QMI_IDL_TYPE88(0, 24),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, mn_ha_key) - QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, mn_ha_key_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, mn_ha_key),
  QMI_IDL_TYPE88(0, 25),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, mn_aaa_key) - QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, mn_aaa_key_valid)),
  0x12,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, mn_aaa_key),
  QMI_IDL_TYPE88(0, 26),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, pref_roaming_list) - QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, pref_roaming_list_valid)),
  0x13,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_activate_manual_req_msg_v01, pref_roaming_list),
  QMI_IDL_TYPE88(0, 27)
};

static const uint8_t dms_activate_manual_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_activate_manual_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_user_lock_state_req_msg is empty
 * static const uint8_t dms_get_user_lock_state_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_user_lock_state_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_user_lock_state_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_get_user_lock_state_resp_msg_v01, lock_enabled)
};

static const uint8_t dms_set_user_lock_state_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_user_lock_state_req_msg_v01, lock_info),
  QMI_IDL_TYPE88(0, 28)
};

static const uint8_t dms_set_user_lock_state_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_user_lock_state_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_set_user_lock_code_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_user_lock_code_req_msg_v01, lock_info),
  QMI_IDL_TYPE88(0, 29)
};

static const uint8_t dms_set_user_lock_code_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_user_lock_code_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_read_user_data_req_msg is empty
 * static const uint8_t dms_read_user_data_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_read_user_data_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_read_user_data_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_read_user_data_resp_msg_v01, user_data),
  QMI_IDL_TYPE88(0, 30)
};

static const uint8_t dms_write_user_data_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_write_user_data_req_msg_v01, user_data),
  QMI_IDL_TYPE88(0, 30)
};

static const uint8_t dms_write_user_data_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_write_user_data_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_read_eri_file_req_msg is empty
 * static const uint8_t dms_read_eri_file_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_read_eri_file_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_read_eri_file_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_read_eri_file_resp_msg_v01, eri_file),
  QMI_IDL_TYPE88(0, 31)
};

static const uint8_t dms_restore_factory_defaults_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_restore_factory_defaults_req_msg_v01, spc),
  QMI_DMS_SPC_LEN_V01
};

static const uint8_t dms_restore_factory_defaults_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_restore_factory_defaults_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_validate_service_programming_code_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_validate_service_programming_code_req_msg_v01, spc),
  QMI_DMS_SPC_LEN_V01
};

static const uint8_t dms_validate_service_programming_code_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_validate_service_programming_code_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_uim_get_iccid_req_msg is empty
 * static const uint8_t dms_uim_get_iccid_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_uim_get_iccid_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_get_iccid_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_uim_get_iccid_resp_msg_v01, uim_id),
  QMI_DMS_UIM_ID_MAX_V01
};

static const uint8_t dms_uim_get_ck_status_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_uim_get_ck_status_req_msg_v01, facility)
};

static const uint8_t dms_uim_get_ck_status_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_get_ck_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_get_ck_status_resp_msg_v01, facility_info),
  QMI_IDL_TYPE88(0, 32),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_uim_get_ck_status_resp_msg_v01, operation_blocking) - QMI_IDL_OFFSET8(dms_uim_get_ck_status_resp_msg_v01, operation_blocking_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_uim_get_ck_status_resp_msg_v01, operation_blocking)
};

static const uint8_t dms_uim_set_ck_protection_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_set_ck_protection_req_msg_v01, facility_set_ck_info),
  QMI_IDL_TYPE88(0, 33)
};

static const uint8_t dms_uim_set_ck_protection_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_set_ck_protection_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_uim_set_ck_protection_resp_msg_v01, verify_retries_left) - QMI_IDL_OFFSET8(dms_uim_set_ck_protection_resp_msg_v01, verify_retries_left_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_uim_set_ck_protection_resp_msg_v01, verify_retries_left)
};

static const uint8_t dms_uim_unblock_ck_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_unblock_ck_req_msg_v01, facility_unblock_info),
  QMI_IDL_TYPE88(0, 34)
};

static const uint8_t dms_uim_unblock_ck_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_unblock_ck_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_uim_unblock_ck_resp_msg_v01, unblock_retries_left) - QMI_IDL_OFFSET8(dms_uim_unblock_ck_resp_msg_v01, unblock_retries_left_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_uim_unblock_ck_resp_msg_v01, unblock_retries_left)
};

/*
 * dms_uim_get_imsi_req_msg is empty
 * static const uint8_t dms_uim_get_imsi_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_uim_get_imsi_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_get_imsi_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_uim_get_imsi_resp_msg_v01, imsi),
  QMI_DMS_IMSI_MAX_V01
};

/*
 * dms_uim_get_state_req_msg is empty
 * static const uint8_t dms_uim_get_state_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_uim_get_state_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_uim_get_state_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(dms_uim_get_state_resp_msg_v01, uim_state)
};

/*
 * dms_get_band_capability_req_msg is empty
 * static const uint8_t dms_get_band_capability_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_band_capability_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, band_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, lte_band_capability) - QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, lte_band_capability_valid)),
  0x10,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, lte_band_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, tds_band_capability) - QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, tds_band_capability_valid)),
  0x11,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, tds_band_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, supported_lte_bands) - QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, supported_lte_bands_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 |   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, supported_lte_bands),
  ((QMI_DMS_MAX_SUPPORTED_LTE_BANDS_V01) & 0xFF), ((QMI_DMS_MAX_SUPPORTED_LTE_BANDS_V01) >> 8),
  QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, supported_lte_bands) - QMI_IDL_OFFSET8(dms_get_band_capability_resp_msg_v01, supported_lte_bands_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_band_capability_resp_msg_v01, supported_nr5g_bands) - QMI_IDL_OFFSET16RELATIVE(dms_get_band_capability_resp_msg_v01, supported_nr5g_bands_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 |   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_get_band_capability_resp_msg_v01, supported_nr5g_bands),
  ((QMI_DMS_MAX_SUPPORTED_NR5G_BANDS_V01) & 0xFF), ((QMI_DMS_MAX_SUPPORTED_NR5G_BANDS_V01) >> 8),
  QMI_IDL_OFFSET16RELATIVE(dms_get_band_capability_resp_msg_v01, supported_nr5g_bands) - QMI_IDL_OFFSET16RELATIVE(dms_get_band_capability_resp_msg_v01, supported_nr5g_bands_len)
};

/*
 * dms_get_factory_sku_req_msg is empty
 * static const uint8_t dms_get_factory_sku_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_factory_sku_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_factory_sku_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_factory_sku_resp_msg_v01, factory_serial_number),
  QMI_DMS_FACTORY_SN_MAX_V01
};

static const uint8_t dms_set_time_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_set_time_req_msg_v01, time_in_ms),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_time_req_msg_v01, time_reference_type) - QMI_IDL_OFFSET8(dms_set_time_req_msg_v01, time_reference_type_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_set_time_req_msg_v01, time_reference_type)
};

static const uint8_t dms_set_time_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_time_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_alt_net_config_req_msg is empty
 * static const uint8_t dms_get_alt_net_config_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_alt_net_config_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_alt_net_config_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_get_alt_net_config_resp_msg_v01, alt_net_config)
};

static const uint8_t dms_set_alt_net_config_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_alt_net_config_req_msg_v01, alt_net_config)
};

static const uint8_t dms_set_alt_net_config_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_alt_net_config_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_sw_version_req_msg is empty
 * static const uint8_t dms_get_sw_version_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_sw_version_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_sw_version_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_get_sw_version_resp_msg_v01, sw_version),
  QMI_DMS_SW_VERSION_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_sw_version_resp_msg_v01, image_versions) - QMI_IDL_OFFSET8(dms_get_sw_version_resp_msg_v01, image_versions_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_sw_version_resp_msg_v01, image_versions),
  QMI_DMS_IMAGE_VER_MAX_V01,
  QMI_IDL_OFFSET8(dms_get_sw_version_resp_msg_v01, image_versions) - QMI_IDL_OFFSET8(dms_get_sw_version_resp_msg_v01, image_versions_len),
  QMI_IDL_TYPE88(0, 35),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_sw_version_resp_msg_v01, sw_version_ext) - QMI_IDL_OFFSET16RELATIVE(dms_get_sw_version_resp_msg_v01, sw_version_ext_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(dms_get_sw_version_resp_msg_v01, sw_version_ext),
  QMI_DMS_SW_VERSION_MAX_EXT_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_get_sw_version_resp_msg_v01, secondary_sw_version) - QMI_IDL_OFFSET16RELATIVE(dms_get_sw_version_resp_msg_v01, secondary_sw_version_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(dms_get_sw_version_resp_msg_v01, secondary_sw_version),
  QMI_DMS_SW_VERSION_MAX_EXT_V01
};

static const uint8_t dms_set_spc_req_msg_data_v01[] = {
  0x01,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_spc_req_msg_v01, curr_spc),
  QMI_DMS_SPC_LEN_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_spc_req_msg_v01, new_spc),
  QMI_DMS_SPC_LEN_V01
};

static const uint8_t dms_set_spc_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_spc_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_current_prl_info_req_msg is empty
 * static const uint8_t dms_get_current_prl_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_current_prl_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, prl_version) - QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, prl_version_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, prl_version),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, prl_only) - QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, prl_only_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, prl_only),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, prl_source) - QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, prl_source_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_get_current_prl_info_resp_msg_v01, prl_source)
};

static const uint8_t dms_bind_subscription_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_bind_subscription_req_msg_v01, bind_subs)
};

static const uint8_t dms_bind_subscription_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_bind_subscription_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_bind_subscription_req_msg is empty
 * static const uint8_t dms_get_bind_subscription_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_bind_subscription_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_bind_subscription_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_bind_subscription_resp_msg_v01, bind_subscription) - QMI_IDL_OFFSET8(dms_get_bind_subscription_resp_msg_v01, bind_subscription_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_get_bind_subscription_resp_msg_v01, bind_subscription)
};

static const uint8_t dms_set_ap_sw_version_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_set_ap_sw_version_req_msg_v01, ap_sw_version),
  QMI_DMS_SW_VERSION_MAX_V01
};

static const uint8_t dms_set_ap_sw_version_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_ap_sw_version_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_cdma_lock_mode_req_msg is empty
 * static const uint8_t dms_get_cdma_lock_mode_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_cdma_lock_mode_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_cdma_lock_mode_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_cdma_lock_mode_resp_msg_v01, cdma_lock_mode_status) - QMI_IDL_OFFSET8(dms_get_cdma_lock_mode_resp_msg_v01, cdma_lock_mode_status_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_get_cdma_lock_mode_resp_msg_v01, cdma_lock_mode_status)
};

static const uint8_t dms_set_test_config_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_test_config_req_msg_v01, tds_config) - QMI_IDL_OFFSET8(dms_set_test_config_req_msg_v01, tds_config_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_set_test_config_req_msg_v01, tds_config)
};

static const uint8_t dms_set_test_config_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_test_config_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_test_config_req_msg is empty
 * static const uint8_t dms_get_test_config_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_test_config_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_test_config_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_test_config_resp_msg_v01, active_tds_config) - QMI_IDL_OFFSET8(dms_get_test_config_resp_msg_v01, active_tds_config_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_get_test_config_resp_msg_v01, active_tds_config),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_test_config_resp_msg_v01, desired_tds_config) - QMI_IDL_OFFSET8(dms_get_test_config_resp_msg_v01, desired_tds_config_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_get_test_config_resp_msg_v01, desired_tds_config)
};

/*
 * dms_clear_test_config_req_msg is empty
 * static const uint8_t dms_clear_test_config_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_clear_test_config_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_clear_test_config_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_oem_china_operator_req_msg is empty
 * static const uint8_t dms_oem_china_operator_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_oem_china_operator_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_oem_china_operator_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_oem_china_operator_resp_msg_v01, operator_info) - QMI_IDL_OFFSET8(dms_oem_china_operator_resp_msg_v01, operator_info_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_oem_china_operator_resp_msg_v01, operator_info)
};

static const uint8_t dms_get_mac_address_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_get_mac_address_req_msg_v01, device)
};

static const uint8_t dms_get_mac_address_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_mac_address_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_mac_address_resp_msg_v01, mac_address) - QMI_IDL_OFFSET8(dms_get_mac_address_resp_msg_v01, mac_address_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_get_mac_address_resp_msg_v01, mac_address),
  QMI_DMS_MAC_ADDR_MAX_V01,
  QMI_IDL_OFFSET8(dms_get_mac_address_resp_msg_v01, mac_address) - QMI_IDL_OFFSET8(dms_get_mac_address_resp_msg_v01, mac_address_len)
};

static const uint8_t dms_config_modem_activity_info_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_config_modem_activity_info_req_msg_v01, enable_statistics) - QMI_IDL_OFFSET8(dms_config_modem_activity_info_req_msg_v01, enable_statistics_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_config_modem_activity_info_req_msg_v01, enable_statistics)
};

static const uint8_t dms_config_modem_activity_info_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_config_modem_activity_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_modem_activity_info_req_msg is empty
 * static const uint8_t dms_get_modem_activity_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_modem_activity_info_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_modem_activity_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_activity_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, idle_mode_duration) - QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, idle_mode_duration_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, idle_mode_duration),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, sleep_mode_duration) - QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, sleep_mode_duration_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, sleep_mode_duration),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, rx_mode_duration) - QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, rx_mode_duration_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, rx_mode_duration),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, tx_mode_duration) - QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, tx_mode_duration_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, tx_mode_duration),
  QMI_DMS_TX_MODEM_LEVEL_MAX_V01,
  QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, tx_mode_duration) - QMI_IDL_OFFSET8(dms_activity_info_ind_msg_v01, tx_mode_duration_len),
  QMI_IDL_TYPE88(0, 36),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, is_newly_calculated_values) - QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, is_newly_calculated_values_valid)),
  0x14,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_activity_info_ind_msg_v01, is_newly_calculated_values),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, modem_tech_active_time) - QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, modem_tech_active_time_valid)),
  0x15,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(dms_activity_info_ind_msg_v01, modem_tech_active_time),
  QMI_DMS_NUM_RAT_TECH_V01,
  QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, modem_tech_active_time) - QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, modem_tech_active_time_len),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, wlan_active_time) - QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, wlan_active_time_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_activity_info_ind_msg_v01, wlan_active_time),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, gps_active_time) - QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, gps_active_time_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_activity_info_ind_msg_v01, gps_active_time),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, modem_active_vote_status) - QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, modem_active_vote_status_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_activity_info_ind_msg_v01, modem_active_vote_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, wlan_active_vote_status) - QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, wlan_active_vote_status_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_activity_info_ind_msg_v01, wlan_active_vote_status),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, gps_active_vote_status) - QMI_IDL_OFFSET16RELATIVE(dms_activity_info_ind_msg_v01, gps_active_vote_status_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(dms_activity_info_ind_msg_v01, gps_active_vote_status)
};

/*
 * dms_psm_get_cfg_params_req_msg is empty
 * static const uint8_t dms_psm_get_cfg_params_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_psm_get_cfg_params_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, psm_enabled) - QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, psm_enabled_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, psm_enabled),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, duration_threshold) - QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, duration_threshold_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, duration_threshold),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, duration_due_to_oos) - QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, duration_due_to_oos_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, duration_due_to_oos),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, randomization_window) - QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, randomization_window_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, randomization_window),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, active_timer) - QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, active_timer_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, active_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, periodic_update_timer) - QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, periodic_update_timer_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, periodic_update_timer),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, early_wakeup_time) - QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, early_wakeup_time_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_get_cfg_params_resp_msg_v01, early_wakeup_time)
};

static const uint8_t dms_psm_enter_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_enter_req_msg_v01, duration_in_psm) - QMI_IDL_OFFSET8(dms_psm_enter_req_msg_v01, duration_in_psm_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_enter_req_msg_v01, duration_in_psm),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_enter_req_msg_v01, status) - QMI_IDL_OFFSET8(dms_psm_enter_req_msg_v01, status_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_psm_enter_req_msg_v01, status)
};

static const uint8_t dms_psm_enter_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_psm_enter_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_psm_status_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_status_ind_msg_v01, psm_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_status_ind_msg_v01, reject_reason) - QMI_IDL_OFFSET8(dms_psm_status_ind_msg_v01, reject_reason_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_status_ind_msg_v01, reject_reason),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_status_ind_msg_v01, periodic_update_timer) - QMI_IDL_OFFSET8(dms_psm_status_ind_msg_v01, periodic_update_timer_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_status_ind_msg_v01, periodic_update_timer)
};

static const uint8_t dms_get_capability_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_capability_req_msg_v01, te_psm_capability) - QMI_IDL_OFFSET8(dms_get_capability_req_msg_v01, te_psm_capability_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_get_capability_req_msg_v01, te_psm_capability)
};

static const uint8_t dms_get_capability_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_capability_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_capability_resp_msg_v01, psm_capability) - QMI_IDL_OFFSET8(dms_get_capability_resp_msg_v01, psm_capability_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_get_capability_resp_msg_v01, psm_capability)
};

/*
 * dms_get_ui_status_info_req_msg is empty
 * static const uint8_t dms_get_ui_status_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_ui_status_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_ui_status_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_ui_status_info_resp_msg_v01, ui_ready_status) - QMI_IDL_OFFSET8(dms_get_ui_status_info_resp_msg_v01, ui_ready_status_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_get_ui_status_info_resp_msg_v01, ui_ready_status)
};

static const uint8_t dms_set_ui_status_info_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_ui_status_info_req_msg_v01, ui_ready_status) - QMI_IDL_OFFSET8(dms_set_ui_status_info_req_msg_v01, ui_ready_status_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_ui_status_info_req_msg_v01, ui_ready_status)
};

static const uint8_t dms_set_ui_status_info_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_ui_status_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_set_device_cap_config_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_device_cap_config_req_msg_v01, explicit_config_index) - QMI_IDL_OFFSET8(dms_set_device_cap_config_req_msg_v01, explicit_config_index_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_set_device_cap_config_req_msg_v01, explicit_config_index)
};

static const uint8_t dms_set_device_cap_config_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_device_cap_config_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_psm_set_cfg_params_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_set_cfg_params_req_msg_v01, psm_enabled) - QMI_IDL_OFFSET8(dms_psm_set_cfg_params_req_msg_v01, psm_enabled_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_psm_set_cfg_params_req_msg_v01, psm_enabled),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_set_cfg_params_req_msg_v01, active_timer) - QMI_IDL_OFFSET8(dms_psm_set_cfg_params_req_msg_v01, active_timer_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_set_cfg_params_req_msg_v01, active_timer),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_set_cfg_params_req_msg_v01, periodic_update_timer) - QMI_IDL_OFFSET8(dms_psm_set_cfg_params_req_msg_v01, periodic_update_timer_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_set_cfg_params_req_msg_v01, periodic_update_timer)
};

static const uint8_t dms_psm_set_cfg_params_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_psm_set_cfg_params_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_psm_cfg_params_change_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_cfg_params_change_ind_msg_v01, psm_enabled) - QMI_IDL_OFFSET8(dms_psm_cfg_params_change_ind_msg_v01, psm_enabled_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_psm_cfg_params_change_ind_msg_v01, psm_enabled),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_cfg_params_change_ind_msg_v01, active_timer) - QMI_IDL_OFFSET8(dms_psm_cfg_params_change_ind_msg_v01, active_timer_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_cfg_params_change_ind_msg_v01, active_timer),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_psm_cfg_params_change_ind_msg_v01, periodic_update_timer) - QMI_IDL_OFFSET8(dms_psm_cfg_params_change_ind_msg_v01, periodic_update_timer_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_psm_cfg_params_change_ind_msg_v01, periodic_update_timer)
};

static const uint8_t dms_ims_capability_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_ims_capability_ind_msg_v01, ims_capability),
  QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01,
  QMI_IDL_OFFSET8(dms_ims_capability_ind_msg_v01, ims_capability) - QMI_IDL_OFFSET8(dms_ims_capability_ind_msg_v01, ims_capability_len),
  QMI_IDL_TYPE88(0, 0)
};

static const uint8_t dms_set_ap_version_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, ap_os_version) - QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, ap_os_version_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, ap_os_version),
  QMI_DMS_AP_OS_VERSION_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, ap_sw_version) - QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, ap_sw_version_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, ap_sw_version),
  QMI_DMS_AP_SW_VERSION_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, ap_wlan_macid) - QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, ap_wlan_macid_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, ap_wlan_macid),
  QMI_DMS_AP_WLAN_MACID_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, sw_image_type) - QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, sw_image_type_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_set_ap_version_req_msg_v01, sw_image_type)
};

static const uint8_t dms_set_ap_version_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_ap_version_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_set_app_priority_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_set_app_priority_req_msg_v01, prioritized_app)
};

static const uint8_t dms_set_app_priority_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_app_priority_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_set_sensor_configuration_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_policy) - QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_policy_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_policy),
  QMI_DMS_SENSOR_CONFIG_MAX_V01,
  QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_policy) - QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_policy_len),
  QMI_IDL_TYPE88(0, 4),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_batch_cnt) - QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_batch_cnt_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_batch_cnt),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, reporting_interval) - QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, reporting_interval_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, reporting_interval),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_config_list) - QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_config_list_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_config_list),
  QMI_DMS_SENSOR_CONFIG_MAX_V01,
  QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_config_list) - QMI_IDL_OFFSET8(dms_set_sensor_configuration_req_msg_v01, sensor_config_list_len),
  QMI_IDL_TYPE88(0, 5)
};

static const uint8_t dms_set_sensor_configuration_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_set_sensor_configuration_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_get_sensor_data_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_get_sensor_data_req_msg_v01, sensor_id_mask)
};

static const uint8_t dms_get_sensor_data_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_sensor_data_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_sensor_data_resp_msg_v01, sensor_info) - QMI_IDL_OFFSET8(dms_get_sensor_data_resp_msg_v01, sensor_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_sensor_data_resp_msg_v01, sensor_info),
  QMI_DMS_SENSOR_TYPE_MAX_V01,
  QMI_IDL_OFFSET8(dms_get_sensor_data_resp_msg_v01, sensor_info) - QMI_IDL_OFFSET8(dms_get_sensor_data_resp_msg_v01, sensor_info_len),
  QMI_IDL_TYPE88(0, 7)
};

/*
 * dms_reset_sensor_config_data_req_msg is empty
 * static const uint8_t dms_reset_sensor_config_data_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_reset_sensor_config_data_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_reset_sensor_config_data_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * dms_get_last_policy_met_info_req_msg is empty
 * static const uint8_t dms_get_last_policy_met_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t dms_get_last_policy_met_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_get_last_policy_met_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_last_policy_met_info_resp_msg_v01, policy_met_sensor_mask) - QMI_IDL_OFFSET8(dms_get_last_policy_met_info_resp_msg_v01, policy_met_sensor_mask_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_get_last_policy_met_info_resp_msg_v01, policy_met_sensor_mask),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_get_last_policy_met_info_resp_msg_v01, batch_full_sensor_mask) - QMI_IDL_OFFSET8(dms_get_last_policy_met_info_resp_msg_v01, batch_full_sensor_mask_valid)),
  0x11,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_get_last_policy_met_info_resp_msg_v01, batch_full_sensor_mask)
};

static const uint8_t dms_sensor_policy_met_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_sensor_policy_met_ind_msg_v01, policy_met_sensor_mask) - QMI_IDL_OFFSET8(dms_sensor_policy_met_ind_msg_v01, policy_met_sensor_mask_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_policy_met_ind_msg_v01, policy_met_sensor_mask),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_sensor_policy_met_ind_msg_v01, batch_full_sensor_mask) - QMI_IDL_OFFSET8(dms_sensor_policy_met_ind_msg_v01, batch_full_sensor_mask_valid)),
  0x11,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(dms_sensor_policy_met_ind_msg_v01, batch_full_sensor_mask)
};

static const uint8_t dms_device_power_info_request_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_device_power_info_request_ind_msg_v01, report_power_status) - QMI_IDL_OFFSET8(dms_device_power_info_request_ind_msg_v01, report_power_status_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_device_power_info_request_ind_msg_v01, report_power_status),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_device_power_info_request_ind_msg_v01, battery_threshold_list) - QMI_IDL_OFFSET8(dms_device_power_info_request_ind_msg_v01, battery_threshold_list_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_device_power_info_request_ind_msg_v01, battery_threshold_list),
  QMI_DMS_MAX_BATTERY_LIST_LEN_V01,
  QMI_IDL_OFFSET8(dms_device_power_info_request_ind_msg_v01, battery_threshold_list) - QMI_IDL_OFFSET8(dms_device_power_info_request_ind_msg_v01, battery_threshold_list_len)
};

static const uint8_t dms_device_interactive_state_request_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_device_interactive_state_request_ind_msg_v01, report_device_interactive_state) - QMI_IDL_OFFSET8(dms_device_interactive_state_request_ind_msg_v01, report_device_interactive_state_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_device_interactive_state_request_ind_msg_v01, report_device_interactive_state)
};

static const uint8_t dms_device_power_info_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, power_save_mode_status) - QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, power_save_mode_status_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, power_save_mode_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_charge_state) - QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_charge_state_valid)),
  0x11,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_charge_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_capacity) - QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_capacity_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_capacity),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_level) - QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_level_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_level),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_level_index) - QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_level_index_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(dms_device_power_info_req_msg_v01, battery_level_index)
};

static const uint8_t dms_device_power_info_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_device_power_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t dms_device_interactive_state_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(dms_device_interactive_state_req_msg_v01, interactive_state)
};

static const uint8_t dms_device_interactive_state_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(dms_device_interactive_state_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/* Type Table */
static const qmi_idl_type_table_entry  dms_type_table_v01[] = {
  {sizeof(dms_ims_capability_type_v01), dms_ims_capability_type_data_v01},
  {sizeof(dms_battery_lvl_limits_type_v01), dms_battery_lvl_limits_type_data_v01},
  {sizeof(dms_power_state_type_v01), dms_power_state_type_data_v01},
  {sizeof(dms_pin_status_type_v01), dms_pin_status_type_data_v01},
  {sizeof(dms_sensor_policy_cond_v01), dms_sensor_policy_cond_data_v01},
  {sizeof(dms_sensor_policy_config_v01), dms_sensor_policy_config_data_v01},
  {sizeof(dms_sensor_sample_data_v01), dms_sensor_sample_data_data_v01},
  {sizeof(dms_sensor_info_v01), dms_sensor_info_data_v01},
  {sizeof(dms_subs_config_type_v01), dms_subs_config_type_data_v01},
  {sizeof(dms_multisim_capability_type_v01), dms_multisim_capability_type_data_v01},
  {sizeof(dms_subs_voice_data_capability_type_v01), dms_subs_voice_data_capability_type_data_v01},
  {sizeof(dms_current_multisim_capability_type_v01), dms_current_multisim_capability_type_data_v01},
  {sizeof(dms_prl_info_type_v01), dms_prl_info_type_data_v01},
  {sizeof(dms_device_config_list_type_v01), dms_device_config_list_type_data_v01},
  {sizeof(dms_device_config_capability_type_v01), dms_device_config_capability_type_data_v01},
  {sizeof(dms_device_capabilities_type_v01), dms_device_capabilities_type_data_v01},
  {sizeof(dms_device_rat_rel_info_v01), dms_device_rat_rel_info_data_v01},
  {sizeof(dms_pin_protection_info_type_v01), dms_pin_protection_info_type_data_v01},
  {sizeof(dms_pin_retries_status_type_v01), dms_pin_retries_status_type_data_v01},
  {sizeof(dms_pin_info_type_v01), dms_pin_info_type_data_v01},
  {sizeof(dms_pin_unblock_info_type_v01), dms_pin_unblock_info_type_data_v01},
  {sizeof(dms_pin_change_info_type_v01), dms_pin_change_info_type_data_v01},
  {sizeof(dms_device_time_type_v01), dms_device_time_type_data_v01},
  {sizeof(dms_activation_code_type_v01), dms_activation_code_type_data_v01},
  {sizeof(dms_manual_act_data_type_v01), dms_manual_act_data_type_data_v01},
  {sizeof(dms_mn_ha_key_type_v01), dms_mn_ha_key_type_data_v01},
  {sizeof(dms_mn_aaa_key_type_v01), dms_mn_aaa_key_type_data_v01},
  {sizeof(dms_pref_roaming_list_type_v01), dms_pref_roaming_list_type_data_v01},
  {sizeof(dms_user_lock_state_info_type_v01), dms_user_lock_state_info_type_data_v01},
  {sizeof(dms_user_lock_set_info_type_v01), dms_user_lock_set_info_type_data_v01},
  {sizeof(dms_user_data_type_v01), dms_user_data_type_data_v01},
  {sizeof(dms_eri_data_type_v01), dms_eri_data_type_data_v01},
  {sizeof(dms_facility_state_info_type_v01), dms_facility_state_info_type_data_v01},
  {sizeof(dms_facility_set_ck_info_type_v01), dms_facility_set_ck_info_type_data_v01},
  {sizeof(dms_facility_unblock_info_type_v01), dms_facility_unblock_info_type_data_v01},
  {sizeof(dms_image_ver_type_v01), dms_image_ver_type_data_v01},
  {sizeof(tx_mode_type_v01), tx_mode_type_data_v01},
  {sizeof(modem_tech_active_time_type_v01), modem_tech_active_time_type_data_v01}
};

/* Message Table */
static const qmi_idl_message_table_entry dms_message_table_v01[] = {
  {sizeof(dms_reset_req_msg_v01), 0},
  {sizeof(dms_reset_resp_msg_v01), dms_reset_resp_msg_data_v01},
  {sizeof(dms_set_event_report_req_msg_v01), dms_set_event_report_req_msg_data_v01},
  {sizeof(dms_set_event_report_resp_msg_v01), dms_set_event_report_resp_msg_data_v01},
  {sizeof(dms_event_report_ind_msg_v01), dms_event_report_ind_msg_data_v01},
  {sizeof(dms_indication_register_req_msg_v01), dms_indication_register_req_msg_data_v01},
  {sizeof(dms_indication_register_resp_msg_v01), dms_indication_register_resp_msg_data_v01},
  {sizeof(dms_get_device_cap_req_msg_v01), 0},
  {sizeof(dms_get_device_cap_resp_msg_v01), dms_get_device_cap_resp_msg_data_v01},
  {sizeof(dms_get_device_mfr_req_msg_v01), 0},
  {sizeof(dms_get_device_mfr_resp_msg_v01), dms_get_device_mfr_resp_msg_data_v01},
  {sizeof(dms_get_device_model_id_req_msg_v01), 0},
  {sizeof(dms_get_device_model_id_resp_msg_v01), dms_get_device_model_id_resp_msg_data_v01},
  {sizeof(dms_get_device_rev_id_req_msg_v01), 0},
  {sizeof(dms_get_device_rev_id_resp_msg_v01), dms_get_device_rev_id_resp_msg_data_v01},
  {sizeof(dms_get_msisdn_req_msg_v01), 0},
  {sizeof(dms_get_msisdn_resp_msg_v01), dms_get_msisdn_resp_msg_data_v01},
  {sizeof(dms_get_device_serial_numbers_req_msg_v01), 0},
  {sizeof(dms_get_device_serial_numbers_resp_msg_v01), dms_get_device_serial_numbers_resp_msg_data_v01},
  {sizeof(dms_get_encrypted_device_serial_numbers_req_msg_v01), 0},
  {sizeof(dms_get_encrypted_device_serial_numbers_resp_msg_v01), dms_get_encrypted_device_serial_numbers_resp_msg_data_v01},
  {sizeof(dms_get_power_state_req_msg_v01), 0},
  {sizeof(dms_get_power_state_resp_msg_v01), dms_get_power_state_resp_msg_data_v01},
  {sizeof(dms_uim_set_pin_protection_req_msg_v01), dms_uim_set_pin_protection_req_msg_data_v01},
  {sizeof(dms_uim_set_pin_protection_resp_msg_v01), dms_uim_set_pin_protection_resp_msg_data_v01},
  {sizeof(dms_uim_verify_pin_req_msg_v01), dms_uim_verify_pin_req_msg_data_v01},
  {sizeof(dms_uim_verify_pin_resp_msg_v01), dms_uim_verify_pin_resp_msg_data_v01},
  {sizeof(dms_uim_unblock_pin_req_msg_v01), dms_uim_unblock_pin_req_msg_data_v01},
  {sizeof(dms_uim_unblock_pin_resp_msg_v01), dms_uim_unblock_pin_resp_msg_data_v01},
  {sizeof(dms_uim_change_pin_req_msg_v01), dms_uim_change_pin_req_msg_data_v01},
  {sizeof(dms_uim_change_pin_resp_msg_v01), dms_uim_change_pin_resp_msg_data_v01},
  {sizeof(dms_uim_get_pin_status_req_msg_v01), 0},
  {sizeof(dms_uim_get_pin_status_resp_msg_v01), dms_uim_get_pin_status_resp_msg_data_v01},
  {sizeof(dms_get_device_hardware_rev_req_msg_v01), 0},
  {sizeof(dms_get_device_hardware_rev_resp_msg_v01), dms_get_device_hardware_rev_resp_msg_data_v01},
  {sizeof(dms_get_operating_mode_req_msg_v01), 0},
  {sizeof(dms_get_operating_mode_resp_msg_v01), dms_get_operating_mode_resp_msg_data_v01},
  {sizeof(dms_set_operating_mode_req_msg_v01), dms_set_operating_mode_req_msg_data_v01},
  {sizeof(dms_set_operating_mode_resp_msg_v01), dms_set_operating_mode_resp_msg_data_v01},
  {sizeof(dms_get_time_req_msg_v01), 0},
  {sizeof(dms_get_time_resp_msg_v01), dms_get_time_resp_msg_data_v01},
  {sizeof(dms_get_prl_ver_req_msg_v01), 0},
  {sizeof(dms_get_prl_ver_resp_msg_v01), dms_get_prl_ver_resp_msg_data_v01},
  {sizeof(dms_get_activation_state_req_msg_v01), 0},
  {sizeof(dms_get_activation_state_resp_msg_v01), dms_get_activation_state_resp_msg_data_v01},
  {sizeof(dms_activate_automatic_req_msg_v01), dms_activate_automatic_req_msg_data_v01},
  {sizeof(dms_activate_automatic_resp_msg_v01), dms_activate_automatic_resp_msg_data_v01},
  {sizeof(dms_activate_manual_req_msg_v01), dms_activate_manual_req_msg_data_v01},
  {sizeof(dms_activate_manual_resp_msg_v01), dms_activate_manual_resp_msg_data_v01},
  {sizeof(dms_get_user_lock_state_req_msg_v01), 0},
  {sizeof(dms_get_user_lock_state_resp_msg_v01), dms_get_user_lock_state_resp_msg_data_v01},
  {sizeof(dms_set_user_lock_state_req_msg_v01), dms_set_user_lock_state_req_msg_data_v01},
  {sizeof(dms_set_user_lock_state_resp_msg_v01), dms_set_user_lock_state_resp_msg_data_v01},
  {sizeof(dms_set_user_lock_code_req_msg_v01), dms_set_user_lock_code_req_msg_data_v01},
  {sizeof(dms_set_user_lock_code_resp_msg_v01), dms_set_user_lock_code_resp_msg_data_v01},
  {sizeof(dms_read_user_data_req_msg_v01), 0},
  {sizeof(dms_read_user_data_resp_msg_v01), dms_read_user_data_resp_msg_data_v01},
  {sizeof(dms_write_user_data_req_msg_v01), dms_write_user_data_req_msg_data_v01},
  {sizeof(dms_write_user_data_resp_msg_v01), dms_write_user_data_resp_msg_data_v01},
  {sizeof(dms_read_eri_file_req_msg_v01), 0},
  {sizeof(dms_read_eri_file_resp_msg_v01), dms_read_eri_file_resp_msg_data_v01},
  {sizeof(dms_restore_factory_defaults_req_msg_v01), dms_restore_factory_defaults_req_msg_data_v01},
  {sizeof(dms_restore_factory_defaults_resp_msg_v01), dms_restore_factory_defaults_resp_msg_data_v01},
  {sizeof(dms_validate_service_programming_code_req_msg_v01), dms_validate_service_programming_code_req_msg_data_v01},
  {sizeof(dms_validate_service_programming_code_resp_msg_v01), dms_validate_service_programming_code_resp_msg_data_v01},
  {sizeof(dms_uim_get_iccid_req_msg_v01), 0},
  {sizeof(dms_uim_get_iccid_resp_msg_v01), dms_uim_get_iccid_resp_msg_data_v01},
  {sizeof(dms_uim_get_ck_status_req_msg_v01), dms_uim_get_ck_status_req_msg_data_v01},
  {sizeof(dms_uim_get_ck_status_resp_msg_v01), dms_uim_get_ck_status_resp_msg_data_v01},
  {sizeof(dms_uim_set_ck_protection_req_msg_v01), dms_uim_set_ck_protection_req_msg_data_v01},
  {sizeof(dms_uim_set_ck_protection_resp_msg_v01), dms_uim_set_ck_protection_resp_msg_data_v01},
  {sizeof(dms_uim_unblock_ck_req_msg_v01), dms_uim_unblock_ck_req_msg_data_v01},
  {sizeof(dms_uim_unblock_ck_resp_msg_v01), dms_uim_unblock_ck_resp_msg_data_v01},
  {sizeof(dms_uim_get_imsi_req_msg_v01), 0},
  {sizeof(dms_uim_get_imsi_resp_msg_v01), dms_uim_get_imsi_resp_msg_data_v01},
  {sizeof(dms_uim_get_state_req_msg_v01), 0},
  {sizeof(dms_uim_get_state_resp_msg_v01), dms_uim_get_state_resp_msg_data_v01},
  {sizeof(dms_get_band_capability_req_msg_v01), 0},
  {sizeof(dms_get_band_capability_resp_msg_v01), dms_get_band_capability_resp_msg_data_v01},
  {sizeof(dms_get_factory_sku_req_msg_v01), 0},
  {sizeof(dms_get_factory_sku_resp_msg_v01), dms_get_factory_sku_resp_msg_data_v01},
  {sizeof(dms_set_time_req_msg_v01), dms_set_time_req_msg_data_v01},
  {sizeof(dms_set_time_resp_msg_v01), dms_set_time_resp_msg_data_v01},
  {sizeof(dms_get_alt_net_config_req_msg_v01), 0},
  {sizeof(dms_get_alt_net_config_resp_msg_v01), dms_get_alt_net_config_resp_msg_data_v01},
  {sizeof(dms_set_alt_net_config_req_msg_v01), dms_set_alt_net_config_req_msg_data_v01},
  {sizeof(dms_set_alt_net_config_resp_msg_v01), dms_set_alt_net_config_resp_msg_data_v01},
  {sizeof(dms_get_sw_version_req_msg_v01), 0},
  {sizeof(dms_get_sw_version_resp_msg_v01), dms_get_sw_version_resp_msg_data_v01},
  {sizeof(dms_set_spc_req_msg_v01), dms_set_spc_req_msg_data_v01},
  {sizeof(dms_set_spc_resp_msg_v01), dms_set_spc_resp_msg_data_v01},
  {sizeof(dms_get_current_prl_info_req_msg_v01), 0},
  {sizeof(dms_get_current_prl_info_resp_msg_v01), dms_get_current_prl_info_resp_msg_data_v01},
  {sizeof(dms_bind_subscription_req_msg_v01), dms_bind_subscription_req_msg_data_v01},
  {sizeof(dms_bind_subscription_resp_msg_v01), dms_bind_subscription_resp_msg_data_v01},
  {sizeof(dms_get_bind_subscription_req_msg_v01), 0},
  {sizeof(dms_get_bind_subscription_resp_msg_v01), dms_get_bind_subscription_resp_msg_data_v01},
  {sizeof(dms_set_ap_sw_version_req_msg_v01), dms_set_ap_sw_version_req_msg_data_v01},
  {sizeof(dms_set_ap_sw_version_resp_msg_v01), dms_set_ap_sw_version_resp_msg_data_v01},
  {sizeof(dms_get_cdma_lock_mode_req_msg_v01), 0},
  {sizeof(dms_get_cdma_lock_mode_resp_msg_v01), dms_get_cdma_lock_mode_resp_msg_data_v01},
  {sizeof(dms_set_test_config_req_msg_v01), dms_set_test_config_req_msg_data_v01},
  {sizeof(dms_set_test_config_resp_msg_v01), dms_set_test_config_resp_msg_data_v01},
  {sizeof(dms_get_test_config_req_msg_v01), 0},
  {sizeof(dms_get_test_config_resp_msg_v01), dms_get_test_config_resp_msg_data_v01},
  {sizeof(dms_clear_test_config_req_msg_v01), 0},
  {sizeof(dms_clear_test_config_resp_msg_v01), dms_clear_test_config_resp_msg_data_v01},
  {sizeof(dms_oem_china_operator_req_msg_v01), 0},
  {sizeof(dms_oem_china_operator_resp_msg_v01), dms_oem_china_operator_resp_msg_data_v01},
  {sizeof(dms_get_mac_address_req_msg_v01), dms_get_mac_address_req_msg_data_v01},
  {sizeof(dms_get_mac_address_resp_msg_v01), dms_get_mac_address_resp_msg_data_v01},
  {sizeof(dms_config_modem_activity_info_req_msg_v01), dms_config_modem_activity_info_req_msg_data_v01},
  {sizeof(dms_config_modem_activity_info_resp_msg_v01), dms_config_modem_activity_info_resp_msg_data_v01},
  {sizeof(dms_get_modem_activity_info_req_msg_v01), 0},
  {sizeof(dms_get_modem_activity_info_resp_msg_v01), dms_get_modem_activity_info_resp_msg_data_v01},
  {sizeof(dms_activity_info_ind_msg_v01), dms_activity_info_ind_msg_data_v01},
  {sizeof(dms_psm_get_cfg_params_req_msg_v01), 0},
  {sizeof(dms_psm_get_cfg_params_resp_msg_v01), dms_psm_get_cfg_params_resp_msg_data_v01},
  {sizeof(dms_psm_enter_req_msg_v01), dms_psm_enter_req_msg_data_v01},
  {sizeof(dms_psm_enter_resp_msg_v01), dms_psm_enter_resp_msg_data_v01},
  {sizeof(dms_psm_status_ind_msg_v01), dms_psm_status_ind_msg_data_v01},
  {sizeof(dms_get_capability_req_msg_v01), dms_get_capability_req_msg_data_v01},
  {sizeof(dms_get_capability_resp_msg_v01), dms_get_capability_resp_msg_data_v01},
  {sizeof(dms_get_ui_status_info_req_msg_v01), 0},
  {sizeof(dms_get_ui_status_info_resp_msg_v01), dms_get_ui_status_info_resp_msg_data_v01},
  {sizeof(dms_set_ui_status_info_req_msg_v01), dms_set_ui_status_info_req_msg_data_v01},
  {sizeof(dms_set_ui_status_info_resp_msg_v01), dms_set_ui_status_info_resp_msg_data_v01},
  {sizeof(dms_set_device_cap_config_req_msg_v01), dms_set_device_cap_config_req_msg_data_v01},
  {sizeof(dms_set_device_cap_config_resp_msg_v01), dms_set_device_cap_config_resp_msg_data_v01},
  {sizeof(dms_psm_set_cfg_params_req_msg_v01), dms_psm_set_cfg_params_req_msg_data_v01},
  {sizeof(dms_psm_set_cfg_params_resp_msg_v01), dms_psm_set_cfg_params_resp_msg_data_v01},
  {sizeof(dms_psm_cfg_params_change_ind_msg_v01), dms_psm_cfg_params_change_ind_msg_data_v01},
  {sizeof(dms_ims_capability_ind_msg_v01), dms_ims_capability_ind_msg_data_v01},
  {sizeof(dms_set_ap_version_req_msg_v01), dms_set_ap_version_req_msg_data_v01},
  {sizeof(dms_set_ap_version_resp_msg_v01), dms_set_ap_version_resp_msg_data_v01},
  {sizeof(dms_set_app_priority_req_msg_v01), dms_set_app_priority_req_msg_data_v01},
  {sizeof(dms_set_app_priority_resp_msg_v01), dms_set_app_priority_resp_msg_data_v01},
  {sizeof(dms_set_sensor_configuration_req_msg_v01), dms_set_sensor_configuration_req_msg_data_v01},
  {sizeof(dms_set_sensor_configuration_resp_msg_v01), dms_set_sensor_configuration_resp_msg_data_v01},
  {sizeof(dms_get_sensor_data_req_msg_v01), dms_get_sensor_data_req_msg_data_v01},
  {sizeof(dms_get_sensor_data_resp_msg_v01), dms_get_sensor_data_resp_msg_data_v01},
  {sizeof(dms_reset_sensor_config_data_req_msg_v01), 0},
  {sizeof(dms_reset_sensor_config_data_resp_msg_v01), dms_reset_sensor_config_data_resp_msg_data_v01},
  {sizeof(dms_get_last_policy_met_info_req_msg_v01), 0},
  {sizeof(dms_get_last_policy_met_info_resp_msg_v01), dms_get_last_policy_met_info_resp_msg_data_v01},
  {sizeof(dms_sensor_policy_met_ind_msg_v01), dms_sensor_policy_met_ind_msg_data_v01},
  {sizeof(dms_device_power_info_request_ind_msg_v01), dms_device_power_info_request_ind_msg_data_v01},
  {sizeof(dms_device_interactive_state_request_ind_msg_v01), dms_device_interactive_state_request_ind_msg_data_v01},
  {sizeof(dms_device_power_info_req_msg_v01), dms_device_power_info_req_msg_data_v01},
  {sizeof(dms_device_power_info_resp_msg_v01), dms_device_power_info_resp_msg_data_v01},
  {sizeof(dms_device_interactive_state_req_msg_v01), dms_device_interactive_state_req_msg_data_v01},
  {sizeof(dms_device_interactive_state_resp_msg_v01), dms_device_interactive_state_resp_msg_data_v01}
};

/* Range Table */
/* No Ranges Defined in IDL */

/* Predefine the Type Table Object */
static const qmi_idl_type_table_object dms_qmi_idl_type_table_object_v01;

/*Referenced Tables Array*/
static const qmi_idl_type_table_object *dms_qmi_idl_type_table_object_referenced_tables_v01[] =
{&dms_qmi_idl_type_table_object_v01, &common_qmi_idl_type_table_object_v01};

/*Type Table Object*/
static const qmi_idl_type_table_object dms_qmi_idl_type_table_object_v01 = {
  sizeof(dms_type_table_v01)/sizeof(qmi_idl_type_table_entry ),
  sizeof(dms_message_table_v01)/sizeof(qmi_idl_message_table_entry),
  1,
  dms_type_table_v01,
  dms_message_table_v01,
  dms_qmi_idl_type_table_object_referenced_tables_v01,
  NULL
};

/*Arrays of service_message_table_entries for commands, responses and indications*/
static const qmi_idl_service_message_table_entry dms_service_command_messages_v01[] = {
  {QMI_DMS_RESET_REQ_V01, QMI_IDL_TYPE16(0, 0), 0},
  {QMI_DMS_SET_EVENT_REPORT_REQ_V01, QMI_IDL_TYPE16(0, 2), 41},
  {QMI_DMS_INDICATION_REGISTER_REQ_V01, QMI_IDL_TYPE16(0, 5), 24},
  {QMI_DMS_GET_SUPPORTED_MSGS_REQ_V01, QMI_IDL_TYPE16(1, 0), 0},
  {QMI_DMS_GET_SUPPORTED_FIELDS_REQ_V01, QMI_IDL_TYPE16(1, 2), 5},
  {QMI_DMS_GET_DEVICE_CAP_REQ_V01, QMI_IDL_TYPE16(0, 7), 0},
  {QMI_DMS_GET_DEVICE_MFR_REQ_V01, QMI_IDL_TYPE16(0, 9), 0},
  {QMI_DMS_GET_DEVICE_MODEL_ID_REQ_V01, QMI_IDL_TYPE16(0, 11), 0},
  {QMI_DMS_GET_DEVICE_REV_ID_REQ_V01, QMI_IDL_TYPE16(0, 13), 0},
  {QMI_DMS_GET_MSISDN_REQ_V01, QMI_IDL_TYPE16(0, 15), 0},
  {QMI_DMS_GET_DEVICE_SERIAL_NUMBERS_REQ_V01, QMI_IDL_TYPE16(0, 17), 0},
  {QMI_DMS_GET_POWER_STATE_REQ_V01, QMI_IDL_TYPE16(0, 21), 0},
  {QMI_DMS_UIM_SET_PIN_PROTECTION_REQ_V01, QMI_IDL_TYPE16(0, 23), 22},
  {QMI_DMS_UIM_VERIFY_PIN_REQ_V01, QMI_IDL_TYPE16(0, 25), 21},
  {QMI_DMS_UIM_UNBLOCK_PIN_REQ_V01, QMI_IDL_TYPE16(0, 27), 38},
  {QMI_DMS_UIM_CHANGE_PIN_REQ_V01, QMI_IDL_TYPE16(0, 29), 38},
  {QMI_DMS_UIM_GET_PIN_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 31), 0},
  {QMI_DMS_GET_DEVICE_HARDWARE_REV_REQ_V01, QMI_IDL_TYPE16(0, 33), 0},
  {QMI_DMS_GET_OPERATING_MODE_REQ_V01, QMI_IDL_TYPE16(0, 35), 0},
  {QMI_DMS_SET_OPERATING_MODE_REQ_V01, QMI_IDL_TYPE16(0, 37), 4},
  {QMI_DMS_GET_TIME_REQ_V01, QMI_IDL_TYPE16(0, 39), 0},
  {QMI_DMS_GET_PRL_VER_REQ_V01, QMI_IDL_TYPE16(0, 41), 0},
  {QMI_DMS_GET_ACTIVATION_STATE_REQ_V01, QMI_IDL_TYPE16(0, 43), 0},
  {QMI_DMS_ACTIVATE_AUTOMATIC_REQ_V01, QMI_IDL_TYPE16(0, 45), 85},
  {QMI_DMS_ACTIVATE_MANUAL_REQ_V01, QMI_IDL_TYPE16(0, 47), 1627},
  {QMI_DMS_GET_USER_LOCK_STATE_REQ_V01, QMI_IDL_TYPE16(0, 49), 0},
  {QMI_DMS_SET_USER_LOCK_STATE_REQ_V01, QMI_IDL_TYPE16(0, 51), 8},
  {QMI_DMS_SET_USER_LOCK_CODE_REQ_V01, QMI_IDL_TYPE16(0, 53), 11},
  {QMI_DMS_READ_USER_DATA_REQ_V01, QMI_IDL_TYPE16(0, 55), 0},
  {QMI_DMS_WRITE_USER_DATA_REQ_V01, QMI_IDL_TYPE16(0, 57), 517},
  {QMI_DMS_READ_ERI_FILE_REQ_V01, QMI_IDL_TYPE16(0, 59), 0},
  {QMI_DMS_RESTORE_FACTORY_DEFAULTS_REQ_V01, QMI_IDL_TYPE16(0, 61), 9},
  {QMI_DMS_VALIDATE_SERVICE_PROGRAMMING_CODE_REQ_V01, QMI_IDL_TYPE16(0, 63), 9},
  {QMI_DMS_UIM_GET_ICCID_REQ_V01, QMI_IDL_TYPE16(0, 65), 0},
  {QMI_DMS_UIM_GET_CK_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 67), 4},
  {QMI_DMS_UIM_SET_CK_PROTECTION_REQ_V01, QMI_IDL_TYPE16(0, 69), 14},
  {QMI_DMS_UIM_UNBLOCK_CK_REQ_V01, QMI_IDL_TYPE16(0, 71), 13},
  {QMI_DMS_UIM_GET_IMSI_REQ_V01, QMI_IDL_TYPE16(0, 73), 0},
  {QMI_DMS_UIM_GET_STATE_REQ_V01, QMI_IDL_TYPE16(0, 75), 0},
  {QMI_DMS_GET_BAND_CAPABILITY_REQ_V01, QMI_IDL_TYPE16(0, 77), 0},
  {QMI_DMS_GET_FACTORY_SKU_REQ_V01, QMI_IDL_TYPE16(0, 79), 0},
  {QMI_DMS_SET_TIME_REQ_V01, QMI_IDL_TYPE16(0, 81), 18},
  {QMI_DMS_GET_ALT_NET_CONFIG_REQ_V01, QMI_IDL_TYPE16(0, 83), 0},
  {QMI_DMS_SET_ALT_NET_CONFIG_REQ_V01, QMI_IDL_TYPE16(0, 85), 4},
  {QMI_DMS_GET_SW_VERSION_REQ_V01, QMI_IDL_TYPE16(0, 87), 0},
  {QMI_DMS_SET_SPC_REQ_V01, QMI_IDL_TYPE16(0, 89), 18},
  {QMI_DMS_GET_CURRENT_PRL_INFO_REQ_V01, QMI_IDL_TYPE16(0, 91), 0},
  {QMI_DMS_BIND_SUBSCRIPTION_REQ_V01, QMI_IDL_TYPE16(0, 93), 7},
  {QMI_DMS_GET_BIND_SUBSCRIPTION_REQ_V01, QMI_IDL_TYPE16(0, 95), 0},
  {QMI_DMS_SET_AP_SW_VERSION_REQ_V01, QMI_IDL_TYPE16(0, 97), 35},
  {QMI_DMS_GET_CDMA_LOCK_MODE_REQ_V01, QMI_IDL_TYPE16(0, 99), 0},
  {QMI_DMS_SET_TEST_CONFIG_REQ_V01, QMI_IDL_TYPE16(0, 101), 7},
  {QMI_DMS_GET_TEST_CONFIG_REQ_V01, QMI_IDL_TYPE16(0, 103), 0},
  {QMI_DMS_CLEAR_TEST_CONFIG_REQ_V01, QMI_IDL_TYPE16(0, 105), 0},
  {QMI_DMS_OEM_CHINA_OPERATOR_REQ_V01, QMI_IDL_TYPE16(0, 107), 0},
  {QMI_DMS_GET_MAC_ADDRESS_REQ_V01, QMI_IDL_TYPE16(0, 109), 7},
  {QMI_DMS_GET_ENCRYPTED_DEVICE_SERIAL_NUMBERS_REQ_V01, QMI_IDL_TYPE16(0, 19), 0},
  {QMI_DMS_TRIGGER_MODEM_ACTIVITY_INFO_CALCULATION_REQ_V01, QMI_IDL_TYPE16(0, 111), 4},
  {QMI_DMS_GET_MODEM_ACTIVITY_INFO_REQ_V01, QMI_IDL_TYPE16(0, 113), 0},
  {QMI_DMS_PSM_GET_CFG_PARAMS_REQ_V01, QMI_IDL_TYPE16(0, 116), 0},
  {QMI_DMS_PSM_ENTER_REQ_V01, QMI_IDL_TYPE16(0, 118), 11},
  {QMI_DMS_GET_UI_STATUS_INFO_REQ_V01, QMI_IDL_TYPE16(0, 123), 0},
  {QMI_DMS_SET_UI_STATUS_INFO_REQ_V01, QMI_IDL_TYPE16(0, 125), 4},
  {QMI_DMS_SET_DEVICE_CAP_CONFIG_REQ_V01, QMI_IDL_TYPE16(0, 127), 5},
  {QMI_DMS_PSM_SET_CFG_PARAMS_REQ_V01, QMI_IDL_TYPE16(0, 129), 18},
  {QMI_DMS_SET_AP_VERSION_REQ_V01, QMI_IDL_TYPE16(0, 133), 184},
  {QMI_DMS_GET_CAPABILITY_REQ_V01, QMI_IDL_TYPE16(0, 121), 7},
  {QMI_DMS_SET_APP_PRIORITY_REQ_V01, QMI_IDL_TYPE16(0, 135), 7},
  {QMI_DMS_SET_SENSOR_CONFIGURATION_REQ_V01, QMI_IDL_TYPE16(0, 137), 1446},
  {QMI_DMS_GET_SENSOR_DATA_REQ_V01, QMI_IDL_TYPE16(0, 139), 5},
  {QMI_DMS_RESET_SENSOR_CONFIG_DATA_REQ_V01, QMI_IDL_TYPE16(0, 141), 0},
  {QMI_DMS_GET_LAST_POLICY_MET_INFO_REQ_V01, QMI_IDL_TYPE16(0, 143), 0},
  {QMI_DMS_DEVICE_POWER_INFO_REQ_V01, QMI_IDL_TYPE16(0, 148), 30},
  {QMI_DMS_DEVICE_INTERACTIVE_STATE_REQ_V01, QMI_IDL_TYPE16(0, 150), 7}
};

static const qmi_idl_service_message_table_entry dms_service_response_messages_v01[] = {
  {QMI_DMS_RESET_RESP_V01, QMI_IDL_TYPE16(0, 1), 7},
  {QMI_DMS_SET_EVENT_REPORT_RESP_V01, QMI_IDL_TYPE16(0, 3), 7},
  {QMI_DMS_INDICATION_REGISTER_RESP_V01, QMI_IDL_TYPE16(0, 6), 7},
  {QMI_DMS_GET_SUPPORTED_MSGS_RESP_V01, QMI_IDL_TYPE16(1, 1), 8204},
  {QMI_DMS_GET_SUPPORTED_FIELDS_RESP_V01, QMI_IDL_TYPE16(1, 3), 115},
  {QMI_DMS_GET_DEVICE_CAP_RESP_V01, QMI_IDL_TYPE16(0, 8), 3640},
  {QMI_DMS_GET_DEVICE_MFR_RESP_V01, QMI_IDL_TYPE16(0, 10), 138},
  {QMI_DMS_GET_DEVICE_MODEL_ID_RESP_V01, QMI_IDL_TYPE16(0, 12), 266},
  {QMI_DMS_GET_DEVICE_REV_ID_RESP_V01, QMI_IDL_TYPE16(0, 14), 543},
  {QMI_DMS_GET_MSISDN_RESP_V01, QMI_IDL_TYPE16(0, 16), 112},
  {QMI_DMS_GET_DEVICE_SERIAL_NUMBERS_RESP_V01, QMI_IDL_TYPE16(0, 18), 370},
  {QMI_DMS_GET_POWER_STATE_RESP_V01, QMI_IDL_TYPE16(0, 22), 12},
  {QMI_DMS_UIM_SET_PIN_PROTECTION_RESP_V01, QMI_IDL_TYPE16(0, 24), 12},
  {QMI_DMS_UIM_VERIFY_PIN_RESP_V01, QMI_IDL_TYPE16(0, 26), 12},
  {QMI_DMS_UIM_UNBLOCK_PIN_RESP_V01, QMI_IDL_TYPE16(0, 28), 12},
  {QMI_DMS_UIM_CHANGE_PIN_RESP_V01, QMI_IDL_TYPE16(0, 30), 12},
  {QMI_DMS_UIM_GET_PIN_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 32), 19},
  {QMI_DMS_GET_DEVICE_HARDWARE_REV_RESP_V01, QMI_IDL_TYPE16(0, 34), 266},
  {QMI_DMS_GET_OPERATING_MODE_RESP_V01, QMI_IDL_TYPE16(0, 36), 20},
  {QMI_DMS_SET_OPERATING_MODE_RESP_V01, QMI_IDL_TYPE16(0, 38), 7},
  {QMI_DMS_GET_TIME_RESP_V01, QMI_IDL_TYPE16(0, 40), 40},
  {QMI_DMS_GET_PRL_VER_RESP_V01, QMI_IDL_TYPE16(0, 42), 16},
  {QMI_DMS_GET_ACTIVATION_STATE_RESP_V01, QMI_IDL_TYPE16(0, 44), 12},
  {QMI_DMS_ACTIVATE_AUTOMATIC_RESP_V01, QMI_IDL_TYPE16(0, 46), 7},
  {QMI_DMS_ACTIVATE_MANUAL_RESP_V01, QMI_IDL_TYPE16(0, 48), 7},
  {QMI_DMS_GET_USER_LOCK_STATE_RESP_V01, QMI_IDL_TYPE16(0, 50), 11},
  {QMI_DMS_SET_USER_LOCK_STATE_RESP_V01, QMI_IDL_TYPE16(0, 52), 7},
  {QMI_DMS_SET_USER_LOCK_CODE_RESP_V01, QMI_IDL_TYPE16(0, 54), 7},
  {QMI_DMS_READ_USER_DATA_RESP_V01, QMI_IDL_TYPE16(0, 56), 524},
  {QMI_DMS_WRITE_USER_DATA_RESP_V01, QMI_IDL_TYPE16(0, 58), 7},
  {QMI_DMS_READ_ERI_FILE_RESP_V01, QMI_IDL_TYPE16(0, 60), 1036},
  {QMI_DMS_RESTORE_FACTORY_DEFAULTS_RESP_V01, QMI_IDL_TYPE16(0, 62), 7},
  {QMI_DMS_VALIDATE_SERVICE_PROGRAMMING_CODE_RESP_V01, QMI_IDL_TYPE16(0, 64), 7},
  {QMI_DMS_UIM_GET_ICCID_RESP_V01, QMI_IDL_TYPE16(0, 66), 30},
  {QMI_DMS_UIM_GET_CK_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 68), 17},
  {QMI_DMS_UIM_SET_CK_PROTECTION_RESP_V01, QMI_IDL_TYPE16(0, 70), 11},
  {QMI_DMS_UIM_UNBLOCK_CK_RESP_V01, QMI_IDL_TYPE16(0, 72), 11},
  {QMI_DMS_UIM_GET_IMSI_RESP_V01, QMI_IDL_TYPE16(0, 74), 42},
  {QMI_DMS_UIM_GET_STATE_RESP_V01, QMI_IDL_TYPE16(0, 76), 11},
  {QMI_DMS_GET_BAND_CAPABILITY_RESP_V01, QMI_IDL_TYPE16(0, 78), 1586},
  {QMI_DMS_GET_FACTORY_SKU_RESP_V01, QMI_IDL_TYPE16(0, 80), 138},
  {QMI_DMS_SET_TIME_RESP_V01, QMI_IDL_TYPE16(0, 82), 7},
  {QMI_DMS_GET_ALT_NET_CONFIG_RESP_V01, QMI_IDL_TYPE16(0, 84), 11},
  {QMI_DMS_SET_ALT_NET_CONFIG_RESP_V01, QMI_IDL_TYPE16(0, 86), 7},
  {QMI_DMS_GET_SW_VERSION_RESP_V01, QMI_IDL_TYPE16(0, 88), 4564},
  {QMI_DMS_SET_SPC_RESP_V01, QMI_IDL_TYPE16(0, 90), 7},
  {QMI_DMS_GET_CURRENT_PRL_INFO_RESP_V01, QMI_IDL_TYPE16(0, 92), 23},
  {QMI_DMS_BIND_SUBSCRIPTION_RESP_V01, QMI_IDL_TYPE16(0, 94), 7},
  {QMI_DMS_GET_BIND_SUBSCRIPTION_RESP_V01, QMI_IDL_TYPE16(0, 96), 14},
  {QMI_DMS_SET_AP_SW_VERSION_RESP_V01, QMI_IDL_TYPE16(0, 98), 7},
  {QMI_DMS_GET_CDMA_LOCK_MODE_RESP_V01, QMI_IDL_TYPE16(0, 100), 14},
  {QMI_DMS_SET_TEST_CONFIG_RESP_V01, QMI_IDL_TYPE16(0, 102), 7},
  {QMI_DMS_GET_TEST_CONFIG_RESP_V01, QMI_IDL_TYPE16(0, 104), 21},
  {QMI_DMS_CLEAR_TEST_CONFIG_RESP_V01, QMI_IDL_TYPE16(0, 106), 7},
  {QMI_DMS_OEM_CHINA_OPERATOR_RESP_V01, QMI_IDL_TYPE16(0, 108), 14},
  {QMI_DMS_GET_MAC_ADDRESS_RESP_V01, QMI_IDL_TYPE16(0, 110), 19},
  {QMI_DMS_GET_ENCRYPTED_DEVICE_SERIAL_NUMBERS_RESP_V01, QMI_IDL_TYPE16(0, 20), 1043},
  {QMI_DMS_TRIGGER_MODEM_ACTIVITY_INFO_CALCULATION_RESP_V01, QMI_IDL_TYPE16(0, 112), 7},
  {QMI_DMS_GET_MODEM_ACTIVITY_INFO_RESP_V01, QMI_IDL_TYPE16(0, 114), 7},
  {QMI_DMS_PSM_GET_CFG_PARAMS_RESP_V01, QMI_IDL_TYPE16(0, 117), 53},
  {QMI_DMS_PSM_ENTER_RESP_V01, QMI_IDL_TYPE16(0, 119), 7},
  {QMI_DMS_GET_UI_STATUS_INFO_RESP_V01, QMI_IDL_TYPE16(0, 124), 11},
  {QMI_DMS_SET_UI_STATUS_INFO_RESP_V01, QMI_IDL_TYPE16(0, 126), 7},
  {QMI_DMS_SET_DEVICE_CAP_CONFIG_RESP_V01, QMI_IDL_TYPE16(0, 128), 7},
  {QMI_DMS_PSM_SET_CFG_PARAMS_RESP_V01, QMI_IDL_TYPE16(0, 130), 7},
  {QMI_DMS_SET_AP_VERSION_RESP_V01, QMI_IDL_TYPE16(0, 134), 7},
  {QMI_DMS_GET_CAPABILITY_RESP_V01, QMI_IDL_TYPE16(0, 122), 14},
  {QMI_DMS_SET_APP_PRIORITY_RESP_V01, QMI_IDL_TYPE16(0, 136), 7},
  {QMI_DMS_SET_SENSOR_CONFIGURATION_RESP_V01, QMI_IDL_TYPE16(0, 138), 7},
  {QMI_DMS_GET_SENSOR_DATA_RESP_V01, QMI_IDL_TYPE16(0, 140), 12311},
  {QMI_DMS_RESET_SENSOR_CONFIG_DATA_RESP_V01, QMI_IDL_TYPE16(0, 142), 7},
  {QMI_DMS_GET_LAST_POLICY_MET_INFO_RESP_V01, QMI_IDL_TYPE16(0, 144), 17},
  {QMI_DMS_DEVICE_POWER_INFO_RESP_V01, QMI_IDL_TYPE16(0, 149), 7},
  {QMI_DMS_DEVICE_INTERACTIVE_STATE_RESP_V01, QMI_IDL_TYPE16(0, 151), 7}
};

static const qmi_idl_service_message_table_entry dms_service_indication_messages_v01[] = {
  {QMI_DMS_EVENT_REPORT_IND_V01, QMI_IDL_TYPE16(0, 4), 3335},
  {QMI_DMS_MODEM_ACTIVITY_INFO_IND_V01, QMI_IDL_TYPE16(0, 115), 1371},
  {QMI_DMS_PSM_STATUS_IND_V01, QMI_IDL_TYPE16(0, 120), 21},
  {QMI_DMS_PSM_CFG_PARAMS_CHANGE_IND_V01, QMI_IDL_TYPE16(0, 131), 18},
  {QMI_DMS_IMS_CAPABILITY_IND_V01, QMI_IDL_TYPE16(0, 132), 34},
  {QMI_DMS_SENSOR_POLICY_MET_IND_V01, QMI_IDL_TYPE16(0, 145), 10},
  {QMI_DMS_DEVICE_POWER_INFO_REQUEST_IND_V01, QMI_IDL_TYPE16(0, 146), 58},
  {QMI_DMS_DEVICE_INTERACTIVE_STATE_REQUEST_IND_V01, QMI_IDL_TYPE16(0, 147), 4}
};

/*Service Object*/
struct qmi_idl_service_object dms_qmi_idl_service_object_v01 = {
  0x06,
  0x01,
  0x02,
  12311,
  { sizeof(dms_service_command_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(dms_service_response_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(dms_service_indication_messages_v01)/sizeof(qmi_idl_service_message_table_entry) },
  { dms_service_command_messages_v01, dms_service_response_messages_v01, dms_service_indication_messages_v01},
  &dms_qmi_idl_type_table_object_v01,
  0x48,
  NULL
};

/* Service Object Accessor */
qmi_idl_service_object_type dms_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version ){
  if ( DMS_V01_IDL_MAJOR_VERS != idl_maj_version || DMS_V01_IDL_MINOR_VERS != idl_min_version
       || DMS_V01_IDL_TOOL_VERS != library_version)
  {
    return NULL;
  }
  return (qmi_idl_service_object_type)&dms_qmi_idl_service_object_v01;
}

