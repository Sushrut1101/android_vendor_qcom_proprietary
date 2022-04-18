/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
package com.qualcomm.qti.panoramaui.preferences.legacycamera;

import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;

import com.qualcomm.qti.panoramaui.R;
import com.qualcomm.qti.panoramaui.preferences.CameraPreference;

import android.content.Context;
import android.hardware.Camera.Parameters;
import android.util.Log;

/**
 * This class implements a {@link CameraPreference} to control exposure compensation
 */
@SuppressWarnings("deprecation")
public class CameraPreferenceExposureCompensation extends CameraPreference
        implements LegacyCameraPreference {

    private static final String TAG = "CameraPreferenceExposureCompensation";

    private final String mTitle;
    private final String[] mEntries;
    private final String[] mValues;
    private final Parameters mParameters;

    /**
     * Construct a {@link CameraPreferenceExposureCompensation}
     * @see CameraPreference#CameraPreference(Context, int, Parameters)
     */
    public CameraPreferenceExposureCompensation(Context context, int cameraId, Parameters p) {
        super(context, cameraId);
        mTitle = context.getResources().getString(R.string.camera_settings_exposure_compensation);

        DecimalFormat df = new DecimalFormat("+#0.##;-#", DecimalFormatSymbols.getInstance(Locale.US));
        int minComp = p.getMinExposureCompensation();
        int maxComp = p.getMaxExposureCompensation();
        float step = p.getExposureCompensationStep();
        int numEntries = maxComp - minComp + 1;
        mEntries = new String[numEntries];
        mValues = new String[numEntries];
        for (int i = 0; i < numEntries; i++) {
            float val = (minComp + i) * step;
            if (Math.abs(val) <= 0.005f) {
                mEntries[i] = "0";
            } else {
                mEntries[i] = df.format(val);
            }
            mValues[i] = Integer.toString(minComp + i);
        }
        mParameters = p;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    protected String getBaseKey() {
        return "camerapref_exposure_comp";
    }

    /**
     * {@inheritDoc}
     */
    @Override
    protected String getTitle() {
        return mTitle;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    protected String[] getEntries() {
        return mEntries;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    protected String[] getValues() {
        return mValues;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    protected String[] getSupportedValues() {
        return null;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    protected String getDefaultValue() {
        return "0";
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void apply() {
        int idx = Integer.parseInt(getValue());
        mParameters.setExposureCompensation(idx);
        Log.i(TAG, "Set exposure compensation idx to [" + idx + "]");
    }
}
