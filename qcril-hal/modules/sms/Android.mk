LOCAL_PATH := $(call my-dir)
QCRIL_DIR := ${LOCAL_PATH}/../..

## Build header library
include $(CLEAR_VARS)
LOCAL_MODULE               := libril-qc-hal-sms-headers
LOCAL_VENDOR_MODULE        := true
LOCAL_EXPORT_C_INCLUDE_DIRS += $(LOCAL_PATH)/src
include $(BUILD_HEADER_LIBRARY)

include $(CLEAR_VARS)

LOCAL_CFLAGS               += -Wall -Werror $(qcril_cflags)
LOCAL_CXXFLAGS             += -std=c++17 $(qcril_cppflags)
LOCAL_CPPFLAGS             += -std=c++17 $(qcril_cppflags)
LOCAL_LDFLAGS              += $(qcril_ldflags)

ifneq ($(qcril_sanitize_diag),)
LOCAL_SANITIZE_DIAG := $(qcril_sanitize_diag)
endif

ifeq ($(QCRIL_BUILD_WITH_ASAN),true)
LOCAL_SANITIZE             += $(qcril_sanitize)
endif
LOCAL_SRC_FILES            += $(call all-cpp-files-under, src)

LOCAL_MODULE               := qcrilSmsModule
LOCAL_MODULE_OWNER         := qti
LOCAL_PROPRIETARY_MODULE   := true
LOCAL_MODULE_TAGS          := optional

LOCAL_SHARED_LIBRARIES     += qtimutex

LOCAL_SHARED_LIBRARIES     += liblog
LOCAL_SHARED_LIBRARIES     += libsqlite
LOCAL_HEADER_LIBRARIES     += libril-qti-hal-qmi-headers
LOCAL_HEADER_LIBRARIES     += qtimutex-headers
LOCAL_HEADER_LIBRARIES     += libcutils_headers
LOCAL_HEADER_LIBRARIES     += libqcril-qc-hal-cmas-headers

LOCAL_WHOLE_STATIC_LIBRARIES += libqcril-qc-hal-cmas

include $(BUILD_STATIC_LIBRARY)

