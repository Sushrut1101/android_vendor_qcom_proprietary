#ifndef QCRIL_UIM_UTIL_H
#define QCRIL_UIM_UTIL_H
/*===========================================================================

  Copyright (c) 2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include "qcril_uim.h"


/*===========================================================================

                           MACROS

===========================================================================*/
#define QCRIL_UIM_FREE_IF_NOT_NULL(x)                     \
            if (x != NULL)                                \
            {                                             \
              qcril_free(x);                              \
              x = NULL;                                   \
            }

#define QCRIL_UIM_DUPLICATE(dest_ptr, src_ptr, src_size, type)  \
            dest_ptr = NULL;                                    \
            if (src_ptr != NULL && src_size > 0)                \
            {                                                   \
              dest_ptr = type qcril_malloc(src_size);       \
              if (dest_ptr != NULL)                             \
              {                                                 \
                memcpy(dest_ptr, src_ptr, src_size);            \
              }                                                 \
            }


/*===========================================================================

                           DEFINES

===========================================================================*/
/* File IDs of DFs */
#define QCRIL_UIM_FILEID_DF_GSM                     0x7F20
#define QCRIL_UIM_FILEID_DF_CDMA                    0x7F25
#define QCRIL_UIM_FILEID_ADF_USIM_CSIM              0x7FFF

#define QCRIL_UIM_EF_ICCID                          0x2FE2

/* Invalid slot/app index values */
#define QCRIL_UIM_INVALID_SLOT_INDEX_VALUE          0xFF
#define QCRIL_UIM_INVALID_APP_INDEX_VALUE           0xFF
#define QCRIL_UIM_INVALID_SLOT_APP_INDEX_VALUE      0xFFFF

#define QCRIL_UIM_UINT16_MAXVAL                     0xFFFF

/*=========================================================================

  FUNCTION:  qcril_uim_align_size

===========================================================================*/
/*!
    @brief
    Calculates the memory size to keep buffers aligned to word.

    @return
    New memory size
*/
/*=========================================================================*/
uint16 qcril_uim_align_size
(
  uint16  orig_size
);

/*=========================================================================

  FUNCTION:  qcril_uim_hexchar_to_bin

===========================================================================*/
/*!
    @brief
    Converts a single character from ASCII to binary

    @return
    Binary value of the ASCII characters
*/
/*=========================================================================*/
uint8 qcril_uim_hexchar_to_bin
(
  char ch
);

/*=========================================================================

  FUNCTION:  qcril_uim_bin_to_hexchar

===========================================================================*/
/*!
    @brief
    Converts a single character from ASCII to binary

    @return
    Binary value of the ASCII characters
*/
/*=========================================================================*/
char qcril_uim_bin_to_hexchar
(
  uint8 ch
);

/*=========================================================================

  FUNCTION:  qcril_uim_alloc_hexstring_to_bin

===========================================================================*/
/*!
    @brief
    Allocates memory and converts a string from ASCII format into
    binary format.

    @return
    Buffer with binary data
*/
/*=========================================================================*/
uint8* qcril_uim_alloc_hexstring_to_bin
(
  const char * string_ptr,
  uint16     * buffer_size_ptr
);

/*=========================================================================

  FUNCTION:  qcril_uim_hexstring_to_bin

===========================================================================*/
/*!
    @brief
    Converts a ASCII string into a bibnary buffer.
    Memory is not allocated for this conversion

    @return
    Size of the data stored in the buffer
*/
/*=========================================================================*/
uint16 qcril_uim_hexstring_to_bin
(
  const char * string_ptr,
  uint8      * buffer_ptr,
  uint16       buffer_size
);

/*=========================================================================

  FUNCTION:  qcril_uim_bin_to_hexstring

===========================================================================*/
/*!
    @brief
    Converts a binary buffer into a string in ASCII format.
    Memory is allocated for the conversion.

    @return
    Pointer to the NULL terminated string
*/
/*=========================================================================*/
char* qcril_uim_alloc_bin_to_hexstring
(
  const uint8*  buffer_ptr,
  uint16        buffer_size
);

/*=========================================================================

  FUNCTION:  qcril_uim_bin_to_hexstring

===========================================================================*/
/*!
    @brief
    Converts a binary buffer into a string in ASCII format.
    Memory is not allocated for this conversion.

    @return
    None
*/
/*=========================================================================*/
void qcril_uim_bin_to_hexstring
(
  const uint8*  buffer_ptr,
  uint16        buffer_size,
  char*         string_ptr,
  uint16        string_size
);

/*===========================================================================

  FUNCTION:  qcril_uim_extract_session_type

===========================================================================*/
/*!
    @brief
    Extracts the session type from a SIM_IO request.
    The AID buffer is optional and is used only for non-provisioning
    session, in order to avoid allocating memory.

    @return
    RIL_UIM_Errno code
*/
/*=========================================================================*/
RIL_UIM_Errno qcril_uim_extract_session_type
(
  uint8                       slot,
  const char                * RIL_aid_ptr,
  uint16                      first_level_df_path,
  qmi_uim_session_info_type * session_info_ptr,
  uint8                     * aid_ptr,
  uint16                      max_aid_len
);

/*===========================================================================

  FUNCTION:  qcril_uim_extract_file_id

===========================================================================*/
/*!
    @brief
    Extract the file id and path from a SIM_IO request.

    @return
    RIL_UIM_Errno code
*/
/*=========================================================================*/
RIL_UIM_Errno qcril_uim_extract_file_id
(
  const RIL_UIM_SIM_IO     * request_io_ptr,
  qmi_uim_file_id_type     * file_id_ptr,
  uint8                    * path_ptr,
  uint16                     max_path_len
);


/*===========================================================================

  FUNCTION:  qcril_uim_extract_pin1_status

===========================================================================*/
/*!
    @brief
    Extract the pin1 status based on the passed application id.

    @return
    RIL_UIM_Errno code
*/
/*=========================================================================*/
RIL_UIM_Errno qcril_uim_extract_pin1_status
(
  uint8                           slot,
  const char                    * RIL_aid_ptr,
  qmi_uim_pin_status_type       * pin_status_ptr
);


/*===========================================================================

  FUNCTION:  qcril_uim_extract_index

===========================================================================*/
/*!
    @brief
    Extracts the provisioning application index & slot from session type.

    @return
    RIL_UIM_Errno code
*/
/*=========================================================================*/
RIL_UIM_Errno qcril_uim_extract_index
(
  uint8                       * index_ptr,
  uint8                       * slot_ptr,
  qmi_uim_session_type          session_type
);

/*=========================================================================

  FUNCTION:  qcril_uim_read_iccid

===========================================================================*/
/*!
    @brief
    Reads EF ICCID from card using CARD_SLOT session

    @return
    None.
*/
/*=========================================================================*/
RIL_UIM_Errno qcril_uim_read_iccid
(
  uint8                                      slot,
  uint8                                    * iccid_data,
  uint8                                    * iccid_len
);


/*===========================================================================

  FUNCTION:  qcril_uim_extract_isim_index

 ==========================================================================*/
/*!
     @brief
      Extracts the app index of ISIM application from slot

     @return
      RIL_UIM_Errno code
                                                                           */
/*=========================================================================*/
RIL_UIM_Errno qcril_uim_extract_isim_index
(
  uint8                       * index_ptr,
  uint8                         slot
);


/*=========================================================================

  FUNCTION:  qcril_uim_find_app_in_slot

===========================================================================*/
/*!
    @brief
    Function to find if the passed application type is present in the slot.

    @return
    TRUE if found, FALSE otherwise.
*/
/*=========================================================================*/
boolean qcril_uim_find_app_in_slot
(
  uint8                  slot,
  qmi_uim_app_type       app_type
);


/*=========================================================================

  FUNCTION:  qcril_uim_check_aid_with_app_type

===========================================================================*/
/*!
    @brief
    Determines if the given AID belongs to ISIM/USIM/CSIM app type

    @return
    boolean
*/
/*=========================================================================*/
boolean qcril_uim_check_aid_with_app_type
(
  const qmi_uim_data_type * aid_ptr,
  qmi_uim_app_type          app_type
);


/*=========================================================================

  FUNCTION:  qcril_uim_alloc_base64string_to_bin

===========================================================================*/
/*!
    @brief
    Allocates memory and converts a Base64 encoded ASCII string into
    binary format.

    @return
    Buffer with binary data
*/
/*=========================================================================*/
uint8* qcril_uim_alloc_base64string_to_bin
(
  const char    * input_ptr,
  uint16        * output_len_ptr
);


/*=========================================================================

  FUNCTION:  qcril_uim_alloc_bin_to_base64string

===========================================================================*/
/*!
    @brief
    Allocates memory and converts a binary datastream to a Base64 encoded
    ASCII string format.

    @return
    NULL terminated Base64 string
*/
/*=========================================================================*/
char* qcril_uim_alloc_bin_to_base64string
(
  const uint8    * input_ptr,
  uint16           input_len
);


/*=========================================================================

  FUNCTION:  qcril_uim_is_prov_app_type

===========================================================================*/
/*!
    @brief
    Function determines if the app type is provision or not.

    @return
    TRUE if provisioning, FALSE otherwise.
*/
/*=========================================================================*/
boolean qcril_uim_is_prov_app_type
(
  qmi_uim_app_type       app_type
);


/*=========================================================================

  FUNCTION:  qcril_uim_is_prov_app_activated

===========================================================================*/
/*!
    @brief
    Function determines if an app on the specified slot is activated.

    @return
    TRUE if activated, FALSE otherwise.
*/
/*=========================================================================*/
boolean qcril_uim_is_prov_app_activated
(
  uint8              slot,
  qmi_uim_app_type   app_type,
  uint8              aid_len,
  char             * aid_ptr
);


/*===========================================================================

  FUNCTION:  qcril_uim_determine_select_template_from_aid

===========================================================================*/
/*!
    @brief
    Function will attempt to determine the FCI values bases on the
    AID/FCI data pairs sent through the UI. If this information is
    not present or incorrect, then we will check hardcoded AID values
    to try and find a match.

    @return
    qcril_uim_fci_value_type
*/
/*=========================================================================*/
qcril_uim_fci_value_type qcril_uim_determine_select_template_from_aid
(
  const char                      * aid_ptr
);


/*===========================================================================

  FUNCTION:  qcril_uim_convert_fci_value

===========================================================================*/
/*!
    @brief
    Function converts QCRIL FCI value type to QMI FCI value type

    @return
    qmi_uim_fci_value_type
*/
/*=========================================================================*/
qmi_uim_fci_value_type qcril_uim_convert_fci_value
(
  qcril_uim_fci_value_type  qcril_fci_value
);


/*===========================================================================

  FUNCTION:  qcril_uim_convert_p2_value

===========================================================================*/
/*!
    @brief
    Function converts QCRIL P2 value type to QCRIL FCI value type

    @return
    RIL_UIM_Errno
*/
/*=========================================================================*/
RIL_UIM_Errno qcril_uim_convert_p2_value
(
  int                        qcril_p2_value,
  qcril_uim_fci_value_type  *qcril_fci_value_ptr
);

/*===========================================================================

FUNCTION:  qcril_uim_util_iccid_to_string

===========================================================================*/
char * qcril_uim_util_iccid_to_string
(
  const uint8_t * iccid_ptr,
  uint16_t        iccid_len
);

/*===========================================================================

  FUNCTION:  qmi_uim_convert_req_type_to_rsp_id

===========================================================================*/
/*!
    @brief
    Converts request type to rsp id

    @return
    qmi_uim_rsp_id_type
*/
/*=========================================================================*/
qmi_uim_rsp_id_type qmi_uim_convert_req_type_to_rsp_id
(
  uint32_t                       request_type
);


/*===========================================================================

  FUNCTION:  qcril_uim_convert_err_value

===========================================================================*/
/*!
    @brief
    Function converts QCRIL error value type to RIL error

    @return
    RIL_Errno
*/
/*=========================================================================*/
RIL_UIM_Errno qcril_uim_convert_err_value
(
  int          qcril_err_code
);

#endif /* QCRIL_UIM_UTIL_H */

