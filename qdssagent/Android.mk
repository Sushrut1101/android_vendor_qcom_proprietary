################################################################################
# @brief Makefile for installing shell scripts in /persist/coresight
################################################################################

LOCAL_PATH:= $(call my-dir)

QDSS_AGENT_PATH := $(PRODUCT_OUT)/persist/coresight

# Begin a new app with CLEAR_VARS
include $(CLEAR_VARS)

LOCAL_MODULE := qdss.agent.sh
LOCAL_SRC_FILES:=  $(LOCAL_MODULE)
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(QDSS_AGENT_PATH)

ifneq (,$(findstring $(PLATFORM_VERSION), 9 8.0 8.1 7.0 7.1 6.0))
    LOCAL_MODULE_TAGS := debug
endif
include $(BUILD_PREBUILT)

# Begin a new app with CLEAR_VARS
include $(CLEAR_VARS)

LOCAL_MODULE := qdss.config.sh
LOCAL_SRC_FILES:=  $(LOCAL_MODULE)
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(QDSS_AGENT_PATH)

ifneq (,$(findstring $(PLATFORM_VERSION), 9 8.0 8.1 7.0 7.1 6.0))
    LOCAL_MODULE_TAGS := debug
endif

include $(BUILD_PREBUILT)

# Begin a new app with CLEAR_VARS
include $(CLEAR_VARS)

LOCAL_MODULE := qdss.functions.sh
LOCAL_SRC_FILES:=  $(LOCAL_MODULE)
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(QDSS_AGENT_PATH)

ifneq (,$(findstring $(PLATFORM_VERSION), 9 8.0 8.1 7.0 7.1 6.0))
    LOCAL_MODULE_TAGS := debug
endif

include $(BUILD_PREBUILT)
