SUNNY_S5K2L7SX_EEPROM_LIBS_PATH := $(call my-dir)

# ---------------------------------------------------------------------------
#        Make the shared library (libmmcamera_sunny_gt24c64_s5k2l7sx_eeprom.so)
# ---------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_PATH := $(SUNNY_S5K2L7SX_EEPROM_LIBS_PATH)
LOCAL_MODULE_TAGS := optional
LOCAL_LDFLAGS := $(mmcamera_debug_lflags)

LOCAL_CFLAGS := -DAMSS_VERSION=$(AMSS_VERSION) \
  $(mmcamera_debug_defines) \
  $(mmcamera_debug_cflags)

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../../../mm-camerasdk/sensor/includes/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../../../mm-camerasdk/sensor/includes/$(CHROMATIX_VERSION)

LOCAL_HEADER_LIBRARIES := libutils_headers
LOCAL_SRC_FILES:= sunny_gt24c64_s5k2l7sx_eeprom.c
LOCAL_MODULE           := libmmcamera_sunny_gt24c64_s5k2l7sx_eeprom
LOCAL_SHARED_LIBRARIES := liblog libcutils libmmcamera_eeprom_util

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

ifeq ($(32_BIT_FLAG), true)
LOCAL_32_BIT_ONLY := true
endif

include $(BUILD_SHARED_LIBRARY)
