# Copyright (c) 2017 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#

# This file is used to generate the autogenerated code and blueprint/makefiles for the hals in
# com.qualcomm.qti.fm@1.0 service:
#
OEMFMHIDL_COMPONENT="vendor.qti.hardware:vendor/qcom/proprietary/interfaces"
LIBHIDL_COMPONENT="android.hidl:system/libhidl/transport"
OEMFM_INTERFACE_LIB="vendor.qti.hardware.fm@1.0"

hidl-gen -Landroidbp -r $OEMFMHIDL_COMPONENT -r $LIBHIDL_COMPONENT $OEMFM_INTERFACE_LIB
hidl-gen -Lmakefile -r $OEMFMHIDL_COMPONENT -r $LIBHIDL_COMPONENT $OEMFM_INTERFACE_LIB