/******************************************************************************
  @file    io-p.c
  @brief   Implementation of performance server module

  DESCRIPTION

  ---------------------------------------------------------------------------
  Copyright (c) 2011-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/

#define ATRACE_TAG ATRACE_TAG_ALWAYS

#include "io-p.h"

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <signal.h>
#include <cutils/properties.h>
#include <cutils/trace.h>
#include <io-prefetch/list_capture.h>
#include <cutils/sockets.h>
#include "EventQueue.h"

#include <io-prefetch/dblayer.h>
#include <io-prefetch/uba.h>

#include <client.h>

#include <dlfcn.h>

#define LOG_TAG           "ANDR-IOP"
#include <log/log.h>

#include "MpctlUtils.h"

static pthread_mutex_t subm_req_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t ux_trigger_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t ux_trigger_cond = PTHREAD_COND_INITIALIZER;
static EventQueue IOPevqueue;
static EventQueue UXEevqueue;
char *preferred_apps;
int uxe_prop_disable = 0;
bool iop_init = false;
bool uxe_init = false;
bool pa_ready = false;

#define BILLION             1000000000L

#define MIN_FREQ_REQ      0
#define MAX_FREQ_REQ      1
#define PKG_LEN           1024

#ifdef SERVER

#define IOP_NO_RECENT_APP 7
/* LAT_THRESHOLD = (1 + %x)
   x is % ceil */
#define LAT_HIGH_THRESHOLD 500
#define LAT_LOW_THRESHOLD 50
#define strcat_sz (PREFERRED_APP_COUNT*(PKG_NAME_LEN+1))

char recent_list[IOP_NO_RECENT_APP][PKG_LEN];
int recent_list_cnt = 0;
int uxe_trigger_freq = 1;

static pthread_t iop_server_thread;
static pthread_t uxe_server_thread;
static iop_msg_t msg;

extern int init_uba();
extern void shutdown_uba();
extern int create_database();
extern void start_playback(char *pkg_name);
extern void stop_playback();

uint64_t time_delta;

int is_boot_complete() {
    char boot_completed[PROPERTY_VALUE_MAX];
    int value = 0;

    property_get("vendor.post_boot.parsed", boot_completed, "0");
    value = strtod(boot_completed, NULL);

    if (value) {
        return 1;
    } else {
        return 0;
    }
}

int uxe_disabled() {
    char property[PROPERTY_VALUE_MAX];
    int enable_uxe = 0;

    strlcpy(property,perf_get_prop("vendor.iop.enable_uxe" , "1").value, PROPERTY_VALUE_MAX);
    property[PROPERTY_VALUE_MAX-1]='\0';

    enable_uxe = strtod(property, NULL);

    if (enable_uxe) {
        return 0;
    } else {
        return 1;
    }
}


/*=========================================================================================================================*/

static void *uxe_server(void *data)
{
    int rc, cmd;
    iop_msg_t *msg = NULL;

    /* Main loop */
    for (;;) {
        QLOGI("UXEngine: Waiting on uxe_server_submit_req in uxe_server\n");

        EventData *evData = UXEevqueue.Wait();

        if (!evData || !evData->mEvData) {
            continue;
        }

        cmd = evData->mEvType;
        msg = (iop_msg_t *)evData->mEvData;

        switch (cmd) {
            case UXENGINE_CMD_PERFLOCK_TRIGGER:
            {
                static int back_to_home = 1;
                pa_ready = false;
                if(uxe_prop_disable || !is_boot_complete())
                {
                    QLOGI("UXEngine is disabled");
                    pthread_cond_signal(&ux_trigger_cond);
                    break;
                }

                if (preferred_apps == NULL) {
                    pthread_cond_signal(&ux_trigger_cond);
                    break;
                }

                // get_preferred_apps.
                if(msg->opcode == UXE_TRIGGER || msg->opcode == UXE_ULMK_TRIGGER)
                {
                    // Trigger frequency. Currently set to trigger
                    // every back-to-home.
                    if (back_to_home < uxe_trigger_freq) {
                        back_to_home++;
                        pthread_cond_signal(&ux_trigger_cond);
                        break;
                    }
                    QLOGI("UXEngine, Received back to home");
                    char *final_out[PREFERRED_APP_COUNT];
                    int uba_return = 0, i = 0;

                    for (i = 0; i < PREFERRED_APP_COUNT; i++) {
                        final_out[i] = (char*) malloc(PKG_NAME_LEN);
                        final_out[i][0] = '\0';
                    }

                    if (msg->opcode == UXE_TRIGGER) {
                        uba_return = get_preferred_apps(final_out, 0, NULL, -1, false);
                    } else {
                        uba_return = get_preferred_apps(final_out, 1, NULL, -1, false);
                    }
                    QLOGI("Final OUTPUT: Preferred Apps returned : %d\n", uba_return);

                    for (i = 0; i < uba_return ; i++) {
                        if (final_out[i][0] != 0) {
                            QLOGI("Final OUTPUT: Apps returned: %s\n", final_out[i]);
                            strlcat(preferred_apps,final_out[i],strcat_sz);
                            strlcat(preferred_apps,"/",strcat_sz);
                        }
                    }
                    pa_ready = true;
                    // return to F/W once HIDL is implemented
                    back_to_home = 1;
                    for (i = 0; i < PREFERRED_APP_COUNT; i++) {
                        free(final_out[i]);
                    }
                    QLOGI("UXEngine: Set preferred apps in uxe_server: %s\n", preferred_apps);
                    pthread_cond_signal(&ux_trigger_cond);
                }
                else if (msg->opcode == UXE_TRIGGER_LIST_FAV_APPS) {
                    char *final_out[PREFERRED_APP_COUNT];
                    char individual_time_slot_fav_apps[PREFERRED_APP_COUNT * APP_NAME_LEN];
                    int uba_return = 0, i = 0;

                    for (i = 0; i < PREFERRED_APP_COUNT; i++) {
                        final_out[i] = &individual_time_slot_fav_apps[i * APP_NAME_LEN];
                        final_out[i][0] = '\0';
                    }
                    char * weekday[] = {"true", "false"};
                    for (int time_slot_iter = 1; time_slot_iter <= 4; time_slot_iter++) {
                        for(int week_day_iter = 0; week_day_iter < 2; week_day_iter++) {
                            uba_return = get_preferred_apps(final_out, 1, weekday[week_day_iter], time_slot_iter, false);

                            QLOGI("Final OUTPUT:       List of all Preferred Apps returned : %d\n", uba_return);

                            for (i = 0; i < uba_return ; i++) {
                                if (final_out[i][0] != '\0') {
                                    QLOGI("Final OUTPUT: Apps returned: %s\n", final_out[i]);
                                    strlcat(preferred_apps,final_out[i],strcat_sz);
                                    /*TODO preferred_apps string is of strcat_sz size. Above Strlcat buffer length should be 8 * 8 * 256 = 8 * 2048,
                                           So using strcat_sz, as it is already 8 * 2048.
                                           If PKG_NAME_LEN changes, then strcat_sz changes. Then, we need to adjust buffer length according to it.*/
                                    strlcat(preferred_apps,"/",strcat_sz);
                                    strlcpy(final_out[i], "", APP_NAME_LEN);
                                }
                            }
                            strlcat(preferred_apps,"=",strcat_sz);//separating delimiter for fav apps of different time slots
                        }
                    }

                    QLOGI("UXEngine: Set All preferred apps in uxe_server: %s\n", preferred_apps);
                    pthread_cond_signal(&ux_trigger_cond);
                }
                break;
            }
            default:
                QLOGI("Unknown command %d", cmd);
        }
        UXEevqueue.GetDataPool().Return(evData);
    }
    QLOGI("UXE server thread exit due to rc=%d", rc);
    return NULL;
}

static void *iop_server(void *data)
{
    int rc, cmd;
    iop_msg_t *msg = NULL;
    (void)data;
    bool is_db_init = false;
    char tmp_pkg_name[PKG_NAME_LEN];
    int bindApp_dur = 0, disAct_dur = 0, avg_bindApp = 0, avg_disAct = 0;
    int pkg_count = 0, bindApp_count = 0, pkg_mismatch = 0, da_reset = 0;
    bool launching = false;

    memset(tmp_pkg_name, 0, PKG_NAME_LEN);
    /* Main loop */
    for (;;) {
       //wait for perflock commands
        EventData *evData = IOPevqueue.Wait();

        if (!evData || !evData->mEvData) {
            continue;
        }
        if(!is_boot_complete())
        {
            QLOGE("io prefetch is disabled waiting for boot_completed");
            continue;
        }
        if(is_db_init == false)
        {
            if(create_database() == 0)
            {
                //Success
                is_db_init = true;
            }
        }

        cmd = evData->mEvType;
        msg = (iop_msg_t *)evData->mEvData;
        pkg_ux_details pkg_info;
        int time_slot = 0;
        pkg_ux_lat_details ux_lat;

        switch (cmd) {
            case UXENGINE_CMD_PERFLOCK_EVENTS:
            {
                if(uxe_prop_disable || !is_boot_complete())
                {
                    QLOGE("UXEngine is disabled");
                    break;
                }

                int opcode = msg->opcode;
                char in_pkg_name[PKG_NAME_LEN];
                strlcpy(in_pkg_name, msg->pkg_name, PKG_NAME_LEN);

                //Opcode = 2 : Client is sending bindApp duration
                if(opcode == UXE_EVENT_BINDAPP)
                {
                    bool pkg_match = false;
                    if (disAct_dur != 0) {
                        disAct_dur = 0;
                    }

                    if (!strncmp(in_pkg_name, tmp_pkg_name, PKG_NAME_LEN)) {
                        pkg_match = true;
                    } else {
                        pkg_match = false;
                    }

                    if (!pkg_match && launching) {
                        // Empty app launch in-between app-launch. Discard.
                        break;
                    }

                    bindApp_dur = msg->lat;
                    bindApp_count = get_total_pkg_bindapp_count(in_pkg_name);
                    QLOGI("UXEngine: Received bindApp duration: %d pkg_name %s tmp_pkg_name: %s\n",
                                                            bindApp_dur, in_pkg_name, tmp_pkg_name);
                    if (bindApp_count) {
                        int lat_thres = 0;
                        get_ux_lat_pkg(in_pkg_name, &ux_lat);
                        QLOGI("UXEngine: Average bindApp before: %d bindApp_count : %d\n",
                                                       ux_lat.bindApp_dur, bindApp_count);
                        if (ux_lat.bindApp_dur != 0)
                             lat_thres = (bindApp_dur*100)/ux_lat.bindApp_dur;
                        if (ux_lat.bindApp_dur != 0 && (LAT_LOW_THRESHOLD < lat_thres && LAT_HIGH_THRESHOLD > lat_thres) && bindApp_dur < 4000) {
                            avg_bindApp = ((bindApp_count) * ux_lat.bindApp_dur + bindApp_dur) / (bindApp_count+1);
                        } else {
                            avg_bindApp = ux_lat.bindApp_dur;
                            if (ux_lat.bindApp_dur == 0)
                                avg_bindApp = bindApp_dur;
                        }
                        avg_disAct = ux_lat.disAct_dur;
                        QLOGI("UXEngine: Average bindApp: %d for app: %s bindApp_count: %d\n",
                                                     avg_bindApp, in_pkg_name, bindApp_count);
                        bindApp_dur = avg_bindApp;
                    } else {
                        avg_disAct = 0;
                    }

                    if (!pkg_match)
                    {
                        // Empty app launch. Update db table.
                        QLOGI("UXEngine: Updating bindApp duration: %d pkg_name %s\n",
                                                            bindApp_dur, in_pkg_name);
                        update_ux_lat_details(in_pkg_name, bindApp_dur, avg_disAct, 0, 1);
                        bindApp_dur = 0;
                        avg_bindApp = 0;
                        avg_disAct = 0;
                    }
                    /* Received bindApp matches launching process.
                       Hold off db table update until displayedAct */
                }

                //Opcode = 3 : Client is sending DisplayedActivity
                if (opcode == UXE_EVENT_DISPLAYED_ACT)
                {
                    int non_empty_launch = 1;
                    bool pkg_match = true;
                    if (tmp_pkg_name[0] == 0)
                        goto disAct_cleanup;

                    if (!strncmp(in_pkg_name, tmp_pkg_name, PKG_NAME_LEN)) {
                        pkg_match = true;
                    } else {
                        //Received unexpected displayed activity.
                        //Update regardless, but for the correct app.
                        //skip update
                        QLOGI("UXEngine: Skip. Received weird DA: %s\n", in_pkg_name);
                        goto disAct_cleanup;
                    }

                    disAct_dur = msg->lat;
                    pkg_count = get_total_pkg_use_count(in_pkg_name);
                    // Empty app launch
                    if ((bindApp_dur == 0 && launching) || !pkg_match) {
                        QLOGI("UXEngine: Empty app launch. Just update DA. pkg_name: %s \n", in_pkg_name);
                        bindApp_count = get_total_pkg_bindapp_count(in_pkg_name);
                        get_ux_lat_pkg(in_pkg_name, &ux_lat);
                        // Launching process would have definitely had a bindApp.
                        // If count=0, something wrong. Skip update.
                        if(bindApp_count)
                            bindApp_dur = ux_lat.bindApp_dur;
                        else
                            goto disAct_cleanup;
                        avg_disAct = ux_lat.disAct_dur;
                        non_empty_launch = 0;
                    }

                    QLOGI("UXEngine: bindApp duration: %d, DisplayedActivity: %d\n", bindApp_dur, disAct_dur);
                    if (pkg_count - 1) {
                        QLOGI("UXEngine: Average displayed activity before: %d pkg_count :%d\n", avg_disAct, pkg_count);
                        int lat_thres = 0;
                        if (avg_disAct != 0)
                            lat_thres = (disAct_dur*100)/avg_disAct;
                        if (avg_disAct != 0 && pkg_count != 0 && (LAT_LOW_THRESHOLD < lat_thres && LAT_HIGH_THRESHOLD > lat_thres) && disAct_dur < 5000) {
                            avg_disAct = ((pkg_count - 1) * avg_disAct + disAct_dur) / pkg_count;
                            disAct_dur = avg_disAct;
                        }
                        QLOGI("UXEngine: Average displayed activity after: %d, bindApp_count: %d\n", avg_disAct);
                        if(avg_disAct != 0)
                            disAct_dur = avg_disAct;
                    }
                    QLOGI("UXEngine: Updating bindApp & DA duration: %d %d pkg_name %s\n",
                                                         bindApp_dur, disAct_dur, in_pkg_name);
                    update_ux_lat_details(in_pkg_name, bindApp_dur, disAct_dur, 0, non_empty_launch);

                    disAct_cleanup:
                        // Refresh preferred apps & palm table after launch.
                        char *final_out[PREFERRED_APP_COUNT];
                        int uba_return = 0, i = 0;
                        for (i = 0; i < PREFERRED_APP_COUNT; i++) {
                            final_out[i] = (char*) malloc(PKG_NAME_LEN);
                            final_out[i][0] = '\0';
                        }
                        uba_return = get_preferred_apps(final_out, 0, NULL, -1, true);
                        update_palm_table(in_pkg_name, 0, 1);
                        //Cleanup
                        for (i = 0; i < PREFERRED_APP_COUNT; i++) {
                            free(final_out[i]);
                        }
                        disAct_dur = 0;
                        bindApp_dur = 0;
                        avg_bindApp = 0;
                        avg_disAct = 0;
                        pkg_count = 0;
                        launching = false;
                        memset(tmp_pkg_name, 0, PKG_NAME_LEN);
                        QLOGI("UXEngine: Finished ux_lat update & reset \n");
                }

                if(opcode == UXE_EVENT_KILL)
                {
                    QLOGI("UXEngine: Received app no-AM kill: %s\n", in_pkg_name);
                    update_palm_table(in_pkg_name, 1, 0);
                }

                if(opcode == UXE_EVENT_GAME)
                {
                    QLOGI("UXEngine: Received game info - %s\n", in_pkg_name);
                    // Overloading latency field in iop msg struct w/ game
                    // identity value 1 or 0.
                    int is_game = msg->lat;
                    if (is_game)
                        update_ux_lat_game_details(in_pkg_name, 0);
                }
                if(opcode == UXE_EVENT_SUB_LAUNCH)
                {
                    char *week_day = NULL;
                    week_day = (char *) malloc(6*sizeof(char));
                    if (week_day == NULL) {
                       //Malloc failed. Most-probably low on memory.
                       break;
                    }
                    strlcpy(pkg_info.pkg_name,in_pkg_name,PKG_NAME_LEN);
                    time(&pkg_info.last_time_launched);
                    compute_time_day_slot(week_day, &time_slot);
                    QLOGI("UXEngine Updating sub_launch Details: pkg_name: %s, week_day: %s, time_slot: %d %s\n", pkg_info.pkg_name, week_day, time_slot, tmp_pkg_name);
                    update_ux_pkg_details(pkg_info, week_day, time_slot, 1);
                    update_palm_table(msg->pkg_name, 0, 1);
                    free(week_day);
                }
                if(opcode == UXE_EVENT_PKG_UNINSTALL)
                {
                    QLOGI("UXEngine: Received pkg uninstall - %s\n", in_pkg_name);
                    int userId = msg->lat;
                    update_palm_table(in_pkg_name, 1, 0);
                    uninstall_pkg(in_pkg_name);
                }
                if(opcode == UXE_EVENT_PKG_INSTALL)
                {
                    QLOGI("UXEngine: Received pkg install - %s\n", in_pkg_name);
                    // install_code = 0 is fresh install, 1 is update.
                    int install_code = msg->lat;
                    /*
                        App newly installed. High chances of being frequently used.
                        Increase priority.
                        IOP file capture logic can benefit from knowing pkg install.
                    */
                }
                break;
            }
            case IOP_CMD_PERFLOCK_IOPREFETCH_START:
            {
                static bool is_in_recent_list = false;
                char enable_prefetch_property[PROPERTY_VALUE_MAX];
                char enable_prefetch_ofr_property[PROPERTY_VALUE_MAX];
                int enable_prefetcher = 0;
                int enable_prefetcher_ofr = 0;

                strlcpy(enable_prefetch_property,perf_get_prop("vendor.enable.prefetch" , "0").value, PROPERTY_VALUE_MAX);
                enable_prefetch_property[PROPERTY_VALUE_MAX-1]='\0';

                enable_prefetcher = strtod(enable_prefetch_property, NULL);

                strlcpy(enable_prefetch_ofr_property,perf_get_prop("vendor.iop.enable_prefetch_ofr" , "0").value, PROPERTY_VALUE_MAX);
                enable_prefetch_ofr_property[PROPERTY_VALUE_MAX-1]='\0';

                enable_prefetcher_ofr = strtod(enable_prefetch_ofr_property, NULL);

                // if PID < 0 consider it as playback operation
                if(msg->pid < 0)
                {
                    int ittr = 0;
                    char *week_day = NULL;
                    week_day = (char *) malloc(6*sizeof(char));
                    // Insert package into the table
                    if (week_day == NULL) {
                       //Malloc failed. Most-probably low on memory.
                       break;
                    }
                    strlcpy(pkg_info.pkg_name,msg->pkg_name,PKG_NAME_LEN);
                    strlcpy(tmp_pkg_name,pkg_info.pkg_name,PKG_NAME_LEN);
                    bindApp_dur = 0;
                    disAct_dur = 0;
                    launching = true;
                    time(&pkg_info.last_time_launched);
                    compute_time_day_slot(week_day, &time_slot);
                    QLOGI("UXEngine Updating Details: pkg_name: %s, week_day: %s, time_slot: %d %s\n", pkg_info.pkg_name, week_day, time_slot, tmp_pkg_name);
                    update_ux_pkg_details(pkg_info, week_day, time_slot, 0);
                    update_palm_table(msg->pkg_name, 0, 1);

                    QLOGI("UXEngine finished ux_pkg_details update \n");
                    free(week_day);
                    is_in_recent_list = false;
                    if(!enable_prefetcher)
                    {
                        QLOGE("io prefetch is disabled");
                        break;
                    }

                    //Check app is in recent list
                    for(ittr = 0; ittr < IOP_NO_RECENT_APP; ittr++)
                    {
                        if(0 == strcmp(msg->pkg_name,recent_list[ittr]))
                        {
                            is_in_recent_list = true;
                            QLOGE("is_in_recent_list is TRUE");
                            break;
                        }
                    }
                    // IF Application is in recent list, return
                    if(true == is_in_recent_list)
                    {
                        QLOGE("io prefetch is deactivate");
                        break;
                    }

                    if(recent_list_cnt == IOP_NO_RECENT_APP)
                        recent_list_cnt = 0;

                    //Copy the package name to recent list
                    strlcpy(recent_list[recent_list_cnt],msg->pkg_name,PKG_LEN);
                    recent_list_cnt++;

                    stop_capture();
                    stop_playback();
                    start_playback(msg->pkg_name);
                }
                // if PID > 0 then consider as capture operation
                if(msg->pid > 0)
                {
                    if(!enable_prefetcher)
                    {
                        QLOGE("io prefetch is disabled");
                        break;
                    }
                    if(true == is_in_recent_list)
                    {
                        QLOGE("io prefetch Capture is deactivated ");
                        break;
                    }
                    stop_capture();
                    start_capture(msg->pid,msg->pkg_name,msg->code_path,enable_prefetcher_ofr);
                }

                break;
            }

            case IOP_CMD_PERFLOCK_IOPREFETCH_STOP:
            {
                stop_capture();
                break;
            }

            default:
                QLOGE("Unknown command %d", cmd);
        }
        IOPevqueue.GetDataPool().Return(evData);
    }

    QLOGI("IOP server thread exit due to rc=%d", rc);
    return NULL;
}

//callbacks for eventqueue
static void *Alloccb() {
    void *mem = (void *) new iop_msg_t;
    return mem;
}

static void Dealloccb(void *mem) {
    if (NULL != mem) {
        delete (iop_msg_t *)mem;
    }
}

//interface implementation
int iop_server_init() {
    int rc1 = 0, stage = 0, rc2 = 0;
    int uba_rc = 0;
    char property[PROPERTY_VALUE_MAX];
    char trace_prop[PROPERTY_VALUE_MAX];

    QLOGI("IOP server starting");

    /* Enable traces by adding vendor.debug.trace.perf=1 into build.prop */
    if (property_get(PROP_NAME, trace_prop, NULL) > 0) {
        if (trace_prop[0] == '1') {
            perf_debug_output = PERF_SYSTRACE = atoi(trace_prop);
        }
    }

    preferred_apps = (char *) malloc (strcat_sz * sizeof(char));
    if (preferred_apps == NULL) {
        goto error;
    }
    memset(preferred_apps, 0, strcat_sz);
    preferred_apps[0] = '\0';

    IOPevqueue.GetDataPool().SetCBs(Alloccb, Dealloccb);

    rc1 = pthread_create(&iop_server_thread, NULL, iop_server, NULL);
    if (rc1 != 0) {
        stage = 3;
        goto error;
    }
    iop_init = true;

    if (uxe_disabled()) {
        uxe_prop_disable = 1;
    } else {
        uxe_prop_disable = 0;

        strlcpy(property,perf_get_prop("vendor.iop.uxe_trigger_freq" , "1").value, PROPERTY_VALUE_MAX);
        property[PROPERTY_VALUE_MAX-1]='\0';

        uxe_trigger_freq = atoi(property);
        UXEevqueue.GetDataPool().SetCBs(Alloccb, Dealloccb);
        rc2 = pthread_create(&uxe_server_thread, NULL, uxe_server, NULL);
        uba_rc = init_uba();
        if (rc2 != 0) {
            goto error;
        }
        if (uba_rc == 0) {
            QLOGE("Fail to init UBA");
            goto error;
        }
        uxe_init = true;
    }

    return 1;

error:
    QLOGE("Unable to create control service (stage=%d, rc1=%d rc2=%d uba_rc=%d)", stage, rc1, rc2, uba_rc);
    return 0;
}

void iop_server_exit()
{
    free(preferred_apps);
    shutdown_uba();
    pthread_join(iop_server_thread, NULL);
    pthread_join(uxe_server_thread, NULL);
    iop_init = false;
    uxe_init = false;
    pthread_cond_destroy(&ux_trigger_cond);
    pthread_mutex_destroy(&subm_req_mutex);
    pthread_mutex_destroy(&ux_trigger_mutex);
}

#endif /* SERVER */

char * uxe_server_submit_request(iop_msg_t *msg) {
    int size = 0;
    struct timespec trigger_timeout;
    EventData *evData;
    int *pl_args = NULL;
    int cmd = 0;

    if (!uxe_init)
        return NULL;
    pthread_mutex_lock(&ux_trigger_mutex);
    memset(preferred_apps, 0, strcat_sz);
    preferred_apps[0] = '\0';

    QLOGI("UXEngine Entered server submit opcode: %d\n", msg->opcode);
    //boot complete check
    if (NULL == msg) {
        pthread_mutex_unlock(&ux_trigger_mutex);
        return NULL;
    }
    cmd = msg->cmd;

    QLOGI("UXEngine PHAL: Received back-to-home. Cmd: %d\n", cmd);

    evData = UXEevqueue.GetDataPool().Get();
    if ((NULL == evData) || (NULL == evData->mEvData)) {
        QLOGE("UXEngine event data pool ran empty");
        pthread_mutex_unlock(&ux_trigger_mutex);
        return NULL;
    }
    iop_msg_t *pMsg = (iop_msg_t *)evData->mEvData;
    memset(pMsg, 0x00, sizeof(iop_msg_t));

    pMsg->opcode = msg->opcode;

    evData->mEvType = cmd;
    UXEevqueue.Wakeup(evData);
    QLOGI("UXEngine: Waiting for server to populate preferred_apps\n");
    clock_gettime(CLOCK_REALTIME, &trigger_timeout);
    //10ms
    trigger_timeout.tv_nsec += 10e7;
    //Nanosec overflow check
    if(trigger_timeout.tv_nsec > BILLION) {
        trigger_timeout.tv_sec += trigger_timeout.tv_nsec / BILLION;
        trigger_timeout.tv_nsec = trigger_timeout.tv_nsec % BILLION;
    }
    if (pthread_cond_timedwait(&ux_trigger_cond, &ux_trigger_mutex, &trigger_timeout) != 0) {
        QLOGE("UXEngine: Error no.: %d\n", errno);
        pthread_mutex_unlock(&ux_trigger_mutex);
        if (pa_ready)
            return preferred_apps;
        else
            return NULL;
    }
    // Read shared string here.
    QLOGI("UXEngine: Server request read string: %s\n", preferred_apps);

    pthread_mutex_unlock(&ux_trigger_mutex);
    return preferred_apps;/*TODO - While returning we are returning by reference. So when a new request comes back to back, we again
                                   memset preferred_apps which can corrupt the global variable.(the string we are still copying) */
}

int iop_server_submit_request(iop_msg_t *msg) {
    int size = 0;
    int handle = -1;
    EventData *evData;
    int *pl_args = NULL;
    int cmd = 0;
    bool bootComplete = false;
    char trace_buf[TRACE_BUF_SZ];

    if (!iop_init)
        return handle;

    //boot complete check
    if (NULL == msg) {
        return handle;
    }

    cmd = msg->cmd;

     /* Enable this log by adding vendor.debug.trace.perf=1 into build.prop */
    if (perf_debug_output) {
        snprintf(trace_buf, TRACE_BUF_SZ, "IOP HAL: Received pkg_name = %s pid = %d", msg->pkg_name,msg->pid);
        QLOGE("%s", trace_buf);
    }

    pthread_mutex_lock(&subm_req_mutex);
    evData = IOPevqueue.GetDataPool().Get();
    if ((NULL == evData) || (NULL == evData->mEvData)) {
        QLOGE("event data pool ran empty");
        pthread_mutex_unlock(&subm_req_mutex);
        return handle;
    }
    iop_msg_t *pMsg = (iop_msg_t *)evData->mEvData;
    memset(pMsg, 0x00, sizeof(iop_msg_t));

    if(IOP_CMD_PERFLOCK_IOPREFETCH_START==cmd)
    {
        pMsg->pid = msg->pid;
        strlcpy(pMsg->pkg_name, msg->pkg_name, PKG_LEN);
        strlcpy(pMsg->code_path, msg->code_path, PKG_LEN);
    } else if (UXENGINE_CMD_PERFLOCK_EVENTS==cmd) {
        pMsg->opcode = msg->opcode;
        pMsg->pid = msg->pid;
        strlcpy(pMsg->pkg_name, msg->pkg_name, PKG_LEN);
        pMsg->lat = msg->lat;
    }

    evData->mEvType = cmd;
    IOPevqueue.Wakeup(evData);

    pthread_mutex_unlock(&subm_req_mutex);
    return handle;
}
