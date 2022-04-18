
/*============================================================================

Copyright (c) 2018 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

============================================================================*/

/*============================================================================
 *                      INCLUDE FILES
 *===========================================================================*/
#include "chromatix.h"

static chromatix_parms_type chromatix_s5k5e9yu05_mono_parms = {
#include "chromatix_s5k5e9yu05_mono_preview_isp.h"
};

/*============================================================================
 * FUNCTION    - load_chromatix -
 *
 * DESCRIPTION:
 *==========================================================================*/
void *load_chromatix(void)
{
  return &chromatix_s5k5e9yu05_mono_parms;
}
