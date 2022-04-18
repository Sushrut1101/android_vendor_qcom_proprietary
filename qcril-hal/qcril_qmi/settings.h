/******************************************************************************
#  Copyright (c) 2016-2017 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#******************************************************************************/
#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include "qcrili.h"
#include "modules/nas/qcril_qmi_nas.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#define QCRIL_UIM_ICCID_LEN                     10

#ifdef QMI_RIL_UTF
#define STUBBED_DECL(decl, impl) \
    static inline decl impl
#else
#define STUBBED_DECL(decl, impl) \
    decl;
#endif

STUBBED_DECL(void settingsd_client_start(void) , {})

STUBBED_DECL(void settingsd_client_update_iccid_card
(
    qcril_instance_id_e_type instance_id,
    char (*mcc)[QCRIL_MCC_MNC_MAX_SIZE],
    char (*mnc)[QCRIL_MCC_MNC_MAX_SIZE],
    char (*iccid)[QCRIL_UIM_ICCID_LEN]
) , {} )


#endif
#ifdef __cplusplus
}
#endif  /* __cplusplus */

