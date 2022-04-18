
## Qualcomm Technologies proprietary product specific compile-time definitions.
#

TARGET_DISABLE_KERNEL_TESTS := true

USE_CAMERA_STUB := false
DEVICE_PACKAGE_OVERLAYS += vendor/qcom/proprietary/common/msm8937_32go/overlay
ifeq ($(TARGET_KERNEL_VERSION), 4.9)
    WIFI_DRIVER_INSTALL_TO_KERNEL_OUT := true
endif
BOARD_USES_ADRENO := true
HAVE_ADRENO_SOURCE := true
HAVE_ADRENO_SC_SOURCE := true
HAVE_ADRENO_FIRMWARE := true
#PCI RCS
TARGET_USES_PCI_RCS := false
TARGET_USES_ION := true
USE_OPENGL_RENDERER := true
TARGET_USES_C2D_COMPOSITION := true

#TARGET_USES_ASHMEM := true
#TARGET_USES_SECURITY_BRIDGE := true
#TARGET_USES_SEAL_2_0 := true
#TARGET_USES_POST_PROCESSING := true
#TARGET_USE_SBC_DECODER := true
#TARGET_USES_SCALAR := true
#
ifeq ($(TARGET_USES_AOSP),true)
  BOARD_VENDOR_QCOM_LOC_PDK_FEATURE_SET := false
  TARGET_SCVE_DISABLED := true
  TARGET_FASTCV_DISABLED := true
else
  BOARD_VENDOR_QCOM_LOC_PDK_FEATURE_SET := false
  TARGET_SCVE_DISABLED := false
endif

TARGET_USES_IMS := true
BOARD_USES_QCNE := true

# Enable real-time face beautification
TARGET_TS_MAKEUP := false

USESECIMAGETOOL := true
## Gensecimage generation of signed apps bootloader
QTI_GENSECIMAGE_MSM_IDS := thorium
## Use signed image as default
QTI_GENSECIMAGE_SIGNED_DEFAULT := thorium
#
##SECIMAGE tool feature flags
USES_SEC_POLICY_MULTIPLE_DEFAULT_SIGN := 1
USES_SEC_POLICY_INTEGRITY_CHECK := 1
##ENERGY_AWARENESS := true

# Enables Adreno RS driver
OVERRIDE_RS_DRIVER := libRSDriver_adreno.so

BOARD_HAS_QCOM_WLAN := true
#BOARD_HAS_ATH_WLAN_AR6004 := true
BOARD_HAVE_BLUETOOTH := true
#BOARD_HAS_QCA_BT_AR3002 := true
BOARD_HAVE_QCOM_FM := true
#BOARD_ANT_WIRELESS_DEVICE := "vfs-prerelease"
ifeq ($(BOARD_HAVE_BLUETOOTH), true)
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
    ifeq ($(TARGET_KERNEL_VERSION), 4.9)
      WIFI_DRIVER_MODULE_PATH := "/system/vendor/lib/modules/pronto_wlan.ko"
    else
      WIFI_DRIVER_MODULE_PATH := "/system/vendor/lib/modules/pronto/pronto_wlan.ko"
    endif # TARGET_KERNEL_VERSION
  else
      WIFI_DRIVER_MODULE_PATH := "/system/lib/modules/wlan.ko"
  endif # PRODUCT_VENDOR_MOVE_ENABLED
  WIFI_DRIVER_MODULE_NAME := "wlan"
  WIFI_DRIVER_MODULE_ARG := ""
  WIFI1_DRIVER_MODULE_PATH := "/system/lib/modules/wil6210.ko"
  WIFI1_DRIVER_MODULE_NAME := "wil6210"
  WIFI1_DRIVER_MODULE_ARG := ""
  WPA_SUPPLICANT_VERSION := VER_0_8_X
  HOSTAPD_VERSION := VER_0_8_X
  CONFIG_ACS := true
  CONFIG_IEEE80211AC := true
  TARGET_USES_QCOM_WCNSS_QMI := true
  BOARD_HAS_CFG80211_KERNEL3_4 := true
  BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_$(BOARD_WLAN_DEVICE)
  BOARD_HOSTAPD_PRIVATE_LIB := lib_driver_cmd_$(BOARD_WLAN_DEVICE)
endif
FEATURE_QCRIL_UIM_SAP_SERVER_MODE := true
BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE := default

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

# TODO: Bring-up exception - all modules must be fixed by corresponding teams
TARGET_CINCLUDES_EXCEPTION_PROJECTS := \
  $(abspath $(TOPDIR)vendor/qcom/proprietary/gles/adreno200) \
  vendor/qcom/proprietary/gles/adreno200 \
  vendor/qcom/proprietary/gps-noship-external \
  vendor/qcom/proprietary/gps-noship \
  disregard/filesystems/mtd-utils
