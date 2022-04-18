/* qsthw_defs.h
 *
 * Copyright (c) 2016-2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 */
#include <system/sound_trigger.h>

#ifndef QTI_ST_HW_DEFS_H
#define QTI_ST_HW_DEFS_H

/*
 * Below are the parameter definitions that are used by ST HAL and
 * qti ST HAL wrapper client.
 */

/* sound trigger recognition event type */
typedef enum {
    QSTHW_RC_EVENT_TYPE_NON_TIMESTAMP = 0,
    QSTHW_RC_EVENT_TYPE_TIMESTAMP = 1
} qsthw_recognition_event_type_t;


/*
 * QTI enhanced recognition event with detection timestamp
 */
struct qsthw_phrase_recognition_event {
    struct sound_trigger_phrase_recognition_event phrase_event; /* key phrase recognition event */
    uint64_t                                      timestamp;       /* event time stamp */
};

struct qsthw_source_tracking_param
{
    int target_angle_L16[2];
    int interf_angle_L16[2];
    char polarActivityGUI[360];
};

struct qsthw_target_channel_index_param
{
    int target_chan_idx;
};

struct qsthw_esp_energy_levels_param {
    int voiceEnergy;
    int ambientNoiseEnergy;
};

typedef union {
    struct qsthw_source_tracking_param st_params;
    struct qsthw_target_channel_index_param ch_index_params;
    struct qsthw_esp_energy_levels_param esp_energy_levels_params;
} qsthw_get_param_payload_t;

/* sound trigger set parameter keys */
#define QSTHW_PARAMETER_CUSTOM_CHANNEL_MIXING "st_custom_channel_mixing"
#define QSTHW_PARAMETER_SESSION_PAUSE "st_session_pause"
#define QSTHW_PARAMETER_BAD_MIC_CHANNEL_INDEX "st_bad_mic_channel_index"
#define QSTHW_PARAMETER_DIRECTION_OF_ARRIVAL "st_direction_of_arrival"
#define QSTHW_PARAMETER_CHANNEL_INDEX "st_channel_index"
#define QSTHW_PARAMETER_EC_REF_DEVICE "st_ec_ref_device"
#define QSTHW_PARAMETER_ESP_ENERGY_LEVELS "st_esp_energy_levels"

#endif  //QTI_ST_HW_DEFS_H
