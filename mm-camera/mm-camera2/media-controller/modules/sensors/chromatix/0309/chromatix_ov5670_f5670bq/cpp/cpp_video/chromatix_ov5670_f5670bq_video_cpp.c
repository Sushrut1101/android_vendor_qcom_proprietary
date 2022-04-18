/*========================================================================
Copyright (c) 2016 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
==========================================================================*/

/*============================================================================
 *                      INCLUDE FILES
 *===========================================================================*/
#include "chromatix_cpp.h"

static chromatix_cpp_type chromatix_ov5670_f5670bq_parms = {
#include "chromatix_ov5670_f5670bq_video_cpp.h"
};

/*============================================================================
 * FUNCTION    - load_chromatix -
 *
 * DESCRIPTION:
 *==========================================================================*/
void *load_chromatix(void)
{
  return &chromatix_ov5670_f5670bq_parms;
}
