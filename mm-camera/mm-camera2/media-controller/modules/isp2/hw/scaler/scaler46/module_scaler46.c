/* module_scaler46.c
 *
 * Copyright (c) 2012-2016 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

/* std headers */
#include <stdio.h>

/* mctl headers */
#include "media_controller.h"
#include "mct_list.h"
#include "mct_module.h"
#include "mct_port.h"
#include "chromatix.h"

/* isp headers */
#include "isp_sub_module_common.h"
#include "isp_common.h"
#include "isp_sub_module_log.h"
#include "port_scaler46.h"
#include "module_scaler46.h"
#include "scaler46.h"
#include "scaler46_util.h"

#undef ISP_DBG
#define ISP_DBG(fmt, args...) \
  ISP_DBG_MOD(ISP_LOG_SCALER, fmt, ##args)
#undef ISP_HIGH
#define ISP_HIGH(fmt, args...) \
  ISP_HIGH_MOD(ISP_LOG_SCALER, fmt, ##args)

/* TODO pass from Android.mk */
#define SCALER46_VERSION "46"

#define SCALER46_VIEWFINDER_NAME(n) \
  "scaler_viewfinder"n

#define SCALER46_ENCODER_NAME(n) \
  "scaler_encoder"n

#define SCALER46_VIDEO_NAME(n) \
  "scaler_video"n

/** module_scaler46_set_mod:
 *
 *  @module: module handle
 *  @module_type: module type
 *  @identity: identity of stream
 *
 *  Handle set mod
 *
 *  Returns void
 **/
static void module_scaler46_set_mod(mct_module_t *module,
  unsigned int module_type, unsigned int identity)
{
  if (!module) {
    ISP_ERR("failed: module %p", module);
    return;
  }
  mct_module_add_type(module, module_type, identity);
  return;
}

/** module_scaler46_query_mod:
 *
 *  @module: module handle
 *  @query_buf: query caps buffer handle
 *  @sessionid: session id
 *
 *  Handle query mod
 *
 *  Returns TRUE on success and FALSE on failure
 **/
static boolean module_scaler46_query_mod(mct_module_t *module,
  void *query_buf, unsigned int sessionid)
{
  boolean ret = TRUE;

  if (!module || !query_buf) {
    ISP_ERR("failed: %p %p", module, query_buf);
    return FALSE;
  }

  ret = isp_zoom_query_mod_func((mct_pipeline_cap_t *)query_buf);
  if (ret == FALSE) {
    ISP_ERR("failed: isp_zoom_query_mod_func");
  }
  return ret;
}

/** module_scaler46_start_session:
 *
 *  @module: module handle
 *  @sessionid: session id
 *
 *  Handle start session
 *
 *  Returns TRUE on success and FALSE on failure
 **/
static boolean module_scaler46_start_session(mct_module_t *module,
  unsigned int session_id)
{
  boolean       ret = TRUE;
  scaler46_t *scaler = NULL;

  if (!module) {
    ISP_ERR("failed: module %p", module);
    return FALSE;
  }

  ISP_HIGH("module %p", module);
  PTHREAD_MUTEX_LOCK(MCT_OBJECT_GET_LOCK(module));
  scaler = MCT_OBJECT_PRIVATE(module);

  /* Initialize hw stream specific params */
  if (!strncmp(MCT_MODULE_NAME(module),
       SCALER46_VIEWFINDER_NAME(SCALER46_VERSION),
       strlen(MCT_MODULE_NAME(module)))) {
    ISP_HIGH("viewfinder");
    scaler->entry_idx = ISP_HW_STREAM_VIEWFINDER;
    scaler->hw_module_id = ISP_MOD_SCALER_VIEWFINDER;
    scaler->reg_off = ISP_SCALER46_VIEW_OFF;
    scaler->reg_len = ISP_SCALER46_VIEW_LEN;
  } else if (!strncmp(MCT_MODULE_NAME(module),
              SCALER46_ENCODER_NAME(SCALER46_VERSION),
              strlen(MCT_MODULE_NAME(module)))) {
    ISP_HIGH("encoder");
    scaler->entry_idx = ISP_HW_STREAM_ENCODER;
    scaler->hw_module_id = ISP_MOD_SCALER_ENCODER;
    scaler->reg_off = ISP_SCALER46_ENC_OFF;
    scaler->reg_len = ISP_SCALER46_ENC_LEN;
  } else if (!strncmp(MCT_MODULE_NAME(module),
              SCALER46_VIDEO_NAME(SCALER46_VERSION),
              strlen(MCT_MODULE_NAME(module)))) {
    ISP_HIGH("video");
    scaler->entry_idx = ISP_HW_STREAM_VIDEO;
    scaler->hw_module_id = ISP_MOD_SCALER_VIDEO;
    scaler->reg_off = ISP_SCALER46_VIDEO_OFF;
    scaler->reg_len = ISP_SCALER46_VIDEO_LEN;
  } else {
    ISP_ERR("failed: invalid module name %s", MCT_MODULE_NAME(module));
  }

  ret = isp_zoom_init(&scaler->zoom, session_id, ISP_VERSION_46);
  if (ret == FALSE) {
    ISP_ERR("failed: isp_zoom_init");
  }

  PTHREAD_MUTEX_UNLOCK(MCT_OBJECT_GET_LOCK(module));

  return ret;

ERROR:
  ISP_ERR("failed: module_scaler46_start_session");
  return ret;
}

/** module_scaler46_stop_session:
 *
 *  @module: module handle
 *  @session_id: session id
 *
 *  Handle stop session
 *
 *  Returns TRUE on success and FALSE on failure
 **/
static boolean module_scaler46_stop_session(mct_module_t *module,
  unsigned int session_id)
{
  boolean       ret = TRUE;
  scaler46_t *scaler = NULL;

  if (!module) {
    ISP_ERR("failed: module %p", module);
    return FALSE;
  }

  PTHREAD_MUTEX_LOCK(MCT_OBJECT_GET_LOCK(module));



  PTHREAD_MUTEX_UNLOCK(MCT_OBJECT_GET_LOCK(module));

  return TRUE;
}

/** module_scaler46_pass_scale_factor
 *
 *  @module: module ctrl handle
 *  @scaler: scaler ctrl handle
 *  @isStreamOff: is this a stream off case
 *
 *  Store chromatix ptr to be used later for interpolation
 *
 *  Return TRUE on success and FALS on failure
 **/
boolean module_scaler46_pass_scale_factor(mct_module_t *module,
  scaler46_t *scaler, boolean is_stream_on, uint32_t identity)
{
  mct_event_t                 mct_event;
  isp_private_event_t         private_event;
  scaler_scale_factor_for_cac cac_scale_factor;

  if (!module || !scaler) {
    ISP_ERR("failed: %p %p",module,scaler);
    return FALSE;
  }
  memset(&mct_event, 0, sizeof(mct_event_t));
  memset(&private_event, 0, sizeof(isp_private_event_t));

  cac_scale_factor.index = scaler->entry_idx;
  cac_scale_factor.scale_factor = scaler->scalers.scaling_factor;
  cac_scale_factor.is_stream_on = is_stream_on;

  /*Send info about crop factor. Handled in CAC*/
  ISP_DBG("E: Fetch info about whether fovcrop has requested for crop");
  private_event.type = ISP_PRIVATE_PASS_SCALER_SCALE_FACTOR;
  private_event.data = (void *)&cac_scale_factor;
  private_event.data_size = sizeof(cac_scale_factor);

  mct_event.identity = identity;
  mct_event.type = MCT_EVENT_MODULE_EVENT;
  mct_event.direction = MCT_EVENT_UPSTREAM;
  mct_event.u.module_event.type = MCT_EVENT_MODULE_ISP_PRIVATE_EVENT;
  mct_event.u.module_event.module_event_data = (void *)&private_event;
  scaler46_util_send_event(module, &mct_event);

  return TRUE;
}

/** module_scaler46_overwrite_funcs:
 *
 *  @module: module handle
 *
 *  Overwrite functions with scaler 46 specific
 *
 *  Returns nothing
 **/
static void module_scaler46_overwrite_funcs(mct_module_t *module)
{
  if (!module) {
    ISP_ERR("failed: module %p", module);
    return;
  }
  mct_module_set_set_mod_func(module, module_scaler46_set_mod);
  mct_module_set_query_mod_func(module, module_scaler46_query_mod);
  mct_module_set_start_session_func(module, module_scaler46_start_session);
  mct_module_set_stop_session_func(module, module_scaler46_stop_session);
}

/** module_scaler46_init:
 *
 *    @name: name of ISP module - "scaler46"
 *
 * Initializes new instance of ISP module
 * create mct module for scaler
 *
 * Return mct module handle on success or NULL on failure
 **/
static mct_module_t *module_scaler46_init(const char *name)
{
  boolean       ret = TRUE;
  mct_module_t *module = NULL;
  scaler46_t *scaler = NULL;

  ret = scaler46_util_setloglevel("scaler", ISP_LOG_SCALER);
  if (ret == FALSE) {
    ISP_ERR("failed: fovcrop46_util_setloglevel");
  }
  ISP_HIGH("name %s", name);

  if (!name) {
    ISP_ERR("failed: name %p", name);
    return NULL;
  }

  if (strncmp(name, SCALER46_VIEWFINDER_NAME(SCALER46_VERSION), strlen(name)) &&
      strncmp(name, SCALER46_ENCODER_NAME(SCALER46_VERSION), strlen(name)) &&
      strncmp(name, SCALER46_VIDEO_NAME(SCALER46_VERSION), strlen(name))) {
    ISP_ERR("failed: invalid name %s expected %s or %s or %s", name,
      SCALER46_VIEWFINDER_NAME(SCALER46_VERSION),
      SCALER46_ENCODER_NAME(SCALER46_VERSION),
      SCALER46_VIDEO_NAME(SCALER46_VERSION));
    return NULL;
  }

  /* Create MCT module for scaler46 */
  module = mct_module_create(name);
  if (!module) {
    ISP_ERR("failed: mct_module_create");
    return NULL;
  }

  /* Create ports */
  ret = port_scaler46_create(module);
  if (ret == FALSE) {
    ISP_ERR("failed: port_isp_create");
    goto ERROR;
  }

  /* Overwrite module functions */
  module_scaler46_overwrite_funcs(module);


  scaler = (scaler46_t *)CAM_MALLOC(sizeof(*scaler));
  if (!scaler) {
    ISP_ERR("failed: scaler %p", scaler);
    return FALSE;
  }
  memset(scaler, 0, sizeof(*scaler));

  /* Initialize max scale factor */
  scaler->max_scale_factor = 1.0f;
  scaler->hw_stream_info.fmt = CAM_FORMAT_MAX;

  MCT_OBJECT_PRIVATE(module) = (void *)scaler;

  pthread_mutex_init(&scaler->mutex, NULL);

  ISP_HIGH("module %p", module);
  return module;

ERROR:
  ISP_ERR("failed: module_scaler46_init");
  port_scaler46_delete_ports(module);
  free(scaler);
  mct_module_destroy(module);
  return NULL;
}

/** module_scaler46_deinit:
 *
 *  @module: isp module handle
 *
 *  Deinit isp module
 *
 *  Returns: void
 **/
static void module_scaler46_deinit(mct_module_t *module)
{
  scaler46_t *scaler = NULL;
  if (!module) {
    ISP_ERR("failed: module %p", module);
    return;
  }

  scaler = MCT_OBJECT_PRIVATE(module);
  if (!scaler) {
    ISP_ERR("failed: scaler %p", scaler);
    return;
  }
  pthread_mutex_destroy(&scaler->mutex);
  free(scaler);
  MCT_OBJECT_PRIVATE(module) = NULL;

  /* Delete source and sink ports */
  port_scaler46_delete_ports(module);

  /* Destroy mct module */
  mct_module_destroy(module);
}

static isp_submod_init_table_t submod_init_table = {
  .module_init = module_scaler46_init,
  .module_deinit = module_scaler46_deinit,
};

isp_submod_init_table_t *module_open(void)
{
  return &submod_init_table;
}
