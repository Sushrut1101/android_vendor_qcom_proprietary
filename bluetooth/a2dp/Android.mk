ifeq ($(BOARD_HAVE_BLUETOOTH_QCOM),true)
ifeq ($(TARGET_HAS_SPLIT_A2DP_FEATURE),true)
LOCAL_PATH := $(call my-dir)
include $(LOCAL_PATH)/1.0/default/Android.mk
endif # TARGET_HAS_SPLIT_A2DP_FEATURE
endif # BOARD_HAVE_BLUETOOTH_QCOM
