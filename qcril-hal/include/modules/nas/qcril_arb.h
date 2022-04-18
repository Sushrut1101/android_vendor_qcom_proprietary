/******************************************************************************
#  Copyright (c) 2009-2013, 2017 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#******************************************************************************/
/******************************************************************************
  @file    qcril_arb.h
  @brief   qcril qmi - compatibility layer for Fusion

  DESCRIPTION

******************************************************************************/


#ifndef QCRIL_ARB_H
#define QCRIL_ARB_H

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/

#include "comdef.h"
#include "qcrili.h"
#include "qcril_otheri.h"
#include "qmi_wds_srvc.h"
#include "wireless_data_service_v01.h"
#include "data_system_determination_v01.h"

#include <QtiMutex.h>
#include "modules/nas/qcril_qmi_nas.h"

/*===========================================================================

                        DEFINITIONS AND TYPES

===========================================================================*/

#define QCRIL_ARB_MAX_MODEMS             qcril_arb_query_max_num_of_modems()

#define QCRIL_ARB_MAX_SLOTS              qcril_arb_query_max_num_of_slots()

#define QCRIL_ARB_MAX_INSTANCES          qcril_arb_query_max_num_of_instances()

/*! @brief Modem Architecture Indicator
*/
typedef enum
{
  QCRIL_ARB_MA_MULTIMODE      = 0, /* Multimode */
  QCRIL_ARB_MA_FUSION_QCS     = 1, /* Fusion (Qualcomm) */
  QCRIL_ARB_MA_FUSION_TPS     = 2, /* Fusion (Third party) */
  QCRIL_ARB_MA_DSDS           = 3, /* DSDS */
  QCRIL_ARB_MA_MAX            = 4
} qcril_arb_ma_e_type;

/*! @brief Preferred Data Technology
*/
typedef enum
{
  QCRIL_ARB_PREF_DATA_TECH_INVALID = -1,
  QCRIL_ARB_PREF_DATA_TECH_UNKNOWN = 0,
  QCRIL_ARB_PREF_DATA_TECH_FIRST   = QCRIL_ARB_PREF_DATA_TECH_UNKNOWN,
  QCRIL_ARB_PREF_DATA_TECH_CDMA    = 1,
  QCRIL_ARB_PREF_DATA_TECH_EVDO    = 2,
  QCRIL_ARB_PREF_DATA_TECH_GSM     = 3,
  QCRIL_ARB_PREF_DATA_TECH_UMTS    = 4,
  QCRIL_ARB_PREF_DATA_TECH_EHRPD   = 5,
  QCRIL_ARB_PREF_DATA_TECH_LTE     = 6,
  QCRIL_ARB_PREF_DATA_TECH_TDSCDMA = 7,
  QCRIL_ARB_PREF_DATA_TECH_5G      = 8,
  QCRIL_ARB_PREF_DATA_TECH_MAX
} qcril_arb_pref_data_tech_e_type;

/*! @brief Cache Type
*/
typedef enum
{
  QCRIL_ARB_CACHE_STATE = 0,
  QCRIL_ARB_CACHE_CM    = 1,
  QCRIL_ARB_CACHE_SMS   = 2,
  QCRIL_ARB_CACHE_PBM   = 3,
  QCRIL_ARB_CACHE_OTHER = 4
} qcril_arb_cache_e_type;

/*! @brief Phone Service Category
*/
typedef enum
{
  QCRIL_ARB_PH_SRV_CAT_3GPP2, /* Phone 3GPP2 Service */
  QCRIL_ARB_PH_SRV_CAT_3GPP,  /* Phone 3GPP Service */
  QCRIL_ARB_PH_SRV_CAT_COMMON /* Phone common Service */
} qcril_arb_ph_srv_cat_e_type;

/*! @brief SMS Service Category
*/
typedef enum
{
  QCRIL_ARB_SMS_SRV_CAT_3GPP2,  /* SMS 3GPP2 SMS Service */
  QCRIL_ARB_SMS_SRV_CAT_3GPP,   /* SMS 3GPP Service */
  QCRIL_ARB_SMS_SRV_CAT_COMMON, /* SMS Common Service */
  QCRIL_ARB_SMS_SRV_CAT_IMS,    /* SMS IMS Service */
  QCRIL_ARB_SMS_SRV_CAT_IMS_REG /* SMS IMS Registration Service */
} qcril_arb_sms_srv_cat_e_type;

/*! @brief NV Service Category
*/
typedef enum
{
  QCRIL_ARB_NV_SRV_CAT_3GPP2, /* 3GPP2 NV item */
  QCRIL_ARB_NV_SRV_CAT_3GPP,  /* 3GPP NV item */
  QCRIL_ARB_NV_SRV_CAT_COMMON /* NV item commonly used by all tech */
} qcril_arb_nv_srv_cat_e_type;

/*! @brief Structure used to cache QCRIL instance state
*/
typedef struct
{

  qcril_modem_state_e_type modem_state;       /*!< Modem State */
  qcril_sim_state_e_type pri_gw_sim_state;    /*!< Primary GSM/WCDMA SIM State */
  qcril_sim_state_e_type pri_cdma_sim_state;  /*!< Primary CDMA SIM State */
  qcril_sim_state_e_type sec_gw_sim_state;    /*!< Secondary GSM/WCDMA SIM State */
  qcril_sim_state_e_type sec_cdma_sim_state;  /*!< Secondary CDMA SIM State */
  qcril_sim_state_e_type ter_gw_sim_state;    /*!< Tertiary GSM/WCDMA SIM State */
  qcril_sim_state_e_type ter_cdma_sim_state;  /*!< Tertiary CDMA SIM State */
  qcril_radio_tech_e_type voice_radio_tech;   /*!< Indicates the voice radio technology that modem camped on */
} qcril_arb_state_info_struct_type;

typedef struct
{
  qtimutex::QtiSharedMutex mutex; /* Mutex used to control simultaneous update/access to state info */
  qcril_arb_state_info_struct_type info[ QCRIL_MAX_INSTANCE_ID ];
} qcril_arb_state_struct_type;

typedef struct
{
    qmi_wds_data_network_type       network_type;
    qmi_wds_db_rat_mask             rat_mask;
    qmi_wds_db_so_mask              db_so_mask;
} qcril_arb_data_sys_status_info_type;

typedef struct
{
    dsd_sys_network_enum_v01        technology;
    dsd_sys_rat_ex_enum_v01         rat_value;
    dsd_sys_so_mask_v01             so_mask;
} qcril_arb_dsd_sys_status_info_type;

typedef struct
{
    int                                 is_current;
    int                                 is_dsd;
    qcril_arb_data_sys_status_info_type data_sys_status_info;
    qcril_arb_dsd_sys_status_info_type  dsd_sys_status_info;
    qcril_arb_pref_data_tech_e_type     pref_data_tech;
    qcril_arb_pref_data_tech_e_type     five_g_data_tech;
    int                                 five_g_is_mmW;
    int                                 radio_technology;
    int                                 is_extrapolation;
} qcril_arb_pref_data_type;

typedef struct
{
    int                             snapshot_radio_technology;
} qcril_arb_pref_data_snapshot_type;

/*===========================================================================

                    EXTERNAL FUNCTION PROTOTYPES

===========================================================================*/

void qcril_arb_init( void );
void *qcril_arb_allocate_cache( qcril_arb_cache_e_type cache_type );
uint8 qcril_arb_query_max_num_of_modems( void );
int qcril_arb_query_max_num_of_instances( void );

uint8 qcril_arb_query_max_num_of_slots( void );

void qcril_arb_query_arch_modem_id( qcril_modem_id_e_type *cdma_modem_id, qcril_modem_id_e_type *evdo_modem_id,
                                    qcril_modem_id_e_type *gwl_modem_id );

void qcril_arb_query_voice_tech_modem_id( qcril_instance_id_e_type instance_id, qcril_modem_id_e_type *cdma_modem_id,
                                          qcril_modem_id_e_type *gw_modem_id );

void qcril_arb_set_dsd_sys_status(const dsd_system_status_ind_msg_v01 *const dsd_system_status);

void qcril_arb_set_data_sys_status( /*qcril_instance_id_e_type     instance_id,*/
                                    const wds_data_system_status_type_v01 *const data_sys_status );

void qcril_arb_set_pref_data_tech( /*qcril_instance_id_e_type instance_id,*/ qcril_arb_pref_data_tech_e_type pref_data_tech );

IxErrnoType qcril_arb_query_ph_srv_modem_id( qcril_arb_ph_srv_cat_e_type ph_srv_cat, qcril_instance_id_e_type instance_id,
                                             qcril_modem_ids_list_type *modem_ids_list_ptr );

IxErrnoType qcril_arb_query_sms_srv_modem_id( qcril_arb_sms_srv_cat_e_type sms_srv_cat, qcril_instance_id_e_type instance_id,
                                              qcril_modem_ids_list_type *modem_ids_list_ptr );

IxErrnoType qcril_arb_query_auth_srv_modem_id( qcril_instance_id_e_type instance_id, qcril_modem_id_e_type *modem_id_ptr );

IxErrnoType qcril_arb_query_nv_srv_modem_id( qcril_arb_nv_srv_cat_e_type nv_srv_cat, qcril_instance_id_e_type instance_id,
                                             qcril_modem_ids_list_type *modem_ids_list_ptr );

void qcril_arb_query_data_tech_modem_id(qcril_instance_id_e_type instance_id, qcril_modem_id_e_type *cdma_modem_id,
	qcril_modem_id_e_type *evdo_modem_id, qcril_modem_id_e_type *gwl_modem_id,
	qcril_modem_id_e_type *pref_data_tech_modem_id, qcril_arb_pref_data_tech_e_type *pref_data_tech);

boolean  qcril_arb_cdma_subscription_is_nv( qcril_instance_id_e_type instance_id, qcril_modem_id_e_type modem_id );

boolean qcril_arb_ma_is_fusion( void  );

boolean qcril_arb_ma_is_dsds( void  );

boolean qcril_arb_in_dsds_ssmm( void  );

boolean qcril_arb_jpn_band_is_supported( qcril_instance_id_e_type instance_id, qcril_modem_id_e_type modem_id );

boolean qcril_arb_in_airplane_mode( qcril_instance_id_e_type instance_id, qcril_modem_id_e_type modem_id );

boolean qcril_arb_in_emerg_cb_mode ( qcril_instance_id_e_type instance_id );

void qcril_qmi_get_pref_data_tech(qcril_arb_pref_data_type *pref_data);

void qcril_qmi_arb_reset_pref_data_snapshot();

uint8_t qcril_arb_check_wlan_rat_dsd_reported(uint32_t *index);
uint8_t qcril_arb_check_lte_rat_dsd_reported();
uint8_t qcril_arb_check_wlan_rat_dsd_reported_helper(uint32_t *index);
uint8_t qcril_arb_decide_data_rat_to_report(uint32_t *index);
uint8_t qcril_arb_find_index_rat_not_wlan_dsd_reported_helper(uint32_t *index);
void qcril_qmi_arb_reset_dsd_system_status_info();

bool qcril_qmi_is_5g_data_connected();
five_g_bearer_status qcril_qmi_query_bearer_status(void);

#endif /* QCRIL_ARB_H */
