ifeq ($(call is-board-platform-in-list,msm8953),true)

ifneq ($(BUILD_TINY_ANDROID),true)

LOCAL_PATH:= $(call my-dir)

# ---------------------------------------------------------------------------------
#             Populate ACDB data files to file system for MTP
# ---------------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_Bluetooth_cal.acdb
LOCAL_MODULE_FILENAME   := Bluetooth_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/
LOCAL_SRC_FILES         := MTP/Bluetooth_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_General_cal.acdb
LOCAL_MODULE_FILENAME   := General_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/
LOCAL_SRC_FILES         := MTP/General_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_Global_cal.acdb
LOCAL_MODULE_FILENAME   := Global_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/
LOCAL_SRC_FILES         := MTP/Global_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_Handset_cal.acdb
LOCAL_MODULE_FILENAME   := Handset_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/
LOCAL_SRC_FILES         := MTP/Handset_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_Hdmi_cal.acdb
LOCAL_MODULE_FILENAME   := Hdmi_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/
LOCAL_SRC_FILES         := MTP/Hdmi_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_Headset_cal.acdb
LOCAL_MODULE_FILENAME   := Headset_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/
LOCAL_SRC_FILES         := MTP/Headset_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_Speaker_cal.acdb
LOCAL_MODULE_FILENAME   := Speaker_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/
LOCAL_SRC_FILES         := MTP/Speaker_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_workspaceFile.qwsp
LOCAL_MODULE_FILENAME   := workspaceFile.qwsp
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/
LOCAL_SRC_FILES         := MTP/workspaceFile.qwsp
include $(BUILD_PREBUILT)

# ---------------------------------------------------------------------------------
#             Populate ACDB data files to file system for MTP Tasha Codec
# ---------------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_WCD9335_Bluetooth_cal.acdb
LOCAL_MODULE_FILENAME   := Bluetooth_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/msm8953-tasha-snd-card/
LOCAL_SRC_FILES         := MTP/msm8953-tasha-snd-card/Bluetooth_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_WCD9335_General_cal.acdb
LOCAL_MODULE_FILENAME   := General_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/msm8953-tasha-snd-card/
LOCAL_SRC_FILES         := MTP/msm8953-tasha-snd-card/General_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_WCD9335_Global_cal.acdb
LOCAL_MODULE_FILENAME   := Global_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/msm8953-tasha-snd-card/
LOCAL_SRC_FILES         := MTP/msm8953-tasha-snd-card/Global_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_WCD9335_Handset_cal.acdb
LOCAL_MODULE_FILENAME   := Handset_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/msm8953-tasha-snd-card/
LOCAL_SRC_FILES         := MTP/msm8953-tasha-snd-card/Handset_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_WCD9335_Hdmi_cal.acdb
LOCAL_MODULE_FILENAME   := Hdmi_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/msm8953-tasha-snd-card/
LOCAL_SRC_FILES         := MTP/msm8953-tasha-snd-card/Hdmi_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_WCD9335_Headset_cal.acdb
LOCAL_MODULE_FILENAME   := Headset_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/msm8953-tasha-snd-card/
LOCAL_SRC_FILES         := MTP/msm8953-tasha-snd-card/Headset_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_WCD9335_Speaker_cal.acdb
LOCAL_MODULE_FILENAME   := Speaker_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/msm8953-tasha-snd-card/
LOCAL_SRC_FILES         := MTP/msm8953-tasha-snd-card/Speaker_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := MTP_WCD9335_workspaceFile.qwsp
LOCAL_MODULE_FILENAME   := workspaceFile.qwsp
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/MTP/msm8953-tasha-snd-card/
LOCAL_SRC_FILES         := MTP/msm8953-tasha-snd-card/workspaceFile.qwsp
include $(BUILD_PREBUILT)

#----------------------------------------------------------------------------------
#             Populate ACDB data files to file system for QRD Codec
# ---------------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_Bluetooth_cal.acdb
LOCAL_MODULE_FILENAME   := Bluetooth_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/
LOCAL_SRC_FILES         := QRD/Bluetooth_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_General_cal.acdb
LOCAL_MODULE_FILENAME   := General_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/
LOCAL_SRC_FILES         := QRD/General_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_Global_cal.acdb
LOCAL_MODULE_FILENAME   := Global_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/
LOCAL_SRC_FILES         := QRD/Global_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_Handset_cal.acdb
LOCAL_MODULE_FILENAME   := Handset_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/
LOCAL_SRC_FILES         := QRD/Handset_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_Hdmi_cal.acdb
LOCAL_MODULE_FILENAME   := Hdmi_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/
LOCAL_SRC_FILES         := QRD/Hdmi_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_Headset_cal.acdb
LOCAL_MODULE_FILENAME   := Headset_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/
LOCAL_SRC_FILES         := QRD/Headset_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_Speaker_cal.acdb
LOCAL_MODULE_FILENAME   := Speaker_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/
LOCAL_SRC_FILES         := QRD/Speaker_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_workspaceFile.qwsp
LOCAL_MODULE_FILENAME   := workspaceFile.qwsp
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/
LOCAL_SRC_FILES         := QRD/workspaceFile.qwsp
include $(BUILD_PREBUILT)

#----------------------------------------------------------------------------------
#             Populate ACDB data files to file system for QRD sku4 Codec
# ---------------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_SKU4_Bluetooth_cal.acdb
LOCAL_MODULE_FILENAME   := Bluetooth_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/msm8953-sku4-snd-card/
LOCAL_SRC_FILES         := QRD/msm8953-sku4-snd-card/Bluetooth_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_SKU4_General_cal.acdb
LOCAL_MODULE_FILENAME   := General_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/msm8953-sku4-snd-card/
LOCAL_SRC_FILES         := QRD/msm8953-sku4-snd-card/General_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_SKU4_Global_cal.acdb
LOCAL_MODULE_FILENAME   := Global_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/msm8953-sku4-snd-card/
LOCAL_SRC_FILES         := QRD/msm8953-sku4-snd-card/Global_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_SKU4_Handset_cal.acdb
LOCAL_MODULE_FILENAME   := Handset_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/msm8953-sku4-snd-card/
LOCAL_SRC_FILES         := QRD/msm8953-sku4-snd-card/Handset_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_SKU4_Hdmi_cal.acdb
LOCAL_MODULE_FILENAME   := Hdmi_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/msm8953-sku4-snd-card/
LOCAL_SRC_FILES         := QRD/msm8953-sku4-snd-card/Hdmi_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_SKU4_Headset_cal.acdb
LOCAL_MODULE_FILENAME   := Headset_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/msm8953-sku4-snd-card/
LOCAL_SRC_FILES         := QRD/msm8953-sku4-snd-card/Headset_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_SKU4_Speaker_cal.acdb
LOCAL_MODULE_FILENAME   := Speaker_cal.acdb
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/msm8953-sku4-snd-card/
LOCAL_SRC_FILES         := QRD/msm8953-sku4-snd-card/Speaker_cal.acdb
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE            := QRD_SKU4_workspaceFile.qwsp
LOCAL_MODULE_FILENAME   := workspaceFile.qwsp
LOCAL_MODULE_TAGS       := optional
LOCAL_MODULE_CLASS      := ETC
LOCAL_MODULE_PATH       := $(TARGET_OUT_VENDOR_ETC)/acdbdata/QRD/msm8953-sku4-snd-card/
LOCAL_SRC_FILES         := QRD/msm8953-sku4-snd-card/workspaceFile.qwsp
include $(BUILD_PREBUILT)

endif #BUILD_TINY_ANDROID
endif
# ---------------------------------------------------------------------------------
#                     END
# ---------------------------------------------------------------------------------

