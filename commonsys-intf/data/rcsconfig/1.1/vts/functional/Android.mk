LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE        := VtsImsRcsConfigTest_IFactoryV2_1
LOCAL_MODULE_TAGS   := optional
LOCAL_CFLAGS        := -O0 -g

LOCAL_SRC_FILES     += VtsImsRcsConfigTest_IFactoryV2_1.cpp

LOCAL_SHARED_LIBRARIES := liblog \
                          libhidlbase \
                          libhidltransport \
                          libutils \
                          libz \
                          vendor.qti.data.factory@2.0 \
                          vendor.qti.ims.rcsconfig@1.0 \
                          vendor.qti.data.factory@2.1 \
                          vendor.qti.ims.rcsconfig@1.1 \

LOCAL_STATIC_LIBRARIES := VtsHalHidlTargetTestBase

LOCAL_MODULE_OWNER := qti

include $(BUILD_NATIVE_TEST)
