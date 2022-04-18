/*!
 * @file vpp_ip_frc_mc.h
 *
 * @cr
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.

 * @services
 */

#ifndef _VPP_IP_FRC_MC_H_
#define _VPP_IP_FRC_MC_H_

#include <pthread.h>
#include <semaphore.h>

#include "vpp_ion.h"
#include "vpp_queue.h"
#include "vpp_reg.h"
#include "vpp_ip.h"
#include "vpp_buf.h"
#include "vpp_svc.h"
#include "vpp_ip_hvx_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 * Local definitions
 ***********************************************************************/
#define FRCMC_CB_GET(ctx) (ctx ? (t_StVppIpFrcMcCb *)ctx : NULL)

#define FRC_ALGO_MC                     (1 << 0)
#define FRC_ALGO_ROI                    (1 << 1)
#define FRCMC_PARAM                     (1 << 16)

#define FRCMC_CMD_Q_SZ                  30
#define FRCMC_PARAMID_BIT_LENGTH        6
#define FRCMC_GLOBAL_LOCAL_BIT_LENGTH   1
#define FRCMC_PARAMID_BIT_MASK          ((1 << (HVX_PARAMID_BIT_LENGTH)) - 1)
#define FRCMC_GLOBAL_LOCAL_BIT_MASK     1
#define FRCMC_CUSTOM_HEADER_SIZE        4

#define FRC_ROI_PERCENTAGE_MAX          100
// Define the number of buffers that won't be returned each process (Peek only)
#define FRCMC_IN_BUF_PEEK_CNT           1
#define FRCMC_IN_BUF_PULL_CNT           (FRC_NUM_IN_PIX_BUFFS - FRCMC_IN_BUF_PEEK_CNT)

#define FRCMC_FRAME_RATE_FACTOR         2

typedef enum {
    eVppFrcMc_StateNull,
    eVppFrcMc_StateActive,
    eVppFrcMc_StateInterlaced,
} t_EVppFrcMcState;

typedef struct StCustomFrcMcParams
{
    vpp_svc_frc_op_mode_t mode;
    uint16_t mc_quality;
    uint16_t no_frame_copy;
    uint16_t RepeatMode_repeatPeriod;
    uint16_t TH_MOTION;
    uint16_t TH_MOTION_LOW;
    uint16_t TH_MVOUTLIER_COUNT;
    uint16_t TH_MVOUTLIER_COUNT_LOW;
    uint16_t TH_OCCLUSION;
    uint16_t TH_OCCLUSION_LOW;
    uint16_t TH_MOTION00;
    uint16_t TH_MOTION00_LOW;
    uint16_t TH_MVOUTLIER_VARIANCE_COUNT;
    uint16_t TH_MVOUTLIER_VARIANCE_COUNT_LOW;
    uint16_t TH_SCENECUT;
    uint16_t TH_VARIANCE;
    uint16_t TH_SAD_FR_RATIO;
} t_StCustomFrcMcParams;

typedef struct {
    struct vpp_port_param stParam;
    t_StVppBufPool stPendingQ;
    int32_t u32IntoProcessing;  // minimum buffers needed for processing
    int32_t u32OutofProcessing; // how many buffers complete processing
} t_StVppIpPort;

typedef struct StFrcMcParam {
    vpp_svc_frc_params_t stFrcParams;
} t_StFrcMcParam;

typedef struct {
    struct  hqv_ctrl_frc stFrc;
    struct hqv_ctrl_global_demo stDemo;
    uint32_t u32AutoHqvEnable;
    uint32_t u32EnableMask;
    uint32_t u32ComputeMask;
    uint32_t u32LoadMask;
} t_StVppIpFrcMcCfg;

typedef struct {
    t_StVppIpBase stBase;
    t_StVppIpHvxCoreCb *pstHvxCore;

    uint32_t u32InternalFlags;

    sem_t sem;
    pthread_t thread;
    pthread_cond_t cond;
    pthread_mutex_t mutex;

    t_StVppIpPort stInput;
    t_StVppIpPort stMbi;
    t_StVppIpPort stOutput;

    t_StVppQueue stCmdQ;
    t_StVppIpCmd astCmdNode[FRCMC_CMD_Q_SZ];

    uint32_t eState;

    t_StVppIpFrcMcCfg stCfg;

    uint32_t u32InputMaxIntoProc; //max number of input buff needed for a processing
    uint32_t u32OutputMaxIntoProc;//max number of output buff needed for a processing

    ////hvx parameters
    vpp_svc_frc_params_t* pstFrcParams;
    ////MBI buffers
    vpp_svc_frame_group_descriptor_t* pstBufferdataExtra;

    t_StFrcMcParam stFrcMcParams;

    t_StCustomFrcMcParams stLocalFrcMcParams;
    t_StCustomFrcMcParams *pstGlobalFrcMcParams;

    t_EVppFrcMcState eFrcMcState;

    struct {
        uint32_t u32InProcCnt;   // Input frames processed
        uint32_t u32OutProcCnt;  // Output frames processed into
        uint32_t u32InYuvQCnt;   // Input YUV buffers queued
        uint32_t u32InMbiQCnt;   // Input MBI buffers queued
        uint32_t u32OutYuvQCnt;  // Output YUV buffers queued
        uint32_t u32IBDYuvCnt;   // YUV IBDs (should only be in case of flush)
        uint32_t u32IBDMbiCnt;   // MBI IBDs
        uint32_t u32OBDYuvCnt;   // YUV OBDs (from both output and displayed input buffers)
    } stats;

    struct {
        uint32_t u32OpenRet;
        uint32_t u32CloseRet;
    } async_res;
} t_StVppIpFrcMcCb;


/***************************************************************************
 * Function Prototypes
 ***************************************************************************/

void *vpVppIpFrcMc_Init(t_StVppCtx *pstCtx, uint32_t u32Flags, t_StVppCallback cbs);
void vVppIpFrcMc_Term(void *ctx);
uint32_t u32VppIpFrcMc_Open(void *ctx);
uint32_t u32VppIpFrcMc_Close(void *ctx);
uint32_t u32VppIpFrcMc_SetParam(void *ctx, enum vpp_port port,
                                struct vpp_port_param param);
uint32_t u32VppIpFrcMc_SetCtrl(void *ctx, struct hqv_control ctrl);
uint32_t u32VppIpFrcMc_GetBufferRequirements(void *ctx,
                                             t_StVppIpBufReq *pstInputBufReq,
                                             t_StVppIpBufReq *pstOutputBufReq);
uint32_t u32VppIpFrcMc_QueueBuf(void *ctx, enum vpp_port ePort,
                                t_StVppBuf *pBuf);
uint32_t u32VppIpFrcMc_Flush(void *ctx, enum vpp_port ePort);

uint32_t u32VppIpFrcMc_Drain(void *ctx);

#ifdef __cplusplus
 }
#endif

#endif /* _VPP_IP_FRC_MC_H_ */
