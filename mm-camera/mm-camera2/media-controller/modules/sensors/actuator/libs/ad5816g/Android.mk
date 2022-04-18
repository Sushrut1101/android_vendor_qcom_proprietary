LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE_TAGS := optional

LOCAL_LDFLAGS := $(mmcamera_debug_lflags)

LOCAL_CFLAGS :=  -DAMSS_VERSION=$(AMSS_VERSION) \
  $(mmcamera_debug_defines) \
  $(mmcamera_debug_cflags)

LOCAL_C_INCLUDES = ad5816g_actuator.h
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../../../mm-camerasdk/sensor/includes/

LOCAL_SRC_FILES := ad5816g_actuator.c

LOCAL_MODULE           := libactuator_ad5816g
LOCAL_SHARED_LIBRARIES := libcutils

ifeq ($(MM_DEBUG),true)
LOCAL_SHARED_LIBRARIES += liblog
endif

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

ifeq ($(32_BIT_FLAG), true)
LOCAL_32_BIT_ONLY := true
endif

include $(BUILD_SHARED_LIBRARY)
