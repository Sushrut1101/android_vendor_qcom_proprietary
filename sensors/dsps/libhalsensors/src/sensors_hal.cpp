/*============================================================================
  @file sensors_hal.cpp

  @brief

  Copyright (c) 2014-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
============================================================================*/
/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include <cutils/properties.h>
#include <errno.h>
#include <math.h>
#include <sensors.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>

#include <hardware/gralloc.h>
#include <hardware/hardware.h>

#include "Sensor.h"
#include "SensorsContext.h"
#include "Utility.h"

#ifdef SNS_DIRECT_REPORT_SUPPORT
#include "rpcmem.h"
#include "sns_low_lat_stream.h"
#endif

/*===========================================================================
                         GLOBAL VARIABLES
===========================================================================*/
hal_log_level_e g_hal_log_level = HAL_LOG_LEVEL_WARN;

/*****************************************************************************/

static int sensors_close(struct hw_device_t *dev)
{
    UNREFERENCED_PARAMETER(dev);
    return 0;
}

static int sensors_activate(struct sensors_poll_device_t *dev,
        int handle, int en)
{
    SensorsContext *ctx = (SensorsContext *)dev;
    int ret = 0;
    ATRACE_BEGIN("SSCHAL:sensors_activate");
    ret = ctx->activate(handle, en);
    ATRACE_END();
    return ret;
}

static int sensors_batch(sensors_poll_device_1_t *dev,
        int handle, int flags, int64_t period_ns, int64_t timeout)
{
    SensorsContext *ctx = (SensorsContext *)dev;
    int ret = 0;
    ATRACE_BEGIN("SSCHAL:sensors_batch");
    ret = ctx->batch(handle, flags, period_ns, timeout);
    ATRACE_END();
    return ret;
}

static int sensors_set_delay(struct sensors_poll_device_t *dev,
        int handle, int64_t ns)
{
    const int flags = 0;
    const int timeout = 0;
    return sensors_batch((sensors_poll_device_1 *)dev, handle, flags, ns, timeout);
}

static int sensors_poll(struct sensors_poll_device_t *dev,
        sensors_event_t* data, int count)
{
    SensorsContext *ctx = (SensorsContext *)dev;
    int ret = 0;
    //ATRACE_BEGIN("SSCHAL:sensors_poll");
    ret = ctx->poll(data, count);
    //ATRACE_END();
    return ret;
}

static int sensors_flush(sensors_poll_device_1_t *dev, int handle)
{
    SensorsContext *ctx = (SensorsContext *)dev;
    int ret = 0;
    ATRACE_BEGIN("SSCHAL:sensors_flush");
    ret = ctx->flush(handle);
    ATRACE_END();
    return ret;
}

static int sensors_inject_sensor_data(struct sensors_poll_device_1 *dev,
    const sensors_event_t *data)
{
    SensorsContext *ctx = (SensorsContext *)dev;
    UNREFERENCED_PARAMETER(data);
    int ret = -EPERM;

    return ret;
}

#ifdef SNS_DIRECT_REPORT_SUPPORT
static int sensors_register_direct_channel(sensors_poll_device_1_t *dev,
    const struct sensors_direct_mem_t* mem, int channel_handle)
{
    SensorsContext *ctx = (SensorsContext *)dev;
    int ret = 0;

    // Unregister the channel
    if (NULL == mem)
    {
        ctx->unregisterDirectChannel(channel_handle);
    }
    // Register the channel
    else
    {
        ret = ctx->registerDirectChannel(mem);
    }

    return ret;
}

static int sensors_config_direct_report(sensors_poll_device_1_t *dev,
    int sensor_handle, int channel_handle, const struct sensors_direct_cfg_t *config)
{
    SensorsContext *ctx = (SensorsContext *)dev;

    return ctx->configDirectReport(sensor_handle, channel_handle, config);
}
#endif

/*****************************************************************************/

static int sensors_open(const struct hw_module_t* module, const char* id,
                        struct hw_device_t** device)
{
    UNREFERENCED_PARAMETER(id);
    int ret = -EINVAL;
    ATRACE_BEGIN("SSCHAL:sensors_open");
    SensorsContext *dev = SensorsContext::getInstance();

    memset(&dev->device, 0, sizeof(sensors_poll_device_1_t));

    dev->device.common.tag       = HARDWARE_DEVICE_TAG;
    dev->device.common.version   = SENSORS_DEVICE_API_VERSION_1_4;
    dev->device.common.module    = const_cast<hw_module_t*>(module);
    dev->device.common.close     = sensors_close;
    dev->device.activate         = sensors_activate;
    dev->device.setDelay         = sensors_set_delay;
    dev->device.poll             = sensors_poll;
    dev->device.batch            = sensors_batch;
    dev->device.flush            = sensors_flush;
    dev->device.inject_sensor_data      = sensors_inject_sensor_data;
#ifdef SNS_DIRECT_REPORT_SUPPORT
    dev->device.register_direct_channel = sensors_register_direct_channel;
    dev->device.config_direct_report    = sensors_config_direct_report;
#else
    dev->device.register_direct_channel = nullptr;
    dev->device.config_direct_report    = nullptr;
#endif

    *device = &dev->device.common;
    ret = 0;
    ATRACE_END();
    return ret;
}

static int sensors_get_sensors_list(struct sensors_module_t* module,
                    struct sensor_t const** list)
{
    UNREFERENCED_PARAMETER(module);
    int i, j;
    /* Number of valid entries in array */
    static int sensor_list_len = 0;
    sensor_trigger_mode sensor_type;
    static struct sensor_t sensor_list[MAX_NUM_SENSORS];
    SensorsContext *context = SensorsContext::getInstance();
    ATRACE_BEGIN("SSCHAL:sensors_get_sensors_list");
    Sensor **mSensors = context->getSensors();

    HAL_LOG_INFO("%s", __FUNCTION__);

    if (sensor_list_len != 0) {
        HAL_LOG_INFO("%s: Already have the list of sensors", __FUNCTION__);
        *list = sensor_list;
        ATRACE_END();
        return sensor_list_len;
    }

    for (i=0; i < ARRAY_SIZE(g_sensor_list_order); i++) {
        int handle = g_sensor_list_order[i];
        if (mSensors[handle] == NULL) {
            HAL_LOG_WARN("%s: handle %d is not registered!",__FUNCTION__, handle);
            continue;
        }
        HAL_LOG_INFO("%s:sensor(%s) handle %d is_attrib_ok %d",
                      __FUNCTION__,mSensors[handle]->getName(),
                      handle, mSensors[handle]->getAttribOK());

        if (mSensors[handle]->getAttribOK()) {
            sensor_list[sensor_list_len].name = mSensors[handle]->getName();
            sensor_list[sensor_list_len].vendor = mSensors[handle]->getVendor();
            sensor_list[sensor_list_len].version = mSensors[handle]->getVersion();
            sensor_list[sensor_list_len].handle = mSensors[handle]->getHandle();
            sensor_list[sensor_list_len].type = mSensors[handle]->getType();
            sensor_list[sensor_list_len].maxRange = mSensors[handle]->getMaxRange();
            sensor_list[sensor_list_len].resolution = mSensors[handle]->getResolution();
            sensor_list[sensor_list_len].power = mSensors[handle]->getPower();
            sensor_list[sensor_list_len].flags = mSensors[handle]->getFlags();
            sensor_type = mSensors[handle]->getTriggerMode();
            sensor_list[sensor_list_len].minDelay =
                    (SENSOR_MODE_EVENT == sensor_type) ? 0 :
                    (SENSOR_MODE_SPECIAL == sensor_type) ? 0 :
                    (SENSOR_MODE_TRIG == sensor_type) ? -1 :
                    (int32_t)HZ_TO_USEC(mSensors[handle]->getMaxFreq());

            mSensors[handle]->setStringType(Utility::SensorTypeToSensorString(mSensors[handle]->getType()));
            sensor_list[sensor_list_len].stringType = mSensors[handle]->getStringType();

            /* Need to set permissions for HRM */
            if (mSensors[handle]->getType() == SENSOR_TYPE_HEART_RATE) {
                mSensors[handle]->setPermissionString(SENSOR_PERMISSION_BODY_SENSORS);
            }
            else {
                mSensors[handle]->setPermissionString("");
            }
            sensor_list[sensor_list_len].requiredPermission = mSensors[handle]->getPermissionString();

            sensor_list[sensor_list_len].maxDelay =
                    (SENSOR_MODE_SPECIAL == sensor_type) ? 0 :
                    (SENSOR_MODE_TRIG == sensor_type) ? 0 :
                    (int32_t)HZ_TO_USEC(mSensors[handle]->getMinFreq());

            /* If we already have a sensor of this type, add " Secondary" to the name */
            for (j = 0; j < sensor_list_len; j++) {
                if(sensor_list[j].type == sensor_list[sensor_list_len].type) {
                    strlcat(mSensors[handle]->getName(),
                        " Secondary", SNS_MAX_SENSOR_NAME_SIZE);
                }
            }

            /* As FIFOs are shared among different sensors, FIFO reserved count should be set to 0 */
            sensor_list[sensor_list_len].fifoReservedEventCount =
                    (SENSOR_MODE_TRIG == sensor_type) ? 0 : mSensors[handle]->getResBufferedSamples();
            sensor_list[sensor_list_len].fifoMaxEventCount =
                    (SENSOR_MODE_TRIG == sensor_type) ? 0 : mSensors[handle]->getMaxBufferedSamples();
            sensor_list_len++;
        }
    }
    *list = sensor_list;

    HAL_LOG_INFO("%s: Number of sensors: %d", __FUNCTION__, sensor_list_len);
    ATRACE_END();
    return sensor_list_len;
}

static int sensors_set_operation_mode(unsigned int mode)
{
    int ret = 0;

    if (mode) {
        ret = -EINVAL;
    }

    return ret;
}

static struct hw_module_methods_t sensors_module_methods = {
    .open = sensors_open
};

struct sensors_module_t HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .module_api_version = (uint16_t)SENSORS_DEVICE_API_VERSION_1_4,
        .hal_api_version = HARDWARE_HAL_API_VERSION,
        .id = SENSORS_HARDWARE_MODULE_ID,
        .name = "QTI Sensors Module",
        .author = "Qualcomm Technologies, Inc.",
        .methods = &sensors_module_methods,
        .dso = NULL,
        .reserved = {0},
    },
    .get_sensors_list = sensors_get_sensors_list,
    .set_operation_mode = sensors_set_operation_mode
};
