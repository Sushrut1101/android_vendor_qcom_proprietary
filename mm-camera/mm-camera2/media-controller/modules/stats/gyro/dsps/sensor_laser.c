/* sensor_laser.c
 *
 * Copyright (c) 2015-2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
*/

#include <pthread.h>
#include "sensor_laser.h"
#include "stats_debug.h"

#ifdef _ANDROID_
#include <hardware/sensors.h>
#include <dlfcn.h>
#endif

#include <string.h>
#include <stdlib.h>

#define SENSOR_LASER_ID 40

/** sensor_laser_thread_handler
 *
 * @arg: arguments to the thread
 *
 * Sensor laser thread handler creates connection with laser
 * sensor module, poll for data and give callback.
 *
 **/
static void* sensor_laser_thread_handler(void *arg)
{
#ifdef _ANDROID_
  sensor_laser_obj_t *sensor_l_obj = (sensor_laser_obj_t *)arg;
  void *sensor_lib = sensor_l_obj->lib_handle;
  struct sensors_poll_device_1 *device = NULL;
  struct sensors_module_t *module = NULL;
  struct sensor_t const *list;
  int sensor_count = 0;
  sensors_event_t event;
  int num_of_events = NUMBER_OF_EVENTS_POLLED;
  sensor_laser_data_cb_t cb_event_data;
  int err;
  int count;
  int i = 0;

  pthread_setname_np(sensor_l_obj->thread_id, "CAM_laser_sens");
  /* set the thread status to ON */
  sensor_l_obj->thread_status = SENSOR_LASER_THREAD_ON;

  /* open and activate the laser sensor */
  /* Get sensor module handle */
  IS_LOW("Get sensor module handle!");
  dlerror();
  module = dlsym(sensor_lib, HAL_MODULE_INFO_SYM_AS_STR);
  if (NULL == module) {
    IS_ERR("Failure getting sensor module handle! Error: %s", dlerror());
    return NULL;
  }

  /* Update internal parameter */
  sensor_l_obj->module = module;

  /* For debugging print id and name of the hw module */
  IS_LOW("HW module: id: %s name: %s",
    sensor_l_obj->module->common.id,
    sensor_l_obj->module->common.name);

  /* Found the hardware. Call open sensor for the module */
  err = module->common.methods->open(&module->common,
    SENSORS_HARDWARE_POLL, (hw_device_t **)&device);
  if (0 != err) {
    IS_ERR("Failure opening sensor module! Error: %s!",
      strerror(-err));
    return NULL;
  }
  sensor_l_obj->device = device;


  /* Get list of sensors supported */
  sensor_count = module->get_sensors_list(module, &list);
  if (0 == sensor_count) {
    IS_ERR("0 sensor supported");
    return NULL;
  }
  sensor_l_obj->sensor_list = list;

  IS_LOW("Number of sensors supported: %d", sensor_count);

  /* There should only be one sensor but let's iterate through the count */
  for (i = 0; i < sensor_count; i++) {
    IS_LOW("name: %s\nvendor: %s\nhandle: %d\ntype: %d\nmaxRange: %f\n"
      "Resolution: %f\nPower: %f mA\nminDelay: %d\n",
      list[i].name, list[i].vendor, list[i].handle, list[i].type,
      list[i].maxRange, list[i].resolution, list[i].power,
      list[i].minDelay);

    /* Get the sensor list handle for laser sensor*/
    if (list[i].type == SENSOR_LASER_ID) {
      sensor_l_obj->sensor_handle = list[i].handle;
      sensor_l_obj->max_range = list[i].maxRange;
    }
  }


  /* Now activate the laser sensor */
  IS_LOW("Activating the laser sensor!");
  err = device->activate(&device->v0, sensor_l_obj->sensor_handle, 1);
  if (0 != err) {
    IS_LOW("Failure Activating the sensor! Error: %s", strerror(-err));
    return NULL;
  }

  IS_LOW("Start polling!");
  do {
    count = device->poll(&device->v0, &event, num_of_events);

    if (count < 0) {
      if (errno != EINTR) {
        IS_ERR("Failure polling the sensor! Error: %s", strerror(-count));
        break;
      }
    }

    IS_LOW("Laser:\n evt_timestamp:%lld"
      " version: %f mm\n type: %f\n distance: %fmm\n"
      "confidence: %f\n near_limit: %f\n far_limit: %f\n",
      event.timestamp, event.data[0], event.data[1], event.data[2],
      event.data[3], event.data[4], event.data[5])

    /* Update event cb data and send callback */
    cb_event_data.data.timestamp = event.timestamp;
    cb_event_data.data.version = event.data[0];
    cb_event_data.data.type = event.data[1];
    cb_event_data.data.distance = event.data[2];
    cb_event_data.data.confidence = event.data[3];
    cb_event_data.data.near_limit = event.data[4];
    cb_event_data.data.far_limit = event.data[5];
    cb_event_data.data.max_range = sensor_l_obj->max_range;

    /* Read laser calibration data */
    //cb_event_data.calib_offset = event.reserved1[0];
    //cb_event_data.calib_xtalk = event.reserved1[1];

    sensor_l_obj->data_cb(sensor_l_obj->cb_hndl, cb_event_data);
  } while (sensor_l_obj->thread_status == SENSOR_LASER_THREAD_ON);

#else
  /* Handle compilation warnings */
  STATS_UNUSED(arg);
#endif
  return NULL;
}



/** sensor_laser_init
 *
 *  @handle: handle
 *  @cb_handle: callback handle to be passed back
 *  @cb: data callback
 *
 *  Initialization of sensor laser module.
 *
 *    Return - sensor_laser_ret_type
 **/
sensor_laser_ret_type sensor_laser_init(
  void **handle,
  void *cb_hndl,
  sensor_laser_data_cb cb)
{
#ifdef _ANDROID_
  sensor_laser_obj_t  *sensor_l_obj = NULL;
  void *sensor_lib = NULL;
  int err = 0;
  IS_HIGH("sensor_laser_init");
  if (NULL == cb) {
    IS_ERR("Callback function is NULL!!!");
    return SENSOR_LASER_RET_BAD_PARAMS;
  }

  sensor_l_obj = calloc(1, sizeof(sensor_laser_obj_t));
  if (NULL == sensor_l_obj) {
    IS_ERR("Failure allocating memory for internal object!");
    return SENSOR_LASER_RET_NO_MEMMORY;
  }

  /* Save the input cb parameters */
  sensor_l_obj->data_cb = cb;
  sensor_l_obj->cb_hndl = cb_hndl;

  /* Open the sensor library */
  IS_HIGH("Open sensor module library: %s!", HAL_LIB_NAME_DEF);
  sensor_lib = dlopen(HAL_LIB_NAME_DEF, RTLD_LAZY);
  if (NULL == sensor_lib) {
    /* Try opening 32 bit library if present */
    IS_HIGH("Failed opening %s. Try opening %s", HAL_LIB_NAME_DEF, HAL_LIB_NAME_32);
    sensor_lib = dlopen(HAL_LIB_NAME_32, RTLD_LAZY);
    if (NULL == sensor_lib) {
      IS_ERR("Failure opening sensor library! Error: %s", dlerror());
      free(sensor_l_obj);
      sensor_l_obj = NULL;
      return SENSOR_LASER_RET_HW_NOT_FOUND;
    }
  }
  sensor_l_obj->lib_handle = sensor_lib;


  /* Initialize and create sensor laser thread to poll the data */
  pthread_create(&sensor_l_obj->thread_id, NULL, sensor_laser_thread_handler,
    (void *)sensor_l_obj);


  *handle = (void *)sensor_l_obj;
  return SENSOR_LASER_RET_SUCCESS;
#else
  /* Handle compilation warnings */
  STATS_UNUSED(handle);
  STATS_UNUSED(cb_hndl);
  STATS_UNUSED(cb);
  return SENSOR_LASER_RET_FAILURE;
#endif
}


/** sensor_laser_deinit
 *
 *  @handle: handle
 *
 *  Deinitialize sensor laser module.
 *
 *    Return - sensor_laser_ret_type
 **/
sensor_laser_ret_type sensor_laser_deinit(void *handle)
{
#ifdef _ANDROID_
  sensor_laser_obj_t *sensor_l_obj = (sensor_laser_obj_t *)handle;

  if (NULL == sensor_l_obj) {
    IS_ERR("Invalid object!");
    return SENSOR_LASER_RET_BAD_PARAMS;
  }

  /*Stop the thread */
  IS_LOW("Updating SENSOR thread status to OFF");
  sensor_l_obj->thread_status = SENSOR_LASER_THREAD_OFF;

  IS_LOW("Waiting for thread to join!");
  pthread_join(sensor_l_obj->thread_id, NULL);

  if (NULL != sensor_l_obj->device) {
    /* Deactivate the sensor */
    IS_LOW("Deactivate");
    sensor_l_obj->device->activate(&sensor_l_obj->device->v0, sensor_l_obj->sensor_handle, 0);

    IS_LOW("Device flush");
    sensor_l_obj->device->flush(sensor_l_obj->device, sensor_l_obj->sensor_handle);

    /* Close the sensor */
    sensor_l_obj->device->common.close((hw_device_t *)&sensor_l_obj->device->common);
  }


  if (NULL != sensor_l_obj->lib_handle) {
    /* Unload the dynamic library loaded */
    dlclose(sensor_l_obj->lib_handle);
  }

  /* Free all the allocated memories */
  free(sensor_l_obj);

  return SENSOR_LASER_RET_SUCCESS;
#else
  /* Handle compilation warnings */
  STATS_UNUSED(handle);
  return SENSOR_LASER_RET_FAILURE;
#endif
}
