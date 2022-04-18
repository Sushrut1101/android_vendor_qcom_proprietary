LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := vendor.qti.hardware.btconfigstore@1.0-impl
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_RELATIVE_PATH := hw

LOCAL_SRC_FILES := \
    BTConfigStore.cpp \

BT_HAL_DIR:= vendor/qcom/proprietary/bluetooth/hidl_transport/bt/1.0/default
LOCAL_C_INCLUDES += $(BT_HAL_DIR)
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/common/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/diag/include
LOCAL_C_INCLUDES += vendor/qcom/opensource/commonsys-intf/bluetooth/include

LOCAL_SHARED_LIBRARIES := \
    libbase \
    libcutils \
    libhidlbase \
    libhidltransport \
    liblog \
    libhwbinder \
    libutils \
    vendor.qti.hardware.btconfigstore@1.0 \
    android.hardware.bluetooth@1.0-impl-qti

include $(BUILD_SHARED_LIBRARY)