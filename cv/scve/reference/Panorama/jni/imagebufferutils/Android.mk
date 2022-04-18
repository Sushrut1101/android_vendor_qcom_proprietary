LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE           := libpanoramaref_imagebufferutils
LOCAL_CFLAGS     := -fvisibility=hidden -fvisibility-inlines-hidden
LOCAL_SHARED_LIBRARIES := libjnigraphics
LOCAL_SRC_FILES  := imagebufferutils.cpp

include vendor/qcom/proprietary/scve/reference/common.mk

LOCAL_PRIVATE_PLATFORM_APIS := true

include $(BUILD_SHARED_LIBRARY)
