################################################################################
# @file ssr_diag/Android.mk
# @brief Makefile for building the ssr diag API on Android.
################################################################################

ifeq ($(call is-vendor-board-platform,QCOM),true)

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

libdiag_includes:= \
	$(TARGET_OUT_HEADERS)/diag/include \
        $(LOCAL_PATH)/../../diag/include \
	$(LOCAL_PATH)/../../diag/src

LOCAL_C_INCLUDES:= $(libdiag_includes)
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/common/inc

LOCAL_SRC_FILES:= \
	ssr_diag_main.c

commonSharedLibraries :=libdiag

LDLIBS += -lpthread
LOCAL_MODULE:= ssr_diag
LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES += $(commonSharedLibraries) libcutils libutils liblog

LOCAL_MODULE_OWNER := qcom
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_EXECUTABLE)

endif
