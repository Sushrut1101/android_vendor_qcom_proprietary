LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CFLAGS += -DFEATURE_DATA_LOG_QXDM

filetoadd = bionic/libc/kernel/arch-arm/asm/posix_types.h
LOCAL_CFLAGS += $(shell if [ -a $(filetoadd) ] ; then echo -include $(filetoadd) ; fi ;)

LOCAL_SHARED_LIBRARIES += libc
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += librmnetctl
LOCAL_SHARED_LIBRARIES += libqmi_cci
LOCAL_SHARED_LIBRARIES += libdsutils
LOCAL_SHARED_LIBRARIES += libdiag
LOCAL_SHARED_LIBRARIES += libqmiservices
LOCAL_SHARED_LIBRARIES += libqmi
LOCAL_SHARED_LIBRARIES += libnetutils
LOCAL_SHARED_LIBRARIES += libcutils
LOCAL_SHARED_LIBRARIES += libqmi_client_qmux
LOCAL_SHARED_LIBRARIES += libqmi_encdec
LOCAL_SHARED_LIBRARIES += libqcmaputils

LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/diag/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../data/mobileap/ipc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../common/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qmi-framework/inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../qmi/inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../qmi/src
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../qmi/platform
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../dsutils/inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../dss_new/inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../dss_new/src/utils/inc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../dss_new/src/platform/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/dataservices/rmnetctl
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/qmi/inc
LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
LOCAL_ADDITIONAL_DEPENDENCIES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr
LOCAL_C_INCLUDES += system/core/include/

LOCAL_SRC_FILES := adpl_main.c \
                   adpl_peripheral.c \
                   adpl_modem.c \
                   adpl_data.c \
                   adpl_qmi.c \
                   adpl_dpm.c

LOCAL_INIT_RC := dataadpl.rc
LOCAL_MODULE := adpl
LOCAL_SANITIZE:=integer_overflow
LOCAL_CLANG := true
LOCAL_MODULE_TAGS := optional

LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_EXECUTABLE)
