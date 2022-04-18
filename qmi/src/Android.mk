LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libqmi_headers
LOCAL_SANITIZE:=integer_overflow

LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/../inc
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/../platform
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/../qmi_client_helper
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/../services
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/../core/lib/inc

LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_HEADER_LIBRARY)

include $(CLEAR_VARS)

LOCAL_COPY_HEADERS_TO   := qmi/inc

LOCAL_COPY_HEADERS      += qmi_i.h
LOCAL_COPY_HEADERS      += qmi_qmux.h
LOCAL_COPY_HEADERS      += qmi_qmux_if.h
LOCAL_COPY_HEADERS      += qmi_qos_srvc_i.h
LOCAL_COPY_HEADERS      += qmi_service.h
LOCAL_COPY_HEADERS      += qmi_wds_srvc_i.h

LOCAL_COPY_HEADERS      += ../inc/qmi_atcop_srvc.h
LOCAL_COPY_HEADERS      += ../inc/qmi_eap_srvc.h
LOCAL_COPY_HEADERS      += ../inc/qmi.h
LOCAL_COPY_HEADERS      += ../inc/qmi_errors.h
LOCAL_COPY_HEADERS      += ../inc/qmi_nas_srvc.h
LOCAL_COPY_HEADERS      += ../inc/qmi_qos_srvc.h
LOCAL_COPY_HEADERS      += ../inc/qmi_wds_srvc.h
LOCAL_COPY_HEADERS      += ../inc/qmi_wds_utils.h
LOCAL_COPY_HEADERS      += ../inc/qmi_port_defs.h

LOCAL_COPY_HEADERS      += ../platform/qmi_platform_config.h
LOCAL_COPY_HEADERS      += ../platform/qmi_platform.h
LOCAL_COPY_HEADERS      += ../platform/qmi_platform_qmux_if.h
LOCAL_COPY_HEADERS      += ../platform/qmi_platform_qmux_io.h

LOCAL_COPY_HEADERS      += ../qmi_client_helper/qmi_client_helper.h

LOCAL_COPY_HEADERS      += ../services/common_v01.h
LOCAL_COPY_HEADERS      += ../services/qmi_adc_service_v01.h
LOCAL_COPY_HEADERS      += ../services/sar_vs_service_v01.h
LOCAL_COPY_HEADERS      += ../core/lib/inc/qmi_idl_lib.h
LOCAL_COPY_HEADERS      += ../core/lib/inc/qmi_idl_lib_internal.h
LOCAL_COPY_HEADERS      += ../services/lowi_service_v01.h
LOCAL_COPY_HEADERS      += ../services/secure_filesystem_service_v01.h
LOCAL_COPY_HEADERS      += ../services/bandwidth_limits_management_v01.h


LOCAL_CFLAGS += -DFEATURE_QMI_ANDROID
LOCAL_CFLAGS += -DFEATURE_QMI_IWLAN

# Logging Features. Turn any one ON at any time

#LOCAL_CFLAGS  += -DFEATURE_DATA_LOG_STDERR
#LOCAL_CFLAGS += -DFEATURE_DATA_LOG_ADB
LOCAL_CFLAGS += -DFEATURE_DATA_LOG_QXDM
LOCAL_CFLAGS += -g


LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/..
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../qmuxd
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../platform
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../core/lib/inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../services
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../proxy
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/common/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/data/inc

LOCAL_SRC_FILES += qmi_service.c
LOCAL_SRC_FILES += qmi.c
LOCAL_SRC_FILES += qmi_errors.c
LOCAL_SRC_FILES += qmi_wds_srvc.c
LOCAL_SRC_FILES += qmi_qos_srvc.c
LOCAL_SRC_FILES += qmi_nas_srvc.c
LOCAL_SRC_FILES += qmi_eap_srvc.c
LOCAL_SRC_FILES += qmi_atcop_srvc.c
LOCAL_SRC_FILES += qmi_wds_utils.c

LOCAL_SHARED_LIBRARIES = libcutils
LOCAL_SHARED_LIBRARIES += libqmi_client_qmux
LOCAL_SHARED_LIBRARIES += libdiag
LOCAL_SHARED_LIBRARIES += libdsutils
LOCAL_SHARED_LIBRARIES += libqmiservices
LOCAL_SHARED_LIBRARIES += libidl
LOCAL_SHARED_LIBRARIES += liblog

LOCAL_HEADER_LIBRARIES += libril-qc-qmi-services-headers
LOCAL_HEADER_LIBRARIES += libqmi_cci_headers
LOCAL_HEADER_LIBRARIES += libdiag_headers

LOCAL_MODULE := libqmi
LOCAL_SANITIZE:=integer_overflow

LOCAL_MODULE_TAGS := optional

LOCAL_CLANG := true

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE_OWNER := qcom
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)
