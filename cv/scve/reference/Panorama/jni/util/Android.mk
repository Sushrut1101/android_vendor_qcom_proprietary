LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE     := libpanoramaref_util
LOCAL_SRC_FILES  := throw_exception.cpp

include vendor/qcom/proprietary/scve/reference/common.mk

LOCAL_PRIVATE_PLATFORM_APIS := true

include $(BUILD_STATIC_LIBRARY)
