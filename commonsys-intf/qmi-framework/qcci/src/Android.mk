LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_COPY_HEADERS_TO   := qmi-framework/inc
LOCAL_COPY_HEADERS      += ../inc/qmi_cci_target.h
LOCAL_COPY_HEADERS      += ../inc/qmi_cci_common.h

LOCAL_COPY_HEADERS      += ../../inc/common_v01.h
LOCAL_COPY_HEADERS      += ../../inc/qmi_cci_target_ext.h
LOCAL_COPY_HEADERS      += ../../inc/qmi_client.h
LOCAL_COPY_HEADERS      += ../../inc/qmi_client_deprecated.h
LOCAL_COPY_HEADERS      += ../../inc/qmi_csi.h
LOCAL_COPY_HEADERS      += ../../inc/qmi_csi_target_ext.h
LOCAL_COPY_HEADERS      += ../../inc/qmi_idl_lib.h
LOCAL_COPY_HEADERS      += ../../inc/qmi_idl_lib_internal.h
LOCAL_COPY_HEADERS      += ../../inc/qmi_idl_lib_target.h
LOCAL_COPY_HEADERS      += ../../inc/qmi_client_instance_defs.h

common_libqcci_cflags := -g
common_libqcci_cflags += -O2
common_libqcci_cflags += -fno-inline
common_libqcci_cflags += -fno-short-enums
common_libqcci_cflags += -fpic
common_libqcci_cflags += -Wno-unused-parameter

LOCAL_CFLAGS := $(common_libqcci_cflags)
LOCAL_CFLAGS += -DQMI_FW_ANDROID
LOCAL_CFLAGS += -DQMI_FW_ADB_LOG
LOCAL_CFLAGS += -DQCCI_OVER_QMUX
LOCAL_CFLAGS += -DQMI_CCI_ANDROID
LOCAL_CFLAGS += -DQMI_CCI_SMEM_LOG_DISABLE

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../common/inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../smem_log
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qmi/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qsocket/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/libmdmdetect/inc/
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qrtr/inc/

LOCAL_HEADER_LIBRARIES := libcutils_headers

LOCAL_SRC_FILES  := qmi_cci_common.c
LOCAL_SRC_FILES  += qmi_cci_target.c
LOCAL_SRC_FILES  += qmi_cci_xport_ipc_router.c
LOCAL_SRC_FILES  += qmi_cci_xport_qmuxd.c
LOCAL_SRC_FILES  += qmi_cci_xport_qrtr.c

LOCAL_SHARED_LIBRARIES := libcutils
LOCAL_SHARED_LIBRARIES += libutils
LOCAL_SHARED_LIBRARIES += libqmi_encdec
LOCAL_SHARED_LIBRARIES += libqmi_client_qmux
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libmdmdetect

LOCAL_STATIC_LIBRARIES := libqmi_common

LOCAL_SANITIZE := integer_overflow

LOCAL_MODULE := libqmi_cci

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

#System Library
include $(CLEAR_VARS)

common_libqcci_cflags := -g
common_libqcci_cflags += -O2
common_libqcci_cflags += -fno-inline
common_libqcci_cflags += -fno-short-enums
common_libqcci_cflags += -fpic
common_libqcci_cflags += -Wno-unused-parameter

LOCAL_CFLAGS := $(common_libqcci_cflags)
LOCAL_CFLAGS += -DQMI_FW_ADB_LOG
LOCAL_CFLAGS += -DQMI_CCI_ANDROID
LOCAL_CFLAGS += -DQMI_CCI_SMEM_LOG_DISABLE
LOCAL_CFLAGS += -DQMI_CCI_SYSTEM

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../common/inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../smem_log
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qsocket/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qrtr/inc/

LOCAL_SRC_FILES  := qmi_cci_common.c
LOCAL_SRC_FILES  += qmi_cci_target.c
LOCAL_SRC_FILES  += qmi_cci_xport_ipc_router.c
LOCAL_SRC_FILES  += qmi_cci_xport_qrtr.c

LOCAL_SHARED_LIBRARIES := libcutils
LOCAL_SHARED_LIBRARIES += libutils
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_STATIC_LIBRARIES := libqmi_common_system
LOCAL_STATIC_LIBRARIES += libqmi_encdec_system

LOCAL_SANITIZE := integer_overflow

LOCAL_MODULE := libqmi_cci_system

LOCAL_PRELINK_MODULE := false

include $(BUILD_SHARED_LIBRARY)

# Header library
include $(CLEAR_VARS)

LOCAL_MODULE := libqmi_cci_headers

LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/../../common/inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/../../inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/../inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/../../smem_log

include $(BUILD_HEADER_LIBRARY)
