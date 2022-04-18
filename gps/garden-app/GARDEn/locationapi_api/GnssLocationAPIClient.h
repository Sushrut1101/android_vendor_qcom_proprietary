/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#ifndef GNSSLOCATIONAPICLIENT_H
#define GNSSLOCATIONAPICLIENT_H

#include <LocationAPIClientBase.h>
#include <loc_gps.h>
#include <location_interface.h>
#include <LocationAPI.h>
#include "GnssCbBase.h"

namespace garden {

class GnssLocationAPIClient: public LocationAPIClientBase {
public:
    GnssLocationAPIClient(LocationAPIControlClient* ControlClient);
    ~GnssLocationAPIClient();
    int setCallbacks(GnssCbBase* callbacks);

    int gnssStart(void);
    int gnssInjectLocation(double latitude, double longitude, float accuracy);
    void gnssDeleteAidingData(LocGpsAidingData flags);
    int gnssSetPositionMode(LocGpsPositionMode mode, LocGpsPositionRecurrence recurrence,
            uint32_t min_interval, uint32_t preferred_accuracy, uint32_t preferred_time);

    void configurationUpdate(const char* config_data, int32_t length);
    void updateNetworkAvailability(int available, const char* apn);

    //callbacks
    void onTrackingCb(Location location) final;
    void onStartTrackingCb(LocationError error) final;
    void onStopTrackingCb(LocationError error) final;
    void onGnssSvCb(GnssSvNotification gnssSvNotification) final;
    void onGnssNmeaCb(GnssNmeaNotification gnssNmeaNotification) final;
    void onGnssMeasurementsCb(GnssMeasurementsNotification gnssMeasurementsNotification) final;
    void onGnssDataCb(GnssDataNotification gnssDataNotification) final;
    void onCapabilitiesCb(LocationCapabilitiesMask capabilitiesMask) final;
    void onGnssNiCb(uint32_t id, GnssNiNotification gnssNiNotification) final;
    void onGnssLocationInfoCb(GnssLocationInfoNotification gnssLocInfoNotif) final;

    LocationAPIControlClient* mControlClient;
private:
    GnssInterface* getGnssInterface();
private:
    mutex mGnssLock;
    TrackingOptions mLocationOptions;
    GnssInterface* mGnssInterface;
    LocationCapabilitiesMask mLocationCapabilitiesMask;
    GnssCbBase* mGnssCallbacks;
};

} // namespace garden

#endif //GNSSLOCATIONAPICLIENT_H

