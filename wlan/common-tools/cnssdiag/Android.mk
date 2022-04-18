LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := cnss_diag
ifeq ($(PRODUCT_VENDOR_MOVE_ENABLED),true)
LOCAL_PROPRIETARY_MODULE := true
endif
LOCAL_CLANG := true
LOCAL_MODULE_TAGS := optional
LOCAL_C_INCLUDES := $(TARGET_OUT_HEADERS)/diag/include
LOCAL_C_INCLUDES += external/libnl/include
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/common/inc
ifneq ($(TARGET_SUPPORTS_WEARABLES),true)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../opensource/time-services/
else
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../device/qcom/msm8909w/opensource/time-services/
endif
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/cld80211-lib
LOCAL_SHARED_LIBRARIES := libc libcutils libdiag libhardware_legacy libtime_genoff libnl libcld80211
LOCAL_SRC_FILES := cld-fwlog-netlink.c parser.c nan-parser.c cld-diag-parser.c
LOCAL_CFLAGS += -DCONFIG_ANDROID_LOG
LOCAL_CFLAGS += -DANDROID -Wall -Werror -Wno-unused-parameter
LOCAL_CFLAGS += -DCONFIG_CLD80211_LIB
ifeq ($(TARGET_USES_QCOM_BSP),true)
LOCAL_CFLAGS += -DQCOM_BSP
endif
LOCAL_LDLIBS += -llog
LOCAL_SANITIZE := integer_overflow
include $(BUILD_EXECUTABLE)
