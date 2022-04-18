# BoardConfigVendor.mk
# Qualcomm Technologies proprietary product specific compile-time definitions.

# Disabling GMS as part of Bring-up
TARGET_GMS_DISABLE := false

USE_CAMERA_STUB := true
DEVICE_PACKAGE_OVERLAYS += vendor/qcom/proprietary/common/msm8909/overlay

BOARD_USES_ADRENO := true
HAVE_ADRENO_SOURCE := true
HAVE_ADRENO_SC_SOURCE := true
HAVE_ADRENO_FIRMWARE := true
#ENABLE_WEBGL := true
#BOARD_USE_QCOM_LLVM_CLANG_RS := true
TARGET_USES_ION := true
USE_OPENGL_RENDERER := true
#TARGET_USES_C2D_COMPOSITION := true

TARGET_USES_ASHMEM := true
TARGET_USES_SECURITY_BRIDGE := true
TARGET_USES_POST_PROCESSING := true
TARGET_USE_SBC_DECODER := true

ifeq ($(TARGET_USES_AOSP),true)
  BOARD_VENDOR_QCOM_LOC_PDK_FEATURE_SET := false
  TARGET_FASTCV_DISABLED := true
  TARGET_SCVE_DISABLED := true
else
  BOARD_VENDOR_QCOM_LOC_PDK_FEATURE_SET := false
endif
#Enable IMS and CNE
TARGET_USES_IMS := true

ifneq ($(TARGET_SUPPORTS_WEARABLES),true)
BOARD_USES_QCNE := true
BOARD_USES_DPM := true
BOARD_USES_LIBC_WRAPPER := true
endif

ifneq ($(TARGET_SUPPORTS_WEARABLES),true)
BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE :=
BOARD_VENDOR_QCOM_LOC_PDK_FEATURE_SET := false
endif

BOARD_HAS_QCOM_WLAN := true
#BOARD_HAS_ATH_WLAN_AR6004 := true
BOARD_HAVE_BLUETOOTH := true
#BOARD_HAS_QCA_BT_AR3002 := true
BOARD_HAVE_QCOM_FM := true
#BOARD_ANT_WIRELESS_DEVICE := "vfs-prerelease"
ifeq ($(BOARD_HAVE_BLUETOOTH), true)
  # Comment the following flag to enable bluedriod
  BOARD_HAVE_BLUETOOTH_BLUEZ := false
  ifneq ($(BOARD_HAVE_BLUETOOTH_BLUEZ), true)
    BOARD_HAVE_BLUETOOTH_QCOM := true
    QCOM_BT_USE_SMD_TTY := true
    BLUETOOTH_HCI_USE_MCT := true
    BOARD_USES_WIPOWER := false
  endif # BOARD_HAVE_BLUETOOTH_BLUEZ
endif # BOARD_HAVE_BLUETOOTH

ifeq ($(findstring true,$(BOARD_HAS_ATH_WLAN_AR6004) $(BOARD_HAS_QCOM_WLAN)),true)
  BOARD_WLAN_DEVICE := qcwcn
  BOARD_WPA_SUPPLICANT_DRIVER := NL80211
  BOARD_HOSTAPD_DRIVER := NL80211
  ifeq ($(PRODUCT_VENDOR_MOVE_ENABLED),true)
    WIFI_DRIVER_MODULE_PATH := "/system/vendor/lib/modules/wlan.ko"
  else
    WIFI_DRIVER_MODULE_PATH := "/system/lib/modules/wlan.ko"
  endif
  WIFI_DRIVER_MODULE_NAME := "wlan"
  WIFI_DRIVER_MODULE_ARG := ""
  WPA_SUPPLICANT_VERSION := VER_0_8_X
  HOSTAPD_VERSION := VER_0_8_X
  # JB MR1 or later
  BOARD_HAS_CFG80211_KERNEL3_4 := true
  # KitKat
  ifeq ($(call is-platform-sdk-version-at-least,19),true)
    BOARD_HAS_CFG80211_KERNEL3_4 := false
    BOARD_HAS_CFG80211_KERNEL3_10 := true
  endif
  BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_$(BOARD_WLAN_DEVICE)
  BOARD_HOSTAPD_PRIVATE_LIB := lib_driver_cmd_$(BOARD_WLAN_DEVICE)
endif

# TODO: Bring-up exception - all modules must be fixed by corresponding teams
INTERNAL_LOCAL_CLANG_EXCEPTION_PROJECTS += \
 $(abspath $(TOPDIR)vendor/qcom/proprietary/gles/adreno200) \
 vendor/qcom/proprietary/gles/adreno200 \
  vendor/qcom/proprietary/fastcv-noship \
  vendor/qcom/proprietary/gps-noship \
  vendor/qcom/proprietary/kernel-tests \
  vendor/qcom/proprietary/mare-noship \
  vendor/qcom/proprietary/mm-camera-lib \
  vendor/qcom/proprietary/mm-camera/mm-camera2/media-controller/modules/imglib \
  vendor/qcom/proprietary/mm-camera/mm-camera2/tests \
  vendor/qcom/proprietary/mm-mux


# TODO: Bring-up exception - all modules must be fixed by corresponding teams 	121
TARGET_CINCLUDES_EXCEPTION_PROJECTS := \
  $(abspath $(TOPDIR)vendor/qcom/proprietary/gles/adreno200) \
  vendor/qcom/proprietary/gles/adreno200 \
  vendor/qcom/proprietary/gps-noship-external \
  vendor/qcom/proprietary/gps-noship \
  disregard/filesystems/mtd-utils
