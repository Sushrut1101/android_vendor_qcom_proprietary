LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_LDFLAGS := $(mmcamera_debug_lflags)

LOCAL_CFLAGS := -DAMSS_VERSION=$(AMSS_VERSION) \
  $(mmcamera_debug_defines) \
  $(mmcamera_debug_cflags)
LOCAL_CFLAGS += -Werror

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../../../../../mm-camerasdk/sensor/includes/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../sensors/module/
LOCAL_C_INCLUDES += ov13850_q13v06k_lib.h

LOCAL_HEADER_LIBRARIES := libutils_headers
LOCAL_SRC_FILES        := ov13850_q13v06k_lib.c
LOCAL_MODULE           := libmmcamera_ov13850_q13v06k
include $(SDCLANG_COMMON_DEFS)
LOCAL_SHARED_LIBRARIES := libcutils
LOCAL_SHARED_LIBRARIES += liblog

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

ifeq ($(32_BIT_FLAG), true)
LOCAL_32_BIT_ONLY := true
endif
include $(BUILD_SHARED_LIBRARY)
