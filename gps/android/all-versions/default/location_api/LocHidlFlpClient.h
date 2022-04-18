/*
 * Copyright (c) 2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
#ifndef LOC_HIDL_VERSION
#error "LOC_HIDL_VERSION must be set before including this file."
#endif

#include <vendor/qti/gnss/1.1/ILocHidlFlpService.h>
#include <vendor/qti/gnss/1.0/ILocHidlFlpServiceCallback.h>
#include <LocationAPI.h>
#include <location_interface.h>
#include <LocationAPIClientBase.h>

namespace vendor {
namespace qti {
namespace gnss {
namespace LOC_HIDL_VERSION {
namespace implementation {

using ::android::sp;

class LocHidlFlpClient : public LocationAPIClientBase
{
public:
    LocHidlFlpClient(const sp<::vendor::qti::gnss::V1_0::ILocHidlFlpServiceCallback>& callback);
    virtual ~LocHidlFlpClient() = default;

    void onCapabilitiesCb(LocationCapabilitiesMask capabilitiesMask) final;
    void onTrackingCb(Location location) final;
    void onBatchingCb(size_t count, Location* locations, BatchingOptions BatchingOptions) final;
    void onBatchingStatusCb(BatchingStatusInfo batchingStatus,
            std::list<uint32_t> &listOfCompletedTrips) final;

    uint32_t locAPIGnssDeleteAidingData(GnssAidingData& data);
    uint32_t updateXtraThrottle(const bool enabled);

private:
    GnssInterface* getGnssInterface();

public:
    LocationCapabilitiesMask mCapabilitiesMask;

private:
    sp<::vendor::qti::gnss::V1_0::ILocHidlFlpServiceCallback> mGnssCbIface;
    GnssInterface* mGnssInterface;
};

}  // namespace implementation
}  // namespace LOC_HIDL_VERSION
}  // namespace gnss
}  // namespace qti
}  // namespace vendor
