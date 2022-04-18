/* is_common_intf.h
 *
 * Copyright (c) 2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef __IS_COMMOM_INTF_H__
#define __IS_COMMOM_INTF_H__


typedef struct {
  uint64_t sof;
  uint64_t frame_time;
  float exposure_time;
} frame_times_t;


/** _eis_kalman_type:
 *    @A: relation between previous state and current state
 *    @Q: variance of process noise
 *    @R: variance of measurement noise
 *    @H: relation between state and measurement
 *    @x: discrete time controlled process
 *    @P: error covariance
 *    @B: relation between state and control input
 *    @u: control input
 *    @z: measurement
 *
 * This structure maintains the state for the Kalman filter defined by the
 * following equations:
 * State equation:        x_k = A*x_(k-1) + B*u_(k-l) + w_k
 * Measurement equation:  z_k = H*x_k + v_k
 * Estimation error:      e = x_est_k - x_k
 * Error covariance:      P = E[e*e']
 **/
typedef struct
{
  int32_t A;
  int32_t Q;
  int32_t R;
  int32_t H;
  int32_t x;
  int32_t P;
  int32_t B;
  int32_t u;
  int32_t z;
} eis_kalman_type;


typedef struct {
  int64_t rs_interval_offset_1;
  int64_t rs_interval_offset_2;
  int64_t rs_interval_offset_3;
  int64_t rs_interval_offset_4;
  int64_t s3d_interval_offset_1;
  int64_t s3d_interval_offset_2;
  int64_t s3d_interval_offset_3;
  int64_t s3d_interval_offset_4;
  double rs_exposure_threshold_1;
  double rs_exposure_threshold_2;
  double rs_exposure_threshold_3;
  double s3d_exposure_threshold_1;
  double s3d_exposure_threshold_2;
  double s3d_exposure_threshold_3;
  int64_t rs_time_interval_1;
  int64_t rs_time_interval_2;
  int64_t rs_time_interval_3;
  int64_t rs_time_interval_4;
} gyro_interval_tuning_parameters_t;


typedef double mat3x3[3][3];


typedef struct {
  double w;
  double x;
  double y;
  double z;
} quaternion_type;
#endif
