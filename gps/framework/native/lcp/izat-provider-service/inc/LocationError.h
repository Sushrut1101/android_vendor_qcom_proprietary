/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

GENERAL DESCRIPTION
  IZatLocationError

  Copyright  (c) 2015, 2018 Qualcomm Technologies, Inc.
  All Rights Reserved. Qualcomm Technologies Proprietary and Confidential.
=============================================================================*/

#ifndef __IZAT_MANAGER_LOCATIONERROR_H__
#define __IZAT_MANAGER_LOCATIONERROR_H__

#include <stdio.h>

namespace izat_manager
{

class IZatLocationError {
public:
    typedef enum LocationErrorType {
        LocationError_NoPosition,
        LocationError_Timeout,
        LocationError_TimeoutImmediateFix,
    } LocationErrorType;

    bool mHasErrorType;
    LocationErrorType mLocationErrorType;

    IZatLocationError() {
        reset();
    }

    IZatLocationError(const IZatLocationError &locError) {
        makeCopy(locError);
    }

    virtual ~IZatLocationError() {
        reset();
    };

    IZatLocationError & operator=(const IZatLocationError &locError) {
        makeCopy(locError);
        return *this;
    }

    void reset() {
        mHasErrorType = false;
    }

    bool isValid() const {
        return mHasErrorType;
    }

    void stringify (string & valueStr) const {
        if (isValid ()) {
            valueStr.clear ();
            valueStr += "Location Error Type (No Positioin - 0, Timeout - 1, TimeoutImmediateFix - 2): ";
            char t[10];
            snprintf(t, 10, "%d", mLocationErrorType);
            string errorType (t);
            valueStr += errorType;
        }
    }

protected:

private:
    void makeCopy(const IZatLocationError & locError) {
        mHasErrorType = locError.mHasErrorType;
        mLocationErrorType = locError.mLocationErrorType;
    }
};

}// namespace izat_manager

#endif // #ifndef __IZAT_MANAGER_LOCATIONERROR_H__
