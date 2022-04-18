/*
* Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
* All Rights Reserved.
* Confidential and Proprietary - Qualcomm Technologies, Inc.
*/

/* std headers */
#include <unistd.h>
#include <math.h>
#ifdef __ANDROID__
#include <cutils/properties.h>
#endif
/* mctl headers */
#include "modules.h"

/* isp headers */
#include "isp_sub_module_log.h"
#include "isp_sub_module_util.h"
#include "ltm47.h"
#include "chromatix.h"
#include "chromatix_3a.h"
#include "isp_pipeline_reg.h"

extern uint32_t weight_default_1x1kernel[];
extern uint32_t weight_default_3x3kernel[];
extern uint16_t weight_new_3x3kernel[];
extern uint16_t weight_new_1x1kernel[];


/* define PRINT_REG_VAL_SET */
#define LTM_CURVE_DEBUG 0
#undef ISP_DBG
#define ISP_DBG(fmt, args...) \
  ISP_DBG_MOD(ISP_LOG_LTM, fmt, ##args)
#undef ISP_HIGH
#define ISP_HIGH(fmt, args...) \
  ISP_HIGH_MOD(ISP_LOG_LTM, fmt, ##args)


/** ltm47_interpolate_curve:
 *
 *  @chromatix_ltm: Normal Ltm structure from chromatix
 *  @chromatix_ltm: backlit Ltm structure from chromatix
 *  @mod: ltm module data
 *  @backlit_enable: backlit check
 *
 *  Interpolate saturation region over tr_index and tr_index +1
 *
 * Return TRUE on success and FALSE on failure
 **/
boolean ltm47_interpolate_curve(isp_sub_module_t *isp_sub_module,
  chromatix_LTM_type* chromatix_ltm_normal,
  chromatix_LTM_type* chromatix_ltm_backlit, ltm47_t *mod, int backlit_enable)
{
  int i = 0;
  RETURN_IF_NULL(isp_sub_module);
  RETURN_IF_NULL(mod);
  RETURN_IF_NULL(chromatix_ltm_normal);
  float normal_ratio = 0.0;
  LTM_light_type normal_trigger_idx;
  float backlit_ratio = 0.0;
  LTM_light_type backlit_trigger_idx;

  if (backlit_enable)
    RETURN_IF_NULL(chromatix_ltm_backlit);

  backlit_ratio = mod->backlit_idx.ratio;
  backlit_trigger_idx = mod->backlit_idx.tr_index;
  normal_ratio = mod->normal_idx.ratio;
  normal_trigger_idx = mod->normal_idx.tr_index;

  if (backlit_enable) {
    if (backlit_trigger_idx + 1 >= LTM_MAX_LIGHT) {
      ISP_DBG("No interpolation, backlit_trigger_idx = %d",
        backlit_trigger_idx);
    for (i = 0; i < LTM_HW_LUT_SIZE + 1; i++)
      mod->unpacked_sat_curve[i] = LTM_CORE_TYPE
        (chromatix_ltm_backlit, sat_curve[i], backlit_trigger_idx);
    return TRUE;
    }
  } else {
    if (normal_trigger_idx + 1 >= LTM_MAX_LIGHT) {
      ISP_DBG("No interpolation, normal_trigger_idx = %d",
        normal_trigger_idx);
    for (i = 0; i < LTM_HW_LUT_SIZE + 1; i++)
      mod->unpacked_sat_curve[i] = LTM_CORE_TYPE
        (chromatix_ltm_normal, sat_curve[i], normal_trigger_idx);
    return TRUE;
    }
  }

  for (i = 0; i < LTM_HW_LUT_SIZE + 1; i++) {
    if (backlit_enable) {
      mod->unpacked_sat_curve[i] = (int)Round((float)LINEAR_INTERPOLATION_LTM(
        (float)LTM_CORE_TYPE(chromatix_ltm_backlit, sat_curve[i],
          backlit_trigger_idx),
        (float)LTM_CORE_TYPE(chromatix_ltm_backlit, sat_curve[i],
          backlit_trigger_idx + 1),
        backlit_ratio));
    } else {
      mod->unpacked_sat_curve[i] = (int)Round((float)LINEAR_INTERPOLATION_LTM(
        (float)LTM_CORE_TYPE(chromatix_ltm_normal, sat_curve[i],
          normal_trigger_idx),
        (float)LTM_CORE_TYPE(chromatix_ltm_normal, sat_curve[i],
          normal_trigger_idx + 1),
        normal_ratio));
    }
  }

  return TRUE;
}

/** ltm47_pack_extra_tables:
 *
 *  @chromatix_ltm: normal Ltm structure from chromatix
 *  @chromatix_ltm: backlit Ltm structure from chromatix
 *  @mod: ltm module data
 *
 *
 * Return TRUE on success and FALSE on failure
 **/
boolean ltm47_pack_extra_tables(chromatix_LTM_type*
  chromatix_ltm_normal __unused,
  chromatix_LTM_type* chromatix_ltm_backlit __unused,
  ltm47_t *dest __unused)
{

  return TRUE;
}

/** load_default_tables
 *
 *  load default tables for curves
 */
boolean load_default_tables(isp_sub_module_t *isp_sub_module,
  void *data)
{
  ASD_VFE_struct_type     *ASD_algo_data = NULL;
  ltm47_t                 *mod = NULL;
  chromatix_LTM_type      *chromatix_LTM_normal = NULL;
  chromatix_LTM_type      *chromatix_LTM_backlit = NULL;
  chromatix_LTM_type      *ltm = NULL;
  isp_ltm_reg_t           *reg = NULL;
  int                      i = 0, idx = LTM_NORMAL_LIGHT;
  chromatix_parms_type    *chromatix = NULL;
  chromatix_3a_parms_type *chromatix_3a_ptr = NULL;
  AAA_ASD_struct_type     *ASD_3a_data = NULL;
  float                    max_percent_threshold;
  uint16_t                 wt[54];
  float                    fSigmaXY, fSigmaXY_2;

  RETURN_IF_NULL(data);
  RETURN_IF_NULL(isp_sub_module);
  mod = (ltm47_t *)data;
  reg = &(mod->reg);

  chromatix = (chromatix_parms_type *)
  isp_sub_module->chromatix_ptrs.chromatixPtr;
  RETURN_IF_NULL(chromatix);
  chromatix_3a_ptr = (chromatix_3a_parms_type *)
    isp_sub_module->chromatix_ptrs.chromatix3APtr;
  RETURN_IF_NULL(chromatix_3a_ptr);
  ASD_3a_data = &(chromatix_3a_ptr->ASD_3A_algo_data);
  max_percent_threshold =
    ASD_3a_data->backlit_scene_detect.max_percent_threshold;
  mod->bsd_ratio = 1.0f - max_percent_threshold;

  ASD_algo_data = &(chromatix->ASD_algo_data);
  if(ASD_algo_data->backlit_scene_detect.backlit_LTM.enable) {
    chromatix_LTM_backlit = &(ASD_algo_data->backlit_scene_detect.backlit_LTM);
  }
  if (chromatix->chromatix_post_processing.chromatix_LTM_data.enable) {
    chromatix_LTM_normal =
      &(chromatix->chromatix_post_processing.chromatix_LTM_data);
  }
  if (chromatix_LTM_backlit) {
    if (chromatix_LTM_normal) {
      /*Both Chromatix Normal and Backlit are enabled. Interpolate the curves */
      for (i = 0; i < LTM_HW_LUT_SIZE + 1; i++) {
        mod->unpacked_master_scale[i] = Round((float)
          LINEAR_INTERPOLATION_LTM(
          (float)chromatix_LTM_normal->reservedData.master_scale[i],
          (float)chromatix_LTM_backlit->reservedData.master_scale[i],
          mod->bsd_ratio));
        mod->unpacked_shift_scale[i] =
          LINEAR_INTERPOLATION_LTM(
          (float)chromatix_LTM_normal->reservedData.shift_scale[i],
          (float)chromatix_LTM_backlit->reservedData.shift_scale[i],
          mod->bsd_ratio);
      }
    } else {
      /* Only Chromatix Backlit Ltm is enabled */
      memcpy(mod->unpacked_master_scale,
        chromatix_LTM_backlit->reservedData.master_scale,
        sizeof(mod->unpacked_master_scale));
      memcpy(mod->unpacked_shift_scale,
        chromatix_LTM_backlit->reservedData.shift_scale,
        sizeof(mod->unpacked_shift_scale));
    }
  } else if (chromatix_LTM_normal) {
      /* Only Chromatix Normal Ltm is enabled */
      memcpy(mod->unpacked_master_scale,
        chromatix_LTM_normal->reservedData.master_scale,
        sizeof(mod->unpacked_master_scale));
      memcpy(mod->unpacked_shift_scale,
        chromatix_LTM_normal->reservedData.shift_scale,
        sizeof(mod->unpacked_shift_scale));
  } else {
    ISP_ERR("Error: Chromatix ltm normal and backlit both are not enabled");
    return FALSE;
  }
  if (!chromatix_LTM_backlit) {
    ltm = &(chromatix->chromatix_post_processing.chromatix_LTM_data);
  } else {
    ltm = &(ASD_algo_data->backlit_scene_detect.backlit_LTM);
  }

  memcpy(mod->unpacked_sat_curve, ltm->chromatix_ltm_core_data[idx].sat_curve,
         sizeof(mod->unpacked_sat_curve));
  memcpy(mod->unpacked_master_curve, ltm->reservedData.master_curve,
         sizeof(mod->unpacked_master_curve));

  /* write tables to dmi */
  pack_tbl_to_lut_i32(ltm->reservedData.mask_rect,
    mod->hw_mask_curve, 1.0f);
  pack_tbl_to_lut_i32(ltm->reservedData.master_curve,
    mod->hw_master_curve, 1.0f);
  pack_tbl_to_lut_i32(ltm->reservedData.master_scale,
    mod->hw_master_scale, 1.0f);
  pack_tbl_to_lut_i32(ltm->reservedData.shift_curve,
    mod->hw_shift_curve, 1.0f);
  pack_tbl_to_lut_i32(ltm->reservedData.shift_scale,
    mod->hw_shift_scale, 1.0f);

  pack_tbl_to_lut_i32(LTM_CORE_TYPE(ltm, sat_curve, idx),
    mod->hw_sat_curve, 1.0f);

  if(ltm->reservedData.wt_3x3 == WT_1x1_FROMHEADER ||
     ltm->reservedData.wt_3x3 == WT_3x3_FROMHEADER) {
    memset(mod->weight_curve, 0, sizeof(mod->weight_curve));
    mod->weight_curve[ 0] = MIN(ltm->reservedData.nLowTrig0,
      LTM_WEIGHT_CURVE_MAX);
    mod->weight_curve[ 9] = MIN(ltm->reservedData.nLowTrig1,
      LTM_WEIGHT_CURVE_MAX);
    mod->weight_curve[18] = MIN(ltm->reservedData.nLowTrig2,
      LTM_WEIGHT_CURVE_MAX);
    mod->weight_curve[27] = MIN(ltm->reservedData.nLowTrig3,
      LTM_WEIGHT_CURVE_MAX);
    mod->weight_curve[36] = MIN(ltm->reservedData.nHighTrig0,
      LTM_WEIGHT_CURVE_MAX);
    mod->weight_curve[45] = MIN(ltm->reservedData.nHighTrig1,
      LTM_WEIGHT_CURVE_MAX);

    fSigmaXY = CLAMP_LTM(ltm->reservedData.fSigmaXY, 0.01, 1.0);
    fSigmaXY_2 = fSigmaXY * 0.85;

    /* 3x3 from cfg */
    if (ltm->reservedData.wt_3x3 == WT_3x3_FROMHEADER) {
        for (i = 0; i < 6; i++) {
            mod->weight_curve[(i * 9) +1] =
              mod->weight_curve[(i * 9) +3] =
              mod->weight_curve[i * 9] * fSigmaXY;

            mod->weight_curve[(i *9) + 4] =
              mod->weight_curve[i * 9] * fSigmaXY_2;
        }
    }
    pack_w_tbl_to_lut(mod->weight_curve, mod->hw_weight);

    /* updated 3x3 */
  } else if ( ltm->reservedData.wt_3x3 == WT_3x3_NEWDEFAULT ) {
    memcpy(mod->weight_curve, weight_new_3x3kernel, 54 * sizeof(uint16_t));
    pack_w_tbl_to_lut(mod->weight_curve, mod->hw_weight);
    /*  updated 1x1 */
  } else if ( ltm->reservedData.wt_3x3 == WT_1x1_NEWDEFAULT ) {
    memcpy(mod->weight_curve, weight_new_1x1kernel, 54 * sizeof(uint16_t));
    pack_w_tbl_to_lut(mod->weight_curve, mod->hw_weight);
  } else if (mod->isp_out_info.is_split) {
    memcpy(mod->hw_weight, weight_default_1x1kernel, (LTM_HW_W_LUT_SIZE * 4));
  } else {
    memcpy(mod->hw_weight, weight_default_3x3kernel, (LTM_HW_W_LUT_SIZE * 4));
  }

  ltm47_setup_dark_bright_region_index(mod, mod->unpacked_master_scale);
  return TRUE;
}

