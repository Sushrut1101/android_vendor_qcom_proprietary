/*============================================================================
  @file Gyroscope.cpp

  @brief
  Gyroscope class implementation.

  Copyright (c) 2014-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
============================================================================*/

#include "Gyroscope.h"

/*============================================================================
  Gyroscope Constructor
============================================================================*/
Gyroscope::Gyroscope(int handle)
    :SMGRSensor(handle)
{
    trigger_mode = SENSOR_MODE_CONT;
    (handle == HANDLE_GYRO_WAKE_UP)?(bWakeUp = true):(bWakeUp = false);

    // Set flags
        flags = SENSOR_FLAG_CONTINUOUS_MODE;
#ifdef SNS_DIRECT_REPORT_SUPPORT
    if (Utility::isDirectChannelTypeSupported()) {
        // Add the Direct Channel Gralloc flag
        flags |= SENSOR_FLAG_DIRECT_CHANNEL_GRALLOC;
        // PEND: This should happen when processing the SMGR info in setSensorInfo to dynamically configure the flags
        // Add the supported Direct Channel rates
        flags |= (SENSOR_DIRECT_RATE_VERY_FAST << SENSOR_FLAG_SHIFT_DIRECT_REPORT);
    }
#endif
}

/*============================================================================
  Gyroscope Destructor
============================================================================*/
Gyroscope::~Gyroscope()
{

}

uint64_t Gyroscope::getSuid()
{
  return SNS_SMGR_SUID_GYRO_1_V01;
}

/*===========================================================================
  FUNCTION:  setSensorInfo
    Fill the sensor information from the sns_smgr_sensor_datatype_info_s_v01 type
    Parameters
    @datatype : sensor information got from the sensor1 callback
===========================================================================*/
void Gyroscope::setSensorInfo(sns_smgr_sensor_datatype_info_s_v01* datatype)
{
    HAL_LOG_DEBUG("%s: GYRO DTy: %d", __FUNCTION__, datatype->DataType);
    setType(SENSOR_TYPE_GYROSCOPE);

    if(bWakeUp == true) {
        flags |= SENSOR_FLAG_WAKE_UP;
        strlcat(name," -Wakeup",SNS_MAX_SENSOR_NAME_SIZE);
    }

    setResolution((float)((float)datatype->Resolution *
                        UNIT_CONVERT_GYRO));
    setMaxRange((float)((float)datatype->MaxRange *
                        UNIT_CONVERT_GYRO));
    setMinFreq(SNS_SMGR_REPORT_RATE_MIN_HZ_V01);
    return;
}

/*===========================================================================
  FUNCTION:  processReportInd
    process the sensor data indicator from the sensor1 type to sensor event type
    Parameters
    @smgr_data : the sensor1 data message from the sensor1 callback
    @sensor_data : the sensor event message that will be send to framework
===========================================================================*/
void Gyroscope::processReportInd(sns_smgr_periodic_report_ind_msg_v01* smgr_ind,
            sns_smgr_data_item_s_v01* smgr_data, sensors_event_t &sensor_data)
{
    uint8_t accuracy = 0x06; // bits 1,2 of Item Flag used for accuracy
    UNREFERENCED_PARAMETER(smgr_ind);

    sensor_data.type = SENSOR_TYPE_GYROSCOPE;
    if(bWakeUp == false) {
        sensor_data.sensor = HANDLE_GYRO;
        HAL_LOG_VERBOSE("%s:sensor %s ",__FUNCTION__,
                    Utility::SensorTypeToSensorString(getType()));
    } else {
        sensor_data.sensor = HANDLE_GYRO_WAKE_UP;
        HAL_LOG_VERBOSE("%s:sensor %s (wake_up)",__FUNCTION__,
                    Utility::SensorTypeToSensorString(getType()));
    }

    /* Convert from SAE to Android co-ordinates and scale
    x' = y; y' = x; z' = -z; */
    sensor_data.gyro.x = (float)(smgr_data->ItemData[1]) * UNIT_CONVERT_GYRO;
    sensor_data.gyro.y = (float)(smgr_data->ItemData[0]) * UNIT_CONVERT_GYRO;
    sensor_data.gyro.z = (float)(-smgr_data->ItemData[2]) * UNIT_CONVERT_GYRO;

    accuracy &= smgr_data->ItemFlags;
    accuracy >>= 1;
    ((sensors_vec_t*)(sensor_data.data))->status = accuracy;

    HAL_LOG_VERBOSE("%s: X: %f Y: %f Z: %f status: %d", __FUNCTION__,
            sensor_data.gyro.x,
            sensor_data.gyro.y,
            sensor_data.gyro.z, sensor_data.gyro.status);
}

/*===========================================================================
  FUNCTION:  prepareAddMsg
    SMGRSensor::SMGRPrepareAddMsg will call this function and this func will
    fill the item that needed for this type of sensor.
    Parameters
    @buff_req : the sensor1 message buffer
===========================================================================*/
void Gyroscope::prepareAddMsg(sns_smgr_buffering_req_msg_v01 **buff_req)
{
    (*buff_req)->Item[0].SensorId = SNS_SMGR_ID_GYRO_V01;
}
