/*
 * Copyright (c) 2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef KEYMASTER_UTILS_KEYMASTERUTILS_H_
#define KEYMASTER_UTILS_KEYMASTERUTILS_H_

#include <hardware/keymaster_defs.h>
#include <QSEEComAPI.h>
#include <linux/msm_ion.h>

#define KEYMASTER_MODULE_API_VERSION_3_0 (3)
#define KEYMASTER_MODULE_API_VERSION_4_0 (4)
#define KEYMASTER_MODULE_HAL_MINOR_VERSION (5)
#define QTI_KM_SHARED_BUF_LEN (40 * 1024)
#define QTI_KM_INPUT_BUF_LEN (16 * 1024)
#define QTI_KM_SPU_INPUT_BUF_LEN (18 * 1024)
#define SPU_BUF_SIZE (20 * 1024)

namespace keymasterutils {

#define GUARD(code)                \
    do {                           \
       ret = (code);               \
       if (ret != 0) {             \
          return ret;              \
       };                          \
    }while(0)

#define GUARD_BAIL(code, status)                   \
    do {                                           \
        if ((code) || (status != KM_ERROR_OK)) {   \
            ALOGE("%s", __func__);                 \
            ALOGE("ret: %d", code);                \
            ALOGE("resp->status: %d", status);     \
            if (ret)                               \
                return ret;                        \
            else                                   \
                ret = (keymaster_error_t) status;  \
            return ret;                            \
        }                                          \
    }while(0)

#if ENABLE_SPU

typedef struct {
   int32_t ion_fd;
   int32_t ifd_data_fd;
   uint32_t sbuf_len;
} sp_km_ion_info;

#endif

typedef struct {
    keymaster_security_level_t level;
    uint32_t major_version = 0;
    uint32_t minor_version = 0;
    uint32_t ta_major_version = 0;
    uint32_t ta_minor_version = 0;
    //struct QSEECom_handle *qseecom = NULL;
    void *qseecom_handle = NULL;
#if ENABLE_SPU
    sp_km_ion_info ion_info;
    uint32_t spu_initialized = 0;
    uint32_t shared_buf_allocated = 0;
    uint32_t spu_available;
#endif
}ctx_t;

class KeymasterUtils {

public:
    KeymasterUtils(keymaster_security_level_t security_level);
    virtual ~KeymasterUtils();

    size_t km_memscpy(void *dst, size_t dst_size, const void *src, size_t src_size);

    keymaster_error_t initialize(size_t size);
    keymaster_error_t gk_initialize(size_t size);
    uint32_t getKeymasterVersion(void);
    uint32_t getKeymasterTaMinorVersion(void);
    uint32_t getKeymasterHalMinorVersion(void);
    void* qseecom_dev_init(void);
    keymaster_error_t send_cmd(void *send_buf,
            uint32_t sbuf_len, void *resp_buf, uint32_t rbuf_len);
    keymaster_error_t spu_init(void);
    void IsTeeKmAvailable(void);
    keymaster_error_t IsSbKmAvailable(void);
private:
    ctx_t *ctx;
};

}
#endif /* KEYMASTER_UTILS_KEYMASTERUTILS_H_ */
