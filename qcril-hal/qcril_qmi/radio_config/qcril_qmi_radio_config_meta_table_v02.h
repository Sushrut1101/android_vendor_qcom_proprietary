/******************************************************************************
#  Copyright (c) 2015-2017 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#******************************************************************************/
/******************************************************************************
  @file    qcril_qmi_radio_config_meta_table_v02.h

  DESCRIPTION
    Handles imss related radio config req and response handlers

******************************************************************************/

#ifndef QCRIL_QMI_CONFIG_META_TABLE_V02_H
#define QCRIL_QMI_CONFIG_META_TABLE_V02_H

#include <vector>

size_t get_length_meta_table_v02();
const std::vector<qcril_qmi_radio_config_meta_type> *get_meta_table_v02();

#endif
