/*****************************************************************************

============================
Copyright (c)  2016-2018  Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================

 File: VideoCodecDecoder.cpp
 Description: Implementation of VideoCodecDecoder

 Revision History
 ===============================================================================
 Date    |   Author's Name    |  BugID  |        Change Description
 ===============================================================================
 1-Dec-16   Sanjeev Mittal      First Version
 *****************************************************************************/
#include<VideoCodecDecoder.h>
#include<string.h>
#include<qplog.h>

#define MEDIA_KEY_LOW_LATENCY (char*)"vendor.qti-ext-dec-picture-order.enable\0"
#define MEDIA_H264_VIDEO_MIME_TYPE  (char*)"video/avc\0"
#define MEDIA_H263_VIDEO_MIME_TYPE  (char*)"video/3gpp\0"
#define MEDIA_HEVC_VIDEO_MIME_TYPE  (char*)"video/hevc\0"
#define MEDIA_MPEG4_VIDEO_MIME_TYPE (char*)"video/mp4v-es\0"
#define MEDIA_KEY_ROTATION (char*)"rotation-degrees\0"
#define MEDIA_KEY_EXTRADATA_TYPE_BASIC (char*)"basic\0"
#define MEDIA_KEY_EXTRADATA_CONCEALINFO (char*)"concealmbinfo\0"
#define MEDIA_KEY_EXTRA_DATA_STRING (char*)"vendor.qti-ext-extradata-enable.types\0"

VideoCodecDecoder::VideoCodecDecoder()
{
  AMediaCodecnativeWindow = NULL;
  m_ePlayerState = VIDEO_INIT;
  CRITICAL1("VideoCodecDecoder ctor called");
}

VideoCodecDecoder::~VideoCodecDecoder()
{
  /* Delete surface object during object destruction */
  AMediaCodecnativeWindow = NULL;
  m_ePlayerState = VIDEO_INIT;
  CRITICAL1("VideoCodecDecoder dtor called");
}

QPE_VIDEO_ERROR VideoCodecDecoder::DeInit()
{
  if (VIDEO_INIT == m_ePlayerState) {
    ERROR2("DeInit:: Player already released, m_ePlayerState %d",
           m_ePlayerState);
    return VIDEO_ERROR_OK;
  }

  CRITICAL4("PlayerStateTransition:%d DeInit Called: m_ePlayerState %d, m_format %p",
            iPlayerState, m_ePlayerState, m_format);
  iPlayerState = eVideoStateNotReady;

  if (m_PlayerThreadCreated == 1) {
    WaitforPlayerThread();
    m_PlayerThreadCreated = 0;
  }

  if (mCodec) {
    AMediaCodec_delete(mCodec);
  }

  if (m_format) {
    AMediaFormat_delete(m_format);
  }

  SendEventsToThinclient(VIDEO_MSG_DEV_UNINITIALISED);
  CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_DEV_UNINITIALISED:m_ePlayerState %d",
            iPlayerState, m_ePlayerState);

  /* If Surface is not available, go to INIT state. */
  if (AMediaCodecnativeWindow.get()) {
    m_ePlayerState = VIDEO_SURFACE_RECEIVED;
  } else {
    m_ePlayerState = VIDEO_INIT;
  }

  return VIDEO_ERROR_OK;
}

QPE_VIDEO_ERROR VideoCodecDecoder::Init(QP_VIDEO_CALLBACK tVideoCallBack,
                                        void* pUserData,
                                        QPE_VIDEO_DEV eVDev,
                                        QP_VIDEO_CONFIG *pCodecConfig)
{
  iPlayerState = eVideoStateNotReady;
  m_format = NULL;
  mCodec = NULL;
  m_bMediaCodecError = false;
  EVENT1("Init:: Register the callback API");
  //please never remove these register api call code as it is first step of
  //registration of callback and variables
  RegisterPlayerCallBack(tVideoCallBack, pUserData,  eVDev, pCodecConfig);
  RegisterCallBacks(tVideoCallBack, pUserData, eVDev);
  CRITICAL3("PlayerStateTransition:%d Init Done: m_ePlayerState %d",
            iPlayerState, m_ePlayerState);
  mTransform = 0;
  m_PlayerThreadCreated = 0;
  return VIDEO_ERROR_OK;
}

void VideoCodecDecoder::SetNativeWindow(ANativeWindow* surfaceFar)
{
  AMediaCodecnativeWindow = surfaceFar;
  CRITICAL3_STR("mNativeWindowSurfaceFar = %p, m_ePlayerState %d",
                AMediaCodecnativeWindow.get(), m_ePlayerState);

  /*If we are in INIT and SURFACE pending states, surface should not be NULL */
  if (VIDEO_INIT == m_ePlayerState && AMediaCodecnativeWindow.get() ) {
    m_ePlayerState = VIDEO_CODEC_PENDING;
    CRITICAL2("Surface State is Ready, m_ePlayerState %d", m_ePlayerState);
  } else if (VIDEO_SURFACE_PENDING == m_ePlayerState &&
             AMediaCodecnativeWindow.get() ) {
    CRITICAL1("Surface State is Ready, Codec already received");
    //! Move to Surface rcvd state so that Configure API will proceed further
    m_ePlayerState = VIDEO_SURFACE_RECEIVED;
    StartPlayer();
  } else if (VIDEO_CODEC_CONFIGURED == m_ePlayerState) {
    /* If we are in play state already, then stop the player first. */
    IsEventInternalTriggered(TRUE);
    Stop();
    IsEventInternalTriggered(FALSE);
    //! Move back to Surface pending state
    m_ePlayerState = VIDEO_SURFACE_PENDING;
    //! Set player start flag so that, after surface is received
    //! Start() API will be called after configure() API
    m_bPlayerStartReq = true;

    if (NULL != AMediaCodecnativeWindow.get() ) {
      //! Move to Surface rcvd state so that Configure API will proceed further
      m_ePlayerState = VIDEO_SURFACE_RECEIVED;
      StartPlayer();
    }
  } //! if(VIDEO_CODEC_CONFIGURED == m_ePlayerState)

  return;
}

QPE_VIDEO_ERROR VideoCodecDecoder::Configure(QP_VIDEO_CONFIG tCodecConfig)
{
  QPE_VIDEO_ERROR status;
  media_status_t mstatus;
  enum eVideoState prevState = iPlayerState;
  CRITICAL4("Configure: m_ePlayerState %d, m_format %p, iPlayerState %d",
            m_ePlayerState, m_format, iPlayerState);
  /* Copy Codec Config info into class param */
  UpdateCodecConfigInfo(&tCodecConfig);
  /* For every config request, Transform needs to be calculated */
  mTransform = 0;

  /* Check player state before configuring codec. */
  if (VIDEO_INIT == m_ePlayerState ||
      VIDEO_SURFACE_PENDING == m_ePlayerState) {
    m_ePlayerState = VIDEO_SURFACE_PENDING;
    CRITICAL2("Configure: Waiting for Surface, m_ePlayerState %d",
              m_ePlayerState);
    //! Send Dummy response to Modem
    SendEventsToThinclient(VIDEO_MSG_CODEC_CHANGED);
    return VIDEO_ERROR_OK;
  }

  if (eVideoStateActive == iPlayerState) {
    MINIMAL1("Configure:  Codec is already Active, stop before configuring it");
    bool OutsideInternalEvent = m_bInternalEvent;
    m_bInternalEvent = true;
    status = Stop();
    m_bInternalEvent = OutsideInternalEvent;

    if (VIDEO_ERROR_OK != status) {
      ERROR2("Configure:  Codec stop failed status %d", status);
      return VIDEO_ERROR_OK;
    }
  }

  //! this needs further debugging, crashing
  if (m_format != NULL) {
    CRITICAL1("Configure: format is clearedup");
    AMediaFormat_delete(m_format);
  }

  AMediaCodec_delete(mCodec); //rk: Needs further testing
  m_format = AMediaFormat_new();

  if (NULL == m_format) {
    ERROR1("Configure: m_format is null")
    return VIDEO_ERROR_UNKNOWN;
  }

  AMediaFormat_setInt32(m_format, AMEDIAFORMAT_KEY_WIDTH, m_codecConfig.iWidth);
  AMediaFormat_setInt32(m_format, AMEDIAFORMAT_KEY_HEIGHT, m_codecConfig.iHeight);
  AMediaFormat_setInt32(m_format, MEDIA_KEY_LOW_LATENCY, 1);
  CRITICAL1("Configure: Creating Decoder Mime");

  if (VIDEO_CODEC_H264 == m_codecConfig.eCodec) {
    mCodec = AMediaCodec_createDecoderByType(MEDIA_H264_VIDEO_MIME_TYPE);
    AMediaFormat_setString(m_format, AMEDIAFORMAT_KEY_MIME,
                           MEDIA_H264_VIDEO_MIME_TYPE);
    AMediaFormat_setString(m_format, MEDIA_KEY_EXTRA_DATA_STRING,
                           MEDIA_KEY_EXTRADATA_TYPE_BASIC);
  } else if (VIDEO_CODEC_H265 == m_codecConfig.eCodec) {
    mCodec = AMediaCodec_createDecoderByType(MEDIA_HEVC_VIDEO_MIME_TYPE);
    AMediaFormat_setString(m_format, AMEDIAFORMAT_KEY_MIME,
                           MEDIA_HEVC_VIDEO_MIME_TYPE);
  } else if (VIDEO_CODEC_H263 == m_codecConfig.eCodec) {
    mCodec = AMediaCodec_createDecoderByType(MEDIA_H263_VIDEO_MIME_TYPE);
    AMediaFormat_setString(m_format, AMEDIAFORMAT_KEY_MIME,
                           MEDIA_H263_VIDEO_MIME_TYPE);
  } else if ((VIDEO_CODEC_MPEG4_ISO == m_codecConfig.eCodec) ||
             (VIDEO_CODEC_MPEG4_XVID == m_codecConfig.eCodec) ) {
    mCodec = AMediaCodec_createDecoderByType(MEDIA_MPEG4_VIDEO_MIME_TYPE);
    AMediaFormat_setString(m_format, AMEDIAFORMAT_KEY_MIME,
                           MEDIA_MPEG4_VIDEO_MIME_TYPE);
  }

  if (NULL == mCodec) {
    ERROR1("Configure:: mCodec is null while creating encoder mime");
    return VIDEO_ERROR_UNKNOWN;
  }

  CRITICAL2("Configuring decoder, mCodec %p", mCodec);
  mstatus = AMediaCodec_configure(mCodec, m_format,
                                  AMediaCodecnativeWindow.get(), NULL, 0);

  if (AMEDIA_OK != mstatus) {
    ERROR2("Configure returned status %d", (int)mstatus);
    return VIDEO_ERROR_UNKNOWN;
  }

  SendEventsToThinclient(VIDEO_MSG_CODEC_CHANGED);
  CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_CODEC_CHANGED: m_ePlayerState %d",
            iPlayerState, m_ePlayerState);
  /* Move player state to Configured */
  m_ePlayerState = VIDEO_CODEC_CONFIGURED;
  iPlayerState = eVideoStateIdle;
  //setting default transform before starting the video playback
  ANativeWindow_setBuffersTransform(AMediaCodecnativeWindow.get(), 0);
  /*IMS will set both but above api will no op for codec2.0
  and below api will no op for iomx*/
  setRotation(0);

  //this is for callwaiting scenarios or
  if (eVideoStateActive == prevState) {
    mstatus = AMediaCodec_start(mCodec);

    if (AMEDIA_OK != mstatus) {
      ERROR2("configured Start returned status %d", (int)mstatus);
      return VIDEO_ERROR_UNKNOWN;
    } else {
      iPlayerState = eVideoStateActive;
      CRITICAL1("Configure: Started mCodec from configured API");

      if (!StartPlayerThread()) {
        ERROR1("Error during creation of the Playerloop thread\n");
        return VIDEO_ERROR_UNKNOWN;
      } else {
        MINIMAL1("videoPlayerLoop thread Started");
        m_PlayerThreadCreated = 1;
      }

      MINIMAL1("Calling sempost vtplayframe");
      sem_post_videoplay();
    }
  }

  return VIDEO_ERROR_OK;
}

QPE_VIDEO_ERROR VideoCodecDecoder::Start()
{
  CHECK_MEDIA_ERROR;
  media_status_t mstatus;
  QPE_VIDEO_ERROR eStatus = VIDEO_ERROR_OK;

  do {
    if (eVideoStateActive == iPlayerState) {
      CRITICAL3("Component already started, m_ePlayerState %d, iPlayerState %d",
                m_ePlayerState, iPlayerState);
      break;
    }
    /* If Codec is not yet configured, then send dummy indication to Upper Layer*/
    else if (VIDEO_INIT == m_ePlayerState ||
             VIDEO_SURFACE_PENDING == m_ePlayerState) {
      m_ePlayerState = VIDEO_SURFACE_PENDING;
      m_bPlayerStartReq = true;
      eStatus = VIDEO_ERROR_PLAYER_DOWN;
      CRITICAL2("Component not configured, send Dummy VIDEO_MSG_PLAYER_STARTED, m_ePlayerState %d",
                m_ePlayerState);
      break;
    } else if (VIDEO_SURFACE_RECEIVED == m_ePlayerState) {
      m_bPlayerStartReq = true;
      eStatus = VIDEO_ERROR_PLAYER_DOWN;
      CRITICAL2("Component not configured, send Dummy VIDEO_MSG_PLAYER_STARTED, m_ePlayerState %d",
                m_ePlayerState);
      CRITICAL1("configure: is already in Q without Start Req, Push another config req into Q with Player start Req");
      StartPlayer();
      break;
    }
    /* If codec is not yet configured, then configure it first. This will be
       useful in the case where player stop is requested and started later. In
       such cases, explicit codec configure will not be triggered. */
    else if (VIDEO_CODEC_PENDING == m_ePlayerState) {
      if ((mCodec == NULL) || (m_format == NULL)) {
        ERROR5("PlayerStateTransition:%d: m_ePlayerState %d, mCodec %p, m_format %p failed",
               iPlayerState, m_ePlayerState, mCodec, m_format);
        eStatus = VIDEO_ERROR_UNKNOWN;
        break;
      }

      CRITICAL2("PlayerStateTransition:%d: Configure decoder from Start API",
                iPlayerState);
      mstatus = AMediaCodec_configure(mCodec, m_format,
                                      AMediaCodecnativeWindow.get(), NULL, 0);

      if (AMEDIA_OK != mstatus) {
        ERROR2("Configure from Start failed, status %d", (int)mstatus);
        eStatus = VIDEO_ERROR_UNKNOWN;
        break;
      }

      CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_CODEC_CHANGED: m_ePlayerState %d",
                iPlayerState, m_ePlayerState);
      /* Move player state to Configured */
      m_ePlayerState = VIDEO_CODEC_CONFIGURED;
    } //! if (VIDEO_CODEC_PENDING == m_ePlayerState)

    /* For every config request, Transform needs to be calculated */
    mTransform = 0;
    //setting default transform before starting the video playback
    ANativeWindow_setBuffersTransform(AMediaCodecnativeWindow.get(), 0);
    /*IMS will set both but above api will no op for codec2.0
    and below api will no op for iomx*/
    setRotation(0);
    /* We reached this stage means, Codec is configured properly */
    m_bPlayerStartReq = false;
    mstatus = AMediaCodec_start(mCodec);

    if (AMEDIA_OK != mstatus) {
      ERROR2("PlayerStateTransition:%d:Codec start failed", iPlayerState);
      eStatus = VIDEO_ERROR_UNKNOWN;
      break;
    }

    iPlayerState = eVideoStateActive;
    MINIMAL1("Calling sempost vtplayframe");
    sem_post_videoplay();

    if (!StartPlayerThread()) {
      ERROR1("Error during creation of the videoPlayerLoop thread");
      eStatus = VIDEO_ERROR_UNKNOWN;
      break;
    } else {
      MINIMAL1("videoPlayerLoop thread Started");
      m_PlayerThreadCreated = 1;
    }
  } while (0);

  if ((VIDEO_ERROR_OK == eStatus) || (VIDEO_ERROR_PLAYER_DOWN == eStatus)) {
    CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_PLAYER_STARTED m_ePlayerState %d",
              iPlayerState, m_ePlayerState);
    SendEventsToThinclient(VIDEO_MSG_PLAYER_STARTED);
  } else {
    ERROR3("PlayerStateTransition:%d:VIDEO_MSG_PLAYER_STARTED failed, m_ePlayerState %d",
           iPlayerState, m_ePlayerState);
    SendEventsToThinclient(VIDEO_MSG_ERROR);
  }

  return eStatus;
}

QPE_VIDEO_ERROR VideoCodecDecoder::Stop()
{
  QPE_VIDEO_ERROR eStatus = VIDEO_ERROR_OK;
  CRITICAL3("PlayerStateTransition:%d:Stop: m_ePlayerState %d requested",
            iPlayerState, m_ePlayerState);

  /* Check Codec state before initiating stop command */
  if (eVideoStateActive == iPlayerState) {
    m_ePlayerState = VIDEO_CODEC_PENDING;
    // Reset flag to false, so that surface will not start player on its own.
    // In such case, Modem will send start again for player
    m_bPlayerStartReq = false;
    iPlayerState = eVideoStateNotReady;

    if (m_PlayerThreadCreated == 1) {
      WaitforPlayerThread();
      m_PlayerThreadCreated = 0;
    }

    media_status_t mStatus = AMediaCodec_stop(mCodec);

    if (AMEDIA_OK != mStatus) {
      ERROR3("PlayerStateTransition:%d: stop failed, status %d",
             iPlayerState, (int)mStatus);
      SendEventsToThinclient(VIDEO_MSG_ERROR);
      eStatus = VIDEO_ERROR_UNKNOWN;
    } else {
      CRITICAL3("PlayerStateTransition:%d:VIDEO_MSG_PLAYER_STOPPED m_ePlayerState %d",
                iPlayerState, m_ePlayerState);
    }
  } else {
    CRITICAL2("PlayerStateTransition:%d: not in active state, send dummy indication",
              iPlayerState);
  }

  if (VIDEO_ERROR_OK == eStatus) {
    SendEventsToThinclient(VIDEO_MSG_PLAYER_STOPPED);
  }

  return eStatus;
}

void VideoCodecDecoder::videoPlayFrameLoop()
{
  AMediaCodecBufferInfo info;
  uint64_t currenttime = 0;
  uint8_t ucCvoInfo;
  int8_t cIndex;
  int belongs_to_drop_set = 0;
  int32_t transform = 0;
  ssize_t status = 0;
  uint32_t ulDataVal = 0;
  MINIMAL1("videoPlayFrameLoop thread Started");

  /* If static image flag enabled, exit the loop. */
  while (eVideoStateActive == iPlayerState) {
    //currenttime = getCurrentSystemTime(NULL);
    //time out in microsecond 100ms
    status = AMediaCodec_dequeueOutputBuffer(mCodec, &info, 100000);

    if (status >= 0) {
      if (info.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM) {
        CRITICAL1("VideoPlayFrame output EOS");
      }

      QP_VIDEO_PLAYOUT_INFO playoutInfo;
      memset(&playoutInfo, 0, sizeof(playoutInfo));
      belongs_to_drop_set = DropFrameCheck(info.presentationTimeUs, ucCvoInfo,
                                           cIndex, &playoutInfo);
      AMediaFormat* pFormat = AMediaCodec_getBufferFormat(mCodec, status);

      if (pFormat) {
        void* pExtraData;
        size_t ulExtraDataLen;
        bool bStatus = AMediaFormat_getBuffer(pFormat,
                                              MEDIA_KEY_EXTRADATA_CONCEALINFO,
                                              &pExtraData,
                                              &ulExtraDataLen);

        if (pExtraData && true == bStatus) {
          ulDataVal = *((uint32_t*)pExtraData);
          CRITICAL2("VideoPlayFrame: pExtraData conceal mb info =%d", ulDataVal);
        }

        AMediaFormat_delete(pFormat);
      }

      belongs_to_drop_set = videoPlaybackDecider(belongs_to_drop_set, ulDataVal,
                            m_height, m_width);
      transform = CalcTransform(ucCvoInfo);

      if (transform != mTransform) {
        CRITICAL3("VideoPlayFrame: Transform=%d prevTransform=%d", transform,
                  mTransform);
        ANativeWindow_setBuffersTransform(AMediaCodecnativeWindow.get(), transform);
        /*IMS will set both but above api will no op for codec2.0
          and below api will no op for iomx*/
        setRotation(ucCvoInfo);
        mTransform = transform;
      }

      if (belongs_to_drop_set) {
        playoutInfo.system_time_render_video_frame = 0;
      }

      LOGPACKET(LOG_VIDEO_PLAYOUT_C, &playoutInfo, sizeof(playoutInfo));
      CRITICAL3("VideoPlayFrame: output buffers rendered=%d, frame time %u",
                !belongs_to_drop_set, (uint32_t)info.presentationTimeUs);
      AMediaCodec_releaseOutputBuffer(mCodec, status, !belongs_to_drop_set);
    } else if (status == AMEDIACODEC_INFO_OUTPUT_BUFFERS_CHANGED) {
      CRITICAL1("VideoPlayFrame output buffers changed");
    } else if (status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED) {
      auto format = AMediaCodec_getOutputFormat(mCodec);
      CRITICAL2_STR("VideoPlayFrame format changed to: %s",
                    AMediaFormat_toString(format));
      int iWidth = 0, iHeight = 0;
      auto bStatus = AMediaFormat_getInt32(format, AMEDIAFORMAT_KEY_WIDTH, &iWidth);
      bStatus = AMediaFormat_getInt32(format, AMEDIAFORMAT_KEY_HEIGHT, &iHeight);

      if (m_height != iHeight || m_width != iWidth) {
        PlayerMsg info;
        memset(&info, 0, sizeof(PlayerMsg));
        info.type = RESOLUTION_UPDATE;
        info.data.resolution.height = m_height = iHeight;
        info.data.resolution.width  = m_width = iWidth;
        EVENT2("Resolution information in VideoCodecDecoder is %p", &info);
        CRITICAL3("VideoPlayFrame: Posting event RESOLUTION_UPDATE height = %d width =  %d",
                  iHeight, iWidth);
        postEvent(&info);
        /* Reset tranform variable so that rendering surface can be updated after
           decoder resolution update */
        mTransform = 0;
      }

      AMediaFormat_delete(format);
    } else if (status == AMEDIACODEC_INFO_TRY_AGAIN_LATER) {
      CRITICAL1("VideoPlayFrame: No Output Buffers Available");
    } else {
      CRITICAL2("VideoPlayFrame: unexpected info code: %d", status);
      SendEventsToThinclient(VIDEO_MSG_ERROR);
      m_bMediaCodecError = true;
      break;
    }
  } //!while (eVideoStateActive == iPlayerState)

  CRITICAL2("Exit videoPlayFrameLoop thread PlayerStartState = %d ",
            iPlayerState);
  return;
}

int32_t VideoCodecDecoder::CalcTransform(uint8_t ucCvoInfo)
{
  int32_t transform;

  switch (ucCvoInfo & 0x03) {
    case CVO_ZERO_ROTATION:
      transform = 0;
      DEBUG1("Rotation 0");
      break;

    case CVO_90_ROTATION:
      transform = NATIVE_WINDOW_TRANSFORM_ROT_90;
      DEBUG1("Rotation 90");
      break;

    case CVO_180_ROTATION:
      transform = NATIVE_WINDOW_TRANSFORM_ROT_180;
      DEBUG1("Rotation 180");
      break;

    case CVO_270_ROTATION:
      transform = NATIVE_WINDOW_TRANSFORM_ROT_270;
      DEBUG1("Rotation 270");
      break;

    default:
      transform = 0;
      break;
  }

  switch (ucCvoInfo & 0x04) {
    case CVO_FLIP_ENABLED:

      /* since flip is applied before the rotation
      we need to change the angles to compensate it*/
      if (transform == NATIVE_WINDOW_TRANSFORM_ROT_90) {
        transform = NATIVE_WINDOW_TRANSFORM_ROT_270;
      } else if (transform == NATIVE_WINDOW_TRANSFORM_ROT_270) {
        transform = NATIVE_WINDOW_TRANSFORM_ROT_90;
      }

      transform ^= NATIVE_WINDOW_TRANSFORM_FLIP_H;
      DEBUG1("Rotation fliph");
      break; //Flip horizontal

    default:
      break;
  }

  return transform;
}
void VideoCodecDecoder::setRotation(uint8_t ucCvoInfo)
{
  uint8_t rotation = ucCvoInfo & 0x3;
  int32_t degrees = rotation == CVO_ZERO_ROTATION ? 0 :
                    rotation == CVO_90_ROTATION ? 90 :
                    rotation == CVO_180_ROTATION ? 180 :
                    rotation == CVO_270_ROTATION ? 270 : 0;
  AMediaFormat* rotationParam = AMediaFormat_new();

  if (rotationParam == nullptr) {
    ERROR1("setRotation: failed to allocate param");
    return;
  }

  AMediaFormat_setInt32(rotationParam, MEDIA_KEY_ROTATION, degrees);

  if (AMediaCodec_setParameters(mCodec, rotationParam) != AMEDIA_OK) {
    ERROR2("setRotation: failed to set rotation to %d degrees", degrees);
    AMediaFormat_delete(rotationParam);
    return;
  }

  CRITICAL2("setRotation: Rotation configured to %d degrees", degrees);
  AMediaFormat_delete(rotationParam);
}

QPE_VIDEO_ERROR VideoCodecDecoder::VideoPlayFrame(QP_MULTIMEDIA_FRAME* pFrame,
    int belongs_to_drop_set)
{
  MEDIA_PACKET_INFO_RX* pRxPkt = NULL;
  ssize_t bufidx = -1;

  /* Validate player state before proceeding further */
  if (eVideoStateActive != iPlayerState) {
    MINIMAL2("VideoPlayFrame: Player is not active %d",
             iPlayerState);
    return VIDEO_ERROR_PLAYER_BUSY; // we have to return player is busy and
    //return this so that we don't loose rendering frames.
  }

  if (pFrame == NULL) {
    ERROR1("VideoPlayFrame: Pframe is null");
    return VIDEO_ERROR_UNKNOWN;
  }

  uint32_t length = pFrame->iDataLen;

  if (length <= 0 || pFrame->pData == NULL) {
    CRITICAL2("VideoPlayFrame: length %d is null or data is null", length);
    return VIDEO_ERROR_UNKNOWN;
  }

  CHECK_MEDIA_ERROR;
  pRxPkt = &(pFrame->sMediaPacketInfo.sMediaPktInfoRx);
  bufidx = AMediaCodec_dequeueInputBuffer(mCodec, 100000);
  MINIMAL4_STR("VideoPlayFrame: input buffer %ld timestamp: %lld, dropset %d",
               bufidx, (long long)pFrame->ullFrameTimeUs, belongs_to_drop_set);

  if (bufidx >= 0) {
    size_t bufsize;
    auto buf = AMediaCodec_getInputBuffer(mCodec, bufidx, &bufsize);

    if (buf && length < bufsize) {
      AddToFrameStateMap(pFrame, belongs_to_drop_set, pFrame->ullFrameTimeUs);
      memcpy(buf, pFrame->pData, length);
      AMediaCodec_queueInputBuffer(mCodec, bufidx, 0, length,
                                   pFrame->ullFrameTimeUs, 0);
    }
  } else {
    ERROR2("VideoPlayFrame: input buffer index is invalid : %ld", bufidx);
    return VIDEO_ERROR_PLAYER_BUSY;
  }

  return VIDEO_ERROR_OK;
}

int VideoCodecDecoder::AddToFrameStateMap(QP_MULTIMEDIA_FRAME* pFrameData,
    int belongs_to_drop_set,
    long long int /*app_tstamp*/)
{
  /* Get current time */
  MEDIA_PACKET_INFO_RX* pRxInfo = &(pFrameData->sMediaPacketInfo.sMediaPktInfoRx);
  int nIdx = m_frameStateIndex;
  uint64_t ullCurSysTime = getCurrentSystemTime(NULL);
  uint64_t system_time_decode_video_frame = (uint64_t)
      (pFrameData->ullFrameTimeUs / 1000 - (ullCurSysTime - pFrameData->ullSysTime));
  /* Memsetting the array */
  memset(&m_frameStateSet[nIdx], 0, sizeof(FrameStateMap));
  m_frameStateSet[nIdx].belongs_to_drop_set  = belongs_to_drop_set;
  m_frameStateSet[nIdx].ucFrameNalType       = pFrameData->pData[4];
  m_frameStateSet[nIdx].ulFrameSize          = pFrameData->iDataLen;
  m_frameStateSet[nIdx].source_time_video_frame =
    pRxInfo->source_time_video_frame;
  m_frameStateSet[nIdx].system_time_decode_video_frame =
    system_time_decode_video_frame;
  m_frameStateSet[nIdx].av_tstamp_in_us = pFrameData->ullFrameTimeUs;
  m_frameStateSet[nIdx].app_tstamp = pFrameData->ullSysTime;
  m_frameStateSet[nIdx].seqno      = pRxInfo->iSeqNum;
  m_frameStateSet[nIdx].rtp_tstamp = pRxInfo->source_rtp_timestamp;
  m_frameStateSet[nIdx].cvo_info   = pFrameData->cvoInfo;
  DEBUG6_STR("AddToFrameStateMap dropset %d seqno %d frameStateIndex %d source_time_video_frame %u, av_tstamp_in_us %llu",
             belongs_to_drop_set, pRxInfo->iSeqNum, nIdx,
             pRxInfo->source_time_video_frame,
             (unsigned long long)m_frameStateSet[nIdx].av_tstamp_in_us);
  m_frameStateIndex = (m_frameStateIndex + 1) % FRAME_STATE_SET_SIZE;
  return m_frameStateIndex;
}

int VideoCodecDecoder::DropFrameCheck(long long int av_tstamp,
                                      uint8_t& cvo_info,
                                      int8_t& retreive_index, QP_VIDEO_PLAYOUT_INFO *playoutInfo)
{
  for (int i = 0; i < FRAME_STATE_SET_SIZE; i++) {
    if ((m_frameStateSet[i].av_tstamp_in_us == (uint64_t)av_tstamp) ||
        ((m_frameStateSet[i].av_tstamp_in_us / 1000) == (uint64_t)(
           av_tstamp / 1000))) {
      DEBUG5_STR(
        "DropFrameCheck belongs_to_drop_set %d  frameStateIndex %d source_time_video_frame %u, av_tstamp_in_us %llu",
        m_frameStateSet[i].belongs_to_drop_set, i,
        m_frameStateSet[i].source_time_video_frame,
        (unsigned long long)m_frameStateSet[i].av_tstamp_in_us);
      playoutInfo->version = 4;
      playoutInfo->source_time_video_frame =
        m_frameStateSet[i].source_time_video_frame;
      playoutInfo->source_rtp_timestamp = m_frameStateSet[i].rtp_tstamp;
      playoutInfo->system_time_decode_video_frame =
        m_frameStateSet[i].system_time_decode_video_frame;
      playoutInfo->ucFrameNalType = m_frameStateSet[i].ucFrameNalType;
      playoutInfo->ulFrameSize   = m_frameStateSet[i].ulFrameSize;
      m_ucPrevCvoInfo = cvo_info = m_frameStateSet[i].cvo_info;
      retreive_index = i;
      playoutInfo->system_time_render_video_frame =
        (m_frameStateSet[i].av_tstamp_in_us / 1000 +
         (getCurrentSystemTime(NULL) - m_frameStateSet[i].app_tstamp));
      return m_frameStateSet[i].belongs_to_drop_set;
    }
  } //! for (int i = 0; i < FRAME_STATE_SET_SIZE; i++)

  retreive_index = -1;
  cvo_info = m_ucPrevCvoInfo;
  CRITICAL2("DropFrameCheck:: didnt match any index return prev_cvo_info - %d",
            m_ucPrevCvoInfo);
  return false;
}

QPE_VIDEO_ERROR VideoCodecDecoder::UpdateNalHeader(
  uint8_t* pVolHeader,
  uint16_t pVolHeaderLen)
{
  CRITICAL3("VideoCodecDecoder::UpdateNalHeader pVolHeader : %p pVolHeaderLen : %d",
            pVolHeader, pVolHeaderLen);

  if (pVolHeader != NULL && pVolHeaderLen > 0) {
    memset(m_pRxNalInfo->rawnal, 0, VIDEOOMX_MAX_NAL_LENGTH - 1);
    memcpy(m_pRxNalInfo->rawnal, pVolHeader,
           pVolHeaderLen);
    m_pRxNalInfo->nalLength = (uint32_t) pVolHeaderLen;
  }

  return VIDEO_ERROR_OK;
}
