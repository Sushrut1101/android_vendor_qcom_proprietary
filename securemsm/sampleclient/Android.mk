ifeq ($(call is-board-platform-in-list,msm8974 msm8960 msm8660 msm8226 msm8610 msm8916 msm8916_32 msm8916_32_k64 msm8916_64 apq8084 msm8939 msm8994 msm8996 msm8992 msm8952 msm8937 msm8953 msm8998 apq8098_latv sdm660 sdm845 sdm710 qcs605 msm8909 msmnile sdmshrike kona $(MSMSTEPPE) lito atoll bengal $(TRINKET)),true)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_C_INCLUDES :=

ifeq ($(call is-board-platform-in-list,msmnile sdmshrike kona $(MSMSTEPPE) lito atoll bengal $(TRINKET)),true)
LIBION_PATH_INCLUDES := true
endif

ifeq ($(LIBION_PATH_INCLUDES),true)
LOCAL_C_INCLUDES += system/core/libion/include \
                    system/core/libion/kernel-headers
LOCAL_SHARED_LIBRARIES += libion
endif

LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include \
                    $(LOCAL_PATH)/../QSEEComAPI \
                    $(LOCAL_PATH)/../sampleclient \
                    $(TARGET_OUT_HEADERS)/common/inc \
                    $(LOCAL_PATH)/../sse/SecureUILib \


LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_SHARED_LIBRARIES += \
        libc \
        libcutils \
        libutils \
        liblog \
        libQSEEComAPI \
        libdl

LOCAL_MODULE := qseecom_sample_client
LOCAL_SRC_FILES := qseecom_sample_client.c
LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS := $(QSEECOM_CFLAGS)

#flag for enabling TUI sample app
ifneq ($(call is-board-platform-in-list, qcs605 msm8909),true)
#Disabling TUI sample app for automotive SPS.
ifneq ($(TARGET_BOARD_AUTO),true)
LOCAL_CFLAGS += -DSECURE_UI
LOCAL_SHARED_LIBRARIES += libSecureUILib
endif
endif

LOCAL_MODULE_OWNER := qcom
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_EXECUTABLE)

endif # end filter
