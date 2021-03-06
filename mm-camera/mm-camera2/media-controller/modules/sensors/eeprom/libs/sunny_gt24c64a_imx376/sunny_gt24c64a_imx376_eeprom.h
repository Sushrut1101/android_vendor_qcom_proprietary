/*============================================================================

Copyright (c) 2017 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

============================================================================*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../eeprom_util/eeprom.h"
#include "eeprom_lib.h"
#include "eeprom_util.h"
#include "debug_lib.h"
#include "sensor_lib.h"
#include <utils/Log.h>

#undef SLOW
#undef SDBG
#define SUNNY_GT24C64A_IMX376_DEBUG
#ifdef SUNNY_GT24C64A_IMX376_DEBUG
#define SLOW(fmt, args...) ALOGE("%s:%d," fmt "\n",__func__,__LINE__, ##args)
#define SDBG(fmt, args...) SERR(fmt, ##args)
#else
#define SLOW(fmt, args...) do { } while (0)
#define SDBG(fmt, args...) do { } while (0)

#endif

#define BASE_ADDR      0x0
#define AF_FLAG_ADDR   0x11
#define AWB_FLAG_ADDR  0x1B
#define LSC_FLAG_ADDR  0x29

#define MODULE_INFO_OFFSET      BASE_ADDR

#define AWB_OFFSET              (AWB_FLAG_ADDR - BASE_ADDR)

#define LSC_OFFSET              (LSC_FLAG_ADDR - BASE_ADDR)
#define LSC_GRID_SIZE   221 //17 x 13

#define AF_OFFSET               (AF_FLAG_ADDR - BASE_ADDR)

#define VALID_FLAG         0x01
#define QVALUE             1024.0
#define INVALID_DATA       0xFFFF

typedef struct {
  unsigned char vendor_id; /*0x01: sunny*/
  unsigned char year;
  unsigned char month;
  unsigned char day;
} module_info_t;

typedef struct {
  unsigned char r_avg_l;
  unsigned char r_avg_h;
  unsigned char gr_avg_l;
  unsigned char gr_avg_h;
  unsigned char gb_avg_l;
  unsigned char gb_avg_h;
  unsigned char b_avg_l;
  unsigned char b_avg_h;
} awb_data_t;

typedef struct {
  unsigned char macro_h;
  unsigned char macro_l;
  unsigned char infinity_h;
  unsigned char infinity_l;
} af_data_t;

static unsigned char awb_present = 0;
static unsigned char af_present  = 0;
static unsigned char lsc_present = 0;

void sunny_gt24c64a_imx376_eeprom_get_calibration_items(void *e_ctrl);
void sunny_gt24c64a_imx376_eeprom_format_calibration_data(void *e_ctrl);

static eeprom_lib_func_t sunny_gt24c64a_imx376_eeprom_lib_func_ptr = {
  .get_calibration_items = sunny_gt24c64a_imx376_eeprom_get_calibration_items,
  .format_calibration_data = sunny_gt24c64a_imx376_eeprom_format_calibration_data,
  .do_af_calibration = eeprom_autofocus_calibration,
  .do_wbc_calibration = eeprom_whitebalance_calibration,
  .do_lsc_calibration = eeprom_lensshading_calibration,
  .get_raw_data = NULL,
  .get_ois_raw_data = NULL,
  .eeprom_info =
  {
    .power_setting_array =
    {
      .power_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VANA,
          .config_val = GPIO_OUT_HIGH,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VANA,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VDIG,
          .config_val = GPIO_OUT_HIGH,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VIO,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 24000000,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_HIGH,
          .delay = 10,
        },
      },
      .size = 8,
      .power_down_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 0,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VIO,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VDIG,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VANA,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VANA,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
      },
      .size_down = 7,
    },
    .i2c_freq_mode = SENSOR_I2C_MODE_FAST,
    .mem_map_array =
    {
      .memory_map =
      {
        {
          .slave_addr = 0xA0,
          .mem_settings =
          {
            { 0x0000, CAMERA_I2C_WORD_ADDR,
              0x0944, CAMERA_I2C_BYTE_DATA, CAMERA_I2C_OP_READ, 1 }
          },
          .memory_map_size = 1,
        },
      },
      .size_map_array = 1,
    },
  },
};
