#======================================================================
#makefile for libmmcamera2_isp2_bcc44.so form mm-camera2
#======================================================================
ifeq ($(call is-vendor-board-platform,QCOM),true)
BOARD_PLATFORM_LIST := apq8084
BOARD_PLATFORM_LIST += msm8994
BOARD_PLATFORM_LIST += msm8992

ifeq ($(call is-board-platform-in-list, $(BOARD_PLATFORM_LIST)),true)

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_LDFLAGS := $(mmcamera_debug_lflags)

LOCAL_CFLAGS :=  -DAMSS_VERSION=$(AMSS_VERSION) \
  $(mmcamera_debug_defines) \
  $(mmcamera_debug_cflags)

ifeq ($(BOARD_QTI_CAMERA_V2),false)
  LOCAL_CFLAGS  += -Werror
endif

LOCAL_MMCAMERA_PATH := $(LOCAL_PATH)/../../../../../../

LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/includes/

LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/server-tuning/tuning/

LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/includes/

LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/mct/bus/
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/mct/controller/
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/mct/event/
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/mct/module/
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/mct/object/
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/mct/pipeline/
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/mct/port/
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/mct/stream/
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/mct/tools/

LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/modules/includes/
LOCAL_C_INCLUDES += $(LOCAL_CHROMATIX_PATH)

LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/modules/isp2/common/
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/modules/isp2/hw/sub_module
LOCAL_C_INCLUDES += $(SRC_CAMERA_HAL_DIR)/QCamera2/stack/common
ifeq ($(call is-board-platform-in-list, msm8974 msm8226 apq8084 msm8992),true)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include44
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/modules/isp2/module/isp44
else
ifeq ($(call is-board-platform-in-list, msm8994),true)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include46
LOCAL_C_INCLUDES += $(LOCAL_MMCAMERA_PATH)/media-controller/modules/isp2/module/isp46
endif
endif

LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/include/mm-camera-interface
ifeq ($(TARGET_COMPILE_WITH_MSM_KERNEL),true)
LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr
endif

LOCAL_SRC_FILES        := module_bcc44.c bcc44.c

LOCAL_MODULE           := libmmcamera_isp_bcc44
LOCAL_SHARED_LIBRARIES := libcutils \
                          libmmcamera2_mct \
                          libmmcamera_isp_sub_module \
                          libmmcamera_dbg \
                          libmmcamera2_isp_modules

ifeq ($(MM_DEBUG),true)
LOCAL_SHARED_LIBRARIES += liblog
endif

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

ifeq ($(32_BIT_FLAG), true)
LOCAL_32_BIT_ONLY := true
endif

include $(BUILD_SHARED_LIBRARY)

endif # if 8974 8226
endif # is-vendor-board-platform,QCOM
