/*
 * Copyright (c) 2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Not a Contribution.
 */
/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.qualcomm.qti.networksetting;

import android.os.Parcel;
import android.telephony.CellIdentity;
import android.telephony.CellIdentityCdma;
import android.telephony.CellIdentityGsm;
import android.telephony.CellIdentityLte;
import android.telephony.CellIdentityNr;
import android.telephony.CellIdentityTdscdma;
import android.telephony.CellIdentityWcdma;
import android.telephony.CellInfo;
import android.telephony.CellInfoCdma;
import android.telephony.CellInfoGsm;
import android.telephony.CellInfoLte;
import android.telephony.CellInfoNr;
import android.telephony.CellInfoTdscdma;
import android.telephony.CellInfoWcdma;
import android.telephony.CellSignalStrengthNr;
import android.text.BidiFormatter;
import android.text.TextDirectionHeuristics;
import android.text.TextUtils;
import android.util.Log;

import com.android.internal.telephony.OperatorInfo;

import java.util.List;

/**
 * Add static Utility functions to get information from the CellInfo object.
 * TODO: Modify {@link CellInfo} for simplify those functions
 */
public final class CellInfoUtil {
    private static final String TAG = "CellInfoUtil";

    private CellInfoUtil() {
    }

    /**
     * Wrap a CellIdentity into a CellInfo.
     */
    public static CellInfo wrapCellInfoWithCellIdentity(CellIdentity cellIdentity) {
        if (cellIdentity instanceof CellIdentityNr) {
            return makeCellInfoNrFromCellIdentityNr((CellIdentityNr) cellIdentity);
        } else if (cellIdentity instanceof CellIdentityLte) {
            CellInfoLte cellInfo = new CellInfoLte();
            cellInfo.setCellIdentity((CellIdentityLte) cellIdentity);
            return cellInfo;
        } else if (cellIdentity instanceof CellIdentityCdma) {
            CellInfoCdma cellInfo = new CellInfoCdma();
            cellInfo.setCellIdentity((CellIdentityCdma) cellIdentity);
            return cellInfo;
        }  else if (cellIdentity instanceof CellIdentityWcdma) {
            CellInfoWcdma cellInfo = new CellInfoWcdma();
            cellInfo.setCellIdentity((CellIdentityWcdma) cellIdentity);
            return cellInfo;
        } else if (cellIdentity instanceof CellIdentityGsm) {
            CellInfoGsm cellInfo = new CellInfoGsm();
            cellInfo.setCellIdentity((CellIdentityGsm) cellIdentity);
            return cellInfo;
        } else if (cellIdentity instanceof CellIdentityTdscdma) {
            CellInfoTdscdma cellInfo = new CellInfoTdscdma();
            cellInfo.setCellIdentity((CellIdentityTdscdma) cellIdentity);
            return cellInfo;
        } else {
            Log.e(TAG, "Invalid CellInfo type");
            return null;
        }
    }

    private static CellInfoNr makeCellInfoNrFromCellIdentityNr(CellIdentityNr cellIdentityNr) {
        // This method is used to set cellIdentity in CellInfoNr using parcel.

        Parcel parcel = Parcel.obtain();

        // Set the type to TYPE_NR
        parcel.writeInt(CellInfo.TYPE_NR);

        // write the contents of CellInfo to parcel
        parcel.writeInt(0);                                                // mRegistered
        parcel.writeLong(Long.MAX_VALUE);                                  // mTimeStamp
        parcel.writeInt(CellInfo.CONNECTION_NONE);                         // mCellConnectionStatus

        // write the contents of CellIdentityNr to parcel
        cellIdentityNr.writeToParcel(parcel, 0 /* flags */);

        // write the contents of CellSignalStrengthNr to parcel
        CellSignalStrengthNr cellSignalStrengthNr = new CellSignalStrengthNr();
        cellSignalStrengthNr.writeToParcel(parcel, 0/* flags */);

        return CellInfoNr.CREATOR.createFromParcel(parcel);
    }

    /**
     * Returns the title of the network obtained in the manual search.
     *
     * @param cellInfo contains the information of the network.
     * @return Long Name if not null/empty, otherwise Short Name if not null/empty,
     * else MCCMNC string.
     */
    public static String getNetworkTitle(CellInfo cellInfo) {
        OperatorInfo oi = getOperatorInfoFromCellInfo(cellInfo);

        if (!TextUtils.isEmpty(oi.getOperatorAlphaLong())) {
            return oi.getOperatorAlphaLong();
        } else if (!TextUtils.isEmpty(oi.getOperatorAlphaShort())) {
            return oi.getOperatorAlphaShort();
        } else {
            BidiFormatter bidiFormatter = BidiFormatter.getInstance();
            return bidiFormatter.unicodeWrap(oi.getOperatorNumeric(), TextDirectionHeuristics.LTR);
        }
    }

    /**
     * Returns the type of the cell identity obtained in the manual search.
     *
     * @param cellInfo contains the information of the network.
     * @return type of CellIdentity corresponding to cellInfo
     */
    public static int getCellIdentityType(CellInfo cellInfo) {
        int type = CellInfo.TYPE_UNKNOWN;
        if (cellInfo.getCellIdentity() != null) {
            return cellInfo.getCellIdentity().getType();
        }

        return type;
    }

    /**
     * Wrap a cell info into an operator info.
     */
    public static OperatorInfo getOperatorInfoFromCellInfo(CellInfo cellInfo) {
        OperatorInfo oi;
        if (cellInfo instanceof CellInfoNr) {
            CellInfoNr nr = (CellInfoNr) cellInfo;
            String mccStr = nr.getCellIdentity().getMccString();
            String mncStr = nr.getCellIdentity().getMncString();
            String mobileNetworkOperator =
                    (mccStr == null || mncStr == null) ? null : mccStr + mncStr;
            oi = new OperatorInfo(
                    (String) nr.getCellIdentity().getOperatorAlphaLong(),
                    (String) nr.getCellIdentity().getOperatorAlphaShort(),
                    mobileNetworkOperator);
        } else if (cellInfo instanceof CellInfoLte) {
            CellInfoLte lte = (CellInfoLte) cellInfo;
            oi = new OperatorInfo(
                    (String) lte.getCellIdentity().getOperatorAlphaLong(),
                    (String) lte.getCellIdentity().getOperatorAlphaShort(),
                    lte.getCellIdentity().getMobileNetworkOperator());
        } else if (cellInfo instanceof CellInfoWcdma) {
            CellInfoWcdma wcdma = (CellInfoWcdma) cellInfo;
            oi = new OperatorInfo(
                    (String) wcdma.getCellIdentity().getOperatorAlphaLong(),
                    (String) wcdma.getCellIdentity().getOperatorAlphaShort(),
                    wcdma.getCellIdentity().getMobileNetworkOperator());
        } else if (cellInfo instanceof CellInfoGsm) {
            CellInfoGsm gsm = (CellInfoGsm) cellInfo;
            oi = new OperatorInfo(
                    (String) gsm.getCellIdentity().getOperatorAlphaLong(),
                    (String) gsm.getCellIdentity().getOperatorAlphaShort(),
                    gsm.getCellIdentity().getMobileNetworkOperator());
        } else if (cellInfo instanceof CellInfoTdscdma) {
            CellInfoTdscdma tdscdma = (CellInfoTdscdma) cellInfo;
            oi = new OperatorInfo(
                    (String) tdscdma.getCellIdentity().getOperatorAlphaLong(),
                    (String) tdscdma.getCellIdentity().getOperatorAlphaShort(),
                    tdscdma.getCellIdentity().getMobileNetworkOperator());
        } else if (cellInfo instanceof CellInfoCdma) {
            CellInfoCdma cdma = (CellInfoCdma) cellInfo;
            oi = new OperatorInfo(
                    (String) cdma.getCellIdentity().getOperatorAlphaLong(),
                    (String) cdma.getCellIdentity().getOperatorAlphaShort(),
                    "" /* operator numeric */);
        } else {
            Log.e(TAG, "Invalid CellInfo type");
            oi = new OperatorInfo("", "", "");
        }
        Log.d(TAG,"getOperatorInfoFromCellInfo operatorInfo: " + oi);
        return oi;
    }

    /**
     * Creates a CellInfo object from OperatorInfo. GsmCellInfo is used here only because
     * operatorInfo does not contain technology type while CellInfo is an abstract object that
     * requires to specify technology type. It doesn't matter which CellInfo type to use here, since
     * we only want to wrap the operator info and PLMN to a CellInfo object.
     */
    public static CellInfo convertOperatorInfoToCellInfo(OperatorInfo operatorInfo) {
        String operatorNumeric = operatorInfo.getOperatorNumeric();
        String mcc = null;
        String mnc = null;
        if (operatorNumeric != null && operatorNumeric.matches("^[0-9]{5,6}$")) {
            mcc = operatorNumeric.substring(0, 3);
            mnc = operatorNumeric.substring(3);
        }
        CellIdentityGsm cig = new CellIdentityGsm(
                Integer.MAX_VALUE /* lac */,
                Integer.MAX_VALUE /* cid */,
                Integer.MAX_VALUE /* arfcn */,
                Integer.MAX_VALUE /* bsic */,
                mcc,
                mnc,
                operatorInfo.getOperatorAlphaLong(),
                operatorInfo.getOperatorAlphaShort());

        CellInfoGsm ci = new CellInfoGsm();
        ci.setCellIdentity(cig);
        return ci;
    }

    /** Checks whether the network operator is forbidden. */
    public static boolean isForbidden(CellInfo cellInfo, List<String> forbiddenPlmns) {
        String plmn = CellInfoUtil.getOperatorInfoFromCellInfo(cellInfo).getOperatorNumeric();
        return forbiddenPlmns != null && forbiddenPlmns.contains(plmn);
    }
}
