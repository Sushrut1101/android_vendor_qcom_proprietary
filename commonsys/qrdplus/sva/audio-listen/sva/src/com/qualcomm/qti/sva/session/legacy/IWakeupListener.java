/*
 * Copyright (c) 2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

package com.qualcomm.qti.sva.session.legacy;

import android.hardware.soundtrigger.SoundTrigger;

public interface IWakeupListener {

    void onRecognition(SoundTrigger.RecognitionEvent recognitionEvent);

    void onServiceStatusChange(int state);

    void onServiceDied();
}
