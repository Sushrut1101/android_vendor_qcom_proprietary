/*
 * Copyright (c) 2014, 2016-2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <inttypes.h>

#include "pa_qti_soundtrigger.h"

#define OK 0
#define MAX_SOUND_TRIGGER_SESSIONS 8
#define FILE_PATH_MAX_LENGTH 128
#define MIN_REQ_PARAMS_PER_SESSION 3
#define SM_MINOR_VERSION 1
#define SM_MINOR_VERSION_2 2
#define MAX_SET_PARAM_KEYS 4
#define MAX_GET_PARAM_KEYS 2

#define SOUNDTRIGGER_TEST_USAGE \
    "pa_qti_soundtrigger_test [OPTIONS]\n" \
    "Example: pa_qti_soundtrigger_test -ns 1 -id 1 -sm /data/HS.uim -nk 1\n" \
    "OPTIONS:\n" \
    "-ns number of sessions\n" \
    "-id session id\n" \
    "-vendor_uuid vendor uuid for the session\n" \
    "-sm soundmodel file\n" \
    "-nk number of keywords\n" \
    "-kwcnf list of keyword confidence levels. valid with -nk\n" \
    " valid Confidence value [1 100]. Default is 60." \
    "-nu number of users per keyword.\n" \
    "-usrcnf list of user confidence levels. Valid with -nu\n" \
    " valid Confidence value [1 100]. Default is 60.\n" \
    "-user enable user identification; true or false. Default is false.\n" \
    "-lab LookAheadBuffering. Default is false.\n" \
    "-lab_duration duration of capture data after detection event. Disabled by default.\n" \
    "-kb KeywordBuffering. Default is false.\n" \
    "-kb_duration duration of keyword for detection in milliseconds. Disabled by default. \n" \
    "-pre_roll_duration for data before keyword in milliseconds. Disabled by default. \n" \
    "-cnn_kwcnf CNN keyword confidence level. valid for multi stage\n" \
    "-vop_usercnf Voice Print user confidence level. valid for multi stage\n" \
    "-generic Use generic payload and get key based detection payload data\n" \
    "-cmd_file Reads list of commands from file instead of standard input\n" \
    "-----------------------------------------------------------\n" \
    "USAGE:\n"  \
    "each session specific data to be given in below format and order\n" \
    "id is Unique(> 0) and should be present at start of each session data\n" \
    "It is also used to identify session for later commands\n" \
    "-nu value is relevant only if user verification is enabled\n" \
    "-vendor_uuid should be valid unique vendor uuid.\n"\
    "In case of no values entered, default value for number of users\n" \
    "and vendor uuid i.e. 0 and sva vendor uuid is assumed\n" \
    "-----------------------------------------------------------\n" \
    "Enter per session params for all the sessions at the start after -ns\n" \
    "-nu and -vendor_uuid are optional per session\n" \
    "sound_trigger_test -ns <number of sessions\n" \
    "-id <session id> -sm <soundmodel> -nk <number of keywords>\n" \
    "-nu <number of users per keyword> -vendor_uuid <vendor uuid>\n" \
    "-----------------------------------------------------------\n" \
    "Optional params to be given after all session specific data is entered\n" \
    "LAB set to disable with KeywordBuffering enabled is treated as an invalid case\n" \
    "-user <user verification>\n" \
    "-lab <LookAheadBuffering enable/disable> -lab_duration <LAB duration in seconds>\n" \
    "-kb <KeywordBuffering enable/disable> -kb_duration <KeywordBuffering duration in milliseconds>\n" \
    "-kwcnf <keyword confidence levels> -usrcnf <user confidence levels>\n" \
    "-pre_roll_duration <to capture environment data before keyword utterance in milliseconds> \n" \
    "-cnn_kwcnf <CNN sound model keyword confidence level>\n" \
    "-vop_usrcnf <VoicePrint user confidence level>\n" \
    "-generic <Use generic payload and get key based detection payload data>\n" \
    "-cmd_file <File name with list of commands to read from>\n"

struct sm_session_data {
    int session_id;
    sound_trigger_uuid_t vendor_uuid;
    char sm_file_path[FILE_PATH_MAX_LENGTH];
    pa_qst_ses_handle_t ses_handle;
    unsigned int num_kws;
    unsigned int num_users;
    bool loaded;
    bool started;
    unsigned int counter;
    struct sound_trigger_recognition_config *rc_config;
    struct pa_qst_phrase_recognition_event *pa_qst_event;
    bool versioned_det_event_payload;
};

struct keyword_buffer_config {
    int version;
    uint32_t kb_duration;
}__attribute__((packed));

/* Definitions from STHAL opaque_header.h to send packed opaque data */
#define ST_MAX_SOUND_MODELS 10
#define ST_MAX_KEYWORDS 10
#define ST_MAX_USERS 10

enum param_key {
    PARAM_KEY_CONFIDENCE_LEVELS,
    PARAM_KEY_HISTORY_BUFFER_CONFIG,
    PARAM_KEY_KEYWORD_INDICES,
    PARAM_KEY_TIMESTAMP,
};

enum sound_model_id {
    SM_ID_NONE = 0x0000,
    SM_ID_SVA_GMM = 0x0001,
    SM_ID_SVA_CNN = 0x0002,
    SM_ID_SVA_VOP = 0x0004,
    SM_ID_SVA_END = 0x00F0,
    SM_ID_CUSTOM_START = 0x0100,
    SM_ID_CUSTOM_END = 0xF000,
};

struct opaque_param_header {
    enum param_key key_id;
    uint32_t payload_size;
}__attribute__((packed));

struct user_levels {
    uint32_t user_id;
    uint8_t level;
}__attribute__((packed));

struct keyword_levels {
    uint8_t kw_level;
    uint32_t num_user_levels;
    struct user_levels user_levels[ST_MAX_USERS];
}__attribute__((packed));

struct sound_model_conf_levels {
    enum sound_model_id sm_id;
    uint32_t num_kw_levels;
    struct keyword_levels kw_levels[ST_MAX_KEYWORDS];
}__attribute__((packed));

struct confidence_levels_info {
    uint32_t version;
    uint32_t num_sound_models;
    struct sound_model_conf_levels conf_levels[ST_MAX_SOUND_MODELS];
}__attribute__((packed));

struct hist_buffer_info {
    uint32_t version;
    uint32_t hist_buffer_duration_msec;
    uint32_t pre_roll_duration_msec;
}__attribute__((packed));

struct keyword_indices_info {
    uint32_t version;
    uint32_t start_index; /* in bytes */
    uint32_t end_index; /* in bytes */
}__attribute__((packed));

struct timestamp_info {
    uint32_t version;
    long first_stage_det_event_timestamp; /* in nanoseconds */
    long second_stage_det_event_timestamp; /* in nanoseconds */
}__attribute__((packed));

const pa_qst_handle_t *pa_qst_handle;
static struct sm_session_data sound_trigger_info[MAX_SOUND_TRIGGER_SESSIONS];
static unsigned int num_sessions;
static int lab_duration = 5; //5sec is default duration
static int kb_duration_ms = 2000; //2000 msec is default duration
int total_duration_ms = 0;
static int generic_payload_size = 0;
static int pre_roll_duration_ms = 0;

/* SVA vendor uuid */
static const sound_trigger_uuid_t qc_uuid =
    { 0x68ab2d40, 0xe860, 0x11e3, 0x95ef, { 0x00, 0x02, 0xa5, 0xd5, 0xc5, 0x1b } };

static const sound_trigger_uuid_t qc_arm_uuid =
    { 0x67fabb70, 0x79e8, 0x4e1c, 0xa202, { 0xbc, 0xb0, 0x50, 0x24, 0x3a, 0x70} };

static void *event_handler_thread(void *);

static const char *set_param_key_array[] = {
     PA_QST_PARAMETER_CUSTOM_CHANNEL_MIXING,
     PA_QST_PARAMETER_SESSION_PAUSE,
     PA_QST_PARAMETER_BAD_MIC_CHANNEL_INDEX,
     PA_QST_PARAMETER_EC_REF_DEVICE
};

static const char *get_param_key_array[] = {
    PA_QST_PARAMETER_DIRECTION_OF_ARRIVAL,
    PA_QST_PARAMETER_CHANNEL_INDEX
};

enum det_event_keys {
    KWD_CONFIDENCE_LEVEL = 0x0,
    KWD_INDEX,
    KWD_MAX
};

bool exit_loop = false;
static struct sm_session_data *get_sm_session_data(int session_id) {
    unsigned int i;

    for (i = 0; i < num_sessions; i++) {
        if (sound_trigger_info[i].session_id == session_id)
            return &sound_trigger_info[i];
    }
    return NULL;
}

static struct sm_session_data *get_sound_trigger_info(pa_qst_ses_handle_t ses_handle) {
    unsigned int i;

    for (i = 0; i < num_sessions; i++) {
        if (sound_trigger_info[i].ses_handle == ses_handle)
            return &sound_trigger_info[i];
    }
    return NULL;
}

static void deinit_sm_session_data(void) {
    int i;

    for (i = 0; i < MAX_SOUND_TRIGGER_SESSIONS; i++) {
        if (sound_trigger_info[i].rc_config)
            free(sound_trigger_info[i].rc_config);
        if (sound_trigger_info[i].pa_qst_event)
            free(sound_trigger_info[i].pa_qst_event);
    }
}

static void init_sm_session_data(void) {
    int i;

    for (i = 0; i < MAX_SOUND_TRIGGER_SESSIONS; i++) {
        sound_trigger_info[i].session_id = -1;
        sound_trigger_info[i].vendor_uuid = qc_uuid;
        sound_trigger_info[i].sm_file_path[0] = '\0';
        sound_trigger_info[i].ses_handle = -1;
        sound_trigger_info[i].num_kws = 0;
        sound_trigger_info[i].num_users = 0;
        sound_trigger_info[i].loaded = false;
        sound_trigger_info[i].started = false;
        sound_trigger_info[i].counter = 0;
        sound_trigger_info[i].rc_config = NULL;
        sound_trigger_info[i].pa_qst_event = NULL;
        sound_trigger_info[i].versioned_det_event_payload = false;
    }
}

static void eventCallback(struct sound_trigger_recognition_event *event, void *sessionHndl __unused) {
    int rc;
    pthread_attr_t attr;
    pthread_t callback_thread;
    pa_qst_ses_handle_t ses_handle = event->model;
    struct pa_qst_phrase_recognition_event *pa_qst_event;
    uint64_t event_timestamp;
    unsigned int event_size;

    printf("[%d] Callback event received: %d\n", event->model, event->status);
    pa_qst_event = (struct pa_qst_phrase_recognition_event *)event;
    event_timestamp = pa_qst_event->timestamp;
    printf("[%d] Event detection timestamp %" PRIu64 "\n", ses_handle, event_timestamp);

    rc = pthread_attr_init(&attr);
    if (rc != 0) {
        printf("pthread attr init failed %d\n",rc);
        return;
    }
    struct sm_session_data *ses_data = get_sound_trigger_info(ses_handle);
    if (ses_data == NULL) {
        printf("Error: Invalid sound model handle %d\n", ses_handle);
        return;
    }
    if (ses_data->pa_qst_event) {
        printf("Error: previous callback in progress for session %d\n", ses_handle);
        return;
    }

    event_size = sizeof(struct pa_qst_phrase_recognition_event) +
                      pa_qst_event->phrase_event.common.data_size;
    ses_data->pa_qst_event = (struct pa_qst_phrase_recognition_event *)calloc(1, event_size);
    if (ses_data->pa_qst_event == NULL) {
        printf("Could not allocate memory for sm data recognition event");
        return;
    }
    memcpy(ses_data->pa_qst_event, pa_qst_event,
           sizeof(struct pa_qst_phrase_recognition_event));
    memcpy((char *)ses_data->pa_qst_event + ses_data->pa_qst_event->phrase_event.common.data_offset,
           (char *)pa_qst_event + pa_qst_event->phrase_event.common.data_offset,
           pa_qst_event->phrase_event.common.data_size);

    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    rc = pthread_create(&callback_thread, &attr,
                        event_handler_thread, ses_data);
    if (rc != 0)
        printf("event_handler_thread create failed %d\n",rc);
    pthread_attr_destroy(&attr);
}

static void capture_lab_data(struct pa_qst_phrase_recognition_event *pa_qst_event) {
    int ret = 0;
    void *buffer;
    unsigned int period_size;
    size_t bytes, written;
    char lab_capture_file[128] = "";
    size_t cur_bytes_read = 0;
    size_t total_bytes_to_read;
    FILE *fp;
    struct sound_trigger_phrase_recognition_event phrase_event =
                                                  pa_qst_event->phrase_event;
    pa_qst_ses_handle_t ses_handle = phrase_event.common.model;
    audio_config_t *audio_config = &phrase_event.common.audio_config;
    uint32_t sample_rate = audio_config->sample_rate;
    uint32_t channels =
             audio_channel_count_from_in_mask(audio_config->channel_mask);
    audio_format_t format = audio_config->format;
    size_t samp_sz = audio_bytes_per_sample(format);
    struct stat st = {0};

    bytes = pa_qst_get_buffer_size(pa_qst_handle, ses_handle);
    if (bytes <= 0) {
        printf("Invalid buffer size returned\n");
        return;
    }

    /* total bytes to read = bytes to read per sec * duration where
     * audio configuration passed as part of recognition event is
     * used to obtain bytes per sec.
     */
    total_bytes_to_read = ((sample_rate * channels * samp_sz) * total_duration_ms)/1000;
    printf("rate %d, channels %d, samp sz %zu, duration %d, total_bytes_to_read %zu\n",
    sample_rate, channels, samp_sz, total_duration_ms, total_bytes_to_read);

    buffer = calloc(1, bytes);
    if (buffer == NULL) {
        printf("Could not allocate memory for capture buffer\n");
        return;
    }

    if (stat("/data/SVA", &st) == -1)
        mkdir("/data/SVA", S_IRWXU | S_IRWXG | S_IRWXO);

    snprintf(lab_capture_file, sizeof(lab_capture_file),
             "/data/SVA/lab_capture_file_%d", ses_handle);
    fp = fopen(lab_capture_file, "wb");
    if (fp == NULL) {
        printf("Could not open lab capture file : %s\n", lab_capture_file);
        free(buffer);
        return;
    }

    printf("lab capture file : %s\n", lab_capture_file);
    while (cur_bytes_read < total_bytes_to_read) {
        pa_qst_read_buffer(pa_qst_handle, ses_handle,
                              buffer, bytes);
        written = fwrite(buffer, 1, bytes, fp);
        if (written != bytes) {
            printf("written %zu, bytes %zu\n", written, bytes);
            if (ferror(fp)) {
                printf("Error writing lab capture data into file %s\n",strerror(errno));
                break;
            }
        }
        cur_bytes_read += bytes;
        memset(buffer, 0, bytes);
    }
    printf("bytes to read %zu, bytes read %zu\n", total_bytes_to_read, cur_bytes_read);
    pa_qst_stop_buffering(pa_qst_handle, ses_handle);
    free(buffer);
    fclose(fp);
}

static void process_detection_event(struct sm_session_data *ses_data) {
    int i, j, k, user_id;
    void *payload;
    char *payload_8;
    uint32_t *payload_32;
    uint32_t version, key, key_version, key_size;
    struct pa_qst_phrase_recognition_event *event = ses_data->pa_qst_event;
    struct sound_trigger_phrase_recognition_event phrase_event;
    size_t payload_size, count = 0;
    struct opaque_param_header *param_hdr = NULL;
    struct confidence_levels_info *conf_levels;
    struct sound_model_conf_levels *sm_levels;
    struct keyword_indices_info *kw_indices;
    struct timestamp_info *ts_info;

    printf("%s: offset %d, size %d\n", __func__, event->phrase_event.common.data_offset,
            event->phrase_event.common.data_size);
    payload_size = event->phrase_event.common.data_size;
    payload = calloc(1, payload_size);
    if (!payload) {
        printf("%s: Memory allocation for payload failed\n", __func__);
        return;
    }
    memcpy(payload, ((char *)event) + event->phrase_event.common.data_offset,
        event->phrase_event.common.data_size);
    payload_8 = (char *)payload;
    payload_32 = (uint32_t *)payload;
    printf("%s: detection event status %d\n", __func__, event->phrase_event.common.status);
    printf("%s: detection event timestamp %" PRIu64 "\n", __func__, event->timestamp);

    phrase_event = event->phrase_event;
    if (ses_data->versioned_det_event_payload) {
        /*
         * ARM usecase: versioned detection event payload
         * will be in following format and needs to be parsed accordingly.
         * uint32 version - describes the release version (starting from 0x1)
         * uint32 key1 - KWD_CONFIDENCE_LEVEL
         * uint32 key1_version - describes release version of key1 (starting from 0x1)
         * uint32 key1_size - payload size of key1 following this attribute
         * Key1_payload - payload of key1
         * ....
         *
         * Similarly key2 represents KWD_INDEX.
         * The payload format can be extended accordingly for any newly added keys
         * distinguished based on version.
         *
         */
        version = *payload_32++;
        printf("%s: version %d\n", __func__, version);
        if (version == 0x1) {
            for (k = 0; k < KWD_MAX; k++) {
                key = *payload_32++;
                printf("%s: [%d]: key %d\n", __func__, k, key);
                key_version = *payload_32++;
                printf("%s: key version %d\n", __func__, key_version);
                key_size = *payload_32++;
                printf("%s: key size %d\n", __func__, key_size);
                switch (key) {
                case KWD_CONFIDENCE_LEVEL:
                    /* parse payload for key == KWD_CONFIDENCE_LEVEL */
                    if (key_version != 0x1) {
                        printf("%s: Invalid version for confidence level key %d\n",
                                __func__, key_version);
                        goto exit;
                    }
                    payload_8 = (char *)payload_32;
                    uint8_t conf_levels = *payload_8++;
                    printf("%s: conf levels %d\n", __func__, conf_levels);
                    for (i = 0; i < conf_levels; i++) {
                        printf("%s: [%d] kw_id level %d\n", __func__, i,
                               payload_8[i]);
                    }
                    payload_32 = (uint32_t *)((char *)payload_32 + key_size);
                    break;
                case KWD_INDEX:
                    /* parse payload for key == KWD_INDEX */
                    if (key_version != 0x1) {
                        printf("%s: Invalid version for keyword index key %d\n",
                                __func__, key_version);
                        goto exit;
                    }
                    printf("%s: keyword start index %d\n", __func__, *payload_32++);
                    printf("%s: keyword stop index %d\n", __func__, *payload_32++);
                    payload_32 += key_size;
                    break;
                default:
                    printf("%s: Invalid key %d\n", __func__, key);
                    goto exit;
                }
            }
        } else {
            printf("%s: Invalid version for detection event payload %d\n",
                    __func__, version);
            goto exit;
        }
    } else if (generic_payload_size != 0) {
        /* LSM/GCS usecase: Generic detection payload with key_id based fields */
        while (count < payload_size) {
            param_hdr = (struct opaque_param_header *)(payload_8);
            switch(param_hdr->key_id) {
            case PARAM_KEY_CONFIDENCE_LEVELS:
                if (param_hdr->payload_size != sizeof(struct confidence_levels_info)) {
                    printf("%s: Invalid payload size of confidence levels\n", __func__);
                    goto exit;
                }
                payload_8 += sizeof(struct opaque_param_header);
                conf_levels = (struct confidence_levels_info *)(payload_8);
                for (i = 0; i < conf_levels->num_sound_models; i++) {
                    if (conf_levels->conf_levels[i].sm_id == SM_ID_SVA_GMM) {
                        for (j = 0; j < conf_levels->conf_levels[i].num_kw_levels; j++) {
                            printf("%s: kw [%d] level %d\n", __func__, j,
                                conf_levels->conf_levels[i].kw_levels[j].kw_level);
                            for (k = 0; k < conf_levels->conf_levels[i].kw_levels[j].num_user_levels; k++) {
                                printf("%s: user [%d] level %d\n", __func__,
                                    conf_levels->conf_levels[i].kw_levels[j].user_levels[k].user_id,
                                    conf_levels->conf_levels[i].kw_levels[j].user_levels[k].level);
                            }
                        }
                    }

                    if (conf_levels->conf_levels[i].sm_id == SM_ID_SVA_CNN) {
                        printf("%s: cnn kw level %d\n", __func__,
                                conf_levels->conf_levels[i].kw_levels[0].kw_level);
                    }

                    if (conf_levels->conf_levels[i].sm_id == SM_ID_SVA_VOP) {
                        printf("%s: vop user level %d\n", __func__,
                                conf_levels->conf_levels[i].kw_levels[0].user_levels[0].level);
                    }
                }
                payload_8 += sizeof(struct confidence_levels_info);
                count += sizeof(struct opaque_param_header) +
                                sizeof(struct confidence_levels_info);
                break;

            case PARAM_KEY_KEYWORD_INDICES:
                if (param_hdr->payload_size != sizeof(struct keyword_indices_info)) {
                    printf("%s: Invalid payload size of keyword indices\n", __func__);
                    goto exit;
                }
                payload_8 += sizeof(struct opaque_param_header);
                kw_indices = (struct keyword_indices_info *)(payload_8);
                printf("%s: kw_indces version %d, start index %d, end index %d\n",
                        __func__, kw_indices->version, kw_indices->start_index,
                        kw_indices->end_index);

                payload_8 += sizeof(struct keyword_indices_info);
                count += sizeof(struct opaque_param_header) +
                                sizeof(struct keyword_indices_info);
                break;

            case PARAM_KEY_TIMESTAMP:
                if (param_hdr->payload_size != sizeof(struct timestamp_info)) {
                    printf("%s: Invalid payload size of timestamp info\n", __func__);
                    goto exit;
                }
                payload_8 += sizeof(struct opaque_param_header);
                ts_info = (struct timestamp_info *)(payload_8);
                printf("%s: timestamp info version %d, 1st stage ts %ld, 2nd stage ts %ld\n",
                        __func__, ts_info->version, ts_info->first_stage_det_event_timestamp,
                        ts_info->second_stage_det_event_timestamp);

                payload_8 += sizeof(struct timestamp_info);
                count += sizeof(struct opaque_param_header) +
                                sizeof(struct timestamp_info);
                break;
            default:
                printf("%s: Invalid param id %d\n", __func__,
                        param_hdr->key_id);
                goto exit;
            }
        }
    } else {
        /* Legacy/Default usecase: only conf level supported. */
        for (i = 0; i < phrase_event.num_phrases; i++) {
            printf("%s: [%d] kw_id %d level %d\n", __func__, i,
                   phrase_event.phrase_extras[i].id,
                   phrase_event.phrase_extras[i].confidence_level);
            printf("%s: Num levels %d\n", __func__,
                   phrase_event.phrase_extras[i].num_levels);
            for (j = 0; j < phrase_event.phrase_extras[i].num_levels; j++) {
                user_id = phrase_event.phrase_extras[i].levels[j].user_id;
                printf("%s: [%d] user_id %d level %d\n", __func__, i,
                       user_id, phrase_event.phrase_extras[i].levels[j].level);
            }
        }
    }

exit:
    if (payload)
        free(payload);
}

static void *event_handler_thread(void *context) {
    int system_ret;
    struct sm_session_data *ses_data = (struct sm_session_data *) context;
    if (!ses_data) {
        printf("Error: context is null\n");
        return NULL;
    }

    system_ret = system("echo qti_services > /sys/power/wake_lock");
    if (system_ret < 0)
        printf("%s: Failed to acquire qti lock\n", __func__);
    else
        printf("%s: Success to acquire qti lock\n", __func__);

    pa_qst_ses_handle_t ses_handle = ses_data->ses_handle;
    printf("[%d] session params %p, %d\n", ses_handle, ses_data->rc_config, total_duration_ms);
    if (ses_data->pa_qst_event) {
        process_detection_event(ses_data);
        if (ses_data->pa_qst_event->phrase_event.common.capture_available) {
            printf ("capture LAB data\n");
            capture_lab_data(ses_data->pa_qst_event);
        }
        free(ses_data->pa_qst_event);
        ses_data->pa_qst_event = NULL;
    }

    /* ignore error */
    pa_qst_start_recognition(pa_qst_handle, ses_handle,
                            ses_data->rc_config, eventCallback, NULL);
    ses_data->counter++;
    printf("[%d] callback event processed, detection counter %d\n", ses_handle, ses_data->counter);
    printf("proceed with utterance or command \n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

    if (system_ret >= 0) {
        system_ret = system("echo qti_services > /sys/power/wake_unlock");
        if (system_ret < 0)
            printf("%s: Failed to release qti lock\n", __func__);
        else
            printf("%s: Success to release qti lock\n", __func__);
    }

    return NULL;
}

static const char *handle_set_parameters(void) {
    char kv_pair[128];
    char *id, *saveptr, *temp_str;
    int i;

    printf("Enter set param key value string:(ex - <st_session_pause=1>");
    fgets(kv_pair, 128, stdin);
    printf("Received key value pair: %s\n", kv_pair);

    kv_pair[strcspn(kv_pair, "\r\n")] = '\0';
    temp_str = strdup(kv_pair);

    id = strtok_r(kv_pair, "= ", &saveptr);
    if (!id) {
        printf("%s: incorrect key value pair", __func__);
        return NULL;
    }

    for (i = 0; i < MAX_SET_PARAM_KEYS; i++) {
         if (!strncmp(id, set_param_key_array[i], strlen(set_param_key_array[i])))
             return temp_str;
    }

    return NULL;
}

static const char *handle_get_parameters(void) {
    char param_string[128];
    char *temp_str;
    int i;

    printf("Enter get param string:(ex - <st_direction_of_arrival>");
    fgets(param_string, 128, stdin);
    printf("Received get param string: %s\n", param_string);

    param_string[strcspn(param_string, "\r\n")] = '\0';
    temp_str = strdup(param_string);

    for (i = 0; i < MAX_GET_PARAM_KEYS; i++) {
         if (!strncmp(temp_str, get_param_key_array[i], strlen(get_param_key_array[i]))) {
             return temp_str;
         }
    }
    return NULL;
}

static void process_get_param_data(const char *param,
                                   pa_qst_get_param_payload_t *payload,
                                   size_t param_data_size) {
    if (!strncmp(param, PA_QST_PARAMETER_DIRECTION_OF_ARRIVAL, sizeof(param))) {
        printf("%s: processing direction of arrival params\n", __func__);
        struct pa_qst_source_tracking_param st_params = payload->st_params;
        if (param_data_size != sizeof(struct pa_qst_source_tracking_param)) {
            printf("%s: ERROR. Invalid param data size returned %zu\n",
                    __func__, param_data_size);
            return;
        }
        printf("%s: target angle boundaries [%d, %d]\n", __func__,
                st_params.target_angle_L16[0], st_params.target_angle_L16[1]);
        printf("%s: interference angle boundaries [%d, %d]\n", __func__,
                st_params.interf_angle_L16[0], st_params.interf_angle_L16[1]);
    } else if (!strncmp(param, PA_QST_PARAMETER_CHANNEL_INDEX, sizeof(param))) {
        printf("%s: processing channel index params\n", __func__);
        struct pa_qst_target_channel_index_param ch_index_params = payload->ch_index_params;
        if (param_data_size != sizeof(struct pa_qst_target_channel_index_param)) {
            printf("%s: ERROR. Invalid param data size returned %zu\n",
                    __func__, param_data_size);
            return;
        }
        printf("%s: target channel index - [%d]\n", __func__,
                ch_index_params.target_chan_idx);
    }
}

static int string_to_uuid(const char *str, sound_trigger_uuid_t *uuid) {
    int tmp[10];

    if (str == NULL || uuid == NULL) {
        return -EINVAL;
    }

    if (sscanf(str, "%08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x",
            tmp, tmp + 1, tmp + 2, tmp + 3, tmp + 4, tmp + 5, tmp + 6,
            tmp + 7, tmp+ 8, tmp+ 9) < 10) {
        return -EINVAL;
    }
    uuid->timeLow = (uint32_t)tmp[0];
    uuid->timeMid = (uint16_t)tmp[1];
    uuid->timeHiAndVersion = (uint16_t)tmp[2];
    uuid->clockSeq = (uint16_t)tmp[3];
    uuid->node[0] = (uint8_t)tmp[4];
    uuid->node[1] = (uint8_t)tmp[5];
    uuid->node[2] = (uint8_t)tmp[6];
    uuid->node[3] = (uint8_t)tmp[7];
    uuid->node[4] = (uint8_t)tmp[8];
    uuid->node[5] = (uint8_t)tmp[9];

    return 0;
}

static void fill_opaque_data(struct sound_trigger_recognition_config *rc_config,
      unsigned int num_kws, unsigned int num_users,
      unsigned int kw_conf, unsigned int user_conf,
      unsigned int cnn_kw_conf, unsigned int vop_user_conf,
      bool kw_buffer)
{
    uint8_t *opaque_ptr = NULL;
    struct opaque_param_header *param_hdr = NULL;
    struct confidence_levels_info *conf_levels = NULL;
    struct sound_model_conf_levels *sm_levels = NULL;
    struct hist_buffer_info *hist_buf = NULL;
    int i = 0, j ,k;
    int user_id = num_kws; //user_id should start from num_kws

    opaque_ptr = (uint8_t *)rc_config + rc_config->data_offset;
    param_hdr = (struct opaque_param_header *)opaque_ptr;

    param_hdr->key_id = PARAM_KEY_CONFIDENCE_LEVELS;
    param_hdr->payload_size = sizeof(struct confidence_levels_info);
    conf_levels = (struct confidence_levels_info *)(opaque_ptr +
                        sizeof(struct opaque_param_header));
    conf_levels->version = SM_MINOR_VERSION;
    conf_levels->num_sound_models = 1;
    sm_levels = (struct sound_model_conf_levels *)&conf_levels->conf_levels[i];
    sm_levels->sm_id = SM_ID_SVA_GMM;
    sm_levels->num_kw_levels = num_kws;
    for (j = 0; j < sm_levels->num_kw_levels; j++) {
        sm_levels->kw_levels[j].kw_level = kw_conf;
        sm_levels->kw_levels[j].num_user_levels = num_users;
        for (k = 0; k < sm_levels->kw_levels[j].num_user_levels; k++) {
            sm_levels->kw_levels[j].user_levels[k].user_id = user_id++;
            sm_levels->kw_levels[j].user_levels[k].level = user_conf;
        }
    }

    if (cnn_kw_conf) {
        conf_levels->num_sound_models++;
        i++;
        sm_levels = (struct sound_model_conf_levels *)&conf_levels->conf_levels[i];
        sm_levels->sm_id = SM_ID_SVA_CNN;
        sm_levels->num_kw_levels = num_kws;
        sm_levels->kw_levels[0].kw_level = cnn_kw_conf;
    }

    if (vop_user_conf) {
        conf_levels->num_sound_models++;
        i++;
        sm_levels = (struct sound_model_conf_levels *)&conf_levels->conf_levels[i];
        sm_levels->sm_id = SM_ID_SVA_VOP;
        sm_levels->kw_levels[0].num_user_levels = num_users;
        sm_levels->kw_levels[0].user_levels[0].level = vop_user_conf;
    }
    opaque_ptr += sizeof(struct opaque_param_header) +
                      sizeof(struct confidence_levels_info);

    if (kw_buffer) {
        param_hdr = (struct opaque_param_header *)opaque_ptr;
        param_hdr->key_id = PARAM_KEY_HISTORY_BUFFER_CONFIG;
        param_hdr->payload_size = sizeof(struct hist_buffer_info);
        hist_buf = (struct hist_buffer_info *)(opaque_ptr +
                            sizeof(struct opaque_param_header));
        hist_buf->version = SM_MINOR_VERSION_2;
        hist_buf->hist_buffer_duration_msec = kb_duration_ms;
        hist_buf->pre_roll_duration_msec = pre_roll_duration_ms;
        opaque_ptr += sizeof(struct opaque_param_header) +
                          sizeof(struct hist_buffer_info);
    }
}

int main(int argc, char *argv[]) {
    int sm_data_size  = 0;
    int sound_model_size = 0, i;
    unsigned int j, k;
    uint32_t rc_config_size;
    struct sound_trigger_phrase_sound_model *sound_model = NULL;
    struct keyword_buffer_config kb_config;
    bool user_verification = false;
    unsigned int kw_conf = 60; //default confidence level is 60
    unsigned int user_conf = 60;
    bool capture_requested = false;
    bool lookahead_buffer = false, keyword_buffer = false;
    bool usr_req_lookahead_buffer = false;
    int index = -1;
    pa_qst_get_param_payload_t payload;
    size_t payload_size = sizeof(pa_qst_get_param_payload_t);
    unsigned int cnn_kw_conf = 0;
    unsigned int vop_user_conf = 0;
    char command[128];
    int status = 0;
    FILE *fp = NULL, *cmd_fp = NULL;
    unsigned int params, count = 0;
    bool use_generic_payload = false;
    char cmd_file_path[FILE_PATH_MAX_LENGTH];
    unsigned int sleep_dur = 0;
    char *token = NULL, *saveptr = NULL;

    if (argc < 3) {
        printf(SOUNDTRIGGER_TEST_USAGE);
        return 0;
    }

    /* arguments to start with number of sessions always */
    if ((strcmp(argv[1], "-ns") == 0)) {
         num_sessions  = atoi(argv[2]);
    }

    if ((num_sessions <= 0) || (num_sessions > MAX_SOUND_TRIGGER_SESSIONS)) {
        printf(SOUNDTRIGGER_TEST_USAGE);
        return 0;
    }

    init_sm_session_data();
    i = 3;

    while (count < num_sessions) {
        unsigned int n = 6;
        if ((i < argc) && (strcmp(argv[i], "-id") == 0) && ((i+1) < argc)) {
            index++;
            sound_trigger_info[index].session_id  = atoi(argv[i+1]);
            params = 1;
        }
        if (((i+2) < argc) && (strcmp(argv[i+2], "-sm") == 0)) {
            if (((i+3) < argc) && (index >= 0)) {
                strlcpy(sound_trigger_info[index].sm_file_path, argv[i+3],
                       sizeof(sound_trigger_info[index].sm_file_path));
                params++;
            }
        }
        if (((i+4) < argc) && (strcmp(argv[i+4], "-nk") == 0)) {
            if (((i+5) < argc) && (index >= 0)) {
                sound_trigger_info[index].num_kws = atoi(argv[i+5]);
                params++;
            }
        }
        if (((i+6) < argc) && (strcmp(argv[i+6], "-nu") == 0)) {
            if (((i+7) < argc) && (index >= 0)) {
                sound_trigger_info[index].num_users = atoi(argv[i+7]);
                params++;
                n = n + 2;
            }
        }
        if (((i+n) < argc) && (strcmp(argv[i+n], "-vendor_uuid") == 0)) {
            if (((i+(n+1)) < argc) && (index >= 0)) {
                string_to_uuid(argv[i+(n+1)],
                               &sound_trigger_info[index].vendor_uuid);
                params++;
                n = n + 2;
            }
        }
        if (params < MIN_REQ_PARAMS_PER_SESSION ) {
            printf("Insufficient data entered for session %d\n", count);
            printf(SOUNDTRIGGER_TEST_USAGE);
            goto exit;
        }
        count++;
        i += (params * 2);

        if (!memcmp(&sound_trigger_info[index].vendor_uuid, &qc_arm_uuid,
            sizeof(sound_trigger_uuid_t))) {
            printf("Versioned detection event\n");
            sound_trigger_info[index].versioned_det_event_payload = true;
        }
    }

    if (++index != num_sessions) {
        printf("Insufficient data entered for sessions\n");
        printf(SOUNDTRIGGER_TEST_USAGE);
        goto exit;
    }

    while (i < argc) {
        if ((strcmp(argv[i], "-user") == 0) && ((i+1) < argc)) {
            user_verification =
                  (0 == strncasecmp(argv[i+1], "true", 4))? true:false;
        } else if ((strcmp(argv[i], "-lab") == 0) && ((i+1) < argc)) {
            lookahead_buffer =
                  (0 == strncasecmp(argv[i+1], "true", 4))? true:false;
            usr_req_lookahead_buffer = true;
        } else if ((strcmp(argv[i], "-lab_duration") == 0) && ((i+1) < argc)) {
            lab_duration = atoi(argv[i+1]);
        } else if ((strcmp(argv[i], "-kb") == 0) && ((i+1) < argc)) {
            keyword_buffer =
                  (0 == strncasecmp(argv[i+1], "true", 4))? true:false;
        } else if ((strcmp(argv[i], "-kb_duration") == 0) && ((i+1) < argc)) {
            kb_duration_ms = atoi(argv[i+1]);
        } else if ((strcmp(argv[i], "-pre_roll_duration") == 0) && ((i+1) < argc)) {
            pre_roll_duration_ms = atoi(argv[i+1]);
        } else if ((strcmp(argv[i], "-kwcnf") == 0) && ((i+1) < argc)) {
            kw_conf = atoi(argv[i+1]);
        } else if ((strcmp(argv[i], "-usrcnf") == 0) && ((i+1) < argc)) {
            user_conf = atoi(argv[i+1]);
        } else if ((strcmp(argv[i], "-cnn_kwcnf") == 0) && ((i+1) < argc)) {
            cnn_kw_conf = atoi(argv[i+1]);
        } else if ((strcmp(argv[i], "-vop_usrcnf") == 0) && ((i+1) < argc)) {
            vop_user_conf = atoi(argv[i+1]);
        } else if ((strcmp(argv[i], "-generic") == 0) && ((i+1) < argc)) {
            use_generic_payload = (0 == strncasecmp(argv[i+1], "true", 4))? true:false;
        } else if ((strcmp(argv[i], "-cmd_file") == 0) && ((i+1) < argc)) {
            strlcpy(cmd_file_path, argv[i+1], sizeof(cmd_file_path));
            cmd_fp = fopen(cmd_file_path, "rb");
            if (cmd_fp == NULL) {
                printf("Could not open command file path : %s\n", cmd_file_path);
                goto exit;
            }
        } else {
            printf("Invalid syntax\n");
            printf(SOUNDTRIGGER_TEST_USAGE);
            goto exit;
        }
        i += 2;
    }

    /* Use generic payload, if using new params or if this is requested explicitly */
    if (cnn_kw_conf || vop_user_conf || pre_roll_duration_ms || use_generic_payload)
        generic_payload_size += sizeof(struct opaque_param_header) +
                                sizeof(struct confidence_levels_info);

    if (generic_payload_size && keyword_buffer)
        generic_payload_size += sizeof(struct opaque_param_header) +
                                sizeof(struct hist_buffer_info);

    if (usr_req_lookahead_buffer) {
        if ((lookahead_buffer == false) && (keyword_buffer == true)) {
            printf("Invalid usecase: lab can't be false when keyword buffer is true ");
            status = -EINVAL;
            goto exit;
        }
    }
    printf("keyword buffer %d\n",keyword_buffer);
    capture_requested = (lookahead_buffer || keyword_buffer) ? true : false;
    total_duration_ms = (lookahead_buffer ? lab_duration * 1000 : 0) +
                        (keyword_buffer ? kb_duration_ms : 0) + pre_roll_duration_ms;

    pa_qst_handle = pa_qst_init(PA_QST_MODULE_ID_PRIMARY);
    if (NULL == pa_qst_handle) {
        printf("pa_qst_init() failed\n");
        status = -EINVAL;
        goto exit;
    }

    for (k = 0; k < num_sessions; k++) {
        unsigned int opaque_data_size = 0;
        unsigned int num_kws = sound_trigger_info[k].num_kws;
        unsigned int num_users =
                 user_verification ? sound_trigger_info[k].num_users : 0;
        pa_qst_ses_handle_t ses_handle = 0;
        struct sound_trigger_recognition_config *rc_config = NULL;

        if (fp)
            fclose(fp);
        fp = fopen(sound_trigger_info[k].sm_file_path, "rb");
        if (fp == NULL) {
            printf("Could not open sound model file : %s\n",
                                   sound_trigger_info[k].sm_file_path);
            goto error;
        }

        /* Get the sound mode size i.e. file size */
        fseek( fp, 0, SEEK_END);
        sm_data_size  = ftell(fp);
        fseek( fp, 0, SEEK_SET);

        sound_model_size = sizeof(struct sound_trigger_phrase_sound_model) + sm_data_size;
        if (sound_model)
            free(sound_model);

        sound_model = (struct sound_trigger_phrase_sound_model *)calloc(1, sound_model_size);
        if (sound_model == NULL) {
            printf("Could not allocate memory for sound model");
           goto error;
        }

        sound_model->common.type = SOUND_MODEL_TYPE_KEYPHRASE;
        sound_model->common.data_size = sm_data_size;
        sound_model->common.data_offset = sizeof(*sound_model);
        sound_model->num_phrases = num_kws;
        for (i = 0; i < num_kws; i++) {
            sound_model->phrases[i].num_users = num_users;
            if (user_verification)
                sound_model->phrases[i].recognition_mode = RECOGNITION_MODE_VOICE_TRIGGER |
                                     RECOGNITION_MODE_USER_IDENTIFICATION;
            else
                sound_model->phrases[i].recognition_mode = RECOGNITION_MODE_VOICE_TRIGGER;
        }
        int bytes_read = fread((char*)sound_model+sound_model->common.data_offset , 1, sm_data_size , fp);
        printf("bytes from the file %d\n", bytes_read);
        if (bytes_read != sm_data_size) {
            printf("Something wrong while reading data from file: bytes_read %d file_size %d", bytes_read, sm_data_size);
            goto error;
        }

        memcpy(&sound_model->common.vendor_uuid, &sound_trigger_info[k].vendor_uuid,
               sizeof(sound_trigger_uuid_t));
        printf("sound model data_size %d data_offset %d\n", sm_data_size, sound_model->common.data_offset);
        status = pa_qst_load_sound_model(pa_qst_handle, &sound_model->common, NULL, NULL, &ses_handle);
        if (OK != status) {
            printf("load_sound_model failed\n");
            goto error;
        }
        sound_trigger_info[k].loaded = true;

        if (generic_payload_size != 0)
            opaque_data_size = generic_payload_size;
        else if (keyword_buffer)
            opaque_data_size = sizeof(struct keyword_buffer_config);

        rc_config_size = sizeof(struct sound_trigger_recognition_config) + opaque_data_size;
        sound_trigger_info[k].rc_config = (struct sound_trigger_recognition_config *)calloc(1, rc_config_size);
        if (sound_trigger_info[k].rc_config == NULL) {
            printf("Could not allocate memory for sm data recognition config");
            goto error;
        }
        rc_config = sound_trigger_info[k].rc_config;
        rc_config->capture_handle = AUDIO_IO_HANDLE_NONE;
        rc_config->capture_device = AUDIO_DEVICE_NONE;
        rc_config->capture_requested = capture_requested;
        rc_config->num_phrases = num_kws;
        rc_config->data_size = opaque_data_size;
        rc_config->data_offset = opaque_data_size ? sizeof(struct sound_trigger_recognition_config) : 0;

        if (generic_payload_size != 0) {
            fill_opaque_data(rc_config, num_kws, num_users, kw_conf, user_conf,
                             cnn_kw_conf, vop_user_conf, keyword_buffer);
        } else if (keyword_buffer) {
            kb_config.version = SM_MINOR_VERSION;
            kb_config.kb_duration = kb_duration_ms;
            memcpy((char *) rc_config + rc_config->data_offset, &kb_config, opaque_data_size);
        }
        int user_id = num_kws; //user_id should start from num_kws
        for (i = 0; i < num_kws; i++) {
            rc_config->phrases[i].id = i;
            rc_config->phrases[i].confidence_level = kw_conf;
            rc_config->phrases[i].num_levels = num_users;
            for (j = 0; j < num_users; j++) {
                rc_config->phrases[i].levels[j].level = user_conf;
                rc_config->phrases[i].levels[j].user_id = user_id++;
            }
            if (user_verification)
                rc_config->phrases[i].recognition_modes = RECOGNITION_MODE_VOICE_TRIGGER |
                             RECOGNITION_MODE_USER_IDENTIFICATION;
            else
                rc_config->phrases[i].recognition_modes = RECOGNITION_MODE_VOICE_TRIGGER;
        }

        sound_trigger_info[k].ses_handle = ses_handle;
        printf("[%d]session params %p, %p, %d\n", k, &sound_trigger_info[k], rc_config, ses_handle);
    }

    do {
        if (cmd_fp) {
            printf("Reading commands from file %s\n", cmd_file_path);
            fgets(command, 128, cmd_fp);
        } else {
            printf("Enter command in following format:\n");
            printf("\t<session_id:start/stop/set_param/get_param> (ex - 1:start)\n");
            printf("\t<global_set_param/exit>\n");
            printf(">> ");
            fgets(command, 128, stdin);
        }
        printf("Received the command: %s\n", command);

        /* Process session independent commands */
        if (!strncmp(command, "exit", 4)) {
            printf("exiting the loop ..\n");
            exit_loop = true;
            continue;
        }

        if (!strncmp(command, "sleep", 5)) {
            token = strtok_r(command, "=", &saveptr);
            if (token == NULL) {
                printf("Error: Invalid sleep command format\n");
                continue;
            }

            token = strtok_r(NULL, "\0", &saveptr);
            if (token == NULL) {
                printf("Invalid sleep duration\n");
                continue;
            }

            sleep_dur = atoi(token);
            if (sleep_dur) {
                printf("Issue sleep for duration %d seconds\n", sleep_dur);
                sleep(sleep_dur);
                printf("Wake up after sleep\n");
            } else {
                printf("Ignore 0sec sleep\n");
            }
            continue;
        }

        if (!strncmp(command, "global_set_param", 16)) {
            printf("in global set parameters\n");
            const char *param = handle_set_parameters();
            if (param == NULL)
                continue;
            printf("global param to set %s\n", param);
            pa_qst_ses_handle_t global_ses_handle = 0;
            status = pa_qst_set_parameters(pa_qst_handle, global_ses_handle, param);
            if (param)
                free((void *)param);
            if (OK != status) {
                printf("Global set parameters failed\n");
                exit_loop = true;
            }
            continue;
        }

        /* Process session specific commands */
        char *token = strtok_r(command, ":", &saveptr);
        if (token == NULL) {
            printf("Error: Invalid command entered: %s\n", command);
            continue;
        }
        int ses_id = atoi(token);
        if (ses_id == 0 && strncmp(token, "0", 1)) {
            printf("Enter valid command: %s\n", command);
            continue;
        }
        struct sm_session_data *ses_data = get_sm_session_data(ses_id);
        if (ses_data == NULL) {
            printf("Error: Invalid sound model handle %d\n", ses_id);
            continue;
        }

        token = strtok_r(NULL, "\0", &saveptr);
        if (token == NULL) {
            printf("Invalid cmd following session id %d:%s\n",ses_id, command);
            continue;
        }
        printf("[%d][%p] command entered: %s\n", ses_id, ses_data, token);
        struct sound_trigger_recognition_config *rc_config = ses_data->rc_config;
        pa_qst_ses_handle_t ses_handle = ses_data->ses_handle;

        if (!strncmp(token, "start", 5)) {
            printf("[%d] in start, ses state %d\n", ses_id, ses_data->started);
            if (ses_data->started)
                continue;
            status = pa_qst_start_recognition(pa_qst_handle, ses_handle,
                                            rc_config, eventCallback, NULL);
            if (OK != status) {
                printf("start_recognition failed\n");
                exit_loop = true;
            }
            ses_data->started = true;
            ses_data->counter = 0;
        } else if (!strncmp(token, "stop", 4)) {
            printf("[%d] in stop, ses state %d\n", ses_id, ses_data->started);
            if (!ses_data->started)
                continue;
            status = pa_qst_stop_recognition(pa_qst_handle, ses_handle);
            if (OK != status) {
                printf("stop_recognition failed\n");
                exit_loop = true;
            }
            ses_data->started = false;
        } else if (!strncmp(token, "set_param", 9)) {
            printf("[%d] in set parameters %d\n", ses_id, ses_data->started);
            const char *param = handle_set_parameters();
            if (param == NULL)
                continue;
            printf("[%d] param to set %s\n", ses_id, param);
            status = pa_qst_set_parameters(pa_qst_handle, ses_handle, param);
            if (param)
                free((void *)param);
            if (OK != status) {
                printf("set parameters failed\n");
                exit_loop = true;
            }
        } else if (!strncmp(token, "get_param", 9)) {
            printf("[%d] in get parameters %d\n", ses_id, ses_data->started);
            char value[128];
            const char *param = handle_get_parameters();
            size_t param_data_size;
            if (param == NULL)
                continue;
            printf("[%d] param to get %s\n", ses_id, param);
            status = pa_qst_get_param_data(pa_qst_handle, ses_handle, param,
                        (void *)&payload, payload_size, &param_data_size);
            if (status < 0) {
                printf("[%d] failed to get param data %s\n", ses_id, param);
            } else {
                process_get_param_data(param, &payload, param_data_size);
            }
            if (param)
                free((void *)param);
        } else {
            printf("Invalid session command\n");
        }
    } while(!exit_loop);

error:
    for (i = 0; i < num_sessions; i++) {
        pa_qst_ses_handle_t ses_handle = sound_trigger_info[i].ses_handle;
        if (sound_trigger_info[i].started) {
            status = pa_qst_stop_recognition(pa_qst_handle, ses_handle);
            if (OK != status)
                printf("stop_recognition failed\n");
            sound_trigger_info[i].started = false;
        }
        if (sound_trigger_info[i].loaded) {
            status = pa_qst_unload_sound_model(pa_qst_handle, ses_handle);
            if (OK != status)
                printf("unload_sound_model failed\n");
            sound_trigger_info[i].loaded = false;
        }
    }

    status = pa_qst_deinit(pa_qst_handle);
    if (OK != status) {
       printf("pa_qst_deinit failed, status %d\n", status);
    }

    if (sound_model)
       free(sound_model);

    if (fp)
        fclose(fp);

exit:
    if (cmd_fp)
        fclose(cmd_fp);

    deinit_sm_session_data();
    return status;
}
