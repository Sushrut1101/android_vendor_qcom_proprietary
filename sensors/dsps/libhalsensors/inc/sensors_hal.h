/*============================================================================
  @file sensors_hal.h

  @brief
  Common code across the Sensors HAL implementation.

  Copyright (c) 2010-2017,2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
============================================================================*/
#ifndef SENSORS_HAL_H
#define SENSORS_HAL_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
/* ADB logcat */
#define LOG_TAG "qti_sensors_hal"
#define LOG_NDEBUG 0
#define LOG_NDDEBUG 0
#define LOG_NIDEBUG 0
#define LOG_NVDEBUG 0

#include <cutils/log.h>
#include <sensors.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include "log.h"
#include <hardware_legacy/power.h>
#include "sensor1.h"
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================================
                   PREPROCESSOR DEFINTIONS
===========================================================================*/

#ifndef UNREFERENCED_PARAMETER
# define UNREFERENCED_PARAMETER(x) (void)x;
#endif /* UNREFERENCED_PARAMETER */

#undef ARRAY_SIZE
#define ARRAY_SIZE(x) (int)(sizeof(x) / sizeof((x)[0]))

/* timeout in ms used in mutex wait */
#define TIME_OUT_MS 1000

/* timeout in ms used in mutex wait for SMD indication */
#define TIME_OUT_MS_SMD_IND 200

/* timeout in ms used in mutex wait for PMD indication */
#define TIME_OUT_MS_PMD_IND 200

/* timeout in ms used in mutex wait for DPC indication */
#define TIME_OUT_MS_DPC_IND 200

/* timeout in ms used in mutex wait for Location Service Resp */
#define TIME_OUT_MS_LOC_SER 10000

/* max number of sensors */
#define MAX_NUM_SENSORS 100

/* Max sensor name and vendor size */
#define SNS_MAX_SENSOR_NAME_SIZE 80
#define SNS_MAX_VENDOR_NAME_SIZE 80
#define SNS_MAX_PERMISSION_SIZE  80

/* Max supported registry settings reading*/
#define SNS_MAX_REGISTRY_REQUEST_SIZE 8

/* Retrial count for SAM services to ready after subsystem restart */
#define SNS_SAM_SVC_RETRIAL_COUNT 20

/* Unit conversion between sensor1 and android */
#define UNIT_Q16                     (65536.0f)
#define UNIT_CONVERT_Q16             (1.0/65536.0)
#define UNIT_CONVERT_ACCELERATION    UNIT_CONVERT_Q16      /* Android (ms2,
                                                              sensor1 (ms2 in q16) */
#define UNIT_CONVERT_MAGNETIC_FIELD  100*UNIT_CONVERT_Q16  /* Android (uTesla)
                                                              Sensor1 (Gauss in q16) */
#define UNIT_CONVERT_TEMPERATURE     UNIT_CONVERT_Q16      /* Android (deg C),
                                                              Sensor1 (deg C in q16)*/
#define UNIT_CONVERT_LIGHT           UNIT_CONVERT_Q16      /* Android (lux),
                                                              sensor1 (lux in q16) */
#define UNIT_CONVERT_PROXIMITY       100*UNIT_CONVERT_Q16  /* Android (cm),
                                                              sensor1 (meter in q16) */
#define UNIT_CONVERT_GYRO            UNIT_CONVERT_Q16      /* Android(rad/s),
                                                              sensor1(rad/s in q16)*/
#define UNIT_CONVERT_POWER           1/1000                /* android(mA),
                                                              Sensor1(uA in q16)*/
#define UNIT_CONVERT_PRESSURE        UNIT_CONVERT_Q16      /* Android (hPa),
                                                             Sensor1 (hPa in q16)*/
#define UNIT_CONVERT_RELATIVE_HUMIDITY UNIT_CONVERT_Q16    /* Android (percentage humidity),
                                                             Sensor1 (percentage humidity in q16)*/
#define UNIT_CONVERT_COLOR_TEMP      UNIT_CONVERT_Q16      /* Android (kelvin),
                                                              sensor1 (kelvin in q16) */
#define UNIT_CONVERT_UV              UNIT_CONVERT_Q16      /* Android (mW/cm2),
                                                              Sensor1 (mW/cm2 in q16)*/

#define RAD2DEG 180.0f/M_PI
#define MIN_FLT_TO_AVOID_SINGULARITY 0.0001f

#define RAD_Q16_TO_DEG_FLT  (UNIT_CONVERT_Q16 * RAD2DEG)

#define INVALID_INSTANCE_ID   0xFF

/* Timing related macros */
#define NSEC_PER_SEC       1000000000LL
#define USEC_PER_SEC       1000000LL
#define USEC_TO_MSEC(usec) ((usec)/1000L)
#define USEC_TO_NSEC(usec) ((usec)*1000L)
#define NSEC_TO_MSEC(nsec) ((nsec)/1000000LL)
#define NSEC_TO_SEC(nsec)  ((nsec)/1000000000LL)
#define HZ_TO_SEC(hz)      (1LL/(hz))
#define HZ_TO_MSEC(hz)     (1000LL/(hz))
#define HZ_TO_USEC(hz)     (1000000LL/(hz))
#define HZ_TO_NSEC(hz)     (1000000000LL/(hz))
#define MSEC_TO_HZ(ms)     (1000.0/(ms))
#define NSEC_TO_HZ(ns)     (1000000000.0/((float)ns))
#define DSPS_HZ            32768LL
/*Minimum frequency supported value is 1 from
corresponding timeout value in HAL is below*/
#define MAX_TIMEOUT        131072LL
#define SEC_TO_NSEC(sec)   ((sec)*NSEC_PER_SEC)

/* If two consecutive sensor samples have non-increasing timestamps:
 * If the second is within X of the first, edit the second. */
#define TS_CORRECT_THRESH 200000

/* If a new sensor sample contains a timestamp that is within X of 0, while
 * the previous sample contained a timestamp within X of UINT32_MAX, the SSC
 * clock may have rolled-over */
#define TS_ROLLOVER_THRESH 2147483648u /* 18.2Hrs -- (2^32)/2 */

/* If a DSPS clock-rollover is detected, ensure that the last rollover event
 * happened more than X ns ago. This prevents false rollover detections from
 * jitter in the incoming SSC timestamps. */
#define BOOT_TS_ROLLOVER_THRESH 5000000000 /* in ns (5 seconds) */

#ifndef LOGV_IF
#define LOGV_IF ALOGV_IF
#endif /* LOG_IF */
#ifndef LOGD_IF
#define LOGD_IF ALOGD_IF
#endif /* LOG_IF */
#ifndef LOGI_IF
#define LOGI_IF ALOGI_IF
#endif /* LOG_IF */
#ifndef LOGW_IF
#define LOGW_IF ALOGW_IF
#endif /* LOG_IF */
#ifndef LOGE_IF
#define LOGE_IF ALOGE_IF
#endif /* LOG_IF */

#define HAL_LOG_VERBOSE(...) LOGV_IF((g_hal_log_level <= HAL_LOG_LEVEL_VERBOSE), __VA_ARGS__ )
#define HAL_LOG_DEBUG(...) LOGD_IF((g_hal_log_level <= HAL_LOG_LEVEL_DEBUG), __VA_ARGS__ )
#define HAL_LOG_INFO(...) LOGI_IF((g_hal_log_level <= HAL_LOG_LEVEL_INFO), __VA_ARGS__ )
#define HAL_LOG_WARN(...) LOGW_IF((g_hal_log_level <= HAL_LOG_LEVEL_WARN), __VA_ARGS__ )
#define HAL_LOG_ERROR(...) LOGE_IF((g_hal_log_level <= HAL_LOG_LEVEL_ERROR), __VA_ARGS__ )

/* Sensor data rate in Hz */
#define FREQ_FASTEST_HZ   400.0f
#define FREQ_GAME_HZ      50.0f
#define FREQ_UI_HZ        15.0f
#define FREQ_NORMAL_HZ    5.0f

/* sensor handle */
#define QCOM_SENSORS_HANDLE_BASE      (SENSORS_HANDLE_BASE+1)
#define HANDLE_ACCELERATION           (QCOM_SENSORS_HANDLE_BASE+0)
#define HANDLE_LIGHT                  (QCOM_SENSORS_HANDLE_BASE+1)
#define HANDLE_GYRO                   (QCOM_SENSORS_HANDLE_BASE+2)
#define HANDLE_PRESSURE               (QCOM_SENSORS_HANDLE_BASE+3)
#define HANDLE_SMGR_STEP_DETECTOR     (QCOM_SENSORS_HANDLE_BASE+4)
#define HANDLE_SMGR_STEP_COUNT        (QCOM_SENSORS_HANDLE_BASE+5)
#define HANDLE_SMGR_SMD               (QCOM_SENSORS_HANDLE_BASE+6)
#define HANDLE_SMGR_GAME_RV           (QCOM_SENSORS_HANDLE_BASE+7)
#define HANDLE_GYRO_UNCALIBRATED      (QCOM_SENSORS_HANDLE_BASE+8)
#define HANDLE_RELATIVE_HUMIDITY      (QCOM_SENSORS_HANDLE_BASE+9)
#define HANDLE_MAGNETIC_FIELD              (QCOM_SENSORS_HANDLE_BASE+10)
#define HANDLE_MAGNETIC_FIELD_UNCALIBRATED (QCOM_SENSORS_HANDLE_BASE+11)
#define HANDLE_RGB                    (QCOM_SENSORS_HANDLE_BASE+12)
#define HANDLE_IR_GESTURE             (QCOM_SENSORS_HANDLE_BASE+13)
#define HANDLE_SAR                    (QCOM_SENSORS_HANDLE_BASE+14)
#define HANDLE_AMBIENT_TEMPERATURE    (QCOM_SENSORS_HANDLE_BASE+15)
#define HANDLE_HALL_EFFECT            (QCOM_SENSORS_HANDLE_BASE+16)
#define HANDLE_UV                     (QCOM_SENSORS_HANDLE_BASE+17)
#define HANDLE_THERMOPILE             (QCOM_SENSORS_HANDLE_BASE+18)
#define HANDLE_CCT                    (QCOM_SENSORS_HANDLE_BASE+19)
#define HANDLE_PROXIMITY              (QCOM_SENSORS_HANDLE_BASE+20)
#define HANDLE_ACCELERATION_UNCALIBRATED   (QCOM_SENSORS_HANDLE_BASE+21)

/* SMGR wake up sensors */
#define WU_HANDLE_BASE                (QCOM_SENSORS_HANDLE_BASE+22)
#define HANDLE_ACCELERATION_WAKE_UP                (WU_HANDLE_BASE)
#define HANDLE_LIGHT_WAKE_UP                       (WU_HANDLE_BASE+1)
#define HANDLE_GYRO_WAKE_UP                        (WU_HANDLE_BASE+2)
#define HANDLE_PRESSURE_WAKE_UP                    (WU_HANDLE_BASE+3)
#define HANDLE_SMGR_STEP_DETECTOR_WAKE_UP          (WU_HANDLE_BASE+4)
#define HANDLE_SMGR_STEP_COUNT_WAKE_UP             (WU_HANDLE_BASE+5)
#define HANDLE_SMGR_GAME_RV_WAKE_UP                (WU_HANDLE_BASE+6)
#define HANDLE_GYRO_UNCALIBRATED_WAKE_UP           (WU_HANDLE_BASE+7)
#define HANDLE_RELATIVE_HUMIDITY_WAKE_UP           (WU_HANDLE_BASE+8)
#define HANDLE_MAGNETIC_FIELD_WAKE_UP              (WU_HANDLE_BASE+9)
#define HANDLE_MAGNETIC_FIELD_UNCALIBRATED_WAKE_UP (WU_HANDLE_BASE+10)
#define HANDLE_AMBIENT_TEMPERATURE_WAKE_UP         (WU_HANDLE_BASE+11)
#define HANDLE_PROXIMITY_NON_WAKE_UP               (WU_HANDLE_BASE+12)
#define HANDLE_ACCELERATION_UNCALIBRATED_WAKE_UP   (WU_HANDLE_BASE+13)

/* SAM sensors */
#define SAM_HANDLE_BASE               (WU_HANDLE_BASE+14)
#define HANDLE_GRAVITY                (SAM_HANDLE_BASE)
#define HANDLE_LINEAR_ACCEL           (SAM_HANDLE_BASE+1)
#define HANDLE_GESTURE_FACE_N_SHAKE   (SAM_HANDLE_BASE+2)
#define HANDLE_GESTURE_BRING_TO_EAR   (SAM_HANDLE_BASE+3)
#define HANDLE_MOTION_ABSOLUTE        (SAM_HANDLE_BASE+4)
#define HANDLE_MOTION_RELATIVE        (SAM_HANDLE_BASE+5)
#define HANDLE_MOTION_VEHICLE         (SAM_HANDLE_BASE+6)
#define HANDLE_ROTATION_VECTOR        (SAM_HANDLE_BASE+7)

#define HANDLE_GESTURE_BASIC_GESTURES (SAM_HANDLE_BASE+8)
#define HANDLE_GESTURE_TAP            (SAM_HANDLE_BASE+9)
#define HANDLE_GESTURE_FACING         (SAM_HANDLE_BASE+10)
#define HANDLE_GESTURE_TILT           (SAM_HANDLE_BASE+11)
#define HANDLE_GESTURE_GYRO_TAP       (SAM_HANDLE_BASE+12)
#define HANDLE_PEDOMETER              (SAM_HANDLE_BASE+13)
#define HANDLE_SAM_STEP_DETECTOR      (SAM_HANDLE_BASE+14)
#define HANDLE_SAM_STEP_COUNTER       (SAM_HANDLE_BASE+15)
#define HANDLE_PAM                    (SAM_HANDLE_BASE+16)
#define HANDLE_MOTION_ACCEL           (SAM_HANDLE_BASE+17)
#define HANDLE_SIGNIFICANT_MOTION     (SAM_HANDLE_BASE+18)
#define HANDLE_THRESH                 (SAM_HANDLE_BASE+19)
#define HANDLE_ORIENTATION            (SAM_HANDLE_BASE+20)
#define HANDLE_GAME_ROTATION_VECTOR   (SAM_HANDLE_BASE+21)
#define HANDLE_MAGNETIC_FIELD_SAM              (SAM_HANDLE_BASE+22)
#define HANDLE_MAGNETIC_FIELD_UNCALIBRATED_SAM (SAM_HANDLE_BASE+23)
#define HANDLE_GEOMAGNETIC_ROTATION_VECTOR     (SAM_HANDLE_BASE+24)
#define HANDLE_CMC                    (SAM_HANDLE_BASE+25)
#define HANDLE_TILT_DETECTOR          (SAM_HANDLE_BASE+26)
#define HANDLE_PICK_UP_GESTURE        (SAM_HANDLE_BASE+27)
#define HANDLE_QHEART                 (SAM_HANDLE_BASE+28)
#define HANDLE_FAST_AMD               (SAM_HANDLE_BASE+29)
#define HANDLE_WRIST_TILT             (SAM_HANDLE_BASE+30)
#define HANDLE_IOD                    (SAM_HANDLE_BASE+31)
#define HANDLE_DPC                    (SAM_HANDLE_BASE+32)
#define HANDLE_MULTISHAKE             (SAM_HANDLE_BASE+33)
#define HANDLE_DEVICE_ORIENTATION     (SAM_HANDLE_BASE+34)
#define HANDLE_PMD                    (SAM_HANDLE_BASE+35)
#define HANDLE_STATIONARY_DETECT      (SAM_HANDLE_BASE+36)
#define HANDLE_MOTION_DETECT          (SAM_HANDLE_BASE+37)

/* SAM wake up sensors */
#define WU_SAM_HANDLE_BASE            (SAM_HANDLE_BASE+38)
#define HANDLE_ORIENTATION_WAKE_UP                     (WU_SAM_HANDLE_BASE)
#define HANDLE_GRAVITY_WAKE_UP                         (WU_SAM_HANDLE_BASE+1)
#define HANDLE_LINEAR_ACCEL_WAKE_UP                    (WU_SAM_HANDLE_BASE+2)
#define HANDLE_ROTATION_VECTOR_WAKE_UP                 (WU_SAM_HANDLE_BASE+3)
#define HANDLE_GAME_ROTATION_VECTOR_WAKE_UP            (WU_SAM_HANDLE_BASE+4)
#define HANDLE_GEOMAGNETIC_ROTATION_VECTOR_WAKE_UP     (WU_SAM_HANDLE_BASE+5)
#define HANDLE_SAM_STEP_DETECTOR_WAKE_UP               (WU_SAM_HANDLE_BASE+6)
#define HANDLE_SAM_STEP_COUNTER_WAKE_UP                (WU_SAM_HANDLE_BASE+7)
#define HANDLE_THRESH_NON_WAKE_UP                      (WU_SAM_HANDLE_BASE+8)
#define HANDLE_MAGNETIC_FIELD_SAM_WAKE_UP              (WU_SAM_HANDLE_BASE+9)
#define HANDLE_MAGNETIC_FIELD_UNCALIBRATED_SAM_WAKE_UP (WU_SAM_HANDLE_BASE+10)
#define HANDLE_QHEART_WAKE_UP                          (WU_SAM_HANDLE_BASE+11)
#define HANDLE_DEVICE_ORIENTATION_WAKE_UP              (WU_SAM_HANDLE_BASE+12)

#define TXN_ID_BASE                   (WU_SAM_HANDLE_BASE+13)
/* Transaction ID used when a response should not be signalled */
#define TXN_ID_NO_RESP_SIGNALLED      (TXN_ID_BASE)

/* All QC defined sensor types must start from QC_SENSOR_TYPE_BASE
   This is to ensure no collission with the Android sensor types
   defined in sensors.h */
#define QC_SENSOR_TYPE_BASE           33171000

#define SENSOR_TYPE_BASIC_GESTURES        (QC_SENSOR_TYPE_BASE)
#define SENSOR_TYPE_TAP                   (QC_SENSOR_TYPE_BASE + 1)
#define SENSOR_TYPE_FACING                (QC_SENSOR_TYPE_BASE + 2)
#define SENSOR_TYPE_TILT                  (QC_SENSOR_TYPE_BASE + 3)
#ifdef FEATURE_SNS_HAL_SAM_INT
#define SENSOR_TYPE_GESTURE_FACE_N_SHAKE  (QC_SENSOR_TYPE_BASE + 4)
#endif /* FEATURE_SNS_HAL_SAM_INT */
#define SENSOR_TYPE_GESTURE_BRING_TO_EAR  (QC_SENSOR_TYPE_BASE + 5)
#define SENSOR_TYPE_MOTION_ABSOLUTE       (QC_SENSOR_TYPE_BASE + 6)
#define SENSOR_TYPE_MOTION_RELATIVE       (QC_SENSOR_TYPE_BASE + 7)
#define SENSOR_TYPE_MOTION_VEHICLE        (QC_SENSOR_TYPE_BASE + 8)
#define SENSOR_TYPE_PEDOMETER             (QC_SENSOR_TYPE_BASE + 9)
#define SENSOR_TYPE_PAM                   (QC_SENSOR_TYPE_BASE + 10)
#define SENSOR_TYPE_SCREEN_ORIENTATION    (QC_SENSOR_TYPE_BASE + 11)
#define SENSOR_TYPE_CMC                   (QC_SENSOR_TYPE_BASE + 12)
#define SENSOR_TYPE_RGB                   (QC_SENSOR_TYPE_BASE + 13)
#define SENSOR_TYPE_IR_GESTURE            (QC_SENSOR_TYPE_BASE + 14)
#define SENSOR_TYPE_SAR                   (QC_SENSOR_TYPE_BASE + 15)
#define SENSOR_TYPE_HALL_EFFECT           (QC_SENSOR_TYPE_BASE + 16)
#define SENSOR_TYPE_FAST_AMD              (QC_SENSOR_TYPE_BASE + 17)
#define SENSOR_TYPE_UV                    (QC_SENSOR_TYPE_BASE + 18)
#define SENSOR_TYPE_THERMOPILE            (QC_SENSOR_TYPE_BASE + 19)
#define SENSOR_TYPE_CCT                   (QC_SENSOR_TYPE_BASE + 20)
#define SENSOR_TYPE_IOD                   (QC_SENSOR_TYPE_BASE + 21)
#define SENSOR_TYPE_DPC                   (QC_SENSOR_TYPE_BASE + 22)
#define SENSOR_TYPE_MULTISHAKE            (QC_SENSOR_TYPE_BASE + 23)
#define SENSOR_TYPE_PMD                   (QC_SENSOR_TYPE_BASE + 24)


/* String type for QC defined sensors */
#define SENSOR_STRING_TYPE_BASIC_GESTURES        "com.qti.sensor.basic_gestures"
#define SENSOR_STRING_TYPE_TAP                   "com.qti.sensor.tap"
#define SENSOR_STRING_TYPE_FACING                "com.qti.sensor.facing"
#define SENSOR_STRING_TYPE_TILT                  "com.qti.sensor.tilt"
#define SENSOR_STRING_TYPE_GESTURE_FACE_N_SHAKE  "com.qti.sensor.fns"
#define SENSOR_STRING_TYPE_GESTURE_BRING_TO_EAR  "com.qti.sensor.bte"
#define SENSOR_STRING_TYPE_MOTION_ABSOLUTE       "com.qti.sensor.amd"
#define SENSOR_STRING_TYPE_MOTION_RELATIVE       "com.qti.sensor.rmd"
#define SENSOR_STRING_TYPE_MOTION_VEHICLE        "com.qti.sensor.vmd"
#define SENSOR_STRING_TYPE_PEDOMETER             "com.qti.sensor.pedometer"
#define SENSOR_STRING_TYPE_PAM                   "com.qti.sensor.pam"
#define SENSOR_STRING_TYPE_SCREEN_ORIENTATION    "com.qti.sensor.motion_accel"
#define SENSOR_STRING_TYPE_CMC                   "com.qti.sensor.cmc"
#define SENSOR_STRING_TYPE_RGB                   "com.qti.sensor.rgb"
#define SENSOR_STRING_TYPE_IR_GESTURE            "com.qti.sensor.ir_gesture"
#define SENSOR_STRING_TYPE_SAR                   "com.qti.sensor.sar"
#define SENSOR_STRING_TYPE_HALL_EFFECT           "com.qti.sensor.hall_effect"
#define SENSOR_STRING_TYPE_FAST_AMD              "com.qti.sensor.fast_amd"
#define SENSOR_STRING_TYPE_UV                    "com.qti.sensor.uv"
#define SENSOR_STRING_TYPE_THERMOPILE            "com.qti.sensor.thermopile"
#define SENSOR_STRING_TYPE_CCT                   "com.qti.sensor.cct"
#define SENSOR_STRING_TYPE_IOD                   "com.qti.sensor.iod"
#define SENSOR_STRING_TYPE_DPC                   "com.qti.sensor.dpc"
#define SENSOR_STRING_TYPE_MULTISHAKE            "com.qti.sensor.multishake"
#define SENSOR_STRING_TYPE_PMD                   "com.qti.sensor.pmd"

/* Properties to set max rates. Limit length of prop name to PROP_NAME_MAX */
#define HAL_PROP_MAX_ACCEL          "ro.vendor.sensors.max_accel_rate"
#define HAL_PROP_MAX_GYRO           "ro.vendor.sensors.max_gyro_rate"
#define HAL_PROP_MAX_MAG            "ro.vendor.sensors.max_mag_rate"
#define HAL_PROP_MAX_GRAV           "ro.vendor.sensors.max_grav_rate"
#define HAL_PROP_MAX_GRAV_NO_GYRO   "ro.vendor.sensors.max_grav_no_gyro"
#define HAL_PROP_MAX_ROTVEC         "ro.vendor.sensors.max_rotvec_rate"
#define HAL_PROP_MAX_GEOMAG_ROTVEC  "ro.vendor.sensors.max_geomag_rotv"
#define HAL_PROP_MAX_GAMERV         "ro.vendor.sensors.max_gamerv_rate"

/* Min sample freq property for QFusion sensors */
#define HAL_PROP_QFUSION_USE_REPORT_PERIOD   "ro.vendor.qfusion_use_report_period"

/* Min rate for qfusion sensors */
#define MIN_FREQ_QFUSION_HZ   1

/* Default max rates for sensors, unless overridden by property value */
#define MAX_ACCEL_RATE   "200"
#define MAX_GYRO_RATE    "200"
#define MAX_MAG_RATE     "100"

#define FREQ_ACCEL_DEF_HZ_STR          MAX_ACCEL_RATE
#define FREQ_GYRO_DEF_HZ_STR           MAX_GYRO_RATE
#define FREQ_MAG_DEF_HZ_STR            MAX_MAG_RATE

/* Properties to enable sensor features */
#define HAL_PROP_DEBUG          "persist.vendor.debug.sensors.hal"
#define HAL_PROP_GESTURES       "ro.vendor.sdk.sensors.gestures"
#define HAL_PROP_PEDOMETER      "ro.vendor.sensors.pedometer"
#define HAL_PROP_STEP_DETECTOR  "ro.vendor.sensors.step_detector"
#define HAL_PROP_STEP_COUNTER   "ro.vendor.sensors.step_counter"
#define HAL_PROP_PAM            "ro.vendor.sensors.pam"
#define HAL_PROP_SCRN_ORTN      "ro.vendor.sensors.scrn_ortn"
#define HAL_PROP_SMD            "ro.vendor.sensors.smd"
#define HAL_PROP_GRV            "ro.vendor.sensors.game_rv"
#define HAL_PROP_GEOMAGNETIC_RV "ro.vendor.sensors.georv"
#define HAL_PROP_CMC            "ro.vendor.sensors.cmc"
#define HAL_PROP_BTE            "ro.vendor.sensors.bte"
#define HAL_PROP_FNS            "ro.vendor.sensors.fns"
#define HAL_PROP_QMD            "ro.vendor.sensors.qmd"
#define HAL_PROP_AMD            "ro.vendor.sensors.amd"
#define HAL_PROP_RMD            "ro.vendor.sensors.rmd"
#define HAL_PROP_VMD            "ro.vendor.sensors.vmd"
#define HAL_PROP_GTAP           "ro.vendor.sensors.gtap"
#define HAL_PROP_TAP            "ro.vendor.sensors.tap"
#define HAL_PROP_FACING         "ro.vendor.sensors.facing"
#define HAL_PROP_TILT           "ro.vendor.sensors.tilt"
#define HAL_PROP_TILT_DETECTOR  "ro.vendor.sensors.tilt_detector"
#define HAL_PROP_PUG            "ro.vendor.sensors.pug"
#define HAL_PROP_QHEART         "ro.vendor.sensors.qheart"
#define HAL_PROP_WU_SENSORS     "ro.vendor.sensors.wu"
#define HAL_PROP_PROXIMITY      "ro.vendor.sensors.proximity"
#define HAL_PROP_GRAVITY        "ro.vendor.sensors.gravity"
#define HAL_PROP_LACCEL         "ro.vendor.sensors.laccel"
#define HAL_PROP_ORIENTATION    "ro.vendor.sensors.orientation"
#define HAL_PROP_ROTVEC         "ro.vendor.sensors.rotvec"
#define HAL_PROP_FAST_AMD       "ro.vendor.sensors.fast_amd"
#define HAL_PROP_WRIST_TILT     "ro.vendor.sensors.wrist_tilt"
#define HAL_PROP_IOD            "ro.vendor.sensors.iod"
#define HAL_PROP_DPC            "ro.vendor.sensors.dpc"
#define HAL_PROP_MULTISHAKE     "ro.vendor.sensors.multishake"
#define HAL_PROP_RAWDATAMODE    "ro.vendor.sensors.rawdata_mode"
#define HAL_PROP_DEV_ORI        "ro.vendor.sensors.dev_ori"
#define HAL_PROP_PMD            "ro.vendor.sensors.pmd"
#define HAL_PROP_STA_DETECT     "ro.vendor.sensors.sta_detect"
#define HAL_PROP_MOT_DETECT     "ro.vendor.sensors.mot_detect"
#define HAL_PROP_MAGHALCAL      "ro.vendor.sensors.maghalcal"
#define HAL_PROP_DIRECT_CHANNEL "persist.vendor.sensors.direct_channel"

/* Duration that must be supported for Wake upon Fifo Full flag */
#define WUFF_MIN_DURATION_SEC 10

/* Delay between activate/batch/setDelay and making the changes take effect */
#define HAL_ACQUIRE_RESOURCES_DELAY_NSEC 10000000L /* 10ms */
#define SNS_ROT_VEC_HEAD_ERR_EST_RAD (M_PI / 6.f)

/* Tilt Detector angle threshlod as per Android HAL API */
#define TILT_ANGLE_THRESH 35

/* wake lock */
#define SENSORS_WAKE_LOCK "sensor_ind"

/* MA/LP2 sampling rate */
#define MOTION_ACCEL_SAMPLE_RATE 15

/* SMGR min report rate to support subHz */
#define SMGR_SUB_HZ_REPORT_RATE_MIN_HZ (0.0152590218966965f)

/* SMGR StepCounter min report rate */
#define SMGR_SCOUNT_REPORT_RATE_MIN_HZ (0.10)

/* SMGR version to be checked to support subHz */
#define SMGR_SUB_HZ_VERSION 21

/* SMGR version to be checked to support Reserved FIFO */
#define SMGR_RES_FIFO_VERSION 25

/* Fast AMD Async report */
#define FAST_AMD_ASYNC_REPORT 0x02

/* Fast AMD Motion State Detection Period in MS */
#define FAST_AMD_MS_DETECTION_PERIOD 10000000

/* Fast AMD Stationary State Detection Period in MS */
#define FAST_AMD_SS_DETECTION_PERIOD 3000000

/*===========================================================================
                   DATA TYPES
===========================================================================*/
typedef struct sensors_poll_device_1 poll_dev_t;
typedef struct sensors_poll_device_1 sensors_poll_device_1;

/* Definitions for logging */
typedef enum {
    HAL_LOG_LEVEL_ALL,
    HAL_LOG_LEVEL_VERBOSE,
    HAL_LOG_LEVEL_DEBUG,
    HAL_LOG_LEVEL_INFO,
    HAL_LOG_LEVEL_WARN,
    HAL_LOG_LEVEL_ERROR,
    HAL_LOG_LEVEL_DISABLED
} hal_log_level_e;

/* sensor event data buffer node */
typedef struct hal_sensor_dataq_t {
    sensors_event_t             data;   /* sensor event data that will report to framework */
    struct hal_sensor_dataq_t*  next;   /* pointer to the next sensor event data */
} hal_sensor_dataq_t;

typedef struct hal_sensor_mag_cal_sample_t {
    uncalibrated_event_t sample;
    uint32_t             smgr_ts;
    uint32_t             sam_ts;
} hal_sensor_mag_cal_sample_s;

/* this type is used for handling the sensor1 callback */
typedef struct hal_sensor1_cb_t {
    sensor1_handle_s*   sensor1_handle;
    bool                error;
    pthread_mutex_t     cb_mutex;       /* mutex lock for sensor1 callback */
    pthread_cond_t      cb_cond;        /* cond variable to signal callback has arrived */
    bool                is_resp_arrived;/* flag to indicate response callback has arrived */
} hal_sensor1_cb_t;

/* this type is used for handling the sensor event polling data */
typedef struct hal_data_cb_t {
    pthread_mutex_t     data_mutex;     /* mutex lock for sensor data */
    pthread_cond_t      data_cond;      /* cond variable to signal has arrived */
    bool                sensors_wakelock_held;/* wakelock currently being held status */
    bool                is_ind_arrived; /* flag to indicate the indicator has arrived */
    pthread_mutex_t     wakelock_mutex; /* mutex lock for wakelock operations */
    uint32_t            wake_events_in_queue; /* number of wake events in queue */
} hal_data_cb_t;

/* The trigger_mode represents the sensor report data method. */
typedef enum {
    SENSOR_MODE_CONT,                   /* the sensor reports continuous data */
    SENSOR_MODE_EVENT,                  /* the sensor reports event data */
    SENSOR_MODE_SPECIAL,                /* the sensor reports special data */
    SENSOR_MODE_TRIG                    /* the sensor data is trigged */
} sensor_trigger_mode;

/*===========================================================================
                    GLOBAL VARIABLES
===========================================================================*/
extern hal_log_level_e g_hal_log_level;

const int g_sensor_list_order[] = {
    /* Physical sensors */
    HANDLE_ACCELERATION,
    HANDLE_ACCELERATION_UNCALIBRATED,
    HANDLE_MAGNETIC_FIELD,
    HANDLE_MAGNETIC_FIELD_UNCALIBRATED,
    HANDLE_MAGNETIC_FIELD_SAM,
    HANDLE_MAGNETIC_FIELD_UNCALIBRATED_SAM,
    HANDLE_GYRO,
    HANDLE_GYRO_UNCALIBRATED,
    HANDLE_PROXIMITY,
    HANDLE_THRESH,
    HANDLE_LIGHT,
    HANDLE_PRESSURE,
    HANDLE_RELATIVE_HUMIDITY,
    HANDLE_AMBIENT_TEMPERATURE,
    /* SMGR wake up sensors */
    HANDLE_ACCELERATION_WAKE_UP,
    HANDLE_ACCELERATION_UNCALIBRATED_WAKE_UP,
    HANDLE_MAGNETIC_FIELD_WAKE_UP,
    HANDLE_MAGNETIC_FIELD_UNCALIBRATED_WAKE_UP,
    HANDLE_MAGNETIC_FIELD_SAM_WAKE_UP,
    HANDLE_MAGNETIC_FIELD_UNCALIBRATED_SAM_WAKE_UP,
    HANDLE_GYRO_WAKE_UP,
    HANDLE_GYRO_UNCALIBRATED_WAKE_UP,
    HANDLE_PROXIMITY_NON_WAKE_UP,
    HANDLE_THRESH_NON_WAKE_UP,
    HANDLE_LIGHT_WAKE_UP,
    HANDLE_PRESSURE_WAKE_UP,
    HANDLE_RELATIVE_HUMIDITY_WAKE_UP,
    HANDLE_AMBIENT_TEMPERATURE_WAKE_UP,

    /* Android virtual sensors via SAM: */
    HANDLE_GRAVITY,
    HANDLE_LINEAR_ACCEL,
    HANDLE_ROTATION_VECTOR,
    HANDLE_SAM_STEP_DETECTOR,
    HANDLE_SAM_STEP_COUNTER,
    HANDLE_SIGNIFICANT_MOTION,
    HANDLE_GAME_ROTATION_VECTOR,
    HANDLE_GEOMAGNETIC_ROTATION_VECTOR,
    HANDLE_ORIENTATION,
    HANDLE_TILT_DETECTOR,
    HANDLE_PICK_UP_GESTURE,
    HANDLE_QHEART,
    HANDLE_WRIST_TILT,
    HANDLE_DEVICE_ORIENTATION,
    HANDLE_STATIONARY_DETECT,
    HANDLE_MOTION_DETECT,
    /* SAM wake up sensors */
    HANDLE_GRAVITY_WAKE_UP,
    HANDLE_LINEAR_ACCEL_WAKE_UP,
    HANDLE_ROTATION_VECTOR_WAKE_UP,
    HANDLE_SAM_STEP_DETECTOR_WAKE_UP,
    HANDLE_SAM_STEP_COUNTER_WAKE_UP,
    HANDLE_GAME_ROTATION_VECTOR_WAKE_UP,
    HANDLE_GEOMAGNETIC_ROTATION_VECTOR_WAKE_UP,
    HANDLE_ORIENTATION_WAKE_UP,
    HANDLE_QHEART_WAKE_UP,
    HANDLE_DEVICE_ORIENTATION_WAKE_UP,

    /* Android virtual sensors via SMGR: */
    HANDLE_SMGR_STEP_DETECTOR,
    HANDLE_SMGR_STEP_COUNT,
    HANDLE_SMGR_SMD,
    HANDLE_SMGR_GAME_RV,
    /* SMGR wake up sensors */
    HANDLE_SMGR_STEP_DETECTOR_WAKE_UP,
    HANDLE_SMGR_STEP_COUNT_WAKE_UP,
    HANDLE_SMGR_GAME_RV_WAKE_UP,

    /* QTI value added sensors: */
    HANDLE_GESTURE_FACE_N_SHAKE,
    HANDLE_GESTURE_BRING_TO_EAR,
    HANDLE_MOTION_ABSOLUTE,
    HANDLE_MOTION_RELATIVE,
    HANDLE_MOTION_VEHICLE,
    HANDLE_GESTURE_BASIC_GESTURES,
    HANDLE_GESTURE_TAP,
    HANDLE_GESTURE_FACING,
    HANDLE_GESTURE_TILT,
    HANDLE_GESTURE_GYRO_TAP,
    HANDLE_PEDOMETER,
    HANDLE_PAM,
    HANDLE_MOTION_ACCEL,
    HANDLE_CMC,
    HANDLE_RGB,
    HANDLE_IR_GESTURE,
    HANDLE_SAR,
    HANDLE_HALL_EFFECT,
    HANDLE_FAST_AMD,
    HANDLE_UV,
    HANDLE_THERMOPILE,
    HANDLE_CCT,
    HANDLE_IOD,
    HANDLE_DPC,
    HANDLE_MULTISHAKE,
    HANDLE_PMD,
};

#ifdef __cplusplus
}
#endif

#endif /* SENSORS_HAL_H */
