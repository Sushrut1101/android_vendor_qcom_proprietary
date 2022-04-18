/*===========================================================================

  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/
/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include "framework/Log.h"
#include "modules/uim/UimSimRefreshIndication.h"
#include "UimPBRRefreshRegisterReqMsg.h"
#include "qcril_uim.h"
#include "qcril_uim_util.h"
#include "qcril_uim_card.h"
#include "qcril_uim_file.h"
#include "qcril_uim_restart.h"
#include "qcril_uim_refresh.h"
#include <string.h>
#include <pthread.h>


/*===========================================================================

                           DEFINES

===========================================================================*/
#define TAG "QCRIL_UIM_REFRESH"

#define QCRIL_UIM_INVALID_APP_INDEX                         0xFFFF
#define QCRIL_UIM_INDEX_DF_TELECOM                          0
#define QCRIL_UIM_INDEX_DF_TELECOM_PBOOK                    1
#define QCRIL_UIM_INDEX_DF_GSM                              2
#define QCRIL_UIM_INDEX_DF_CDMA                             3
#define QCRIL_UIM_INDEX_ADF                                 4
#define QCRIL_UIM_REFRESH_REG_MASK_PRI_GW                   0x00000001
#define QCRIL_UIM_REFRESH_REG_MASK_PRI_1X                   0x00000002
#define QCRIL_UIM_REFRESH_REG_MASK_SEC_GW                   0x00000004
#define QCRIL_UIM_REFRESH_REG_MASK_SEC_1X                   0x00000008
#define QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_STATIC      0x00000010
#define QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_STATIC      0x00000020
#define QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_DYNAMIC     0x00000040
#define QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_DYNAMIC     0x00000080
#define QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_1              0x00000100
#define QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_2              0x00000200
#define QCRIL_UIM_REFRESH_REG_MASK_TER_GW                   0x00000400
#define QCRIL_UIM_REFRESH_REG_MASK_TER_1X                   0x00000800
#define QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_3              0x00001000
#define QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_STATIC      0x00002000
#define QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_DYNAMIC     0x00004000
#define QCRIL_UIM_REFRESH_REG_MASK_CARD_SLOT_1              0x00008000
#define QCRIL_UIM_REFRESH_REG_MASK_CARD_SLOT_2              0x00010000
#define QCRIL_UIM_REFRESH_REG_MASK_CARD_SLOT_3              0x00020000
#define QCRIL_UIM_FILEID_EF_PBR                             0x4F30

//Derived from qmi_uim_app_type values which are
//UNKNOWN APP, SIM, USIM, RUIM, CSIM, ISIM
#define QCRIL_UIM_MAX_APP_TYPE                              6

/*---------------------------------------------------------------------------
  File ID table used for Refresh. Files needed for registering for refresh
  should be added here.
---------------------------------------------------------------------------*/
const unsigned char qcril_uim_refresh_file_list[5][6] =
                    {
                      {0x3F, 0x00, 0x7F, 0x10, 0x00, 0x00}, /* DF TELECOM           */
                      {0x3F, 0x00, 0x7F, 0x10, 0x5F, 0x3A}, /* DF TELECOM_PHONEBOOK */
                      {0x3F, 0x00, 0x7F, 0x20, 0x00, 0x00}, /* DF GSM               */
                      {0x3F, 0x00, 0x7F, 0x25, 0x00, 0x00}, /* DF CDMA              */
                      {0x3F, 0x00, 0x7F, 0xFF, 0x00, 0x00}  /* ADF USIM/CSIM/ISIM   */
                    };

/* EF Table for fixed File IDs.
   Note: DF Phoneook EFs for USIM that have no fixed file ids by the Spec are read
   from PBR and dynamically included in the request for refresh registation. */
const qmi_uim_file_id_type file_id_table_df_telecom[] =
        {
          { 0x6F3A, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM] } }, /* MMGSDI_TELECOM_ADN      */
          { 0x6F3B, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM] } }, /* MMGSDI_TELECOM_FDN      */
          { 0x6F3C, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM] } }, /* MMGSDI_TELECOM_SMS      */
          { 0x6F40, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM] } }, /* MMGSDI_TELECOM_MSISDN   */
          { 0x6F4A, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM] } }  /* MMGSDI_TELECOM_EXT1     */
        };

const qmi_uim_file_id_type file_id_table_df_gsm[] =
        {
          { 0x6F07, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_IMSI         */
          { 0x6F11, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_VMWI         */
          { 0x6F12, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_SVC_STR_TBL  */
          { 0x6F13, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_CFF          */
          { 0x6F14, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_ONS          */
          { 0x6F15, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_CSP          */
          { 0x6F17, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_MN           */
          { 0x6F18, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* EF ON Shortform         */
          { 0x6F19, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* EF Info numbers         */
          { 0x6F46, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_SPN          */
          { 0x6FC5, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_PNN          */
          { 0x6FC6, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_OPL          */
          { 0x6FC7, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } },     /* MMGSDI_GSM_MBDN         */
          { 0x6FCB, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_GSM] } }      /* MMGSDI_GSM_CFIS         */
        };

const qmi_uim_file_id_type file_id_table_adf[] =
        {
          { 0x6F07, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_IMSI        */
          { 0x6F11, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_VMWI        */
          { 0x6F12, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_SVC_STR_TBL */
          { 0x6F13, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_CFF         */
          { 0x6F14, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_ONS         */
          { 0x6F15, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_CSP         */
          { 0x6F17, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_MN          */
          { 0x6F18, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* EF ON Shortform         */
          { 0x6F19, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* EF Info numbers         */
          { 0x6F3B, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_FDN         */
          { 0x6F3C, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_SMS         */
          { 0x6F40, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_MSISDN      */
          { 0x6F46, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_SPN         */
          { 0x6FC5, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_PNN         */
          { 0x6FC6, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_OPL         */
          { 0x6FC7, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_USIM_MBDN        */
          { 0x6FCB, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } }    /* MMGSDI_USIM_CFIS        */
        };

const qmi_uim_file_id_type file_id_table_adf_isim[] =
        {
          { 0x6F02, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_ISIM_IMPI        */
          { 0x6F03, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_ISIM_DOMAIN      */
          { 0x6F04, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } },   /* MMGSDI_ISIM_IMPU        */
          { 0x6F09, { 4, (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_ADF] } }    /* EF P-CSCF               */
        };

/* After both INIT_FCN and FCN are done, then send the refresh response to framework. */
static boolean            dont_send_refresh_fcn_unsol[QMI_UIM_MAX_CARD_COUNT][QCRIL_UIM_MAX_APP_TYPE];

/*===========================================================================

                               INTERNAL FUNCTIONS

===========================================================================*/

/*===========================================================================

  FUNCTION:  qcril_uim_ef_pbr_resp_calculate_files

===========================================================================*/
/*!
    @brief
    Parses the response data & calculates the number of files present based
    on the File tag found. File tags compared are per Spec 31.102.

    @return
    Number of files found if successful, else 0.
*/
/*=========================================================================*/
static uint16 qcril_uim_ef_pbr_resp_calculate_files
(
  const qmi_uim_data_type                   * rsp_data_ptr
)
{
  uint16                    num_files   = 0;
  unsigned char           * data_ptr    = NULL;
  int                       data_index  = 0;

  QCRIL_ASSERT (rsp_data_ptr);

  data_ptr = rsp_data_ptr->data_ptr;

  if ((data_ptr == NULL) || (rsp_data_ptr->data_len <= 0))
  {
    QCRIL_LOG_ERROR("Error in response parameters");
    return num_files;
  }

  /* Loop response data find num_files */
  while ((data_index+1) < rsp_data_ptr->data_len)
  {
    uint8 tag_len = 0;

    /* Check for the Tags */
    switch (*(data_ptr+data_index))
    {
      case QCRIL_UIM_FILE_TAG_CONST_TYPE_1:
      case QCRIL_UIM_FILE_TAG_CONST_TYPE_2:
      case QCRIL_UIM_FILE_TAG_CONST_TYPE_3:
        /* Validate the constructed tag length */
        tag_len = *(data_ptr+data_index+1);
        if ((data_index + 2 + tag_len) > rsp_data_ptr->data_len)
        {
          /* Error in data, cannot parse further */
          QCRIL_LOG_ERROR("Incorrect tag length, cannot parse further: 0x%X \n", tag_len);
          return 0;
        }
        /* Not interested in constructed tags, jump to the next tag */
        data_index += 2;
        break;

      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_ADN:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_IAP:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_EXT1:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_SNE:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_ANR:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_PBC:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_GRP:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_AAS:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_GAS:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_UID:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_EMAIL:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_CCP1:
        /* Found a file tag ! */
        num_files++;

        /* Validate the tag length */
        tag_len = *(data_ptr+data_index+1);
        if ((data_index + 2 + tag_len) > rsp_data_ptr->data_len)
        {
          /* Error in data, cannot parse further */
          QCRIL_LOG_ERROR("Incorrect tag length, cannot parse further: 0x%X \n", tag_len);
          return 0;
        }
        /* Jump to the next tag */
        data_index += tag_len + 2;
        break;

      default:
        /* Assuming that it is a non-Spec tag, continue to next tag if possible */
        tag_len = *(data_ptr+data_index+1);
        if (*(data_ptr+data_index) == 0xFF)
        {
          /* End of tags, no need to parse further */
          return num_files;
        }
        /* Validate the tag length for non-Spec tag */
        if ((data_index + 2 + tag_len) > rsp_data_ptr->data_len)
        {
          /* Error in data, cannot parse further */
          QCRIL_LOG_ERROR("Incorrect tag length, cannot parse further: 0x%X \n", tag_len);
          return 0;
        }
        QCRIL_LOG_INFO( "Tag not identified: 0x%X, continuing to next tag, tag_len: 0x%X",
                        *(data_ptr+data_index), tag_len);
        data_index += tag_len + 2;
        break;
    }
  }
  return num_files;
} /* qcril_uim_ef_pbr_resp_calculate_files */


/*===========================================================================

  FUNCTION:  qcril_uim_ef_pbr_resp_parse_files

===========================================================================*/
/*!
    @brief
    Parses the response data for the actual file tags specified.File tags
    compared are per Spec 31.102.

    @return
    None.
*/
/*=========================================================================*/
static int qcril_uim_ef_pbr_resp_parse_files
(
  uint8                                       slot,
  uint16                                      total_num_files,
  const qmi_uim_data_type                   * rsp_data_ptr
)
{
  int                       res             = 0;
  unsigned char           * data_ptr        = NULL;
  int                       data_index      = 0;
  int                       file_offset     = 0;

  QCRIL_ASSERT (rsp_data_ptr);
  QCRIL_ASSERT (slot < QMI_UIM_MAX_CARD_COUNT);

  data_ptr = rsp_data_ptr->data_ptr;

  if ((data_ptr == NULL) || (rsp_data_ptr->data_len <= 0))
  {
    QCRIL_LOG_ERROR("Error in response parameters");
    return -1;
  }

  /* Loop response data find num_files */
  while ((data_index+1) < rsp_data_ptr->data_len)
  {
    uint8 tag_len = 0;

    /* Check for the Tags */
    switch (*(data_ptr+data_index))
    {
      case QCRIL_UIM_FILE_TAG_CONST_TYPE_1:
      case QCRIL_UIM_FILE_TAG_CONST_TYPE_2:
      case QCRIL_UIM_FILE_TAG_CONST_TYPE_3:
        /* Validate the constructed tag length */
        tag_len = *(data_ptr+data_index+1);
        if ((data_index + 2 + tag_len) > rsp_data_ptr->data_len)
        {
          /* Error in data, cannot parse further */
          QCRIL_LOG_ERROR("Incorrect tag length, cannot parse further: 0x%X \n", tag_len);
          return 0;
        }
        /* Print & jump to the next tag */
        QCRIL_LOG_INFO( "Length of Constructed Tag 0x%X: %d",
                        *(data_ptr+data_index), *(data_ptr+data_index+1));
        data_index += 2;
        break;

      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_ADN:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_IAP:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_EXT1:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_SNE:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_ANR:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_PBC:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_GRP:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_AAS:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_GAS:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_UID:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_EMAIL:
      case QCRIL_UIM_FILE_TAG_PRIMITIVE_EF_CCP1:
        /* Validate the tag length */
        tag_len = *(data_ptr+data_index+1);
        if ((data_index + 2 + tag_len) > rsp_data_ptr->data_len)
        {
          /* Error in data, cannot parse further */
          QCRIL_LOG_ERROR("Incorrect tag length, cannot parse further: 0x%X \n", tag_len);
          return 0;
        }

        /* Parse files - save file ids and other info */
        if (((data_index + 3) < rsp_data_ptr->data_len) &&
            (file_offset < total_num_files))
        {
          /* Offset needed in case there are more than 1 records in EF PBR */
          file_offset = qcril_uim.refresh_info.files_info[slot].num_files;

          /* Update tag info */
          qcril_uim.refresh_info.files_info[slot].files_ptr[file_offset].file_tag =
                                         (qcril_uim_phonebook_file_tag_type)  *(data_ptr+data_index);

          /* Parse file id */
          qcril_uim.refresh_info.files_info[slot].files_ptr[file_offset].file_id_info.file_id =
                                          (*(data_ptr+data_index+2) << 8) |
                                           *(data_ptr+data_index+3);
          /* Update the file path length */
          qcril_uim.refresh_info.files_info[slot].files_ptr[file_offset].file_id_info.path.data_len =
              sizeof(qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM_PBOOK]);

          /* Update the file path */
          qcril_uim.refresh_info.files_info[slot].files_ptr[file_offset].file_id_info.path.data_ptr =
              (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM_PBOOK];

          QCRIL_LOG_INFO( "Updated files_ptr[%d] - file_id: 0x%X, file_tag: 0x%X",
            file_offset,
            qcril_uim.refresh_info.files_info[slot].files_ptr[file_offset].file_id_info.file_id,
            qcril_uim.refresh_info.files_info[slot].files_ptr[file_offset].file_tag);

          /* Move to next file */
          qcril_uim.refresh_info.files_info[slot].num_files++;
        }
        else
        {
          QCRIL_LOG_ERROR("Invalid length: data_index:%d, file_offset: %d, total_num_files: %d",
                          data_index, file_offset, total_num_files);
        }

        /* Jump to the next tag */
        data_index += tag_len + 2;
        break;

      default:
        /* Assuming that it is a non-Spec tag, continue to next tag if possible */
        tag_len = *(data_ptr+data_index+1);
        if (*(data_ptr+data_index) == 0xFF)
        {
          /* End of tags, no need to parse further */
          return 0;
        }
        /* Validate the tag length for non-Spec tag */
        if ((data_index + 2 + tag_len) > rsp_data_ptr->data_len)
        {
          /* Error in data, cannot parse further */
          QCRIL_LOG_ERROR("Incorrect tag length, cannot parse further: 0x%X \n", tag_len);
          return 0;
        }
        QCRIL_LOG_INFO( "Tag not identified: 0x%X, continuing to next tag, tag_len: 0x%X",
                        *(data_ptr+data_index), tag_len);
        data_index += tag_len + 2;
        break;
    }
  }
  return res;
} /* qcril_uim_ef_pbr_resp_parse_files */


/*===========================================================================

  FUNCTION:  qcril_uim_read_ef_pbr_parse_resp

===========================================================================*/
/*!
    @brief
    Parses response for EF-PBR read and updates the global EF table
    for respective EFs.

    @return
    None.
*/
/*=========================================================================*/
static int qcril_uim_read_ef_pbr_parse_resp
(
  const qmi_uim_rsp_data_type                   * rsp_data_ptr,
  qmi_uim_session_type                            qmi_session_type
)
{
  int                                   res               = 0;
  uint16                                file_offset       = 0;
  uint8                                 slot              = 0;
  uint16                                num_files         = 0;
  qcril_uim_phonebook_file_info_type  * tmp_files_ptr     = NULL;

  QCRIL_ASSERT (rsp_data_ptr);

  /* Extract slot info */
  switch (qmi_session_type)
  {
    case QMI_UIM_SESSION_TYPE_CARD_SLOT_1:
      slot = 0;
      break;
    case QMI_UIM_SESSION_TYPE_CARD_SLOT_2:
      slot = 1;
      break;
    case QMI_UIM_SESSION_TYPE_CARD_SLOT_3:
      slot = 2;
      break;
    case QMI_UIM_SESSION_TYPE_PRI_GW_PROV:
      slot = (qcril_uim.card_status.index_gw_pri_prov >> 8) & 0xFF;
      break;
    case QMI_UIM_SESSION_TYPE_PRI_1X_PROV:
      slot = (qcril_uim.card_status.index_1x_pri_prov >> 8) & 0xFF;
      break;
    case QMI_UIM_SESSION_TYPE_SEC_GW_PROV:
      slot = (qcril_uim.card_status.index_gw_sec_prov >> 8) & 0xFF;
      break;
    case QMI_UIM_SESSION_TYPE_SEC_1X_PROV:
      slot = (qcril_uim.card_status.index_1x_sec_prov >> 8) & 0xFF;
      break;
    case QMI_UIM_SESSION_TYPE_TER_GW_PROV:
      slot = (qcril_uim.card_status.index_gw_ter_prov >> 8) & 0xFF;
      break;
    case QMI_UIM_SESSION_TYPE_TER_1X_PROV:
      slot = (qcril_uim.card_status.index_1x_ter_prov >> 8) & 0xFF;
      break;
    default:
      QCRIL_LOG_ERROR("Unsupported session type: 0x%X \n", qmi_session_type);
      return -1;
  }

  QCRIL_ASSERT (slot < QMI_UIM_MAX_CARD_COUNT);

  num_files = qcril_uim_ef_pbr_resp_calculate_files(
                &rsp_data_ptr->rsp_data.read_record_rsp.content);

  QCRIL_LOG_INFO( "Number files in response data: %d", num_files );

  if (num_files == 0)
  {
    return res;
  }

  /* Offset needed in case there are more than 1 records in EF PBR */
  file_offset = qcril_uim.refresh_info.files_info[slot].num_files;

  /* Allocate buffer for global refresh files_ptr, freed in qcril_uim_release */
  tmp_files_ptr = (qcril_uim_phonebook_file_info_type*) qcril_malloc(
      (num_files + file_offset)* sizeof(qcril_uim_phonebook_file_info_type));
  if (tmp_files_ptr == NULL)
  {
    QCRIL_LOG_ERROR("qcril_uim.refresh_info.files_info[%d].files_ptr alloc failed",
                    slot);
    return -1;
  }

  /* Init newly allocated memory */
  memset(tmp_files_ptr, 0,
         (num_files + file_offset) * sizeof(qcril_uim_phonebook_file_info_type));

  /* If files were already read (more than 1 record in EF PBR), copy those files
   * into the new buffer and free original pointer */
  if (qcril_uim.refresh_info.files_info[slot].files_ptr)
  {
    memcpy(tmp_files_ptr,
           qcril_uim.refresh_info.files_info[slot].files_ptr,
           file_offset * sizeof(qcril_uim_phonebook_file_info_type));
    qcril_free(qcril_uim.refresh_info.files_info[slot].files_ptr);
  }

  /* Re-assign the pointer back */
  qcril_uim.refresh_info.files_info[slot].files_ptr = tmp_files_ptr;
  tmp_files_ptr = NULL;

  /* Now parse and update the global refresh info */
  res = qcril_uim_ef_pbr_resp_parse_files(
                                slot,
                                num_files + file_offset,
                                &rsp_data_ptr->rsp_data.read_record_rsp.content);
  return res;
} /* qcril_uim_read_ef_pbr_parse_resp */


/*===========================================================================

  FUNCTION:  qcril_uim_find_telecom_mask

===========================================================================*/
/*!
    @brief
    Checks and returns the telecom mask capabilities (both static & dynamic)
    for the slot of the passed provisioning application.

    @return
    Mask if successful, else 0.
*/
/*=========================================================================*/
static boolean qcril_uim_find_telecom_mask
(
  qmi_uim_session_type                    qmi_session_type,
  uint32                                * telecom_mask_ptr
)
{
  uint8                     prov_app_index    = 0;
  uint8                     slot              = 0;
  boolean                   result            = FALSE;
  qmi_uim_app_state_type    prov_app_state    = QMI_UIM_APP_STATE_UNKNOWN;
  qmi_uim_app_type          prov_app_type     = QMI_UIM_APP_UNKNOWN;

  QCRIL_ASSERT(telecom_mask_ptr);

  if (qcril_uim_extract_index(&prov_app_index,
                              &slot,
                              qmi_session_type) == RIL_UIM_E_SUCCESS)
  {
    result = TRUE;
    /* static mask is always set */
    if (slot == 0)
    {
      *telecom_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_STATIC;
    }
    else if (slot == 1)
    {
      *telecom_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_STATIC;
    }
    else
    {
      *telecom_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_STATIC;
    }

    /* If dynamic mask is already set, dont need to re-read EF PBR */
    if (((slot == 0) && (qcril_uim.refresh_info.registration_mask & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_DYNAMIC)) ||
        ((slot == 1) && (qcril_uim.refresh_info.registration_mask & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_DYNAMIC)) ||
        ((slot == 2) && (qcril_uim.refresh_info.registration_mask & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_DYNAMIC)))
    {
      QCRIL_LOG_INFO( "Telecom Dynamic mask already set, skipping for slot: 0x%X", slot);
      return result;
    }

    /* Next, find if this card supports EF PBR for dynamic files */
    if ((prov_app_index < QMI_UIM_MAX_APP_PER_CARD_COUNT) &&
        (slot < QMI_UIM_MAX_CARD_COUNT))
    {
      prov_app_type = qcril_uim.card_status.card[slot].application[prov_app_index].app_type;
      prov_app_state = qcril_uim.card_status.card[slot].application[prov_app_index].app_state;

      QCRIL_LOG_INFO( "Extracted prov_app_index: 0x%X, slot: 0x%X, prov_app_type: 0x%X, prov_app_state: 0x%X",
                    prov_app_index, slot, prov_app_type, prov_app_state);

      if ((prov_app_type == QMI_UIM_APP_USIM) || (prov_app_type == QMI_UIM_APP_CSIM))
      {
        if (slot == 0)
        {
          *telecom_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_DYNAMIC;
        }
        else if (slot == 1)
        {
          *telecom_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_DYNAMIC;
        }
        else
        {
          *telecom_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_DYNAMIC;
        }
      }
    }
  }
  return result;
} /* qcril_uim_find_telecom_mask */


/*===========================================================================

  FUNCTION:  qcril_uim_convert_session_type_to_mask

===========================================================================*/
/*!
    @brief
    Fetches the registration mask bits based on the passed session type. This
    essentially means that the session type is capable of those file types
    in the mask.

    @return
    TRUE if successful, else FALSE.
*/
/*=========================================================================*/
static boolean qcril_uim_convert_session_type_to_mask
(
  qmi_uim_session_type                    qmi_session_type,
  uint32                                * reg_mask_ptr
)
{
  boolean result = FALSE;

  QCRIL_ASSERT(reg_mask_ptr);

  switch (qmi_session_type)
  {
    case QMI_UIM_SESSION_TYPE_PRI_GW_PROV:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_PRI_GW;
      break;

    case QMI_UIM_SESSION_TYPE_PRI_1X_PROV:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_PRI_1X;
      break;

    case QMI_UIM_SESSION_TYPE_SEC_GW_PROV:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_SEC_GW;
      break;

    case QMI_UIM_SESSION_TYPE_SEC_1X_PROV:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_SEC_1X;
      break;

    case QMI_UIM_SESSION_TYPE_TER_GW_PROV:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_TER_GW;
      break;

    case QMI_UIM_SESSION_TYPE_TER_1X_PROV:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_TER_1X;
      break;

    case QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_1:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_1;
      break;

    case QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_2:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_2;
      break;

    case QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_3:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_3;
      break;

    case QMI_UIM_SESSION_TYPE_CARD_SLOT_1:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_CARD_SLOT_1;
      break;

    case QMI_UIM_SESSION_TYPE_CARD_SLOT_2:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_CARD_SLOT_2;
      break;

    case QMI_UIM_SESSION_TYPE_CARD_SLOT_3:
      *reg_mask_ptr |= QCRIL_UIM_REFRESH_REG_MASK_CARD_SLOT_3;
      break;

    default:
      QCRIL_LOG_ERROR("Invalid session type for registration: 0x%X", qmi_session_type);
      return FALSE;
  }

  /* Fetch the capability of static/dynamic telecom masks. Note that static mask
     is always set but dynamic mask depends on the card. If prov app is not valid,
     this returns FALSE as well */
  result = qcril_uim_find_telecom_mask(qmi_session_type, reg_mask_ptr);

  return result;
} /* qcril_uim_convert_session_type_to_mask */


/*===========================================================================

  FUNCTION:  qcril_uim_calculate_num_files

===========================================================================*/
/*!
    @brief
    Calculates the number of files that are needed for refresh registation
    based on the passed session type.

    @return
    Number of files for the session type.
*/
/*=========================================================================*/
static int qcril_uim_calculate_num_files
(
  uint32                                  reg_mask
)
{
  int       total_num_files = 0;

  /* Calculate the number of files to be added, based on the mask set */
  if ((reg_mask & QCRIL_UIM_REFRESH_REG_MASK_PRI_GW) ||
      (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_SEC_GW) ||
      (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_TER_GW))
  {
    total_num_files = (sizeof(file_id_table_df_gsm)/sizeof(qmi_uim_file_id_type)) +
                      (sizeof(file_id_table_adf)/sizeof(qmi_uim_file_id_type)) +
                      (sizeof(file_id_table_df_telecom)/sizeof(qmi_uim_file_id_type));
  }
  else if ((reg_mask & QCRIL_UIM_REFRESH_REG_MASK_PRI_1X) ||
           (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_SEC_1X) ||
           (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_TER_1X))
  {
    total_num_files = (sizeof(file_id_table_adf)/sizeof(qmi_uim_file_id_type)) +
                      (sizeof(file_id_table_df_telecom)/sizeof(qmi_uim_file_id_type));
  }
  else if ((reg_mask & QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_1) ||
           (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_2) ||
           (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_3))
  {
    total_num_files = sizeof(file_id_table_adf_isim)/sizeof(qmi_uim_file_id_type);
  }
  else
  {
    QCRIL_LOG_ERROR("Invalid mask for registration: 0x%X", reg_mask);
    return total_num_files;
  }

  /* Also account for dynamic files if relevant */
  if (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_DYNAMIC)
  {
    total_num_files += qcril_uim.refresh_info.files_info[0].num_files;
  }
  if (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_DYNAMIC)
  {
    total_num_files += qcril_uim.refresh_info.files_info[1].num_files;
  }
  if (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_DYNAMIC)
  {
    total_num_files += qcril_uim.refresh_info.files_info[2].num_files;
  }

  return total_num_files;

} /* qcril_uim_calculate_num_files */


/*===========================================================================

  FUNCTION:  qcril_uim_send_refresh_register

===========================================================================*/
/*!
    @brief
    Prepares the data needed for refresh register QMI command and sends it.

    @return
    Result code of the QMI API call.
*/
/*=========================================================================*/
static int qcril_uim_send_refresh_register
(
  int                                       num_files,
  const qmi_uim_file_id_type              * files_ptr,
  qmi_uim_session_type                      qmi_session_type
)
{
  qmi_uim_refresh_register_params_type  refresh_register_params  = {};
  int                                   result_code              = 0;
    std::shared_ptr<UimRefreshRegisterReqMsg> req_ptr            = NULL;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  QCRIL_ASSERT(files_ptr);

  memset(&refresh_register_params, 0, sizeof(qmi_uim_refresh_register_params_type));

  refresh_register_params.session_info.session_type = qmi_session_type;
  refresh_register_params.session_info.aid.data_len = 0;
  refresh_register_params.session_info.aid.data_ptr = NULL;

  refresh_register_params.reg_for_refresh = QMI_UIM_TRUE;

  /* To keep it simple, just let QMI vote on behalf of QCRIL */
  refresh_register_params.vote_for_init = QMI_UIM_FALSE;

  /* Update the file details */
  refresh_register_params.num_files = num_files;
  refresh_register_params.files_ptr = (qmi_uim_file_id_type*)files_ptr;

  req_ptr = std::make_shared<UimRefreshRegisterReqMsg>(refresh_register_params.session_info.session_type);

  if (req_ptr == NULL)
  {
    QCRIL_LOG_ERROR("error allocating memory for request_ptr!");
    return -1;
  }

  result_code = qcril_uim_send_qmi_async_msg(QCRIL_UIM_REQUEST_REFRESH_REGISTER,
                                             (void *)&refresh_register_params,
                                             req_ptr);
  if(result_code < 0)
  {
    QCRIL_LOG_ERROR( "Error for qcril_qmi_uim_refresh_register, session_type: 0x%X, result_code: 0x%X",
                     refresh_register_params.session_info.session_type,
                     result_code );
  }

  return result_code;

} /* qcril_uim_send_refresh_register */


/*===========================================================================

  FUNCTION:  qcril_uim_refresh_calculate_files_and_register

===========================================================================*/
/*!
    @brief
    Checks if GW and Primary subscription Apps are in ready state. If yes,
    it Prepares the data needed for refresh register QMI command and sends it.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_refresh_calculate_files_and_register
(
  qmi_uim_session_type                qmi_session_type,
  uint32                              reg_mask
)
{
  uint16                    index                   = 0;
  int                       file_offset             = 0;
  int                       total_num_files         = 0;
  qmi_uim_file_id_type    * refresh_reg_file_id_ptr = NULL;

  /* Fetch number of files needed to register */
  total_num_files = qcril_uim_calculate_num_files(reg_mask);

  QCRIL_LOG_INFO( "Number of files registering for refresh: %d", total_num_files);

  if (total_num_files == 0)
  {
    QCRIL_LOG_ERROR( "total_num_files is 0, cannot register for refresh\n" );
    return;
  }

  /* Allocate intermediate buffer for all the files needed for registration */
  refresh_reg_file_id_ptr = (qmi_uim_file_id_type*) qcril_malloc(
                               total_num_files * sizeof(qmi_uim_file_id_type));
  if (refresh_reg_file_id_ptr == NULL)
  {
    QCRIL_LOG_ERROR( "refresh_reg_file_id_ptr alloc failed, cannot register for refresh\n" );
    return;
  }

  /* Initialize and fill the buffer */
  memset(refresh_reg_file_id_ptr, 0, total_num_files * sizeof(qmi_uim_file_id_type));

  /* Update buffer with necessary files needed to register based on session type */
  switch (qmi_session_type)
  {
    case QMI_UIM_SESSION_TYPE_PRI_GW_PROV:
    case QMI_UIM_SESSION_TYPE_SEC_GW_PROV:
    case QMI_UIM_SESSION_TYPE_TER_GW_PROV:
      /* Add static DF GSM files and update offset */
      memcpy(refresh_reg_file_id_ptr, file_id_table_df_gsm, sizeof(file_id_table_df_gsm));
      file_offset = sizeof(file_id_table_df_gsm)/sizeof(qmi_uim_file_id_type);

      /* Add static ADF files and update offset */
      memcpy(refresh_reg_file_id_ptr+file_offset, file_id_table_adf, sizeof(file_id_table_adf));
      file_offset += sizeof(file_id_table_adf)/sizeof(qmi_uim_file_id_type);

      /* Add static DF Telecom files and update offset */
      memcpy(refresh_reg_file_id_ptr+file_offset, file_id_table_df_telecom, sizeof(file_id_table_df_telecom));
      file_offset += sizeof(file_id_table_df_telecom)/sizeof(qmi_uim_file_id_type);
      break;

    case QMI_UIM_SESSION_TYPE_PRI_1X_PROV:
    case QMI_UIM_SESSION_TYPE_SEC_1X_PROV:
    case QMI_UIM_SESSION_TYPE_TER_1X_PROV:
      /* Add static ADF files and update offset */
      memcpy(refresh_reg_file_id_ptr, file_id_table_adf, sizeof(file_id_table_adf));
      file_offset += sizeof(file_id_table_adf)/sizeof(qmi_uim_file_id_type);

      /* Add static DF Telecom files and update offset */
      memcpy(refresh_reg_file_id_ptr+file_offset, file_id_table_df_telecom, sizeof(file_id_table_df_telecom));
      file_offset += sizeof(file_id_table_df_telecom)/sizeof(qmi_uim_file_id_type);
      break;

    default:
      QCRIL_LOG_ERROR( "Unsupported session_type for refresh: 0x%X\n", qmi_session_type );
      qcril_free(refresh_reg_file_id_ptr);
      refresh_reg_file_id_ptr = NULL;
      return;
  }

  /* Also account for the dynamic files if relevant */
  if (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_DYNAMIC)
  {
    for (index = 0;
         (index < qcril_uim.refresh_info.files_info[0].num_files) &&
         ((index+file_offset) < total_num_files);
         index++)
    {
      refresh_reg_file_id_ptr[index+file_offset] =
        qcril_uim.refresh_info.files_info[0].files_ptr[index].file_id_info;
    }
  }

  if (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_DYNAMIC)
  {
    for (index = 0;
         (index < qcril_uim.refresh_info.files_info[1].num_files) &&
         ((index+file_offset) < total_num_files);
         index++)
    {
      refresh_reg_file_id_ptr[index+file_offset] =
        qcril_uim.refresh_info.files_info[1].files_ptr[index].file_id_info;
    }
  }

  if (reg_mask & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_DYNAMIC)
  {
    for (index = 0;
         (index < qcril_uim.refresh_info.files_info[2].num_files) &&
         ((index+file_offset) < total_num_files);
         index++)
    {
      refresh_reg_file_id_ptr[index+file_offset] =
        qcril_uim.refresh_info.files_info[2].files_ptr[index].file_id_info;
    }
  }

  /* Send the registration request, set the mask if call is successful and
     it will be updated in the callback in case registration fails */
  if (qcril_uim_send_refresh_register(total_num_files,
                                      refresh_reg_file_id_ptr,
                                      qmi_session_type) >= 0)
  {
    QCRIL_LOG_INFO( "Successful queue of refresh registration for session type: 0x%X",
                    qmi_session_type);

    /* Update the respective mask */
    qcril_uim.refresh_info.registration_mask |= reg_mask;
  }
  else
  {
    /* On error, it will be retried later */
    QCRIL_LOG_ERROR( "Error registering for refresh, session type: 0x%X",
                     qmi_session_type);
  }

  QCRIL_LOG_INFO( "Updated registration_mask: 0x%X", qcril_uim.refresh_info.registration_mask);

  /* Free temp buffer that was allocated */
  if (refresh_reg_file_id_ptr)
  {
    qcril_free(refresh_reg_file_id_ptr);
    refresh_reg_file_id_ptr = NULL;
  }
} /* qcril_uim_refresh_calculate_files_and_register */


/*===========================================================================

  FUNCTION:  qcril_uim_refresh_read_pbr_record

===========================================================================*/
/*!
    @brief
    Sends a read for EF PBR record(s). On a successful read, parses and
    updates the global EF table for respective EFs.

    @return
    Result code of the QMI API call.
*/
/*=========================================================================*/
static int qcril_uim_refresh_read_pbr_record
(
  qmi_uim_session_type          qmi_session_type,
  uint16                        record_index,
  uint16                        record_size,
  uint16                        num_records,
  uint32                        dynamic_mask
)
{
  int                                          res          = 0;
  qcril_uim_pbr_refresh_reg_info_type          refresh_pbr  = {};
  qmi_uim_read_record_params_type              read_params  = {};
  std::shared_ptr<UimPBRRefreshRegisterReqMsg> req_ptr      = NULL;
  std::shared_ptr<UimReadRecordReqMsg>         req_msg_ptr  = NULL;

  refresh_pbr.dyn_mask = dynamic_mask;
  refresh_pbr.record_index = record_index;
  refresh_pbr.record_size = record_size;
  refresh_pbr.num_records = num_records;

  req_ptr = std::make_shared<UimPBRRefreshRegisterReqMsg>(refresh_pbr, qmi_session_type);

  if (req_ptr == NULL)
  {
    return -1;
  }

  read_params.session_info.session_type = qmi_session_type;
  read_params.file_id.file_id = QCRIL_UIM_FILEID_EF_PBR;
  read_params.file_id.path.data_len =
      sizeof(qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM_PBOOK]);
  read_params.file_id.path.data_ptr =
      (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM_PBOOK];
  read_params.length = record_size;
  read_params.record = record_index;

  req_msg_ptr = std::make_shared<UimReadRecordReqMsg>(req_ptr, read_params);

  if (req_msg_ptr == NULL)
  {
    return -1;
  }

  if (qcril_uim_send_qmi_async_msg(QCRIL_UIM_REQUEST_READ_RECORD,
                                   (void *)&read_params,
                                   req_msg_ptr) < 0)
  {
    res = -1;
  }

  return res;
} /* qcril_uim_refresh_read_pbr_record */


/*=========================================================================

  FUNCTION:  qcril_uim_refresh_read_pbr_record_resp

===========================================================================*/
/*!
    @brief
    Process the response for PBR read

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_refresh_read_pbr_record_resp
(
  const qcril_uim_callback_params_type * const params_ptr,
  const std::shared_ptr<UimReadRecordReqMsg> msg_ptr
)
{
  uint32                                       dynamic_mask    = 0;
  qmi_uim_session_type                         session_type    = QMI_UIM_SESSION_TYPE_PRI_GW_PROV;
  uint32                                       reg_mask        = 0;
  int                                          res             = -1;
  qcril_uim_pbr_refresh_reg_info_type          refresh_pbr     = {};
  std::shared_ptr<UimPBRRefreshRegisterReqMsg> req_ptr         = NULL;

  if(params_ptr == NULL || msg_ptr == NULL)
  {
    QCRIL_LOG_ERROR("NULL pointer");
    QCRIL_ASSERT(0);
    return;
  }

  req_ptr = std::static_pointer_cast<UimPBRRefreshRegisterReqMsg>(msg_ptr->get_request_msg());

  if (req_ptr == NULL)
  {
    QCRIL_LOG_ERROR("NULL pointer");
    return;
  }

  refresh_pbr = req_ptr->get_params();

  QCRIL_LOG_DEBUG( "qcril_uim_refresh_read_pbr_record_resp: qmi_err_code=0x%X \n",
                    params_ptr->qmi_rsp_data.qmi_err_code);

  dynamic_mask = refresh_pbr.dyn_mask;
  session_type = req_ptr->get_session_type();

  if (params_ptr->qmi_rsp_data.qmi_err_code == 0)
  {
    /* Parse the response & update the EF table */
    res = qcril_uim_read_ef_pbr_parse_resp(&params_ptr->qmi_rsp_data, req_ptr->get_session_type());
    if (res < 0)
    {
      QCRIL_LOG_ERROR( "Error parsing EF PBR record, res: 0x%X", res );
    }
  }

  /* Read next PBR record */
  if (refresh_pbr.record_index < refresh_pbr.num_records)
  {
    res = qcril_uim_refresh_read_pbr_record(
            req_ptr->get_session_type(),
            refresh_pbr.record_index + 1,
            refresh_pbr.record_size,
            refresh_pbr.num_records,
            refresh_pbr.dyn_mask);
  }

  if (refresh_pbr.record_index == refresh_pbr.num_records)
  {
    /* If all records have been read, continue with refresh registration */
    if(qcril_uim_convert_session_type_to_mask(req_ptr->get_session_type(), &reg_mask))
    {
      uint8 slot = QCRIL_UIM_INVALID_SLOT_INDEX_VALUE;
      uint8 app_index = QCRIL_UIM_INVALID_SLOT_INDEX_VALUE;

      reg_mask |= refresh_pbr.dyn_mask;

      qcril_uim_refresh_calculate_files_and_register(req_ptr->get_session_type(), reg_mask);

      if ((qcril_uim_extract_index(&app_index, &slot, req_ptr->get_session_type()) == RIL_UIM_E_SUCCESS) &&
          (slot < QMI_UIM_MAX_CARD_COUNT) &&
          (app_index < QMI_UIM_MAX_APP_PER_CARD_COUNT))
      {
        qcril_uim.refresh_info.pbr_read_in_progress[slot] = FALSE;
      }
    }
  }
} /* qcril_uim_refresh_read_pbr_record_resp */


/*===========================================================================

  FUNCTION:  qcril_uim_refresh_get_pbr_attr

===========================================================================*/
/*!
    @brief
    Sends a read for EF PBR record(s). On a successful read, parses and
    updates the global EF table for respective EFs.

    @return
    Result code of the QMI API call.
*/
/*=========================================================================*/
static int qcril_uim_refresh_get_pbr_attr
(
  qmi_uim_session_type          qmi_session_type,
  uint32                        dynamic_mask
)
{
  int                                          res             = -1;
  qmi_uim_get_file_attributes_params_type      get_attr_params = {};
  qcril_uim_pbr_refresh_reg_info_type          refresh_pbr     = {};
  std::shared_ptr<UimPBRRefreshRegisterReqMsg> req_ptr         = NULL;
  std::shared_ptr<UimGetAttributesReqMsg>      req_msg_ptr     = NULL;

  /* Get file attribute parameters */
  get_attr_params.session_info.session_type = qmi_session_type;
  get_attr_params.file_id.file_id = QCRIL_UIM_FILEID_EF_PBR;
  get_attr_params.file_id.path.data_len =
      sizeof(qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM_PBOOK]);
  get_attr_params.file_id.path.data_ptr =
      (unsigned char*)qcril_uim_refresh_file_list[QCRIL_UIM_INDEX_DF_TELECOM_PBOOK];

  refresh_pbr.dyn_mask = dynamic_mask;

  req_ptr = std::make_shared<UimPBRRefreshRegisterReqMsg>(refresh_pbr, qmi_session_type);

  if (req_ptr == NULL)
  {
    return -1;
  }

  req_msg_ptr = std::make_shared<UimGetAttributesReqMsg>(req_ptr, get_attr_params);

  if (req_msg_ptr == NULL)
  {
    return -1;
  }

  QCRIL_LOG_INFO("queuing GET FILE ATTR for EF-PBR");
  res = qcril_uim_send_qmi_async_msg(QCRIL_UIM_REQUEST_GET_RESPONSE,
                                     (void *)&get_attr_params,
                                     req_msg_ptr);

  return res;
} /* qcril_uim_refresh_get_pbr_attr */


/*=========================================================================

  FUNCTION:  qcril_uim_refresh_get_pbr_attr_resp

===========================================================================*/
/*!
    @brief
    Process the response for get PBR attributes.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_refresh_get_pbr_attr_resp
(
  const qcril_uim_callback_params_type * const params_ptr,
  const std::shared_ptr<UimGetAttributesReqMsg> msg_ptr
)
{
  uint32                                       reg_mask        = 0;
  int                                          res             = -1;
  qcril_uim_pbr_refresh_reg_info_type          refresh_pbr     = {};
  std::shared_ptr<UimPBRRefreshRegisterReqMsg> req_ptr         = NULL;
  uint32                                       dynamic_mask    = 0;

  if(params_ptr == NULL || msg_ptr == NULL)
  {
    QCRIL_LOG_ERROR("NULL pointer");
    QCRIL_ASSERT(0);
    return;
  }

  req_ptr = std::static_pointer_cast<UimPBRRefreshRegisterReqMsg>(msg_ptr->get_request_msg());

  if (req_ptr == NULL)
  {
    QCRIL_LOG_ERROR("NULL pointer");
    return;
  }

  refresh_pbr = req_ptr->get_params();

  dynamic_mask = refresh_pbr.dyn_mask;

  QCRIL_LOG_DEBUG( "qcril_uim_refresh_get_pbr_attr_resp: qmi_err_code=0x%X \n",
                    params_ptr->qmi_rsp_data.qmi_err_code);

  if (params_ptr->qmi_rsp_data.qmi_err_code == 0)
  {
    /* Start reading the PBR records */
    if (params_ptr->qmi_rsp_data.rsp_data.get_file_attributes_rsp.record_count >= 1)
    {
      res = qcril_uim_refresh_read_pbr_record(
              req_ptr->get_session_type(),
              1,
              params_ptr->qmi_rsp_data.rsp_data.get_file_attributes_rsp.record_size,
              params_ptr->qmi_rsp_data.rsp_data.get_file_attributes_rsp.record_count,
              dynamic_mask);
    }
  }

  if (res < 0)
  {
    QCRIL_LOG_INFO("error in reading EF-PBR; register for refresh without dynamic files");

    /* In case of error in getting attributes of EF-PBR, continue with
       registration without the dynamic files. */
    if(qcril_uim_convert_session_type_to_mask(req_ptr->get_session_type(), &reg_mask))
    {
      reg_mask &= (~dynamic_mask);

      qcril_uim_refresh_calculate_files_and_register(req_ptr->get_session_type(), reg_mask);
    }
  }
} /* qcril_uim_refresh_get_pbr_attr_resp */


/*===========================================================================

  FUNCTION:  qcril_uim_find_telecom_dynamic_files

===========================================================================*/
/*!
    @brief
    Fetches the dynamic telecom files for 3G cards and updates the global
    buffer if successful. If it was not successful (3G App not ready or error
    reading EF PBR) it clears the dynamic mask.

    @return
    0 if successful, -1 otherwise.
*/
/*=========================================================================*/
static int qcril_uim_find_telecom_dynamic_files
(
  qmi_uim_session_type                qmi_session_type,
  uint32                            * reg_mask_ptr
)
{
  int                       result          = -1;
  uint32                    dyn_mask        = 0;
  uint8                     prov_app_index  = 0;
  uint8                     slot            = 0;
  qmi_uim_app_state_type    prov_app_state  = QMI_UIM_APP_STATE_UNKNOWN;
  qmi_uim_app_type          prov_app_type   = QMI_UIM_APP_UNKNOWN;

  QCRIL_ASSERT(reg_mask_ptr);

  /* In case EF PBR is already read, no need to re-read it */
  if (((*reg_mask_ptr & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_DYNAMIC) &&
       (qcril_uim.refresh_info.files_info[0].files_ptr != NULL) &&
       (qcril_uim.refresh_info.files_info[0].num_files != 0)) ||
      ((*reg_mask_ptr & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_DYNAMIC) &&
       (qcril_uim.refresh_info.files_info[1].files_ptr != NULL) &&
       (qcril_uim.refresh_info.files_info[1].num_files != 0)) ||
      ((*reg_mask_ptr & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_DYNAMIC) &&
       (qcril_uim.refresh_info.files_info[2].files_ptr != NULL) &&
       (qcril_uim.refresh_info.files_info[2].num_files != 0)))
  {
    QCRIL_LOG_INFO( "Dynamic telecom files not read - already read for mask: 0x%X",
                    *reg_mask_ptr);
    return result;
  }

  /* Clear dynamic mask intially, we set it below on successful read of EF PBR */
  if (*reg_mask_ptr & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_DYNAMIC)
  {
    dyn_mask = QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_1_DYNAMIC;
    *reg_mask_ptr &= (~dyn_mask);
  }
  else if (*reg_mask_ptr & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_DYNAMIC)
  {
    dyn_mask = QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_2_DYNAMIC;
    *reg_mask_ptr &= (~dyn_mask);
  }
  else if (*reg_mask_ptr & QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_DYNAMIC)
  {
    dyn_mask = QCRIL_UIM_REFRESH_REG_MASK_DF_TELECOM_3_DYNAMIC;
    *reg_mask_ptr &= (~dyn_mask);
  }
  else
  {
    /* No need to read PBR, skip it */
    QCRIL_LOG_INFO( "Dynamic telecom files not read - mask not set, session type: 0x%X",
                    qmi_session_type);
    return result;
  }

  if (qcril_uim_extract_index(&prov_app_index,
                              &slot,
                              qmi_session_type) == RIL_UIM_E_SUCCESS)
  {
    if ((prov_app_index < QMI_UIM_MAX_APP_PER_CARD_COUNT) &&
        (slot < QMI_UIM_MAX_CARD_COUNT))
    {
      if (qcril_uim.refresh_info.pbr_read_in_progress[slot])
      {
        QCRIL_LOG_INFO( "EF-PBR being read");
        return result;
      }

      prov_app_type = qcril_uim.card_status.card[slot].application[prov_app_index].app_type;
      prov_app_state = qcril_uim.card_status.card[slot].application[prov_app_index].app_state;

      QCRIL_LOG_INFO( "Extracted prov_app_index: 0x%X, slot: 0x%X, prov_app_type: 0x%X, prov_app_state: 0x%X",
                    prov_app_index, slot, prov_app_type, prov_app_state);

      if (((prov_app_type == QMI_UIM_APP_USIM) || (prov_app_type == QMI_UIM_APP_CSIM)) &&
          (prov_app_state == QMI_UIM_APP_STATE_READY))
      {
        result = qcril_uim_refresh_get_pbr_attr(qmi_session_type, dyn_mask);
        if (result == 0)
        {
          qcril_uim.refresh_info.pbr_read_in_progress[slot] = TRUE;
        }
      }
    }
  }
  return result;
} /* qcril_uim_find_telecom_dynamic_files */


/*===========================================================================

  FUNCTION:  qcril_uim_send_refresh_ok

===========================================================================*/
/*!
    @brief
    Prepares the data needed for refresh ok QMI command and sends it.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_send_refresh_ok
(
  qmi_uim_session_type                      qmi_session_type
)
{
  int result_code = 0;
  qmi_uim_refresh_ok_params_type    refresh_ok_params;
  qmi_uim_rsp_data_type             refresh_ok_rsp;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  memset(&refresh_ok_params, 0, sizeof(qmi_uim_refresh_ok_params_type));
  memset(&refresh_ok_rsp, 0, sizeof(qmi_uim_rsp_data_type));

  refresh_ok_params.session_info.session_type = qmi_session_type;
  refresh_ok_params.session_info.aid.data_len = 0;
  refresh_ok_params.session_info.aid.data_ptr = NULL;
  refresh_ok_params.ok_to_refresh = QMI_UIM_TRUE;

  result_code = qcril_uim_send_qmi_sync_msg(QCRIL_UIM_REQUEST_REFRESH_OK,
                                            &refresh_ok_params,
                                            &refresh_ok_rsp);
  if(result_code < 0)
  {
    QCRIL_LOG_ERROR( "Error for qcril_qmi_uim_refresh_ok, result_code: 0x%X, qmi_err_code: 0x%X\n",
                     result_code, refresh_ok_rsp.qmi_err_code);
  }
} /* qcril_uim_send_refresh_ok */


/*===========================================================================

  FUNCTION:  qcril_uim_send_refresh_complete

===========================================================================*/
/*!
    @brief
    Prepares the data needed for refresh complete QMI command and sends it.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_send_refresh_complete
(
  qmi_uim_refresh_ind_type                * refresh_ind_ptr
)
{
  int                   result_code = 0;
  qmi_uim_refresh_complete_params_type    refresh_complete_params;
  qmi_uim_rsp_data_type                   refresh_complete_rsp;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  memset(&refresh_complete_params, 0, sizeof(qmi_uim_refresh_complete_params_type));
  memset(&refresh_complete_rsp, 0, sizeof(qmi_uim_rsp_data_type));

  refresh_complete_params.session_info.session_type =
    refresh_ind_ptr->refresh_event.session_type;

  if(refresh_ind_ptr->refresh_event.session_type == QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_1 ||
     refresh_ind_ptr->refresh_event.session_type == QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_2 ||
     refresh_ind_ptr->refresh_event.session_type == QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_3)
  {
    refresh_complete_params.session_info.aid.data_len =
      refresh_ind_ptr->refresh_event.aid_len;
    refresh_complete_params.session_info.aid.data_ptr =
      (unsigned char*)refresh_ind_ptr->refresh_event.aid_value;
  }
  else
  {
    refresh_complete_params.session_info.aid.data_len = 0;
    refresh_complete_params.session_info.aid.data_ptr = NULL;
  }
  refresh_complete_params.refresh_success = QMI_UIM_TRUE;

  result_code = qcril_uim_send_qmi_sync_msg(QCRIL_UIM_REQUEST_REFRESH_COMPLETE,
                                            &refresh_complete_params,
                                            &refresh_complete_rsp);
  if(result_code < 0)
  {
    QCRIL_LOG_ERROR( "Error for qcril_qmi_uim_refresh_complete, result_code: 0x%X, qmi_err_code: 0x%X\n",
                     result_code, refresh_complete_rsp.qmi_err_code);
  }
} /* qcril_uim_send_refresh_complete */


/*===========================================================================

  FUNCTION:  qcril_uim_refresh_handle_mode_change

===========================================================================*/
/*!
    @brief
    Based on the refresh mode and sesion type, this function updated the
    respective provisioning application's status. Also sends QCRIL internal
    events if needed.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_refresh_handle_mode_change
(
  qmi_uim_refresh_ind_type        * refresh_ind_ptr
)
{
  uint8 app_index = QCRIL_UIM_INVALID_APP_INDEX_VALUE;
  uint8 slot      = QCRIL_UIM_INVALID_SLOT_INDEX_VALUE;

  if( refresh_ind_ptr == NULL )
  {
    QCRIL_LOG_ERROR("NULL pointer");
    QCRIL_ASSERT(0);
    return;
  }

  if ((refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_INIT) ||
      (refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_INIT_FCN) ||
      (refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_INIT_FULL_FCN) ||
      (refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_APP_RESET) ||
      (refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_3G_SESSION_RESET))
  {
    switch (refresh_ind_ptr->refresh_event.session_type)
    {
      case QMI_UIM_SESSION_TYPE_PRI_GW_PROV:
        slot = (qcril_uim.card_status.index_gw_pri_prov >> 8) & 0xFF;
        app_index = qcril_uim.card_status.index_gw_pri_prov & 0xFF;
        break;
      case QMI_UIM_SESSION_TYPE_PRI_1X_PROV:
        slot = (qcril_uim.card_status.index_1x_pri_prov >> 8) & 0xFF;
        app_index = qcril_uim.card_status.index_1x_pri_prov & 0xFF;
        break;
      case QMI_UIM_SESSION_TYPE_SEC_GW_PROV:
        slot = (qcril_uim.card_status.index_gw_sec_prov >> 8) & 0xFF;
        app_index = qcril_uim.card_status.index_gw_sec_prov & 0xFF;
        break;
      case QMI_UIM_SESSION_TYPE_SEC_1X_PROV:
        slot = (qcril_uim.card_status.index_1x_sec_prov >> 8) & 0xFF;
        app_index = qcril_uim.card_status.index_1x_sec_prov & 0xFF;
        break;
      case QMI_UIM_SESSION_TYPE_TER_GW_PROV:
        slot = (qcril_uim.card_status.index_gw_ter_prov >> 8) & 0xFF;
        app_index = qcril_uim.card_status.index_gw_ter_prov & 0xFF;
        break;
      case QMI_UIM_SESSION_TYPE_TER_1X_PROV:
        slot = (qcril_uim.card_status.index_1x_ter_prov >> 8) & 0xFF;
        app_index = qcril_uim.card_status.index_1x_ter_prov & 0xFF;
        break;
      default:
        QCRIL_LOG_ERROR( "Refresh for non-provisioning session type [0x%x] not supported \n",
                         (unsigned int)refresh_ind_ptr->refresh_event.session_type);
        return;
    }
  }
  else if (refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_RESET)
  {
    switch (refresh_ind_ptr->refresh_event.session_type)
    {
      case QMI_UIM_SESSION_TYPE_CARD_SLOT_1:
        slot = 0;
        break;
      case QMI_UIM_SESSION_TYPE_CARD_SLOT_2:
        slot = 1;
        break;
      case QMI_UIM_SESSION_TYPE_CARD_SLOT_3:
        slot = 2;
        break;
      default:
        QCRIL_LOG_ERROR( "Refresh Reset for session type [0x%x] not supported \n",
                         (unsigned int)refresh_ind_ptr->refresh_event.session_type);
        return;
    }
  }
  else
  {
    QCRIL_LOG_INFO( " Unsupported refresh mode! \n");
    return;
  }

  QCRIL_LOG_INFO("Found for updation: card[%d].application[%d]",
                 slot, app_index);

  /* Sanity checks */
  if (slot >= QMI_UIM_MAX_CARD_COUNT)
  {
    QCRIL_LOG_ERROR("Invalid slot value: 0x%x", slot);
    return;
  }

  if (app_index >= QMI_UIM_MAX_APP_PER_CARD_COUNT &&
      refresh_ind_ptr->refresh_event.refresh_mode != QMI_UIM_REFRESH_MODE_RESET)
  {
    QCRIL_LOG_ERROR("Invalid app_index: 0x%x", app_index);
    return;
  }

  /* Update globals depending upon the mode */
  switch (refresh_ind_ptr->refresh_event.refresh_mode)
  {
    case QMI_UIM_REFRESH_MODE_INIT:
    case QMI_UIM_REFRESH_MODE_INIT_FCN:
    case QMI_UIM_REFRESH_MODE_INIT_FULL_FCN:
      qcril_uim.card_status.card[slot].application[app_index].app_state = QMI_UIM_APP_STATE_PERSO;
      qcril_uim.card_status.card[slot].application[app_index].perso_state = QMI_UIM_PERSO_STATE_UNKNOWN;
      qcril_uim.card_status.card[slot].application[app_index].perso_feature = QMI_UIM_PERSO_FEATURE_STATUS_UNKNOWN;
      break;

    case QMI_UIM_REFRESH_MODE_RESET:
      /* Send internal notifications only in case of QMI_UIM_REFRESH_MODE_RESET */
      qcril_uim_update_cm_card_status(slot, QCRIL_CARD_STATUS_REFRESH);
      break;

    case QMI_UIM_REFRESH_MODE_APP_RESET:
    case QMI_UIM_REFRESH_MODE_3G_SESSION_RESET:
      qcril_uim.card_status.card[slot].application[app_index].app_state = QMI_UIM_APP_STATE_DETECTED;
      qcril_uim.card_status.card[slot].application[app_index].perso_state = QMI_UIM_PERSO_STATE_UNKNOWN;
      qcril_uim.card_status.card[slot].application[app_index].perso_feature = QMI_UIM_PERSO_FEATURE_STATUS_UNKNOWN;
      qcril_uim.card_status.card[slot].application[app_index].pin1_state = QMI_UIM_PIN_STATE_UNKNOWN;
      qcril_uim.card_status.card[slot].application[app_index].pin2_state = QMI_UIM_PIN_STATE_UNKNOWN;
      break;

    default:
      QCRIL_LOG_INFO( " Unsupported refresh mode! \n");
      break;
  }

  if (qcril_uim.card_status.num_slots > 1)
  {
    if (refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_RESET)
    {
      /* refresh all sessions of the same slot that variable "slot" stores */
      /* The refresh_event.session_type has already been checked before, it
         must fall in the following cases */
      if (((qcril_uim.card_status.index_gw_pri_prov >> 8) & 0xFF) == slot)
      {
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_PRI_GW_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
      if (((qcril_uim.card_status.index_1x_pri_prov >> 8) & 0xFF) == slot)
      {
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_PRI_1X_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
      if (((qcril_uim.card_status.index_gw_sec_prov >> 8) & 0xFF) == slot)
      {
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_SEC_GW_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
      if (((qcril_uim.card_status.index_1x_sec_prov >> 8) & 0xFF) == slot)
      {
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_SEC_1X_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
      if (((qcril_uim.card_status.index_gw_ter_prov >> 8) & 0xFF) == slot)
      {
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_TER_GW_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
      if (((qcril_uim.card_status.index_1x_ter_prov >> 8) & 0xFF) == slot)
      {
        qcril_uim_update_prov_session_type(QMI_UIM_SESSION_TYPE_TER_1X_PROV,
                                           QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
      }
    }
    else
    {
      /* Update provisioning session info in all of the above modes */
      qcril_uim_update_prov_session_type(refresh_ind_ptr->refresh_event.session_type,
                                       QCRIL_UIM_PROV_SESSION_NOT_ACTIVATED);
    }
  }
} /* qcril_uim_refresh_handle_mode_change */


/*===========================================================================

  FUNCTION:  qcril_uim_refresh_send_unsol_sim_refresh

===========================================================================*/
/*!
    @brief
    Sends the unsolicited notification RIL_UNSOL_SIM_REFRESH.

    @return
    None.
*/
/*=========================================================================*/
static void qcril_uim_refresh_send_unsol_sim_refresh
(
  uint8                             slot,
  RIL_UIM_SIM_RefreshIndication   & ril_refresh_resp
)
{
  /* Since QMI indications are posted to both RILD instances, we need to send the unsolicted response
     to only the necessary RILD instance */
  QCRIL_LOG_INFO("qcril_instance_id: 0x%X, refresh_instance_id: 0x%X",
                 qmi_ril_get_process_instance_id(), slot);

  if (slot == qmi_ril_get_process_instance_id())
  {
    auto ind_ptr = std::make_shared<UimSimRefreshIndication>(ril_refresh_resp);

    /* Send unsolicited response to framework */
    if (ind_ptr != NULL)
    {
      ind_ptr->broadcast();
    }
  }
} /* qcril_uim_refresh_send_unsol_sim_refresh */


/*=========================================================================

  FUNCTION:  qcril_uim_refresh_register_resp

===========================================================================*/
/*!
    @brief
    Process the response for refresh register.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_refresh_register_resp
(
  const qcril_uim_callback_params_type * const params_ptr,
  const std::shared_ptr<UimRefreshRegisterReqMsg> req_ptr
)
{
  if(params_ptr == NULL || req_ptr == NULL)
  {
    QCRIL_LOG_ERROR("NULL pointer");
    QCRIL_ASSERT(0);
    return;
  }

  QCRIL_LOG_DEBUG( "qcril_uim_refresh_register_resp: qmi_err_code=0x%X \n",
                    params_ptr->qmi_rsp_data.qmi_err_code);

  /* Update the global registration mask only on error */
  if ((params_ptr->qmi_rsp_data.sys_err_code != 0) ||
      (params_ptr->qmi_rsp_data.qmi_err_code != 0))
  {
    uint32   reg_mask = 0;

    qcril_uim_convert_session_type_to_mask(req_ptr->get_session_type(), &reg_mask);

    /* On error clear respective mask & it will be retried on next card event */
    qcril_uim.refresh_info.registration_mask &= (~reg_mask);

    QCRIL_LOG_INFO( "Updated registration_mask: 0x%X", qcril_uim.refresh_info.registration_mask);
  }
} /* qcril_uim_refresh_register_resp */


/*===========================================================================

  FUNCTION:  qcril_uim_init_refresh_info

===========================================================================*/
/*!
    @brief
    Initializes the global refresh info structure.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_init_refresh_info
(
  void
)
{
  memset(&qcril_uim.refresh_info, 0, sizeof(qcril_uim_refresh_info_type));
} /* qcril_uim_init_refresh_info */


/*===========================================================================

  FUNCTION:  qcril_uim_cleanup_refresh_info

===========================================================================*/
/*!
    @brief
    Frees the memory in global refresh info structure.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_cleanup_refresh_info
(
  void
)
{
  int slot = 0;

  /* Free allocated buffer for refresh files */
  for (slot = 0; slot < QMI_UIM_MAX_CARD_COUNT; slot++)
  {
    if (qcril_uim.refresh_info.files_info[slot].files_ptr)
    {
      qcril_free(qcril_uim.refresh_info.files_info[slot].files_ptr);
    }
  }

  memset(&qcril_uim.refresh_info, 0, sizeof(qcril_uim_refresh_info_type));

} /* qcril_uim_cleanup_refresh_info */


/*===========================================================================

  FUNCTION:  qcril_uim_refresh_register

===========================================================================*/
/*!
    @brief
    Checks if GW and Primary subscription Apps are in ready state. If yes,
    it Prepares the data needed for refresh register QMI command and sends it.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_refresh_register
(
  qmi_uim_session_type                qmi_session_type
)
{
  uint32                    reg_mask                = 0;

  /* Fetch the needed mask */
  if (!qcril_uim_convert_session_type_to_mask(qmi_session_type, &reg_mask))
  {
    QCRIL_LOG_INFO("Session type not valid for refresh registration: 0x%X",
                   qmi_session_type);
    return;
  }

  /* Check if registration is needed */
  if ((qcril_uim.refresh_info.registration_mask & reg_mask) == reg_mask)
  {
    QCRIL_LOG_INFO("Already registered for all file types, Session type: 0x%X",
                   qmi_session_type);
    return;
  }

  /* Check if dynamic files for DF Telecom needs to be found out
     If DF Telecom dynamic files are read successfully, we included it for registration.
     Otherwise, continue with only static files */
  if (qcril_uim_find_telecom_dynamic_files(qmi_session_type, &reg_mask) != 0)
  {
    /* Check again since we may have done for other files already */
    if ((qcril_uim.refresh_info.registration_mask & reg_mask) == reg_mask)
    {
      QCRIL_LOG_INFO( "Already registered for other file types, Session type: 0x%X",
                       qmi_session_type);
      return;
    }
  }
  else
  {
    uint8 slot = QCRIL_UIM_INVALID_SLOT_INDEX_VALUE;
    uint8 app_index = QCRIL_UIM_INVALID_SLOT_INDEX_VALUE;

    if ((qcril_uim_extract_index(&app_index, &slot, qmi_session_type) == RIL_UIM_E_SUCCESS) &&
        (slot < QMI_UIM_MAX_CARD_COUNT) &&
        (app_index < QMI_UIM_MAX_APP_PER_CARD_COUNT))
    {
      if (qcril_uim.refresh_info.pbr_read_in_progress[slot])
      {
        QCRIL_LOG_INFO("Continue registration for refresh after EF-PBR is read");
        return;
      }
    }
  }

  qcril_uim_refresh_calculate_files_and_register(qmi_session_type, reg_mask);
} /* qcril_uim_refresh_register */


/*===========================================================================

  FUNCTION:  qcril_uim_refresh_register_isim

===========================================================================*/
/*!
    @brief
    Registers for refresh for an ISIM App.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_refresh_register_isim
(
  qmi_uim_slot_type                   qmi_slot
)
{
  uint8                                 slot          = 0;
  uint8                                 app_index     = QCRIL_UIM_INVALID_APP_INDEX_VALUE;
  uint32                                reg_mask      = 0;
  int                                   num_files     = 0;
  int                                   result_code   = 0;
  qmi_uim_refresh_register_params_type  refresh_register_params = {};
  std::shared_ptr<UimRefreshRegisterReqMsg> req_ptr   = NULL;

  switch(qmi_slot)
  {
    case QMI_UIM_SLOT_1:
      slot = 0;
      reg_mask = QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_1;
      refresh_register_params.session_info.session_type =
         QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_1;
      break;

    case QMI_UIM_SLOT_2:
      slot = 1;
      reg_mask = QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_2;
      refresh_register_params.session_info.session_type =
         QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_2;
      break;

    case QMI_UIM_SLOT_3:
      slot = 2;
      reg_mask = QCRIL_UIM_REFRESH_REG_MASK_ISIM_SLOT_3;
      refresh_register_params.session_info.session_type =
         QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_3;
      break;

    default:
      QCRIL_LOG_INFO("Invalid qmi_uim slot id: 0x%X", qmi_slot);
      return;
  }

  /* Check if registration is needed */
  if ((qcril_uim.refresh_info.registration_mask & reg_mask) == reg_mask)
  {
    QCRIL_LOG_INFO("Already registered for all ISIM files, slot: 0x%X",
                   slot);
    return;
  }

  /* Find the ISIM app in QCRIL UIM global */
  if(qcril_uim_extract_isim_index(&app_index, slot) != RIL_UIM_E_SUCCESS)
  {
    QCRIL_LOG_INFO("%s\n", "ISIM app not found: not registering for ISIM Refresh");
    return;
  }

  refresh_register_params.session_info.aid.data_len =
    qcril_uim.card_status.card[slot].application[app_index].aid_len;
  refresh_register_params.session_info.aid.data_ptr =
    (unsigned char *) qcril_malloc(refresh_register_params.session_info.aid.data_len);
  if(refresh_register_params.session_info.aid.data_ptr == NULL)
  {
    QCRIL_LOG_ERROR("%s\n","Allocation for AID failed; cannot send refresh_register");
    return;
  }

  memset(refresh_register_params.session_info.aid.data_ptr,
         0,
         refresh_register_params.session_info.aid.data_len);

  memcpy(refresh_register_params.session_info.aid.data_ptr,
         qcril_uim.card_status.card[slot].application[app_index].aid_value,
         refresh_register_params.session_info.aid.data_len);

  /* Fetch number of files needed to register */
  num_files = qcril_uim_calculate_num_files(reg_mask);

  if(num_files == 0)
  {
    qcril_free(refresh_register_params.session_info.aid.data_ptr);
    refresh_register_params.session_info.aid.data_ptr = NULL;
    return;
  }

  QCRIL_LOG_INFO( "Number of files registering for refresh: %d", num_files);

  /* Allocate buffer for all the files needed for registration */
  refresh_register_params.files_ptr = (qmi_uim_file_id_type*) qcril_malloc(
                                         num_files * sizeof(qmi_uim_file_id_type));
  if (refresh_register_params.files_ptr == NULL)
  {
    QCRIL_LOG_ERROR( "Allocation for refresh file list failed, cannot register for refresh\n" );
    qcril_free(refresh_register_params.session_info.aid.data_ptr);
    refresh_register_params.session_info.aid.data_ptr = NULL;
    return;
  }

  /* Initialize and fill the buffer */
  memset(refresh_register_params.files_ptr, 0, num_files * sizeof(qmi_uim_file_id_type));

  memcpy(refresh_register_params.files_ptr, file_id_table_adf_isim, sizeof(file_id_table_adf_isim));
  refresh_register_params.num_files = num_files;

  refresh_register_params.reg_for_refresh = QMI_UIM_TRUE;

  /* To keep it simple, just let QMI vote on behalf of QCRIL */
  refresh_register_params.vote_for_init = QMI_UIM_FALSE;

  req_ptr = std::make_shared<UimRefreshRegisterReqMsg>(refresh_register_params.session_info.session_type);

  if (req_ptr == NULL)
  {
    QCRIL_LOG_ERROR("error allocating memory for request_ptr!");
    qcril_free(refresh_register_params.session_info.aid.data_ptr);
    refresh_register_params.session_info.aid.data_ptr = NULL;
    qcril_free(refresh_register_params.files_ptr);
    refresh_register_params.files_ptr = NULL;
    return;
  }

  result_code = qcril_uim_send_qmi_async_msg(QCRIL_UIM_REQUEST_REFRESH_REGISTER,
                                             (void*)&refresh_register_params,
                                             req_ptr);
  if(result_code >= 0)
  {
    QCRIL_LOG_INFO( "Successful queue of refresh registration for ISIM on slot 0x%X",
                    slot);

    /* Update the respective mask */
    qcril_uim.refresh_info.registration_mask |= reg_mask;
  }
  else
  {
    QCRIL_LOG_ERROR( "Error for qmi_uim_refresh_register, session_type: 0x%X, result_code: 0x%X",
                     refresh_register_params.session_info.session_type,
                     result_code );
  }

  QCRIL_LOG_INFO( "Updated registration_mask: 0x%X", qcril_uim.refresh_info.registration_mask);

  /* Free file list buffer that was allocated */
  qcril_free(refresh_register_params.files_ptr);
  refresh_register_params.files_ptr = NULL;

  /* Free AID buffer that was allocated */
  qcril_free(refresh_register_params.session_info.aid.data_ptr);
  refresh_register_params.session_info.aid.data_ptr = NULL;
}/* qcril_uim_refresh_register_isim */


/*===========================================================================

  FUNCTION:  qcril_uim_process_refresh_ind

===========================================================================*/
/*!
    @brief
    Main function for processing QMI refresh indications. Based
    on the indication received, if needed, it updates the global card status,
    ret_ptr and sends card events internal to QCRIL (CM & PBM).

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_process_refresh_ind
(
  const qcril_uim_indication_params_type  * ind_param_ptr
)
{
  qmi_uim_refresh_ind_type      * refresh_ind_ptr     = NULL;
  boolean                         send_refresh_unsol  = FALSE;
  boolean                         update_qcril_params = FALSE;
  RIL_UIM_SIM_RefreshResult       ril_refresh_mode    = RIL_UIM_SIM_FILE_UPDATE;
  RIL_UIM_SIM_RefreshIndication   ril_refresh_resp    = {};
  qcril_sim_state_e_type          new_sim_state       = QCRIL_SIM_STATE_ABSENT;
  uint8                           prov_app_slot       = QCRIL_UIM_INVALID_SLOT_INDEX_VALUE;
  uint8                           prov_app_index      = QCRIL_UIM_INVALID_APP_INDEX_VALUE;
  int                             i                   = 0;
  qmi_uim_app_type                app_type            = QMI_UIM_APP_UNKNOWN;

  QCRIL_LOG_INFO( "%s\n", __FUNCTION__);

  if(ind_param_ptr == NULL)
  {
    QCRIL_LOG_ERROR("NULL pointer");
    QCRIL_ASSERT(0);
    return;
  }

  refresh_ind_ptr = (qmi_uim_refresh_ind_type*)&ind_param_ptr->ind_data.refresh_ind;

  QCRIL_LOG_INFO("Refresh Indication - stage: 0x%X, mode: 0x%X\n",
                 refresh_ind_ptr->refresh_event.refresh_stage,
                 refresh_ind_ptr->refresh_event.refresh_mode);

  /* Handle refresh reset only for card session type */
  if (refresh_ind_ptr->refresh_event.refresh_stage == QMI_UIM_REFRESH_STAGE_START &&
      refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_RESET &&
      refresh_ind_ptr->refresh_event.session_type != QMI_UIM_SESSION_TYPE_CARD_SLOT_1 &&
      refresh_ind_ptr->refresh_event.session_type != QMI_UIM_SESSION_TYPE_CARD_SLOT_2 &&
      refresh_ind_ptr->refresh_event.session_type != QMI_UIM_SESSION_TYPE_CARD_SLOT_3)
  {
    return;
  }

  /* First fetch indexes */
  if (qcril_uim_extract_index(&prov_app_index,
                              &prov_app_slot,
                              refresh_ind_ptr->refresh_event.session_type) != RIL_UIM_E_SUCCESS)
  {
    /* We need to find out atleast slot since this indication is not for any prov app */
    switch (refresh_ind_ptr->refresh_event.session_type)
    {
      case QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_1:
        prov_app_slot = 0;
        if(qcril_uim_extract_isim_index(&prov_app_index, prov_app_slot) != RIL_UIM_E_SUCCESS)
        {
          QCRIL_LOG_ERROR( "No ISIM app found corresponding to session_type: 0x%X\n",
                          refresh_ind_ptr->refresh_event.session_type);
        }
        break;

      case QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_2:
        prov_app_slot = 1;
        if(qcril_uim_extract_isim_index(&prov_app_index, prov_app_slot) != RIL_UIM_E_SUCCESS)
        {
          QCRIL_LOG_ERROR( "No ISIM app found corresponding to session_type: 0x%X\n",
                          refresh_ind_ptr->refresh_event.session_type);
        }
        break;


      case QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_3:
        prov_app_slot = 2;
        if(qcril_uim_extract_isim_index(&prov_app_index, prov_app_slot) != RIL_UIM_E_SUCCESS)
        {
          QCRIL_LOG_ERROR( "No ISIM app found corresponding to session_type: 0x%X\n",
                          refresh_ind_ptr->refresh_event.session_type);
        }
        break;

      case QMI_UIM_SESSION_TYPE_CARD_SLOT_1:
        prov_app_slot = 0;
        break;

      case QMI_UIM_SESSION_TYPE_CARD_SLOT_2:
        prov_app_slot = 1;
        break;

      case QMI_UIM_SESSION_TYPE_CARD_SLOT_3:
        prov_app_slot = 2;
        break;

      default:
        QCRIL_LOG_ERROR( "Unsupported session_type: 0x%X\n",
                         refresh_ind_ptr->refresh_event.session_type);
        break;
    }
  }

  QCRIL_LOG_INFO("Extracted info: prov_app_slot: 0x%x, prov_app_index: 0x%x",
                  prov_app_slot, prov_app_index);
  /* Update AID, initialize to an empty string */
  if ((prov_app_index < QMI_UIM_MAX_APP_PER_CARD_COUNT) && (prov_app_slot < QMI_UIM_MAX_CARD_COUNT))
  {
    app_type = qcril_uim.card_status.card[prov_app_slot].application[prov_app_index].app_type;
    QCRIL_LOG_INFO("app_type 0x%x", app_type);
  }

  if (prov_app_slot >= QMI_UIM_MAX_CARD_COUNT || app_type >= QCRIL_UIM_MAX_APP_TYPE)
  {
    QCRIL_LOG_ERROR("Invalid SIM refresh indication");
    return;
  }

  switch (refresh_ind_ptr->refresh_event.refresh_stage)
  {
    case QMI_UIM_REFRESH_STAGE_WAIT_FOR_OK_TO_INIT:
      qcril_uim_send_refresh_ok(refresh_ind_ptr->refresh_event.session_type);
      break;

    case QMI_UIM_REFRESH_STAGE_START:
      switch (refresh_ind_ptr->refresh_event.refresh_mode)
      {
        case QMI_UIM_REFRESH_MODE_FCN:
          qcril_uim_send_refresh_complete(refresh_ind_ptr);
          break;

        case QMI_UIM_REFRESH_MODE_INIT_FCN:
        case QMI_UIM_REFRESH_MODE_INIT:
        case QMI_UIM_REFRESH_MODE_INIT_FULL_FCN:
        case QMI_UIM_REFRESH_MODE_3G_SESSION_RESET:
          if (refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_INIT_FCN)
          {
            /* To control the INIT_FCN refresh mode, don't send response when STAGE_END_SUCCESS. */
            dont_send_refresh_fcn_unsol[prov_app_slot][app_type] = TRUE;
          }
          if (refresh_ind_ptr->refresh_event.session_type == QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_1 ||
              refresh_ind_ptr->refresh_event.session_type == QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_2 ||
              refresh_ind_ptr->refresh_event.session_type == QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_3)
          {
            qcril_uim_send_refresh_complete(refresh_ind_ptr);
          }
          else
          {
            qcril_uim_refresh_handle_mode_change(refresh_ind_ptr);
          }
          send_refresh_unsol  = TRUE;
          ril_refresh_mode    = RIL_UIM_SIM_INIT;
          update_qcril_params = TRUE;
          new_sim_state       = QCRIL_SIM_STATE_NOT_READY;
          break;

        case QMI_UIM_REFRESH_MODE_RESET:
          qcril_uim_refresh_handle_mode_change(refresh_ind_ptr);
          /* Reset our global since we will start getting QMI card status indications */
          qcril_uim_init_card_status(&qcril_uim.card_status);
          /* Also cleanup refresh data */
          qcril_uim_cleanup_refresh_info();

          /* clear ARA-M delay cache info */
          qcril_uim_cleanup_ara_m_delay_cache_info();
          /* Clean up Long APDU info, if any */
          qcril_uim_cleanup_long_apdu_info();
          /* Clean up select response info, if any */
          qcril_uim_cleanup_select_response_info();
          /* Clear encrypted PIN1 data */
          qcril_uim_clear_encrypted_pin_after_card_reset(prov_app_slot);

          send_refresh_unsol    = TRUE;
          ril_refresh_mode      = RIL_UIM_SIM_RESET;
          update_qcril_params   = TRUE;
          new_sim_state         = QCRIL_SIM_STATE_NOT_READY;
          break;

        case QMI_UIM_REFRESH_MODE_APP_RESET:
          if (refresh_ind_ptr->refresh_event.session_type == QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_1 ||
              refresh_ind_ptr->refresh_event.session_type == QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_2 ||
              refresh_ind_ptr->refresh_event.session_type == QMI_UIM_SESSION_TYPE_NON_PROV_SLOT_3)
          {
            qcril_uim_send_refresh_complete(refresh_ind_ptr);
          }
          else
          {
            qcril_uim_refresh_handle_mode_change(refresh_ind_ptr);
          }
          send_refresh_unsol    = TRUE;
          ril_refresh_mode      = RIL_UIM_SIM_RESET;
          update_qcril_params   = TRUE;
          new_sim_state         = QCRIL_SIM_STATE_NOT_READY;
          break;

        default:
          QCRIL_LOG_INFO( " Unsupported refresh mode! \n");
          break;
      }
      break;

    case QMI_UIM_REFRESH_STAGE_END_SUCCESS:
      if (refresh_ind_ptr->refresh_event.refresh_mode == QMI_UIM_REFRESH_MODE_FCN)
      {
        if(dont_send_refresh_fcn_unsol[prov_app_slot][app_type] == FALSE)
        {
          QCRIL_LOG_INFO( "app type is %x, in other refresh mode, send refresh response",
                          app_type );
          send_refresh_unsol = TRUE;
        }
        else
        {
          /*In case of  INIT_FCN, modem will change its mode to FCN after init finish, don't sent
                  *refresh unsol to android since android will try to read all files when receive INIT.*/
          QCRIL_LOG_INFO( "app type is %x, in INIT_FCN refresh mode, doesn't need to send refresh response",
                          app_type );
          dont_send_refresh_fcn_unsol[prov_app_slot][app_type] = FALSE;
        }
      }
      break;

    case QMI_UIM_REFRESH_STAGE_END_FAILURE:
      dont_send_refresh_fcn_unsol[prov_app_slot][app_type] = FALSE;
      QCRIL_LOG_ERROR( "%s\n", "Refresh stage end with failure!" );
      break;

    default:
      QCRIL_LOG_INFO( " Unsupported refresh stage! \n");
      break;
  }

  /* Send unsolicited response */
  if (send_refresh_unsol)
  {
    /* Update common parameters */
    ril_refresh_resp.result = ril_refresh_mode;

    QCRIL_LOG_INFO("Extracted info: prov_app_slot: 0x%x, prov_app_index: 0x%x",
                    prov_app_slot,
                    prov_app_index);

    /* Update AID, initialize to an empty string */
    if ((prov_app_index < QMI_UIM_MAX_APP_PER_CARD_COUNT) &&
        (prov_app_slot < QMI_UIM_MAX_CARD_COUNT))
    {
      /* Convert the AID in hex to a null terminated ASCII string
         The function qcril_uim_alloc_bin_to_hexstring will perform the allocation & data conversion */
      if (qcril_uim.card_status.card[prov_app_slot].application[prov_app_index].aid_len != 0)
      {
        char *aid = qcril_uim_alloc_bin_to_hexstring(
          (const uint8*)qcril_uim.card_status.card[prov_app_slot].application[prov_app_index].aid_value,
                        qcril_uim.card_status.card[prov_app_slot].application[prov_app_index].aid_len);
        if (aid != NULL)
        {
          ril_refresh_resp.aid = aid;
          qcril_free(aid);
        }
        ril_refresh_resp.app_type = (RIL_UIM_AppType)
            qcril_uim.card_status.card[prov_app_slot].application[prov_app_index].app_type;
      }
    }

    QCRIL_LOG_INFO( "Sending RIL_UNSOL_SIM_REFRESH, RIL_SimRefreshResult: 0x%x, AID: %s",
                    ril_refresh_resp.result, ril_refresh_resp.aid.c_str());

    if (ril_refresh_resp.result == RIL_UIM_SIM_FILE_UPDATE)
    {
      for (i = 0; (i < refresh_ind_ptr->refresh_event.num_files) &&
                  (refresh_ind_ptr->refresh_event.files_ptr!= NULL); i++)
      {
        int j = 0;
        ril_refresh_resp.ef_id = refresh_ind_ptr->refresh_event.files_ptr[i].file_id;
        QCRIL_LOG_INFO( "Sending RIL_UNSOL_SIM_REFRESH-SIM_FILE_UPDATE for 0x%X \n",
                        ril_refresh_resp.ef_id);

        QCRIL_LOG_INFO( "path_len: 0x%X \n", refresh_ind_ptr->refresh_event.files_ptr[i].path_len);
        for(j=0; j<QMI_UIM_MAX_FILE_PATH;j++)
        {
          QCRIL_LOG_INFO( "path[j]: 0x%X \n", refresh_ind_ptr->refresh_event.files_ptr[i].path_value[j]);
        }
        qcril_uim_refresh_send_unsol_sim_refresh(prov_app_slot, ril_refresh_resp);
      }
    }
    else
    {
      qcril_uim_refresh_send_unsol_sim_refresh(prov_app_slot, ril_refresh_resp);
    }

  }
} /* qcril_uim_process_refresh_ind */


/*===========================================================================

  FUNCTION:  qcril_uim_refresh_register_card_session

===========================================================================*/
/*!
    @brief
    Registers for refresh for card session.

    @return
    None.
*/
/*=========================================================================*/
void qcril_uim_refresh_register_card_session
(
  uint8                   slot
)
{
  uint32                                reg_mask      = 0;
  int                                   result_code   = 0;
  qmi_uim_refresh_register_params_type  refresh_register_params = {};
  std::shared_ptr<UimRefreshRegisterReqMsg> req_ptr   = NULL;

  switch(slot)
  {
    case 0:
      reg_mask = QCRIL_UIM_REFRESH_REG_MASK_CARD_SLOT_1;
      refresh_register_params.session_info.session_type =
         QMI_UIM_SESSION_TYPE_CARD_SLOT_1;
      break;

    case 1:
      slot = 1;
      reg_mask = QCRIL_UIM_REFRESH_REG_MASK_CARD_SLOT_2;
      refresh_register_params.session_info.session_type =
         QMI_UIM_SESSION_TYPE_CARD_SLOT_2;
      break;

    case 2:
      slot = 2;
      reg_mask = QCRIL_UIM_REFRESH_REG_MASK_CARD_SLOT_3;
      refresh_register_params.session_info.session_type =
         QMI_UIM_SESSION_TYPE_CARD_SLOT_3;
      break;

    default:
      QCRIL_LOG_INFO("Invalid slot id: 0x%X", slot);
      return;
  }

  /* Check if registration is needed */
  if ((qcril_uim.refresh_info.registration_mask & reg_mask) == reg_mask)
  {
    QCRIL_LOG_INFO("Already registered for card session, slot: 0x%X",
                   slot);
    return;
  }

  refresh_register_params.reg_for_refresh = QMI_UIM_TRUE;
  /* To keep it simple, just let QMI vote on behalf of QCRIL */
  refresh_register_params.vote_for_init = QMI_UIM_FALSE;
  /* Allocate original request, it is freed in qmi_uim_callback */
  req_ptr = std::make_shared<UimRefreshRegisterReqMsg>(refresh_register_params.session_info.session_type);

  if (req_ptr == NULL)
  {
    QCRIL_LOG_ERROR("error allocating memory for original_request_ptr!");
    return;
  }

  result_code = qcril_uim_send_qmi_async_msg(QCRIL_UIM_REQUEST_REFRESH_REGISTER,
                                             (void *)&refresh_register_params,
                                             req_ptr);

  if(result_code >= 0)
  {
    QCRIL_LOG_INFO( "Successful queue of refresh registration for card session on slot 0x%X",
                    slot);
    /* Update the respective mask */
    qcril_uim.refresh_info.registration_mask |= reg_mask;
  }
  else
  {
    QCRIL_LOG_ERROR( "Error for qmi_uim_refresh_register, session_type: 0x%X, result_code: 0x%X",
                     refresh_register_params.session_info.session_type,
                     result_code );
  }

  QCRIL_LOG_INFO( "Updated registration_mask: 0x%X", qcril_uim.refresh_info.registration_mask);
} /* qcril_uim_refresh_register_card_session */
