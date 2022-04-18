/*
 * Copyright 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "attestation_record.h"

#include <assert.h>

#include <openssl/asn1t.h>

//#include "openssl_err.h"
//#include "openssl_utils.h"
#include <android_keymaster_utils.h>
//#include <keymaster/keymaster_context.h>

//using namespace keymasterdevice;

namespace keymaster {

template<typename T, void (*FreeFunc)(T*)> struct OpenSslObjectDeleter {
    void operator()(T* p) {
        FreeFunc(p);
    }
};

typedef OpenSslObjectDeleter<BIGNUM, BN_free> BIGNUM_Delete;

struct stack_st_ASN1_TYPE_Delete {
    void operator()(stack_st_ASN1_TYPE* p) { sk_ASN1_TYPE_free(p); }
};

struct ASN1_STRING_Delete {
    void operator()(ASN1_STRING* p) { ASN1_STRING_free(p); }
};

struct ASN1_TYPE_Delete {
    void operator()(ASN1_TYPE* p) { ASN1_TYPE_free(p); }
};

#define ASN1_INTEGER_SET STACK_OF(ASN1_INTEGER)

typedef struct km_root_of_trust {
    ASN1_OCTET_STRING* verified_boot_key;
    ASN1_BOOLEAN* device_locked;
    ASN1_ENUMERATED* verified_boot_state;
    ASN1_OCTET_STRING* verified_boot_hash;
} KM_ROOT_OF_TRUST;

ASN1_SEQUENCE(KM_ROOT_OF_TRUST) = {
    ASN1_SIMPLE(KM_ROOT_OF_TRUST, verified_boot_key, ASN1_OCTET_STRING),
    ASN1_SIMPLE(KM_ROOT_OF_TRUST, device_locked, ASN1_BOOLEAN),
    ASN1_SIMPLE(KM_ROOT_OF_TRUST, verified_boot_state, ASN1_ENUMERATED),
    ASN1_SIMPLE(KM_ROOT_OF_TRUST, verified_boot_hash, ASN1_OCTET_STRING),
} ASN1_SEQUENCE_END(KM_ROOT_OF_TRUST);
IMPLEMENT_ASN1_FUNCTIONS(KM_ROOT_OF_TRUST);

typedef struct km_auth_list {
    ASN1_INTEGER_SET* purpose;
    ASN1_INTEGER* algorithm;
    ASN1_INTEGER* key_size;
    ASN1_INTEGER_SET* digest;
    ASN1_INTEGER_SET* padding;
    ASN1_INTEGER_SET* kdf;
    ASN1_INTEGER* ec_curve;
    ASN1_INTEGER* rsa_public_exponent;
    ASN1_NULL* rollback_resistance;
    ASN1_INTEGER* active_date_time;
    ASN1_INTEGER* origination_expire_date_time;
    ASN1_INTEGER* usage_expire_date_time;
    ASN1_NULL* no_auth_required;
    ASN1_INTEGER* user_auth_type;
    ASN1_INTEGER* auth_timeout;
    ASN1_NULL* allow_while_on_body;
    ASN1_NULL* user_presence_required;
    ASN1_NULL* trusted_confirmation_required;
    ASN1_NULL* unlocked_device_required;
    ASN1_NULL* all_applications;
    ASN1_OCTET_STRING* application_id;
    ASN1_INTEGER* creation_date_time;
    ASN1_INTEGER* origin;
    ASN1_NULL* rollback_resistant;
    KM_ROOT_OF_TRUST* root_of_trust;
    ASN1_INTEGER* os_version;
    ASN1_INTEGER* os_patchlevel;
    ASN1_OCTET_STRING* attestation_application_id;
    ASN1_OCTET_STRING* attestation_id_brand;
    ASN1_OCTET_STRING* attestation_id_device;
    ASN1_OCTET_STRING* attestation_id_product;
    ASN1_OCTET_STRING* attestation_id_serial;
    ASN1_OCTET_STRING* attestation_id_imei;
    ASN1_OCTET_STRING* attestation_id_meid;
    ASN1_OCTET_STRING* attestation_id_manufacturer;
    ASN1_OCTET_STRING* attestation_id_model;
    ASN1_INTEGER* vendor_patchlevel;
    ASN1_INTEGER* boot_patchlevel;
} KM_AUTH_LIST;

ASN1_SEQUENCE(KM_AUTH_LIST) = {
    ASN1_EXP_SET_OF_OPT(KM_AUTH_LIST, purpose, ASN1_INTEGER, TAG_PURPOSE.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, algorithm, ASN1_INTEGER, TAG_ALGORITHM.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, key_size, ASN1_INTEGER, TAG_KEY_SIZE.masked_tag()),
    ASN1_EXP_SET_OF_OPT(KM_AUTH_LIST, digest, ASN1_INTEGER, TAG_DIGEST.masked_tag()),
    ASN1_EXP_SET_OF_OPT(KM_AUTH_LIST, padding, ASN1_INTEGER, TAG_PADDING.masked_tag()),
    ASN1_EXP_SET_OF_OPT(KM_AUTH_LIST, kdf, ASN1_INTEGER, TAG_KDF.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, ec_curve, ASN1_INTEGER, TAG_EC_CURVE.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, rsa_public_exponent, ASN1_INTEGER,
                 TAG_RSA_PUBLIC_EXPONENT.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, rollback_resistance, ASN1_NULL, TAG_ROLLBACK_RESISTANCE.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, active_date_time, ASN1_INTEGER, TAG_ACTIVE_DATETIME.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, origination_expire_date_time, ASN1_INTEGER,
                 TAG_ORIGINATION_EXPIRE_DATETIME.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, usage_expire_date_time, ASN1_INTEGER,
                 TAG_USAGE_EXPIRE_DATETIME.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, no_auth_required, ASN1_NULL, TAG_NO_AUTH_REQUIRED.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, user_auth_type, ASN1_INTEGER, TAG_USER_AUTH_TYPE.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, auth_timeout, ASN1_INTEGER, TAG_AUTH_TIMEOUT.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, allow_while_on_body, ASN1_NULL,
                 TAG_ALLOW_WHILE_ON_BODY.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, user_presence_required, ASN1_NULL,
                 TRUSTED_USER_PRESENCE_REQUIRED.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, trusted_confirmation_required, ASN1_NULL,
                 TRUSTED_CONFIRMATION_REQUIRED.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, unlocked_device_required, ASN1_NULL,
                 UNLOCKED_DEVICE_REQUIRED.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, all_applications, ASN1_NULL, TAG_ALL_APPLICATIONS.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, application_id, ASN1_OCTET_STRING, TAG_APPLICATION_ID.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, creation_date_time, ASN1_INTEGER,
                 TAG_CREATION_DATETIME.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, origin, ASN1_INTEGER, TAG_ORIGIN.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, rollback_resistant, ASN1_NULL, TAG_ROLLBACK_RESISTANT.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, root_of_trust, KM_ROOT_OF_TRUST, TAG_ROOT_OF_TRUST.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, os_version, ASN1_INTEGER, TAG_OS_VERSION.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, os_patchlevel, ASN1_INTEGER, TAG_OS_PATCHLEVEL.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, attestation_application_id, ASN1_OCTET_STRING,
                 TAG_ATTESTATION_APPLICATION_ID.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, attestation_id_brand, ASN1_OCTET_STRING,
                 TAG_ATTESTATION_ID_BRAND.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, attestation_id_device, ASN1_OCTET_STRING,
                 TAG_ATTESTATION_ID_DEVICE.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, attestation_id_product, ASN1_OCTET_STRING,
                 TAG_ATTESTATION_ID_PRODUCT.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, attestation_id_serial, ASN1_OCTET_STRING,
                 TAG_ATTESTATION_ID_SERIAL.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, attestation_id_imei, ASN1_OCTET_STRING,
                 TAG_ATTESTATION_ID_IMEI.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, attestation_id_meid, ASN1_OCTET_STRING,
                 TAG_ATTESTATION_ID_MEID.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, attestation_id_manufacturer, ASN1_OCTET_STRING,
                 TAG_ATTESTATION_ID_MANUFACTURER.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, attestation_id_model, ASN1_OCTET_STRING,
                 TAG_ATTESTATION_ID_MODEL.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, vendor_patchlevel, ASN1_INTEGER, TAG_VENDOR_PATCHLEVEL.masked_tag()),
    ASN1_EXP_OPT(KM_AUTH_LIST, boot_patchlevel, ASN1_INTEGER, BOOT_PATCHLEVEL.masked_tag()),
} ASN1_SEQUENCE_END(KM_AUTH_LIST);
IMPLEMENT_ASN1_FUNCTIONS(KM_AUTH_LIST);

typedef struct km_key_description {
    ASN1_INTEGER* attestation_version;
    ASN1_ENUMERATED* attestation_security_level;
    ASN1_INTEGER* keymaster_version;
    ASN1_ENUMERATED* keymaster_security_level;
    ASN1_OCTET_STRING* attestation_challenge;
    KM_AUTH_LIST* software_enforced;
    KM_AUTH_LIST* tee_enforced;
    ASN1_INTEGER* unique_id;
} KM_KEY_DESCRIPTION;

ASN1_SEQUENCE(KM_KEY_DESCRIPTION) = {
    ASN1_SIMPLE(KM_KEY_DESCRIPTION, attestation_version, ASN1_INTEGER),
    ASN1_SIMPLE(KM_KEY_DESCRIPTION, attestation_security_level, ASN1_ENUMERATED),
    ASN1_SIMPLE(KM_KEY_DESCRIPTION, keymaster_version, ASN1_INTEGER),
    ASN1_SIMPLE(KM_KEY_DESCRIPTION, keymaster_security_level, ASN1_ENUMERATED),
    ASN1_SIMPLE(KM_KEY_DESCRIPTION, attestation_challenge, ASN1_OCTET_STRING),
    ASN1_SIMPLE(KM_KEY_DESCRIPTION, unique_id, ASN1_OCTET_STRING),
    ASN1_SIMPLE(KM_KEY_DESCRIPTION, software_enforced, KM_AUTH_LIST),
    ASN1_SIMPLE(KM_KEY_DESCRIPTION, tee_enforced, KM_AUTH_LIST),
} ASN1_SEQUENCE_END(KM_KEY_DESCRIPTION);
IMPLEMENT_ASN1_FUNCTIONS(KM_KEY_DESCRIPTION);

struct KM_AUTH_LIST_Delete {
    void operator()(KM_AUTH_LIST* p) { KM_AUTH_LIST_free(p); }
};

struct KM_KEY_DESCRIPTION_Delete {
    void operator()(KM_KEY_DESCRIPTION* p) { KM_KEY_DESCRIPTION_free(p); }
};

// Copy all enumerated values with the specified tag from stack to auth_list.
static bool get_repeated_enums(const stack_st_ASN1_INTEGER* stack, keymaster_tag_t tag,
                               AuthorizationSet* auth_list) {
    assert(keymaster_tag_get_type(tag) == KM_ENUM_REP);
    for (size_t i = 0; i < sk_ASN1_INTEGER_num(stack); ++i) {
        if (!auth_list->push_back(
                keymaster_param_enum(tag, ASN1_INTEGER_get(sk_ASN1_INTEGER_value(stack, i)))))
            return false;
    }
    return true;
}

// Add the specified integer tag/value pair to auth_list.
template <keymaster_tag_type_t Type, keymaster_tag_t Tag, typename KeymasterEnum>
static bool get_enum(const ASN1_INTEGER* asn1_int, TypedEnumTag<Type, Tag, KeymasterEnum> tag,
                     AuthorizationSet* auth_list) {
    if (!asn1_int)
        return true;
    return auth_list->push_back(tag, static_cast<KeymasterEnum>(ASN1_INTEGER_get(asn1_int)));
}

// Add the specified ulong tag/value pair to auth_list.
static bool get_ulong(const ASN1_INTEGER* asn1_int, keymaster_tag_t tag,
                      AuthorizationSet* auth_list) {
    uint64_t ulong;
    if (!asn1_int)
        return true;
    std::unique_ptr<BIGNUM, BIGNUM_Delete> bn(ASN1_INTEGER_to_BN(asn1_int, nullptr));
    if (!bn.get())
        return false;
    if (!BN_get_u64(bn.get(), &ulong))
        return false;
    return auth_list->push_back(keymaster_param_long(tag, ulong));
}

// Extract the values from the specified ASN.1 record and place them in auth_list.
static keymaster_error_t extract_auth_list(const KM_AUTH_LIST* record,
                                           AuthorizationSet* auth_list) {
    if (!record)
        return KM_ERROR_OK;

    // Purpose
    if (!get_repeated_enums(record->purpose, TAG_PURPOSE, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Algorithm
    if (!get_enum(record->algorithm, TAG_ALGORITHM, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Key size
    if (record->key_size && !auth_list->push_back(TAG_KEY_SIZE, ASN1_INTEGER_get(record->key_size)))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Digest
    if (!get_repeated_enums(record->digest, TAG_DIGEST, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Padding
    if (!get_repeated_enums(record->padding, TAG_PADDING, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // EC curve
    if (!get_enum(record->ec_curve, TAG_EC_CURVE, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // RSA public exponent
    if (!get_ulong(record->rsa_public_exponent, TAG_RSA_PUBLIC_EXPONENT, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Rollback resistance
    if (record->rollback_resistance && !auth_list->push_back(TAG_ROLLBACK_RESISTANCE))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Active date time
    if (!get_ulong(record->active_date_time, TAG_ACTIVE_DATETIME, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Origination expire date time
    if (!get_ulong(record->origination_expire_date_time, TAG_ORIGINATION_EXPIRE_DATETIME,
                   auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Usage Expire date time
    if (!get_ulong(record->usage_expire_date_time, TAG_USAGE_EXPIRE_DATETIME, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // No auth required
    if (record->no_auth_required && !auth_list->push_back(TAG_NO_AUTH_REQUIRED))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // User auth type
    if (!get_enum(record->user_auth_type, TAG_USER_AUTH_TYPE, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Auth timeout
    if (record->auth_timeout &&
        !auth_list->push_back(TAG_AUTH_TIMEOUT, ASN1_INTEGER_get(record->auth_timeout)))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // user_presence_required
    if (record->user_presence_required && !auth_list->push_back(TRUSTED_USER_PRESENCE_REQUIRED))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // trusted_confirmation_required
    if (record->trusted_confirmation_required && !auth_list->push_back(TRUSTED_CONFIRMATION_REQUIRED))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // unlocked_device_required
    if (record->unlocked_device_required && !auth_list->push_back(UNLOCKED_DEVICE_REQUIRED))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // All applications
    if (record->all_applications && !auth_list->push_back(TAG_ALL_APPLICATIONS))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Application ID
    if (record->application_id &&
        !auth_list->push_back(TAG_APPLICATION_ID, record->application_id->data,
                              record->application_id->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Creation date time
    if (!get_ulong(record->creation_date_time, TAG_CREATION_DATETIME, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Origin
    if (!get_enum(record->origin, TAG_ORIGIN, auth_list))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Rollback resistant
    if (record->rollback_resistant && !auth_list->push_back(TAG_ROLLBACK_RESISTANT))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Root of trust
    if (record->root_of_trust) {
        KM_ROOT_OF_TRUST* rot = record->root_of_trust;
        if (!rot->verified_boot_key)
            return KM_ERROR_INVALID_KEY_BLOB;

        // Other root of trust fields are not mapped to auth set entries.
    }

    // attestation_application_id
    if (record->attestation_application_id &&
        !auth_list->push_back(TAG_ATTESTATION_APPLICATION_ID, record->attestation_application_id->data,
                              record->attestation_application_id->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // OS Version
    if (record->os_version &&
        !auth_list->push_back(TAG_OS_VERSION, ASN1_INTEGER_get(record->os_version)))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // OS Patch level
    if (record->os_patchlevel &&
        !auth_list->push_back(TAG_OS_PATCHLEVEL, ASN1_INTEGER_get(record->os_patchlevel)))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Brand name
    if (record->attestation_id_brand &&
        !auth_list->push_back(TAG_ATTESTATION_ID_BRAND, record->attestation_id_brand->data,
                              record->attestation_id_brand->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Device name
    if (record->attestation_id_device &&
        !auth_list->push_back(TAG_ATTESTATION_ID_DEVICE, record->attestation_id_device->data,
                              record->attestation_id_device->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Product name
    if (record->attestation_id_product &&
        !auth_list->push_back(TAG_ATTESTATION_ID_PRODUCT, record->attestation_id_product->data,
                              record->attestation_id_product->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Serial number
    if (record->attestation_id_serial &&
        !auth_list->push_back(TAG_ATTESTATION_ID_SERIAL, record->attestation_id_serial->data,
                              record->attestation_id_serial->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // IMEI
    if (record->attestation_id_imei &&
        !auth_list->push_back(TAG_ATTESTATION_ID_IMEI, record->attestation_id_imei->data,
                              record->attestation_id_imei->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // MEID
    if (record->attestation_id_meid &&
        !auth_list->push_back(TAG_ATTESTATION_ID_MEID, record->attestation_id_meid->data,
                              record->attestation_id_meid->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // MANUFACTURER
    if (record->attestation_id_manufacturer &&
        !auth_list->push_back(TAG_ATTESTATION_ID_MANUFACTURER, record->attestation_id_manufacturer->data,
                              record->attestation_id_manufacturer->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // MODEL
    if (record->attestation_id_model &&
        !auth_list->push_back(TAG_ATTESTATION_ID_MODEL, record->attestation_id_model->data,
                              record->attestation_id_model->length))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Vendor Patch Level
    if (record->vendor_patchlevel &&
        !auth_list->push_back(TAG_VENDOR_PATCHLEVEL, ASN1_INTEGER_get(record->vendor_patchlevel)))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    // Boot Patch Level
    if (record->boot_patchlevel &&
        !auth_list->push_back(BOOT_PATCHLEVEL, ASN1_INTEGER_get(record->boot_patchlevel)))
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    return KM_ERROR_OK;
}

// Parse the DER-encoded attestation record, placing the results in keymaster_version,
// attestation_challenge, software_enforced, tee_enforced and unique_id.
keymaster_error_t parse_attestation_record(const uint8_t* asn1_key_desc, size_t asn1_key_desc_len,
                                           uint32_t* attestation_version,  //
                                           keymaster_security_level_t* attestation_security_level,
                                           uint32_t* keymaster_version,
                                           keymaster_security_level_t* keymaster_security_level,
                                           keymaster_blob_t* attestation_challenge,
                                           AuthorizationSet* software_enforced,
                                           AuthorizationSet* tee_enforced,
                                           keymaster_blob_t* unique_id) {
    const uint8_t* p = asn1_key_desc;
    std::unique_ptr<KM_KEY_DESCRIPTION, KM_KEY_DESCRIPTION_Delete> record(
        d2i_KM_KEY_DESCRIPTION(nullptr, &p, asn1_key_desc_len));
    if (!record.get())
        return KM_ERROR_UNKNOWN_ERROR;

    *attestation_version = ASN1_INTEGER_get(record->attestation_version);
    *attestation_security_level = static_cast<keymaster_security_level_t>(
        ASN1_ENUMERATED_get(record->attestation_security_level));
    *keymaster_version = ASN1_INTEGER_get(record->keymaster_version);
    *keymaster_security_level = static_cast<keymaster_security_level_t>(
        ASN1_ENUMERATED_get(record->keymaster_security_level));

    attestation_challenge->data =
        dup_buffer(record->attestation_challenge->data, record->attestation_challenge->length);
    attestation_challenge->data_length = record->attestation_challenge->length;

    unique_id->data = dup_buffer(record->unique_id->data, record->unique_id->length);
    unique_id->data_length = record->unique_id->length;

    keymaster_error_t error = extract_auth_list(record->software_enforced, software_enforced);
    if (error != KM_ERROR_OK)
        return error;

    return extract_auth_list(record->tee_enforced, tee_enforced);
}

}  // namepace keymaster

