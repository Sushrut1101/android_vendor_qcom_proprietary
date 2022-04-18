LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := $(call all-subdir-java-files)

LOCAL_C_INCLUDES += \
        $(JNI_H_INCLUDE) \
        $(TARGET_OUT_HEADERS)/common/inc \
        $(TARGET_OUT_HEADERS)/diag/include \

commonSharedLibraries :=libdiag
LOCAL_STATIC_LIBRARIES += libdiagjni

LOCAL_PRELINK_MODULE := false
LOCAL_MODULE:= libdiagwrapper

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_STATIC_JAVA_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := com.qualcomm.qti.diagservice.libdiagwrapper.xml

LOCAL_MODULE_CLASS := ETC

LOCAL_SRC_FILES := $(LOCAL_MODULE)

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_PREBUILT)
