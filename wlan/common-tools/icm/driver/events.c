/*
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * this is to process nl80211 events that are called by driver_nl80211.c
 */

#include "icm.h"
#include "icm_internal.h"

#define ENUM2STRING(x) case x: return #x;
// if MBL flags is enabled, process enums as per mbl driver definitions
#ifndef ICM_RTR_DRIVER
/* copy of MBL driver enum */
typedef enum {
    /* 11a/b/g only, no HT, no proprietary */
    eCSR_DOT11_MODE_abg = 0x0001,
    eCSR_DOT11_MODE_11a = 0x0002,
    eCSR_DOT11_MODE_11b = 0x0004,
    eCSR_DOT11_MODE_11g = 0x0008,
    eCSR_DOT11_MODE_11n = 0x0010,
    eCSR_DOT11_MODE_11g_ONLY = 0x0020,
    eCSR_DOT11_MODE_11n_ONLY = 0x0040,
    eCSR_DOT11_MODE_11b_ONLY = 0x0080,
    eCSR_DOT11_MODE_11ac = 0x0100,
    eCSR_DOT11_MODE_11ac_ONLY = 0x0200,
    /*
     * This is for WIFI test. It is same as eWNIAPI_MAC_PROTOCOL_ALL
     * except when it starts IBSS in 11B of 2.4GHz
     * It is for CSR internal use
     */
    eCSR_DOT11_MODE_AUTO = 0x0400,

    /* specify the number of maximum bits for phyMode */
    eCSR_NUM_PHY_MODE = 16,
} eCsrPhyMode;

typedef enum {
    eCSR_BAND_ALL,
    eCSR_BAND_24,
    eCSR_BAND_5G,
    eCSR_BAND_MAX,
} eCsrBand;

ICM_CH_BW_T convert_mbl_to_RTR_chan_width(enum phy_ch_width mbl_ch_width)
{
    switch (mbl_ch_width){
        case CH_WIDTH_20MHZ:
            return ICM_CH_BW_20;
        case CH_WIDTH_40MHZ:
            return ICM_CH_BW_40;
        case CH_WIDTH_80MHZ:
            return ICM_CH_BW_80;
        case CH_WIDTH_160MHZ:
            return ICM_CH_BW_160;
        case CH_WIDTH_80P80MHZ:
            return ICM_CH_BW_80_PLUS_80;
        default:
            return ICM_CH_BW_INVALID;
    }

    return ICM_CH_BW_INVALID;
}

int convert_RTR_to_mbl_chan_width(ICM_CH_BW_T rtr_ch_width)
{
    switch (rtr_ch_width){
        case ICM_CH_BW_20:
            return CH_WIDTH_20MHZ;
        case ICM_CH_BW_40MINUS:
        case ICM_CH_BW_40PLUS:
        case ICM_CH_BW_40:
            return CH_WIDTH_40MHZ;
        case ICM_CH_BW_80:
            return CH_WIDTH_80MHZ;
        case ICM_CH_BW_160:
            return CH_WIDTH_160MHZ;
        case ICM_CH_BW_80_PLUS_80:
            return CH_WIDTH_80P80MHZ;
        default:
            return CH_WIDTH_INVALID;
    }

    return CH_WIDTH_INVALID;
}

ICM_PHY_SPEC_T convert_mbl_to_RTR_phy_mode(eCsrPhyMode mbl_phy_mode, ICM_BAND_T scan_band)
{
    switch (mbl_phy_mode){
        case eCSR_DOT11_MODE_abg:
            return ICM_PHY_SPEC_ANY;
        case eCSR_DOT11_MODE_11a:
            return ICM_PHY_SPEC_11A;
        case eCSR_DOT11_MODE_11b:
        case eCSR_DOT11_MODE_11b_ONLY:
            return ICM_PHY_SPEC_11B;
        case eCSR_DOT11_MODE_11g:
        case eCSR_DOT11_MODE_11g_ONLY:
            return ICM_PHY_SPEC_11G;
        case eCSR_DOT11_MODE_11n_ONLY:
        case eCSR_DOT11_MODE_11n:
        case eCSR_DOT11_MODE_AUTO:
            if (scan_band == ICM_BAND_2_4G)
                return ICM_PHY_SPEC_11NG;
            else
                return ICM_PHY_SPEC_11NA;
        case eCSR_DOT11_MODE_11ac:
        case eCSR_DOT11_MODE_11ac_ONLY:
            return ICM_PHY_SPEC_11AC;
        /* 11AX TODO: Add MBL conversions for 11ax here */
        default:
            return ICM_PHY_SPEC_INVALID;
    }

    return ICM_PHY_SPEC_INVALID;
}

ICM_BAND_T convert_mbl_to_RTR_scan_band(eCsrBand mbl_scan_band)
{
    switch (mbl_scan_band){
        case eCSR_BAND_ALL:
            return ICM_BAND_DUAL;
        case eCSR_BAND_24:
            return ICM_BAND_2_4G;
        case eCSR_BAND_5G:
            return ICM_BAND_5G;
        default:
            return ICM_BAND_INVALID;
    }

    return ICM_BAND_INVALID;
}
#endif /* ICM_RTR_DRIVER */

const char * icm_band_to_string(ICM_BAND_T band)
{
    switch (band) {
        ENUM2STRING(ICM_BAND_2_4G)
        ENUM2STRING(ICM_BAND_5G)
        ENUM2STRING(ICM_BAND_DUAL)
        default:
            return "ICM_BAND_INVALID";
    }
}

const char * icm_chan_width_to_string(ICM_CH_BW_T chan_width)
{
    switch (chan_width) {
        ENUM2STRING(ICM_CH_BW_20)
        ENUM2STRING(ICM_CH_BW_40MINUS)
        ENUM2STRING(ICM_CH_BW_40PLUS)
        ENUM2STRING(ICM_CH_BW_40)
        ENUM2STRING(ICM_CH_BW_80)
        ENUM2STRING(ICM_CH_BW_160)
        ENUM2STRING(ICM_CH_BW_80_PLUS_80)
        default:
            return "ICM_CH_BW_INVALID";
    }
}

const char * icm_phy_mode_to_string(ICM_PHY_SPEC_T phy_mode)
{
    switch (phy_mode) {
        ENUM2STRING(ICM_PHY_SPEC_11A)
        ENUM2STRING(ICM_PHY_SPEC_11B)
        ENUM2STRING(ICM_PHY_SPEC_11G)
        ENUM2STRING(ICM_PHY_SPEC_FH)
        ENUM2STRING(ICM_PHY_SPEC_TURBO_A)
        ENUM2STRING(ICM_PHY_SPEC_TURBO_G)
        ENUM2STRING(ICM_PHY_SPEC_11NA)
        ENUM2STRING(ICM_PHY_SPEC_11NG)
        ENUM2STRING(ICM_PHY_SPEC_11AC)
        ENUM2STRING(ICM_PHY_SPEC_ANY)
        default:
            return "ICM_PHY_SPEC_INVALID";
    }
}

const char * icm_acs_policy_to_string(u32 policy)
{
    switch (policy) {
        case QCA_WLAN_VENDOR_ATTR_EXTERNAL_ACS_POLICY_PCL_PREFERRED:
            return "PCL_PREFERRED";
        case QCA_WLAN_VENDOR_ATTR_EXTERNAL_ACS_POLICY_PCL_MANDATORY:
            return "PCL_MANDATORY";
        default:
            return "Invalid/No Policy";
    }
}

u64 get_channel_free_time(u64 time, u64 time_busy)
{
    u64 chan_free_time = 0;

    if (time) {
        chan_free_time = ((time - time_busy) * MAX_USABILITY) / time;
    } else {
        /* Cycle count cannot be zero. But if so,
         * set the chan_free_time to zero */
        chan_free_time = 0;
    }
    return chan_free_time;
}

// get scan results and process here
static void event_scan_results(ICM_INFO_T *picm)
{
    // Call to get kernel bss table here.
    struct scan_results *res;
    struct scan_res *r;
    ICM_SCAN_INFO_T *elem;
    int i, k;
    u8 *pos;
    const u8 *ssid;
    struct iwscan_state iw_state; // Only for passing AP index in scanlist
    ICM_DEV_INFO_T* pdev = get_pdev();
    CHANNEL_PROPERTIES_T *chan_prop = picm->slist.chan_properties;
    ICM_CHANNEL_LIST_T *pchlist = NULL;
    int chn_idx = 0;

    /* handle aborted case here. Close ICM */
    if(picm->drv.aborted) {
        icm_cleanup(pdev);
        return;
    }

    res = driver_nl80211_get_scan_results(picm);

    if (res == NULL) {
        icm_printf("Failed to get scan results\n");
        return;
    }

    if (picm->rropavail_info == ICM_RROPAVAIL_INFO_VSCAN_END) {
        if (icm_wal_get_chan_rropinfo(picm)) {
            icm_printf("Failed to get RROP info\n");
            return;
        }
    }

    // We got scan_res here. send/fill corresponding ICM structure now
    // map scan_results to icm_scan_list and scan_res to icm_scan_info
    icm_printf("Scan Results received:\n");
    for (i = 0; i < res->num; i++) {
        if (i >= MAX_SCAN_ENTRIES) {
            icm_printf("max limit reached. can't store more than %d\n", MAX_SCAN_ENTRIES);
            break;
        }
        r = res->res[i];
        elem = &picm->slist.elem[i];
        memcpy(elem->bssid, r->bssid, ETH_ALEN);
        elem->freq = (double) r->freq;
        elem->channel = icm_convert_mhz2channel(r->freq);
        /* what is mode in ICM_SCAN_INFO_T */
        elem->rssi = r->level;
        elem->rssi_valid = true;
        elem->valid = true;

        /* get SSID from scan ie */
        pos = (u8 *) (r + 1);
        ssid = get_ie(pos, r->ie_len, WLAN_EID_SSID);
        if (ssid != NULL) {
            /* TYPE | LEN | VALUE */
            elem->ssid_len = *(ssid + 1);
            memcpy(elem->ssid, ssid + 2, elem->ssid_len);
            elem->ssid[elem->ssid_len] = '\0';
        } else {
            elem->ssid[0] = '\0';
            elem->ssid_len = 0;
        }

        /* Get the relevant operating band */
        if (picm->band == ICM_BAND_2_4G) {
            pchlist = ICM_GET_11BG_CHANNEL_LIST_PTR(picm);
        } else if (picm->band == ICM_BAND_5G) {
            pchlist = ICM_GET_11A_CHANNEL_LIST_PTR(picm);
        } else {
            pchlist = ICM_GET_GENERIC_CHANNEL_LIST_PTR(picm);
        }

        /* update OBSS for 20 MHz bandwidth */
        chn_idx = icm_get_channel_index(pchlist, elem->channel);
        if (chn_idx != -1) {
            pchlist->ch[chn_idx].num_wnw++;
            pchlist->ch[chn_idx].num_wnw_20++;

            /* Update Wireless Preference factor for this bss */
            picm->wpf = icm_get_wpf(r->level);
            pchlist->ch[chn_idx].num_wpf += picm->wpf;
            pchlist->ch[chn_idx].num_wpf_20 += picm->wpf;
        }

        iw_state.ap_num = i;
        icm_parse_gen_ie(picm, &iw_state, pos, r->ie_len);

        icm_printf("\tSSID: %s, BSSID: "MACSTR", freq: %d, rssi: %d wpf: %lf\n",
                elem->ssid, MAC2STR(r->bssid), r->freq, r->level, picm->wpf);
    }

    if (res->info.count) {

        /* Only fill noisefloor, cycle_count and channel_free_time,
         * rest are calucated and stored dynamically */
        for (k = 0; k < res->info.count; k++) {
            for (i = 0; i < picm->chlist.count; i++) {
                if ((int)picm->chlist.ch[i].freq == res->info.freq[k]) {
                    /* copy data in channel properties based on chlist index */
                    int chan_num = icm_convert_mhz2channel(res->info.freq[k]);
                    chan_prop[chan_num].noisefloor = (signed char)res->info.noise[k];
                    chan_prop[chan_num].cycle_count = res->info.time[k];
                    chan_prop[chan_num].channel_free_time = get_channel_free_time(res->info.time[k], res->info.time_busy[k]);

#ifdef ICM_RTR_DRIVER
                    icm_printf("\t freq %u, noisefloor: %d, ",
                               res->info.freq[k],
                               chan_prop[chan_num].noisefloor);
                    icm_printf("time [cycle_count] %u, time_busy %llu, "
                               "channel free time: %u\n",
                               chan_prop[chan_num].cycle_count,
                               res->info.time_busy[k],
                               chan_prop[chan_num].channel_free_time);
#else
                    icm_printf("\t freq %u, noisefloor: %d, "
                               "time [cycle_count] %lu, time_busy %lu, "
                               "channel free time: %d, wpf: %lf\n",
                               res->info.freq[k],
                               chan_prop[chan_num].noisefloor,
                               chan_prop[chan_num].cycle_count,
                               res->info.time_busy[k],
                               chan_prop[chan_num].channel_free_time,
                               picm->chlist.ch[i].num_wpf);
#endif
                }
            }
        }
    }

    /* Free res here */
    scan_results_free(res);

    /* start channel selection */
    icm_cfg_select_channel(picm, TRUE);
}

static void event_start_acs(ICM_INFO_T *picm, void *event_data)
{
    ICM_CAPABILITY_INFO_T *acs_data = event_data;
    ICM_DEV_INFO_T* pdev = get_pdev();
#ifdef ICM_RTR_DRIVER
    int ret = -1;
    int i = 0, j = 0;
#endif /* ICM_RTR_DRIVER */

    if (acs_data == NULL) {
        icm_printf("No data received\n");
        return;
    }
#ifndef ICM_RTR_DRIVER
    acs_data->scan_band = convert_mbl_to_RTR_scan_band(acs_data->scan_band);
    /* call phy_mode conversion only after scan_band is mapped */
    acs_data->phy_mode = convert_mbl_to_RTR_phy_mode(acs_data->phy_mode, acs_data->scan_band);
    acs_data->chan_width = convert_mbl_to_RTR_chan_width(acs_data->chan_width);
#else
    acs_data->scan_band = icm_get_radio_band(acs_data->phy_mode);
    acs_data->chan_width = icm_get_radio_channel_width(acs_data->phy_mode);
    acs_data->phy_mode = convert_phymode_to_icm_physpec(acs_data->phy_mode);
#endif /* ICM_RTR_DRIVER */

    if (icm_vap_init_with_cap_info(pdev, acs_data, picm->dev_index)
            != SUCCESS) {
        return;
    }

    if (picm->rropavail_info == ICM_RROPAVAIL_INFO_EXTERNAL_ACS_START) {
        if (icm_wal_get_chan_rropinfo(picm)) {
            icm_printf("Failed to get RROP info\n");
            return;
        }
    }

#ifdef ICM_RTR_DRIVER
    picm->pri20_blockchanlist.num_channels = 0;
    if ((ret = icm_wal_get_radio_pri20_blockchanlist(picm)) != 0) {
        icm_printf("Failed to get pri20 blockchanlist.\n");
        return;
    }

    if (picm->pri20_blockchanlist.num_channels > 0) {
        for (i = 0; i < picm->chlist.count; i++) {
            for (j = 0; j < picm->pri20_blockchanlist.num_channels; j++) {
                if (picm->chlist.ch[i].ic_ieee ==
                        picm->pri20_blockchanlist.chan[j]) {
                    ICM_SET_OPRI20CHANNEL_EXCLUDE(picm,
                            picm->chlist.ch[i].channel);
                    icm_printf("Channel %hhu blocked for use as pri20. May "
                               "still be used as sec20/sec40/sec80 where "
                               "applicable if other exlusions do not apply.\n",
                               picm->chlist.ch[i].ic_ieee);
                    break;
                }
            }
        }
    }
#endif /* ICM_RTR_DRIVER */

    /*
     * All pri20 channels are assumed to have the max primary channel metric
     * unless the driver/target provides a lower value.
     */
    for (i = 0; i < picm->chlist.count; i++) {
        ICM_SET_PRI20CHANNEL_GRADE(picm, picm->chlist.ch[i].channel,
                NL80211_RF_CHARACTERIZATION_CHAN_METRIC_MAX);
    }

#ifdef ICM_RTR_DRIVER
    picm->chan_rf_characterization.num_prichannels = 0;
    if ((ret = icm_wal_get_radio_chan_rf_characterization_info(picm)) != 0) {
        icm_printf("Failed to get RF characterization info.\n");
        return;
    }

    if (picm->chan_rf_characterization.num_prichannels > 0) {
        for (i = 0; i < picm->chan_rf_characterization.num_prichannels; i++) {
            if (picm->chan_rf_characterization.prichaninfo[i].bw !=
                                                        CH_WIDTH_20MHZ) {
                icm_printf("Freq=%hu: Chan BW %hhu is not handled "
                           "currently. Skipping.\n",
                       picm->chan_rf_characterization.prichaninfo[i].freq,
                       picm->chan_rf_characterization.prichaninfo[i].bw);
                continue;
            }

            for (j = 0; j < picm->chlist.count; j++) {
                if (picm->chlist.ch[j].freq ==
                        picm->chan_rf_characterization.prichaninfo[i].freq) {
                    ICM_SET_PRI20CHANNEL_GRADE(picm,
                        picm->chlist.ch[j].channel,
                        picm->chan_rf_characterization.prichaninfo[i].\
                                                                chan_metric);
                    break;
                }
            }
        }
    }
#endif /* ICM_RTR_DRIVER */

    icm_wal_do_80211_scan(picm);
}

// Process all NL80211 driver events that are sent to ICM application
void process_nl80211_events(void *ctx, enum event_type event, void *event_data)
{
    ICM_INFO_T *picm = ctx;

    switch (event) {
        case EVENT_SCAN_RESULTS:
            event_scan_results(picm);
            break;
        case EVENT_START_ACS:
            event_start_acs(picm, event_data);
            break;
        default:
            icm_printf("ICM: unknown event_type\n");
            break;
    }
}
#undef ENUM2STRING
