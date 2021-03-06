#pragma once
// AUTOGENERATED FILE: DO NOT EDIT

#include <stdint.h>
#include "object.h"
#include "ICert.h"

// ============================================================================
// Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
// ============================================================================

#define ICertManager_TAG_RDN_LIST UINT32_C(0)
#define ICertManager_TAG_RDN_COMMON_NAME UINT32_C(1)
#define ICertManager_TAG_RDN_ORG UINT32_C(2)
#define ICertManager_TAG_RDN_ORG_UNIT UINT32_C(3)
#define ICertManager_TAG_RDN_LOCALITY UINT32_C(4)
#define ICertManager_TAG_RDN_STATE UINT32_C(5)
#define ICertManager_TAG_RDN_COUNTRY UINT32_C(6)
#define ICertManager_TAG_RDN_SERIAL_NUM UINT32_C(7)
#define ICertManager_TAG_DIGEST_ALG UINT32_C(8)
#define ICertManager_DIGEST_SHA_2_256 UINT32_C(9)
#define ICertManager_DIGEST_SHA_2_384 UINT32_C(10)
#define ICertManager_DIGEST_SHA_2_512 UINT32_C(11)
#define ICertManager_USAGE_TYPE_PROVISIONING UINT32_C(12)
#define ICertManager_USAGE_TYPE_TLS UINT32_C(13)

#define ICertManager_ERROR_CERT_ID_NOT_FOUND INT32_C(10)
#define ICertManager_ERROR_SERVICE_ID_NOT_FOUND INT32_C(11)
#define ICertManager_ERROR_NO_ROTATIONS INT32_C(12)
#define ICertManager_ERROR_FUNCTION_NOT_IMPLEMENTED INT32_C(13)

#define ICertManager_OP_generateCSR 0
#define ICertManager_OP_generateSecureCSR 1
#define ICertManager_OP_saveCert 2
#define ICertManager_OP_getCertObj 3
#define ICertManager_OP_getCertIds 4
#define ICertManager_OP_generateRotationCSR 5
#define ICertManager_OP_removeCert 6

static inline int32_t
ICertManager_release(Object self)
{
  return Object_invoke(self, Object_OP_release, 0, 0);
}

static inline int32_t
ICertManager_retain(Object self)
{
  return Object_invoke(self, Object_OP_retain, 0, 0);
}

static inline int32_t
ICertManager_generateCSR(Object self, uint32_t UsageType_val, const void *KeyParams_CBOR_ptr, size_t KeyParams_CBOR_len, const void *CsrParams_CBOR_ptr, size_t CsrParams_CBOR_len, uint8_t *CSR_ptr, size_t CSR_len, size_t *CSR_lenout)
{
  ObjectArg a[4];
  a[0].b = (ObjectBuf) { &UsageType_val, sizeof(uint32_t) };
  a[1].bi = (ObjectBufIn) { KeyParams_CBOR_ptr, KeyParams_CBOR_len * 1 };
  a[2].bi = (ObjectBufIn) { CsrParams_CBOR_ptr, CsrParams_CBOR_len * 1 };
  a[3].b = (ObjectBuf) { CSR_ptr, CSR_len * sizeof(uint8_t) };

  int32_t result = Object_invoke(self, ICertManager_OP_generateCSR, a, ObjectCounts_pack(3, 1, 0, 0));

  *CSR_lenout = a[3].b.size / sizeof(uint8_t);

  return result;
}

static inline int32_t
ICertManager_generateSecureCSR(Object self, uint32_t UsageType_val, const void *KeyParams_CBOR_ptr, size_t KeyParams_CBOR_len, const void *CsrParams_CBOR_ptr, size_t CsrParams_CBOR_len, const void *HavenToken_License_ptr, size_t HavenToken_License_len, const void *CertReq_HavenT_Input_CBOR_ptr, size_t CertReq_HavenT_Input_CBOR_len, uint8_t *HavenToken_CSR_ptr, size_t HavenToken_CSR_len, size_t *HavenToken_CSR_lenout)
{
  ObjectArg a[6];
  a[0].b = (ObjectBuf) { &UsageType_val, sizeof(uint32_t) };
  a[1].bi = (ObjectBufIn) { KeyParams_CBOR_ptr, KeyParams_CBOR_len * 1 };
  a[2].bi = (ObjectBufIn) { CsrParams_CBOR_ptr, CsrParams_CBOR_len * 1 };
  a[3].bi = (ObjectBufIn) { HavenToken_License_ptr, HavenToken_License_len * 1 };
  a[4].bi = (ObjectBufIn) { CertReq_HavenT_Input_CBOR_ptr, CertReq_HavenT_Input_CBOR_len * 1 };
  a[5].b = (ObjectBuf) { HavenToken_CSR_ptr, HavenToken_CSR_len * sizeof(uint8_t) };

  int32_t result = Object_invoke(self, ICertManager_OP_generateSecureCSR, a, ObjectCounts_pack(5, 1, 0, 0));

  *HavenToken_CSR_lenout = a[5].b.size / sizeof(uint8_t);

  return result;
}

static inline int32_t
ICertManager_saveCert(Object self, const void *Certificate_ptr, size_t Certificate_len, uint8_t *CertId_ptr, size_t CertId_len, size_t *CertId_lenout)
{
  ObjectArg a[2];
  a[0].bi = (ObjectBufIn) { Certificate_ptr, Certificate_len * 1 };
  a[1].b = (ObjectBuf) { CertId_ptr, CertId_len * sizeof(uint8_t) };

  int32_t result = Object_invoke(self, ICertManager_OP_saveCert, a, ObjectCounts_pack(1, 1, 0, 0));

  *CertId_lenout = a[1].b.size / sizeof(uint8_t);

  return result;
}

static inline int32_t
ICertManager_getCertObj(Object self, const uint8_t *CertId_ptr, size_t CertId_len, Object *CertObj_ptr)
{
  ObjectArg a[2];
  a[0].bi = (ObjectBufIn) { CertId_ptr, CertId_len * sizeof(uint8_t) };

  int32_t result = Object_invoke(self, ICertManager_OP_getCertObj, a, ObjectCounts_pack(1, 0, 0, 1));

  *CertObj_ptr = a[1].o;

  return result;
}

static inline int32_t
ICertManager_getCertIds(Object self, const void *ServiceId_ptr, size_t ServiceId_len, uint8_t *CertIdsCBOR_ptr, size_t CertIdsCBOR_len, size_t *CertIdsCBOR_lenout)
{
  ObjectArg a[2];
  a[0].bi = (ObjectBufIn) { ServiceId_ptr, ServiceId_len * 1 };
  a[1].b = (ObjectBuf) { CertIdsCBOR_ptr, CertIdsCBOR_len * sizeof(uint8_t) };

  int32_t result = Object_invoke(self, ICertManager_OP_getCertIds, a, ObjectCounts_pack(1, 1, 0, 0));

  *CertIdsCBOR_lenout = a[1].b.size / sizeof(uint8_t);

  return result;
}

static inline int32_t
ICertManager_generateRotationCSR(Object self, uint32_t ExpirationLimitSeconds_val, const void *HavenToken_License_ptr, size_t HavenToken_License_len, uint8_t *HavenToken_CSR_ptr, size_t HavenToken_CSR_len, size_t *HavenToken_CSR_lenout)
{
  ObjectArg a[3];
  a[0].b = (ObjectBuf) { &ExpirationLimitSeconds_val, sizeof(uint32_t) };
  a[1].bi = (ObjectBufIn) { HavenToken_License_ptr, HavenToken_License_len * 1 };
  a[2].b = (ObjectBuf) { HavenToken_CSR_ptr, HavenToken_CSR_len * sizeof(uint8_t) };

  int32_t result = Object_invoke(self, ICertManager_OP_generateRotationCSR, a, ObjectCounts_pack(2, 1, 0, 0));

  *HavenToken_CSR_lenout = a[2].b.size / sizeof(uint8_t);

  return result;
}

static inline int32_t
ICertManager_removeCert(Object self, const uint8_t *CertId_ptr, size_t CertId_len)
{
  ObjectArg a[1];
  a[0].bi = (ObjectBufIn) { CertId_ptr, CertId_len * sizeof(uint8_t) };

  return Object_invoke(self, ICertManager_OP_removeCert, a, ObjectCounts_pack(1, 0, 0, 0));
}



