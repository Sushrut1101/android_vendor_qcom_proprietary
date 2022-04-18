/*
 * Copyright (c) 2012,2017-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * 2012 Qualcomm Atheros, Inc..
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 *
 * =====================================================================================
 *
 *       Filename:  icm_spectral.c
 *
 *    Description:  ICM Spectral related changes
 *
 *        Version:  1.0
 *        Created:  04/19/2012 01:18:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  S.Karthikeyan (),
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <icm.h>
#include <sys/ioctl.h>
#include <string.h>
#include <sys/socket.h>
#include <net/if.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#include "icm_wal.h"
#define _LINUX_TYPES_H

#ifdef WLAN_SPECTRAL_ENABLE
#include "if_athioctl.h"
#ifndef __packed
#define __packed __attribute__((packed))
#endif
#include "spectral_ioctl.h"
#include "spectral_data.h"
#include "spec_msg_proto.h"
#include "ath_classifier.h"
#include "spectral.h"

#ifndef ATH_DEFAULT
#define ATH_DEFAULT "wifi0"
#endif


/*
 * Function     : icm_init_spectral
 * Description  : initialize spectral related info
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int icm_init_spectral(ICM_INFO_T* picm)
{
    int err = SUCCESS;
    ICM_SPECTRAL_INFO_T* psinfo = &picm->sinfo;

    if (picm->radio_ifname == NULL)
        return -EINVAL;

    os_strlcpy(psinfo->atd.ad_name, picm->radio_ifname,  sizeof(psinfo->atd.ad_name));
    psinfo->dwell_interval = CHANNEL_DWELL_INTERVAL;
    psinfo->dwell_interval_short = CHANNEL_DWELL_INTERVAL_SHORT;
    psinfo->spectral_scan_count = 0;
    psinfo->log_mode = SPECT_CLASS_DETECT_ALL;

    return err;
}

/*
 * Function     : icm_update_next_channel
 * Description  : initialize current active channel
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int icm_update_next_channel(ICM_INFO_T* picm)
{
    int status = FAILURE;
    int found = FALSE;
    ICM_CHANNEL_LIST_T *pchlist = NULL;

    if (picm->band == ICM_BAND_2_4G) {
        pchlist = &picm->chlist_bg;
    } else if (picm->band == ICM_BAND_5G) {
        pchlist = &picm->chlist_a;
    } else {
        pchlist = &picm->chlist;
    }

    /* check if we have reached the end of the list */
    if (pchlist->channel_index >= pchlist->count) {
        pchlist->channel_index = 0;
    }

    /* find the next channel, which is non-overlapping */
    while ((!found) && (pchlist->channel_index < pchlist->count)) {
        picm->current_channel = pchlist->ch[pchlist->channel_index].channel;

        if (pchlist->ch[pchlist->channel_index].non_overlapping_ch == TRUE) {
            found = TRUE;
            status = SUCCESS;
        }
        pchlist->channel_index++;
    }

    /* check if we completed one sweep */
    if (pchlist->channel_index >= pchlist->count) {
        picm->sinfo.spectral_scan_count++;
    }

    return status;
}

/*
 * Function     : icm_spectral_set_width_and_channel
 * Description  : set channel 1/6/11 in 20 MHz width
 *                for Spectral
 * Input params : pointer to icm info, channel
 * Return       : SUCCESS/FAILURE
 */
static int icm_spectral_set_width_and_channel(ICM_INFO_T *picm, int channel)
{
    struct nl80211_channel_config chan_config;
    struct nl80211_chan_args *chan_list;
    ICM_CH_BW_T channel_width;
    int ch_index = 0;
    char modestr[24] = {'\0'};
    ICM_DEV_INFO_T* pdev = get_pdev();
    int i = 0;

    channel_width = ICM_CH_BW_20;

    /* get channel index in picm->chlist.ch.. channel should be non-zero. */
    for (ch_index = 0; ch_index < picm->chlist.count; ch_index++)
        if (picm->chlist.ch[ch_index].channel == channel)
            break;

    if (ch_index == picm->chlist.count) {
        /* This is highly unlikely */
        err("selected channel %d is not present in supproted channel list", channel);
        return FAILURE;
    }

    if (channel_width >= ICM_CH_BW_INVALID) {
        err("Invalid channel width enumeration %u", channel_width);
        return FAILURE;
    }

    /* Set mode */
    if (icm_compose_phymode_str(picm->phy_spec,
                channel_width,
                modestr,
                sizeof(modestr)) == NULL) {
        return FAILURE;
    }

    chan_config.ifname = picm->dev_ifname;
    chan_config.reselect_reason = QCA_WLAN_VENDOR_ACS_SELECT_REASON_INIT;
    chan_config.num_channel = 1;

    chan_list = zalloc(sizeof(*chan_list) * chan_config.num_channel);
    if (chan_list == NULL) {
        icm_printf("ICM: Failed to allocate memory\n");
        return -1;
    }

    for (i = 0; i < chan_config.num_channel; i++) {
        if (channel <= 14 )
            chan_list[i].band = NL80211_BAND_2GHZ;
        else
            chan_list[i].band = NL80211_BAND_5GHZ;

        chan_list[i].pri_ch = channel; /* use sort_chan_list instead */
        chan_list[i].ht_sec_ch = 0;
#ifdef ICM_RTR_DRIVER
        chan_list[i].channel_width = channel_width;
#else
        chan_list[i].channel_width = convert_RTR_to_mbl_chan_width(channel_width);
#endif /* ICM_RTR_DRIVER */
        chan_list[i].vht_seg0_center_ch = 0;
        chan_list[i].vht_seg1_center_ch = 0;
    }
    chan_config.channel_list = chan_list;

    if (icm_wal_set_channel(picm, &chan_config)){
        err("Error in setting channel; ");
        return FAILURE;
    }
    ICM_DPRINTF(pdev, ICM_PRCTRL_FLAG_NONE, ICM_DEBUG_LEVEL_MAJOR,
                ICM_MODULE_ID_MAIN,
                "Successfully set channel %d mode %s for Spectral\n", channel, modestr);

    return SUCCESS;
}

/*
 * Function     : icm_switch_channel
 * Description  : initialize spectral related info
 * Input params : pointer to icm info structrue, is_first flag
 * Return       : success/failure
 *
 */
int icm_switch_channel(ICM_INFO_T* picm, bool is_first)
{
    char cmd[CMD_BUF_SIZE] = {'\0'};
    ICM_DEV_INFO_T* pdev = get_pdev();
    int ret;

    /* prevent channel switch */
    alarm(0);

    if (icm_update_next_channel(picm) == SUCCESS) {
        if (is_first) {
            icm_spectral_set_width_and_channel(picm, picm->current_channel);
        } else {
            snprintf(cmd, sizeof(cmd), "%s %s %s %1d", "iwconfig",
                     picm->dev_ifname, "channel", picm->current_channel);
            ICM_DPRINTF(pdev, ICM_PRCTRL_FLAG_NONE, ICM_DEBUG_LEVEL_MAJOR,
                        ICM_MODULE_ID_SPECTRAL, "Spectral scan on ch : %d\n",
                        picm->current_channel);

            /* execute the command */
            ret = system(cmd);

            if (ret == -1) {
                perror("icm : system");
                return FAILURE;
            }

            if (WEXITSTATUS(ret) != 0) {
                err("Error in setting channel; command was: %s", cmd);
                return FAILURE;
            }

            snprintf(cmd, sizeof(cmd), "%s %s %s", "iwlist",
                     picm->dev_ifname, "channel");

            /* execute the command */
            ret = system(cmd);
            if (ret == -1) {
                perror("icm : system");
                return FAILURE;
            }

            if (WEXITSTATUS(ret) != 0) {
                err("Error in listing channel; command was: %s", cmd);
                return FAILURE;
            }
        }
        /* initialize the classifier */
        picm->init_classifier = TRUE;
    }

    return SUCCESS;
}


/*
 * Function     : icm_process_spectral_msg
 * Description  : analyze spectral message
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int icm_process_spectral_msg(ICM_INFO_T* picm, struct spectral_samp_msg* msg)
{
    CLASSIFER_DATA_STRUCT *pclas    = NULL;
    ICM_CHANNEL_LIST_T* pchan       = &picm->chlist_bg;
    /* The above needs to fixed */
    u_int32_t chan_idx = 0;

    pclas = get_classifier_data(msg->macaddr);

    classifier_process_spectral_msg(msg, pclas, picm->sinfo.log_mode, 1);

    /* XXX: Modify the below if Spectral for 5 GHz is implemented. */
    if (msg->freq == 2484) {
        /* This is channel 14. The index into the array will be 14 - 1 = 13 */
        chan_idx = 13;
    } else {
        chan_idx = (msg->freq - CHAN1FREQ_MHZ) / PERCHANWIDTH_MHZ;
    }

    if (IS_MWO_DETECTED(pclas)) {
        pchan->ch[chan_idx].flags
            |= SPECT_CLASS_DETECT_MWO;
    }

    if (IS_CW_DETECTED(pclas)) {
        pchan->ch[chan_idx].flags
            |= SPECT_CLASS_DETECT_CW;
    }

    if (IS_WiFi_DETECTED(pclas)) {
        pchan->ch[chan_idx].flags
            |= SPECT_CLASS_DETECT_WiFi;
    }

    if (IS_CORDLESS_24_DETECTED(pclas)) {
        pchan->ch[chan_idx].flags
            |= SPECT_CLASS_DETECT_CORDLESS_24;
    }

    if (IS_CORDLESS_5_DETECTED(pclas)) {
        pchan->ch[chan_idx].flags
            |= SPECT_CLASS_DETECT_CORDLESS_5;
    }

    if (IS_BT_DETECTED(pclas)) {
        pchan->ch[chan_idx].flags
            |= SPECT_CLASS_DETECT_BT;
    }

    if (IS_FHSS_DETECTED(pclas)) {
        pchan->ch[chan_idx].flags
            |= SPECT_CLASS_DETECT_FHSS;
    }

    return 0;
}

/*
 * Function     : icm_handle_spectral_data
 * Description  : handle spectral data
 * Input params : pointer to dev info structure,
 *                pointer to icm info structrue (if this is NULL,
 *                the function will determine the appropriate
 *                picm from the spectral message).
 * Return       : success/failure
 *
 */
int icm_handle_spectral_data(ICM_DEV_INFO_T* pdev, ICM_INFO_T *picmarg)
{

    int sockerr = 0;
    ICM_NLSOCK_T *pnlinfo = ICM_GET_ADDR_OF_NLSOCK_INFO(pdev);
    ICM_INFO_T *picm = picmarg;
    int i = 0;

    struct spectral_samp_msg* ss_msg = NULL;

    assert(&pdev->msg != NULL);
    assert(pdev->nlh != NULL);

    /* receive spectral data from spectral driver */
    sockerr = recvmsg(pnlinfo->sock_fd, &pdev->msg, MSG_WAITALL);

    ss_msg = (struct spectral_samp_msg*)NLMSG_DATA(pdev->nlh);

    if (sockerr >= 0) {
        if (ss_msg->signature != SPECTRAL_SIGNATURE) {
            err("Received spectral message without valid signature");
            return FAILURE; 
        }

        if (picm == NULL) {
            /* Determine picm from SS message */
            /* XXX: Hashing can be used. But for now, when spectral
               samples are being received, picm is known and will not
               be passed to us NULL. Only the main select thread passes
               us a NULL thread, expecting EACS related messages.
               Hence, we keep things simple for now */
            for (i = 0; i < pdev->conf.num_radios; i++) {
                picm = get_picm(i);
                if (!memcmp(ss_msg->macaddr, picm->radio_addr, ETH_ALEN)) {
                    break;
                }
            }

            if ((i == pdev->conf.num_radios) || (!picm)) {
                /* In case we see spectral messages with unexpected MAC
                 * addresses (e.g. all 0's), this should be investigated.
                 */
                err("Received spectral message for unidentified interface");
                return FAILURE;
            }
        }

        if (pdev->nlh->nlmsg_len) {
            if (ss_msg->int_type == SPECTRAL_DCS_INT_NONE) {
                /* This is spectral data */
                icm_process_spectral_msg(picm, ss_msg);
            } else {
                /* This is a interference message */
                icm_change_channel(picm, ss_msg->int_type, ss_msg->dcs_enabled);
            }
        }
    } else if ((sockerr < 0) && (sockerr != EINTR)) {
        perror("icm : recvmsg");
    }

    return SUCCESS;
}

/*
 * Function     : icm_recv_spectral_data
 * Description  : receive spectral data from driver
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int icm_recv_spectral_data(ICM_INFO_T* picm)
{

    int fdmax;
    int fd = 0;
    fd_set master;
    fd_set read_fds;
    struct timeval tv;          /* range */
    int ret;
    int evret;
    ICM_EVENT_T event = ICM_EVENT_INVALID;
    int spectraldone = 0;
    int eventfd = -1;
    int nl80211_sock_fd = -1;
    int nl80211_event_fd = -1;
    ICM_NLSOCK_T* prtnlinfo = NULL;

    ICM_DEV_INFO_T* pdev = get_pdev();
    ICM_CONFIG_T* conf = &pdev->conf;

    ICM_NLSOCK_T* pnlinfo = NULL;
    ICM_INET_T* pinet = NULL;

    FD_ZERO(&master);
    FD_ZERO(&read_fds);

    pinet = ICM_GET_ADDR_OF_INETINFO(pdev);
    pnlinfo = ICM_GET_ADDR_OF_NLSOCK_INFO(pdev);

    eventfd = icm_register_event_recipient(pdev,
            ICM_EVENT_RECIPIENT_SPECTRAL_LOOP);

    nl80211_sock_fd = nl_socket_get_fd(pdev->nl80211->nl);
    nl80211_event_fd = nl_socket_get_fd(pdev->nl80211->nl_event);
    prtnlinfo = ICM_GET_ADDR_OF_RTNLSOCK_INFO(pdev);

    if (eventfd == -1 || nl80211_sock_fd == -1 || nl80211_event_fd == -1 ||
        prtnlinfo == NULL || pnlinfo == NULL) {
        err("Could not register for event reception");
        return FAILURE;
    }

    FD_SET(pnlinfo->sock_fd, &master);
    FD_SET(prtnlinfo->sock_fd, &master);
    FD_SET(eventfd, &master);
    FD_SET(nl80211_sock_fd, &master);
    FD_SET(nl80211_event_fd, &master);

    if (conf->server_mode == TRUE) {
        FD_SET(pinet->listener, &master);
    }

    fdmax = (eventfd > pnlinfo->sock_fd) ? \
            eventfd : pnlinfo->sock_fd;

    fdmax = (fdmax < nl80211_event_fd) ? nl80211_event_fd : fdmax;
    fdmax = (fdmax < nl80211_sock_fd) ? nl80211_sock_fd : fdmax;
    fdmax = (fdmax < prtnlinfo->sock_fd) ? prtnlinfo->sock_fd : fdmax;

    if (conf->server_mode == TRUE && fdmax < pinet->listener) {
        fdmax =  pinet->listener;
    }

    tv.tv_sec = (CHANNEL_DWELL_INTERVAL * 4);
    tv.tv_usec = 0;

    while(1) {

        read_fds = master;

        /* Wait until some thing happens */
        ret = select(fdmax + 1, &read_fds, NULL, NULL, &tv);

        if (ret == 0) {
            ICM_DPRINTF(pdev, ICM_PRCTRL_FLAG_NONE, ICM_DEBUG_LEVEL_MAJOR, ICM_MODULE_ID_SPECTRAL, "socket timeout\n");
            break;
        }

        if (ret < 0) {
            if (errno == EAGAIN || errno == EINTR) {
                continue;
            } else {
                perror("icm : select");
                return FAILURE;
            }
        }

        for (fd = 0; fd <= fdmax; fd++) {
            if (FD_ISSET(fd, &read_fds)) {
                if (fd == pnlinfo->sock_fd) {
                    if (icm_handle_spectral_data(pdev, picm) == FAILURE) {
                        icm_cleanup(pdev);
                        return FAILURE;
                    }
                } else if (fd == eventfd) {
                    evret = icm_get_event(pdev,
                            ICM_EVENT_RECIPIENT_SPECTRAL_LOOP,
                            &event);

                    if (evret < 0) {
                        err("Error retrieving event");
                        return FAILURE;
                    }

                    if (event == ICM_EVENT_SPECTRAL_SWEEP_DONE) {
                        ICM_DPRINTF(pdev, ICM_PRCTRL_FLAG_NONE, ICM_DEBUG_LEVEL_MAJOR, ICM_MODULE_ID_SPECTRAL, "Received Spectral Scan Done event\n");
                        spectraldone = 1;
                        break;
                    } else {
                        err("Unexpected event\n");
                        return FAILURE;
                    }
                } else if (fd == nl80211_event_fd) {
                    /* Data/event received on nl80211->nl_event socket. */
                    if (driver_nl80211_event_receive(pdev->nl80211->nl_cb, pdev->nl80211->nl_event) < 0) {
                        err("recvmsg on nl80211_event_fd failed");
                    }
                } else if (fd == nl80211_sock_fd) {
                    /* Data/event received on nl8011->nl socket. */
                    if (driver_nl80211_event_receive(pdev->nl80211->nl_cb, pdev->nl80211->nl) < 0) {
                        err("recvmsg on nl80211_sock_fd failed");
                    }
                } else if (fd == prtnlinfo->sock_fd) {
                    ICM_DPRINTF(pdev, ICM_PRCTRL_FLAG_NONE, ICM_DEBUG_LEVEL_MAJOR, ICM_MODULE_ID_MAIN,  "Received device state change event \n");
                    if(icm_parse_rtnetlink_msg(pdev) == FAILURE) {
                        err("parse rtnetlink message failed");
                        icm_cleanup(pdev);
                        return FAILURE;
                    }
               }
            }
        }

        if (spectraldone) {
            break;
        }
    }

    icm_deregister_event_recipient(pdev, ICM_EVENT_RECIPIENT_SPECTRAL_LOOP);

    icm_send_event(pdev,
            ICM_EVENT_RECIPIENT_MAIN,
            ICM_EVENT_SPECTRAL_SWEEP_DONE);

    picm->substate = ICM_STATE_INVALID;
    return SUCCESS;
}

/*
 * Function     : get_raw_spectral_data
 * Description  : get raw spectral data from driver
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int icm_get_raw_spectral_data(ICM_INFO_T* picm)
{
    ICM_SPECTRAL_INFO_T* psinfo = &picm->sinfo;
    psinfo = psinfo;
    not_yet();
    return 0;
}

/*
 * Function     : is_spectral_enab
 * Description  : check is spectral is enabled
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int icm_is_spectral_enab(ICM_INFO_T* picm)
{
    return icm_wal_is_spectral_enab(picm);
}


/*
 * Function     : is_spectral_active
 * Description  : check is spectral is active
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int icm_is_spectral_active(ICM_INFO_T* picm)
{
    ICM_SPECTRAL_INFO_T* psinfo = &picm->sinfo;
    psinfo = psinfo;
    not_yet();
    return 0;
}

/*
 * Function     : icm_get_spectral_params
 * Description  : Get values of Spectral parameters
 * Input params : pointer to icm info structure
 * Output params: pointer to Spectral params structure, to be populated
 * Return       : SUCCESS/FAILURE
 */
int icm_get_spectral_params(ICM_INFO_T *picm, struct spectral_config *sp)
{
    return icm_wal_get_spectral_params(picm, sp);
}

/*
 * Function     : icm_set_spectral_params
 * Description  : Set values of Spectral parameters
 * Input params : pointer to icm info structure, pointer to Spectral params
 *                structure containing values to be set
 * Return       : SUCCESS/FAILURE
 */
int icm_set_spectral_params(ICM_INFO_T *picm, struct spectral_config *sp)
{
    return icm_wal_set_spectral_params(picm, sp);
}

/*
 * Function     : icm_configure_spectral_params
 * Description  : Configure values of Spectral parameters as required for ICM
 *                operation
 * Input params : pointer to icm info structure
 * Return       : SUCCESS/FAILURE
 */
int icm_configure_spectral_params(ICM_INFO_T *picm)
{
    struct spectral_config sp;
    ICM_DEV_INFO_T* pdev = get_pdev();
    enum ieee80211_cwm_width ch_width;
    int is_11ac = 0;

    if (picm == NULL) {
        err("icm: ICM Information structure is invalid");
        return FAILURE;
    }

    memset(&sp, 0, sizeof(sp));

    if (picm->scfgmgmt_ctx.is_valid == true) {
        err("icm: Spectral Configuration Management Context is in inconsistent "
                "state");
        return FAILURE;
    }

    switch (picm->spectral_hw_gen) {
        case QCA_WLAN_VENDOR_SPECTRAL_SCAN_CAP_HW_GEN_1:
            is_11ac = 0;
            break;

        case QCA_WLAN_VENDOR_SPECTRAL_SCAN_CAP_HW_GEN_2:
            is_11ac = 1;
            break;

        case QCA_WLAN_VENDOR_SPECTRAL_SCAN_CAP_HW_GEN_3:
            is_11ac = 1;
            break;

        default:
            err("Invalid Spectral harware generation\n");
            return FAILURE;
    }

    if (icm_get_spectral_params(picm, &sp) != SUCCESS) {
        return FAILURE;
    }

    if ((ch_width = icm_get_channel_width(picm)) ==
            IEEE80211_CWM_WIDTHINVALID) {
        return FAILURE;
    }

    memcpy(&picm->scfgmgmt_ctx.saved_sp,
            &sp,
            sizeof(picm->scfgmgmt_ctx.saved_sp));

    picm->scfgmgmt_ctx.is_valid = true;

    sp.ss_spectral_pri = 1;

    if (is_11ac) {
        sp.ss_restart_ena = 1;

        switch (ch_width) {
            case IEEE80211_CWM_WIDTH20:
                sp.ss_fft_size = 7;
                break;

            case IEEE80211_CWM_WIDTH40:
                sp.ss_fft_size = 8;
                break;

            case IEEE80211_CWM_WIDTH80:
                sp.ss_fft_size = 9;
                break;

            default:
                err("icm: Invalid/unsupported channel width enumeration %d\n",
                        ch_width);
                return FAILURE;
        }
    }

    if (icm_set_spectral_params(picm, &sp) != SUCCESS) {
        ICM_DPRINTF(pdev,
                ICM_PRCTRL_FLAG_NONE,
                ICM_DEBUG_LEVEL_MAJOR,
                ICM_MODULE_ID_SPECTRAL,
                "Could not set desired Spectral config. Attempting to " 
                "restore original Spectral config\n");
        if (icm_restore_spectral_params(picm) != SUCCESS) {
            /* Too bad. Post mortems should be carried out. */
            picm->scfgmgmt_ctx.is_valid = false;
        }
        return FAILURE;
    }

    return SUCCESS;
}

/*
 * Function     : icm_restore_spectral_params
 * Description  : Restore original values of Spectral parameters
 * Input params : pointer to icm info structure
 * Return       : SUCCESS/FAILURE
 */
int icm_restore_spectral_params(ICM_INFO_T *picm)
{
    struct spectral_config sp;

    if (picm == NULL) {
        err("icm: ICM Information structure is invalid");
        return FAILURE;
    }

    if (picm->scfgmgmt_ctx.is_valid == false) {
        err("icm: Spectral Configuration Management Context is in inconsistent "
                "state");
        return FAILURE;
    }

    /* Even if setting of parameters fails at lower levels, the current
       context is marked as invalid since its usage could be one of
       the factors leading to failure. */
    picm->scfgmgmt_ctx.is_valid = false;

    memcpy(&sp,
            &picm->scfgmgmt_ctx.saved_sp,
            sizeof(sp));

    if (icm_set_spectral_params(picm, &sp) != SUCCESS) {
        return FAILURE;
    }

    return SUCCESS;
}

/*
 * Function     : icm_do_spectral_scan
 * Description  : carry out spectral scans on required channels. Note
 *                that we currently carry out spectral scans only for
 *                ICM_BAND_2_4G
 * Input params : pointer to icm info structrue, bool specifying whether
 *                to restore original channel after scan.
 * Return       : success/failure
 */
int icm_do_spectral_scan(ICM_INFO_T* picm, bool restore_channel)
{
    int chan_before_spectral = 0;
    char cmd[CMD_BUF_SIZE] = {'\0'};
    ICM_DEV_INFO_T *pdev = get_pdev();
    struct spectral_caps scaps;

    if (picm->band != ICM_BAND_2_4G) {
        /* Not currently supported */
        err("Only 2.4 GHz Band currently supported for Spectral scan.");
        return FAILURE;
    }

    if (restore_channel) {
        if ((chan_before_spectral = icm_get_currchan(picm)) < 0)
        {
            err("Unable to get current channel.");
            return FAILURE;
        }
    }

    ICM_DPRINTF(pdev, ICM_PRCTRL_FLAG_NONE, ICM_DEBUG_LEVEL_MAJOR, ICM_MODULE_ID_SPECTRAL, "Starting spectral scan...\n");

    if (icm_wal_get_spectral_capabilities(picm, &scaps) != SUCCESS) {
        err("Cannot get Spectral capabilities...");
        return FAILURE;
    }

    init_classifier_data(picm->radio_addr, &scaps, sizeof(scaps));

    picm->spectral_hw_gen = scaps.hw_gen;

    if (icm_configure_spectral_params(picm) != SUCCESS) {
        err("Cannot configure required Spectral Scan parameters...");
        return FAILURE;
    }

    if (icm_start_spectral_scan(picm) != SUCCESS) {
        err("Cannot start spectral scan...");
        return FAILURE;
    }

    icm_send_event(pdev,
            ICM_EVENT_RECIPIENT_MAIN,
            ICM_EVENT_SPECTRAL_SWEEP_STARTED);

    /* Receive spectral scan till we complete all the channels */
    if (icm_recv_spectral_data(picm) != SUCCESS) {
        err("Failure while receiving spectral data...");
        return FAILURE;
    }

    if (restore_channel) {
        if (chan_before_spectral != picm->def_channel) {
            ICM_DPRINTF(pdev, ICM_PRCTRL_FLAG_NONE, ICM_DEBUG_LEVEL_MAJOR, ICM_MODULE_ID_SPECTRAL,
                    "Error : Default channel (%d) and User set channel (%d) don't match\n",
                    picm->def_channel, chan_before_spectral);
        }

        ICM_DPRINTF(pdev, ICM_PRCTRL_FLAG_NONE, ICM_DEBUG_LEVEL_MAJOR, ICM_MODULE_ID_SPECTRAL,
                "Configuring back operating channel %d\n", picm->def_channel);
        snprintf(cmd, sizeof(cmd), "%s %s %s %1d", "iwconfig",
                picm->dev_ifname, "channel",  picm->def_channel);
        system(cmd);
    }

    return SUCCESS;
}

int icm_start_spectral_scan(ICM_INFO_T* picm)
{
    ICM_DEV_INFO_T* pdev = get_pdev();

    /* Re-initialize */
    if (icm_init_spectral(picm) != SUCCESS) {
        return FAILURE;
    }

    if (icm_switch_channel(picm, true) != SUCCESS)
            return FAILURE;

    start_spectral_scan(picm);
    pdev->active_device = picm->dev_index;

    if (picm->current_channel == 1) {
        alarm(picm->sinfo.dwell_interval_short);
    } else {
        alarm(picm->sinfo.dwell_interval);
    }

    return SUCCESS;
}

/*
 * Function     : start_spectral_scan
 * Description  : start the spectrla scan on current channel
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int start_spectral_scan(ICM_INFO_T* picm)
{
    return icm_wal_start_spectral_scan(picm);
}

/*
 * Function     : set_spectral_debug
 * Description  : set the spectral module debug level
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int set_spectral_debug(ICM_INFO_T* picm, int dbglevel)
{
    return icm_wal_set_spectral_debug(picm, dbglevel);
}

int icm_stop_spectral_scan(ICM_INFO_T* picm)
{
    int status;
    status = stop_spectral_scan(picm);
    return status;
}


/*
 * Function     : stop_spectral_scan
 * Description  : stop the spectrla scan on current channel
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int stop_spectral_scan(ICM_INFO_T* picm)
{
    return icm_wal_stop_spectral_scan(picm);
}

/*
 * Function     : get_spectral_thresholds
 * Description  : get spectral threshold values
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int get_spectral_threholds(ICM_INFO_T* picm)
{
    ICM_SPECTRAL_INFO_T* psinfo = &picm->sinfo;
    psinfo = psinfo;
    not_yet();
    return 0;
}



int icm_clear_spectral_chan_properties(ICM_INFO_T* picm)
{
    return icm_wal_clear_spectral_chan_properties(picm);;
}


#endif /* WLAN_SPECTRAL_ENABLE */

int icm_get_channel_vendorsurvey_info(ICM_INFO_T* picm)
{
    return icm_wal_get_channel_vendorsurvey_info(picm);
}

int icm_set_icm_active(ICM_INFO_T *picm, u_int32_t val)
{
    return icm_wal_set_icm_active(picm, val);

}

/*
 * Function     : icm_get_nominal_noisefloor
 * Description  : get nominal noisefloor
 * Input params : pointer to icm info structrue
 * Return       : success/failure
 *
 */
int icm_get_nominal_noisefloor(ICM_INFO_T *picm)
{
    return icm_wal_get_nominal_noisefloor(picm);;

}

