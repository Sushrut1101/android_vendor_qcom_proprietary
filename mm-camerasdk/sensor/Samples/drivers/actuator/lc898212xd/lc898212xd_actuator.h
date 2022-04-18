/**
 * lc898212xd_actuator.h
 *
 * Copyright (c) 2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
  {
    .actuator_params =
    {
      .module_name = "onsemi",
      .actuator_name = "lc898212xd",
      .i2c_addr = 0xE4,
      .i2c_freq_mode = SENSOR_I2C_MODE_FAST,
      .i2c_data_type = CAMERA_I2C_WORD_DATA,
      .i2c_addr_type = CAMERA_I2C_BYTE_ADDR,
      .act_type = ACTUATOR_TYPE_BIVCM,
      .data_size = 12,
      .reg_tbl =
      {
        .reg_tbl_size = 3,
        .reg_params =
        {
          {
            .reg_write_type = ACTUATOR_WRITE_DIR_REG,
            .reg_addr = 0x16,
            .data_type = CAMERA_I2C_WORD_DATA,
            .addr_type = CAMERA_I2C_BYTE_ADDR,
          },
          {
            .reg_write_type = ACTUATOR_WRITE_DAC,
            .hw_mask = 0x0000,
            .reg_addr = 0xA1,
            .hw_shift = 0,
            .data_shift = 4,
          },
          {
            .reg_write_type = ACTUATOR_WRITE,
            .reg_addr = 0x8A,
            .data_type = CAMERA_I2C_BYTE_DATA,
            .addr_type = CAMERA_I2C_BYTE_ADDR,
            .reg_data = 0xD,
          },
        },
      },
      .init_setting_size = 55,
      .init_settings =
      {
        /* Settings acording to: */
        /* 101414A-LC898212-TVC820-Initialize and Filter Setting.txt */
        /* TDK_CL-ACT_ 212_SPtype_Ini_130114.txt + ST820_140911-1.h */
        /* CLKSEL 1/1, CLKON */
        { 0x80, CAMERA_I2C_BYTE_ADDR,
          0x34, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /*  AD 4Time */
        { 0x81, CAMERA_I2C_BYTE_ADDR,
          0x20, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* STBY   AD ON,DA ON,OP ON */
        { 0x84, CAMERA_I2C_BYTE_ADDR,
          0xE0, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* PIDSW OFF,AF ON,MS2 ON */
        { 0x87, CAMERA_I2C_BYTE_ADDR,
          0x05, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* Internal OSC Setup (No01=24.18MHz) */
        { 0xA4, CAMERA_I2C_BYTE_ADDR,
          0x24, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* OFFSET Clear */
        { 0x3A, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* RZ Clear(Target Value) */
        { 0x04, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* PIDZO Clear */
        { 0x02, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* MS1Z22 Clear(STMV Target Value) */
        { 0x18, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },

        /* Filter Setting: ST820_140911-1 */
        { 0x40, CAMERA_I2C_BYTE_ADDR,
          0x4030, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x42, CAMERA_I2C_BYTE_ADDR,
          0x7150, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x44, CAMERA_I2C_BYTE_ADDR,
          0x8F90, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x46, CAMERA_I2C_BYTE_ADDR,
          0x61B0, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x48, CAMERA_I2C_BYTE_ADDR,
          0x7FF0, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x4A, CAMERA_I2C_BYTE_ADDR,
          0x3930, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x4C, CAMERA_I2C_BYTE_ADDR,
          0x4030, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x4E, CAMERA_I2C_BYTE_ADDR,
          0x8010, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x50, CAMERA_I2C_BYTE_ADDR,
          0x04F0, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x52, CAMERA_I2C_BYTE_ADDR,
          0x7610, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x54, CAMERA_I2C_BYTE_ADDR,
          0x2030, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x56, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x58, CAMERA_I2C_BYTE_ADDR,
          0x7FF0, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x5A, CAMERA_I2C_BYTE_ADDR,
          0x0800, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x5C, CAMERA_I2C_BYTE_ADDR,
          0x72F0, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x5E, CAMERA_I2C_BYTE_ADDR,
          0x7F70, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x60, CAMERA_I2C_BYTE_ADDR,
          0x7ED0, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x62, CAMERA_I2C_BYTE_ADDR,
          0x7FF0, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x64, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x66, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x68, CAMERA_I2C_BYTE_ADDR,
          0x5130, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x6A, CAMERA_I2C_BYTE_ADDR,
          0x72F0, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x6C, CAMERA_I2C_BYTE_ADDR,
          0x8010, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x6E, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x70, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x72, CAMERA_I2C_BYTE_ADDR,
          0x18E0, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x74, CAMERA_I2C_BYTE_ADDR,
          0x4E30, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x30, CAMERA_I2C_BYTE_ADDR,
          0x0000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x76, CAMERA_I2C_BYTE_ADDR,
          0x0C50, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x78, CAMERA_I2C_BYTE_ADDR,
          0x4000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },

        /* DSSEL 1/16 INTON */
        { 0x86, CAMERA_I2C_BYTE_ADDR,
          0x60, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* ANA1   Hall Bias:2mA Amp Gain: x100(Spring Type) */
        { 0x88, CAMERA_I2C_BYTE_ADDR,
          0x70, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* Hall Offset/Bias */
        { 0x28, CAMERA_I2C_BYTE_ADDR,
          0x8020, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* Loop Gain */
        { 0x4C, CAMERA_I2C_BYTE_ADDR,
          0x4000, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* RZ OFF,STSW=ms2x2,MS1IN OFF,MS2IN=RZ,FFIN AFTER,DSW ag */
        { 0x83, CAMERA_I2C_BYTE_ADDR,
          0xAC, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* AF filter,MS1 Clr */
        { 0x85, CAMERA_I2C_BYTE_ADDR,
          0xC0, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },

        /*  Repeat to read the register "0085" until the value turns 0x00 */
        { 0x85, CAMERA_I2C_BYTE_ADDR,
          0x00, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_POLL, 1 },

        /* Exit from Stand-By */
        /* STBY   AD ON,DA ON,OP ON,DRMODE H,LNSTBB H */
        { 0x84, CAMERA_I2C_BYTE_ADDR,
          0xE3, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* DRVSEL */
        { 0x97, CAMERA_I2C_BYTE_ADDR,
          0x00, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* LNFC   1.5MHz 12bit */
        { 0x98, CAMERA_I2C_BYTE_ADDR,
          0x42, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* LNSMTH Smoothing Set */
        { 0x99, CAMERA_I2C_BYTE_ADDR,
          0x00, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        /* LNSAMP */
        { 0x9A, CAMERA_I2C_BYTE_ADDR,
          0x00, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },

        { 0x93, CAMERA_I2C_BYTE_ADDR,
          0x40, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0x7c, CAMERA_I2C_BYTE_ADDR,
          0x180, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
        { 0xA0, CAMERA_I2C_BYTE_ADDR,
          0x02, CAMERA_I2C_WORD_DATA, ACTUATOR_I2C_OP_WRITE, 0 },

        /* Servo On */
        /* PIDSW ON,AF ON,MS2 ON */
        { 0x87, CAMERA_I2C_BYTE_ADDR,
          0x85, CAMERA_I2C_BYTE_DATA, ACTUATOR_I2C_OP_WRITE, 0 },
      },
    }, /* actuator_params */

    .actuator_tuned_params =
    {
      .scenario_size =
      {
        1, /* MOVE_NEAR */
        1, /* MOVE_FAR */
      },
      .ringing_scenario =
      {
        /* MOVE_NEAR */
        {
          336,
        },
        /* MOVE_FAR */
        {
          336,
        },
      },
      .initial_code = 1451,	//0xEFF,
      .region_size = 1,
      .region_params =
      {
        {
          .step_bound =
          {
            336, /* Macro step boundary*/
            0, /* Infinity step boundary*/
          },
          .code_per_step = 4,
          .qvalue = 128,
        },
      },
      /* damping used as direction value */
      .damping =
      {
        /* damping[MOVE_NEAR] */
        {
          /* Scenario 0 */
          {
            .ringing_params =
            {
              /* Region 0 */
              {
                .damping_step = 0xFFF,
                .damping_delay = 1000,
                .hw_params = 0x0000180,
              },
            },
          },
        },
        /* damping[MOVE_FAR] */
        {
          /* Scenario 0 */
          {
            .ringing_params =
            {
              /* Region 0 */
              {
                .damping_step = 0xFFF,
                .damping_delay = 1000,
                .hw_params = 0x0000FE80,
              },
            },
          },
        },
      },
    }, /* actuator_tuned_params */
  },
