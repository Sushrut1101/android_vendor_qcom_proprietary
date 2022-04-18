/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                        W I R E L E S S _ D A T A _ S E R V I C E _ V 0 1  . C

GENERAL DESCRIPTION
  This is the file which defines the wds service Data structures.

  Copyright (c) 2006-2019 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.


  $Header$
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7
   It was generated on: Wed Feb  5 2020 (Spin 0)
   From IDL File: wireless_data_service_v01.idl */

#include "stdint.h"
#include "qmi_idl_lib_internal.h"
#include "wireless_data_service_v01.h"
#include "common_v01.h"
#include "data_common_v01.h"
#include "wireless_data_service_common_v01.h"


/*Type Definitions*/
static const uint8_t wds_ladn_status_info_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_ladn_status_info_type_v01, ladn_name),
  QMI_WDS_APN_NAME_MAX_V01,
  QMI_IDL_OFFSET8(wds_ladn_status_info_type_v01, ladn_name) - QMI_IDL_OFFSET8(wds_ladn_status_info_type_v01, ladn_name_len),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_ladn_status_info_type_v01, is_avail),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_result_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_result_type_v01, service_id),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_result_type_v01, result),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_non_sps_info_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_info_type_v01, service_id),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_info_type_v01, port),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_sps_flow_id_info_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_id_info_v01, req_id),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_id_info_v01, sps_id),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_sps_flow_result_info_data_v01[] = {
  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_result_info_v01, flow_id),
  QMI_IDL_TYPE88(0, 3),
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_result_info_v01, result),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_tx_pool_id_info_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_tx_pool_id_info_type_v01, pool_id),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_tx_pool_id_info_type_v01, min_freq),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_tx_pool_id_info_type_v01, max_freq),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_pppp_info_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_pppp_info_type_v01, priority),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_pppp_info_type_v01, pdb),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_op_reserved_pco_info_ex_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_ex_type_v01, pco_id),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_ex_type_v01, mcc),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_ex_type_v01, mnc),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_ex_type_v01, mnc_includes_pcs_digit),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_ex_type_v01, app_specific_info),
  QMI_WDS_APP_SPECIFIC_INFO_V01,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_ex_type_v01, app_specific_info) - QMI_IDL_OFFSET8(wds_op_reserved_pco_info_ex_type_v01, app_specific_info_len),

  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_op_reserved_pco_info_ex_type_v01, container_id),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_op_reserved_pco_list_info_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_list_info_type_v01, pco_info),
  QMI_WDS_MAX_NUM_PCO_V01,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_list_info_type_v01, pco_info) - QMI_IDL_OFFSET8(wds_op_reserved_pco_list_info_type_v01, pco_info_len),
  QMI_IDL_TYPE88(0, 7),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_op_reserved_pco_list_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_list_type_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_list_type_v01, pco_list_info),
  QMI_IDL_TYPE88(0, 8),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_report_apn_op_reserved_pco_list_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_report_apn_op_reserved_pco_list_v01, report_op_reserved_pco_list_change),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_report_apn_op_reserved_pco_list_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_apn_msisdn_info_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_apn_msisdn_info_type_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_apn_msisdn_info_type_v01, msisdn),
  QMI_WDS_MSISDN_INFO_MAX_V01,
  QMI_IDL_OFFSET8(wds_apn_msisdn_info_type_v01, msisdn) - QMI_IDL_OFFSET8(wds_apn_msisdn_info_type_v01, msisdn_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_op_reserved_pco_info_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_type_v01, mcc),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_type_v01, mnc),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_type_v01, mnc_includes_pcs_digit),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_type_v01, app_specific_info),
  QMI_WDS_APP_SPECIFIC_INFO_V01,
  QMI_IDL_OFFSET8(wds_op_reserved_pco_info_type_v01, app_specific_info) - QMI_IDL_OFFSET8(wds_op_reserved_pco_info_type_v01, app_specific_info_len),

  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_op_reserved_pco_info_type_v01, container_id),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_runtime_ipv6_addr_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_runtime_ipv6_addr_type_v01, ipv6_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_runtime_ipv6_addr_type_v01, ipv6_prefix_length),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_report_apn_msisdn_change_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_report_apn_msisdn_change_v01, report_msisdn_info_change),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_report_apn_msisdn_change_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_apn_name_list_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_apn_name_list_type_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_data_bearer_type_info_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_data_bearer_type_info_v01, bearer_id),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_data_bearer_type_info_v01, ul_direction),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_data_bearer_type_info_v01, dl_direction),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_ran_asst_media_adapt_bit_rate_info_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adapt_bit_rate_info_type_v01, direction),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adapt_bit_rate_info_type_v01, bit_rate),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_ran_asst_media_adapt_client_info_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adapt_client_info_type_v01, handle),

  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adapt_client_info_type_v01, bit_rate_info),
  QMI_IDL_TYPE88(0, 17),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_ran_asst_media_adapt_info_type_data_v01[] = {
  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adapt_info_type_v01, info),
  QMI_IDL_TYPE88(0, 18),
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adapt_info_type_v01, is_rohc_enabled),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t qmi_wds_transaction_info_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(qmi_wds_transaction_info_type_v01, transaction_id),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(qmi_wds_transaction_info_type_v01, num_segments),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(qmi_wds_transaction_info_type_v01, segment_index),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_pdn_throttle_info_per_apn_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, apn_string) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, apn_string_len),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, is_ipv4_throttled),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, is_ipv6_throttled),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, is_non_ip_throttled),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, remaining_ipv4_throttled_time),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, remaining_ipv6_throttled_time),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, remaining_non_ip_throttled_time),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, is_emergency_apn),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, apn_blocked_on_all_plmns),

  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_per_apn_type_v01, throttled_plmn_id),
  3,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_statistics_indicator_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_statistics_indicator_type_v01, stats_period),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_statistics_indicator_type_v01, stats_mask),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_channel_rate_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_channel_rate_type_v01, current_channel_tx_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_channel_rate_type_v01, current_channel_rx_rate),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_channel_rate_ex_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_channel_rate_ex_type_v01, rate_type),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_channel_rate_ex_type_v01, channel_tx_rate_ex),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_channel_rate_ex_type_v01, channel_rx_rate_ex),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_current_bearer_tech_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_current_bearer_tech_type_v01, current_nw),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_current_bearer_tech_type_v01, rat_mask),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_current_bearer_tech_type_v01, so_mask),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_evdo_page_monitor_period_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_evdo_page_monitor_period_type_v01, evdo_page_monitor_period_change),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_evdo_page_monitor_period_type_v01, evdo_force_long_sleep),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_event_data_call_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_event_data_call_type_v01, data_call_type),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_event_data_call_type_v01, tethered_call_type),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_sys_network_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_sys_network_info_type_v01, network),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_sys_network_info_type_v01, rat_mask),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_sys_network_info_type_v01, so_mask),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_data_system_status_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_data_system_status_type_v01, preferred_network),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_data_system_status_type_v01, network_info),
  QMI_WDS_SYS_NETWORK_MAX_V01,
  QMI_IDL_OFFSET8(wds_data_system_status_type_v01, network_info) - QMI_IDL_OFFSET8(wds_data_system_status_type_v01, network_info_len),
  QMI_IDL_TYPE88(0, 28),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_bearer_tech_info_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_bearer_tech_info_type_v01, technology),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_bearer_tech_info_type_v01, rat_value),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_bearer_tech_info_type_v01, so_mask),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_delay_dormancy_result_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_delay_dormancy_result_type_v01, status),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_delay_dormancy_result_type_v01, dormancy_failure_reason),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_handoff_context_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_handoff_context_type_v01, ipv4_addr),

  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_handoff_context_type_v01, ipv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_handoff_context_type_v01, bearer_ip_type),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_verbose_call_end_reason_type_data_v01[] = {
  QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_verbose_call_end_reason_type_v01, call_end_reason_type),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_verbose_call_end_reason_type_v01, call_end_reason),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_packet_service_status_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_packet_service_status_type_v01, connection_status),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_packet_service_status_type_v01, reconfiguration_required),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_current_channel_rate_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_current_channel_rate_type_v01, current_channel_tx_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_current_channel_rate_type_v01, current_channel_rx_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_current_channel_rate_type_v01, max_channel_tx_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_current_channel_rate_type_v01, max_channel_rx_rate),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_current_channel_rate_ex_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_current_channel_rate_ex_type_v01, rate_type),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_current_channel_rate_ex_type_v01, current_channel_tx_rate),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_current_channel_rate_ex_type_v01, current_channel_rx_rate),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_current_channel_rate_ex_type_v01, max_channel_tx_rate),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_current_channel_rate_ex_type_v01, max_channel_rx_rate),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_umts_qos_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, traffic_class),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, max_uplink_bitrate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, max_downlink_bitrate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, guaranteed_uplink_bitrate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, guaranteed_downlink_bitrate),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, qos_delivery_order),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, max_sdu_size),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, sdu_error_ratio),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, residual_bit_error_ratio),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, delivery_erroneous_SDUs),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, transfer_delay),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_umts_qos_type_v01, traffic_handling_priority),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_umts_qos_with_sig_ind_type_data_v01[] = {
  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_umts_qos_with_sig_ind_type_v01, umts_qos),
  QMI_IDL_TYPE88(0, 37),
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_umts_qos_with_sig_ind_type_v01, sig_ind),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_gprs_qos_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_gprs_qos_type_v01, precedence_class),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_gprs_qos_type_v01, delay_class),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_gprs_qos_type_v01, reliability_class),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_gprs_qos_type_v01, peak_throughput_class),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_gprs_qos_type_v01, mean_throughput_class),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_tft_id_param_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, filter_id),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, eval_id),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, ip_version),

  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, source_ip),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, source_ip_mask),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, next_header),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, dest_port_range_start),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, dest_port_range_end),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, src_port_range_start),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, src_port_range_end),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, ipsec_spi),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, tos_mask),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_tft_id_param_type_v01, flow_label),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_3gpp_lte_qos_params_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_3gpp_lte_qos_params_v01, qci),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_3gpp_lte_qos_params_v01, g_dl_bit_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_3gpp_lte_qos_params_v01, max_dl_bit_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_3gpp_lte_qos_params_v01, g_ul_bit_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_3gpp_lte_qos_params_v01, max_ul_bit_rate),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_mnc_pcs_digit_include_status_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_mnc_pcs_digit_include_status_type_v01, mnc),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_mnc_pcs_digit_include_status_type_v01, mnc_includes_pcs_digit),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_common_linger_param_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_common_linger_param_type_v01, common_allow_linger),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_common_linger_param_type_v01, common_linger_timeout),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_eap_auth_param_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_eap_auth_param_type_v01, auth_type),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_eap_auth_param_type_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_eap_auth_param_type_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_eap_auth_param_type_v01, certificate_path),
  QMI_WDS_CERT_PATH_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_profile_identifier_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_identifier_type_v01, profile_type),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_profile_identifier_type_v01, profile_index),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_profile_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_info_type_v01, profile_type),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_profile_info_type_v01, profile_index),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_profile_info_type_v01, profile_name),
  QMI_WDS_PROFILE_NAME_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_runtime_profile_identifier_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_runtime_profile_identifier_type_v01, profile_type),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_runtime_profile_identifier_type_v01, profile_index),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_pcscf_ipv4_addr_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pcscf_ipv4_addr_type_v01, pcscf_ipv4_address),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_pcscf_ipv4_addr_list_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pcscf_ipv4_addr_list_type_v01, pcscf_ipv4_addr_list),
  QMI_WDS_PCSCF_ADDR_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_pcscf_ipv4_addr_list_type_v01, pcscf_ipv4_addr_list) - QMI_IDL_OFFSET8(wds_pcscf_ipv4_addr_list_type_v01, pcscf_ipv4_addr_list_len),
  QMI_IDL_TYPE88(0, 48),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_fqdn_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_fqdn_type_v01, fqdn),
  ((QMI_WDS_FQDN_MAX_V01) & 0xFF), ((QMI_WDS_FQDN_MAX_V01) >> 8),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_fqdn_list_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_fqdn_list_type_v01, fqdn_list),
  QMI_WDS_FQDN_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_fqdn_list_type_v01, fqdn_list) - QMI_IDL_OFFSET8(wds_fqdn_list_type_v01, fqdn_list_len),
  QMI_IDL_TYPE88(0, 50),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_domain_name_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_domain_name_type_v01, domain_name),
  ((QMI_WDS_DOMAIN_NAME_MAX_V01) & 0xFF), ((QMI_WDS_DOMAIN_NAME_MAX_V01) >> 8),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_domain_name_list_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_domain_name_list_type_v01, domain_name_list),
  QMI_WDS_DOMAIN_NAME_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_domain_name_list_type_v01, domain_name_list) - QMI_IDL_OFFSET8(wds_domain_name_list_type_v01, domain_name_list_len),
  QMI_IDL_TYPE88(0, 52),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_pcscf_ipv6_addr_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pcscf_ipv6_addr_type_v01, pcscf_ipv6_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_pcscf_ipv6_addr_list_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pcscf_ipv6_addr_list_type_v01, pcscf_ipv6_addr_list),
  QMI_WDS_PCSCF_ADDR_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_pcscf_ipv6_addr_list_type_v01, pcscf_ipv6_addr_list) - QMI_IDL_OFFSET8(wds_pcscf_ipv6_addr_list_type_v01, pcscf_ipv6_addr_list_len),
  QMI_IDL_TYPE88(0, 54),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_dun_stats_indicator_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_dun_stats_indicator_type_v01, stats_peroid),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_dun_stats_indicator_type_v01, stats_mask),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_dun_connection_status_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_dun_connection_status_type_v01, modem_connection_status),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_dun_connection_status_type_v01, modem_call_duration),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_mip_profile_identifier_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_mip_profile_identifier_type_v01, spc),
  QMI_WDS_SPC_LEN_V01,

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_mip_profile_identifier_type_v01, profile_index),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_call_record_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_type),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_data_bearer),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_timestamp),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_ip_addr),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_duration_total),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_duration_active),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_rx_ok_bytes),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_tx_ok_bytes),

  QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_end_reason),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_call_record_type_v01, call_phone_num),
  QMI_WDS_MAX_PHONE_NUMBER_LEN_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_full_call_record_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_full_call_record_type_v01, call_record_id),

  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_full_call_record_type_v01, call_record),
  QMI_IDL_TYPE88(0, 59),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_full_call_history_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_full_call_history_type_v01, full_call_history),
  ((QMI_WDS_MAX_CALL_HISTORY_V01) & 0xFF), ((QMI_WDS_MAX_CALL_HISTORY_V01) >> 8),
  QMI_IDL_OFFSET8(wds_full_call_history_type_v01, full_call_history) - QMI_IDL_OFFSET8(wds_full_call_history_type_v01, full_call_history_len),
  QMI_IDL_TYPE88(0, 60),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_id_only_call_record_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_id_only_call_record_type_v01, call_record_id),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_id_only_call_history_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_id_only_call_history_type_v01, id_only_call_history),
  ((QMI_WDS_MAX_CALL_HISTORY_V01) & 0xFF), ((QMI_WDS_MAX_CALL_HISTORY_V01) >> 8),
  QMI_IDL_OFFSET8(wds_id_only_call_history_type_v01, id_only_call_history) - QMI_IDL_OFFSET8(wds_id_only_call_history_type_v01, id_only_call_history_len),
  QMI_IDL_TYPE88(0, 62),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_profile_id_family_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_id_family_type_v01, profile_type),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_id_family_type_v01, profile_family),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_profile_identifier_with_family_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_identifier_with_family_type_v01, profile_type),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_identifier_with_family_type_v01, profile_family),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_profile_identifier_with_family_type_v01, profile_index),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_profile_param_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_param_type_v01, profile_type),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_profile_param_type_v01, profile_index),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_profile_param_type_v01, profile_param_id),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_tunnel_params_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_tunnel_params_type_v01, stream_id),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_tunnel_params_type_v01, nat_presence_indicator),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_tunnel_params_type_v01, port_id),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_predormancy_cdma_settings_type_data_v01[] = {
  QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_predormancy_cdma_settings_type_v01, service_option),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_predormancy_cdma_settings_type_v01, data_sess_nw),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_call_throttle_info_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_call_throttle_info_type_v01, hdr_call_throttled_delay),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_call_throttle_info_type_v01, cdma_call_throttled_delay),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_embms_tmgi_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_type_v01, tmgi),
  6,

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_type_v01, session_id_valid),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_type_v01, session_id),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_embms_earfcn_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_earfcn_type_v01, earfcn),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_embms_tmgi_list_struct_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_embms_tmgi_list_struct_type_v01, list_type),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_list_struct_type_v01, tmgi_list),
  QMI_WDS_EMBMS_MAX_TMGI_V01,
  QMI_IDL_OFFSET8(wds_embms_tmgi_list_struct_type_v01, tmgi_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_list_struct_type_v01, tmgi_list_len),
  QMI_IDL_TYPE88(0, 70),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_get_data_call_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_data_call_type_v01, data_call_type),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_data_call_type_v01, tethered_call_type),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_pdn_throttle_info_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_type_v01, is_ipv4_throttled),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_type_v01, is_ipv6_throttled),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_type_v01, remaining_ipv4_throttled_time),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_type_v01, remaining_ipv6_throttled_time),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_type_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_type_v01, apn_string) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_type_v01, apn_string_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_pdn_throttle_info_ext_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ext_type_v01, is_ipv4_throttled),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ext_type_v01, is_ipv6_throttled),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ext_type_v01, is_non_ip_throttled),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ext_type_v01, remaining_ipv4_throttled_time),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ext_type_v01, remaining_ipv6_throttled_time),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ext_type_v01, remaining_non_ip_throttled_time),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ext_type_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ext_type_v01, apn_string) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_ext_type_v01, apn_string_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_pdn_throttle_info_addn_params_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_addn_params_v01, is_emergency_apn),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_addn_params_v01, apn_blocked_on_all_plmns),

  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_addn_params_v01, throttled_plmn_id),
  3,

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_addn_params_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_addn_params_v01, apn_string) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_addn_params_v01, apn_string_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_reqd_net_policy_info_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_reqd_net_policy_info_v01, tech_pref),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_reqd_net_policy_info_v01, profile_id_3gpp2),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_reqd_net_policy_info_v01, profile_id_3gpp),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_tcp_udp_port_range_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_tcp_udp_port_range_v01, port),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_tcp_udp_port_range_v01, port_range),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_ip_addr_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_ip_addr_type_v01, addr_family),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_ip_addr_type_v01, ip_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01,
  QMI_IDL_OFFSET8(wds_ip_addr_type_v01, ip_addr) - QMI_IDL_OFFSET8(wds_ip_addr_type_v01, ip_addr_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_cfg_attr_ipv4_subnet_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_cfg_attr_ipv4_subnet_type_v01, ipv4_subnet_address),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_cfg_attr_ipv4_subnet_type_v01, subnet_mask),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_cfg_attr_ipv6_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_cfg_attr_ipv6_type_v01, ipv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_traffic_selector_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_traffic_selector_type_v01, protocol),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_traffic_selector_type_v01, start_port),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_traffic_selector_type_v01, end_port),

  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_traffic_selector_type_v01, start_address),
  QMI_IDL_TYPE88(0, 79),
  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_traffic_selector_type_v01, end_address),
  QMI_IDL_TYPE88(0, 79),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_handoff_event_info_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_handoff_event_info_type_v01, srat),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_handoff_event_info_type_v01, trat),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_handoff_failure_reason_type_data_v01[] = {
  QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_handoff_failure_reason_type_v01, failure_reason_type),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_handoff_failure_reason_type_v01, failure_reason),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_embms_sai_list_per_freq_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_type_v01, frequency),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_type_v01, is_serving_frequency),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_type_v01, sai_list),
  QMI_WDS_EMBMS_SAI_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_type_v01, sai_list) - QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_type_v01, sai_list_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_embms_sai_list_per_freq_ex_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_ex_type_v01, frequency),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_ex_type_v01, is_serving_frequency),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_ex_type_v01, sai_list),
  QMI_WDS_EMBMS_SAI_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_ex_type_v01, sai_list) - QMI_IDL_OFFSET8(wds_embms_sai_list_per_freq_ex_type_v01, sai_list_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_outage_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_outage_type_v01, time_to_outage),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_outage_type_v01, duration),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_rf_conditions_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_rf_conditions_type_v01, db_current_nw),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_rf_conditions_type_v01, db_rat_mask),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_rf_conditions_type_v01, db_so_mask),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_rf_conditions_type_v01, rf_cond),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_dos_ack_info_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_dos_ack_info_type_v01, handle),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_dos_ack_info_type_v01, overflow),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_dos_ack_info_type_v01, dos_ack_status),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_get_runtime_settings_error_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_runtime_settings_error_v01, bit_number),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_get_runtime_settings_error_v01, error_value),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_session_timer_1x_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_session_timer_1x_v01, timer_select),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_session_timer_1x_v01, timer_val),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_set_runtime_settings_error_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_runtime_settings_error_v01, tlv_type),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_set_runtime_settings_error_v01, error_value),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_bearer_rlp_mac_id_throughput_info_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_bearer_rlp_mac_id_throughput_info_type_v01, bearer_rlp_mac_id),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_bearer_rlp_mac_id_throughput_info_type_v01, uplink_actual_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_bearer_rlp_mac_id_throughput_info_type_v01, uplink_queue_size),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_bearer_rlp_mac_id_throughput_info_type_v01, is_primary),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_throughput_info_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, ip_type),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, tech_type),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, subscription),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, uplink_actual_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, uplink_allowed_rate),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, uplink_queue_size),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, throughput_signal),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, valid_port),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, data_port),

  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, ep_id),
  QMI_IDL_TYPE88(2, 0),
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, mux_id),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, bearer_rlp_mac_id_throughput_info),
  QMI_WDS_MAX_BEARER_RLP_MAC_ID_CONTEXT_V01,
  QMI_IDL_OFFSET8(wds_throughput_info_type_v01, bearer_rlp_mac_id_throughput_info) - QMI_IDL_OFFSET8(wds_throughput_info_type_v01, bearer_rlp_mac_id_throughput_info_len),
  QMI_IDL_TYPE88(0, 93),
  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_profile_event_register_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_event_register_type_v01, profile_type),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_profile_event_register_type_v01, profile_index),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_profile_changed_ind_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_changed_ind_type_v01, profile_type),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_profile_changed_ind_type_v01, profile_index),

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_changed_ind_type_v01, profile_change_evt),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_apn_param_apn_string_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_apn_param_apn_string_type_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_profile_identifier_ex_type_data_v01[] = {
  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_profile_identifier_ex_type_v01, profile_ident_type),
  QMI_IDL_TYPE88(0, 45),
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_profile_identifier_ex_type_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_identifier_ex_type_v01, pdp_type),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_non_sps_flow_info_type_data_v01[] = {
  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_info_type_v01, reg_info),
  QMI_IDL_TYPE88(0, 2),
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_info_type_v01, protocol),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_service_sub_info_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_service_sub_info_type_v01, req_id),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_service_sub_info_type_v01, action),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_profile_lite_info_type_data_v01[] = {
  QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_profile_lite_info_type_v01, pdp_type),

  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_profile_lite_info_type_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_config_file_seg_info_type_data_v01[] = {
  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_config_file_seg_info_type_v01, num_segments),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_config_file_seg_info_type_v01, seg_index),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_sps_scheduling_info_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_scheduling_info_type_v01, sps_id),

  QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_scheduling_info_type_v01, utc_time),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_scheduling_info_type_v01, periodicity),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_trusted_ue_info_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_trusted_ue_info_type_v01, src_l2_id),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_trusted_ue_info_type_v01, time_confidence_level),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_trusted_ue_info_type_v01, position_confidence_level),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_trusted_ue_info_type_v01, propagation_delay),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_v2x_trusted_ue_info_ex_type_data_v01[] = {
  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_trusted_ue_info_ex_type_v01, src_l2_id),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_trusted_ue_info_ex_type_v01, time_uncertainty),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_trusted_ue_info_ex_type_v01, position_confidence_level),

  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_trusted_ue_info_ex_type_v01, propagation_delay),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t qmi_wds_xcap_transaction_info_type_data_v01[] = {
  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(qmi_wds_xcap_transaction_info_type_v01, transaction_id),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(qmi_wds_xcap_transaction_info_type_v01, num_configs),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(qmi_wds_xcap_transaction_info_type_v01, config_index),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(qmi_wds_xcap_transaction_info_type_v01, num_segments),

  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(qmi_wds_xcap_transaction_info_type_v01, segment_index),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_ladn_config_type_data_v01[] = {
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_ladn_config_type_v01, ladn_name),
  QMI_WDS_APN_NAME_MAX_V01,
  QMI_IDL_OFFSET8(wds_ladn_config_type_v01, ladn_name) - QMI_IDL_OFFSET8(wds_ladn_config_type_v01, ladn_name_len),

  QMI_IDL_FLAG_END_VALUE
};

static const uint8_t wds_reject_reason_type_data_v01[] = {
  QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_reject_reason_type_v01, reject_reason_type),

  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_reject_reason_type_v01, reject_reason),

  QMI_IDL_FLAG_END_VALUE
};

/*Message Definitions*/
/*
 * wds_reset_req_msg is empty
 * static const uint8_t wds_reset_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_reset_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reset_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_set_event_report_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_channel_rate) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_channel_rate_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_channel_rate),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_stats) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_stats_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_stats),
  QMI_IDL_TYPE88(0, 22),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_bearer_tech) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_bearer_tech_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_bearer_tech),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_dormancy_status) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_dormancy_status_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_dormancy_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_mip_status) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_mip_status_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_mip_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_current_data_bearer_tech) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_current_data_bearer_tech_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_current_data_bearer_tech),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_call_status_change) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_call_status_change_valid)),
  0x17,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_call_status_change),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_preferred_data_system) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_preferred_data_system_valid)),
  0x18,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_preferred_data_system),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_evdo_page_monitor_period_change) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_evdo_page_monitor_period_change_valid)),
  0x19,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_evdo_page_monitor_period_change),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_system_status) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_system_status_valid)),
  0x1A,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_system_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_uplink_flow_control) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_uplink_flow_control_valid)),
  0x1B,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_uplink_flow_control),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, limited_data_system_status) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, limited_data_system_status_valid)),
  0x1C,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, limited_data_system_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_additional_pdn_filters_removal) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_additional_pdn_filters_removal_valid)),
  0x1D,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_additional_pdn_filters_removal),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_bearer_tech_ex) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_bearer_tech_ex_valid)),
  0x1E,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_data_bearer_tech_ex),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_delay_dormancy_result) - QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_delay_dormancy_result_valid)),
  0x1F,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_event_report_req_msg_v01, report_delay_dormancy_result)
};

static const uint8_t wds_set_event_report_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_event_report_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_event_report_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_ok_count) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_ok_count_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_ok_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_ok_count) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_ok_count_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_ok_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_err_count) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_err_count_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_err_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_err_count) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_err_count_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_err_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_ofl_count) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_ofl_count_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_ofl_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_ofl_count) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_ofl_count_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_ofl_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, channel_rate) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, channel_rate_valid)),
  0x16,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, channel_rate),
  QMI_IDL_TYPE88(0, 23),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, data_bearer_tech) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, data_bearer_tech_valid)),
  0x17,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, data_bearer_tech),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, dormancy_status) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, dormancy_status_valid)),
  0x18,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, dormancy_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_ok_bytes_count_valid)),
  0x19,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, tx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_ok_bytes_count_valid)),
  0x1A,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, rx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, mip_status) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, mip_status_valid)),
  0x1B,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, mip_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, current_bearer_tech) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, current_bearer_tech_valid)),
  0x1D,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, current_bearer_tech),
  QMI_IDL_TYPE88(0, 25),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, data_call_status) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, data_call_status_valid)),
  0x1F,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, data_call_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, current_sys) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, current_sys_valid)),
  0x20,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, current_sys),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, data_call_type) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, data_call_type_valid)),
  0x22,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, data_call_type),
  QMI_IDL_TYPE88(0, 27),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, evdo_page_monitor_period_change) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, evdo_page_monitor_period_change_valid)),
  0x23,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, evdo_page_monitor_period_change),
  QMI_IDL_TYPE88(0, 26),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, system_status) - QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, system_status_valid)),
  0x24,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_event_report_ind_msg_v01, system_status),
  QMI_IDL_TYPE88(0, 29),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, tx_dropped_count) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, tx_dropped_count_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_event_report_ind_msg_v01, tx_dropped_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, rx_dropped_count) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, rx_dropped_count_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_event_report_ind_msg_v01, rx_dropped_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, uplink_flow_control) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, uplink_flow_control_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_event_report_ind_msg_v01, uplink_flow_control),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, data_call_addr_family) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, data_call_addr_family_valid)),
  0x28,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_event_report_ind_msg_v01, data_call_addr_family),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, removed_filter_handles) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, removed_filter_handles_valid)),
  0x29,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_event_report_ind_msg_v01, removed_filter_handles),
  QMI_WDS_ADDITIONAL_PDN_FILTERS_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, removed_filter_handles) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, removed_filter_handles_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, bearer_tech_ex) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, bearer_tech_ex_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_event_report_ind_msg_v01, bearer_tech_ex),
  QMI_IDL_TYPE88(0, 30),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, uplink_fc_seq_num) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, uplink_fc_seq_num_valid)),
  0x2B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_event_report_ind_msg_v01, uplink_fc_seq_num),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, delay_dormancy_result) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, delay_dormancy_result_valid)),
  0x2C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_event_report_ind_msg_v01, delay_dormancy_result),
  QMI_IDL_TYPE88(0, 31),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, channel_rate_ex) - QMI_IDL_OFFSET16RELATIVE(wds_event_report_ind_msg_v01, channel_rate_ex_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_event_report_ind_msg_v01, channel_rate_ex),
  QMI_IDL_TYPE88(0, 24)
};

static const uint8_t wds_abort_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_abort_req_msg_v01, tx_id)
};

static const uint8_t wds_abort_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_abort_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_indication_register_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_tmgi_list) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_tmgi_list_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_tmgi_list),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, suppress_pkt_srvc_ind) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, suppress_pkt_srvc_ind_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, suppress_pkt_srvc_ind),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_extended_ip_config_change) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_extended_ip_config_change_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_extended_ip_config_change),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_lte_attach_pdn_list_change) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_lte_attach_pdn_list_change_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_lte_attach_pdn_list_change),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_reverse_ip_transport_filter_setup) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_reverse_ip_transport_filter_setup_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_reverse_ip_transport_filter_setup),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_handoff_information) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_handoff_information_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_handoff_information),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_sai_list) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_sai_list_valid)),
  0x17,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_sai_list),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_throughput) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_throughput_valid)),
  0x18,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_throughput),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_profile_changed_events) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_profile_changed_events_valid)),
  0x19,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_profile_changed_events),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_roaming_apn_list) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_roaming_apn_list_valid)),
  0x1A,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_roaming_apn_list),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_dl_throughput) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_dl_throughput_valid)),
  0x1B,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_dl_throughput),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_content_desc_control) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_content_desc_control_valid)),
  0x1C,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_content_desc_control),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_policy_ready) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_policy_ready_valid)),
  0x1D,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_policy_ready),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_apn_param_change_info) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_apn_param_change_info_valid)),
  0x1E,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_apn_param_change_info),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_configured_throughput) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_configured_throughput_valid)),
  0x1F,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_configured_throughput),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_svc_interest) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_svc_interest_valid)),
  0x20,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_embms_svc_interest),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_dl_thrpt_reporting_status_change) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_dl_thrpt_reporting_status_change_valid)),
  0x21,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_dl_thrpt_reporting_status_change),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_lte_attach_params) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_lte_attach_params_valid)),
  0x22,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_lte_attach_params),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_apn_op_reserved_pco_list) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_apn_op_reserved_pco_list_valid)),
  0x23,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_apn_op_reserved_pco_list),
  QMI_IDL_TYPE88(0, 10),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_apn_msisdn_change) - QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_apn_msisdn_change_valid)),
  0x24,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_indication_register_req_msg_v01, report_apn_msisdn_change),
  QMI_IDL_TYPE88(0, 14),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_3gpp_rab_reject_ind) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_3gpp_rab_reject_ind_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_3gpp_rab_reject_ind),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_pdn_throttle_info) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_pdn_throttle_info_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_pdn_throttle_info),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_ma_keep_alive_status) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_ma_keep_alive_status_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_ma_keep_alive_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_sps_flow_reg_result) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_sps_flow_reg_result_valid)),
  0x28,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_v2x_sps_flow_reg_result),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_sps_flow_update_result) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_sps_flow_update_result_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_v2x_sps_flow_update_result),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_sps_flow_dereg_result) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_sps_flow_dereg_result_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_v2x_sps_flow_dereg_result),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_service_sub_result) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_service_sub_result_valid)),
  0x2B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_v2x_service_sub_result),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_ran_asst_media_adapt_info) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_ran_asst_media_adapt_info_valid)),
  0x2C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_ran_asst_media_adapt_info),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_sps_scheduling_info) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_sps_scheduling_info_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_v2x_sps_scheduling_info),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_src_l2_info) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_src_l2_info_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_v2x_src_l2_info),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_bearer_type) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_bearer_type_valid)),
  0x2F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_bearer_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_capability_info) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_v2x_capability_info_valid)),
  0x30,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_v2x_capability_info),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_ladn_info) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_ladn_info_valid)),
  0x31,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_ladn_info),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_default_flow_rebind) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_default_flow_rebind_valid)),
  0x32,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_default_flow_rebind),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_lte_attach_failure_info) - QMI_IDL_OFFSET16RELATIVE(wds_indication_register_req_msg_v01, report_lte_attach_failure_info_valid)),
  0x33,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_indication_register_req_msg_v01, report_lte_attach_failure_info)
};

static const uint8_t wds_indication_register_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_indication_register_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_start_network_interface_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, primary_nbns_address_pref) - QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, primary_nbns_address_pref_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, primary_nbns_address_pref),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, secondary_nbns_address_pref) - QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, secondary_nbns_address_pref_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, secondary_nbns_address_pref),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, apn_name_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, ipv4_address_pref) - QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, ipv4_address_pref_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, ipv4_address_pref),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, authentication_preference) - QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, authentication_preference_valid)),
  0x16,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, username) - QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, username_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_start_network_interface_req_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, password) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, password_valid)),
  0x18,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, ip_family_preference) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, ip_family_preference_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, ip_family_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, technology_preference) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, technology_preference_valid)),
  0x30,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, technology_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, profile_index) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, profile_index_valid)),
  0x31,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, profile_index),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, profile_index_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, profile_index_3gpp2_valid)),
  0x32,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, profile_index_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, enable_autoconnect) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, enable_autoconnect_valid)),
  0x33,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, enable_autoconnect),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, ext_technology_preference) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, ext_technology_preference_valid)),
  0x34,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, ext_technology_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, call_type) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, call_type_valid)),
  0x35,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, call_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, handoff_context) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, handoff_context_valid)),
  0x36,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, handoff_context),
  QMI_IDL_TYPE88(0, 32),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, ips_id) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, ips_id_valid)),
  0x37,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, ips_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, apn_type) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, apn_type_valid)),
  0x38,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, apn_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, disallow_in_roaming) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, disallow_in_roaming_valid)),
  0x39,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, disallow_in_roaming),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, mo_exceptional_data_capability) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, mo_exceptional_data_capability_valid)),
  0x3A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, mo_exceptional_data_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, ep_id) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, ep_id_valid)),
  0x3B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, ep_id),
  QMI_IDL_TYPE88(2, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, bring_up_by_apn_name) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, bring_up_by_apn_name_valid)),
  0x3C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, bring_up_by_apn_name),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, bring_up_by_apn_type) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, bring_up_by_apn_type_valid)),
  0x3D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, bring_up_by_apn_type),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, apn_type_mask) - QMI_IDL_OFFSET16RELATIVE(wds_start_network_interface_req_msg_v01, apn_type_mask_valid)),
  0x3E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_start_network_interface_req_msg_v01, apn_type_mask)
};

static const uint8_t wds_start_network_interface_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, pkt_data_handle),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, call_end_reason) - QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, call_end_reason_valid)),
  0x10,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, call_end_reason),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, verbose_call_end_reason) - QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, verbose_call_end_reason_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, verbose_call_end_reason),
  QMI_IDL_TYPE88(0, 33),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, ep_id) - QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, ep_id_valid)),
  0x12,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, ep_id),
  QMI_IDL_TYPE88(2, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, mux_id) - QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, mux_id_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_start_network_interface_resp_msg_v01, mux_id)
};

static const uint8_t wds_stop_network_interface_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_stop_network_interface_req_msg_v01, pkt_data_handle),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_stop_network_interface_req_msg_v01, disable_autoconnect) - QMI_IDL_OFFSET8(wds_stop_network_interface_req_msg_v01, disable_autoconnect_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_stop_network_interface_req_msg_v01, disable_autoconnect),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_stop_network_interface_req_msg_v01, local_abort) - QMI_IDL_OFFSET8(wds_stop_network_interface_req_msg_v01, local_abort_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_stop_network_interface_req_msg_v01, local_abort)
};

static const uint8_t wds_stop_network_interface_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_stop_network_interface_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_get_pkt_srvc_status_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_req_msg_v01, ip_config_req_mask) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_req_msg_v01, ip_config_req_mask_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_req_msg_v01, ip_config_req_mask)
};

static const uint8_t wds_get_pkt_srvc_status_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, connection_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ip_family) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ip_family_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ip_family),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv4_address) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv4_address_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv6_addr) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv6_addr_valid)),
  0x12,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv6_addr),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv4_gateway_addr) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv4_gateway_addr_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv4_gateway_addr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv4_subnet_mask) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv4_subnet_mask_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv4_subnet_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv6_gateway_addr) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv6_gateway_addr_valid)),
  0x15,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, ipv6_gateway_addr),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, primary_DNS_IPv4_address) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, primary_DNS_IPv4_address_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, primary_DNS_IPv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, secondary_DNS_IPv4_address) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, secondary_DNS_IPv4_address_valid)),
  0x17,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, secondary_DNS_IPv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, primary_dns_IPv6_address) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, primary_dns_IPv6_address_valid)),
  0x18,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, primary_dns_IPv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, secondary_dns_IPv6_address) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, secondary_dns_IPv6_address_valid)),
  0x19,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, secondary_dns_IPv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, mtu) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, mtu_valid)),
  0x1A,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, mtu),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, operator_reserved_pco) - QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, operator_reserved_pco_valid)),
  0x1B,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_pkt_srvc_status_resp_msg_v01, operator_reserved_pco),
  QMI_IDL_TYPE88(0, 12)
};

static const uint8_t wds_pkt_srvc_status_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, status),
  QMI_IDL_TYPE88(0, 34),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, call_end_reason) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, call_end_reason_valid)),
  0x10,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, call_end_reason),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, verbose_call_end_reason) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, verbose_call_end_reason_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, verbose_call_end_reason),
  QMI_IDL_TYPE88(0, 33),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ip_family) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ip_family_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ip_family),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, tech_name) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, tech_name_valid)),
  0x13,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, tech_name),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, bearer_id) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, bearer_id_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, bearer_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, xlat_capable) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, xlat_capable_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, xlat_capable),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, changed_ip_config_mask) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, changed_ip_config_mask_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, changed_ip_config_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv4_address) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv4_address_valid)),
  0x17,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv6_addr) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv6_addr_valid)),
  0x18,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv6_addr),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv4_gateway_addr) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv4_gateway_addr_valid)),
  0x19,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv4_gateway_addr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv4_subnet_mask) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv4_subnet_mask_valid)),
  0x1A,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv4_subnet_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv6_gateway_addr) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv6_gateway_addr_valid)),
  0x1B,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, ipv6_gateway_addr),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, primary_DNS_IPv4_address) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, primary_DNS_IPv4_address_valid)),
  0x1C,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, primary_DNS_IPv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, secondary_DNS_IPv4_address) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, secondary_DNS_IPv4_address_valid)),
  0x1D,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, secondary_DNS_IPv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, primary_dns_IPv6_address) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, primary_dns_IPv6_address_valid)),
  0x1E,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, primary_dns_IPv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, secondary_dns_IPv6_address) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, secondary_dns_IPv6_address_valid)),
  0x1F,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, secondary_dns_IPv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, mtu) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, mtu_valid)),
  0x20,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, mtu),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, operator_reserved_pco) - QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, operator_reserved_pco_valid)),
  0x21,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pkt_srvc_status_ind_msg_v01, operator_reserved_pco),
  QMI_IDL_TYPE88(0, 12)
};

/*
 * wds_get_current_channel_rate_req_msg is empty
 * static const uint8_t wds_get_current_channel_rate_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_current_channel_rate_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_current_channel_rate_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_current_channel_rate_resp_msg_v01, rates),
  QMI_IDL_TYPE88(0, 35),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_current_channel_rate_resp_msg_v01, rates_ex) - QMI_IDL_OFFSET8(wds_get_current_channel_rate_resp_msg_v01, rates_ex_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_current_channel_rate_resp_msg_v01, rates_ex),
  QMI_IDL_TYPE88(0, 36)
};

static const uint8_t wds_get_pkt_statistics_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_req_msg_v01, stats_mask)
};

static const uint8_t wds_get_pkt_statistics_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_ok_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_ok_count_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_ok_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_ok_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_ok_count_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_ok_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_err_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_err_count_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_err_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_err_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_err_count_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_err_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_ofl_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_ofl_count_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_ofl_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_ofl_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_ofl_count_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_ofl_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_ok_bytes_count_valid)),
  0x19,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_ok_bytes_count_valid)),
  0x1A,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, last_call_tx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, last_call_tx_ok_bytes_count_valid)),
  0x1B,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, last_call_tx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, last_call_rx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, last_call_rx_ok_bytes_count_valid)),
  0x1C,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, last_call_rx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_dropped_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_dropped_count_valid)),
  0x1D,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, tx_dropped_count),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_dropped_count) - QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_dropped_count_valid)),
  0x1E,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_pkt_statistics_resp_msg_v01, rx_dropped_count)
};

static const uint8_t wds_go_dormant_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_go_dormant_req_msg_v01, delay_timer) - QMI_IDL_OFFSET8(wds_go_dormant_req_msg_v01, delay_timer_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_go_dormant_req_msg_v01, delay_timer),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_go_dormant_req_msg_v01, send_scri) - QMI_IDL_OFFSET8(wds_go_dormant_req_msg_v01, send_scri_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_go_dormant_req_msg_v01, send_scri)
};

static const uint8_t wds_go_dormant_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_go_dormant_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_go_active_req_msg is empty
 * static const uint8_t wds_go_active_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_go_active_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_go_active_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_create_profile_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, profile_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, profile_name) - QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, profile_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, profile_name),
  QMI_WDS_PROFILE_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, pdp_type) - QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, pdp_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, pdp_hdr_compression_type) - QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, pdp_hdr_compression_type_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, pdp_hdr_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, pdp_data_compression_type) - QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, pdp_data_compression_type_valid)),
  0x13,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, pdp_data_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, apn_name_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_create_profile_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_requested_qos_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, umts_requested_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_minimum_qos_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, umts_minimum_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, gprs_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, gprs_requested_qos_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, gprs_requested_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, gprs_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, gprs_minimum_qos_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, gprs_minimum_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, username) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, username_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, password) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, password_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, authentication_preference_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipv4_address_preference_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, ipv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pcscf_addr_using_pco_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdp_access_control_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdp_access_control_flag_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdp_access_control_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pcscf_addr_using_dhcp_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, im_cn_flag_valid)),
  0x22,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, tft_id1_params) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, tft_id1_params_valid)),
  0x23,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, tft_id1_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, tft_id2_params) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, tft_id2_params_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, tft_id2_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdp_context) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdp_context_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdp_context),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secondary_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secondary_flag_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, secondary_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_id) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_id_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, primary_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipv6_address_preference_valid)),
  0x28,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_requested_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_requested_qos_with_sig_ind_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, umts_requested_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_minimum_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_minimum_qos_with_sig_ind_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, umts_minimum_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_dns_ipv6_address_preference_valid)),
  0x2B,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secodnary_dns_ipv6_address_preference_valid)),
  0x2C,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, addr_allocation_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, addr_allocation_preference_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, addr_allocation_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, threegpp_lte_qos_params) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, threegpp_lte_qos_params_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, threegpp_lte_qos_params),
  QMI_IDL_TYPE88(0, 41),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_disabled_flag_valid)),
  0x2F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_inactivity_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_inactivity_timeout_valid)),
  0x30,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_inactivity_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_class_valid)),
  0x31,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_bearer) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_bearer_valid)),
  0x35,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, apn_bearer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, support_emergency_calls) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, support_emergency_calls_valid)),
  0x36,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, support_emergency_calls),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, op_pco_id_valid)),
  0x37,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pco_mcc_valid)),
  0x38,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pco_mnc_includes_pcs_digit_valid)),
  0x39,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, max_pdn_conn_per_block) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, max_pdn_conn_per_block_valid)),
  0x3A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, max_pdn_conn_per_block),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, max_pdn_conn_timer) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, max_pdn_conn_timer_valid)),
  0x3B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, max_pdn_conn_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_req_wait_interval) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_req_wait_interval_valid)),
  0x3C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_req_wait_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, app_user_data_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, app_user_data_3gpp_valid)),
  0x3D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, app_user_data_3gpp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, roaming_disallowed) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, roaming_disallowed_valid)),
  0x3E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, roaming_disallowed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_discon_wait_timer) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_discon_wait_timer_valid)),
  0x3F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_discon_wait_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, dns_addr_using_dhcp_valid)),
  0x40,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, lte_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, lte_roaming_pdp_type_valid)),
  0x41,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, lte_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, umts_roaming_pdp_type_valid)),
  0x42,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, umts_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag_valid)),
  0x43,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag_valid)),
  0x44,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, failure_timer_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, failure_timer_3gpp_valid)),
  0x45,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, failure_timer_3gpp),
  QMI_WDS_3GPP_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, override_home_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, override_home_pdp_type_valid)),
  0x46,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, override_home_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, op_reserved_pco_id_list) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, op_reserved_pco_id_list_valid)),
  0x47,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, op_reserved_pco_id_list),
  QMI_WDS_MAX_NUM_PCO_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, msisdn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, msisdn_flag_valid)),
  0x48,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, msisdn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, attach_wo_pdn) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, attach_wo_pdn_valid)),
  0x49,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, attach_wo_pdn),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_label_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_label_3gpp_valid)),
  0x4A,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_label_3gpp),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, eap_auth) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, eap_auth_valid)),
  0x4B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, eap_auth),
  QMI_IDL_TYPE88(0, 44),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, rqos_support) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, rqos_support_valid)),
  0x4C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, rqos_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, mhipv6_support) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, mhipv6_support_valid)),
  0x4D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, mhipv6_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, always_on_pdu) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, always_on_pdu_valid)),
  0x4E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, always_on_pdu),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_pcscf_addr_using_dhcp_valid)),
  0x7D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_dns_addr_using_dhcp_valid)),
  0x7E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_pdp_type_valid)),
  0x7F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_app_user_data) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_app_user_data_valid)),
  0x80,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_app_user_data),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_pco_mnc_includes_pcs_digit_valid)),
  0x81,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_pco_mcc_valid)),
  0x82,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_op_pco_id_valid)),
  0x83,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_auth_password_valid)),
  0x84,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_user_id_valid)),
  0x85,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_auth_protocol_valid)),
  0x86,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_is_pcscf_address_needed_valid)),
  0x87,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, linger_params) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, linger_params_valid)),
  0x88,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, linger_params),
  QMI_IDL_TYPE88(0, 43),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_secodnary_dns_ipv6_address_preference_valid)),
  0x89,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_primary_dns_ipv6_address_preference_valid)),
  0x8A,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_secondary_DNS_IPv4_address_preference_valid)),
  0x8B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_primary_DNS_IPv4_address_preference_valid)),
  0x8C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_apn_class_valid)),
  0x8D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, common_apn_disabled_flag_valid)),
  0x8E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, common_apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, persistent) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, persistent_valid)),
  0x8F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, persistent),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, negotiate_dns_server_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, negotiate_dns_server_preference_valid)),
  0x90,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, negotiate_dns_server_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ppp_session_close_timer_DO) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ppp_session_close_timer_DO_valid)),
  0x91,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, ppp_session_close_timer_DO),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ppp_session_close_timer_1x) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ppp_session_close_timer_1x_valid)),
  0x92,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, ppp_session_close_timer_1x),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, allow_linger) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, allow_linger_valid)),
  0x93,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, allow_linger),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, lcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, lcp_ack_timeout_valid)),
  0x94,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, lcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipcp_ack_timeout_valid)),
  0x95,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, ipcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, auth_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, auth_timeout_valid)),
  0x96,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, auth_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, lcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, lcp_creq_retry_count_valid)),
  0x97,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, lcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipcp_creq_retry_count_valid)),
  0x98,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, ipcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, auth_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, auth_retry_count_valid)),
  0x99,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, auth_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, auth_protocol_valid)),
  0x9A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, user_id) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, user_id_valid)),
  0x9B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, auth_password_valid)),
  0x9C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, data_rate) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, data_rate_valid)),
  0x9D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, data_rate),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, app_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, app_type_valid)),
  0x9E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, app_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, data_mode) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, data_mode_valid)),
  0x9F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, data_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, app_priority) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, app_priority_valid)),
  0xA0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, app_priority),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_string) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_string_valid)),
  0xA1,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_type_valid)),
  0xA2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, is_pcscf_address_needed_valid)),
  0xA3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_v4_dns_address_valid)),
  0xA4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, primary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secondary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secondary_v4_dns_address_valid)),
  0xA5,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, secondary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, primary_v6_dns_address_valid)),
  0xA6,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, primary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secondary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, secondary_v6_dns_address_valid)),
  0xA7,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, secondary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, rat_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, rat_type_valid)),
  0xA8,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, rat_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_enabled_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_enabled_3gpp2_valid)),
  0xA9,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, apn_enabled_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_inactivity_timeout_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_inactivity_timeout_3gpp2_valid)),
  0xAA,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_inactivity_timeout_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_class_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_class_3gpp2_valid)),
  0xAB,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, apn_class_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_level_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_level_auth_protocol_valid)),
  0xAD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_level_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_level_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_level_user_id_valid)),
  0xAE,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_level_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_level_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_level_auth_password_valid)),
  0xAF,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_level_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_label) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pdn_label_valid)),
  0xB0,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pdn_label),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, op_pco_id_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, op_pco_id_3gpp2_valid)),
  0xBD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, op_pco_id_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pco_mcc_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pco_mcc_3gpp2_valid)),
  0xBE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pco_mcc_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pco_mnc_includes_pcs_digit_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pco_mnc_includes_pcs_digit_3gpp2_valid)),
  0xBF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pco_mnc_includes_pcs_digit_3gpp2),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, failure_timer) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, failure_timer_valid)),
  0xC0,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, failure_timer),
  QMI_WDS_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, disallow_timer) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, disallow_timer_valid)),
  0xC1,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, disallow_timer),
  QMI_WDS_MAX_DISALLOW_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, app_user_data_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, app_user_data_3gpp2_valid)),
  0xC2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, app_user_data_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pcscf_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, pcscf_addr_using_dhcp_3gpp2_valid)),
  0xC3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, pcscf_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, dns_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, dns_addr_using_dhcp_3gpp2_valid)),
  0xC4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, dns_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_type_mask) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, apn_type_mask_valid)),
  0xDD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, apn_type_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, clat_enabled) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, clat_enabled_valid)),
  0xDE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, clat_enabled),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipv6_prefix_delegation) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_req_msg_v01, ipv6_prefix_delegation_valid)),
  0xDF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_req_msg_v01, ipv6_prefix_delegation)
};

static const uint8_t wds_create_profile_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_create_profile_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_create_profile_resp_msg_v01, profile),
  QMI_IDL_TYPE88(0, 45),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_create_profile_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_create_profile_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_modify_profile_settings_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, profile),
  QMI_IDL_TYPE88(0, 45),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, profile_name) - QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, profile_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, profile_name),
  QMI_WDS_PROFILE_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, pdp_type) - QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, pdp_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, pdp_hdr_compression_type) - QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, pdp_hdr_compression_type_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, pdp_hdr_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, pdp_data_compression_type) - QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, pdp_data_compression_type_valid)),
  0x13,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, pdp_data_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, apn_name_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_requested_qos_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, umts_requested_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_minimum_qos_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, umts_minimum_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, gprs_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, gprs_requested_qos_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, gprs_requested_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, gprs_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, gprs_minimum_qos_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, gprs_minimum_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, username) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, username_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, password) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, password_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, authentication_preference_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipv4_address_preference_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, ipv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pcscf_addr_using_pco_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdp_access_control_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdp_access_control_flag_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdp_access_control_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, im_cn_flag_valid)),
  0x22,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, tft_id1_params) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, tft_id1_params_valid)),
  0x23,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, tft_id1_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, tft_id2_params) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, tft_id2_params_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, tft_id2_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdp_context) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdp_context_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdp_context),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secondary_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secondary_flag_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, secondary_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_id) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_id_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, primary_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipv6_address_preference_valid)),
  0x28,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_requested_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_requested_qos_with_sig_ind_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, umts_requested_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_minimum_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_minimum_qos_with_sig_ind_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, umts_minimum_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_dns_ipv6_address_preference_valid)),
  0x2B,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secodnary_dns_ipv6_address_preference_valid)),
  0x2C,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, addr_allocation_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, addr_allocation_preference_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, addr_allocation_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, threegpp_lte_qos_params) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, threegpp_lte_qos_params_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, threegpp_lte_qos_params),
  QMI_IDL_TYPE88(0, 41),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_disabled_flag_valid)),
  0x2F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout_valid)),
  0x30,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_class_valid)),
  0x31,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_bearer) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_bearer_valid)),
  0x35,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, apn_bearer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, support_emergency_calls) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, support_emergency_calls_valid)),
  0x36,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, support_emergency_calls),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, op_pco_id_valid)),
  0x37,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pco_mcc_valid)),
  0x38,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit_valid)),
  0x39,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, max_pdn_conn_per_block) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, max_pdn_conn_per_block_valid)),
  0x3A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, max_pdn_conn_per_block),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, max_pdn_conn_timer) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, max_pdn_conn_timer_valid)),
  0x3B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, max_pdn_conn_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_req_wait_interval) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_req_wait_interval_valid)),
  0x3C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_req_wait_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, app_user_data_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, app_user_data_3gpp_valid)),
  0x3D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, app_user_data_3gpp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, roaming_disallowed) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, roaming_disallowed_valid)),
  0x3E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, roaming_disallowed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_discon_wait_timer) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_discon_wait_timer_valid)),
  0x3F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_discon_wait_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp_valid)),
  0x40,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, lte_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, lte_roaming_pdp_type_valid)),
  0x41,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, lte_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, umts_roaming_pdp_type_valid)),
  0x42,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, umts_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag_valid)),
  0x43,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag_valid)),
  0x44,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, failure_timer_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, failure_timer_3gpp_valid)),
  0x45,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, failure_timer_3gpp),
  QMI_WDS_3GPP_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, override_home_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, override_home_pdp_type_valid)),
  0x46,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, override_home_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, op_reserved_pco_id_list) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, op_reserved_pco_id_list_valid)),
  0x47,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, op_reserved_pco_id_list),
  QMI_WDS_MAX_NUM_PCO_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, msisdn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, msisdn_flag_valid)),
  0x48,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, msisdn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, attach_wo_pdn) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, attach_wo_pdn_valid)),
  0x49,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, attach_wo_pdn),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_label_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_label_3gpp_valid)),
  0x4A,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_label_3gpp),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, eap_auth) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, eap_auth_valid)),
  0x4B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, eap_auth),
  QMI_IDL_TYPE88(0, 44),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, rqos_support) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, rqos_support_valid)),
  0x4C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, rqos_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, mhipv6_support) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, mhipv6_support_valid)),
  0x4D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, mhipv6_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, always_on_pdu) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, always_on_pdu_valid)),
  0x4E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, always_on_pdu),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_pcscf_addr_using_dhcp_valid)),
  0x7D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_dns_addr_using_dhcp_valid)),
  0x7E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_pdp_type_valid)),
  0x7F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_app_user_data) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_app_user_data_valid)),
  0x80,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_app_user_data),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_pco_mnc_includes_pcs_digit_valid)),
  0x81,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_pco_mcc_valid)),
  0x82,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_op_pco_id_valid)),
  0x83,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_auth_password_valid)),
  0x84,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_user_id_valid)),
  0x85,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_auth_protocol_valid)),
  0x86,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_is_pcscf_address_needed_valid)),
  0x87,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, linger_params) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, linger_params_valid)),
  0x88,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, linger_params),
  QMI_IDL_TYPE88(0, 43),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_secodnary_dns_ipv6_address_preference_valid)),
  0x89,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_primary_dns_ipv6_address_preference_valid)),
  0x8A,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_secondary_DNS_IPv4_address_preference_valid)),
  0x8B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_primary_DNS_IPv4_address_preference_valid)),
  0x8C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_apn_class_valid)),
  0x8D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, common_apn_disabled_flag_valid)),
  0x8E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, common_apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, negotiate_dns_server_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, negotiate_dns_server_preference_valid)),
  0x90,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, negotiate_dns_server_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ppp_session_close_timer_DO) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ppp_session_close_timer_DO_valid)),
  0x91,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, ppp_session_close_timer_DO),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ppp_session_close_timer_1x) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ppp_session_close_timer_1x_valid)),
  0x92,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, ppp_session_close_timer_1x),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, allow_linger) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, allow_linger_valid)),
  0x93,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, allow_linger),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, lcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, lcp_ack_timeout_valid)),
  0x94,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, lcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipcp_ack_timeout_valid)),
  0x95,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, ipcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, auth_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, auth_timeout_valid)),
  0x96,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, auth_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, lcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, lcp_creq_retry_count_valid)),
  0x97,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, lcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipcp_creq_retry_count_valid)),
  0x98,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, ipcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, auth_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, auth_retry_count_valid)),
  0x99,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, auth_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, auth_protocol_valid)),
  0x9A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, user_id) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, user_id_valid)),
  0x9B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, auth_password_valid)),
  0x9C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, data_rate) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, data_rate_valid)),
  0x9D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, data_rate),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, app_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, app_type_valid)),
  0x9E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, app_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, data_mode) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, data_mode_valid)),
  0x9F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, data_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, app_priority) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, app_priority_valid)),
  0xA0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, app_priority),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_string) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_string_valid)),
  0xA1,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_type_valid)),
  0xA2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, is_pcscf_address_needed_valid)),
  0xA3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_v4_dns_address_valid)),
  0xA4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, primary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secondary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secondary_v4_dns_address_valid)),
  0xA5,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, secondary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, primary_v6_dns_address_valid)),
  0xA6,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, primary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secondary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, secondary_v6_dns_address_valid)),
  0xA7,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, secondary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, rat_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, rat_type_valid)),
  0xA8,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, rat_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_enabled_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_enabled_3gpp2_valid)),
  0xA9,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, apn_enabled_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout_3gpp2_valid)),
  0xAA,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_class_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_class_3gpp2_valid)),
  0xAB,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, apn_class_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_level_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_level_auth_protocol_valid)),
  0xAD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_level_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_level_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_level_user_id_valid)),
  0xAE,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_level_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_level_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_level_auth_password_valid)),
  0xAF,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_level_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_label) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pdn_label_valid)),
  0xB0,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pdn_label),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, op_pco_id_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, op_pco_id_3gpp2_valid)),
  0xBD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, op_pco_id_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pco_mcc_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pco_mcc_3gpp2_valid)),
  0xBE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pco_mcc_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit_3gpp2_valid)),
  0xBF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit_3gpp2),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, failure_timer) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, failure_timer_valid)),
  0xC0,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, failure_timer),
  QMI_WDS_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, disallow_timer) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, disallow_timer_valid)),
  0xC1,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, disallow_timer),
  QMI_WDS_MAX_DISALLOW_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, app_user_data_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, app_user_data_3gpp2_valid)),
  0xC2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, app_user_data_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp_3gpp2_valid)),
  0xC3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp_3gpp2_valid)),
  0xC4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_type_mask) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, apn_type_mask_valid)),
  0xDD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, apn_type_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, clat_enabled) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, clat_enabled_valid)),
  0xDE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, clat_enabled),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipv6_prefix_delegation) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_req_msg_v01, ipv6_prefix_delegation_valid)),
  0xDF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_req_msg_v01, ipv6_prefix_delegation)
};

static const uint8_t wds_modify_profile_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_profile_settings_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_modify_profile_settings_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_delete_profile_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_delete_profile_req_msg_v01, profile),
  QMI_IDL_TYPE88(0, 45)
};

static const uint8_t wds_delete_profile_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_delete_profile_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_delete_profile_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_delete_profile_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_delete_profile_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_get_profile_list_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, profile_type) - QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, profile_type_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, profile_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, search_type) - QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, search_type_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, search_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, apn_name_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, apn_type_mask) - QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, apn_type_mask_valid)),
  0x13,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_profile_list_req_msg_v01, apn_type_mask)
};

static const uint8_t wds_get_profile_list_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_list_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_profile_list_resp_msg_v01, profile_list),
  QMI_WDS_PROFILE_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_profile_list_resp_msg_v01, profile_list) - QMI_IDL_OFFSET8(wds_get_profile_list_resp_msg_v01, profile_list_len),
  QMI_IDL_TYPE88(0, 46),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_list_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_list_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_list_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_get_profile_settings_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_profile_settings_req_msg_v01, profile),
  QMI_IDL_TYPE88(0, 45)
};

static const uint8_t wds_get_profile_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, profile_name) - QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, profile_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, profile_name),
  QMI_WDS_PROFILE_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, pdp_type) - QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, pdp_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, pdp_hdr_compression_type) - QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, pdp_hdr_compression_type_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, pdp_hdr_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, pdp_data_compression_type) - QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, pdp_data_compression_type_valid)),
  0x13,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, pdp_data_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, apn_name_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_profile_settings_resp_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_requested_qos_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, umts_requested_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_minimum_qos_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, umts_minimum_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, gprs_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, gprs_requested_qos_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, gprs_requested_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, gprs_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, gprs_minimum_qos_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, gprs_minimum_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, username) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, username_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, password) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, password_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, authentication_preference_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipv4_address_preference_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, ipv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pcscf_addr_using_pco_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdp_access_control_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdp_access_control_flag_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdp_access_control_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pcscf_addr_using_dhcp_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, im_cn_flag_valid)),
  0x22,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, tft_id1_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, tft_id1_params_valid)),
  0x23,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, tft_id1_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, tft_id2_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, tft_id2_params_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, tft_id2_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdp_context) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdp_context_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdp_context),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secondary_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secondary_flag_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, secondary_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_id_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, primary_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipv6_address_preference_valid)),
  0x28,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_requested_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_requested_qos_with_sig_ind_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, umts_requested_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_minimum_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_minimum_qos_with_sig_ind_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, umts_minimum_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_dns_ipv6_address_preference_valid)),
  0x2B,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secodnary_dns_ipv6_address_preference_valid)),
  0x2C,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, addr_allocation_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, addr_allocation_preference_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, addr_allocation_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, threegpp_lte_qos_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, threegpp_lte_qos_params_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, threegpp_lte_qos_params),
  QMI_IDL_TYPE88(0, 41),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_disabled_flag_valid)),
  0x2F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_inactivity_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_inactivity_timeout_valid)),
  0x30,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_inactivity_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_class_valid)),
  0x31,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_bearer) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_bearer_valid)),
  0x35,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, apn_bearer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, support_emergency_calls) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, support_emergency_calls_valid)),
  0x36,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, support_emergency_calls),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, op_pco_id_valid)),
  0x37,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pco_mcc_valid)),
  0x38,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pco_mnc_includes_pcs_digit_valid)),
  0x39,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, max_pdn_conn_per_block) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, max_pdn_conn_per_block_valid)),
  0x3A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, max_pdn_conn_per_block),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, max_pdn_conn_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, max_pdn_conn_timer_valid)),
  0x3B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, max_pdn_conn_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_req_wait_interval) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_req_wait_interval_valid)),
  0x3C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_req_wait_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, app_user_data_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, app_user_data_3gpp_valid)),
  0x3D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, app_user_data_3gpp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, roaming_disallowed) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, roaming_disallowed_valid)),
  0x3E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, roaming_disallowed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_discon_wait_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_discon_wait_timer_valid)),
  0x3F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_discon_wait_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, dns_addr_using_dhcp_valid)),
  0x40,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, lte_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, lte_roaming_pdp_type_valid)),
  0x41,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, lte_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, umts_roaming_pdp_type_valid)),
  0x42,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, umts_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag_valid)),
  0x43,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag_valid)),
  0x44,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, failure_timer_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, failure_timer_3gpp_valid)),
  0x45,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, failure_timer_3gpp),
  QMI_WDS_3GPP_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, override_home_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, override_home_pdp_type_valid)),
  0x46,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, override_home_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, op_reserved_pco_id_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, op_reserved_pco_id_list_valid)),
  0x47,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, op_reserved_pco_id_list),
  QMI_WDS_MAX_NUM_PCO_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, msisdn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, msisdn_flag_valid)),
  0x48,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, msisdn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, attach_wo_pdn) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, attach_wo_pdn_valid)),
  0x49,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, attach_wo_pdn),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_label_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_label_3gpp_valid)),
  0x4A,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_label_3gpp),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, eap_auth) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, eap_auth_valid)),
  0x4B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, eap_auth),
  QMI_IDL_TYPE88(0, 44),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, rqos_support) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, rqos_support_valid)),
  0x4C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, rqos_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, mhipv6_support) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, mhipv6_support_valid)),
  0x4D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, mhipv6_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, always_on_pdu) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, always_on_pdu_valid)),
  0x4E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, always_on_pdu),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_pcscf_addr_using_dhcp_valid)),
  0x7D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_dns_addr_using_dhcp_valid)),
  0x7E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_pdp_type_valid)),
  0x7F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_app_user_data) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_app_user_data_valid)),
  0x80,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_app_user_data),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_pco_mnc_includes_pcs_digit_valid)),
  0x81,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_pco_mcc_valid)),
  0x82,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_op_pco_id_valid)),
  0x83,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_auth_password_valid)),
  0x84,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_user_id_valid)),
  0x85,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_auth_protocol_valid)),
  0x86,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_is_pcscf_address_needed_valid)),
  0x87,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, linger_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, linger_params_valid)),
  0x88,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, linger_params),
  QMI_IDL_TYPE88(0, 43),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_secodnary_dns_ipv6_address_preference_valid)),
  0x89,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_primary_dns_ipv6_address_preference_valid)),
  0x8A,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_secondary_DNS_IPv4_address_preference_valid)),
  0x8B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_primary_DNS_IPv4_address_preference_valid)),
  0x8C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_apn_class_valid)),
  0x8D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, common_apn_disabled_flag_valid)),
  0x8E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, common_apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, persistent) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, persistent_valid)),
  0x8F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, persistent),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, negotiate_dns_server_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, negotiate_dns_server_preference_valid)),
  0x90,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, negotiate_dns_server_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ppp_session_close_timer_DO) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ppp_session_close_timer_DO_valid)),
  0x91,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, ppp_session_close_timer_DO),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ppp_session_close_timer_1x) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ppp_session_close_timer_1x_valid)),
  0x92,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, ppp_session_close_timer_1x),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, allow_linger) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, allow_linger_valid)),
  0x93,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, allow_linger),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, lcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, lcp_ack_timeout_valid)),
  0x94,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, lcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipcp_ack_timeout_valid)),
  0x95,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, ipcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, auth_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, auth_timeout_valid)),
  0x96,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, auth_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, lcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, lcp_creq_retry_count_valid)),
  0x97,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, lcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipcp_creq_retry_count_valid)),
  0x98,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, ipcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, auth_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, auth_retry_count_valid)),
  0x99,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, auth_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, auth_protocol_valid)),
  0x9A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, user_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, user_id_valid)),
  0x9B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, auth_password_valid)),
  0x9C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, data_rate) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, data_rate_valid)),
  0x9D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, data_rate),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, app_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, app_type_valid)),
  0x9E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, app_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, data_mode) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, data_mode_valid)),
  0x9F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, data_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, app_priority) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, app_priority_valid)),
  0xA0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, app_priority),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_string) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_string_valid)),
  0xA1,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_type_valid)),
  0xA2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, is_pcscf_address_needed_valid)),
  0xA3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_v4_dns_address_valid)),
  0xA4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, primary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secondary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secondary_v4_dns_address_valid)),
  0xA5,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, secondary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, primary_v6_dns_address_valid)),
  0xA6,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, primary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secondary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, secondary_v6_dns_address_valid)),
  0xA7,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, secondary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, rat_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, rat_type_valid)),
  0xA8,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, rat_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_enabled_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_enabled_3gpp2_valid)),
  0xA9,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, apn_enabled_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_inactivity_timeout_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_inactivity_timeout_3gpp2_valid)),
  0xAA,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_inactivity_timeout_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_class_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_class_3gpp2_valid)),
  0xAB,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, apn_class_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_level_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_level_auth_protocol_valid)),
  0xAD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_level_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_level_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_level_user_id_valid)),
  0xAE,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_level_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_level_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_level_auth_password_valid)),
  0xAF,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_level_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_label) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pdn_label_valid)),
  0xB0,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pdn_label),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, op_pco_id_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, op_pco_id_3gpp2_valid)),
  0xBD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, op_pco_id_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pco_mcc_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pco_mcc_3gpp2_valid)),
  0xBE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pco_mcc_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pco_mnc_includes_pcs_digit_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pco_mnc_includes_pcs_digit_3gpp2_valid)),
  0xBF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pco_mnc_includes_pcs_digit_3gpp2),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, failure_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, failure_timer_valid)),
  0xC0,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, failure_timer),
  QMI_WDS_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, disallow_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, disallow_timer_valid)),
  0xC1,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, disallow_timer),
  QMI_WDS_MAX_DISALLOW_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, app_user_data_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, app_user_data_3gpp2_valid)),
  0xC2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, app_user_data_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pcscf_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, pcscf_addr_using_dhcp_3gpp2_valid)),
  0xC3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, pcscf_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, dns_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, dns_addr_using_dhcp_3gpp2_valid)),
  0xC4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, dns_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_type_mask) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, apn_type_mask_valid)),
  0xDD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, apn_type_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, clat_enabled) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, clat_enabled_valid)),
  0xDE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, clat_enabled),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipv6_prefix_delegation) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, ipv6_prefix_delegation_valid)),
  0xDF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, ipv6_prefix_delegation),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_get_default_settings_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_default_settings_req_msg_v01, profile_type)
};

static const uint8_t wds_get_default_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, profile_name) - QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, profile_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, profile_name),
  QMI_WDS_PROFILE_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, pdp_type) - QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, pdp_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, pdp_hdr_compression_type) - QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, pdp_hdr_compression_type_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, pdp_hdr_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, pdp_data_compression_type) - QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, pdp_data_compression_type_valid)),
  0x13,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, pdp_data_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, apn_name_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_default_settings_resp_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_requested_qos_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, umts_requested_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_minimum_qos_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, umts_minimum_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, gprs_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, gprs_requested_qos_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, gprs_requested_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, gprs_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, gprs_minimum_qos_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, gprs_minimum_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, username) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, username_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, password) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, password_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, authentication_preference_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipv4_address_preference_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, ipv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pcscf_addr_using_pco_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdp_access_control_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdp_access_control_flag_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdp_access_control_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pcscf_addr_using_dhcp_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, im_cn_flag_valid)),
  0x22,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, tft_id1_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, tft_id1_params_valid)),
  0x23,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, tft_id1_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, tft_id2_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, tft_id2_params_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, tft_id2_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdp_context) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdp_context_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdp_context),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secondary_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secondary_flag_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, secondary_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_id_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, primary_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipv6_address_preference_valid)),
  0x28,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_requested_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_requested_qos_with_sig_ind_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, umts_requested_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_minimum_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_minimum_qos_with_sig_ind_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, umts_minimum_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_dns_ipv6_address_preference_valid)),
  0x2B,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secodnary_dns_ipv6_address_preference_valid)),
  0x2C,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, addr_allocation_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, addr_allocation_preference_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, addr_allocation_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, threegpp_lte_qos_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, threegpp_lte_qos_params_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, threegpp_lte_qos_params),
  QMI_IDL_TYPE88(0, 41),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_disabled_flag_valid)),
  0x2F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_inactivity_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_inactivity_timeout_valid)),
  0x30,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_inactivity_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_class_valid)),
  0x31,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_bearer) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_bearer_valid)),
  0x35,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, apn_bearer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, support_emergency_calls) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, support_emergency_calls_valid)),
  0x36,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, support_emergency_calls),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, op_pco_id_valid)),
  0x37,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pco_mcc_valid)),
  0x38,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pco_mnc_includes_pcs_digit_valid)),
  0x39,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, max_pdn_conn_per_block) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, max_pdn_conn_per_block_valid)),
  0x3A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, max_pdn_conn_per_block),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, max_pdn_conn_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, max_pdn_conn_timer_valid)),
  0x3B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, max_pdn_conn_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_req_wait_interval) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_req_wait_interval_valid)),
  0x3C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_req_wait_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, app_user_data_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, app_user_data_3gpp_valid)),
  0x3D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, app_user_data_3gpp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, roaming_disallowed) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, roaming_disallowed_valid)),
  0x3E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, roaming_disallowed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_discon_wait_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_discon_wait_timer_valid)),
  0x3F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_discon_wait_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, dns_addr_using_dhcp_valid)),
  0x40,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, lte_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, lte_roaming_pdp_type_valid)),
  0x41,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, lte_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, umts_roaming_pdp_type_valid)),
  0x42,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, umts_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag_valid)),
  0x43,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag_valid)),
  0x44,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, failure_timer_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, failure_timer_3gpp_valid)),
  0x45,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, failure_timer_3gpp),
  QMI_WDS_3GPP_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, override_home_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, override_home_pdp_type_valid)),
  0x46,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, override_home_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, op_reserved_pco_id_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, op_reserved_pco_id_list_valid)),
  0x47,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, op_reserved_pco_id_list),
  QMI_WDS_MAX_NUM_PCO_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, msisdn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, msisdn_flag_valid)),
  0x48,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, msisdn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, attach_wo_pdn) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, attach_wo_pdn_valid)),
  0x49,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, attach_wo_pdn),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_label_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_label_3gpp_valid)),
  0x4A,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_label_3gpp),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, eap_auth) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, eap_auth_valid)),
  0x4B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, eap_auth),
  QMI_IDL_TYPE88(0, 44),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, rqos_support) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, rqos_support_valid)),
  0x4C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, rqos_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, mhipv6_support) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, mhipv6_support_valid)),
  0x4D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, mhipv6_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, always_on_pdu) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, always_on_pdu_valid)),
  0x4E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, always_on_pdu),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_pcscf_addr_using_dhcp_valid)),
  0x7D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_dns_addr_using_dhcp_valid)),
  0x7E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_pdp_type_valid)),
  0x7F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_app_user_data) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_app_user_data_valid)),
  0x80,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_app_user_data),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_pco_mnc_includes_pcs_digit_valid)),
  0x81,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_pco_mcc_valid)),
  0x82,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_op_pco_id_valid)),
  0x83,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_auth_password_valid)),
  0x84,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_user_id_valid)),
  0x85,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_auth_protocol_valid)),
  0x86,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_is_pcscf_address_needed_valid)),
  0x87,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, linger_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, linger_params_valid)),
  0x88,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, linger_params),
  QMI_IDL_TYPE88(0, 43),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_secodnary_dns_ipv6_address_preference_valid)),
  0x89,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_primary_dns_ipv6_address_preference_valid)),
  0x8A,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_secondary_DNS_IPv4_address_preference_valid)),
  0x8B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_primary_DNS_IPv4_address_preference_valid)),
  0x8C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_apn_class_valid)),
  0x8D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, common_apn_disabled_flag_valid)),
  0x8E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, common_apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, negotiate_dns_server_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, negotiate_dns_server_preference_valid)),
  0x90,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, negotiate_dns_server_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ppp_session_close_timer_DO) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ppp_session_close_timer_DO_valid)),
  0x91,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, ppp_session_close_timer_DO),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ppp_session_close_timer_1x) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ppp_session_close_timer_1x_valid)),
  0x92,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, ppp_session_close_timer_1x),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, allow_linger) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, allow_linger_valid)),
  0x93,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, allow_linger),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, lcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, lcp_ack_timeout_valid)),
  0x94,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, lcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipcp_ack_timeout_valid)),
  0x95,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, ipcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, auth_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, auth_timeout_valid)),
  0x96,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, auth_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, lcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, lcp_creq_retry_count_valid)),
  0x97,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, lcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipcp_creq_retry_count_valid)),
  0x98,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, ipcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, auth_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, auth_retry_count_valid)),
  0x99,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, auth_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, auth_protocol_valid)),
  0x9A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, user_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, user_id_valid)),
  0x9B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, auth_password_valid)),
  0x9C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, data_rate) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, data_rate_valid)),
  0x9D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, data_rate),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, app_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, app_type_valid)),
  0x9E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, app_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, data_mode) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, data_mode_valid)),
  0x9F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, data_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, app_priority) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, app_priority_valid)),
  0xA0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, app_priority),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_string) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_string_valid)),
  0xA1,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_type_valid)),
  0xA2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, is_pcscf_address_needed_valid)),
  0xA3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_v4_dns_address_valid)),
  0xA4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, primary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secondary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secondary_v4_dns_address_valid)),
  0xA5,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, secondary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, primary_v6_dns_address_valid)),
  0xA6,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, primary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secondary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, secondary_v6_dns_address_valid)),
  0xA7,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, secondary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, rat_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, rat_type_valid)),
  0xA8,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, rat_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_enabled_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_enabled_3gpp2_valid)),
  0xA9,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, apn_enabled_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_inactivity_timeout_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_inactivity_timeout_3gpp2_valid)),
  0xAA,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_inactivity_timeout_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_class_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_class_3gpp2_valid)),
  0xAB,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, apn_class_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_level_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_level_auth_protocol_valid)),
  0xAD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_level_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_level_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_level_user_id_valid)),
  0xAE,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_level_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_level_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_level_auth_password_valid)),
  0xAF,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_level_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_label) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pdn_label_valid)),
  0xB0,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pdn_label),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, op_pco_id_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, op_pco_id_3gpp2_valid)),
  0xBD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, op_pco_id_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pco_mcc_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pco_mcc_3gpp2_valid)),
  0xBE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pco_mcc_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pco_mnc_includes_pcs_digit_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pco_mnc_includes_pcs_digit_3gpp2_valid)),
  0xBF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pco_mnc_includes_pcs_digit_3gpp2),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, failure_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, failure_timer_valid)),
  0xC0,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, failure_timer),
  QMI_WDS_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, disallow_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, disallow_timer_valid)),
  0xC1,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, disallow_timer),
  QMI_WDS_MAX_DISALLOW_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, app_user_data_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, app_user_data_3gpp2_valid)),
  0xC2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, app_user_data_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pcscf_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, pcscf_addr_using_dhcp_3gpp2_valid)),
  0xC3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, pcscf_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, dns_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, dns_addr_using_dhcp_3gpp2_valid)),
  0xC4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, dns_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_type_mask) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, apn_type_mask_valid)),
  0xDD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, apn_type_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, clat_enabled) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, clat_enabled_valid)),
  0xDE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, clat_enabled),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipv6_prefix_delegation) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, ipv6_prefix_delegation_valid)),
  0xDF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, ipv6_prefix_delegation),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET16RELATIVE(wds_get_default_settings_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_default_settings_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_get_runtime_settings_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_runtime_settings_req_msg_v01, requested_settings) - QMI_IDL_OFFSET8(wds_get_runtime_settings_req_msg_v01, requested_settings_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_runtime_settings_req_msg_v01, requested_settings)
};

static const uint8_t wds_get_runtime_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, profile_name) - QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, profile_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, profile_name),
  QMI_WDS_PROFILE_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, pdp_type) - QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, pdp_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, apn_name_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_runtime_settings_resp_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, umts_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, umts_requested_qos_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, umts_requested_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, gprs_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, gprs_requested_qos_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, gprs_requested_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, username) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, username_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, authentication_preference_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv4_address_preference_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, ipv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, profile) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, profile_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, profile),
  QMI_IDL_TYPE88(0, 47),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv4_gateway_addr) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv4_gateway_addr_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, ipv4_gateway_addr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv4_subnet_mask) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv4_subnet_mask_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, ipv4_subnet_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, pcscf_addr_using_pco_valid)),
  0x22,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, pcscf_ipv4_server_addr_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, pcscf_ipv4_server_addr_list_valid)),
  0x23,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, pcscf_ipv4_server_addr_list),
  QMI_IDL_TYPE88(0, 49),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, fqdn) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, fqdn_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, fqdn),
  QMI_IDL_TYPE88(0, 51),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv6_addr) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv6_addr_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, ipv6_addr),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv6_gateway_addr) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ipv6_gateway_addr_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, ipv6_gateway_addr),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, primary_dns_IPv6_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, primary_dns_IPv6_address_valid)),
  0x27,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, primary_dns_IPv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, secondary_dns_IPv6_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, secondary_dns_IPv6_address_valid)),
  0x28,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, secondary_dns_IPv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, mtu) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, mtu_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, mtu),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, domain_name_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, domain_name_list_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, domain_name_list),
  QMI_IDL_TYPE88(0, 53),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ip_family) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, ip_family_valid)),
  0x2B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, ip_family),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, im_cn_flag_valid)),
  0x2C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, technology_name) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, technology_name_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, technology_name),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, pcscf_ipv6_server_addr_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, pcscf_ipv6_server_addr_list_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, pcscf_ipv6_server_addr_list),
  QMI_IDL_TYPE88(0, 55),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, operator_reserved_pco) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, operator_reserved_pco_valid)),
  0x2F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, operator_reserved_pco),
  QMI_IDL_TYPE88(0, 12),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, operator_reserved_pco_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, operator_reserved_pco_list_valid)),
  0x30,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, operator_reserved_pco_list),
  QMI_IDL_TYPE88(0, 8),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, msisdn) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, msisdn_valid)),
  0x31,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_runtime_settings_resp_msg_v01, msisdn),
  QMI_WDS_MSISDN_INFO_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, msisdn) - QMI_IDL_OFFSET16RELATIVE(wds_get_runtime_settings_resp_msg_v01, msisdn_len)
};

static const uint8_t wds_set_mip_mode_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_mip_mode_req_msg_v01, mip_mode)
};

static const uint8_t wds_set_mip_mode_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_mip_mode_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_mip_mode_req_msg is empty
 * static const uint8_t wds_get_mip_mode_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_mip_mode_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_mip_mode_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_mip_mode_resp_msg_v01, mip_mode)
};

/*
 * wds_get_dormancy_status_req_msg is empty
 * static const uint8_t wds_get_dormancy_status_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_dormancy_status_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_dormancy_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_dormancy_status_resp_msg_v01, dormancy_status)
};

/*
 * wds_get_autoconnect_setting_req_msg is empty
 * static const uint8_t wds_get_autoconnect_setting_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_autoconnect_setting_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_autoconnect_setting_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_autoconnect_setting_resp_msg_v01, autoconnect_setting),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_autoconnect_setting_resp_msg_v01, autoconnect_roam_setting) - QMI_IDL_OFFSET8(wds_get_autoconnect_setting_resp_msg_v01, autoconnect_roam_setting_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_autoconnect_setting_resp_msg_v01, autoconnect_roam_setting)
};

/*
 * wds_get_call_duration_req_msg is empty
 * static const uint8_t wds_get_call_duration_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_call_duration_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, call_duration),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, last_call_duration) - QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, last_call_duration_valid)),
  0x10,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, last_call_duration),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, call_active_duration) - QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, call_active_duration_valid)),
  0x11,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, call_active_duration),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, last_call_active_duration) - QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, last_call_active_duration_valid)),
  0x12,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_call_duration_resp_msg_v01, last_call_active_duration)
};

/*
 * wds_get_data_bearer_technology_req_msg is empty
 * static const uint8_t wds_get_data_bearer_technology_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_data_bearer_technology_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_bearer_technology_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_data_bearer_technology_resp_msg_v01, data_bearer_tech),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_bearer_technology_resp_msg_v01, last_call_data_bearer_tech) - QMI_IDL_OFFSET8(wds_get_data_bearer_technology_resp_msg_v01, last_call_data_bearer_tech_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_data_bearer_technology_resp_msg_v01, last_call_data_bearer_tech)
};

static const uint8_t wds_get_dun_call_info_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_connection_status) - QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_connection_status_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_connection_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_stats) - QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_stats_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_stats),
  QMI_IDL_TYPE88(0, 56),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_dormancy_status) - QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_dormancy_status_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_dormancy_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_data_bearer_tech) - QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_data_bearer_tech_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_data_bearer_tech),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_channel_rate) - QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_channel_rate_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_req_msg_v01, report_channel_rate)
};

static const uint8_t wds_get_dun_call_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, connection_status) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, connection_status_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, connection_status),
  QMI_IDL_TYPE88(0, 57),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, call_end_reason) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, call_end_reason_valid)),
  0x11,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, call_end_reason),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, tx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, tx_ok_bytes_count_valid)),
  0x12,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, tx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, rx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, rx_ok_bytes_count_valid)),
  0x13,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, rx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, dormancy_status) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, dormancy_status_valid)),
  0x14,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, dormancy_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, data_bearer_tech) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, data_bearer_tech_valid)),
  0x15,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, data_bearer_tech),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, channel_rate) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, channel_rate_valid)),
  0x16,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, channel_rate),
  QMI_IDL_TYPE88(0, 35),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, last_call_tx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, last_call_tx_ok_bytes_count_valid)),
  0x17,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, last_call_tx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, last_call_rx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, last_call_rx_ok_bytes_count_valid)),
  0x18,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, last_call_rx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, modem_call_duration_active) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, modem_call_duration_active_valid)),
  0x19,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, modem_call_duration_active),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, last_call_data_bearer_tech) - QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, last_call_data_bearer_tech_valid)),
  0x20,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_dun_call_info_resp_msg_v01, last_call_data_bearer_tech)
};

static const uint8_t wds_dun_call_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, modem_connection_status) - QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, modem_connection_status_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, modem_connection_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, call_end_reason) - QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, call_end_reason_valid)),
  0x11,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, call_end_reason),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, tx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, tx_ok_bytes_count_valid)),
  0x12,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, tx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, rx_ok_bytes_count) - QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, rx_ok_bytes_count_valid)),
  0x13,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, rx_ok_bytes_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, dormancy_status) - QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, dormancy_status_valid)),
  0x14,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, dormancy_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, data_beare_technology) - QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, data_beare_technology_valid)),
  0x15,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, data_beare_technology),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, channel_rate) - QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, channel_rate_valid)),
  0x16,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_dun_call_info_ind_msg_v01, channel_rate),
  QMI_IDL_TYPE88(0, 23)
};

/*
 * wds_get_active_mip_profile_req_msg is empty
 * static const uint8_t wds_get_active_mip_profile_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_active_mip_profile_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_active_mip_profile_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_active_mip_profile_resp_msg_v01, profile_index)
};

static const uint8_t wds_set_active_mip_profile_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_active_mip_profile_req_msg_v01, profile_identifier),
  QMI_IDL_TYPE88(0, 58)
};

static const uint8_t wds_set_active_mip_profile_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_active_mip_profile_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_read_mip_profile_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_read_mip_profile_req_msg_v01, profile_index)
};

static const uint8_t wds_read_mip_profile_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, profile_state) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, profile_state_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, profile_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, home_address) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, home_address_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, home_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, home_agent_priv) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, home_agent_priv_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, home_agent_priv),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, home_agent_sec) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, home_agent_sec_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, home_agent_sec),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, rev_tun_pref) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, rev_tun_pref_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, rev_tun_pref),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, nai) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, nai_valid)),
  0x15,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, nai),
  QMI_WDS_MAX_NAI_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_ha_spi) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_ha_spi_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_ha_spi),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_aaa_spi) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_aaa_spi_valid)),
  0x17,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_aaa_spi),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_ha_key_state) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_ha_key_state_valid)),
  0x1A,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_ha_key_state),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_aaa_key_state) - QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_aaa_key_state_valid)),
  0x1B,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_read_mip_profile_resp_msg_v01, mn_aaa_key_state)
};

static const uint8_t wds_modify_mip_profile_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, profile_identifier),
  QMI_IDL_TYPE88(0, 58),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, profile_state) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, profile_state_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, profile_state),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, home_address) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, home_address_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, home_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, home_agent_priv) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, home_agent_priv_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, home_agent_priv),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, home_agent_sec) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, home_agent_sec_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, home_agent_sec),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, rev_tun_pref) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, rev_tun_pref_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, rev_tun_pref),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, nai) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, nai_valid)),
  0x15,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, nai),
  QMI_WDS_MAX_NAI_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_ha_spi) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_ha_spi_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_ha_spi),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_aaa_spi) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_aaa_spi_valid)),
  0x17,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_aaa_spi),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_ha_key) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_ha_key_valid)),
  0x18,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_ha_key),
  QMI_WDS_MAX_MN_HA_KEY_LEN_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_aaa_key) - QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_aaa_key_valid)),
  0x19,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_req_msg_v01, mn_aaa_key),
  QMI_WDS_MAX_MN_AAA_KEY_LEN_V01
};

static const uint8_t wds_modify_mip_profile_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_modify_mip_profile_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_mip_settings_req_msg is empty
 * static const uint8_t wds_get_mip_settings_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_mip_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_mode) - QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_mode_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_reg_retry_count) - QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_reg_retry_count_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_reg_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_reg_retry_interval) - QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_reg_retry_interval_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_reg_retry_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_re_reg_peroid) - QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_re_reg_peroid_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_re_reg_peroid),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_re_reg_if_traf) - QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_re_reg_if_traf_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_re_reg_if_traf),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_qc_handoff) - QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_qc_handoff_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_qc_handoff),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_rfc2002bis) - QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_rfc2002bis_valid)),
  0x16,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_mip_settings_resp_msg_v01, mip_rfc2002bis)
};

static const uint8_t wds_set_mip_settings_req_msg_data_v01[] = {
  0x01,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, spc),
  QMI_WDS_SPC_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_mode) - QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_mode_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_reg_retry_count) - QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_reg_retry_count_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_reg_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_reg_retry_interval) - QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_reg_retry_interval_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_reg_retry_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_re_reg_peroid) - QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_re_reg_peroid_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_re_reg_peroid),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_re_reg_if_traf) - QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_re_reg_if_traf_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_re_reg_if_traf),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_qc_handoff) - QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_qc_handoff_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_qc_handoff),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_rfc2002bis) - QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_rfc2002bis_valid)),
  0x16,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_mip_settings_req_msg_v01, mip_rfc2002bis)
};

static const uint8_t wds_set_mip_settings_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_mip_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_last_mip_status_req_msg is empty
 * static const uint8_t wds_get_last_mip_status_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_last_mip_status_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_last_mip_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_last_mip_status_resp_msg_v01, mip_error)
};

/*
 * wds_get_current_data_bearer_technology_req_msg is empty
 * static const uint8_t wds_get_current_data_bearer_technology_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_current_data_bearer_technology_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_current_data_bearer_technology_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_current_data_bearer_technology_resp_msg_v01, current_bearer_tech),
  QMI_IDL_TYPE88(0, 25),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_current_data_bearer_technology_resp_msg_v01, last_bearer_tech) - QMI_IDL_OFFSET8(wds_get_current_data_bearer_technology_resp_msg_v01, last_bearer_tech_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_current_data_bearer_technology_resp_msg_v01, last_bearer_tech),
  QMI_IDL_TYPE88(0, 25)
};

/*
 * wds_call_history_list_req_msg is empty
 * static const uint8_t wds_call_history_list_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_call_history_list_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_call_history_list_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_call_history_list_resp_msg_v01, full_call_history) - QMI_IDL_OFFSET8(wds_call_history_list_resp_msg_v01, full_call_history_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_call_history_list_resp_msg_v01, full_call_history),
  QMI_IDL_TYPE88(0, 61),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_call_history_list_resp_msg_v01, id_only_call_history) - QMI_IDL_OFFSET16RELATIVE(wds_call_history_list_resp_msg_v01, id_only_call_history_valid)),
  0x11,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_call_history_list_resp_msg_v01, id_only_call_history),
  QMI_IDL_TYPE88(0, 63)
};

static const uint8_t wds_call_history_read_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_call_history_read_req_msg_v01, call_record_id)
};

static const uint8_t wds_call_history_read_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_call_history_read_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_call_history_read_resp_msg_v01, call_history_record),
  QMI_IDL_TYPE88(0, 59)
};

/*
 * wds_call_history_delete_req_msg is empty
 * static const uint8_t wds_call_history_delete_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_call_history_delete_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_call_history_delete_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_call_history_max_size_req_msg is empty
 * static const uint8_t wds_call_history_max_size_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_call_history_max_size_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_call_history_max_size_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_call_history_max_size_resp_msg_v01, max_size)
};

static const uint8_t wds_get_default_profile_num_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_default_profile_num_req_msg_v01, profile),
  QMI_IDL_TYPE88(0, 64)
};

static const uint8_t wds_get_default_profile_num_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_default_profile_num_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_default_profile_num_resp_msg_v01, profile_index),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_default_profile_num_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_get_default_profile_num_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_default_profile_num_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_set_default_profile_num_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_default_profile_num_req_msg_v01, profile_identifier),
  QMI_IDL_TYPE88(0, 65)
};

static const uint8_t wds_set_default_profile_num_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_default_profile_num_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_default_profile_num_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_set_default_profile_num_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_default_profile_num_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_reset_profile_to_default_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reset_profile_to_default_req_msg_v01, profile_identifier),
  QMI_IDL_TYPE88(0, 45)
};

static const uint8_t wds_reset_profile_to_default_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reset_profile_to_default_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reset_profile_to_default_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_reset_profile_to_default_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_reset_profile_to_default_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_reset_profile_param_to_invalid_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reset_profile_param_to_invalid_req_msg_v01, profile_param),
  QMI_IDL_TYPE88(0, 66)
};

static const uint8_t wds_reset_profile_param_to_invalid_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reset_profile_param_to_invalid_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reset_profile_param_to_invalid_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_reset_profile_param_to_invalid_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_reset_profile_param_to_invalid_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_set_client_ip_family_pref_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_client_ip_family_pref_req_msg_v01, ip_preference)
};

static const uint8_t wds_set_client_ip_family_pref_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_client_ip_family_pref_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_fmc_set_tunnel_params_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_fmc_set_tunnel_params_req_msg_v01, tunnel_params),
  QMI_IDL_TYPE88(0, 67),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_fmc_set_tunnel_params_req_msg_v01, ipv4_sock_addr) - QMI_IDL_OFFSET8(wds_fmc_set_tunnel_params_req_msg_v01, ipv4_sock_addr_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_fmc_set_tunnel_params_req_msg_v01, ipv4_sock_addr),
  QMI_WDS_IPV4_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_fmc_set_tunnel_params_req_msg_v01, ipv6_sock_addr) - QMI_IDL_OFFSET8(wds_fmc_set_tunnel_params_req_msg_v01, ipv6_sock_addr_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_fmc_set_tunnel_params_req_msg_v01, ipv6_sock_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01
};

static const uint8_t wds_fmc_set_tunnel_params_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_fmc_set_tunnel_params_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_fmc_clear_tunnel_params_req_msg is empty
 * static const uint8_t wds_fmc_clear_tunnel_params_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_fmc_clear_tunnel_params_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_fmc_clear_tunnel_params_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_fmc_get_tunnel_params_req_msg is empty
 * static const uint8_t wds_fmc_get_tunnel_params_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_fmc_get_tunnel_params_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, tunnel_params) - QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, tunnel_params_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, tunnel_params),
  QMI_IDL_TYPE88(0, 67),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, ipv4_sock_addr) - QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, ipv4_sock_addr_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, ipv4_sock_addr),
  QMI_WDS_IPV4_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, ipv6_sock_addr) - QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, ipv6_sock_addr_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_fmc_get_tunnel_params_resp_msg_v01, ipv6_sock_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01
};

static const uint8_t wds_set_autoconnect_settings_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_autoconnect_settings_req_msg_v01, autoconnect_setting),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_autoconnect_settings_req_msg_v01, autoconnect_roam_setting) - QMI_IDL_OFFSET8(wds_set_autoconnect_settings_req_msg_v01, autoconnect_roam_setting_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_autoconnect_settings_req_msg_v01, autoconnect_roam_setting)
};

static const uint8_t wds_set_autoconnect_settings_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_autoconnect_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_dns_settings_req_msg is empty
 * static const uint8_t wds_get_dns_settings_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_dns_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, primary_dns_ipv4_address) - QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, primary_dns_ipv4_address_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, primary_dns_ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, secondary_dns_ipv4_address) - QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, secondary_dns_ipv4_address_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, secondary_dns_ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, primary_dns_ipv6_address) - QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, primary_dns_ipv6_address_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, primary_dns_ipv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, secondary_dns_ipv6_address) - QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, secondary_dns_ipv6_address_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_dns_settings_resp_msg_v01, secondary_dns_ipv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01
};

static const uint8_t wds_set_dns_settings_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, primary_dns_ipv4_address) - QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, primary_dns_ipv4_address_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, primary_dns_ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, secondary_dns_ipv4_address) - QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, secondary_dns_ipv4_address_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, secondary_dns_ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, primary_dns_ipv6_address) - QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, primary_dns_ipv6_address_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, primary_dns_ipv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, secondary_dns_ipv6_address) - QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, secondary_dns_ipv6_address_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_dns_settings_req_msg_v01, secondary_dns_ipv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01
};

static const uint8_t wds_set_dns_settings_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_dns_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_pre_dormancy_cdma_settings_req_msg is empty
 * static const uint8_t wds_get_pre_dormancy_cdma_settings_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_pre_dormancy_cdma_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_pre_dormancy_cdma_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_pre_dormancy_cdma_settings_resp_msg_v01, pre_dormancy_settings),
  QMI_IDL_TYPE88(0, 68)
};

static const uint8_t wds_set_cam_timer_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_cam_timer_req_msg_v01, cam_timer)
};

static const uint8_t wds_set_cam_timer_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_cam_timer_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_cam_timer_req_msg is empty
 * static const uint8_t wds_get_cam_timer_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_cam_timer_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_cam_timer_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_cam_timer_resp_msg_v01, cam_timer)
};

static const uint8_t wds_set_scrm_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_scrm_req_msg_v01, scrm)
};

static const uint8_t wds_set_scrm_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_scrm_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_scrm_req_msg is empty
 * static const uint8_t wds_get_scrm_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_scrm_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_scrm_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_scrm_resp_msg_v01, scrm)
};

static const uint8_t wds_set_rdud_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_rdud_req_msg_v01, rdud)
};

static const uint8_t wds_set_rdud_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_rdud_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_rdud_req_msg is empty
 * static const uint8_t wds_get_rdud_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_rdud_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_rdud_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_rdud_resp_msg_v01, rdud)
};

/*
 * wds_get_sip_mip_call_type_req_msg is empty
 * static const uint8_t wds_get_sip_mip_call_type_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_sip_mip_call_type_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_sip_mip_call_type_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_sip_mip_call_type_resp_msg_v01, call_type)
};

static const uint8_t wds_set_evdo_page_monitor_period_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_evdo_page_monitor_period_req_msg_v01, evdo_page_monitor_period)
};

static const uint8_t wds_set_evdo_page_monitor_period_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_evdo_page_monitor_period_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_evdo_page_monitor_period_result_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_evdo_page_monitor_period_result_ind_msg_v01, status)
};

static const uint8_t wds_set_evdo_force_long_sleep_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_evdo_force_long_sleep_req_msg_v01, force_evdo_long_sleep)
};

static const uint8_t wds_set_evdo_force_long_sleep_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_evdo_force_long_sleep_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_evdo_page_monitor_period_req_msg is empty
 * static const uint8_t wds_get_evdo_page_monitor_period_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_evdo_page_monitor_period_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_evdo_page_monitor_period_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_evdo_page_monitor_period_resp_msg_v01, evdo_page_monitor_period),
  QMI_IDL_TYPE88(0, 26)
};

/*
 * wds_get_call_throttle_info_req_msg is empty
 * static const uint8_t wds_get_call_throttle_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_call_throttle_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_call_throttle_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_call_throttle_info_resp_msg_v01, call_throttled),
  QMI_IDL_TYPE88(0, 69)
};

static const uint8_t wds_get_nsapi_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_nsapi_req_msg_v01, apn),
  QMI_WDS_APN_NAME_MAX_V01
};

static const uint8_t wds_get_nsapi_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_nsapi_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_nsapi_resp_msg_v01, nsapi),
  QMI_WDS_MAX_BEARER_CONTEXT_V01,
  QMI_IDL_OFFSET8(wds_get_nsapi_resp_msg_v01, nsapi) - QMI_IDL_OFFSET8(wds_get_nsapi_resp_msg_v01, nsapi_len)
};

static const uint8_t wds_set_dun_ctrl_pref_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_dun_ctrl_pref_req_msg_v01, dun_control_preference),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_dun_ctrl_pref_req_msg_v01, dun_allow_preference) - QMI_IDL_OFFSET8(wds_set_dun_ctrl_pref_req_msg_v01, dun_allow_preference_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_dun_ctrl_pref_req_msg_v01, dun_allow_preference)
};

static const uint8_t wds_set_dun_ctrl_pref_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_dun_ctrl_pref_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_dun_ctrl_info_req_msg is empty
 * static const uint8_t wds_get_dun_ctrl_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_dun_ctrl_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, dun_control_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, allow_preference) - QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, allow_preference_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, allow_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, current_control_point) - QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, current_control_point_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, current_control_point),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, event_report_mask) - QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, event_report_mask_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_dun_ctrl_info_resp_msg_v01, event_report_mask)
};

static const uint8_t wds_set_dun_ctrl_event_report_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_dun_ctrl_event_report_req_msg_v01, notify_dun_call),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_dun_ctrl_event_report_req_msg_v01, notify_entitlement) - QMI_IDL_OFFSET8(wds_set_dun_ctrl_event_report_req_msg_v01, notify_entitlement_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_dun_ctrl_event_report_req_msg_v01, notify_entitlement),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_dun_ctrl_event_report_req_msg_v01, notify_silent_redial) - QMI_IDL_OFFSET8(wds_set_dun_ctrl_event_report_req_msg_v01, notify_silent_redial_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_dun_ctrl_event_report_req_msg_v01, notify_silent_redial)
};

static const uint8_t wds_set_dun_ctrl_event_report_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_dun_ctrl_event_report_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_dun_ctrl_event_report_resp_msg_v01, accepted_event_report_mask)
};

static const uint8_t wds_dun_ctrl_event_report_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, dun_ctrl_event),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, dun_call_notification) - QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, dun_call_notification_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, dun_call_notification),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, dun_call_id) - QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, dun_call_id_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, dun_call_id),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, previous_dun_failure_reason) - QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, previous_dun_failure_reason_valid)),
  0x12,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_dun_ctrl_event_report_ind_msg_v01, previous_dun_failure_reason),
  QMI_IDL_TYPE88(0, 33)
};

static const uint8_t wds_control_pending_dun_call_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_control_pending_dun_call_req_msg_v01, dun_call_action),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_control_pending_dun_call_req_msg_v01, dun_call_id)
};

static const uint8_t wds_control_pending_dun_call_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_control_pending_dun_call_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_embms_tmgi_activate_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, tmgi),
  QMI_IDL_TYPE88(0, 70),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, tranx_id) - QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, tranx_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, preempt_priority) - QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, preempt_priority_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, preempt_priority),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, earfcn_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, earfcn_list_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, earfcn_list),
  QMI_WDS_EMBMS_MAX_EARFCN_V01,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, earfcn_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, earfcn_list_len),
  QMI_IDL_TYPE88(0, 71),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, sai_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, sai_list_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, sai_list),
  QMI_WDS_EMBMS_SAI_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, sai_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_activate_req_msg_v01, sai_list_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, earfcn_list_ex) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, earfcn_list_ex_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_activate_req_msg_v01, earfcn_list_ex),
  QMI_WDS_EMBMS_MAX_EARFCN_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, earfcn_list_ex) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, earfcn_list_ex_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, multicast_ip_type) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, multicast_ip_type_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_activate_req_msg_v01, multicast_ip_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, multicast_ipv4_addr) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, multicast_ipv4_addr_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_activate_req_msg_v01, multicast_ipv4_addr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, multicast_ipv6_addr) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, multicast_ipv6_addr_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_activate_req_msg_v01, multicast_ipv6_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, multicast_port) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_activate_req_msg_v01, multicast_port_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_activate_req_msg_v01, multicast_port)
};

static const uint8_t wds_embms_tmgi_activate_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_activate_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_embms_tmgi_activate_resp_msg_v01, extended_error_code_valid)),
  0x10,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_embms_tmgi_activate_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_ind_msg_v01, activate_status),

  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_ind_msg_v01, tmgi),
  QMI_IDL_TYPE88(0, 70),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_activate_ind_msg_v01, tranx_id) - QMI_IDL_OFFSET8(wds_embms_tmgi_activate_ind_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_activate_ind_msg_v01, tranx_id)
};

static const uint8_t wds_embms_tmgi_deactivate_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_req_msg_v01, tmgi),
  QMI_IDL_TYPE88(0, 70),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_req_msg_v01, tranx_id) - QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_req_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_req_msg_v01, tranx_id)
};

static const uint8_t wds_embms_tmgi_deactivate_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_resp_msg_v01, extended_error_code_valid)),
  0x10,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_embms_tmgi_deactivate_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_ind_msg_v01, deactivate_status),

  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_ind_msg_v01, tmgi),
  QMI_IDL_TYPE88(0, 70),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_ind_msg_v01, tranx_id) - QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_ind_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_deactivate_ind_msg_v01, tranx_id)
};

static const uint8_t wds_embms_tmgi_list_query_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_embms_tmgi_list_query_req_msg_v01, list_type),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_list_query_req_msg_v01, tranx_id) - QMI_IDL_OFFSET8(wds_embms_tmgi_list_query_req_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_list_query_req_msg_v01, tranx_id)
};

static const uint8_t wds_embms_tmgi_list_query_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_list_query_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_list_query_resp_msg_v01, tmgi_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_list_query_resp_msg_v01, tmgi_list_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_list_query_resp_msg_v01, tmgi_list),
  QMI_IDL_TYPE88(0, 72),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_list_query_resp_msg_v01, warn_reason) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_list_query_resp_msg_v01, warn_reason_valid)),
  0x11,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_list_query_resp_msg_v01, warn_reason)
};

static const uint8_t wds_embms_tmgi_list_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_list_ind_msg_v01, tmgi_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_list_ind_msg_v01, tmgi_list_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_list_ind_msg_v01, tmgi_list),
  QMI_IDL_TYPE88(0, 72),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_list_ind_msg_v01, warn_reason) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_list_ind_msg_v01, warn_reason_valid)),
  0x11,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_list_ind_msg_v01, warn_reason),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_list_ind_msg_v01, tranx_id) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_list_ind_msg_v01, tranx_id_valid)),
  0x12,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_list_ind_msg_v01, tranx_id)
};

/*
 * wds_get_preferred_data_system_req_msg is empty
 * static const uint8_t wds_get_preferred_data_system_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_preferred_data_system_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_preferred_data_system_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_preferred_data_system_resp_msg_v01, current_sys) - QMI_IDL_OFFSET8(wds_get_preferred_data_system_resp_msg_v01, current_sys_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_preferred_data_system_resp_msg_v01, current_sys)
};

/*
 * wds_get_last_data_call_status_req_msg is empty
 * static const uint8_t wds_get_last_data_call_status_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_last_data_call_status_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, data_call_status) - QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, data_call_status_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, data_call_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, data_call_type) - QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, data_call_type_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, data_call_type),
  QMI_IDL_TYPE88(0, 73),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, data_call_addr_family) - QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, data_call_addr_family_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_last_data_call_status_resp_msg_v01, data_call_addr_family)
};

/*
 * wds_get_current_data_system_status_req_msg is empty
 * static const uint8_t wds_get_current_data_system_status_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_current_data_system_status_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_current_data_system_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_current_data_system_status_resp_msg_v01, system_status) - QMI_IDL_OFFSET8(wds_get_current_data_system_status_resp_msg_v01, system_status_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_current_data_system_status_resp_msg_v01, system_status),
  QMI_IDL_TYPE88(0, 29)
};

static const uint8_t wds_get_pdn_throttle_info_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_pdn_throttle_info_req_msg_v01, tech_type)
};

static const uint8_t wds_get_pdn_throttle_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_pdn_throttle_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info) - QMI_IDL_OFFSET8(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info),
  QMI_WDS_APNS_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info) - QMI_IDL_OFFSET8(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_len),
  QMI_IDL_TYPE88(0, 74),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_ext) - QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_ext_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_ext),
  QMI_WDS_APNS_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_ext) - QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_ext_len),
  QMI_IDL_TYPE88(0, 75),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_addn_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_addn_params_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_addn_params),
  QMI_WDS_APNS_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_addn_params) - QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, throttle_info_addn_params_len),
  QMI_IDL_TYPE88(0, 76),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, tx_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_pdn_throttle_info_resp_msg_v01, tx_id_valid)),
  0x13,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_pdn_throttle_info_resp_msg_v01, tx_id)
};

static const uint8_t wds_pdn_throttle_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pdn_throttle_info_ind_msg_v01, throttle_info) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_ind_msg_v01, throttle_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ind_msg_v01, throttle_info),
  QMI_WDS_APNS_MAX_V01,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_ind_msg_v01, throttle_info) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_ind_msg_v01, throttle_info_len),
  QMI_IDL_TYPE88(0, 74),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_pdn_throttle_info_ind_msg_v01, throttle_info_ext) - QMI_IDL_OFFSET16RELATIVE(wds_pdn_throttle_info_ind_msg_v01, throttle_info_ext_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_pdn_throttle_info_ind_msg_v01, throttle_info_ext),
  QMI_WDS_APNS_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_pdn_throttle_info_ind_msg_v01, throttle_info_ext) - QMI_IDL_OFFSET16RELATIVE(wds_pdn_throttle_info_ind_msg_v01, throttle_info_ext_len),
  QMI_IDL_TYPE88(0, 75),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_pdn_throttle_info_ind_msg_v01, throttle_info_addn_params) - QMI_IDL_OFFSET16RELATIVE(wds_pdn_throttle_info_ind_msg_v01, throttle_info_addn_params_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_pdn_throttle_info_ind_msg_v01, throttle_info_addn_params),
  QMI_WDS_APNS_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_pdn_throttle_info_ind_msg_v01, throttle_info_addn_params) - QMI_IDL_OFFSET16RELATIVE(wds_pdn_throttle_info_ind_msg_v01, throttle_info_addn_params_len),
  QMI_IDL_TYPE88(0, 76)
};

/*
 * wds_get_lte_max_attach_pdn_num_req_msg is empty
 * static const uint8_t wds_get_lte_max_attach_pdn_num_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_lte_max_attach_pdn_num_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_lte_max_attach_pdn_num_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_max_attach_pdn_num_resp_msg_v01, max_attach_pdn_num) - QMI_IDL_OFFSET8(wds_get_lte_max_attach_pdn_num_resp_msg_v01, max_attach_pdn_num_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_max_attach_pdn_num_resp_msg_v01, max_attach_pdn_num)
};

static const uint8_t wds_set_lte_attach_pdn_list_req_msg_data_v01[] = {
  0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_set_lte_attach_pdn_list_req_msg_v01, attach_pdn_list),
  QMI_WDS_ATTACH_PDN_MAX_V01,
  QMI_IDL_OFFSET8(wds_set_lte_attach_pdn_list_req_msg_v01, attach_pdn_list) - QMI_IDL_OFFSET8(wds_set_lte_attach_pdn_list_req_msg_v01, attach_pdn_list_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_lte_attach_pdn_list_req_msg_v01, action) - QMI_IDL_OFFSET8(wds_set_lte_attach_pdn_list_req_msg_v01, action_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_lte_attach_pdn_list_req_msg_v01, action)
};

static const uint8_t wds_set_lte_attach_pdn_list_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_lte_attach_pdn_list_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_set_lte_attach_pdn_list_action_result_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_lte_attach_pdn_list_action_result_ind_msg_v01, result)
};

/*
 * wds_get_lte_attach_pdn_list_req_msg is empty
 * static const uint8_t wds_get_lte_attach_pdn_list_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_lte_attach_pdn_list_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, attach_pdn_list) - QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, attach_pdn_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, attach_pdn_list),
  QMI_WDS_ATTACH_PDN_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, attach_pdn_list) - QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, attach_pdn_list_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, pending_attach_pdn_list) - QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, pending_attach_pdn_list_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, pending_attach_pdn_list),
  QMI_WDS_ATTACH_PDN_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, pending_attach_pdn_list) - QMI_IDL_OFFSET8(wds_get_lte_attach_pdn_list_resp_msg_v01, pending_attach_pdn_list_len)
};

static const uint8_t wds_lte_attach_pdn_list_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_lte_attach_pdn_list_ind_msg_v01, attach_pdn_list) - QMI_IDL_OFFSET8(wds_lte_attach_pdn_list_ind_msg_v01, attach_pdn_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_lte_attach_pdn_list_ind_msg_v01, attach_pdn_list),
  QMI_WDS_ATTACH_PDN_MAX_V01,
  QMI_IDL_OFFSET8(wds_lte_attach_pdn_list_ind_msg_v01, attach_pdn_list) - QMI_IDL_OFFSET8(wds_lte_attach_pdn_list_ind_msg_v01, attach_pdn_list_len)
};

/*
 * wds_get_lte_attach_params_req_msg is empty
 * static const uint8_t wds_get_lte_attach_params_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_lte_attach_params_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, apn_string) - QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, apn_string_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ip_type) - QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ip_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ip_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ota_attach_performed) - QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ota_attach_performed_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ota_attach_performed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv4_address) - QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv4_address_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv4_gateway_addr) - QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv4_gateway_addr_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv4_gateway_addr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv4_subnet_mask) - QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv4_subnet_mask_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv4_subnet_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv6_addr) - QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv6_addr_valid)),
  0x16,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_params_resp_msg_v01, ipv6_addr),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_lte_attach_params_resp_msg_v01, ipv6_gateway_addr) - QMI_IDL_OFFSET16RELATIVE(wds_get_lte_attach_params_resp_msg_v01, ipv6_gateway_addr_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_lte_attach_params_resp_msg_v01, ipv6_gateway_addr),
  QMI_IDL_TYPE88(0, 13)
};

/*
 * wds_reset_pkt_statistics_req_msg is empty
 * static const uint8_t wds_reset_pkt_statistics_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_reset_pkt_statistics_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reset_pkt_statistics_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_flow_control_status_req_msg is empty
 * static const uint8_t wds_get_flow_control_status_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_flow_control_status_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_flow_control_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_flow_control_status_resp_msg_v01, uplink_flow_control) - QMI_IDL_OFFSET8(wds_get_flow_control_status_resp_msg_v01, uplink_flow_control_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_flow_control_status_resp_msg_v01, uplink_flow_control)
};

static const uint8_t wds_embms_tmgi_act_deact_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, act_tmgi),
  QMI_IDL_TYPE88(0, 70),

  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, deact_tmgi),
  QMI_IDL_TYPE88(0, 70),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, tranx_id) - QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, tranx_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, preempt_priority) - QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, preempt_priority_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, preempt_priority),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list),
  QMI_WDS_EMBMS_MAX_EARFCN_V01,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list_len),
  QMI_IDL_TYPE88(0, 71),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, sai_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, sai_list_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, sai_list),
  QMI_WDS_EMBMS_SAI_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, sai_list) - QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_req_msg_v01, sai_list_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list_ex) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list_ex_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list_ex),
  QMI_WDS_EMBMS_MAX_EARFCN_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list_ex) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, earfcn_list_ex_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, multicast_ip_type) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, multicast_ip_type_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_act_deact_req_msg_v01, multicast_ip_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, multicast_ipv4_addr) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, multicast_ipv4_addr_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_act_deact_req_msg_v01, multicast_ipv4_addr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, multicast_ipv6_addr) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, multicast_ipv6_addr_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_act_deact_req_msg_v01, multicast_ipv6_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, multicast_port) - QMI_IDL_OFFSET16RELATIVE(wds_embms_tmgi_act_deact_req_msg_v01, multicast_port_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_tmgi_act_deact_req_msg_v01, multicast_port)
};

static const uint8_t wds_embms_tmgi_act_deact_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_resp_msg_v01, extended_error_code_valid)),
  0x10,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_embms_tmgi_act_deact_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_ind_msg_v01, act_status),

  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_ind_msg_v01, act_tmgi),
  QMI_IDL_TYPE88(0, 70),

  0x03,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_ind_msg_v01, deact_status),

  0x04,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_ind_msg_v01, deact_tmgi),
  QMI_IDL_TYPE88(0, 70),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_ind_msg_v01, tranx_id) - QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_ind_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_tmgi_act_deact_ind_msg_v01, tranx_id)
};

static const uint8_t wds_bind_data_port_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_bind_data_port_req_msg_v01, data_port)
};

static const uint8_t wds_bind_data_port_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_bind_data_port_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_set_additional_pdn_filter_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_req_msg_v01, ip_version),

  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_req_msg_v01, net_policy_info),
  QMI_IDL_TYPE88(0, 77),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_req_msg_v01, next_hdr_prot) - QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_req_msg_v01, next_hdr_prot_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_req_msg_v01, next_hdr_prot),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_req_msg_v01, tcp_udp_src) - QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_req_msg_v01, tcp_udp_src_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_req_msg_v01, tcp_udp_src),
  QMI_IDL_TYPE88(0, 78)
};

static const uint8_t wds_set_additional_pdn_filter_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_resp_msg_v01, filter_handle) - QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_resp_msg_v01, filter_handle_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_additional_pdn_filter_resp_msg_v01, filter_handle)
};

static const uint8_t wds_remove_additional_pdn_filter_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_remove_additional_pdn_filter_req_msg_v01, filter_handle)
};

static const uint8_t wds_remove_additional_pdn_filter_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_remove_additional_pdn_filter_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_extended_ip_config_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_extended_ip_config_ind_msg_v01, changed_ip_config) - QMI_IDL_OFFSET8(wds_extended_ip_config_ind_msg_v01, changed_ip_config_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_extended_ip_config_ind_msg_v01, changed_ip_config)
};

static const uint8_t wds_reverse_ip_transport_connection_ind_registration_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_registration_req_msg_v01, register_for_ind)
};

static const uint8_t wds_reverse_ip_transport_connection_ind_registration_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_registration_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_reverse_ip_transport_connection_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, rev_ip_transport_conn_status),

  0x02,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, transaction_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, tech_name) - QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, tech_name_valid)),
  0x10,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, tech_name),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, is_shared) - QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, is_shared_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, is_shared),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, ipv4_addr) - QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, ipv4_addr_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, ipv4_addr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, ipv4_subnet_mask) - QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, ipv4_subnet_mask_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, ipv4_subnet_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, ipv6_addr) - QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, ipv6_addr_valid)),
  0x14,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, ipv6_addr),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, mtu) - QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, mtu_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_connection_ind_msg_v01, mtu)
};

/*
 * wds_get_ipsec_static_sa_config_req_msg is empty
 * static const uint8_t wds_get_ipsec_static_sa_config_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_ipsec_static_sa_config_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, spi_rx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, spi_rx_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, spi_rx),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, spi_tx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, spi_tx_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, spi_tx),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, ipsec_sa_protocol) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, ipsec_sa_protocol_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, ipsec_sa_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, encapsulation_mode) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, encapsulation_mode_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, encapsulation_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, dest_addr) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, dest_addr_valid)),
  0x14,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, dest_addr),
  QMI_IDL_TYPE88(0, 79),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, local_addr) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, local_addr_valid)),
  0x15,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, local_addr),
  QMI_IDL_TYPE88(0, 79),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_algo) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_algo_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_algo),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_rx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_rx_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_rx),
  QMI_WDS_IPSEC_SA_HASH_MAX_SIZE_V01,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_rx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_rx_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_tx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_tx_valid)),
  0x18,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_tx),
  QMI_WDS_IPSEC_SA_HASH_MAX_SIZE_V01,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_tx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, hash_key_tx_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_algo) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_algo_valid)),
  0x19,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_algo),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_rx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_rx_valid)),
  0x1A,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_rx),
  QMI_WDS_IPSEC_SA_CRYPTO_ALGO_KEY_MAX_SIZE_V01,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_rx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_rx_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_tx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_tx_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_tx),
  QMI_WDS_IPSEC_SA_CRYPTO_ALGO_KEY_MAX_SIZE_V01,
  QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_tx) - QMI_IDL_OFFSET8(wds_get_ipsec_static_sa_config_resp_msg_v01, crypto_key_tx_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, iv) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, iv_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, iv),
  QMI_WDS_IPSEC_SA_AES_BLOCK_BYTE_LEN_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, iv) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, iv_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, is_udp_encaps) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, is_udp_encaps_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, is_udp_encaps),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, nat_local_ip_addr) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, nat_local_ip_addr_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, nat_local_ip_addr),
  QMI_IDL_TYPE88(0, 79),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, nat_remote_ip_addr) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, nat_remote_ip_addr_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, nat_remote_ip_addr),
  QMI_IDL_TYPE88(0, 79),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_address_valid)),
  0x20,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_address),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_address_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_netmask) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_netmask_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_netmask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dns) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dns_valid)),
  0x22,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dns),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dns) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dns_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_nbns) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_nbns_valid)),
  0x23,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_nbns),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_nbns) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_nbns_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_address_expiry) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_address_expiry_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_address_expiry),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dhcp_valid)),
  0x25,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dhcp),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_dhcp_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_application_version) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_application_version_valid)),
  0x26,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_application_version),
  QMI_WDS_IPSEC_SA_CFG_DATA_SIZE_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_application_version) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_application_version_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_address_valid)),
  0x27,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_address),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_address_len),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dns) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dns_valid)),
  0x28,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dns),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dns) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dns_len),
  QMI_IDL_TYPE88(0, 81),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_nbns) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_nbns_valid)),
  0x29,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_nbns),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_nbns) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_nbns_len),
  QMI_IDL_TYPE88(0, 81),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dhcp_valid)),
  0x2A,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dhcp),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_dhcp_len),
  QMI_IDL_TYPE88(0, 81),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_subnet) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_subnet_valid)),
  0x2B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_subnet),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_subnet) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv4_subnet_len),
  QMI_IDL_TYPE88(0, 80),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_supported_attributes) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_supported_attributes_valid)),
  0x2C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_supported_attributes),
  QMI_WDS_IPSEC_SA_CFG_DATA_SIZE_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_supported_attributes) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_supported_attributes_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_subnet) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_subnet_valid)),
  0x2D,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_subnet),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_subnet) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_ipv6_subnet_len),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv4_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv4_address_valid)),
  0x2E,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv4_address),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv4_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv4_address_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv6_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv6_address_valid)),
  0x2F,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv6_address),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv6_address) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_internal_pcscf_ipv6_address_len),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_ha) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_ha_valid)),
  0x30,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_ha),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_ha) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_ha_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_hoa) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_hoa_valid)),
  0x31,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_hoa),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_hoa) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip4_hoa_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_ha) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_ha_valid)),
  0x32,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_ha),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_ha) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_ha_len),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_hoa) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_hoa_valid)),
  0x33,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_hoa),
  QMI_WDS_IPSEC_SA_CFG_ATTR_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_hoa) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, cfg_attr_3gpp2_mip6_hoa_len),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_list_valid)),
  0x34,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_list),
  QMI_WDS_IPSEC_SA_MAX_TS_COUNT_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_list_len),
  QMI_IDL_TYPE88(0, 82),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_responder_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_responder_list_valid)),
  0x35,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_responder_list),
  QMI_WDS_IPSEC_SA_MAX_TS_COUNT_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_responder_list) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, traffic_selector_responder_list_len),
  QMI_IDL_TYPE88(0, 82),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, apn) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, apn_valid)),
  0x36,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, apn),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, aes_mode) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, aes_mode_valid)),
  0x37,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, aes_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_rx) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_rx_valid)),
  0x38,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_rx),
  QMI_WDS_IPSEC_SA_EXT_HASH_MAX_SIZE_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_rx) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_rx_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_tx) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_tx_valid)),
  0x39,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_tx),
  QMI_WDS_IPSEC_SA_EXT_HASH_MAX_SIZE_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_tx) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext_hash_key_tx_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, udp_encap_src_port) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, udp_encap_src_port_valid)),
  0x3A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, udp_encap_src_port),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_rx) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_rx_valid)),
  0x3B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 |   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_rx),
  ((QMI_WDS_IPSEC_SA_EXT2_HASH_MAX_SIZE_V01) & 0xFF), ((QMI_WDS_IPSEC_SA_EXT2_HASH_MAX_SIZE_V01) >> 8),
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_rx) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_rx_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_tx) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_tx_valid)),
  0x3C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 |   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_tx),
  ((QMI_WDS_IPSEC_SA_EXT2_HASH_MAX_SIZE_V01) & 0xFF), ((QMI_WDS_IPSEC_SA_EXT2_HASH_MAX_SIZE_V01) >> 8),
  QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_tx) - QMI_IDL_OFFSET16RELATIVE(wds_get_ipsec_static_sa_config_resp_msg_v01, ext2_hash_key_tx_len)
};

static const uint8_t wds_reverse_ip_transport_config_complete_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_config_complete_req_msg_v01, config_result),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_config_complete_req_msg_v01, transaction_id)
};

static const uint8_t wds_reverse_ip_transport_config_complete_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_config_complete_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_data_bearer_technology_ex_req_msg is empty
 * static const uint8_t wds_get_data_bearer_technology_ex_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_data_bearer_technology_ex_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_bearer_technology_ex_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_bearer_technology_ex_resp_msg_v01, bearer_tech) - QMI_IDL_OFFSET8(wds_get_data_bearer_technology_ex_resp_msg_v01, bearer_tech_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_bearer_technology_ex_resp_msg_v01, bearer_tech),
  QMI_IDL_TYPE88(0, 30),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_bearer_technology_ex_resp_msg_v01, last_bearer_tech) - QMI_IDL_OFFSET8(wds_get_data_bearer_technology_ex_resp_msg_v01, last_bearer_tech_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_bearer_technology_ex_resp_msg_v01, last_bearer_tech),
  QMI_IDL_TYPE88(0, 30)
};

static const uint8_t wds_set_lte_data_retry_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_lte_data_retry_req_msg_v01, lte_data_retry)
};

static const uint8_t wds_set_lte_data_retry_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_lte_data_retry_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_lte_data_retry_req_msg is empty
 * static const uint8_t wds_get_lte_data_retry_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_lte_data_retry_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_lte_data_retry_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_data_retry_resp_msg_v01, lte_data_retry) - QMI_IDL_OFFSET8(wds_get_lte_data_retry_resp_msg_v01, lte_data_retry_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_data_retry_resp_msg_v01, lte_data_retry)
};

static const uint8_t wds_set_lte_attach_type_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_lte_attach_type_req_msg_v01, lte_attach_type)
};

static const uint8_t wds_set_lte_attach_type_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_lte_attach_type_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_lte_attach_type_req_msg is empty
 * static const uint8_t wds_get_lte_attach_type_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_lte_attach_type_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_type_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_attach_type_resp_msg_v01, lte_attach_type) - QMI_IDL_OFFSET8(wds_get_lte_attach_type_resp_msg_v01, lte_attach_type_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_attach_type_resp_msg_v01, lte_attach_type)
};

static const uint8_t wds_reverse_ip_transport_filter_setup_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_filter_setup_ind_msg_v01, filter_type),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reverse_ip_transport_filter_setup_ind_msg_v01, spi) - QMI_IDL_OFFSET8(wds_reverse_ip_transport_filter_setup_ind_msg_v01, spi_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_reverse_ip_transport_filter_setup_ind_msg_v01, spi)
};

static const uint8_t wds_handoff_information_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_handoff_information_ind_msg_v01, handoff_information),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_handoff_information_ind_msg_v01, handoff_event_info) - QMI_IDL_OFFSET8(wds_handoff_information_ind_msg_v01, handoff_event_info_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_handoff_information_ind_msg_v01, handoff_event_info),
  QMI_IDL_TYPE88(0, 83),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_handoff_information_ind_msg_v01, handoff_failure_reason) - QMI_IDL_OFFSET8(wds_handoff_information_ind_msg_v01, handoff_failure_reason_valid)),
  0x11,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_handoff_information_ind_msg_v01, handoff_failure_reason),
  QMI_IDL_TYPE88(0, 84)
};

static const uint8_t wds_set_data_path_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_data_path_req_msg_v01, data_path)
};

static const uint8_t wds_set_data_path_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_data_path_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_data_path_req_msg is empty
 * static const uint8_t wds_get_data_path_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_data_path_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_path_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_path_resp_msg_v01, data_path) - QMI_IDL_OFFSET8(wds_get_data_path_resp_msg_v01, data_path_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_data_path_resp_msg_v01, data_path)
};

/*
 * wds_update_lte_attach_pdn_list_profiles_req_msg is empty
 * static const uint8_t wds_update_lte_attach_pdn_list_profiles_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_update_lte_attach_pdn_list_profiles_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_update_lte_attach_pdn_list_profiles_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_embms_sai_list_query_req_msg is empty
 * static const uint8_t wds_embms_sai_list_query_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_embms_sai_list_query_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_sai_list_query_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list) - QMI_IDL_OFFSET8(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list),
  QMI_WDS_EMBMS_FREQ_SAI_MAX_V01,
  QMI_IDL_OFFSET8(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list) - QMI_IDL_OFFSET8(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list_len),
  QMI_IDL_TYPE88(0, 85),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list_ex) - QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list_ex_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list_ex),
  QMI_WDS_EMBMS_FREQ_SAI_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list_ex) - QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_query_resp_msg_v01, freq_sai_list_ex_len),
  QMI_IDL_TYPE88(0, 86)
};

static const uint8_t wds_embms_sai_list_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_sai_list_ind_msg_v01, freq_sai_list) - QMI_IDL_OFFSET8(wds_embms_sai_list_ind_msg_v01, freq_sai_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_sai_list_ind_msg_v01, freq_sai_list),
  QMI_WDS_EMBMS_FREQ_SAI_MAX_V01,
  QMI_IDL_OFFSET8(wds_embms_sai_list_ind_msg_v01, freq_sai_list) - QMI_IDL_OFFSET8(wds_embms_sai_list_ind_msg_v01, freq_sai_list_len),
  QMI_IDL_TYPE88(0, 85),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_ind_msg_v01, tranx_id) - QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_ind_msg_v01, tranx_id_valid)),
  0x11,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_sai_list_ind_msg_v01, tranx_id),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_ind_msg_v01, freq_sai_list_ex) - QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_ind_msg_v01, freq_sai_list_ex_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_sai_list_ind_msg_v01, freq_sai_list_ex),
  QMI_WDS_EMBMS_FREQ_SAI_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_ind_msg_v01, freq_sai_list_ex) - QMI_IDL_OFFSET16RELATIVE(wds_embms_sai_list_ind_msg_v01, freq_sai_list_ex_len),
  QMI_IDL_TYPE88(0, 86)
};

static const uint8_t wds_bind_mux_data_port_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, ep_id) - QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, ep_id_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, ep_id),
  QMI_IDL_TYPE88(2, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, mux_id) - QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, mux_id_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, mux_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, reversed) - QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, reversed_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, reversed),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, client_type) - QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, client_type_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_bind_mux_data_port_req_msg_v01, client_type)
};

static const uint8_t wds_bind_mux_data_port_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_bind_mux_data_port_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_initiate_esp_rekey_req_msg is empty
 * static const uint8_t wds_initiate_esp_rekey_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_initiate_esp_rekey_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_initiate_esp_rekey_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_internal_iface_ev_register_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_register_req_msg_v01, event_registration_mask)
};

static const uint8_t wds_internal_iface_ev_register_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_register_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_internal_iface_ev_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, iface_event_name),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, outage) - QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, outage_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, outage),
  QMI_IDL_TYPE88(0, 87),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, extended_ip_config_status) - QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, extended_ip_config_status_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, extended_ip_config_status),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, hdr_rate_intertia_fail) - QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, hdr_rate_intertia_fail_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, hdr_rate_intertia_fail),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, hdr_sm_fail) - QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, hdr_sm_fail_valid)),
  0x13,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, hdr_sm_fail),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, slot_cycle_changed) - QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, slot_cycle_changed_valid)),
  0x14,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, slot_cycle_changed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, rf_conditions) - QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, rf_conditions_valid)),
  0x15,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, rf_conditions),
  QMI_IDL_TYPE88(0, 88),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, dos_ack_info) - QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, dos_ack_info_valid)),
  0x16,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_internal_iface_ev_ind_msg_v01, dos_ack_info),
  QMI_IDL_TYPE88(0, 89)
};

static const uint8_t wds_get_internal_runtime_settings_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_req_msg_v01, requested_internal_settings) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_req_msg_v01, requested_internal_settings_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_req_msg_v01, requested_internal_settings),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_req_msg_v01, timer_select) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_req_msg_v01, timer_select_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_req_msg_v01, timer_select),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_req_msg_v01, flags) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_req_msg_v01, flags_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_req_msg_v01, flags)
};

static const uint8_t wds_get_internal_runtime_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, rf_conditions) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, rf_conditions_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, rf_conditions),
  QMI_IDL_TYPE88(0, 88),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, dorm_timer) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, dorm_timer_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, dorm_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, session_timer_value) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, session_timer_value_valid)),
  0x12,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, session_timer_value),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, hdr_1x_handdown_option) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, hdr_1x_handdown_option_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, hdr_1x_handdown_option),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, hysterisis_act_timer) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, hysterisis_act_timer_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, hysterisis_act_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, slotted_mode_option) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, slotted_mode_option_valid)),
  0x15,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, slotted_mode_option),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, sdb_support) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, sdb_support_valid)),
  0x16,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, sdb_support),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, operation_failure) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, operation_failure_valid)),
  0xE1,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, operation_failure),
  QMI_WDS_MAX_RUNTIME_SETTINGS_FAILURES_V01,
  QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, operation_failure) - QMI_IDL_OFFSET8(wds_get_internal_runtime_settings_resp_msg_v01, operation_failure_len),
  QMI_IDL_TYPE88(0, 90)
};

static const uint8_t wds_set_internal_runtime_settings_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, enable_1x_holddown) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, enable_1x_holddown_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, enable_1x_holddown),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, dorm_timer) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, dorm_timer_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, dorm_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, session_timer) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, session_timer_valid)),
  0x12,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, session_timer),
  QMI_IDL_TYPE88(0, 91),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, hdr_1x_handdown_option) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, hdr_1x_handdown_option_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, hdr_1x_handdown_option),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, hysterisis_act_timer) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, hysterisis_act_timer_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, hysterisis_act_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, slotted_mode_option) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, slotted_mode_option_valid)),
  0x15,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, slotted_mode_option),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, enable_hdr_hpt) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, enable_hdr_hpt_valid)),
  0x16,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, enable_hdr_hpt),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, enable_hdr_rev0_rate_inertia) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, enable_hdr_rev0_rate_inertia_valid)),
  0x17,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_req_msg_v01, enable_hdr_rev0_rate_inertia)
};

static const uint8_t wds_set_internal_runtime_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_resp_msg_v01, operation_failure) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_resp_msg_v01, operation_failure_valid)),
  0xE1,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_resp_msg_v01, operation_failure),
  QMI_WDS_MAX_RUNTIME_SETTINGS_FAILURES_V01,
  QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_resp_msg_v01, operation_failure) - QMI_IDL_OFFSET8(wds_set_internal_runtime_settings_resp_msg_v01, operation_failure_len),
  QMI_IDL_TYPE88(0, 92)
};

/*
 * wds_refresh_dhcp_config_info_req_msg is empty
 * static const uint8_t wds_refresh_dhcp_config_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_refresh_dhcp_config_info_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_refresh_dhcp_config_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_set_throughput_info_ind_freq_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_throughput_info_ind_freq_req_msg_v01, report_interval) - QMI_IDL_OFFSET8(wds_set_throughput_info_ind_freq_req_msg_v01, report_interval_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_throughput_info_ind_freq_req_msg_v01, report_interval)
};

static const uint8_t wds_set_throughput_info_ind_freq_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_throughput_info_ind_freq_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_last_throughput_info_req_msg is empty
 * static const uint8_t wds_get_last_throughput_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_last_throughput_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_last_throughput_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_last_throughput_info_resp_msg_v01, throughput_info) - QMI_IDL_OFFSET8(wds_get_last_throughput_info_resp_msg_v01, throughput_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_last_throughput_info_resp_msg_v01, throughput_info),
  QMI_WDS_MAX_THROUGHPUT_INFO_V01,
  QMI_IDL_OFFSET8(wds_get_last_throughput_info_resp_msg_v01, throughput_info) - QMI_IDL_OFFSET8(wds_get_last_throughput_info_resp_msg_v01, throughput_info_len),
  QMI_IDL_TYPE88(0, 94)
};

static const uint8_t wds_throughput_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_throughput_info_ind_msg_v01, throughput_info) - QMI_IDL_OFFSET8(wds_throughput_info_ind_msg_v01, throughput_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_throughput_info_ind_msg_v01, throughput_info),
  QMI_WDS_MAX_THROUGHPUT_INFO_V01,
  QMI_IDL_OFFSET8(wds_throughput_info_ind_msg_v01, throughput_info) - QMI_IDL_OFFSET8(wds_throughput_info_ind_msg_v01, throughput_info_len),
  QMI_IDL_TYPE88(0, 94)
};

static const uint8_t wds_config_profile_list_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_config_profile_list_req_msg_v01, profile_event_register) - QMI_IDL_OFFSET8(wds_config_profile_list_req_msg_v01, profile_event_register_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_config_profile_list_req_msg_v01, profile_event_register),
  QMI_WDS_PROFILE_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_config_profile_list_req_msg_v01, profile_event_register) - QMI_IDL_OFFSET8(wds_config_profile_list_req_msg_v01, profile_event_register_len),
  QMI_IDL_TYPE88(0, 95)
};

static const uint8_t wds_config_profile_list_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_config_profile_list_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_profile_changed_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_profile_changed_ind_msg_v01, profile_changed_ind) - QMI_IDL_OFFSET8(wds_profile_changed_ind_msg_v01, profile_changed_ind_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_profile_changed_ind_msg_v01, profile_changed_ind),
  QMI_IDL_TYPE88(0, 96)
};

static const uint8_t wds_get_capabilities_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, extended_embms_frequency) - QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, extended_embms_frequency_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, extended_embms_frequency),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, attach_pdn_list_action_capability) - QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, attach_pdn_list_action_capability_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, attach_pdn_list_action_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, is_clat_supported) - QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, is_clat_supported_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, is_clat_supported),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, mux_id_support_capability) - QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, mux_id_support_capability_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, mux_id_support_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, bring_up_capability) - QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, bring_up_capability_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, bring_up_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, pdn_throttle_cap) - QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, pdn_throttle_cap_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, pdn_throttle_cap),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, roaming_info_cap) - QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, roaming_info_cap_valid)),
  0x16,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, roaming_info_cap),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, lte_attach_failure_info_capability) - QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, lte_attach_failure_info_capability_valid)),
  0x17,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_req_msg_v01, lte_attach_failure_info_capability)
};

static const uint8_t wds_get_capabilities_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, extended_embms_frequency) - QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, extended_embms_frequency_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, extended_embms_frequency),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, attach_pdn_list_action_capability) - QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, attach_pdn_list_action_capability_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, attach_pdn_list_action_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, is_clat_supported) - QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, is_clat_supported_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, is_clat_supported),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, mux_id_support) - QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, mux_id_support_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, mux_id_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, bring_up_capability) - QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, bring_up_capability_valid)),
  0x14,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, bring_up_capability),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, pdn_throttle_cap) - QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, pdn_throttle_cap_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, pdn_throttle_cap),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, roaming_info_cap) - QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, roaming_info_cap_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, roaming_info_cap),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, lte_attach_failure_info_capability) - QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, lte_attach_failure_info_capability_valid)),
  0x17,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_capabilities_resp_msg_v01, lte_attach_failure_info_capability)
};

/*
 * wds_get_roaming_info_req_msg is empty
 * static const uint8_t wds_get_roaming_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_roaming_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_roaming_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_roaming_info_resp_msg_v01, roaming_apn_name_list) - QMI_IDL_OFFSET8(wds_get_roaming_info_resp_msg_v01, roaming_apn_name_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_roaming_info_resp_msg_v01, roaming_apn_name_list),
  QMI_WDS_APN_NAME_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_roaming_info_resp_msg_v01, roaming_apn_name_list) - QMI_IDL_OFFSET8(wds_get_roaming_info_resp_msg_v01, roaming_apn_name_list_len),
  QMI_IDL_TYPE88(0, 15),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_roaming_info_resp_msg_v01, tx_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_roaming_info_resp_msg_v01, tx_id_valid)),
  0x11,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_roaming_info_resp_msg_v01, tx_id)
};

static const uint8_t wds_roaming_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_roaming_info_ind_msg_v01, roaming_apn_name_list) - QMI_IDL_OFFSET8(wds_roaming_info_ind_msg_v01, roaming_apn_name_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_roaming_info_ind_msg_v01, roaming_apn_name_list),
  QMI_WDS_APN_NAME_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_roaming_info_ind_msg_v01, roaming_apn_name_list) - QMI_IDL_OFFSET8(wds_roaming_info_ind_msg_v01, roaming_apn_name_list_len),
  QMI_IDL_TYPE88(0, 15),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_roaming_info_ind_msg_v01, tx_info) - QMI_IDL_OFFSET16RELATIVE(wds_roaming_info_ind_msg_v01, tx_info_valid)),
  0x11,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_roaming_info_ind_msg_v01, tx_info),
  QMI_IDL_TYPE88(0, 20)
};

static const uint8_t wds_get_delegated_ipv6_prefix_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_delegated_ipv6_prefix_req_msg_v01, src_ipv6_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01
};

static const uint8_t wds_get_delegated_ipv6_prefix_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_delegated_ipv6_prefix_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_delegated_ipv6_prefix_resp_msg_v01, ipv6_prefix) - QMI_IDL_OFFSET8(wds_get_delegated_ipv6_prefix_resp_msg_v01, ipv6_prefix_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_delegated_ipv6_prefix_resp_msg_v01, ipv6_prefix),
  QMI_IDL_TYPE88(0, 13)
};

static const uint8_t wds_remove_delegated_ipv6_prefix_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_remove_delegated_ipv6_prefix_req_msg_v01, ipv6_prefix) - QMI_IDL_OFFSET8(wds_remove_delegated_ipv6_prefix_req_msg_v01, ipv6_prefix_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_remove_delegated_ipv6_prefix_req_msg_v01, ipv6_prefix),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_remove_delegated_ipv6_prefix_req_msg_v01, host_ll_addr) - QMI_IDL_OFFSET8(wds_remove_delegated_ipv6_prefix_req_msg_v01, host_ll_addr_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_remove_delegated_ipv6_prefix_req_msg_v01, host_ll_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01
};

static const uint8_t wds_remove_delegated_ipv6_prefix_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_remove_delegated_ipv6_prefix_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_abort_go_dormant_req_msg is empty
 * static const uint8_t wds_abort_go_dormant_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_abort_go_dormant_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_abort_go_dormant_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_bind_subscription_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_bind_subscription_req_msg_v01, subscription)
};

static const uint8_t wds_bind_subscription_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_bind_subscription_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_bind_subscription_req_msg is empty
 * static const uint8_t wds_get_bind_subscription_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_bind_subscription_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_bind_subscription_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_bind_subscription_resp_msg_v01, subscription) - QMI_IDL_OFFSET8(wds_get_bind_subscription_resp_msg_v01, subscription_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_bind_subscription_resp_msg_v01, subscription)
};

static const uint8_t wds_set_lte_data_call_type_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_lte_data_call_type_req_msg_v01, call_type)
};

static const uint8_t wds_set_lte_data_call_type_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_lte_data_call_type_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_set_downlink_throughput_info_ind_freq_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_downlink_throughput_info_ind_freq_req_msg_v01, downlink_report_interval)
};

static const uint8_t wds_set_downlink_throughput_info_ind_freq_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_downlink_throughput_info_ind_freq_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_downlink_throughput_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_downlink_throughput_info_ind_msg_v01, downlink_allowed_rate) - QMI_IDL_OFFSET8(wds_downlink_throughput_info_ind_msg_v01, downlink_allowed_rate_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_downlink_throughput_info_ind_msg_v01, downlink_allowed_rate),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_downlink_throughput_info_ind_msg_v01, confidence_level) - QMI_IDL_OFFSET8(wds_downlink_throughput_info_ind_msg_v01, confidence_level_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_downlink_throughput_info_ind_msg_v01, confidence_level),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_downlink_throughput_info_ind_msg_v01, is_suspended) - QMI_IDL_OFFSET8(wds_downlink_throughput_info_ind_msg_v01, is_suspended_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_downlink_throughput_info_ind_msg_v01, is_suspended)
};

/*
 * wds_get_downlink_throughput_info_params_req_msg is empty
 * static const uint8_t wds_get_downlink_throughput_info_params_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_downlink_throughput_info_params_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_params_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_params_resp_msg_v01, min_dl_interval) - QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_params_resp_msg_v01, min_dl_interval_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_params_resp_msg_v01, min_dl_interval)
};

static const uint8_t wds_embms_content_desc_update_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, tmgi),
  QMI_IDL_TYPE88(0, 70),

  0x02,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, tranx_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, obj_delivery_duration) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, obj_delivery_duration_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, obj_delivery_duration),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, session_fec_redundancy_lvl) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, session_fec_redundancy_lvl_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, session_fec_redundancy_lvl),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, service_type) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, service_type_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, service_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, priority) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, priority_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, priority),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_1) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_1_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_1),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_2) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_2_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_3) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_3_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_3),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_4) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_4_valid)),
  0x17,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, media_data_rate_4),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, tsi) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, tsi_valid)),
  0x24,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, tsi),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, toi) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, toi_valid)),
  0x25,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, toi),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, obj_size) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, obj_size_valid)),
  0x26,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, obj_size),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, symbol_size) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, symbol_size_valid)),
  0x27,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, symbol_size),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, obj_fec_redundancy_lvl) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, obj_fec_redundancy_lvl_valid)),
  0x28,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, obj_fec_redundancy_lvl),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_tsi) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_tsi_valid)),
  0x29,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_tsi),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_toi) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_toi_valid)),
  0x2A,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_toi),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_valid)),
  0x2B,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_last_decoding_esi) - QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_last_decoding_esi_valid)),
  0x2C,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_req_msg_v01, status_last_decoding_esi)
};

static const uint8_t wds_embms_content_desc_update_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_update_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_embms_content_desc_control_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, tmgi),
  QMI_IDL_TYPE88(0, 70),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, tranx_id) - QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, tranx_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, content_control) - QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, content_control_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, content_control),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, status_control) - QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, status_control_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_embms_content_desc_control_ind_msg_v01, status_control)
};

static const uint8_t wds_policy_refresh_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_policy_refresh_req_msg_v01, policy_type)
};

static const uint8_t wds_policy_refresh_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_policy_refresh_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_policy_refresh_result_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_policy_refresh_result_ind_msg_v01, status)
};

static const uint8_t wds_policy_ready_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, policy_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, ftp_ipv6_addr) - QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, ftp_ipv6_addr_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, ftp_ipv6_addr),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, tcp_port) - QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, tcp_port_valid)),
  0x11,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, tcp_port),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, policy_file_name) - QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, policy_file_name_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_policy_ready_ind_msg_v01, policy_file_name),
  QMI_WDS_MAX_FILE_NAME_V01
};

static const uint8_t wds_apn_param_info_change_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_apn_param_info_change_ind_msg_v01, changed_apn_string_info) - QMI_IDL_OFFSET8(wds_apn_param_info_change_ind_msg_v01, changed_apn_string_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_apn_param_info_change_ind_msg_v01, changed_apn_string_info),
  QMI_WDS_MAX_APN_INFO_ARRAY_SIZE_V01,
  QMI_IDL_TYPE88(0, 97),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_apn_param_info_change_ind_msg_v01, changed_pdp_type_info) - QMI_IDL_OFFSET16RELATIVE(wds_apn_param_info_change_ind_msg_v01, changed_pdp_type_info_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_apn_param_info_change_ind_msg_v01, changed_pdp_type_info),
  QMI_WDS_MAX_APN_INFO_ARRAY_SIZE_V01
};

static const uint8_t wds_set_silent_redial_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_silent_redial_req_msg_v01, set_silent_redial) - QMI_IDL_OFFSET8(wds_set_silent_redial_req_msg_v01, set_silent_redial_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_silent_redial_req_msg_v01, set_silent_redial)
};

static const uint8_t wds_set_silent_redial_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_silent_redial_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_configured_throughput_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_configured_throughput_info_ind_msg_v01, ul_configured_throughput) - QMI_IDL_OFFSET8(wds_configured_throughput_info_ind_msg_v01, ul_configured_throughput_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_configured_throughput_info_ind_msg_v01, ul_configured_throughput),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_configured_throughput_info_ind_msg_v01, dl_configured_throughput) - QMI_IDL_OFFSET8(wds_configured_throughput_info_ind_msg_v01, dl_configured_throughput_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_configured_throughput_info_ind_msg_v01, dl_configured_throughput)
};

/*
 * wds_get_configured_throughput_info_req_msg is empty
 * static const uint8_t wds_get_configured_throughput_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_configured_throughput_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_configured_throughput_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_configured_throughput_info_resp_msg_v01, ul_configured_throughput) - QMI_IDL_OFFSET8(wds_get_configured_throughput_info_resp_msg_v01, ul_configured_throughput_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_configured_throughput_info_resp_msg_v01, ul_configured_throughput),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_configured_throughput_info_resp_msg_v01, dl_configured_throughput) - QMI_IDL_OFFSET8(wds_get_configured_throughput_info_resp_msg_v01, dl_configured_throughput_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_configured_throughput_info_resp_msg_v01, dl_configured_throughput)
};

/*
 * wds_get_downlink_throughput_info_req_msg is empty
 * static const uint8_t wds_get_downlink_throughput_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_downlink_throughput_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_resp_msg_v01, downlink_rate) - QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_resp_msg_v01, downlink_rate_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_resp_msg_v01, downlink_rate),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_resp_msg_v01, confidence_level) - QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_resp_msg_v01, confidence_level_valid)),
  0x11,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_downlink_throughput_info_resp_msg_v01, confidence_level)
};

static const uint8_t wds_embms_svc_interest_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_embms_svc_interest_ind_msg_v01, tranx_id) - QMI_IDL_OFFSET8(wds_embms_svc_interest_ind_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_embms_svc_interest_ind_msg_v01, tranx_id)
};

static const uint8_t wds_embms_svc_interest_info_req_msg_data_v01[] = {
  0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_svc_interest_info_req_msg_v01, tmgi_list),
  QMI_WDS_EMBMS_SVC_INTEREST_MAX_V01,
  QMI_IDL_OFFSET8(wds_embms_svc_interest_info_req_msg_v01, tmgi_list) - QMI_IDL_OFFSET8(wds_embms_svc_interest_info_req_msg_v01, tmgi_list_len),
  QMI_IDL_TYPE88(0, 70),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_embms_svc_interest_info_req_msg_v01, tranx_id) - QMI_IDL_OFFSET16RELATIVE(wds_embms_svc_interest_info_req_msg_v01, tranx_id_valid)),
  0x10,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_embms_svc_interest_info_req_msg_v01, tranx_id)
};

static const uint8_t wds_embms_svc_interest_info_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_embms_svc_interest_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_set_downlink_throughput_report_period_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_downlink_throughput_report_period_req_msg_v01, downlink_throughput_report_period) - QMI_IDL_OFFSET8(wds_set_downlink_throughput_report_period_req_msg_v01, downlink_throughput_report_period_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_downlink_throughput_report_period_req_msg_v01, downlink_throughput_report_period)
};

static const uint8_t wds_set_downlink_throughput_report_period_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_downlink_throughput_report_period_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_downlink_throughput_reporting_status_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_downlink_throughput_reporting_status_ind_msg_v01, reporting_status) - QMI_IDL_OFFSET8(wds_downlink_throughput_reporting_status_ind_msg_v01, reporting_status_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_downlink_throughput_reporting_status_ind_msg_v01, reporting_status),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_downlink_throughput_reporting_status_ind_msg_v01, actual_interval) - QMI_IDL_OFFSET8(wds_downlink_throughput_reporting_status_ind_msg_v01, actual_interval_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_downlink_throughput_reporting_status_ind_msg_v01, actual_interval)
};

/*
 * wds_query_downlink_throughput_reporting_status_req_msg is empty
 * static const uint8_t wds_query_downlink_throughput_reporting_status_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_query_downlink_throughput_reporting_status_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_query_downlink_throughput_reporting_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_query_downlink_throughput_reporting_status_resp_msg_v01, reporting_status) - QMI_IDL_OFFSET8(wds_query_downlink_throughput_reporting_status_resp_msg_v01, reporting_status_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_query_downlink_throughput_reporting_status_resp_msg_v01, reporting_status),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_query_downlink_throughput_reporting_status_resp_msg_v01, actual_interval) - QMI_IDL_OFFSET8(wds_query_downlink_throughput_reporting_status_resp_msg_v01, actual_interval_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_query_downlink_throughput_reporting_status_resp_msg_v01, actual_interval)
};

static const uint8_t wds_keep_alive_data_session_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_keep_alive_data_session_req_msg_v01, keep_alive)
};

static const uint8_t wds_keep_alive_data_session_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_keep_alive_data_session_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_set_always_on_pdn_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_always_on_pdn_req_msg_v01, profile_index_3gpp) - QMI_IDL_OFFSET8(wds_set_always_on_pdn_req_msg_v01, profile_index_3gpp_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_always_on_pdn_req_msg_v01, profile_index_3gpp),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_always_on_pdn_req_msg_v01, applicable_rat_mask) - QMI_IDL_OFFSET8(wds_set_always_on_pdn_req_msg_v01, applicable_rat_mask_valid)),
  0x11,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_set_always_on_pdn_req_msg_v01, applicable_rat_mask)
};

static const uint8_t wds_set_always_on_pdn_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_always_on_pdn_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_apn_op_reserved_pco_list_change_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_apn_op_reserved_pco_list_change_ind_msg_v01, pco_list),
  QMI_IDL_TYPE88(0, 9)
};

static const uint8_t wds_get_apn_op_reserved_pco_list_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_op_reserved_pco_list_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_get_apn_op_reserved_pco_list_req_msg_v01, apn_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_apn_op_reserved_pco_list_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01
};

static const uint8_t wds_get_apn_op_reserved_pco_list_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_apn_op_reserved_pco_list_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_op_reserved_pco_list_resp_msg_v01, pco_list_info) - QMI_IDL_OFFSET8(wds_get_apn_op_reserved_pco_list_resp_msg_v01, pco_list_info_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_apn_op_reserved_pco_list_resp_msg_v01, pco_list_info),
  QMI_IDL_TYPE88(0, 8)
};

static const uint8_t wds_apn_msisdn_change_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_apn_msisdn_change_ind_msg_v01, apn_msisdn_info),
  QMI_IDL_TYPE88(0, 11)
};

static const uint8_t wds_get_apn_msisdn_info_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_msisdn_info_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_get_apn_msisdn_info_req_msg_v01, apn_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_apn_msisdn_info_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01
};

static const uint8_t wds_get_apn_msisdn_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_apn_msisdn_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_msisdn_info_resp_msg_v01, msisdn) - QMI_IDL_OFFSET8(wds_get_apn_msisdn_info_resp_msg_v01, msisdn_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_apn_msisdn_info_resp_msg_v01, msisdn),
  QMI_WDS_MSISDN_INFO_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_apn_msisdn_info_resp_msg_v01, msisdn) - QMI_IDL_OFFSET8(wds_get_apn_msisdn_info_resp_msg_v01, msisdn_len)
};

/*
 * wds_tear_down_always_on_pdn_req_msg is empty
 * static const uint8_t wds_tear_down_always_on_pdn_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_tear_down_always_on_pdn_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_tear_down_always_on_pdn_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_lte_attach_params_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, attach_params_valid),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, apn_string) - QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, apn_string_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ip_type) - QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ip_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ip_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv4_address) - QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv4_address_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv4_gateway_addr) - QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv4_gateway_addr_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv4_gateway_addr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv4_subnet_mask) - QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv4_subnet_mask_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv4_subnet_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv6_addr) - QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv6_addr_valid)),
  0x15,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_lte_attach_params_ind_msg_v01, ipv6_addr),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_lte_attach_params_ind_msg_v01, ipv6_gateway_addr) - QMI_IDL_OFFSET16RELATIVE(wds_lte_attach_params_ind_msg_v01, ipv6_gateway_addr_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_lte_attach_params_ind_msg_v01, ipv6_gateway_addr),
  QMI_IDL_TYPE88(0, 13)
};

static const uint8_t wds_reset_and_modify_profile_settings_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, profile),
  QMI_IDL_TYPE88(0, 45),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, profile_name) - QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, profile_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, profile_name),
  QMI_WDS_PROFILE_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_type) - QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_hdr_compression_type) - QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_hdr_compression_type_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_hdr_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_data_compression_type) - QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_data_compression_type_valid)),
  0x13,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_data_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, apn_name_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_requested_qos_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, umts_requested_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_minimum_qos_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, umts_minimum_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, gprs_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, gprs_requested_qos_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, gprs_requested_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, gprs_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, gprs_minimum_qos_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, gprs_minimum_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, username) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, username_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, password) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, password_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, authentication_preference_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipv4_address_preference_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, ipv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pcscf_addr_using_pco_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_access_control_flag) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_access_control_flag_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_access_control_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, im_cn_flag_valid)),
  0x22,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, tft_id1_params) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, tft_id1_params_valid)),
  0x23,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, tft_id1_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, tft_id2_params) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, tft_id2_params_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, tft_id2_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_context) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_context_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdp_context),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_flag) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_flag_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_id) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_id_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, primary_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipv6_address_preference_valid)),
  0x28,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_requested_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_requested_qos_with_sig_ind_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, umts_requested_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_minimum_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_minimum_qos_with_sig_ind_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, umts_minimum_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_dns_ipv6_address_preference_valid)),
  0x2B,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secodnary_dns_ipv6_address_preference_valid)),
  0x2C,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, addr_allocation_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, addr_allocation_preference_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, addr_allocation_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, threegpp_lte_qos_params) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, threegpp_lte_qos_params_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, threegpp_lte_qos_params),
  QMI_IDL_TYPE88(0, 41),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_disabled_flag_valid)),
  0x2F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout_valid)),
  0x30,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_class_valid)),
  0x31,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_bearer) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_bearer_valid)),
  0x35,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, apn_bearer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, support_emergency_calls) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, support_emergency_calls_valid)),
  0x36,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, support_emergency_calls),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, op_pco_id_valid)),
  0x37,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mcc_valid)),
  0x38,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit_valid)),
  0x39,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, max_pdn_conn_per_block) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, max_pdn_conn_per_block_valid)),
  0x3A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, max_pdn_conn_per_block),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, max_pdn_conn_timer) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, max_pdn_conn_timer_valid)),
  0x3B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, max_pdn_conn_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_req_wait_interval) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_req_wait_interval_valid)),
  0x3C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_req_wait_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, app_user_data_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, app_user_data_3gpp_valid)),
  0x3D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, app_user_data_3gpp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, roaming_disallowed) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, roaming_disallowed_valid)),
  0x3E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, roaming_disallowed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_discon_wait_timer) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_discon_wait_timer_valid)),
  0x3F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_discon_wait_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp_valid)),
  0x40,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, lte_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, lte_roaming_pdp_type_valid)),
  0x41,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, lte_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, umts_roaming_pdp_type_valid)),
  0x42,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, umts_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag_valid)),
  0x43,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag_valid)),
  0x44,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, failure_timer_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, failure_timer_3gpp_valid)),
  0x45,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, failure_timer_3gpp),
  QMI_WDS_3GPP_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, override_home_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, override_home_pdp_type_valid)),
  0x46,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, override_home_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, op_reserved_pco_id_list) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, op_reserved_pco_id_list_valid)),
  0x47,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, op_reserved_pco_id_list),
  QMI_WDS_MAX_NUM_PCO_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, msisdn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, msisdn_flag_valid)),
  0x48,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, msisdn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, attach_wo_pdn) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, attach_wo_pdn_valid)),
  0x49,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, attach_wo_pdn),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_label_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_label_3gpp_valid)),
  0x4A,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_label_3gpp),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, eap_auth) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, eap_auth_valid)),
  0x4B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, eap_auth),
  QMI_IDL_TYPE88(0, 44),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, rqos_support) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, rqos_support_valid)),
  0x4C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, rqos_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, mhipv6_support) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, mhipv6_support_valid)),
  0x4D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, mhipv6_support),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, always_on_pdu) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, always_on_pdu_valid)),
  0x4E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, always_on_pdu),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_pcscf_addr_using_dhcp_valid)),
  0x7D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_dns_addr_using_dhcp_valid)),
  0x7E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_pdp_type_valid)),
  0x7F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_app_user_data) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_app_user_data_valid)),
  0x80,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_app_user_data),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_pco_mnc_includes_pcs_digit_valid)),
  0x81,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_pco_mcc_valid)),
  0x82,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_op_pco_id_valid)),
  0x83,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_auth_password_valid)),
  0x84,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_user_id_valid)),
  0x85,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_auth_protocol_valid)),
  0x86,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_is_pcscf_address_needed_valid)),
  0x87,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, linger_params) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, linger_params_valid)),
  0x88,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, linger_params),
  QMI_IDL_TYPE88(0, 43),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_secodnary_dns_ipv6_address_preference_valid)),
  0x89,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_primary_dns_ipv6_address_preference_valid)),
  0x8A,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_secondary_DNS_IPv4_address_preference_valid)),
  0x8B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_primary_DNS_IPv4_address_preference_valid)),
  0x8C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_apn_class_valid)),
  0x8D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, common_apn_disabled_flag_valid)),
  0x8E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, common_apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, negotiate_dns_server_preference) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, negotiate_dns_server_preference_valid)),
  0x90,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, negotiate_dns_server_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ppp_session_close_timer_DO) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ppp_session_close_timer_DO_valid)),
  0x91,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, ppp_session_close_timer_DO),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ppp_session_close_timer_1x) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ppp_session_close_timer_1x_valid)),
  0x92,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, ppp_session_close_timer_1x),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, allow_linger) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, allow_linger_valid)),
  0x93,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, allow_linger),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, lcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, lcp_ack_timeout_valid)),
  0x94,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, lcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipcp_ack_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipcp_ack_timeout_valid)),
  0x95,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, ipcp_ack_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, auth_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, auth_timeout_valid)),
  0x96,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, auth_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, lcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, lcp_creq_retry_count_valid)),
  0x97,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, lcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipcp_creq_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipcp_creq_retry_count_valid)),
  0x98,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, ipcp_creq_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, auth_retry_count) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, auth_retry_count_valid)),
  0x99,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, auth_retry_count),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, auth_protocol_valid)),
  0x9A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, user_id) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, user_id_valid)),
  0x9B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, auth_password_valid)),
  0x9C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, data_rate) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, data_rate_valid)),
  0x9D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, data_rate),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, app_type) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, app_type_valid)),
  0x9E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, app_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, data_mode) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, data_mode_valid)),
  0x9F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, data_mode),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, app_priority) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, app_priority_valid)),
  0xA0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, app_priority),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_string) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_string_valid)),
  0xA1,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, apn_string),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_type) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_type_valid)),
  0xA2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, is_pcscf_address_needed) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, is_pcscf_address_needed_valid)),
  0xA3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, is_pcscf_address_needed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_v4_dns_address_valid)),
  0xA4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, primary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_v4_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_v4_dns_address_valid)),
  0xA5,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_v4_dns_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, primary_v6_dns_address_valid)),
  0xA6,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, primary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_v6_dns_address) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_v6_dns_address_valid)),
  0xA7,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, secondary_v6_dns_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, rat_type) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, rat_type_valid)),
  0xA8,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, rat_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_enabled_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_enabled_3gpp2_valid)),
  0xA9,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, apn_enabled_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout_3gpp2_valid)),
  0xAA,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_inactivity_timeout_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_class_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_class_3gpp2_valid)),
  0xAB,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, apn_class_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_level_auth_protocol) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_level_auth_protocol_valid)),
  0xAD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_level_auth_protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_level_user_id) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_level_user_id_valid)),
  0xAE,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_level_user_id),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_level_auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_level_auth_password_valid)),
  0xAF,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_level_auth_password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_label) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_label_valid)),
  0xB0,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pdn_label),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, op_pco_id_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, op_pco_id_3gpp2_valid)),
  0xBD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, op_pco_id_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mcc_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mcc_3gpp2_valid)),
  0xBE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mcc_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit_3gpp2_valid)),
  0xBF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pco_mnc_includes_pcs_digit_3gpp2),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, failure_timer) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, failure_timer_valid)),
  0xC0,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, failure_timer),
  QMI_WDS_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, disallow_timer) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, disallow_timer_valid)),
  0xC1,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, disallow_timer),
  QMI_WDS_MAX_DISALLOW_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, app_user_data_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, app_user_data_3gpp2_valid)),
  0xC2,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, app_user_data_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp_3gpp2_valid)),
  0xC3,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, pcscf_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp_3gpp2) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp_3gpp2_valid)),
  0xC4,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, dns_addr_using_dhcp_3gpp2),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_type_mask) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, apn_type_mask_valid)),
  0xDD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, apn_type_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, clat_enabled) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, clat_enabled_valid)),
  0xDE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, clat_enabled),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipv6_prefix_delegation) - QMI_IDL_OFFSET16RELATIVE(wds_reset_and_modify_profile_settings_req_msg_v01, ipv6_prefix_delegation_valid)),
  0xDF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_reset_and_modify_profile_settings_req_msg_v01, ipv6_prefix_delegation)
};

static const uint8_t wds_reset_and_modify_profile_settings_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_reset_and_modify_profile_settings_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_set_attach_profile_info_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, profile_name) - QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, profile_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, profile_name),
  QMI_WDS_PROFILE_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, pdp_type) - QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, pdp_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, pdp_hdr_compression_type) - QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, pdp_hdr_compression_type_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, pdp_hdr_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, pdp_data_compression_type) - QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, pdp_data_compression_type_valid)),
  0x13,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, pdp_data_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, apn_name_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_set_attach_profile_info_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_requested_qos_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, umts_requested_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_minimum_qos_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, umts_minimum_qos),
  QMI_IDL_TYPE88(0, 37),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, gprs_requested_qos) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, gprs_requested_qos_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, gprs_requested_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, gprs_minimum_qos) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, gprs_minimum_qos_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, gprs_minimum_qos),
  QMI_IDL_TYPE88(0, 39),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, username) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, username_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, password) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, password_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, authentication_preference_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, ipv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, ipv4_address_preference_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, ipv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pcscf_addr_using_pco_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdp_access_control_flag) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdp_access_control_flag_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, pdp_access_control_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pcscf_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pcscf_addr_using_dhcp_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, pcscf_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, im_cn_flag_valid)),
  0x22,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, tft_id1_params) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, tft_id1_params_valid)),
  0x23,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, tft_id1_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, tft_id2_params) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, tft_id2_params_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, tft_id2_params),
  QMI_IDL_TYPE88(0, 40),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdp_context) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdp_context_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, pdp_context),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, secondary_flag) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, secondary_flag_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, secondary_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, primary_id) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, primary_id_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, primary_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, ipv6_address_preference_valid)),
  0x28,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_requested_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_requested_qos_with_sig_ind_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, umts_requested_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_minimum_qos_with_sig_ind) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_minimum_qos_with_sig_ind_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, umts_minimum_qos_with_sig_ind),
  QMI_IDL_TYPE88(0, 38),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, primary_dns_ipv6_address_preference_valid)),
  0x2B,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, secodnary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, secodnary_dns_ipv6_address_preference_valid)),
  0x2C,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, secodnary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, addr_allocation_preference) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, addr_allocation_preference_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, addr_allocation_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, threegpp_lte_qos_params) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, threegpp_lte_qos_params_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, threegpp_lte_qos_params),
  QMI_IDL_TYPE88(0, 41),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, apn_disabled_flag_valid)),
  0x2F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdn_inactivity_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdn_inactivity_timeout_valid)),
  0x30,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, pdn_inactivity_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, apn_class_valid)),
  0x31,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, apn_bearer) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, apn_bearer_valid)),
  0x35,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, apn_bearer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, support_emergency_calls) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, support_emergency_calls_valid)),
  0x36,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, support_emergency_calls),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, op_pco_id_valid)),
  0x37,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pco_mcc_valid)),
  0x38,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pco_mnc_includes_pcs_digit_valid)),
  0x39,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, max_pdn_conn_per_block) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, max_pdn_conn_per_block_valid)),
  0x3A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, max_pdn_conn_per_block),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, max_pdn_conn_timer) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, max_pdn_conn_timer_valid)),
  0x3B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, max_pdn_conn_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdn_req_wait_interval) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdn_req_wait_interval_valid)),
  0x3C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, pdn_req_wait_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, app_user_data_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, app_user_data_3gpp_valid)),
  0x3D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, app_user_data_3gpp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, roaming_disallowed) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, roaming_disallowed_valid)),
  0x3E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, roaming_disallowed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdn_discon_wait_timer) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, pdn_discon_wait_timer_valid)),
  0x3F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, pdn_discon_wait_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, dns_addr_using_dhcp) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, dns_addr_using_dhcp_valid)),
  0x40,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, dns_addr_using_dhcp),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, lte_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, lte_roaming_pdp_type_valid)),
  0x41,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, lte_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, umts_roaming_pdp_type_valid)),
  0x42,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, umts_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag_valid)),
  0x43,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, iwlan_to_lte_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag_valid)),
  0x44,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, lte_to_iwlan_roaming_ho_allowed_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, failure_timer_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, failure_timer_3gpp_valid)),
  0x45,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, failure_timer_3gpp),
  QMI_WDS_3GPP_MAX_FAILURE_TIMER_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, override_home_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, override_home_pdp_type_valid)),
  0x46,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, override_home_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, op_reserved_pco_id_list) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, op_reserved_pco_id_list_valid)),
  0x47,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, op_reserved_pco_id_list),
  QMI_WDS_MAX_NUM_PCO_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, msisdn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, msisdn_flag_valid)),
  0x48,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, msisdn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, append_flag) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, append_flag_valid)),
  0x90,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, append_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_config_action) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_config_action_valid)),
  0x91,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, attach_config_action),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_apn_ip_addr_rules) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_apn_ip_addr_rules_valid)),
  0x92,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, attach_apn_ip_addr_rules),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_apn_dns_addr_rules) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_apn_dns_addr_rules_valid)),
  0x93,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, attach_apn_dns_addr_rules),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_apn_pcscf_addr_rules) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_apn_pcscf_addr_rules_valid)),
  0x94,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, attach_apn_pcscf_addr_rules),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_apn_pcscf_or_dns_addr_rules) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, attach_apn_pcscf_or_dns_addr_rules_valid)),
  0x95,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, attach_apn_pcscf_or_dns_addr_rules),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_ip_addr_rules) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_ip_addr_rules_valid)),
  0x96,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_ip_addr_rules),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_dns_addr_rules) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_dns_addr_rules_valid)),
  0x97,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_dns_addr_rules),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_pcscf_addr_rules) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_pcscf_addr_rules_valid)),
  0x98,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_pcscf_addr_rules),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_pcscf_or_dns_addr_rules) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_pcscf_or_dns_addr_rules_valid)),
  0x99,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, on_demand_apn_pcscf_or_dns_addr_rules),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, apn_type_mask) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, apn_type_mask_valid)),
  0xDD,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, apn_type_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, clat_enabled) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, clat_enabled_valid)),
  0xDE,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, clat_enabled),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, ipv6_prefix_delegation) - QMI_IDL_OFFSET16RELATIVE(wds_set_attach_profile_info_req_msg_v01, ipv6_prefix_delegation_valid)),
  0xDF,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_attach_profile_info_req_msg_v01, ipv6_prefix_delegation)
};

static const uint8_t wds_set_attach_profile_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_attach_profile_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_attach_profile_info_resp_msg_v01, profile_index) - QMI_IDL_OFFSET8(wds_set_attach_profile_info_resp_msg_v01, profile_index_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_attach_profile_info_resp_msg_v01, profile_index),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_attach_profile_info_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_set_attach_profile_info_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_set_attach_profile_info_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_delete_all_profiles_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_delete_all_profiles_req_msg_v01, profile_type_mask),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_delete_all_profiles_req_msg_v01, profile_persistence_mask) - QMI_IDL_OFFSET8(wds_delete_all_profiles_req_msg_v01, profile_persistence_mask_valid)),
  0x10,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_delete_all_profiles_req_msg_v01, profile_persistence_mask),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_delete_all_profiles_req_msg_v01, profile_client_type_mask) - QMI_IDL_OFFSET8(wds_delete_all_profiles_req_msg_v01, profile_client_type_mask_valid)),
  0x11,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_delete_all_profiles_req_msg_v01, profile_client_type_mask)
};

static const uint8_t wds_delete_all_profiles_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_delete_all_profiles_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_delete_all_profiles_result_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_delete_all_profiles_result_ind_msg_v01, status),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_delete_all_profiles_result_ind_msg_v01, deleted_profiles_list) - QMI_IDL_OFFSET8(wds_delete_all_profiles_result_ind_msg_v01, deleted_profiles_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_delete_all_profiles_result_ind_msg_v01, deleted_profiles_list),
  QMI_WDS_DELETE_ALL_PROFILES_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_delete_all_profiles_result_ind_msg_v01, deleted_profiles_list) - QMI_IDL_OFFSET8(wds_delete_all_profiles_result_ind_msg_v01, deleted_profiles_list_len),
  QMI_IDL_TYPE88(0, 98)
};

static const uint8_t wds_3gpp_rab_reject_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_3gpp_rab_reject_ind_msg_v01, rab_reject_cause)
};

/*
 * wds_get_last_3gpp_rab_reject_info_req_msg is empty
 * static const uint8_t wds_get_last_3gpp_rab_reject_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_last_3gpp_rab_reject_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_last_3gpp_rab_reject_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_last_3gpp_rab_reject_info_resp_msg_v01, rab_reject_cause) - QMI_IDL_OFFSET8(wds_get_last_3gpp_rab_reject_info_resp_msg_v01, rab_reject_cause_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_last_3gpp_rab_reject_info_resp_msg_v01, rab_reject_cause)
};

/*
 * wds_get_throttled_pdn_reject_timer_req_msg is empty
 * static const uint8_t wds_get_throttled_pdn_reject_timer_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_throttled_pdn_reject_timer_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_throttled_pdn_reject_timer_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_throttled_pdn_reject_timer_resp_msg_v01, throttled_pdn_reject_timer) - QMI_IDL_OFFSET8(wds_get_throttled_pdn_reject_timer_resp_msg_v01, throttled_pdn_reject_timer_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_throttled_pdn_reject_timer_resp_msg_v01, throttled_pdn_reject_timer)
};

static const uint8_t wds_set_throttled_pdn_reject_timer_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_throttled_pdn_reject_timer_req_msg_v01, throttled_pdn_reject_timer)
};

static const uint8_t wds_set_throttled_pdn_reject_timer_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_throttled_pdn_reject_timer_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_set_ehrpd_fallback_apn_list_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_ehrpd_fallback_apn_list_req_msg_v01, fallback_apn_name_list),
  QMI_WDS_EHRPD_FALLBACK_APN_MAX_V01,
  QMI_IDL_OFFSET8(wds_set_ehrpd_fallback_apn_list_req_msg_v01, fallback_apn_name_list) - QMI_IDL_OFFSET8(wds_set_ehrpd_fallback_apn_list_req_msg_v01, fallback_apn_name_list_len),
  QMI_IDL_TYPE88(0, 15)
};

static const uint8_t wds_set_ehrpd_fallback_apn_list_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_ehrpd_fallback_apn_list_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_ehrpd_fallback_apn_list_req_msg is empty
 * static const uint8_t wds_get_ehrpd_fallback_apn_list_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_ehrpd_fallback_apn_list_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_ehrpd_fallback_apn_list_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ehrpd_fallback_apn_list_resp_msg_v01, fallback_apn_name_list) - QMI_IDL_OFFSET8(wds_get_ehrpd_fallback_apn_list_resp_msg_v01, fallback_apn_name_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_ehrpd_fallback_apn_list_resp_msg_v01, fallback_apn_name_list),
  QMI_WDS_EHRPD_FALLBACK_APN_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_ehrpd_fallback_apn_list_resp_msg_v01, fallback_apn_name_list) - QMI_IDL_OFFSET8(wds_get_ehrpd_fallback_apn_list_resp_msg_v01, fallback_apn_name_list_len),
  QMI_IDL_TYPE88(0, 15)
};

static const uint8_t wds_subsequent_data_transfer_status_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET8(wds_subsequent_data_transfer_status_req_msg_v01, subsequent_data_transfer_status_type_mask)
};

static const uint8_t wds_subsequent_data_transfer_status_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_subsequent_data_transfer_status_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_modem_assisted_ka_start_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, keep_alive_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, timer_value) - QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, timer_value_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, timer_value),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, dest_ipv4_address) - QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, dest_ipv4_address_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, dest_ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, dest_ipv6_address) - QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, dest_ipv6_address_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, dest_ipv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, source_ipv4_address) - QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, source_ipv4_address_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, source_ipv4_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, source_ipv6_address) - QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, source_ipv6_address_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, source_ipv6_address),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, dest_port) - QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, dest_port_valid)),
  0x15,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, dest_port),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, source_port) - QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, source_port_valid)),
  0x16,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, source_port),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, apn_name_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01
};

static const uint8_t wds_modem_assisted_ka_start_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_resp_msg_v01, keep_alive_handle) - QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_resp_msg_v01, keep_alive_handle_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_start_resp_msg_v01, keep_alive_handle)
};

static const uint8_t wds_modem_assisted_ka_status_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_status_ind_msg_v01, status),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_status_ind_msg_v01, keep_alive_handle)
};

static const uint8_t wds_modem_assisted_ka_stop_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_stop_req_msg_v01, keep_alive_handle)
};

static const uint8_t wds_modem_assisted_ka_stop_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_modem_assisted_ka_stop_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_v2x_sps_flow_reg_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, req_id),

  0x02,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, priority),

  0x03,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, periodicity),

  0x04,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, msg_size),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, service_id) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, service_id_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, service_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, sps_port) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, sps_port_valid)),
  0x11,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, sps_port),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, evt_driven_port) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, evt_driven_port_valid)),
  0x12,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, evt_driven_port),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, protocol) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, protocol_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, peak_tx_power) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, peak_tx_power_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, peak_tx_power),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, mcs_index) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, mcs_index_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, mcs_index),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, retx_setting) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, retx_setting_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, retx_setting),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, tx_pool_id) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, tx_pool_id_valid)),
  0x17,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_req_msg_v01, tx_pool_id)
};

static const uint8_t wds_v2x_sps_flow_reg_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_v2x_sps_flow_reg_result_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_reg_result_ind_msg_v01, reg_result),
  QMI_IDL_TYPE88(0, 4)
};

static const uint8_t wds_v2x_sps_flow_dereg_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_dereg_req_msg_v01, flow_id),
  QMI_IDL_TYPE88(0, 3)
};

static const uint8_t wds_v2x_sps_flow_dereg_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_dereg_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_v2x_sps_flow_dereg_result_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_dereg_result_ind_msg_v01, dereg_result),
  QMI_IDL_TYPE88(0, 4)
};

static const uint8_t wds_v2x_sps_flow_update_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, flow_id),
  QMI_IDL_TYPE88(0, 3),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, periodicity) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, periodicity_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, periodicity),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, msg_size) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, msg_size_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, msg_size),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, peak_tx_power) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, peak_tx_power_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, peak_tx_power),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, mcs_index) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, mcs_index_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, mcs_index),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, retx_setting) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, retx_setting_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, retx_setting),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, tx_pool_id) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, tx_pool_id_valid)),
  0x15,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_req_msg_v01, tx_pool_id)
};

static const uint8_t wds_v2x_sps_flow_update_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_v2x_sps_flow_update_result_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_update_result_ind_msg_v01, update_result),
  QMI_IDL_TYPE88(0, 4)
};

static const uint8_t wds_v2x_sps_flow_get_info_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_req_msg_v01, flow_id),
  QMI_IDL_TYPE88(0, 3)
};

static const uint8_t wds_v2x_sps_flow_get_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, priority) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, priority_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, priority),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, periodicity) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, periodicity_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, periodicity),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, msg_size) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, msg_size_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, msg_size),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, service_id) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, service_id_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, service_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, sps_port) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, sps_port_valid)),
  0x14,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, sps_port),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, evt_driven_port) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, evt_driven_port_valid)),
  0x15,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, evt_driven_port),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, protocol) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, protocol_valid)),
  0x16,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, peak_tx_power) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, peak_tx_power_valid)),
  0x17,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, peak_tx_power),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, mcs_index) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, mcs_index_valid)),
  0x18,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, mcs_index),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, retx_setting) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, retx_setting_valid)),
  0x19,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, retx_setting),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, tx_pool_id) - QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, tx_pool_id_valid)),
  0x1A,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_sps_flow_get_info_resp_msg_v01, tx_pool_id)
};

static const uint8_t wds_v2x_non_sps_flow_reg_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_req_msg_v01, req_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_req_msg_v01, non_sps_flow_info) - QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_req_msg_v01, non_sps_flow_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_req_msg_v01, non_sps_flow_info),
  WDS_V2X_NON_SPS_MAX_FLOWS_V01,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_req_msg_v01, non_sps_flow_info) - QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_req_msg_v01, non_sps_flow_info_len),
  QMI_IDL_TYPE88(0, 99),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, non_sps_flow) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, non_sps_flow_valid)),
  0x11,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_non_sps_flow_reg_req_msg_v01, non_sps_flow),
  QMI_IDL_TYPE88(0, 99),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, peak_tx_power) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, peak_tx_power_valid)),
  0x12,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_non_sps_flow_reg_req_msg_v01, peak_tx_power),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, mcs_index) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, mcs_index_valid)),
  0x13,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_non_sps_flow_reg_req_msg_v01, mcs_index),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, retx_setting) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, retx_setting_valid)),
  0x14,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_non_sps_flow_reg_req_msg_v01, retx_setting),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, tx_pool_id) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_req_msg_v01, tx_pool_id_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_non_sps_flow_reg_req_msg_v01, tx_pool_id)
};

static const uint8_t wds_v2x_non_sps_flow_reg_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_resp_msg_v01, reg_result) - QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_resp_msg_v01, reg_result_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_resp_msg_v01, reg_result),
  WDS_V2X_NON_SPS_MAX_FLOWS_V01,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_resp_msg_v01, reg_result) - QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_reg_resp_msg_v01, reg_result_len),
  QMI_IDL_TYPE88(0, 1),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_resp_msg_v01, result) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_non_sps_flow_reg_resp_msg_v01, result_valid)),
  0x11,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_non_sps_flow_reg_resp_msg_v01, result),
  QMI_IDL_TYPE88(0, 1)
};

static const uint8_t wds_v2x_non_sps_flow_dereg_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_req_msg_v01, req_id),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_req_msg_v01, non_sps_flow_info) - QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_req_msg_v01, non_sps_flow_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_req_msg_v01, non_sps_flow_info),
  WDS_V2X_NON_SPS_MAX_FLOWS_V01,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_req_msg_v01, non_sps_flow_info) - QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_req_msg_v01, non_sps_flow_info_len),
  QMI_IDL_TYPE88(0, 2)
};

static const uint8_t wds_v2x_non_sps_flow_dereg_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_resp_msg_v01, dereg_result) - QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_resp_msg_v01, dereg_result_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_resp_msg_v01, dereg_result),
  WDS_V2X_NON_SPS_MAX_FLOWS_V01,
  QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_resp_msg_v01, dereg_result) - QMI_IDL_OFFSET8(wds_v2x_non_sps_flow_dereg_resp_msg_v01, dereg_result_len),
  QMI_IDL_TYPE88(0, 1)
};

static const uint8_t wds_v2x_service_subscribe_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_service_subscribe_req_msg_v01, service_info),
  QMI_IDL_TYPE88(0, 100),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_service_subscribe_req_msg_v01, service_id_list) - QMI_IDL_OFFSET8(wds_v2x_service_subscribe_req_msg_v01, service_id_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_service_subscribe_req_msg_v01, service_id_list),
  QMI_WDS_V2X_MAX_SUB_V01,
  QMI_IDL_OFFSET8(wds_v2x_service_subscribe_req_msg_v01, service_id_list) - QMI_IDL_OFFSET8(wds_v2x_service_subscribe_req_msg_v01, service_id_list_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_service_subscribe_req_msg_v01, port) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_service_subscribe_req_msg_v01, port_valid)),
  0x11,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_service_subscribe_req_msg_v01, port)
};

static const uint8_t wds_v2x_service_subscribe_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_service_subscribe_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_v2x_service_subscribe_result_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_service_subscribe_result_ind_msg_v01, req_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_service_subscribe_result_ind_msg_v01, subscribe_wildcard_result) - QMI_IDL_OFFSET8(wds_v2x_service_subscribe_result_ind_msg_v01, subscribe_wildcard_result_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_service_subscribe_result_ind_msg_v01, subscribe_wildcard_result),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_service_subscribe_result_ind_msg_v01, reg_result) - QMI_IDL_OFFSET8(wds_v2x_service_subscribe_result_ind_msg_v01, reg_result_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_service_subscribe_result_ind_msg_v01, reg_result),
  QMI_WDS_V2X_MAX_SUB_V01,
  QMI_IDL_OFFSET8(wds_v2x_service_subscribe_result_ind_msg_v01, reg_result) - QMI_IDL_OFFSET8(wds_v2x_service_subscribe_result_ind_msg_v01, reg_result_len),
  QMI_IDL_TYPE88(0, 1)
};

/*
 * wds_v2x_service_get_subscribe_list_req_msg is empty
 * static const uint8_t wds_v2x_service_get_subscribe_list_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_v2x_service_get_subscribe_list_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_service_get_subscribe_list_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_service_get_subscribe_list_resp_msg_v01, wildcard_enabled) - QMI_IDL_OFFSET8(wds_v2x_service_get_subscribe_list_resp_msg_v01, wildcard_enabled_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_service_get_subscribe_list_resp_msg_v01, wildcard_enabled),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_service_get_subscribe_list_resp_msg_v01, service_id) - QMI_IDL_OFFSET8(wds_v2x_service_get_subscribe_list_resp_msg_v01, service_id_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_service_get_subscribe_list_resp_msg_v01, service_id),
  QMI_WDS_V2X_MAX_SUB_V01,
  QMI_IDL_OFFSET8(wds_v2x_service_get_subscribe_list_resp_msg_v01, service_id) - QMI_IDL_OFFSET8(wds_v2x_service_get_subscribe_list_resp_msg_v01, service_id_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_service_get_subscribe_list_resp_msg_v01, dest_port) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_service_get_subscribe_list_resp_msg_v01, dest_port_valid)),
  0x12,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_service_get_subscribe_list_resp_msg_v01, dest_port)
};

static const uint8_t wds_set_data_low_latency_mode_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, ul_latency_level) - QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, ul_latency_level_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, ul_latency_level),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, dl_latency_level) - QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, dl_latency_level_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, dl_latency_level),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, prioritize_ps_data) - QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, prioritize_ps_data_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, prioritize_ps_data),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, enable_connection_extension) - QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, enable_connection_extension_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_req_msg_v01, enable_connection_extension)
};

static const uint8_t wds_set_data_low_latency_mode_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_data_low_latency_mode_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_data_low_latency_mode_req_msg is empty
 * static const uint8_t wds_get_data_low_latency_mode_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_data_low_latency_mode_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, ul_latency_level) - QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, ul_latency_level_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, ul_latency_level),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, dl_latency_level) - QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, dl_latency_level_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, dl_latency_level),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, prioritize_ps_data) - QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, prioritize_ps_data_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, prioritize_ps_data),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, enable_connection_extension) - QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, enable_connection_extension_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_data_low_latency_mode_resp_msg_v01, enable_connection_extension)
};

/*
 * wds_get_avail_ext_ipv6_addr_req_msg is empty
 * static const uint8_t wds_get_avail_ext_ipv6_addr_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_avail_ext_ipv6_addr_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_avail_ext_ipv6_addr_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_avail_ext_ipv6_addr_resp_msg_v01, ext_ipv6_addr_list) - QMI_IDL_OFFSET8(wds_get_avail_ext_ipv6_addr_resp_msg_v01, ext_ipv6_addr_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_avail_ext_ipv6_addr_resp_msg_v01, ext_ipv6_addr_list),
  WDS_EXT_IPV6_ADDRS_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_avail_ext_ipv6_addr_resp_msg_v01, ext_ipv6_addr_list) - QMI_IDL_OFFSET8(wds_get_avail_ext_ipv6_addr_resp_msg_v01, ext_ipv6_addr_list_len),
  QMI_IDL_TYPE88(0, 13)
};

static const uint8_t wds_create_profile_lite_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, apn_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, pdp_hdr_compression_type) - QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, pdp_hdr_compression_type_valid)),
  0x11,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, pdp_hdr_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, pdp_data_compression_type) - QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, pdp_data_compression_type_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, pdp_data_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, username) - QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, username_valid)),
  0x15,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_create_profile_lite_req_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, password) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, password_valid)),
  0x16,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, authentication_preference_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pcscf_addr_using_pco_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pdp_access_control_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pdp_access_control_flag_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, pdp_access_control_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, im_cn_flag_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, primary_dns_ipv6_address_preference_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, secondary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, secondary_dns_ipv6_address_preference_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, secondary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, apn_disabled_flag_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pdn_inactivity_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pdn_inactivity_timeout_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, pdn_inactivity_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, apn_class_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, apn_bearer) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, apn_bearer_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, apn_bearer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, op_pco_id_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pco_mcc_valid)),
  0x22,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pco_mnc_includes_pcs_digit_valid)),
  0x23,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, max_pdn_conn_per_block) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, max_pdn_conn_per_block_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, max_pdn_conn_per_block),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, max_pdn_conn_timer) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, max_pdn_conn_timer_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, max_pdn_conn_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pdn_req_wait_interval) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pdn_req_wait_interval_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, pdn_req_wait_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, roaming_disallowed) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, roaming_disallowed_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, roaming_disallowed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pdn_discon_wait_timer) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, pdn_discon_wait_timer_valid)),
  0x28,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, pdn_discon_wait_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, lte_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, lte_roaming_pdp_type_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, lte_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, umts_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, umts_roaming_pdp_type_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, umts_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, override_home_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, override_home_pdp_type_valid)),
  0x2B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, override_home_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, attach_wo_pdn) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, attach_wo_pdn_valid)),
  0x2C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, attach_wo_pdn),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, clat_enabled) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, clat_enabled_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, clat_enabled),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, persistent) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, persistent_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, persistent),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, failure_timer_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_create_profile_lite_req_msg_v01, failure_timer_3gpp_valid)),
  0x2F,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_create_profile_lite_req_msg_v01, failure_timer_3gpp),
  QMI_WDS_3GPP_MAX_FAILURE_TIMER_V01
};

static const uint8_t wds_create_profile_lite_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_create_profile_lite_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_create_profile_lite_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_create_profile_lite_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_create_profile_lite_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_modify_profile_settings_lite_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_req_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_req_msg_v01, apn_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_req_msg_v01, changed_apn_name) - QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_req_msg_v01, changed_apn_name_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_req_msg_v01, changed_apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, changed_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, changed_pdp_type_valid)),
  0x12,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, changed_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdp_hdr_compression_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdp_hdr_compression_type_valid)),
  0x13,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, pdp_hdr_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdp_data_compression_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdp_data_compression_type_valid)),
  0x14,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, pdp_data_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x15,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x16,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, username) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, username_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, password) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, password_valid)),
  0x18,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, password),
  QMI_WDS_PASSWORD_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, authentication_preference_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pcscf_addr_using_pco_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdp_access_control_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdp_access_control_flag_valid)),
  0x1B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, pdp_access_control_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, im_cn_flag_valid)),
  0x1C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, primary_dns_ipv6_address_preference_valid)),
  0x1D,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, secondary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, secondary_dns_ipv6_address_preference_valid)),
  0x1E,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, secondary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, apn_disabled_flag_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdn_inactivity_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdn_inactivity_timeout_valid)),
  0x20,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, pdn_inactivity_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, apn_class_valid)),
  0x21,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, apn_bearer) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, apn_bearer_valid)),
  0x22,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, apn_bearer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, op_pco_id_valid)),
  0x23,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pco_mcc_valid)),
  0x24,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pco_mnc_includes_pcs_digit_valid)),
  0x25,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, max_pdn_conn_per_block) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, max_pdn_conn_per_block_valid)),
  0x26,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, max_pdn_conn_per_block),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, max_pdn_conn_timer) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, max_pdn_conn_timer_valid)),
  0x27,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, max_pdn_conn_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdn_req_wait_interval) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdn_req_wait_interval_valid)),
  0x28,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, pdn_req_wait_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, roaming_disallowed) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, roaming_disallowed_valid)),
  0x29,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, roaming_disallowed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdn_discon_wait_timer) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, pdn_discon_wait_timer_valid)),
  0x2A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, pdn_discon_wait_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, lte_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, lte_roaming_pdp_type_valid)),
  0x2B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, lte_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, umts_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, umts_roaming_pdp_type_valid)),
  0x2C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, umts_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, override_home_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, override_home_pdp_type_valid)),
  0x2D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, override_home_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, attach_wo_pdn) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, attach_wo_pdn_valid)),
  0x2E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, attach_wo_pdn),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, clat_enabled) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, clat_enabled_valid)),
  0x2F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, clat_enabled),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, failure_timer_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_modify_profile_settings_lite_req_msg_v01, failure_timer_3gpp_valid)),
  0x30,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_modify_profile_settings_lite_req_msg_v01, failure_timer_3gpp),
  QMI_WDS_3GPP_MAX_FAILURE_TIMER_V01
};

static const uint8_t wds_modify_profile_settings_lite_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_modify_profile_settings_lite_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_delete_profile_lite_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_delete_profile_lite_req_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_delete_profile_lite_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_delete_profile_lite_req_msg_v01, apn_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_delete_profile_lite_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01
};

static const uint8_t wds_delete_profile_lite_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_delete_profile_lite_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_delete_profile_lite_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET8(wds_delete_profile_lite_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_delete_profile_lite_resp_msg_v01, extended_error_code)
};

static const uint8_t wds_get_profile_settings_lite_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_profile_settings_lite_req_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_lite_req_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_get_profile_settings_lite_req_msg_v01, apn_name_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_profile_settings_lite_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01
};

static const uint8_t wds_get_profile_settings_lite_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, pdp_type) - QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, pdp_type_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, apn_name_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, pdp_hdr_compression_type) - QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, pdp_hdr_compression_type_valid)),
  0x12,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, pdp_hdr_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, pdp_data_compression_type) - QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, pdp_data_compression_type_valid)),
  0x13,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, pdp_data_compression_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, primary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, primary_DNS_IPv4_address_preference_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, primary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, secondary_DNS_IPv4_address_preference) - QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, secondary_DNS_IPv4_address_preference_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_profile_settings_lite_resp_msg_v01, secondary_DNS_IPv4_address_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, username) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, username_valid)),
  0x16,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, username),
  QMI_WDS_USER_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, authentication_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, authentication_preference_valid)),
  0x17,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, authentication_preference),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pcscf_addr_using_pco) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pcscf_addr_using_pco_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, pcscf_addr_using_pco),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pdp_access_control_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pdp_access_control_flag_valid)),
  0x19,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, pdp_access_control_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, im_cn_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, im_cn_flag_valid)),
  0x1A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, im_cn_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, primary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, primary_dns_ipv6_address_preference_valid)),
  0x1B,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, primary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, secondary_dns_ipv6_address_preference) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, secondary_dns_ipv6_address_preference_valid)),
  0x1C,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, secondary_dns_ipv6_address_preference),
  QMI_WDS_IPV6_ADDR_LEN_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, apn_disabled_flag) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, apn_disabled_flag_valid)),
  0x1D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, apn_disabled_flag),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pdn_inactivity_timeout) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pdn_inactivity_timeout_valid)),
  0x1E,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, pdn_inactivity_timeout),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, apn_class) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, apn_class_valid)),
  0x1F,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, apn_class),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, apn_bearer) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, apn_bearer_valid)),
  0x35,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_8_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, apn_bearer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, op_pco_id) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, op_pco_id_valid)),
  0x36,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, op_pco_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pco_mcc) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pco_mcc_valid)),
  0x37,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, pco_mcc),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pco_mnc_includes_pcs_digit) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pco_mnc_includes_pcs_digit_valid)),
  0x38,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, pco_mnc_includes_pcs_digit),
  QMI_IDL_TYPE88(0, 42),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, max_pdn_conn_per_block) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, max_pdn_conn_per_block_valid)),
  0x39,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, max_pdn_conn_per_block),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, max_pdn_conn_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, max_pdn_conn_timer_valid)),
  0x3A,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, max_pdn_conn_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pdn_req_wait_interval) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pdn_req_wait_interval_valid)),
  0x3B,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, pdn_req_wait_interval),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, roaming_disallowed) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, roaming_disallowed_valid)),
  0x3C,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, roaming_disallowed),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pdn_discon_wait_timer) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, pdn_discon_wait_timer_valid)),
  0x3D,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, pdn_discon_wait_timer),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, lte_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, lte_roaming_pdp_type_valid)),
  0x41,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, lte_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, umts_roaming_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, umts_roaming_pdp_type_valid)),
  0x42,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, umts_roaming_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, override_home_pdp_type) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, override_home_pdp_type_valid)),
  0x43,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, override_home_pdp_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, attach_wo_pdn) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, attach_wo_pdn_valid)),
  0x44,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, attach_wo_pdn),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, clat_enabled) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, clat_enabled_valid)),
  0x45,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, clat_enabled),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, extended_error_code),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, persistent) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, persistent_valid)),
  0xE1,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, persistent),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, failure_timer_3gpp) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_settings_lite_resp_msg_v01, failure_timer_3gpp_valid)),
  0xE2,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_settings_lite_resp_msg_v01, failure_timer_3gpp),
  QMI_WDS_3GPP_MAX_FAILURE_TIMER_V01
};

/*
 * wds_get_profile_list_lite_req_msg is empty
 * static const uint8_t wds_get_profile_list_lite_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_profile_list_lite_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_profile_list_lite_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_profile_list_lite_resp_msg_v01, profile_list) - QMI_IDL_OFFSET8(wds_get_profile_list_lite_resp_msg_v01, profile_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_profile_list_lite_resp_msg_v01, profile_list),
  QMI_WDS_PROFILE_LITE_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_profile_list_lite_resp_msg_v01, profile_list) - QMI_IDL_OFFSET8(wds_get_profile_list_lite_resp_msg_v01, profile_list_len),
  QMI_IDL_TYPE88(0, 101),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_get_profile_list_lite_resp_msg_v01, extended_error_code) - QMI_IDL_OFFSET16RELATIVE(wds_get_profile_list_lite_resp_msg_v01, extended_error_code_valid)),
  0xE0,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_2_BYTE_ENUM,
  QMI_IDL_OFFSET16ARRAY(wds_get_profile_list_lite_resp_msg_v01, extended_error_code)
};

/*
 * wds_get_lte_emergency_attach_params_req_msg is empty
 * static const uint8_t wds_get_lte_emergency_attach_params_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_lte_emergency_attach_params_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_lte_emergency_attach_params_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_lte_emergency_attach_params_resp_msg_v01, is_null_algo_used) - QMI_IDL_OFFSET8(wds_get_lte_emergency_attach_params_resp_msg_v01, is_null_algo_used_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_lte_emergency_attach_params_resp_msg_v01, is_null_algo_used)
};

static const uint8_t wds_ran_asst_media_adaptation_reg_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ip_type) - QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ip_type_valid)),
  0x10,
   QMI_IDL_1_BYTE_ENUM,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ip_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv4_src_address) - QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv4_src_address_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv4_src_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv6_src_address) - QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv6_src_address_valid)),
  0x12,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv6_src_address),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv4_dest_address) - QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv4_dest_address_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv4_dest_address),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv6_dest_address) - QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv6_dest_address_valid)),
  0x14,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, ipv6_dest_address),
  QMI_IDL_TYPE88(0, 13),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, protocol) - QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, protocol_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, protocol),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, src_port) - QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, src_port_valid)),
  0x16,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, src_port),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, dest_port) - QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, dest_port_valid)),
  0x17,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_req_msg_v01, dest_port)
};

static const uint8_t wds_ran_asst_media_adaptation_reg_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_resp_msg_v01, handle) - QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_resp_msg_v01, handle_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_reg_resp_msg_v01, handle)
};

static const uint8_t wds_ran_asst_media_adaptation_dereg_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_dereg_req_msg_v01, handle)
};

static const uint8_t wds_ran_asst_media_adaptation_dereg_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adaptation_dereg_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_update_ran_asst_media_adapt_rate_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_update_ran_asst_media_adapt_rate_req_msg_v01, info),
  QMI_IDL_TYPE88(0, 18)
};

static const uint8_t wds_update_ran_asst_media_adapt_rate_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_update_ran_asst_media_adapt_rate_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_ran_asst_media_adapt_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_ran_asst_media_adapt_info_ind_msg_v01, info),
  QMI_IDL_TYPE88(0, 19)
};

static const uint8_t wds_v2x_send_config_file_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_send_config_file_req_msg_v01, tx_id),

  0x02,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_send_config_file_req_msg_v01, file_type),

  0x03,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_send_config_file_req_msg_v01, seg_info),
  QMI_IDL_TYPE88(0, 102),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x04,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN | QMI_IDL_FLAGS_SZ_IS_16 |   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_send_config_file_req_msg_v01, cfg_file_content),
  ((QMI_WDS_V2X_CONFIG_FILE_CONTENT_MAX_V01) & 0xFF), ((QMI_WDS_V2X_CONFIG_FILE_CONTENT_MAX_V01) >> 8),
  QMI_IDL_OFFSET8(wds_v2x_send_config_file_req_msg_v01, cfg_file_content) - QMI_IDL_OFFSET8(wds_v2x_send_config_file_req_msg_v01, cfg_file_content_len)
};

static const uint8_t wds_v2x_send_config_file_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_send_config_file_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_v2x_send_config_file_result_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_send_config_file_result_ind_msg_v01, tx_id),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_send_config_file_result_ind_msg_v01, result)
};

static const uint8_t wds_v2x_sps_scheduling_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_sps_scheduling_info_ind_msg_v01, info),
  QMI_IDL_TYPE88(0, 103)
};

/*
 * wds_v2x_update_src_l2_info_req_msg is empty
 * static const uint8_t wds_v2x_update_src_l2_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_v2x_update_src_l2_info_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_update_src_l2_info_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_v2x_src_l2_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_src_l2_info_ind_msg_v01, src_l2_id)
};

static const uint8_t wds_v2x_tunnel_mode_info_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_tunnel_mode_info_req_msg_v01, malicious_src_l2_id_list) - QMI_IDL_OFFSET8(wds_v2x_tunnel_mode_info_req_msg_v01, malicious_src_l2_id_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_tunnel_mode_info_req_msg_v01, malicious_src_l2_id_list),
  QMI_WDS_V2X_INFO_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_v2x_tunnel_mode_info_req_msg_v01, malicious_src_l2_id_list) - QMI_IDL_OFFSET8(wds_v2x_tunnel_mode_info_req_msg_v01, malicious_src_l2_id_list_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info),
  QMI_WDS_V2X_INFO_LIST_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info_len),
  QMI_IDL_TYPE88(0, 104),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info_ex) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info_ex_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET16ARRAY(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info_ex),
  QMI_WDS_V2X_INFO_LIST_MAX_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info_ex) - QMI_IDL_OFFSET16RELATIVE(wds_v2x_tunnel_mode_info_req_msg_v01, trusted_l2_info_ex_len),
  QMI_IDL_TYPE88(0, 105)
};

static const uint8_t wds_v2x_tunnel_mode_info_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_tunnel_mode_info_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_get_data_bearer_type_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_bearer_type_req_msg_v01, bearer_id) - QMI_IDL_OFFSET8(wds_get_data_bearer_type_req_msg_v01, bearer_id_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_data_bearer_type_req_msg_v01, bearer_id)
};

static const uint8_t wds_get_data_bearer_type_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_bearer_type_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_bearer_type_resp_msg_v01, bearer_type_info) - QMI_IDL_OFFSET8(wds_get_data_bearer_type_resp_msg_v01, bearer_type_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_bearer_type_resp_msg_v01, bearer_type_info),
  QMI_WDS_MAX_BEARERS_V01,
  QMI_IDL_OFFSET8(wds_get_data_bearer_type_resp_msg_v01, bearer_type_info) - QMI_IDL_OFFSET8(wds_get_data_bearer_type_resp_msg_v01, bearer_type_info_len),
  QMI_IDL_TYPE88(0, 16)
};

static const uint8_t wds_data_bearer_type_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_data_bearer_type_ind_msg_v01, bearer_type_info) - QMI_IDL_OFFSET8(wds_data_bearer_type_ind_msg_v01, bearer_type_info_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_data_bearer_type_ind_msg_v01, bearer_type_info),
  QMI_IDL_TYPE88(0, 16)
};

/*
 * wds_v2x_get_capability_info_req_msg is empty
 * static const uint8_t wds_v2x_get_capability_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_v2x_get_capability_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, max_sps_flow_cnt) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, max_sps_flow_cnt_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, max_sps_flow_cnt),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, max_event_driven_flow_cnt) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, max_event_driven_flow_cnt_valid)),
  0x11,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, max_event_driven_flow_cnt),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, is_concurrency_supported) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, is_concurrency_supported_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, is_concurrency_supported),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, pppp_info) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, pppp_info_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, pppp_info),
  QMI_WDS_V2X_PPPP_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, pppp_info) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, pppp_info_len),
  QMI_IDL_TYPE88(0, 6),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, min_tx_pwr) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, min_tx_pwr_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, min_tx_pwr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, max_tx_pwr) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, max_tx_pwr_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, max_tx_pwr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, supported_periodicity_list) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, supported_periodicity_list_valid)),
  0x16,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, supported_periodicity_list),
  QMI_WDS_V2X_PERIODICITY_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, supported_periodicity_list) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, supported_periodicity_list_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, tx_pool_id_list) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, tx_pool_id_list_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, tx_pool_id_list),
  QMI_WDS_V2X_POOL_ID_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, tx_pool_id_list) - QMI_IDL_OFFSET8(wds_v2x_get_capability_info_resp_msg_v01, tx_pool_id_list_len),
  QMI_IDL_TYPE88(0, 5)
};

static const uint8_t wds_v2x_capability_info_ind_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, max_sps_flow_cnt) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, max_sps_flow_cnt_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, max_sps_flow_cnt),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, max_event_driven_flow_cnt) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, max_event_driven_flow_cnt_valid)),
  0x11,
   QMI_IDL_GENERIC_2_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, max_event_driven_flow_cnt),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, is_concurrency_supported) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, is_concurrency_supported_valid)),
  0x12,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, is_concurrency_supported),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, pppp_info) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, pppp_info_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, pppp_info),
  QMI_WDS_V2X_PPPP_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, pppp_info) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, pppp_info_len),
  QMI_IDL_TYPE88(0, 6),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, min_tx_pwr) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, min_tx_pwr_valid)),
  0x14,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, min_tx_pwr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, max_tx_pwr) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, max_tx_pwr_valid)),
  0x15,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, max_tx_pwr),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, supported_periodicity_list) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, supported_periodicity_list_valid)),
  0x16,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, supported_periodicity_list),
  QMI_WDS_V2X_PERIODICITY_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, supported_periodicity_list) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, supported_periodicity_list_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, tx_pool_id_list) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, tx_pool_id_list_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, tx_pool_id_list),
  QMI_WDS_V2X_POOL_ID_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, tx_pool_id_list) - QMI_IDL_OFFSET8(wds_v2x_capability_info_ind_msg_v01, tx_pool_id_list_len),
  QMI_IDL_TYPE88(0, 5)
};

static const uint8_t wds_set_data_coalescing_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_data_coalescing_req_msg_v01, coalescing_info),
  QMI_IDL_TYPE88(2, 1)
};

static const uint8_t wds_set_data_coalescing_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_data_coalescing_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

/*
 * wds_get_data_coalescing_req_msg is empty
 * static const uint8_t wds_get_data_coalescing_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_data_coalescing_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_coalescing_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_data_coalescing_resp_msg_v01, coalescing_info) - QMI_IDL_OFFSET8(wds_get_data_coalescing_resp_msg_v01, coalescing_info_valid)),
  0x10,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_data_coalescing_resp_msg_v01, coalescing_info),
  QMI_IDL_TYPE88(2, 1)
};

/*
 * wds_get_splmn_rate_control_info_req_msg is empty
 * static const uint8_t wds_get_splmn_rate_control_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_splmn_rate_control_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_enabled) - QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_enabled_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_enabled),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_rate) - QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_rate_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_rate),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_pkt_counter) - QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_pkt_counter_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_pkt_counter),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_rate_exceeded) - QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_rate_exceeded_valid)),
  0x13,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_splmn_rate_control_info_resp_msg_v01, splmn_rate_exceeded)
};

/*
 * wds_get_apn_rate_control_info_req_msg is empty
 * static const uint8_t wds_get_apn_rate_control_info_req_msg_data_v01[] = {
 * };
 */

static const uint8_t wds_get_apn_rate_control_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, applies_to_mo_ex) - QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, applies_to_mo_ex_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, applies_to_mo_ex),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, uplink_time) - QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, uplink_time_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, uplink_time),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, max_uplink_rate) - QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, max_uplink_rate_valid)),
  0x12,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, max_uplink_rate),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, pkt_counter) - QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, pkt_counter_valid)),
  0x13,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, pkt_counter),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, apn_rate_exceeded) - QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, apn_rate_exceeded_valid)),
  0x14,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, apn_rate_exceeded),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, apn_name) - QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, apn_name_valid)),
  0x15,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_STRING,
  QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, num_bearers) - QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, num_bearers_valid)),
  0x16,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_apn_rate_control_info_resp_msg_v01, num_bearers)
};

static const uint8_t wds_set_xcap_config_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, tx_info),
  QMI_IDL_TYPE88(0, 106),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, xcap_access_type) - QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, xcap_access_type_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, xcap_access_type),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, connection_access) - QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, connection_access_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, connection_access),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, uri) - QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, uri_valid)),
  0x12,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, uri),
  QMI_WDS_XCAP_CONFIG_MAX_LENGTH_V01,
  QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, uri) - QMI_IDL_OFFSET8(wds_set_xcap_config_req_msg_v01, uri_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, name) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, name_valid)),
  0x13,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_xcap_config_req_msg_v01, name),
  QMI_WDS_XCAP_CONFIG_MAX_LENGTH_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, name) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, name_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, provider_id) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, provider_id_valid)),
  0x14,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_xcap_config_req_msg_v01, provider_id),
  QMI_WDS_XCAP_CONFIG_MAX_LENGTH_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, provider_id) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, provider_id_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, apn_name) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, apn_name_valid)),
  0x15,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_STRING,
  QMI_IDL_OFFSET16ARRAY(wds_set_xcap_config_req_msg_v01, apn_name),
  QMI_WDS_APN_NAME_MAX_V01,

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_name) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_name_valid)),
  0x16,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_xcap_config_req_msg_v01, auth_name),
  QMI_WDS_XCAP_CONFIG_MAX_LENGTH_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_name) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_name_len),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_password_valid)),
  0x17,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_xcap_config_req_msg_v01, auth_password),
  QMI_WDS_XCAP_CONFIG_MAX_LENGTH_V01,
  QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_password) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_password_len),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_type) - QMI_IDL_OFFSET16RELATIVE(wds_set_xcap_config_req_msg_v01, auth_type_valid)),
  0x18,
   QMI_IDL_FLAGS_OFFSET_IS_16 | QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET16ARRAY(wds_set_xcap_config_req_msg_v01, auth_type)
};

static const uint8_t wds_set_xcap_config_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_xcap_config_resp_msg_v01, response),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_set_xcap_config_result_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_xcap_config_result_ind_msg_v01, result),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_xcap_config_result_ind_msg_v01, transaction_id)
};

static const uint8_t wds_set_ladn_config_req_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_ladn_config_req_msg_v01, tx_id),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_ladn_config_req_msg_v01, plmn_id) - QMI_IDL_OFFSET8(wds_set_ladn_config_req_msg_v01, plmn_id_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_set_ladn_config_req_msg_v01, plmn_id),
  QMI_WDS_PLMN_ID_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_ladn_config_req_msg_v01, ladn_config) - QMI_IDL_OFFSET8(wds_set_ladn_config_req_msg_v01, ladn_config_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_ladn_config_req_msg_v01, ladn_config),
  QMI_WDS_CONFIG_LADN_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_set_ladn_config_req_msg_v01, ladn_config) - QMI_IDL_OFFSET8(wds_set_ladn_config_req_msg_v01, ladn_config_len),
  QMI_IDL_TYPE88(0, 107)
};

static const uint8_t wds_set_ladn_config_resp_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_ladn_config_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0)
};

static const uint8_t wds_ladn_config_result_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_ladn_config_result_ind_msg_v01, tx_id),

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_ladn_config_result_ind_msg_v01, result)
};

static const uint8_t wds_ladn_info_ind_msg_data_v01[] = {
  0x01,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_ladn_info_ind_msg_v01, plmn_id),
  QMI_WDS_PLMN_ID_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_ladn_info_ind_msg_v01, ladn_info) - QMI_IDL_OFFSET8(wds_ladn_info_ind_msg_v01, ladn_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_ladn_info_ind_msg_v01, ladn_info),
  QMI_WDS_LADN_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_ladn_info_ind_msg_v01, ladn_info) - QMI_IDL_OFFSET8(wds_ladn_info_ind_msg_v01, ladn_info_len),
  QMI_IDL_TYPE88(0, 0)
};

static const uint8_t wds_get_ladn_info_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ladn_info_req_msg_v01, plmn_id) - QMI_IDL_OFFSET8(wds_get_ladn_info_req_msg_v01, plmn_id_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_ladn_info_req_msg_v01, plmn_id),
  QMI_WDS_PLMN_ID_MAX_V01
};

static const uint8_t wds_get_ladn_info_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_ladn_info_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ladn_info_resp_msg_v01, plmn_id) - QMI_IDL_OFFSET8(wds_get_ladn_info_resp_msg_v01, plmn_id_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_get_ladn_info_resp_msg_v01, plmn_id),
  QMI_WDS_PLMN_ID_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_get_ladn_info_resp_msg_v01, ladn_info) - QMI_IDL_OFFSET8(wds_get_ladn_info_resp_msg_v01, ladn_info_valid)),
  0x11,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_get_ladn_info_resp_msg_v01, ladn_info),
  QMI_WDS_LADN_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_get_ladn_info_resp_msg_v01, ladn_info) - QMI_IDL_OFFSET8(wds_get_ladn_info_resp_msg_v01, ladn_info_len),
  QMI_IDL_TYPE88(0, 0)
};

static const uint8_t wds_set_capabilities_req_msg_data_v01[] = {
  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_capabilities_req_msg_v01, pdn_throttle_cap) - QMI_IDL_OFFSET8(wds_set_capabilities_req_msg_v01, pdn_throttle_cap_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_capabilities_req_msg_v01, pdn_throttle_cap),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_capabilities_req_msg_v01, roaming_info_cap) - QMI_IDL_OFFSET8(wds_set_capabilities_req_msg_v01, roaming_info_cap_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_capabilities_req_msg_v01, roaming_info_cap)
};

static const uint8_t wds_set_capabilities_resp_msg_data_v01[] = {
  0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_set_capabilities_resp_msg_v01, resp),
  QMI_IDL_TYPE88(1, 0),

  QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_capabilities_resp_msg_v01, pdn_throttle_cap) - QMI_IDL_OFFSET8(wds_set_capabilities_resp_msg_v01, pdn_throttle_cap_valid)),
  0x10,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_capabilities_resp_msg_v01, pdn_throttle_cap),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_set_capabilities_resp_msg_v01, roaming_info_cap) - QMI_IDL_OFFSET8(wds_set_capabilities_resp_msg_v01, roaming_info_cap_valid)),
  0x11,
   QMI_IDL_GENERIC_4_BYTE,
  QMI_IDL_OFFSET8(wds_set_capabilities_resp_msg_v01, roaming_info_cap)
};

static const uint8_t wds_pdn_throttle_info_v2_result_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_result_ind_msg_v01, tx_info),
  QMI_IDL_TYPE88(0, 20),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_result_ind_msg_v01, throttle_info) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_result_ind_msg_v01, throttle_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_result_ind_msg_v01, throttle_info),
  QMI_WDS_APNS_MAX_V01,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_result_ind_msg_v01, throttle_info) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_result_ind_msg_v01, throttle_info_len),
  QMI_IDL_TYPE88(0, 21)
};

static const uint8_t wds_pdn_throttle_info_v2_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_ind_msg_v01, tx_info),
  QMI_IDL_TYPE88(0, 20),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_ind_msg_v01, throttle_info) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_ind_msg_v01, throttle_info_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_ind_msg_v01, throttle_info),
  QMI_WDS_APNS_MAX_V01,
  QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_ind_msg_v01, throttle_info) - QMI_IDL_OFFSET8(wds_pdn_throttle_info_v2_ind_msg_v01, throttle_info_len),
  QMI_IDL_TYPE88(0, 21)
};

static const uint8_t wds_roaming_info_v2_result_ind_msg_data_v01[] = {
  0x01,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_roaming_info_v2_result_ind_msg_v01, tx_info),
  QMI_IDL_TYPE88(0, 20),

  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_roaming_info_v2_result_ind_msg_v01, roaming_apn_name_list) - QMI_IDL_OFFSET8(wds_roaming_info_v2_result_ind_msg_v01, roaming_apn_name_list_valid)),
  0x10,
  QMI_IDL_FLAGS_IS_ARRAY | QMI_IDL_FLAGS_IS_VARIABLE_LEN |  QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_roaming_info_v2_result_ind_msg_v01, roaming_apn_name_list),
  QMI_WDS_APN_NAME_LIST_MAX_V01,
  QMI_IDL_OFFSET8(wds_roaming_info_v2_result_ind_msg_v01, roaming_apn_name_list) - QMI_IDL_OFFSET8(wds_roaming_info_v2_result_ind_msg_v01, roaming_apn_name_list_len),
  QMI_IDL_TYPE88(0, 15)
};

static const uint8_t wds_rebind_default_flow_info_ind_data_v01[] = {
  QMI_IDL_TLV_FLAGS_LAST_TLV | QMI_IDL_TLV_FLAGS_OPTIONAL | (QMI_IDL_OFFSET8(wds_rebind_default_flow_info_ind_v01, bearer_id) - QMI_IDL_OFFSET8(wds_rebind_default_flow_info_ind_v01, bearer_id_valid)),
  0x10,
   QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_rebind_default_flow_info_ind_v01, bearer_id)
};

static const uint8_t wds_lte_attach_failure_info_ind_msg_data_v01[] = {
  0x01,
  QMI_IDL_FLAGS_IS_ARRAY |  QMI_IDL_GENERIC_1_BYTE,
  QMI_IDL_OFFSET8(wds_lte_attach_failure_info_ind_msg_v01, plmn_id),
  QMI_WDS_PLMN_ID_MAX_V01,

  QMI_IDL_TLV_FLAGS_LAST_TLV | 0x02,
   QMI_IDL_AGGREGATE,
  QMI_IDL_OFFSET8(wds_lte_attach_failure_info_ind_msg_v01, lte_attach_reject_reason),
  QMI_IDL_TYPE88(0, 108)
};

/* Type Table */
static const qmi_idl_type_table_entry  wds_type_table_v01[] = {
  {sizeof(wds_ladn_status_info_type_v01), wds_ladn_status_info_type_data_v01},
  {sizeof(wds_v2x_result_type_v01), wds_v2x_result_type_data_v01},
  {sizeof(wds_v2x_non_sps_info_type_v01), wds_v2x_non_sps_info_type_data_v01},
  {sizeof(wds_v2x_sps_flow_id_info_v01), wds_v2x_sps_flow_id_info_data_v01},
  {sizeof(wds_v2x_sps_flow_result_info_v01), wds_v2x_sps_flow_result_info_data_v01},
  {sizeof(wds_v2x_tx_pool_id_info_type_v01), wds_v2x_tx_pool_id_info_type_data_v01},
  {sizeof(wds_v2x_pppp_info_type_v01), wds_v2x_pppp_info_type_data_v01},
  {sizeof(wds_op_reserved_pco_info_ex_type_v01), wds_op_reserved_pco_info_ex_type_data_v01},
  {sizeof(wds_op_reserved_pco_list_info_type_v01), wds_op_reserved_pco_list_info_type_data_v01},
  {sizeof(wds_op_reserved_pco_list_type_v01), wds_op_reserved_pco_list_type_data_v01},
  {sizeof(wds_report_apn_op_reserved_pco_list_v01), wds_report_apn_op_reserved_pco_list_data_v01},
  {sizeof(wds_apn_msisdn_info_type_v01), wds_apn_msisdn_info_type_data_v01},
  {sizeof(wds_op_reserved_pco_info_type_v01), wds_op_reserved_pco_info_type_data_v01},
  {sizeof(wds_runtime_ipv6_addr_type_v01), wds_runtime_ipv6_addr_type_data_v01},
  {sizeof(wds_report_apn_msisdn_change_v01), wds_report_apn_msisdn_change_data_v01},
  {sizeof(wds_apn_name_list_type_v01), wds_apn_name_list_type_data_v01},
  {sizeof(wds_data_bearer_type_info_v01), wds_data_bearer_type_info_data_v01},
  {sizeof(wds_ran_asst_media_adapt_bit_rate_info_type_v01), wds_ran_asst_media_adapt_bit_rate_info_type_data_v01},
  {sizeof(wds_ran_asst_media_adapt_client_info_type_v01), wds_ran_asst_media_adapt_client_info_type_data_v01},
  {sizeof(wds_ran_asst_media_adapt_info_type_v01), wds_ran_asst_media_adapt_info_type_data_v01},
  {sizeof(qmi_wds_transaction_info_type_v01), qmi_wds_transaction_info_type_data_v01},
  {sizeof(wds_pdn_throttle_info_per_apn_type_v01), wds_pdn_throttle_info_per_apn_type_data_v01},
  {sizeof(wds_statistics_indicator_type_v01), wds_statistics_indicator_type_data_v01},
  {sizeof(wds_channel_rate_type_v01), wds_channel_rate_type_data_v01},
  {sizeof(wds_channel_rate_ex_type_v01), wds_channel_rate_ex_type_data_v01},
  {sizeof(wds_current_bearer_tech_type_v01), wds_current_bearer_tech_type_data_v01},
  {sizeof(wds_evdo_page_monitor_period_type_v01), wds_evdo_page_monitor_period_type_data_v01},
  {sizeof(wds_event_data_call_type_v01), wds_event_data_call_type_data_v01},
  {sizeof(wds_sys_network_info_type_v01), wds_sys_network_info_type_data_v01},
  {sizeof(wds_data_system_status_type_v01), wds_data_system_status_type_data_v01},
  {sizeof(wds_bearer_tech_info_type_v01), wds_bearer_tech_info_type_data_v01},
  {sizeof(wds_delay_dormancy_result_type_v01), wds_delay_dormancy_result_type_data_v01},
  {sizeof(wds_handoff_context_type_v01), wds_handoff_context_type_data_v01},
  {sizeof(wds_verbose_call_end_reason_type_v01), wds_verbose_call_end_reason_type_data_v01},
  {sizeof(wds_packet_service_status_type_v01), wds_packet_service_status_type_data_v01},
  {sizeof(wds_current_channel_rate_type_v01), wds_current_channel_rate_type_data_v01},
  {sizeof(wds_current_channel_rate_ex_type_v01), wds_current_channel_rate_ex_type_data_v01},
  {sizeof(wds_umts_qos_type_v01), wds_umts_qos_type_data_v01},
  {sizeof(wds_umts_qos_with_sig_ind_type_v01), wds_umts_qos_with_sig_ind_type_data_v01},
  {sizeof(wds_gprs_qos_type_v01), wds_gprs_qos_type_data_v01},
  {sizeof(wds_tft_id_param_type_v01), wds_tft_id_param_type_data_v01},
  {sizeof(wds_3gpp_lte_qos_params_v01), wds_3gpp_lte_qos_params_data_v01},
  {sizeof(wds_mnc_pcs_digit_include_status_type_v01), wds_mnc_pcs_digit_include_status_type_data_v01},
  {sizeof(wds_common_linger_param_type_v01), wds_common_linger_param_type_data_v01},
  {sizeof(wds_eap_auth_param_type_v01), wds_eap_auth_param_type_data_v01},
  {sizeof(wds_profile_identifier_type_v01), wds_profile_identifier_type_data_v01},
  {sizeof(wds_profile_info_type_v01), wds_profile_info_type_data_v01},
  {sizeof(wds_runtime_profile_identifier_type_v01), wds_runtime_profile_identifier_type_data_v01},
  {sizeof(wds_pcscf_ipv4_addr_type_v01), wds_pcscf_ipv4_addr_type_data_v01},
  {sizeof(wds_pcscf_ipv4_addr_list_type_v01), wds_pcscf_ipv4_addr_list_type_data_v01},
  {sizeof(wds_fqdn_type_v01), wds_fqdn_type_data_v01},
  {sizeof(wds_fqdn_list_type_v01), wds_fqdn_list_type_data_v01},
  {sizeof(wds_domain_name_type_v01), wds_domain_name_type_data_v01},
  {sizeof(wds_domain_name_list_type_v01), wds_domain_name_list_type_data_v01},
  {sizeof(wds_pcscf_ipv6_addr_type_v01), wds_pcscf_ipv6_addr_type_data_v01},
  {sizeof(wds_pcscf_ipv6_addr_list_type_v01), wds_pcscf_ipv6_addr_list_type_data_v01},
  {sizeof(wds_dun_stats_indicator_type_v01), wds_dun_stats_indicator_type_data_v01},
  {sizeof(wds_dun_connection_status_type_v01), wds_dun_connection_status_type_data_v01},
  {sizeof(wds_mip_profile_identifier_type_v01), wds_mip_profile_identifier_type_data_v01},
  {sizeof(wds_call_record_type_v01), wds_call_record_type_data_v01},
  {sizeof(wds_full_call_record_type_v01), wds_full_call_record_type_data_v01},
  {sizeof(wds_full_call_history_type_v01), wds_full_call_history_type_data_v01},
  {sizeof(wds_id_only_call_record_type_v01), wds_id_only_call_record_type_data_v01},
  {sizeof(wds_id_only_call_history_type_v01), wds_id_only_call_history_type_data_v01},
  {sizeof(wds_profile_id_family_type_v01), wds_profile_id_family_type_data_v01},
  {sizeof(wds_profile_identifier_with_family_type_v01), wds_profile_identifier_with_family_type_data_v01},
  {sizeof(wds_profile_param_type_v01), wds_profile_param_type_data_v01},
  {sizeof(wds_tunnel_params_type_v01), wds_tunnel_params_type_data_v01},
  {sizeof(wds_predormancy_cdma_settings_type_v01), wds_predormancy_cdma_settings_type_data_v01},
  {sizeof(wds_call_throttle_info_type_v01), wds_call_throttle_info_type_data_v01},
  {sizeof(wds_embms_tmgi_type_v01), wds_embms_tmgi_type_data_v01},
  {sizeof(wds_embms_earfcn_type_v01), wds_embms_earfcn_type_data_v01},
  {sizeof(wds_embms_tmgi_list_struct_type_v01), wds_embms_tmgi_list_struct_type_data_v01},
  {sizeof(wds_get_data_call_type_v01), wds_get_data_call_type_data_v01},
  {sizeof(wds_pdn_throttle_info_type_v01), wds_pdn_throttle_info_type_data_v01},
  {sizeof(wds_pdn_throttle_info_ext_type_v01), wds_pdn_throttle_info_ext_type_data_v01},
  {sizeof(wds_pdn_throttle_info_addn_params_v01), wds_pdn_throttle_info_addn_params_data_v01},
  {sizeof(wds_reqd_net_policy_info_v01), wds_reqd_net_policy_info_data_v01},
  {sizeof(wds_tcp_udp_port_range_v01), wds_tcp_udp_port_range_data_v01},
  {sizeof(wds_ip_addr_type_v01), wds_ip_addr_type_data_v01},
  {sizeof(wds_cfg_attr_ipv4_subnet_type_v01), wds_cfg_attr_ipv4_subnet_type_data_v01},
  {sizeof(wds_cfg_attr_ipv6_type_v01), wds_cfg_attr_ipv6_type_data_v01},
  {sizeof(wds_traffic_selector_type_v01), wds_traffic_selector_type_data_v01},
  {sizeof(wds_handoff_event_info_type_v01), wds_handoff_event_info_type_data_v01},
  {sizeof(wds_handoff_failure_reason_type_v01), wds_handoff_failure_reason_type_data_v01},
  {sizeof(wds_embms_sai_list_per_freq_type_v01), wds_embms_sai_list_per_freq_type_data_v01},
  {sizeof(wds_embms_sai_list_per_freq_ex_type_v01), wds_embms_sai_list_per_freq_ex_type_data_v01},
  {sizeof(wds_outage_type_v01), wds_outage_type_data_v01},
  {sizeof(wds_rf_conditions_type_v01), wds_rf_conditions_type_data_v01},
  {sizeof(wds_dos_ack_info_type_v01), wds_dos_ack_info_type_data_v01},
  {sizeof(wds_get_runtime_settings_error_v01), wds_get_runtime_settings_error_data_v01},
  {sizeof(wds_session_timer_1x_v01), wds_session_timer_1x_data_v01},
  {sizeof(wds_set_runtime_settings_error_v01), wds_set_runtime_settings_error_data_v01},
  {sizeof(wds_bearer_rlp_mac_id_throughput_info_type_v01), wds_bearer_rlp_mac_id_throughput_info_type_data_v01},
  {sizeof(wds_throughput_info_type_v01), wds_throughput_info_type_data_v01},
  {sizeof(wds_profile_event_register_type_v01), wds_profile_event_register_type_data_v01},
  {sizeof(wds_profile_changed_ind_type_v01), wds_profile_changed_ind_type_data_v01},
  {sizeof(wds_apn_param_apn_string_type_v01), wds_apn_param_apn_string_type_data_v01},
  {sizeof(wds_profile_identifier_ex_type_v01), wds_profile_identifier_ex_type_data_v01},
  {sizeof(wds_v2x_non_sps_flow_info_type_v01), wds_v2x_non_sps_flow_info_type_data_v01},
  {sizeof(wds_v2x_service_sub_info_type_v01), wds_v2x_service_sub_info_type_data_v01},
  {sizeof(wds_profile_lite_info_type_v01), wds_profile_lite_info_type_data_v01},
  {sizeof(wds_v2x_config_file_seg_info_type_v01), wds_v2x_config_file_seg_info_type_data_v01},
  {sizeof(wds_v2x_sps_scheduling_info_type_v01), wds_v2x_sps_scheduling_info_type_data_v01},
  {sizeof(wds_v2x_trusted_ue_info_type_v01), wds_v2x_trusted_ue_info_type_data_v01},
  {sizeof(wds_v2x_trusted_ue_info_ex_type_v01), wds_v2x_trusted_ue_info_ex_type_data_v01},
  {sizeof(qmi_wds_xcap_transaction_info_type_v01), qmi_wds_xcap_transaction_info_type_data_v01},
  {sizeof(wds_ladn_config_type_v01), wds_ladn_config_type_data_v01},
  {sizeof(wds_reject_reason_type_v01), wds_reject_reason_type_data_v01}
};

/* Message Table */
static const qmi_idl_message_table_entry wds_message_table_v01[] = {
  {sizeof(wds_reset_req_msg_v01), 0},
  {sizeof(wds_reset_resp_msg_v01), wds_reset_resp_msg_data_v01},
  {sizeof(wds_set_event_report_req_msg_v01), wds_set_event_report_req_msg_data_v01},
  {sizeof(wds_set_event_report_resp_msg_v01), wds_set_event_report_resp_msg_data_v01},
  {sizeof(wds_event_report_ind_msg_v01), wds_event_report_ind_msg_data_v01},
  {sizeof(wds_abort_req_msg_v01), wds_abort_req_msg_data_v01},
  {sizeof(wds_abort_resp_msg_v01), wds_abort_resp_msg_data_v01},
  {sizeof(wds_indication_register_req_msg_v01), wds_indication_register_req_msg_data_v01},
  {sizeof(wds_indication_register_resp_msg_v01), wds_indication_register_resp_msg_data_v01},
  {sizeof(wds_start_network_interface_req_msg_v01), wds_start_network_interface_req_msg_data_v01},
  {sizeof(wds_start_network_interface_resp_msg_v01), wds_start_network_interface_resp_msg_data_v01},
  {sizeof(wds_stop_network_interface_req_msg_v01), wds_stop_network_interface_req_msg_data_v01},
  {sizeof(wds_stop_network_interface_resp_msg_v01), wds_stop_network_interface_resp_msg_data_v01},
  {sizeof(wds_get_pkt_srvc_status_req_msg_v01), wds_get_pkt_srvc_status_req_msg_data_v01},
  {sizeof(wds_get_pkt_srvc_status_resp_msg_v01), wds_get_pkt_srvc_status_resp_msg_data_v01},
  {sizeof(wds_pkt_srvc_status_ind_msg_v01), wds_pkt_srvc_status_ind_msg_data_v01},
  {sizeof(wds_get_current_channel_rate_req_msg_v01), 0},
  {sizeof(wds_get_current_channel_rate_resp_msg_v01), wds_get_current_channel_rate_resp_msg_data_v01},
  {sizeof(wds_get_pkt_statistics_req_msg_v01), wds_get_pkt_statistics_req_msg_data_v01},
  {sizeof(wds_get_pkt_statistics_resp_msg_v01), wds_get_pkt_statistics_resp_msg_data_v01},
  {sizeof(wds_go_dormant_req_msg_v01), wds_go_dormant_req_msg_data_v01},
  {sizeof(wds_go_dormant_resp_msg_v01), wds_go_dormant_resp_msg_data_v01},
  {sizeof(wds_go_active_req_msg_v01), 0},
  {sizeof(wds_go_active_resp_msg_v01), wds_go_active_resp_msg_data_v01},
  {sizeof(wds_create_profile_req_msg_v01), wds_create_profile_req_msg_data_v01},
  {sizeof(wds_create_profile_resp_msg_v01), wds_create_profile_resp_msg_data_v01},
  {sizeof(wds_modify_profile_settings_req_msg_v01), wds_modify_profile_settings_req_msg_data_v01},
  {sizeof(wds_modify_profile_settings_resp_msg_v01), wds_modify_profile_settings_resp_msg_data_v01},
  {sizeof(wds_delete_profile_req_msg_v01), wds_delete_profile_req_msg_data_v01},
  {sizeof(wds_delete_profile_resp_msg_v01), wds_delete_profile_resp_msg_data_v01},
  {sizeof(wds_get_profile_list_req_msg_v01), wds_get_profile_list_req_msg_data_v01},
  {sizeof(wds_get_profile_list_resp_msg_v01), wds_get_profile_list_resp_msg_data_v01},
  {sizeof(wds_get_profile_settings_req_msg_v01), wds_get_profile_settings_req_msg_data_v01},
  {sizeof(wds_get_profile_settings_resp_msg_v01), wds_get_profile_settings_resp_msg_data_v01},
  {sizeof(wds_get_default_settings_req_msg_v01), wds_get_default_settings_req_msg_data_v01},
  {sizeof(wds_get_default_settings_resp_msg_v01), wds_get_default_settings_resp_msg_data_v01},
  {sizeof(wds_get_runtime_settings_req_msg_v01), wds_get_runtime_settings_req_msg_data_v01},
  {sizeof(wds_get_runtime_settings_resp_msg_v01), wds_get_runtime_settings_resp_msg_data_v01},
  {sizeof(wds_set_mip_mode_req_msg_v01), wds_set_mip_mode_req_msg_data_v01},
  {sizeof(wds_set_mip_mode_resp_msg_v01), wds_set_mip_mode_resp_msg_data_v01},
  {sizeof(wds_get_mip_mode_req_msg_v01), 0},
  {sizeof(wds_get_mip_mode_resp_msg_v01), wds_get_mip_mode_resp_msg_data_v01},
  {sizeof(wds_get_dormancy_status_req_msg_v01), 0},
  {sizeof(wds_get_dormancy_status_resp_msg_v01), wds_get_dormancy_status_resp_msg_data_v01},
  {sizeof(wds_get_autoconnect_setting_req_msg_v01), 0},
  {sizeof(wds_get_autoconnect_setting_resp_msg_v01), wds_get_autoconnect_setting_resp_msg_data_v01},
  {sizeof(wds_get_call_duration_req_msg_v01), 0},
  {sizeof(wds_get_call_duration_resp_msg_v01), wds_get_call_duration_resp_msg_data_v01},
  {sizeof(wds_get_data_bearer_technology_req_msg_v01), 0},
  {sizeof(wds_get_data_bearer_technology_resp_msg_v01), wds_get_data_bearer_technology_resp_msg_data_v01},
  {sizeof(wds_get_dun_call_info_req_msg_v01), wds_get_dun_call_info_req_msg_data_v01},
  {sizeof(wds_get_dun_call_info_resp_msg_v01), wds_get_dun_call_info_resp_msg_data_v01},
  {sizeof(wds_dun_call_info_ind_msg_v01), wds_dun_call_info_ind_msg_data_v01},
  {sizeof(wds_get_active_mip_profile_req_msg_v01), 0},
  {sizeof(wds_get_active_mip_profile_resp_msg_v01), wds_get_active_mip_profile_resp_msg_data_v01},
  {sizeof(wds_set_active_mip_profile_req_msg_v01), wds_set_active_mip_profile_req_msg_data_v01},
  {sizeof(wds_set_active_mip_profile_resp_msg_v01), wds_set_active_mip_profile_resp_msg_data_v01},
  {sizeof(wds_read_mip_profile_req_msg_v01), wds_read_mip_profile_req_msg_data_v01},
  {sizeof(wds_read_mip_profile_resp_msg_v01), wds_read_mip_profile_resp_msg_data_v01},
  {sizeof(wds_modify_mip_profile_req_msg_v01), wds_modify_mip_profile_req_msg_data_v01},
  {sizeof(wds_modify_mip_profile_resp_msg_v01), wds_modify_mip_profile_resp_msg_data_v01},
  {sizeof(wds_get_mip_settings_req_msg_v01), 0},
  {sizeof(wds_get_mip_settings_resp_msg_v01), wds_get_mip_settings_resp_msg_data_v01},
  {sizeof(wds_set_mip_settings_req_msg_v01), wds_set_mip_settings_req_msg_data_v01},
  {sizeof(wds_set_mip_settings_resp_msg_v01), wds_set_mip_settings_resp_msg_data_v01},
  {sizeof(wds_get_last_mip_status_req_msg_v01), 0},
  {sizeof(wds_get_last_mip_status_resp_msg_v01), wds_get_last_mip_status_resp_msg_data_v01},
  {sizeof(wds_get_current_data_bearer_technology_req_msg_v01), 0},
  {sizeof(wds_get_current_data_bearer_technology_resp_msg_v01), wds_get_current_data_bearer_technology_resp_msg_data_v01},
  {sizeof(wds_call_history_list_req_msg_v01), 0},
  {sizeof(wds_call_history_list_resp_msg_v01), wds_call_history_list_resp_msg_data_v01},
  {sizeof(wds_call_history_read_req_msg_v01), wds_call_history_read_req_msg_data_v01},
  {sizeof(wds_call_history_read_resp_msg_v01), wds_call_history_read_resp_msg_data_v01},
  {sizeof(wds_call_history_delete_req_msg_v01), 0},
  {sizeof(wds_call_history_delete_resp_msg_v01), wds_call_history_delete_resp_msg_data_v01},
  {sizeof(wds_call_history_max_size_req_msg_v01), 0},
  {sizeof(wds_call_history_max_size_resp_msg_v01), wds_call_history_max_size_resp_msg_data_v01},
  {sizeof(wds_get_default_profile_num_req_msg_v01), wds_get_default_profile_num_req_msg_data_v01},
  {sizeof(wds_get_default_profile_num_resp_msg_v01), wds_get_default_profile_num_resp_msg_data_v01},
  {sizeof(wds_set_default_profile_num_req_msg_v01), wds_set_default_profile_num_req_msg_data_v01},
  {sizeof(wds_set_default_profile_num_resp_msg_v01), wds_set_default_profile_num_resp_msg_data_v01},
  {sizeof(wds_reset_profile_to_default_req_msg_v01), wds_reset_profile_to_default_req_msg_data_v01},
  {sizeof(wds_reset_profile_to_default_resp_msg_v01), wds_reset_profile_to_default_resp_msg_data_v01},
  {sizeof(wds_reset_profile_param_to_invalid_req_msg_v01), wds_reset_profile_param_to_invalid_req_msg_data_v01},
  {sizeof(wds_reset_profile_param_to_invalid_resp_msg_v01), wds_reset_profile_param_to_invalid_resp_msg_data_v01},
  {sizeof(wds_set_client_ip_family_pref_req_msg_v01), wds_set_client_ip_family_pref_req_msg_data_v01},
  {sizeof(wds_set_client_ip_family_pref_resp_msg_v01), wds_set_client_ip_family_pref_resp_msg_data_v01},
  {sizeof(wds_fmc_set_tunnel_params_req_msg_v01), wds_fmc_set_tunnel_params_req_msg_data_v01},
  {sizeof(wds_fmc_set_tunnel_params_resp_msg_v01), wds_fmc_set_tunnel_params_resp_msg_data_v01},
  {sizeof(wds_fmc_clear_tunnel_params_req_msg_v01), 0},
  {sizeof(wds_fmc_clear_tunnel_params_resp_msg_v01), wds_fmc_clear_tunnel_params_resp_msg_data_v01},
  {sizeof(wds_fmc_get_tunnel_params_req_msg_v01), 0},
  {sizeof(wds_fmc_get_tunnel_params_resp_msg_v01), wds_fmc_get_tunnel_params_resp_msg_data_v01},
  {sizeof(wds_set_autoconnect_settings_req_msg_v01), wds_set_autoconnect_settings_req_msg_data_v01},
  {sizeof(wds_set_autoconnect_settings_resp_msg_v01), wds_set_autoconnect_settings_resp_msg_data_v01},
  {sizeof(wds_get_dns_settings_req_msg_v01), 0},
  {sizeof(wds_get_dns_settings_resp_msg_v01), wds_get_dns_settings_resp_msg_data_v01},
  {sizeof(wds_set_dns_settings_req_msg_v01), wds_set_dns_settings_req_msg_data_v01},
  {sizeof(wds_set_dns_settings_resp_msg_v01), wds_set_dns_settings_resp_msg_data_v01},
  {sizeof(wds_get_pre_dormancy_cdma_settings_req_msg_v01), 0},
  {sizeof(wds_get_pre_dormancy_cdma_settings_resp_msg_v01), wds_get_pre_dormancy_cdma_settings_resp_msg_data_v01},
  {sizeof(wds_set_cam_timer_req_msg_v01), wds_set_cam_timer_req_msg_data_v01},
  {sizeof(wds_set_cam_timer_resp_msg_v01), wds_set_cam_timer_resp_msg_data_v01},
  {sizeof(wds_get_cam_timer_req_msg_v01), 0},
  {sizeof(wds_get_cam_timer_resp_msg_v01), wds_get_cam_timer_resp_msg_data_v01},
  {sizeof(wds_set_scrm_req_msg_v01), wds_set_scrm_req_msg_data_v01},
  {sizeof(wds_set_scrm_resp_msg_v01), wds_set_scrm_resp_msg_data_v01},
  {sizeof(wds_get_scrm_req_msg_v01), 0},
  {sizeof(wds_get_scrm_resp_msg_v01), wds_get_scrm_resp_msg_data_v01},
  {sizeof(wds_set_rdud_req_msg_v01), wds_set_rdud_req_msg_data_v01},
  {sizeof(wds_set_rdud_resp_msg_v01), wds_set_rdud_resp_msg_data_v01},
  {sizeof(wds_get_rdud_req_msg_v01), 0},
  {sizeof(wds_get_rdud_resp_msg_v01), wds_get_rdud_resp_msg_data_v01},
  {sizeof(wds_get_sip_mip_call_type_req_msg_v01), 0},
  {sizeof(wds_get_sip_mip_call_type_resp_msg_v01), wds_get_sip_mip_call_type_resp_msg_data_v01},
  {sizeof(wds_set_evdo_page_monitor_period_req_msg_v01), wds_set_evdo_page_monitor_period_req_msg_data_v01},
  {sizeof(wds_set_evdo_page_monitor_period_resp_msg_v01), wds_set_evdo_page_monitor_period_resp_msg_data_v01},
  {sizeof(wds_evdo_page_monitor_period_result_ind_msg_v01), wds_evdo_page_monitor_period_result_ind_msg_data_v01},
  {sizeof(wds_set_evdo_force_long_sleep_req_msg_v01), wds_set_evdo_force_long_sleep_req_msg_data_v01},
  {sizeof(wds_set_evdo_force_long_sleep_resp_msg_v01), wds_set_evdo_force_long_sleep_resp_msg_data_v01},
  {sizeof(wds_get_evdo_page_monitor_period_req_msg_v01), 0},
  {sizeof(wds_get_evdo_page_monitor_period_resp_msg_v01), wds_get_evdo_page_monitor_period_resp_msg_data_v01},
  {sizeof(wds_get_call_throttle_info_req_msg_v01), 0},
  {sizeof(wds_get_call_throttle_info_resp_msg_v01), wds_get_call_throttle_info_resp_msg_data_v01},
  {sizeof(wds_get_nsapi_req_msg_v01), wds_get_nsapi_req_msg_data_v01},
  {sizeof(wds_get_nsapi_resp_msg_v01), wds_get_nsapi_resp_msg_data_v01},
  {sizeof(wds_set_dun_ctrl_pref_req_msg_v01), wds_set_dun_ctrl_pref_req_msg_data_v01},
  {sizeof(wds_set_dun_ctrl_pref_resp_msg_v01), wds_set_dun_ctrl_pref_resp_msg_data_v01},
  {sizeof(wds_get_dun_ctrl_info_req_msg_v01), 0},
  {sizeof(wds_get_dun_ctrl_info_resp_msg_v01), wds_get_dun_ctrl_info_resp_msg_data_v01},
  {sizeof(wds_set_dun_ctrl_event_report_req_msg_v01), wds_set_dun_ctrl_event_report_req_msg_data_v01},
  {sizeof(wds_set_dun_ctrl_event_report_resp_msg_v01), wds_set_dun_ctrl_event_report_resp_msg_data_v01},
  {sizeof(wds_dun_ctrl_event_report_ind_msg_v01), wds_dun_ctrl_event_report_ind_msg_data_v01},
  {sizeof(wds_control_pending_dun_call_req_msg_v01), wds_control_pending_dun_call_req_msg_data_v01},
  {sizeof(wds_control_pending_dun_call_resp_msg_v01), wds_control_pending_dun_call_resp_msg_data_v01},
  {sizeof(wds_embms_tmgi_activate_req_msg_v01), wds_embms_tmgi_activate_req_msg_data_v01},
  {sizeof(wds_embms_tmgi_activate_resp_msg_v01), wds_embms_tmgi_activate_resp_msg_data_v01},
  {sizeof(wds_embms_tmgi_activate_ind_msg_v01), wds_embms_tmgi_activate_ind_msg_data_v01},
  {sizeof(wds_embms_tmgi_deactivate_req_msg_v01), wds_embms_tmgi_deactivate_req_msg_data_v01},
  {sizeof(wds_embms_tmgi_deactivate_resp_msg_v01), wds_embms_tmgi_deactivate_resp_msg_data_v01},
  {sizeof(wds_embms_tmgi_deactivate_ind_msg_v01), wds_embms_tmgi_deactivate_ind_msg_data_v01},
  {sizeof(wds_embms_tmgi_list_query_req_msg_v01), wds_embms_tmgi_list_query_req_msg_data_v01},
  {sizeof(wds_embms_tmgi_list_query_resp_msg_v01), wds_embms_tmgi_list_query_resp_msg_data_v01},
  {sizeof(wds_embms_tmgi_list_ind_msg_v01), wds_embms_tmgi_list_ind_msg_data_v01},
  {sizeof(wds_get_preferred_data_system_req_msg_v01), 0},
  {sizeof(wds_get_preferred_data_system_resp_msg_v01), wds_get_preferred_data_system_resp_msg_data_v01},
  {sizeof(wds_get_last_data_call_status_req_msg_v01), 0},
  {sizeof(wds_get_last_data_call_status_resp_msg_v01), wds_get_last_data_call_status_resp_msg_data_v01},
  {sizeof(wds_get_current_data_system_status_req_msg_v01), 0},
  {sizeof(wds_get_current_data_system_status_resp_msg_v01), wds_get_current_data_system_status_resp_msg_data_v01},
  {sizeof(wds_get_pdn_throttle_info_req_msg_v01), wds_get_pdn_throttle_info_req_msg_data_v01},
  {sizeof(wds_get_pdn_throttle_info_resp_msg_v01), wds_get_pdn_throttle_info_resp_msg_data_v01},
  {sizeof(wds_pdn_throttle_info_ind_msg_v01), wds_pdn_throttle_info_ind_msg_data_v01},
  {sizeof(wds_get_lte_max_attach_pdn_num_req_msg_v01), 0},
  {sizeof(wds_get_lte_max_attach_pdn_num_resp_msg_v01), wds_get_lte_max_attach_pdn_num_resp_msg_data_v01},
  {sizeof(wds_set_lte_attach_pdn_list_req_msg_v01), wds_set_lte_attach_pdn_list_req_msg_data_v01},
  {sizeof(wds_set_lte_attach_pdn_list_resp_msg_v01), wds_set_lte_attach_pdn_list_resp_msg_data_v01},
  {sizeof(wds_set_lte_attach_pdn_list_action_result_ind_msg_v01), wds_set_lte_attach_pdn_list_action_result_ind_msg_data_v01},
  {sizeof(wds_get_lte_attach_pdn_list_req_msg_v01), 0},
  {sizeof(wds_get_lte_attach_pdn_list_resp_msg_v01), wds_get_lte_attach_pdn_list_resp_msg_data_v01},
  {sizeof(wds_lte_attach_pdn_list_ind_msg_v01), wds_lte_attach_pdn_list_ind_msg_data_v01},
  {sizeof(wds_get_lte_attach_params_req_msg_v01), 0},
  {sizeof(wds_get_lte_attach_params_resp_msg_v01), wds_get_lte_attach_params_resp_msg_data_v01},
  {sizeof(wds_reset_pkt_statistics_req_msg_v01), 0},
  {sizeof(wds_reset_pkt_statistics_resp_msg_v01), wds_reset_pkt_statistics_resp_msg_data_v01},
  {sizeof(wds_get_flow_control_status_req_msg_v01), 0},
  {sizeof(wds_get_flow_control_status_resp_msg_v01), wds_get_flow_control_status_resp_msg_data_v01},
  {sizeof(wds_embms_tmgi_act_deact_req_msg_v01), wds_embms_tmgi_act_deact_req_msg_data_v01},
  {sizeof(wds_embms_tmgi_act_deact_resp_msg_v01), wds_embms_tmgi_act_deact_resp_msg_data_v01},
  {sizeof(wds_embms_tmgi_act_deact_ind_msg_v01), wds_embms_tmgi_act_deact_ind_msg_data_v01},
  {sizeof(wds_bind_data_port_req_msg_v01), wds_bind_data_port_req_msg_data_v01},
  {sizeof(wds_bind_data_port_resp_msg_v01), wds_bind_data_port_resp_msg_data_v01},
  {sizeof(wds_set_additional_pdn_filter_req_msg_v01), wds_set_additional_pdn_filter_req_msg_data_v01},
  {sizeof(wds_set_additional_pdn_filter_resp_msg_v01), wds_set_additional_pdn_filter_resp_msg_data_v01},
  {sizeof(wds_remove_additional_pdn_filter_req_msg_v01), wds_remove_additional_pdn_filter_req_msg_data_v01},
  {sizeof(wds_remove_additional_pdn_filter_resp_msg_v01), wds_remove_additional_pdn_filter_resp_msg_data_v01},
  {sizeof(wds_extended_ip_config_ind_msg_v01), wds_extended_ip_config_ind_msg_data_v01},
  {sizeof(wds_reverse_ip_transport_connection_ind_registration_req_msg_v01), wds_reverse_ip_transport_connection_ind_registration_req_msg_data_v01},
  {sizeof(wds_reverse_ip_transport_connection_ind_registration_resp_msg_v01), wds_reverse_ip_transport_connection_ind_registration_resp_msg_data_v01},
  {sizeof(wds_reverse_ip_transport_connection_ind_msg_v01), wds_reverse_ip_transport_connection_ind_msg_data_v01},
  {sizeof(wds_get_ipsec_static_sa_config_req_msg_v01), 0},
  {sizeof(wds_get_ipsec_static_sa_config_resp_msg_v01), wds_get_ipsec_static_sa_config_resp_msg_data_v01},
  {sizeof(wds_reverse_ip_transport_config_complete_req_msg_v01), wds_reverse_ip_transport_config_complete_req_msg_data_v01},
  {sizeof(wds_reverse_ip_transport_config_complete_resp_msg_v01), wds_reverse_ip_transport_config_complete_resp_msg_data_v01},
  {sizeof(wds_get_data_bearer_technology_ex_req_msg_v01), 0},
  {sizeof(wds_get_data_bearer_technology_ex_resp_msg_v01), wds_get_data_bearer_technology_ex_resp_msg_data_v01},
  {sizeof(wds_set_lte_data_retry_req_msg_v01), wds_set_lte_data_retry_req_msg_data_v01},
  {sizeof(wds_set_lte_data_retry_resp_msg_v01), wds_set_lte_data_retry_resp_msg_data_v01},
  {sizeof(wds_get_lte_data_retry_req_msg_v01), 0},
  {sizeof(wds_get_lte_data_retry_resp_msg_v01), wds_get_lte_data_retry_resp_msg_data_v01},
  {sizeof(wds_set_lte_attach_type_req_msg_v01), wds_set_lte_attach_type_req_msg_data_v01},
  {sizeof(wds_set_lte_attach_type_resp_msg_v01), wds_set_lte_attach_type_resp_msg_data_v01},
  {sizeof(wds_get_lte_attach_type_req_msg_v01), 0},
  {sizeof(wds_get_lte_attach_type_resp_msg_v01), wds_get_lte_attach_type_resp_msg_data_v01},
  {sizeof(wds_reverse_ip_transport_filter_setup_ind_msg_v01), wds_reverse_ip_transport_filter_setup_ind_msg_data_v01},
  {sizeof(wds_handoff_information_ind_msg_v01), wds_handoff_information_ind_msg_data_v01},
  {sizeof(wds_set_data_path_req_msg_v01), wds_set_data_path_req_msg_data_v01},
  {sizeof(wds_set_data_path_resp_msg_v01), wds_set_data_path_resp_msg_data_v01},
  {sizeof(wds_get_data_path_req_msg_v01), 0},
  {sizeof(wds_get_data_path_resp_msg_v01), wds_get_data_path_resp_msg_data_v01},
  {sizeof(wds_update_lte_attach_pdn_list_profiles_req_msg_v01), 0},
  {sizeof(wds_update_lte_attach_pdn_list_profiles_resp_msg_v01), wds_update_lte_attach_pdn_list_profiles_resp_msg_data_v01},
  {sizeof(wds_embms_sai_list_query_req_msg_v01), 0},
  {sizeof(wds_embms_sai_list_query_resp_msg_v01), wds_embms_sai_list_query_resp_msg_data_v01},
  {sizeof(wds_embms_sai_list_ind_msg_v01), wds_embms_sai_list_ind_msg_data_v01},
  {sizeof(wds_bind_mux_data_port_req_msg_v01), wds_bind_mux_data_port_req_msg_data_v01},
  {sizeof(wds_bind_mux_data_port_resp_msg_v01), wds_bind_mux_data_port_resp_msg_data_v01},
  {sizeof(wds_initiate_esp_rekey_req_msg_v01), 0},
  {sizeof(wds_initiate_esp_rekey_resp_msg_v01), wds_initiate_esp_rekey_resp_msg_data_v01},
  {sizeof(wds_internal_iface_ev_register_req_msg_v01), wds_internal_iface_ev_register_req_msg_data_v01},
  {sizeof(wds_internal_iface_ev_register_resp_msg_v01), wds_internal_iface_ev_register_resp_msg_data_v01},
  {sizeof(wds_internal_iface_ev_ind_msg_v01), wds_internal_iface_ev_ind_msg_data_v01},
  {sizeof(wds_get_internal_runtime_settings_req_msg_v01), wds_get_internal_runtime_settings_req_msg_data_v01},
  {sizeof(wds_get_internal_runtime_settings_resp_msg_v01), wds_get_internal_runtime_settings_resp_msg_data_v01},
  {sizeof(wds_set_internal_runtime_settings_req_msg_v01), wds_set_internal_runtime_settings_req_msg_data_v01},
  {sizeof(wds_set_internal_runtime_settings_resp_msg_v01), wds_set_internal_runtime_settings_resp_msg_data_v01},
  {sizeof(wds_refresh_dhcp_config_info_req_msg_v01), 0},
  {sizeof(wds_refresh_dhcp_config_info_resp_msg_v01), wds_refresh_dhcp_config_info_resp_msg_data_v01},
  {sizeof(wds_set_throughput_info_ind_freq_req_msg_v01), wds_set_throughput_info_ind_freq_req_msg_data_v01},
  {sizeof(wds_set_throughput_info_ind_freq_resp_msg_v01), wds_set_throughput_info_ind_freq_resp_msg_data_v01},
  {sizeof(wds_get_last_throughput_info_req_msg_v01), 0},
  {sizeof(wds_get_last_throughput_info_resp_msg_v01), wds_get_last_throughput_info_resp_msg_data_v01},
  {sizeof(wds_throughput_info_ind_msg_v01), wds_throughput_info_ind_msg_data_v01},
  {sizeof(wds_config_profile_list_req_msg_v01), wds_config_profile_list_req_msg_data_v01},
  {sizeof(wds_config_profile_list_resp_msg_v01), wds_config_profile_list_resp_msg_data_v01},
  {sizeof(wds_profile_changed_ind_msg_v01), wds_profile_changed_ind_msg_data_v01},
  {sizeof(wds_get_capabilities_req_msg_v01), wds_get_capabilities_req_msg_data_v01},
  {sizeof(wds_get_capabilities_resp_msg_v01), wds_get_capabilities_resp_msg_data_v01},
  {sizeof(wds_get_roaming_info_req_msg_v01), 0},
  {sizeof(wds_get_roaming_info_resp_msg_v01), wds_get_roaming_info_resp_msg_data_v01},
  {sizeof(wds_roaming_info_ind_msg_v01), wds_roaming_info_ind_msg_data_v01},
  {sizeof(wds_get_delegated_ipv6_prefix_req_msg_v01), wds_get_delegated_ipv6_prefix_req_msg_data_v01},
  {sizeof(wds_get_delegated_ipv6_prefix_resp_msg_v01), wds_get_delegated_ipv6_prefix_resp_msg_data_v01},
  {sizeof(wds_remove_delegated_ipv6_prefix_req_msg_v01), wds_remove_delegated_ipv6_prefix_req_msg_data_v01},
  {sizeof(wds_remove_delegated_ipv6_prefix_resp_msg_v01), wds_remove_delegated_ipv6_prefix_resp_msg_data_v01},
  {sizeof(wds_abort_go_dormant_req_msg_v01), 0},
  {sizeof(wds_abort_go_dormant_resp_msg_v01), wds_abort_go_dormant_resp_msg_data_v01},
  {sizeof(wds_bind_subscription_req_msg_v01), wds_bind_subscription_req_msg_data_v01},
  {sizeof(wds_bind_subscription_resp_msg_v01), wds_bind_subscription_resp_msg_data_v01},
  {sizeof(wds_get_bind_subscription_req_msg_v01), 0},
  {sizeof(wds_get_bind_subscription_resp_msg_v01), wds_get_bind_subscription_resp_msg_data_v01},
  {sizeof(wds_set_lte_data_call_type_req_msg_v01), wds_set_lte_data_call_type_req_msg_data_v01},
  {sizeof(wds_set_lte_data_call_type_resp_msg_v01), wds_set_lte_data_call_type_resp_msg_data_v01},
  {sizeof(wds_set_downlink_throughput_info_ind_freq_req_msg_v01), wds_set_downlink_throughput_info_ind_freq_req_msg_data_v01},
  {sizeof(wds_set_downlink_throughput_info_ind_freq_resp_msg_v01), wds_set_downlink_throughput_info_ind_freq_resp_msg_data_v01},
  {sizeof(wds_downlink_throughput_info_ind_msg_v01), wds_downlink_throughput_info_ind_msg_data_v01},
  {sizeof(wds_get_downlink_throughput_info_params_req_msg_v01), 0},
  {sizeof(wds_get_downlink_throughput_info_params_resp_msg_v01), wds_get_downlink_throughput_info_params_resp_msg_data_v01},
  {sizeof(wds_embms_content_desc_update_req_msg_v01), wds_embms_content_desc_update_req_msg_data_v01},
  {sizeof(wds_embms_content_desc_update_resp_msg_v01), wds_embms_content_desc_update_resp_msg_data_v01},
  {sizeof(wds_embms_content_desc_control_ind_msg_v01), wds_embms_content_desc_control_ind_msg_data_v01},
  {sizeof(wds_policy_refresh_req_msg_v01), wds_policy_refresh_req_msg_data_v01},
  {sizeof(wds_policy_refresh_resp_msg_v01), wds_policy_refresh_resp_msg_data_v01},
  {sizeof(wds_policy_refresh_result_ind_msg_v01), wds_policy_refresh_result_ind_msg_data_v01},
  {sizeof(wds_policy_ready_ind_msg_v01), wds_policy_ready_ind_msg_data_v01},
  {sizeof(wds_apn_param_info_change_ind_msg_v01), wds_apn_param_info_change_ind_msg_data_v01},
  {sizeof(wds_set_silent_redial_req_msg_v01), wds_set_silent_redial_req_msg_data_v01},
  {sizeof(wds_set_silent_redial_resp_msg_v01), wds_set_silent_redial_resp_msg_data_v01},
  {sizeof(wds_configured_throughput_info_ind_msg_v01), wds_configured_throughput_info_ind_msg_data_v01},
  {sizeof(wds_get_configured_throughput_info_req_msg_v01), 0},
  {sizeof(wds_get_configured_throughput_info_resp_msg_v01), wds_get_configured_throughput_info_resp_msg_data_v01},
  {sizeof(wds_get_downlink_throughput_info_req_msg_v01), 0},
  {sizeof(wds_get_downlink_throughput_info_resp_msg_v01), wds_get_downlink_throughput_info_resp_msg_data_v01},
  {sizeof(wds_embms_svc_interest_ind_msg_v01), wds_embms_svc_interest_ind_msg_data_v01},
  {sizeof(wds_embms_svc_interest_info_req_msg_v01), wds_embms_svc_interest_info_req_msg_data_v01},
  {sizeof(wds_embms_svc_interest_info_resp_msg_v01), wds_embms_svc_interest_info_resp_msg_data_v01},
  {sizeof(wds_set_downlink_throughput_report_period_req_msg_v01), wds_set_downlink_throughput_report_period_req_msg_data_v01},
  {sizeof(wds_set_downlink_throughput_report_period_resp_msg_v01), wds_set_downlink_throughput_report_period_resp_msg_data_v01},
  {sizeof(wds_downlink_throughput_reporting_status_ind_msg_v01), wds_downlink_throughput_reporting_status_ind_msg_data_v01},
  {sizeof(wds_query_downlink_throughput_reporting_status_req_msg_v01), 0},
  {sizeof(wds_query_downlink_throughput_reporting_status_resp_msg_v01), wds_query_downlink_throughput_reporting_status_resp_msg_data_v01},
  {sizeof(wds_keep_alive_data_session_req_msg_v01), wds_keep_alive_data_session_req_msg_data_v01},
  {sizeof(wds_keep_alive_data_session_resp_msg_v01), wds_keep_alive_data_session_resp_msg_data_v01},
  {sizeof(wds_set_always_on_pdn_req_msg_v01), wds_set_always_on_pdn_req_msg_data_v01},
  {sizeof(wds_set_always_on_pdn_resp_msg_v01), wds_set_always_on_pdn_resp_msg_data_v01},
  {sizeof(wds_apn_op_reserved_pco_list_change_ind_msg_v01), wds_apn_op_reserved_pco_list_change_ind_msg_data_v01},
  {sizeof(wds_get_apn_op_reserved_pco_list_req_msg_v01), wds_get_apn_op_reserved_pco_list_req_msg_data_v01},
  {sizeof(wds_get_apn_op_reserved_pco_list_resp_msg_v01), wds_get_apn_op_reserved_pco_list_resp_msg_data_v01},
  {sizeof(wds_apn_msisdn_change_ind_msg_v01), wds_apn_msisdn_change_ind_msg_data_v01},
  {sizeof(wds_get_apn_msisdn_info_req_msg_v01), wds_get_apn_msisdn_info_req_msg_data_v01},
  {sizeof(wds_get_apn_msisdn_info_resp_msg_v01), wds_get_apn_msisdn_info_resp_msg_data_v01},
  {sizeof(wds_tear_down_always_on_pdn_req_msg_v01), 0},
  {sizeof(wds_tear_down_always_on_pdn_resp_msg_v01), wds_tear_down_always_on_pdn_resp_msg_data_v01},
  {sizeof(wds_lte_attach_params_ind_msg_v01), wds_lte_attach_params_ind_msg_data_v01},
  {sizeof(wds_reset_and_modify_profile_settings_req_msg_v01), wds_reset_and_modify_profile_settings_req_msg_data_v01},
  {sizeof(wds_reset_and_modify_profile_settings_resp_msg_v01), wds_reset_and_modify_profile_settings_resp_msg_data_v01},
  {sizeof(wds_set_attach_profile_info_req_msg_v01), wds_set_attach_profile_info_req_msg_data_v01},
  {sizeof(wds_set_attach_profile_info_resp_msg_v01), wds_set_attach_profile_info_resp_msg_data_v01},
  {sizeof(wds_delete_all_profiles_req_msg_v01), wds_delete_all_profiles_req_msg_data_v01},
  {sizeof(wds_delete_all_profiles_resp_msg_v01), wds_delete_all_profiles_resp_msg_data_v01},
  {sizeof(wds_delete_all_profiles_result_ind_msg_v01), wds_delete_all_profiles_result_ind_msg_data_v01},
  {sizeof(wds_3gpp_rab_reject_ind_msg_v01), wds_3gpp_rab_reject_ind_msg_data_v01},
  {sizeof(wds_get_last_3gpp_rab_reject_info_req_msg_v01), 0},
  {sizeof(wds_get_last_3gpp_rab_reject_info_resp_msg_v01), wds_get_last_3gpp_rab_reject_info_resp_msg_data_v01},
  {sizeof(wds_get_throttled_pdn_reject_timer_req_msg_v01), 0},
  {sizeof(wds_get_throttled_pdn_reject_timer_resp_msg_v01), wds_get_throttled_pdn_reject_timer_resp_msg_data_v01},
  {sizeof(wds_set_throttled_pdn_reject_timer_req_msg_v01), wds_set_throttled_pdn_reject_timer_req_msg_data_v01},
  {sizeof(wds_set_throttled_pdn_reject_timer_resp_msg_v01), wds_set_throttled_pdn_reject_timer_resp_msg_data_v01},
  {sizeof(wds_set_ehrpd_fallback_apn_list_req_msg_v01), wds_set_ehrpd_fallback_apn_list_req_msg_data_v01},
  {sizeof(wds_set_ehrpd_fallback_apn_list_resp_msg_v01), wds_set_ehrpd_fallback_apn_list_resp_msg_data_v01},
  {sizeof(wds_get_ehrpd_fallback_apn_list_req_msg_v01), 0},
  {sizeof(wds_get_ehrpd_fallback_apn_list_resp_msg_v01), wds_get_ehrpd_fallback_apn_list_resp_msg_data_v01},
  {sizeof(wds_subsequent_data_transfer_status_req_msg_v01), wds_subsequent_data_transfer_status_req_msg_data_v01},
  {sizeof(wds_subsequent_data_transfer_status_resp_msg_v01), wds_subsequent_data_transfer_status_resp_msg_data_v01},
  {sizeof(wds_modem_assisted_ka_start_req_msg_v01), wds_modem_assisted_ka_start_req_msg_data_v01},
  {sizeof(wds_modem_assisted_ka_start_resp_msg_v01), wds_modem_assisted_ka_start_resp_msg_data_v01},
  {sizeof(wds_modem_assisted_ka_status_ind_msg_v01), wds_modem_assisted_ka_status_ind_msg_data_v01},
  {sizeof(wds_modem_assisted_ka_stop_req_msg_v01), wds_modem_assisted_ka_stop_req_msg_data_v01},
  {sizeof(wds_modem_assisted_ka_stop_resp_msg_v01), wds_modem_assisted_ka_stop_resp_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_reg_req_msg_v01), wds_v2x_sps_flow_reg_req_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_reg_resp_msg_v01), wds_v2x_sps_flow_reg_resp_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_reg_result_ind_msg_v01), wds_v2x_sps_flow_reg_result_ind_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_dereg_req_msg_v01), wds_v2x_sps_flow_dereg_req_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_dereg_resp_msg_v01), wds_v2x_sps_flow_dereg_resp_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_dereg_result_ind_msg_v01), wds_v2x_sps_flow_dereg_result_ind_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_update_req_msg_v01), wds_v2x_sps_flow_update_req_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_update_resp_msg_v01), wds_v2x_sps_flow_update_resp_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_update_result_ind_msg_v01), wds_v2x_sps_flow_update_result_ind_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_get_info_req_msg_v01), wds_v2x_sps_flow_get_info_req_msg_data_v01},
  {sizeof(wds_v2x_sps_flow_get_info_resp_msg_v01), wds_v2x_sps_flow_get_info_resp_msg_data_v01},
  {sizeof(wds_v2x_non_sps_flow_reg_req_msg_v01), wds_v2x_non_sps_flow_reg_req_msg_data_v01},
  {sizeof(wds_v2x_non_sps_flow_reg_resp_msg_v01), wds_v2x_non_sps_flow_reg_resp_msg_data_v01},
  {sizeof(wds_v2x_non_sps_flow_dereg_req_msg_v01), wds_v2x_non_sps_flow_dereg_req_msg_data_v01},
  {sizeof(wds_v2x_non_sps_flow_dereg_resp_msg_v01), wds_v2x_non_sps_flow_dereg_resp_msg_data_v01},
  {sizeof(wds_v2x_service_subscribe_req_msg_v01), wds_v2x_service_subscribe_req_msg_data_v01},
  {sizeof(wds_v2x_service_subscribe_resp_msg_v01), wds_v2x_service_subscribe_resp_msg_data_v01},
  {sizeof(wds_v2x_service_subscribe_result_ind_msg_v01), wds_v2x_service_subscribe_result_ind_msg_data_v01},
  {sizeof(wds_v2x_service_get_subscribe_list_req_msg_v01), 0},
  {sizeof(wds_v2x_service_get_subscribe_list_resp_msg_v01), wds_v2x_service_get_subscribe_list_resp_msg_data_v01},
  {sizeof(wds_set_data_low_latency_mode_req_msg_v01), wds_set_data_low_latency_mode_req_msg_data_v01},
  {sizeof(wds_set_data_low_latency_mode_resp_msg_v01), wds_set_data_low_latency_mode_resp_msg_data_v01},
  {sizeof(wds_get_data_low_latency_mode_req_msg_v01), 0},
  {sizeof(wds_get_data_low_latency_mode_resp_msg_v01), wds_get_data_low_latency_mode_resp_msg_data_v01},
  {sizeof(wds_get_avail_ext_ipv6_addr_req_msg_v01), 0},
  {sizeof(wds_get_avail_ext_ipv6_addr_resp_msg_v01), wds_get_avail_ext_ipv6_addr_resp_msg_data_v01},
  {sizeof(wds_create_profile_lite_req_msg_v01), wds_create_profile_lite_req_msg_data_v01},
  {sizeof(wds_create_profile_lite_resp_msg_v01), wds_create_profile_lite_resp_msg_data_v01},
  {sizeof(wds_modify_profile_settings_lite_req_msg_v01), wds_modify_profile_settings_lite_req_msg_data_v01},
  {sizeof(wds_modify_profile_settings_lite_resp_msg_v01), wds_modify_profile_settings_lite_resp_msg_data_v01},
  {sizeof(wds_delete_profile_lite_req_msg_v01), wds_delete_profile_lite_req_msg_data_v01},
  {sizeof(wds_delete_profile_lite_resp_msg_v01), wds_delete_profile_lite_resp_msg_data_v01},
  {sizeof(wds_get_profile_settings_lite_req_msg_v01), wds_get_profile_settings_lite_req_msg_data_v01},
  {sizeof(wds_get_profile_settings_lite_resp_msg_v01), wds_get_profile_settings_lite_resp_msg_data_v01},
  {sizeof(wds_get_profile_list_lite_req_msg_v01), 0},
  {sizeof(wds_get_profile_list_lite_resp_msg_v01), wds_get_profile_list_lite_resp_msg_data_v01},
  {sizeof(wds_get_lte_emergency_attach_params_req_msg_v01), 0},
  {sizeof(wds_get_lte_emergency_attach_params_resp_msg_v01), wds_get_lte_emergency_attach_params_resp_msg_data_v01},
  {sizeof(wds_ran_asst_media_adaptation_reg_req_msg_v01), wds_ran_asst_media_adaptation_reg_req_msg_data_v01},
  {sizeof(wds_ran_asst_media_adaptation_reg_resp_msg_v01), wds_ran_asst_media_adaptation_reg_resp_msg_data_v01},
  {sizeof(wds_ran_asst_media_adaptation_dereg_req_msg_v01), wds_ran_asst_media_adaptation_dereg_req_msg_data_v01},
  {sizeof(wds_ran_asst_media_adaptation_dereg_resp_msg_v01), wds_ran_asst_media_adaptation_dereg_resp_msg_data_v01},
  {sizeof(wds_update_ran_asst_media_adapt_rate_req_msg_v01), wds_update_ran_asst_media_adapt_rate_req_msg_data_v01},
  {sizeof(wds_update_ran_asst_media_adapt_rate_resp_msg_v01), wds_update_ran_asst_media_adapt_rate_resp_msg_data_v01},
  {sizeof(wds_ran_asst_media_adapt_info_ind_msg_v01), wds_ran_asst_media_adapt_info_ind_msg_data_v01},
  {sizeof(wds_v2x_send_config_file_req_msg_v01), wds_v2x_send_config_file_req_msg_data_v01},
  {sizeof(wds_v2x_send_config_file_resp_msg_v01), wds_v2x_send_config_file_resp_msg_data_v01},
  {sizeof(wds_v2x_send_config_file_result_ind_msg_v01), wds_v2x_send_config_file_result_ind_msg_data_v01},
  {sizeof(wds_v2x_sps_scheduling_info_ind_msg_v01), wds_v2x_sps_scheduling_info_ind_msg_data_v01},
  {sizeof(wds_v2x_update_src_l2_info_req_msg_v01), 0},
  {sizeof(wds_v2x_update_src_l2_info_resp_msg_v01), wds_v2x_update_src_l2_info_resp_msg_data_v01},
  {sizeof(wds_v2x_src_l2_info_ind_msg_v01), wds_v2x_src_l2_info_ind_msg_data_v01},
  {sizeof(wds_v2x_tunnel_mode_info_req_msg_v01), wds_v2x_tunnel_mode_info_req_msg_data_v01},
  {sizeof(wds_v2x_tunnel_mode_info_resp_msg_v01), wds_v2x_tunnel_mode_info_resp_msg_data_v01},
  {sizeof(wds_get_data_bearer_type_req_msg_v01), wds_get_data_bearer_type_req_msg_data_v01},
  {sizeof(wds_get_data_bearer_type_resp_msg_v01), wds_get_data_bearer_type_resp_msg_data_v01},
  {sizeof(wds_data_bearer_type_ind_msg_v01), wds_data_bearer_type_ind_msg_data_v01},
  {sizeof(wds_v2x_get_capability_info_req_msg_v01), 0},
  {sizeof(wds_v2x_get_capability_info_resp_msg_v01), wds_v2x_get_capability_info_resp_msg_data_v01},
  {sizeof(wds_v2x_capability_info_ind_msg_v01), wds_v2x_capability_info_ind_msg_data_v01},
  {sizeof(wds_set_data_coalescing_req_msg_v01), wds_set_data_coalescing_req_msg_data_v01},
  {sizeof(wds_set_data_coalescing_resp_msg_v01), wds_set_data_coalescing_resp_msg_data_v01},
  {sizeof(wds_get_data_coalescing_req_msg_v01), 0},
  {sizeof(wds_get_data_coalescing_resp_msg_v01), wds_get_data_coalescing_resp_msg_data_v01},
  {sizeof(wds_get_splmn_rate_control_info_req_msg_v01), 0},
  {sizeof(wds_get_splmn_rate_control_info_resp_msg_v01), wds_get_splmn_rate_control_info_resp_msg_data_v01},
  {sizeof(wds_get_apn_rate_control_info_req_msg_v01), 0},
  {sizeof(wds_get_apn_rate_control_info_resp_msg_v01), wds_get_apn_rate_control_info_resp_msg_data_v01},
  {sizeof(wds_set_xcap_config_req_msg_v01), wds_set_xcap_config_req_msg_data_v01},
  {sizeof(wds_set_xcap_config_resp_msg_v01), wds_set_xcap_config_resp_msg_data_v01},
  {sizeof(wds_set_xcap_config_result_ind_msg_v01), wds_set_xcap_config_result_ind_msg_data_v01},
  {sizeof(wds_set_ladn_config_req_msg_v01), wds_set_ladn_config_req_msg_data_v01},
  {sizeof(wds_set_ladn_config_resp_msg_v01), wds_set_ladn_config_resp_msg_data_v01},
  {sizeof(wds_ladn_config_result_ind_msg_v01), wds_ladn_config_result_ind_msg_data_v01},
  {sizeof(wds_ladn_info_ind_msg_v01), wds_ladn_info_ind_msg_data_v01},
  {sizeof(wds_get_ladn_info_req_msg_v01), wds_get_ladn_info_req_msg_data_v01},
  {sizeof(wds_get_ladn_info_resp_msg_v01), wds_get_ladn_info_resp_msg_data_v01},
  {sizeof(wds_set_capabilities_req_msg_v01), wds_set_capabilities_req_msg_data_v01},
  {sizeof(wds_set_capabilities_resp_msg_v01), wds_set_capabilities_resp_msg_data_v01},
  {sizeof(wds_pdn_throttle_info_v2_result_ind_msg_v01), wds_pdn_throttle_info_v2_result_ind_msg_data_v01},
  {sizeof(wds_pdn_throttle_info_v2_ind_msg_v01), wds_pdn_throttle_info_v2_ind_msg_data_v01},
  {sizeof(wds_roaming_info_v2_result_ind_msg_v01), wds_roaming_info_v2_result_ind_msg_data_v01},
  {sizeof(wds_rebind_default_flow_info_ind_v01), wds_rebind_default_flow_info_ind_data_v01},
  {sizeof(wds_lte_attach_failure_info_ind_msg_v01), wds_lte_attach_failure_info_ind_msg_data_v01}
};

/* Range Table */
/* No Ranges Defined in IDL */

/* Predefine the Type Table Object */
static const qmi_idl_type_table_object wds_qmi_idl_type_table_object_v01;

/*Referenced Tables Array*/
static const qmi_idl_type_table_object *wds_qmi_idl_type_table_object_referenced_tables_v01[] =
{&wds_qmi_idl_type_table_object_v01, &common_qmi_idl_type_table_object_v01, &data_common_qmi_idl_type_table_object_v01, &wireless_data_service_common_qmi_idl_type_table_object_v01};

/*Type Table Object*/
static const qmi_idl_type_table_object wds_qmi_idl_type_table_object_v01 = {
  sizeof(wds_type_table_v01)/sizeof(qmi_idl_type_table_entry ),
  sizeof(wds_message_table_v01)/sizeof(qmi_idl_message_table_entry),
  1,
  wds_type_table_v01,
  wds_message_table_v01,
  wds_qmi_idl_type_table_object_referenced_tables_v01,
  NULL
};

/*Arrays of service_message_table_entries for commands, responses and indications*/
static const qmi_idl_service_message_table_entry wds_service_command_messages_v01[] = {
  {QMI_WDS_RESET_REQ_V01, QMI_IDL_TYPE16(0, 0), 0},
  {QMI_WDS_SET_EVENT_REPORT_REQ_V01, QMI_IDL_TYPE16(0, 2), 64},
  {QMI_WDS_ABORT_REQ_V01, QMI_IDL_TYPE16(0, 5), 5},
  {QMI_WDS_INDICATION_REGISTER_REQ_V01, QMI_IDL_TYPE16(0, 7), 442},
  {QMI_WDS_GET_SUPPORTED_MSGS_REQ_V01, QMI_IDL_TYPE16(1, 0), 0},
  {QMI_WDS_GET_SUPPORTED_FIELDS_REQ_V01, QMI_IDL_TYPE16(1, 2), 5},
  {QMI_WDS_START_NETWORK_INTERFACE_REQ_V01, QMI_IDL_TYPE16(0, 9), 554},
  {QMI_WDS_STOP_NETWORK_INTERFACE_REQ_V01, QMI_IDL_TYPE16(0, 11), 15},
  {QMI_WDS_GET_PKT_SRVC_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 13), 7},
  {QMI_WDS_GET_CURRENT_CHANNEL_RATE_REQ_V01, QMI_IDL_TYPE16(0, 16), 0},
  {QMI_WDS_GET_PKT_STATISTICS_REQ_V01, QMI_IDL_TYPE16(0, 18), 7},
  {QMI_WDS_GO_DORMANT_REQ_V01, QMI_IDL_TYPE16(0, 20), 11},
  {QMI_WDS_GO_ACTIVE_REQ_V01, QMI_IDL_TYPE16(0, 22), 0},
  {QMI_WDS_CREATE_PROFILE_REQ_V01, QMI_IDL_TYPE16(0, 24), 3092},
  {QMI_WDS_MODIFY_PROFILE_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 26), 3089},
  {QMI_WDS_DELETE_PROFILE_REQ_V01, QMI_IDL_TYPE16(0, 28), 5},
  {QMI_WDS_GET_PROFILE_LIST_REQ_V01, QMI_IDL_TYPE16(0, 30), 175},
  {QMI_WDS_GET_PROFILE_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 32), 5},
  {QMI_WDS_GET_DEFAULT_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 34), 4},
  {QMI_WDS_GET_RUNTIME_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 36), 7},
  {QMI_WDS_SET_MIP_MODE_REQ_V01, QMI_IDL_TYPE16(0, 38), 4},
  {QMI_WDS_GET_MIP_MODE_REQ_V01, QMI_IDL_TYPE16(0, 40), 0},
  {QMI_WDS_GET_DORMANCY_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 42), 0},
  {QMI_WDS_GET_AUTOCONNECT_SETTING_REQ_V01, QMI_IDL_TYPE16(0, 44), 0},
  {QMI_WDS_GET_CALL_DURATION_REQ_V01, QMI_IDL_TYPE16(0, 46), 0},
  {QMI_WDS_GET_DATA_BEARER_TECHNOLOGY_REQ_V01, QMI_IDL_TYPE16(0, 48), 0},
  {QMI_WDS_GET_DUN_CALL_INFO_REQ_V01, QMI_IDL_TYPE16(0, 50), 31},
  {QMI_WDS_GET_ACTIVE_MIP_PROFILE_REQ_V01, QMI_IDL_TYPE16(0, 53), 0},
  {QMI_WDS_SET_ACTIVE_MIP_PROFILE_REQ_V01, QMI_IDL_TYPE16(0, 55), 10},
  {QMI_WDS_READ_MIP_PROFILE_REQ_V01, QMI_IDL_TYPE16(0, 57), 4},
  {QMI_WDS_MODIFY_MIP_PROFILE_REQ_V01, QMI_IDL_TYPE16(0, 59), 166},
  {QMI_WDS_GET_MIP_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 61), 0},
  {QMI_WDS_SET_MIP_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 63), 37},
  {QMI_WDS_GET_LAST_MIP_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 65), 0},
  {QMI_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_REQ_V01, QMI_IDL_TYPE16(0, 67), 0},
  {QMI_WDS_CALL_HISTORY_LIST_REQ_V01, QMI_IDL_TYPE16(0, 69), 0},
  {QMI_WDS_CALL_HISTORY_READ_REQ_V01, QMI_IDL_TYPE16(0, 71), 5},
  {QMI_WDS_CALL_HISTORY_DELETE_REQ_V01, QMI_IDL_TYPE16(0, 73), 0},
  {QMI_WDS_CALL_HISTORY_MAX_SIZE_REQ_V01, QMI_IDL_TYPE16(0, 75), 0},
  {QMI_WDS_GET_DEFAULT_PROFILE_NUM_REQ_V01, QMI_IDL_TYPE16(0, 77), 5},
  {QMI_WDS_SET_DEFAULT_PROFILE_NUM_REQ_V01, QMI_IDL_TYPE16(0, 79), 6},
  {QMI_WDS_RESET_PROFILE_TO_DEFAULT_REQ_V01, QMI_IDL_TYPE16(0, 81), 5},
  {QMI_WDS_RESET_PROFILE_PARAM_TO_INVALID_REQ_V01, QMI_IDL_TYPE16(0, 83), 9},
  {QMI_WDS_SET_CLIENT_IP_FAMILY_PREF_REQ_V01, QMI_IDL_TYPE16(0, 85), 4},
  {QMI_WDS_FMC_SET_TUNNEL_PARAMS_REQ_V01, QMI_IDL_TYPE16(0, 87), 36},
  {QMI_WDS_FMC_CLEAR_TUNNEL_PARAMS_REQ_V01, QMI_IDL_TYPE16(0, 89), 0},
  {QMI_WDS_FMC_GET_TUNNEL_PARAMS_REQ_V01, QMI_IDL_TYPE16(0, 91), 0},
  {QMI_WDS_SET_AUTOCONNECT_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 93), 8},
  {QMI_WDS_GET_DNS_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 95), 0},
  {QMI_WDS_SET_DNS_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 97), 52},
  {QMI_WDS_GET_PRE_DORMANCY_CDMA_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 99), 0},
  {QMI_WDS_SET_CAM_TIMER_REQ_V01, QMI_IDL_TYPE16(0, 101), 7},
  {QMI_WDS_GET_CAM_TIMER_REQ_V01, QMI_IDL_TYPE16(0, 103), 0},
  {QMI_WDS_SET_SCRM_REQ_V01, QMI_IDL_TYPE16(0, 105), 4},
  {QMI_WDS_GET_SCRM_REQ_V01, QMI_IDL_TYPE16(0, 107), 0},
  {QMI_WDS_SET_RDUD_REQ_V01, QMI_IDL_TYPE16(0, 109), 4},
  {QMI_WDS_GET_RDUD_REQ_V01, QMI_IDL_TYPE16(0, 111), 0},
  {QMI_WDS_GET_SIP_MIP_CALL_TYPE_REQ_V01, QMI_IDL_TYPE16(0, 113), 0},
  {QMI_WDS_SET_EVDO_PAGE_MONITOR_PERIOD_REQ_V01, QMI_IDL_TYPE16(0, 115), 4},
  {QMI_WDS_SET_EVDO_FORCE_LONG_SLEEP_REQ_V01, QMI_IDL_TYPE16(0, 118), 4},
  {QMI_WDS_GET_EVDO_PAGE_MONITOR_PERIOD_REQ_V01, QMI_IDL_TYPE16(0, 120), 0},
  {QMI_WDS_GET_CALL_THROTTLE_INFO_REQ_V01, QMI_IDL_TYPE16(0, 122), 0},
  {QMI_WDS_GET_NSAPI_REQ_V01, QMI_IDL_TYPE16(0, 124), 153},
  {QMI_WDS_SET_DUN_CTRL_PREF_REQ_V01, QMI_IDL_TYPE16(0, 126), 8},
  {QMI_WDS_GET_DUN_CTRL_INFO_REQ_V01, QMI_IDL_TYPE16(0, 128), 0},
  {QMI_WDS_SET_DUN_CTRL_EVENT_REPORT_REQ_V01, QMI_IDL_TYPE16(0, 130), 12},
  {QMI_WDS_CONTROL_PENDING_DUN_CALL_REQ_V01, QMI_IDL_TYPE16(0, 133), 8},
  {QMI_WDS_EMBMS_TMGI_ACTIVATE_REQ_V01, QMI_IDL_TYPE16(0, 135), 710},
  {QMI_WDS_EMBMS_TMGI_DEACTIVATE_REQ_V01, QMI_IDL_TYPE16(0, 138), 16},
  {QMI_WDS_EMBMS_TMGI_LIST_QUERY_REQ_V01, QMI_IDL_TYPE16(0, 141), 9},
  {QMI_WDS_GET_PREFERRED_DATA_SYSTEM_REQ_V01, QMI_IDL_TYPE16(0, 144), 0},
  {QMI_WDS_GET_LAST_DATA_CALL_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 146), 0},
  {QMI_WDS_GET_CURRENT_SYSTEM_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 148), 0},
  {QMI_WDS_GET_PDN_THROTTLE_INFO_REQ_V01, QMI_IDL_TYPE16(0, 150), 4},
  {QMI_WDS_GET_LTE_ATTACH_PARAMS_REQ_V01, QMI_IDL_TYPE16(0, 161), 0},
  {QMI_WDS_RESET_PKT_STATISTICS_REQ_V01, QMI_IDL_TYPE16(0, 163), 0},
  {QMI_WDS_GET_FLOW_CONTROL_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 165), 0},
  {QMI_WDS_EMBMS_TMGI_ACT_DEACT_REQ_V01, QMI_IDL_TYPE16(0, 167), 721},
  {QMI_WDS_BIND_DATA_PORT_REQ_V01, QMI_IDL_TYPE16(0, 170), 5},
  {QMI_WDS_SET_ADDITIONAL_PDN_FILTER_REQ_V01, QMI_IDL_TYPE16(0, 172), 24},
  {QMI_WDS_REMOVE_ADDITIONAL_PDN_FILTER_REQ_V01, QMI_IDL_TYPE16(0, 174), 7},
  {QMI_WDS_REVERSE_IP_TRANSPORT_CONNECTION_IND_REGISTRATION_REQ_V01, QMI_IDL_TYPE16(0, 177), 4},
  {QMI_WDS_GET_IPSEC_STATIC_SA_CONFIG_REQ_V01, QMI_IDL_TYPE16(0, 180), 0},
  {QMI_WDS_REVERSE_IP_TRANSPORT_CONFIG_COMPLETE_REQ_V01, QMI_IDL_TYPE16(0, 182), 11},
  {QMI_WDS_GET_DATA_BEARER_TECHNOLOGY_EX_REQ_V01, QMI_IDL_TYPE16(0, 184), 0},
  {QMI_WDS_GET_LTE_MAX_ATTACH_PDN_NUM_REQ_V01, QMI_IDL_TYPE16(0, 153), 0},
  {QMI_WDS_SET_LTE_ATTACH_PDN_LIST_REQ_V01, QMI_IDL_TYPE16(0, 155), 123},
  {QMI_WDS_GET_LTE_ATTACH_PDN_LIST_REQ_V01, QMI_IDL_TYPE16(0, 158), 0},
  {QMI_WDS_SET_LTE_DATA_RETRY_REQ_V01, QMI_IDL_TYPE16(0, 186), 4},
  {QMI_WDS_GET_LTE_DATA_RETRY_REQ_V01, QMI_IDL_TYPE16(0, 188), 0},
  {QMI_WDS_SET_LTE_ATTACH_TYPE_REQ_V01, QMI_IDL_TYPE16(0, 190), 7},
  {QMI_WDS_GET_LTE_ATTACH_TYPE_REQ_V01, QMI_IDL_TYPE16(0, 192), 0},
  {QMI_WDS_SET_DATA_PATH_REQ_V01, QMI_IDL_TYPE16(0, 196), 7},
  {QMI_WDS_GET_DATA_PATH_REQ_V01, QMI_IDL_TYPE16(0, 198), 0},
  {QMI_WDS_UPDATE_LTE_ATTACH_PDN_LIST_PROFILES_REQ_V01, QMI_IDL_TYPE16(0, 200), 0},
  {QMI_WDS_EMBMS_SAI_LIST_QUERY_REQ_V01, QMI_IDL_TYPE16(0, 202), 0},
  {QMI_WDS_BIND_MUX_DATA_PORT_REQ_V01, QMI_IDL_TYPE16(0, 205), 26},
  {QMI_WDS_SET_THROUGHPUT_INFO_IND_FREQ_REQ_V01, QMI_IDL_TYPE16(0, 218), 7},
  {QMI_WDS_GET_LAST_THROUGHPUT_INFO_REQ_V01, QMI_IDL_TYPE16(0, 220), 0},
  {QMI_WDS_INITIATE_ESP_REKEY_REQ_V01, QMI_IDL_TYPE16(0, 207), 0},
  {QMI_WDS_CONFIGURE_PROFILE_EVENT_LIST_REQ_V01, QMI_IDL_TYPE16(0, 223), 514},
  {QMI_WDS_GET_CAPABILITIES_REQ_V01, QMI_IDL_TYPE16(0, 226), 32},
  {QMI_WDS_GET_ROAMING_INFO_REQ_V01, QMI_IDL_TYPE16(0, 228), 0},
  {QMI_WDS_GET_DELEGATED_IPV6_PREFIX_REQ_V01, QMI_IDL_TYPE16(0, 231), 19},
  {QMI_WDS_REMOVE_DELEGATED_IPV6_PREFIX_REQ_V01, QMI_IDL_TYPE16(0, 233), 39},
  {QMI_WDS_ABORT_GO_DORMANT_REQ_V01, QMI_IDL_TYPE16(0, 235), 0},
  {QMI_WDS_BIND_SUBSCRIPTION_REQ_V01, QMI_IDL_TYPE16(0, 237), 7},
  {QMI_WDS_GET_BIND_SUBSCRIPTION_REQ_V01, QMI_IDL_TYPE16(0, 239), 0},
  {QMI_WDS_SET_LTE_DATA_CALL_TYPE_REQ_V01, QMI_IDL_TYPE16(0, 241), 7},
  {QMI_WDS_SET_DOWNLINK_THROUGHPUT_INFO_IND_FREQ_REQ_V01, QMI_IDL_TYPE16(0, 243), 7},
  {QMI_WDS_GET_DOWNLINK_THROUGHPUT_INFO_PARAMS_REQ_V01, QMI_IDL_TYPE16(0, 246), 0},
  {QMI_WDS_EMBMS_CONTENT_DESC_UPDATE_REQ_V01, QMI_IDL_TYPE16(0, 248), 135},
  {QMI_WDS_POLICY_REFRESH_REQ_V01, QMI_IDL_TYPE16(0, 251), 7},
  {QMI_WDS_SET_SILENT_REDIAL_REQ_V01, QMI_IDL_TYPE16(0, 256), 4},
  {QMI_WDS_GET_CONFIGURED_THROUGHPUT_INFO_REQ_V01, QMI_IDL_TYPE16(0, 259), 0},
  {QMI_WDS_GET_DOWNLINK_THROUGHPUT_INFO_REQ_V01, QMI_IDL_TYPE16(0, 261), 0},
  {QMI_WDS_EMBMS_SVC_INTEREST_INFO_REQ_V01, QMI_IDL_TYPE16(0, 264), 1033},
  {QMI_WDS_SET_DOWNLINK_THROUGHPUT_REPORT_PERIOD_REQ_V01, QMI_IDL_TYPE16(0, 266), 7},
  {QMI_WDS_QUERY_DOWNLINK_THROUGHPUT_REPORTING_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 269), 0},
  {QMI_WDS_KEEP_ALIVE_DATA_SESSION_REQ_V01, QMI_IDL_TYPE16(0, 271), 4},
  {QMI_WDS_SET_ALWAYS_ON_PDN_REQ_V01, QMI_IDL_TYPE16(0, 273), 15},
  {QMI_WDS_TEAR_DOWN_ALWAYS_ON_PDN_REQ_V01, QMI_IDL_TYPE16(0, 281), 0},
  {QMI_WDS_RESET_AND_MODIFY_PROFILE_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 284), 3089},
  {QMI_WDS_SET_ATTACH_PROFILE_INFO_REQ_V01, QMI_IDL_TYPE16(0, 286), 1153},
  {QMI_WDS_GET_APN_OP_RESERVED_PCO_LIST_REQ_V01, QMI_IDL_TYPE16(0, 276), 153},
  {QMI_WDS_GET_APN_MSISDN_INFO_REQ_V01, QMI_IDL_TYPE16(0, 279), 153},
  {QMI_WDS_DELETE_ALL_PROFILES_REQ_V01, QMI_IDL_TYPE16(0, 288), 33},
  {QMI_WDS_GET_LAST_3GPP_RAB_REJECT_INFO_REQ_V01, QMI_IDL_TYPE16(0, 292), 0},
  {QMI_WDS_GET_THROTTLED_PDN_REJECT_TIMER_REQ_V01, QMI_IDL_TYPE16(0, 294), 0},
  {QMI_WDS_SET_THROTTLED_PDN_REJECT_TIMER_REQ_V01, QMI_IDL_TYPE16(0, 296), 7},
  {QMI_WDS_SET_EHRPD_FALLBACK_APN_LIST_REQ_V01, QMI_IDL_TYPE16(0, 298), 2420},
  {QMI_WDS_GET_EHRPD_FALLBACK_APN_LIST_REQ_V01, QMI_IDL_TYPE16(0, 300), 0},
  {QMI_WDS_SUBSEQUENT_DATA_TRANSFER_STATUS_REQ_V01, QMI_IDL_TYPE16(0, 302), 11},
  {QMI_WDS_MODEM_ASSISTED_KA_START_REQ_V01, QMI_IDL_TYPE16(0, 304), 229},
  {QMI_WDS_MODEM_ASSISTED_KA_STOP_REQ_V01, QMI_IDL_TYPE16(0, 307), 7},
  {QMI_WDS_V2X_SPS_FLOW_REG_REQ_V01, QMI_IDL_TYPE16(0, 309), 71},
  {QMI_WDS_V2X_SPS_FLOW_DEREG_REQ_V01, QMI_IDL_TYPE16(0, 312), 8},
  {QMI_WDS_V2X_SPS_FLOW_UPDATE_REQ_V01, QMI_IDL_TYPE16(0, 315), 44},
  {QMI_WDS_V2X_SPS_FLOW_GET_INFO_REQ_V01, QMI_IDL_TYPE16(0, 318), 8},
  {QMI_WDS_V2X_NON_SPS_FLOW_REG_REQ_V01, QMI_IDL_TYPE16(0, 320), 2596},
  {QMI_WDS_V2X_NON_SPS_FLOW_DEREG_REQ_V01, QMI_IDL_TYPE16(0, 322), 1541},
  {QMI_WDS_V2X_SERVICE_SUBSCRIBE_REQ_V01, QMI_IDL_TYPE16(0, 324), 1040},
  {QMI_WDS_V2X_GET_SERVICE_SUBSCRIPTION_INFO_REQ_V01, QMI_IDL_TYPE16(0, 327), 0},
  {QMI_WDS_SET_DATA_LOW_LATENCY_MODE_REQ_V01, QMI_IDL_TYPE16(0, 329), 22},
  {QMI_WDS_GET_DATA_LOW_LATENCY_MODE_REQ_V01, QMI_IDL_TYPE16(0, 331), 0},
  {QMI_WDS_GET_AVAIL_EXT_IPV6_ADDRS_REQ_V01, QMI_IDL_TYPE16(0, 333), 0},
  {QMI_WDS_GET_LTE_EMERGENCY_ATTACH_PARAMS_REQ_V01, QMI_IDL_TYPE16(0, 345), 0},
  {QMI_WDS_RAN_ASST_MEDIA_ADAPTATION_REG_REQ_V01, QMI_IDL_TYPE16(0, 347), 75},
  {QMI_WDS_RAN_ASST_MEDIA_ADAPTATION_DEREG_REQ_V01, QMI_IDL_TYPE16(0, 349), 7},
  {QMI_WDS_UPDATE_RAN_ASST_MEDIA_ADAPTION_REQ_V01, QMI_IDL_TYPE16(0, 351), 12},
  {QMI_WDS_V2X_SEND_CONFIG_FILE_REQ_V01, QMI_IDL_TYPE16(0, 354), 1523},
  {QMI_WDS_V2X_UPDATE_SRC_L2_INFO_REQ_V01, QMI_IDL_TYPE16(0, 358), 0},
  {QMI_WDS_CREATE_PROFILE_LITE_REQ_V01, QMI_IDL_TYPE16(0, 335), 634},
  {QMI_WDS_MODIFY_PROFILE_SETTINGS_LITE_REQ_V01, QMI_IDL_TYPE16(0, 337), 787},
  {QMI_WDS_DELETE_PROFILE_LITE_REQ_V01, QMI_IDL_TYPE16(0, 339), 157},
  {QMI_WDS_GET_PROFILE_SETTINGS_LITE_REQ_V01, QMI_IDL_TYPE16(0, 341), 157},
  {QMI_WDS_GET_PROFILE_LIST_LITE_REQ_V01, QMI_IDL_TYPE16(0, 343), 0},
  {QMI_WDS_V2X_TUNNEL_MODE_INFO_REQ_V01, QMI_IDL_TYPE16(0, 361), 1512},
  {QMI_WDS_GET_DATA_BEARER_TYPE_REQ_V01, QMI_IDL_TYPE16(0, 363), 4},
  {QMI_WDS_V2X_GET_CAPABILITY_INFO_REQ_V01, QMI_IDL_TYPE16(0, 366), 0},
  {QMI_WDS_SET_DATA_COALESCING_REQ_V01, QMI_IDL_TYPE16(0, 369), 5},
  {QMI_WDS_GET_DATA_COALESCING_REQ_V01, QMI_IDL_TYPE16(0, 371), 0},
  {QMI_WDS_GET_SPLMN_RATE_CONTROL_INFO_REQ_V01, QMI_IDL_TYPE16(0, 373), 0},
  {QMI_WDS_GET_APN_RATE_CONTROL_INFO_REQ_V01, QMI_IDL_TYPE16(0, 375), 0},
  {QMI_WDS_SET_XCAP_CONFIG_REQ_V01, QMI_IDL_TYPE16(0, 377), 1477},
  {QMI_WDS_SET_LADN_CONFIG_REQ_V01, QMI_IDL_TYPE16(0, 380), 1222},
  {QMI_WDS_GET_LADN_INFO_REQ_V01, QMI_IDL_TYPE16(0, 384), 6},
  {QMI_WDS_SET_CAPABILITIES_REQ_V01, QMI_IDL_TYPE16(0, 386), 14},
  {QMI_WDS_REFRESH_DHCP_CONFIG_INFO_REQ_V01, QMI_IDL_TYPE16(0, 216), 0},
  {QMI_WDS_SET_INTERNAL_RUNTIME_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 214), 40},
  {QMI_WDS_GET_INTERNAL_RUNTIME_SETTINGS_REQ_V01, QMI_IDL_TYPE16(0, 212), 18},
  {QMI_WDS_INTERNAL_IFACE_EV_REGISTER_REQ_V01, QMI_IDL_TYPE16(0, 209), 7}
};

static const qmi_idl_service_message_table_entry wds_service_response_messages_v01[] = {
  {QMI_WDS_RESET_RESP_V01, QMI_IDL_TYPE16(0, 1), 7},
  {QMI_WDS_SET_EVENT_REPORT_RESP_V01, QMI_IDL_TYPE16(0, 3), 7},
  {QMI_WDS_ABORT_RESP_V01, QMI_IDL_TYPE16(0, 6), 7},
  {QMI_WDS_INDICATION_REGISTER_RESP_V01, QMI_IDL_TYPE16(0, 8), 7},
  {QMI_WDS_GET_SUPPORTED_MSGS_RESP_V01, QMI_IDL_TYPE16(1, 1), 8204},
  {QMI_WDS_GET_SUPPORTED_FIELDS_RESP_V01, QMI_IDL_TYPE16(1, 3), 115},
  {QMI_WDS_START_NETWORK_INTERFACE_RESP_V01, QMI_IDL_TYPE16(0, 10), 41},
  {QMI_WDS_STOP_NETWORK_INTERFACE_RESP_V01, QMI_IDL_TYPE16(0, 12), 7},
  {QMI_WDS_GET_PKT_SRVC_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 14), 401},
  {QMI_WDS_GET_CURRENT_CHANNEL_RATE_RESP_V01, QMI_IDL_TYPE16(0, 17), 65},
  {QMI_WDS_GET_PKT_STATISTICS_RESP_V01, QMI_IDL_TYPE16(0, 19), 107},
  {QMI_WDS_GO_DORMANT_RESP_V01, QMI_IDL_TYPE16(0, 21), 7},
  {QMI_WDS_GO_ACTIVE_RESP_V01, QMI_IDL_TYPE16(0, 23), 7},
  {QMI_WDS_CREATE_PROFILE_RESP_V01, QMI_IDL_TYPE16(0, 25), 17},
  {QMI_WDS_MODIFY_PROFILE_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 27), 12},
  {QMI_WDS_DELETE_PROFILE_RESP_V01, QMI_IDL_TYPE16(0, 29), 12},
  {QMI_WDS_GET_PROFILE_LIST_RESP_V01, QMI_IDL_TYPE16(0, 31), 13531},
  {QMI_WDS_GET_PROFILE_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 33), 3100},
  {QMI_WDS_GET_DEFAULT_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 35), 3096},
  {QMI_WDS_GET_RUNTIME_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 37), 11887},
  {QMI_WDS_SET_MIP_MODE_RESP_V01, QMI_IDL_TYPE16(0, 39), 7},
  {QMI_WDS_GET_MIP_MODE_RESP_V01, QMI_IDL_TYPE16(0, 41), 11},
  {QMI_WDS_GET_DORMANCY_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 43), 11},
  {QMI_WDS_GET_AUTOCONNECT_SETTING_RESP_V01, QMI_IDL_TYPE16(0, 45), 15},
  {QMI_WDS_GET_CALL_DURATION_RESP_V01, QMI_IDL_TYPE16(0, 47), 51},
  {QMI_WDS_GET_DATA_BEARER_TECHNOLOGY_RESP_V01, QMI_IDL_TYPE16(0, 49), 15},
  {QMI_WDS_GET_DUN_CALL_INFO_RESP_V01, QMI_IDL_TYPE16(0, 51), 110},
  {QMI_WDS_GET_ACTIVE_MIP_PROFILE_RESP_V01, QMI_IDL_TYPE16(0, 54), 11},
  {QMI_WDS_SET_ACTIVE_MIP_PROFILE_RESP_V01, QMI_IDL_TYPE16(0, 56), 7},
  {QMI_WDS_READ_MIP_PROFILE_RESP_V01, QMI_IDL_TYPE16(0, 58), 133},
  {QMI_WDS_MODIFY_MIP_PROFILE_RESP_V01, QMI_IDL_TYPE16(0, 60), 7},
  {QMI_WDS_GET_MIP_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 62), 35},
  {QMI_WDS_SET_MIP_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 64), 7},
  {QMI_WDS_GET_LAST_MIP_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 66), 11},
  {QMI_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_RESP_V01, QMI_IDL_TYPE16(0, 68), 31},
  {QMI_WDS_CALL_HISTORY_LIST_RESP_V01, QMI_IDL_TYPE16(0, 70), 7667},
  {QMI_WDS_CALL_HISTORY_READ_RESP_V01, QMI_IDL_TYPE16(0, 72), 159},
  {QMI_WDS_CALL_HISTORY_DELETE_RESP_V01, QMI_IDL_TYPE16(0, 74), 7},
  {QMI_WDS_CALL_HISTORY_MAX_SIZE_RESP_V01, QMI_IDL_TYPE16(0, 76), 12},
  {QMI_WDS_GET_DEFAULT_PROFILE_NUM_RESP_V01, QMI_IDL_TYPE16(0, 78), 16},
  {QMI_WDS_SET_DEFAULT_PROFILE_NUM_RESP_V01, QMI_IDL_TYPE16(0, 80), 12},
  {QMI_WDS_RESET_PROFILE_TO_DEFAULT_RESP_V01, QMI_IDL_TYPE16(0, 82), 12},
  {QMI_WDS_RESET_PROFILE_PARAM_TO_INVALID_RESP_V01, QMI_IDL_TYPE16(0, 84), 12},
  {QMI_WDS_SET_CLIENT_IP_FAMILY_PREF_RESP_V01, QMI_IDL_TYPE16(0, 86), 7},
  {QMI_WDS_FMC_SET_TUNNEL_PARAMS_RESP_V01, QMI_IDL_TYPE16(0, 88), 7},
  {QMI_WDS_FMC_CLEAR_TUNNEL_PARAMS_RESP_V01, QMI_IDL_TYPE16(0, 90), 7},
  {QMI_WDS_FMC_GET_TUNNEL_PARAMS_RESP_V01, QMI_IDL_TYPE16(0, 92), 43},
  {QMI_WDS_SET_AUTOCONNECT_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 94), 7},
  {QMI_WDS_GET_DNS_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 96), 59},
  {QMI_WDS_SET_DNS_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 98), 7},
  {QMI_WDS_GET_PRE_DORMANCY_CDMA_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 100), 13},
  {QMI_WDS_SET_CAM_TIMER_RESP_V01, QMI_IDL_TYPE16(0, 102), 7},
  {QMI_WDS_GET_CAM_TIMER_RESP_V01, QMI_IDL_TYPE16(0, 104), 14},
  {QMI_WDS_SET_SCRM_RESP_V01, QMI_IDL_TYPE16(0, 106), 7},
  {QMI_WDS_GET_SCRM_RESP_V01, QMI_IDL_TYPE16(0, 108), 11},
  {QMI_WDS_SET_RDUD_RESP_V01, QMI_IDL_TYPE16(0, 110), 7},
  {QMI_WDS_GET_RDUD_RESP_V01, QMI_IDL_TYPE16(0, 112), 11},
  {QMI_WDS_GET_SIP_MIP_CALL_TYPE_RESP_V01, QMI_IDL_TYPE16(0, 114), 11},
  {QMI_WDS_SET_EVDO_PAGE_MONITOR_PERIOD_RESP_V01, QMI_IDL_TYPE16(0, 116), 7},
  {QMI_WDS_SET_EVDO_FORCE_LONG_SLEEP_RESP_V01, QMI_IDL_TYPE16(0, 119), 7},
  {QMI_WDS_GET_EVDO_PAGE_MONITOR_PERIOD_RESP_V01, QMI_IDL_TYPE16(0, 121), 12},
  {QMI_WDS_GET_CALL_THROTTLE_INFO_RESP_V01, QMI_IDL_TYPE16(0, 123), 18},
  {QMI_WDS_GET_NAAPI_RESP_V01, QMI_IDL_TYPE16(0, 125), 19},
  {QMI_WDS_SET_DUN_CTRL_PREF_RESP_V01, QMI_IDL_TYPE16(0, 127), 7},
  {QMI_WDS_GET_DUN_CTRL_INFO_RESP_V01, QMI_IDL_TYPE16(0, 129), 23},
  {QMI_WDS_SET_DUN_CTRL_EVENT_REPORT_RESP_V01, QMI_IDL_TYPE16(0, 131), 11},
  {QMI_WDS_CONTROL_PENDING_DUN_CALL_RESP_V01, QMI_IDL_TYPE16(0, 134), 7},
  {QMI_WDS_EMBMS_TMGI_ACTIVATE_RESP_V01, QMI_IDL_TYPE16(0, 136), 12},
  {QMI_WDS_EMBMS_TMGI_DEACTIVATE_RESP_V01, QMI_IDL_TYPE16(0, 139), 12},
  {QMI_WDS_EMBMS_TMGI_LIST_QUERY_RESP_V01, QMI_IDL_TYPE16(0, 142), 1043},
  {QMI_WDS_GET_PREFERRED_DATA_SYSTEM_RESP_V01, QMI_IDL_TYPE16(0, 145), 14},
  {QMI_WDS_GET_LAST_DATA_CALL_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 147), 23},
  {QMI_WDS_GET_CURRENT_SYSTEM_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 149), 156},
  {QMI_WDS_GET_PDN_THROTTLE_INFO_RESP_V01, QMI_IDL_TYPE16(0, 151), 3888},
  {QMI_WDS_GET_LTE_ATTACH_PARAMS_RESP_V01, QMI_IDL_TYPE16(0, 162), 229},
  {QMI_WDS_RESET_PKT_STATISTICS_RESP_V01, QMI_IDL_TYPE16(0, 164), 7},
  {QMI_WDS_GET_FLOW_CONTROL_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 166), 11},
  {QMI_WDS_EMBMS_TMGI_ACT_DEACT_RESP_V01, QMI_IDL_TYPE16(0, 168), 12},
  {QMI_WDS_BIND_DATA_PORT_RESP_V01, QMI_IDL_TYPE16(0, 171), 7},
  {QMI_WDS_SET_ADDITIONAL_PDN_FILTER_RESP_V01, QMI_IDL_TYPE16(0, 173), 14},
  {QMI_WDS_REMOVE_ADDITIONAL_PDN_FILTER_RESP_V01, QMI_IDL_TYPE16(0, 175), 7},
  {QMI_WDS_REVERSE_IP_TRANSPORT_CONNECTION_IND_REGISTRATION_RESP_V01, QMI_IDL_TYPE16(0, 178), 7},
  {QMI_WDS_GET_IPSEC_STATIC_SA_CONFIG_RESP_V01, QMI_IDL_TYPE16(0, 181), 3625},
  {QMI_WDS_REVERSE_IP_TRANSPORT_CONFIG_COMPLETE_RESP_V01, QMI_IDL_TYPE16(0, 183), 7},
  {QMI_WDS_GET_DATA_BEARER_TECHNOLOGY_EX_RESP_V01, QMI_IDL_TYPE16(0, 185), 45},
  {QMI_WDS_GET_LTE_MAX_ATTACH_PDN_NUM_RESP_V01, QMI_IDL_TYPE16(0, 154), 11},
  {QMI_WDS_SET_LTE_ATTACH_PDN_LIST_RESP_V01, QMI_IDL_TYPE16(0, 156), 7},
  {QMI_WDS_GET_LTE_ATTACH_PDN_LIST_RESP_V01, QMI_IDL_TYPE16(0, 159), 239},
  {QMI_WDS_SET_LTE_DATA_RETRY_RESP_V01, QMI_IDL_TYPE16(0, 187), 7},
  {QMI_WDS_GET_LTE_DATA_RETRY_RESP_V01, QMI_IDL_TYPE16(0, 189), 11},
  {QMI_WDS_SET_LTE_ATTACH_TYPE_RESP_V01, QMI_IDL_TYPE16(0, 191), 7},
  {QMI_WDS_GET_LTE_ATTACH_TYPE_RESP_V01, QMI_IDL_TYPE16(0, 193), 14},
  {QMI_WDS_SET_DATA_PATH_RESP_V01, QMI_IDL_TYPE16(0, 197), 7},
  {QMI_WDS_GET_DATA_PATH_RESP_V01, QMI_IDL_TYPE16(0, 199), 14},
  {QMI_WDS_UPDATE_LTE_ATTACH_PDN_LIST_PROFILES_RESP_V01, QMI_IDL_TYPE16(0, 201), 7},
  {QMI_WDS_EMBMS_SAI_LIST_QUERY_RESP_V01, QMI_IDL_TYPE16(0, 203), 9411},
  {QMI_WDS_BIND_MUX_DATA_PORT_RESP_V01, QMI_IDL_TYPE16(0, 206), 7},
  {QMI_WDS_SET_THROUGHPUT_INFO_IND_FREQ_RESP_V01, QMI_IDL_TYPE16(0, 219), 7},
  {QMI_WDS_GET_LAST_THROUGHPUT_INFO_RESP_V01, QMI_IDL_TYPE16(0, 221), 42261},
  {QMI_WDS_INITIATE_ESP_REKEY_RESP_V01, QMI_IDL_TYPE16(0, 208), 7},
  {QMI_WDS_CONFIGURE_PROFILE_EVENT_LIST_RESP_V01, QMI_IDL_TYPE16(0, 224), 7},
  {QMI_WDS_GET_CAPABILITIES_RESP_V01, QMI_IDL_TYPE16(0, 227), 55},
  {QMI_WDS_GET_ROAMING_INFO_RESP_V01, QMI_IDL_TYPE16(0, 229), 3036},
  {QMI_WDS_GET_DELEGATED_IPV6_PREFIX_RESP_V01, QMI_IDL_TYPE16(0, 232), 27},
  {QMI_WDS_REMOVE_DELEGATED_IPV6_PREFIX_RESP_V01, QMI_IDL_TYPE16(0, 234), 7},
  {QMI_WDS_ABORT_GO_DORMANT_RESP_V01, QMI_IDL_TYPE16(0, 236), 7},
  {QMI_WDS_BIND_SUBSCRIPTION_RESP_V01, QMI_IDL_TYPE16(0, 238), 7},
  {QMI_WDS_GET_BIND_SUBSCRIPTION_RESP_V01, QMI_IDL_TYPE16(0, 240), 14},
  {QMI_WDS_SET_LTE_DATA_CALL_TYPE_RESP_V01, QMI_IDL_TYPE16(0, 242), 7},
  {QMI_WDS_SET_DOWNLINK_THROUGHPUT_INFO_IND_FREQ_RESP_V01, QMI_IDL_TYPE16(0, 244), 7},
  {QMI_WDS_GET_DOWNLINK_THROUGHPUT_INFO_PARAMS_RESP_V01, QMI_IDL_TYPE16(0, 247), 14},
  {QMI_WDS_EMBMS_CONTENT_DESC_UPDATE_RESP_V01, QMI_IDL_TYPE16(0, 249), 7},
  {QMI_WDS_POLICY_REFRESH_RESP_V01, QMI_IDL_TYPE16(0, 252), 7},
  {QMI_WDS_SET_SILENT_REDIAL_RESP_V01, QMI_IDL_TYPE16(0, 257), 7},
  {QMI_WDS_GET_CONFIGURED_THROUGHPUT_INFO_RESP_V01, QMI_IDL_TYPE16(0, 260), 21},
  {QMI_WDS_GET_DOWNLINK_THROUGHPUT_INFO_RESP_V01, QMI_IDL_TYPE16(0, 262), 18},
  {QMI_WDS_EMBMS_SVC_INTEREST_INFO_RESP_V01, QMI_IDL_TYPE16(0, 265), 7},
  {QMI_WDS_SET_DOWNLINK_THROUGHPUT_REPORT_PERIOD_RESP_V01, QMI_IDL_TYPE16(0, 267), 7},
  {QMI_WDS_QUERY_DOWNLINK_THROUGHPUT_REPORTING_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 270), 21},
  {QMI_WDS_KEEP_ALIVE_DATA_SESSION_RESP_V01, QMI_IDL_TYPE16(0, 272), 7},
  {QMI_WDS_SET_ALWAYS_ON_PDN_RESP_V01, QMI_IDL_TYPE16(0, 274), 7},
  {QMI_WDS_TEAR_DOWN_ALWAYS_ON_PDN_RESP_V01, QMI_IDL_TYPE16(0, 282), 7},
  {QMI_WDS_RESET_AND_MODIFY_PROFILE_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 285), 12},
  {QMI_WDS_SET_ATTACH_PROFILE_INFO_RESP_V01, QMI_IDL_TYPE16(0, 287), 16},
  {QMI_WDS_GET_APN_OP_RESERVED_PCO_LIST_RESP_V01, QMI_IDL_TYPE16(0, 277), 2661},
  {QMI_WDS_GET_APN_MSISDN_INFO_RESP_V01, QMI_IDL_TYPE16(0, 280), 266},
  {QMI_WDS_DELETE_ALL_PROFILES_RESP_V01, QMI_IDL_TYPE16(0, 289), 7},
  {QMI_WDS_GET_LAST_3GPP_RAB_REJECT_INFO_RESP_V01, QMI_IDL_TYPE16(0, 293), 14},
  {QMI_WDS_GET_THROTTLED_PDN_REJECT_TIMER_RESP_V01, QMI_IDL_TYPE16(0, 295), 14},
  {QMI_WDS_SET_THROTTLED_PDN_REJECT_TIMER_RESP_V01, QMI_IDL_TYPE16(0, 297), 7},
  {QMI_WDS_SET_EHRPD_FALLBACK_APN_LIST_RESP_V01, QMI_IDL_TYPE16(0, 299), 7},
  {QMI_WDS_GET_EHRPD_FALLBACK_APN_LIST_RESP_V01, QMI_IDL_TYPE16(0, 301), 2427},
  {QMI_WDS_SUBSEQUENT_DATA_TRANSFER_STATUS_RESP_V01, QMI_IDL_TYPE16(0, 303), 7},
  {QMI_WDS_MODEM_ASSISTED_KA_START_RESP_V01, QMI_IDL_TYPE16(0, 305), 14},
  {QMI_WDS_MODEM_ASSISTED_KA_STOP_RESP_V01, QMI_IDL_TYPE16(0, 308), 7},
  {QMI_WDS_V2X_SPS_FLOW_REG_RESP_V01, QMI_IDL_TYPE16(0, 310), 7},
  {QMI_WDS_V2X_SPS_FLOW_DEREG_RESP_V01, QMI_IDL_TYPE16(0, 313), 7},
  {QMI_WDS_V2X_SPS_FLOW_UPDATE_RESP_V01, QMI_IDL_TYPE16(0, 316), 7},
  {QMI_WDS_V2X_SPS_FLOW_GET_INFO_RESP_V01, QMI_IDL_TYPE16(0, 319), 71},
  {QMI_WDS_V2X_NON_SPS_FLOW_REG_RESP_V01, QMI_IDL_TYPE16(0, 321), 2062},
  {QMI_WDS_V2X_NON_SPS_FLOW_DEREG_RESP_V01, QMI_IDL_TYPE16(0, 323), 2051},
  {QMI_WDS_V2X_SERVICE_SUBSCRIBE_RESP_V01, QMI_IDL_TYPE16(0, 325), 7},
  {QMI_WDS_V2X_GET_SERVICE_SUBSCRIPTION_INFO_RESP_V01, QMI_IDL_TYPE16(0, 328), 1040},
  {QMI_WDS_SET_DATA_LOW_LATENCY_MODE_RESP_V01, QMI_IDL_TYPE16(0, 330), 7},
  {QMI_WDS_GET_DATA_LOW_LATENCY_MODE_RESP_V01, QMI_IDL_TYPE16(0, 332), 29},
  {QMI_WDS_GET_AVAIL_EXT_IPV6_ADDRS_RESP_V01, QMI_IDL_TYPE16(0, 334), 521},
  {QMI_WDS_GET_LTE_EMERGENCY_ATTACH_PARAMS_RESP_V01, QMI_IDL_TYPE16(0, 346), 11},
  {QMI_WDS_RAN_ASST_MEDIA_ADAPTATION_REG_RESP_V01, QMI_IDL_TYPE16(0, 348), 14},
  {QMI_WDS_RAN_ASST_MEDIA_ADAPTATION_DEREG_RESP_V01, QMI_IDL_TYPE16(0, 350), 7},
  {QMI_WDS_UPDATE_RAN_ASST_MEDIA_ADAPTION_RESP_V01, QMI_IDL_TYPE16(0, 352), 7},
  {QMI_WDS_V2X_SEND_CONFIG_FILE_RESP_V01, QMI_IDL_TYPE16(0, 355), 7},
  {QMI_WDS_V2X_UPDATE_SRC_L2_INFO_RESP_V01, QMI_IDL_TYPE16(0, 359), 7},
  {QMI_WDS_CREATE_PROFILE_LITE_RESP_V01, QMI_IDL_TYPE16(0, 336), 12},
  {QMI_WDS_MODIFY_PROFILE_SETTINGS_LITE_RESP_V01, QMI_IDL_TYPE16(0, 338), 12},
  {QMI_WDS_DELETE_PROFILE_LITE_RESP_V01, QMI_IDL_TYPE16(0, 340), 12},
  {QMI_WDS_GET_PROFILE_SETTINGS_LITE_RESP_V01, QMI_IDL_TYPE16(0, 342), 516},
  {QMI_WDS_GET_PROFILE_LIST_LITE_RESP_V01, QMI_IDL_TYPE16(0, 344), 4576},
  {QMI_WDS_V2X_TUNNEL_MODE_INFO_RESP_V01, QMI_IDL_TYPE16(0, 362), 7},
  {QMI_WDS_GET_DATA_BEARER_TYPE_RESP_V01, QMI_IDL_TYPE16(0, 364), 299},
  {QMI_WDS_V2X_GET_CAPABILITY_INFO_RESP_V01, QMI_IDL_TYPE16(0, 367), 274},
  {QMI_WDS_SET_DATA_COALESCING_RESP_V01, QMI_IDL_TYPE16(0, 370), 7},
  {QMI_WDS_GET_DATA_COALESCING_RESP_V01, QMI_IDL_TYPE16(0, 372), 12},
  {QMI_WDS_GET_SPLMN_RATE_CONTROL_INFO_RESP_V01, QMI_IDL_TYPE16(0, 374), 29},
  {QMI_WDS_GET_APN_RATE_CONTROL_INFO_RESP_V01, QMI_IDL_TYPE16(0, 376), 193},
  {QMI_WDS_SET_XCAP_CONFIG_RESP_V01, QMI_IDL_TYPE16(0, 378), 7},
  {QMI_WDS_SET_LADN_CONFIG_RESP_V01, QMI_IDL_TYPE16(0, 381), 7},
  {QMI_WDS_GET_LADN_INFO_RESP_V01, QMI_IDL_TYPE16(0, 385), 2449},
  {QMI_WDS_SET_CAPABILITIES_RESP_V01, QMI_IDL_TYPE16(0, 387), 21},
  {QMI_WDS_REFRESH_DHCP_CONFIG_INFO_RESP_V01, QMI_IDL_TYPE16(0, 217), 7},
  {QMI_WDS_SET_INTERNAL_RUNTIME_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 215), 56},
  {QMI_WDS_GET_INTERNAL_RUNTIME_SETTINGS_RESP_V01, QMI_IDL_TYPE16(0, 213), 100},
  {QMI_WDS_INTERNAL_IFACE_EV_REGISTER_RESP_V01, QMI_IDL_TYPE16(0, 210), 7}
};

static const qmi_idl_service_message_table_entry wds_service_indication_messages_v01[] = {
  {QMI_WDS_EVENT_REPORT_IND_V01, QMI_IDL_TYPE16(0, 4), 553},
  {QMI_WDS_PKT_SRVC_STATUS_IND_V01, QMI_IDL_TYPE16(0, 15), 427},
  {QMI_WDS_DUN_CALL_INFO_IND_V01, QMI_IDL_TYPE16(0, 52), 50},
  {QMI_WDS_EVDO_PAGE_MONITOR_PERIOD_RESULT_IND_V01, QMI_IDL_TYPE16(0, 117), 4},
  {QMI_WDS_DUN_CTRL_EVENT_REPORT_IND_V01, QMI_IDL_TYPE16(0, 132), 19},
  {QMI_WDS_EMBMS_TMGI_ACTIVATE_IND_V01, QMI_IDL_TYPE16(0, 137), 23},
  {QMI_WDS_EMBMS_TMGI_DEACTIVATE_IND_V01, QMI_IDL_TYPE16(0, 140), 23},
  {QMI_WDS_EMBMS_TMGI_LIST_IND_V01, QMI_IDL_TYPE16(0, 143), 1041},
  {QMI_WDS_PDN_THROTTLE_INFO_V2_RESULT_IND_V01, QMI_IDL_TYPE16(0, 388), 1379},
  {QMI_WDS_EMBMS_TMGI_ACT_DEACT_IND_V01, QMI_IDL_TYPE16(0, 169), 41},
  {QMI_WDS_EXTENDED_IP_CONFIG_IND_V01, QMI_IDL_TYPE16(0, 176), 7},
  {QMI_WDS_REVERSE_IP_TRANSPORT_CONNECTION_IND_V01, QMI_IDL_TYPE16(0, 179), 64},
  {QMI_WDS_SET_LTE_ATTACH_PDN_LIST_ACTION_RESULT_IND_V01, QMI_IDL_TYPE16(0, 157), 4},
  {QMI_WDS_LTE_ATTACH_PDN_LIST_IND_V01, QMI_IDL_TYPE16(0, 160), 116},
  {QMI_WDS_REVERSE_IP_TRANSPORT_FILTER_SETUP_IND_V01, QMI_IDL_TYPE16(0, 194), 14},
  {QMI_WDS_HANDOFF_INFORMATION_IND_V01, QMI_IDL_TYPE16(0, 195), 25},
  {QMI_WDS_EMBMS_SAI_LIST_IND_V01, QMI_IDL_TYPE16(0, 204), 9409},
  {QMI_WDS_THROUGHPUT_INFO_IND_V01, QMI_IDL_TYPE16(0, 222), 42254},
  {QMI_WDS_PROFILE_EVENT_REGISTER_IND_V01, QMI_IDL_TYPE16(0, 225), 6},
  {QMI_WDS_ROAMING_INFO_V2_RESULT_IND_V01, QMI_IDL_TYPE16(0, 390), 3031},
  {QMI_WDS_ROAMING_INFO_IND_V01, QMI_IDL_TYPE16(0, 230), 3031},
  {QMI_WDS_DOWNLINK_THROUGHPUT_INFO_IND_V01, QMI_IDL_TYPE16(0, 245), 15},
  {QMI_WDS_EMBMS_CONTENT_DESC_CONTROL_IND_V01, QMI_IDL_TYPE16(0, 250), 30},
  {QMI_WDS_POLICY_REFRESH_RESULT_IND_V01, QMI_IDL_TYPE16(0, 253), 7},
  {QMI_WDS_POLICY_READY_IND_V01, QMI_IDL_TYPE16(0, 254), 134},
  {QMI_WDS_APN_PARAM_INFO_CHANGE_IND_V01, QMI_IDL_TYPE16(0, 255), 310},
  {QMI_WDS_CONFIGURED_THROUGHPUT_INFO_IND_V01, QMI_IDL_TYPE16(0, 258), 14},
  {QMI_WDS_EMBMS_SVC_INTEREST_IND_V01, QMI_IDL_TYPE16(0, 263), 5},
  {QMI_WDS_DOWNLINK_THROUGHPUT_REPORTING_STATUS_IND_V01, QMI_IDL_TYPE16(0, 268), 14},
  {QMI_WDS_LTE_ATTACH_PARAMS_IND_V01, QMI_IDL_TYPE16(0, 283), 222},
  {QMI_WDS_APN_OP_RESERVED_PCO_LIST_CHANGE_IND_V01, QMI_IDL_TYPE16(0, 275), 2805},
  {QMI_WDS_APN_MSISDN_CHANGE_IND_V01, QMI_IDL_TYPE16(0, 278), 410},
  {QMI_WDS_DELETE_ALL_PROFILES_RESULT_IND_V01, QMI_IDL_TYPE16(0, 290), 7708},
  {QMI_WDS_3GPP_RAB_REJECT_IND_V01, QMI_IDL_TYPE16(0, 291), 7},
  {QMI_WDS_PDN_THROTTLE_INFO_IND_V01, QMI_IDL_TYPE16(0, 152), 3876},
  {QMI_WDS_MODEM_ASSISTED_KA_STATUS_IND_V01, QMI_IDL_TYPE16(0, 306), 14},
  {QMI_WDS_V2X_SPS_FLOW_REG_RESULT_IND_V01, QMI_IDL_TYPE16(0, 311), 12},
  {QMI_WDS_V2X_SPS_FLOW_DEREG_RESULT_IND_V01, QMI_IDL_TYPE16(0, 314), 12},
  {QMI_WDS_V2X_SPS_FLOW_UPDATE_RESULT_IND_V01, QMI_IDL_TYPE16(0, 317), 12},
  {QMI_WDS_V2X_SERVICE_SUBSCRIBE_RESULT_IND_V01, QMI_IDL_TYPE16(0, 326), 2055},
  {QMI_WDS_RAN_ASST_MEDIA_ADAPTATION_INFO_IND_V01, QMI_IDL_TYPE16(0, 353), 13},
  {QMI_WDS_V2X_SEND_CONFIG_FILE_RESULT_IND_V01, QMI_IDL_TYPE16(0, 356), 11},
  {QMI_WDS_V2X_SPS_SCHEDULING_INFO_IND_V01, QMI_IDL_TYPE16(0, 357), 16},
  {QMI_WDS_V2X_SRC_L2_INFO_IND_V01, QMI_IDL_TYPE16(0, 360), 7},
  {QMI_WDS_DATA_BEARER_TYPE_IND_V01, QMI_IDL_TYPE16(0, 365), 12},
  {QMI_WDS_V2X_CAPABILITY_INFO_IND_V01, QMI_IDL_TYPE16(0, 368), 267},
  {QMI_WDS_SET_XCAP_CONFIG_RESULT_IND_V01, QMI_IDL_TYPE16(0, 379), 11},
  {QMI_WDS_LADN_CONFIG_RESULT_IND_V01, QMI_IDL_TYPE16(0, 382), 11},
  {QMI_WDS_LADN_INFO_IND_V01, QMI_IDL_TYPE16(0, 383), 2442},
  {QMI_WDS_PDN_THROTTLE_INFO_V2_IND_V01, QMI_IDL_TYPE16(0, 389), 1379},
  {QMI_WDS_REBIND_DEFAULT_FLOW_INFO_IND_V01, QMI_IDL_TYPE16(0, 391), 4},
  {QMI_WDS_LTE_ATTACH_FAILURE_INFO_IND_V01, QMI_IDL_TYPE16(0, 392), 13},
  {QMI_WDS_INTERNAL_IFACE_EV_IND_V01, QMI_IDL_TYPE16(0, 211), 58}
};

/*Service Object*/
struct qmi_idl_service_object wds_qmi_idl_service_object_v01 = {
  0x06,
  0x01,
  0x01,
  42261,
  { sizeof(wds_service_command_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(wds_service_response_messages_v01)/sizeof(qmi_idl_service_message_table_entry),
    sizeof(wds_service_indication_messages_v01)/sizeof(qmi_idl_service_message_table_entry) },
  { wds_service_command_messages_v01, wds_service_response_messages_v01, wds_service_indication_messages_v01},
  &wds_qmi_idl_type_table_object_v01,
  0xB2,
  NULL
};

/* Service Object Accessor */
qmi_idl_service_object_type wds_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version ){
  if ( WDS_V01_IDL_MAJOR_VERS != idl_maj_version || WDS_V01_IDL_MINOR_VERS != idl_min_version
       || WDS_V01_IDL_TOOL_VERS != library_version)
  {
    return NULL;
  }
  return (qmi_idl_service_object_type)&wds_qmi_idl_service_object_v01;
}
