LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

BDROID_DIR := system/bt

LOCAL_MODULE := libbthost_if
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_OWNER := qti
LOCAL_MODULE_TAGS := optional
LOCAL_PROPRIETARY_MODULE := true

LOCAL_SRC_FILES := bthost_ipc.cpp

LOCAL_C_INCLUDES += \
    $(LOCAL_PATH)/bthost_ipc.h \
    $(TOP)/system/media/audio/include

LOCAL_SHARED_LIBRARIES := \
    liblog \
    libcutils \
    libutils \
    libhidlbase \
    android.hardware.bluetooth.a2dp@1.0

ifdef TARGET_2ND_ARCH
LOCAL_MODULE_PATH_32 := $(TARGET_OUT_VENDOR)/lib
LOCAL_MODULE_PATH_64 := $(TARGET_OUT_VENDOR)/lib64
else
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR_SHARED_LIBRARIES)
endif

include $(BUILD_SHARED_LIBRARY)
