#ifndef _CNE_FACTORY_H_
#define _CNE_FACTORY_H_
 /*
 * @file CneFactory.h
 *
 * @brief
 * Connectivity Engine Observer Interface Header File
 *
 * This file contains the definitions of constants, data structures and
 * interfaces for the Connectivity Engine Observer Interface
 *
 * Users should use Connectivity Engine Observer Interface to get access to
 * Connectivity Engine Network, Battery and Feature Observer
 *
 *                   Copyright (c) 2010-2012,2015-2016,2018 Qualcomm Technologies, Inc.
 *                   All Rights Reserved.
 *                   Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

/**
 * @mainpage Connectivity Engine Observer Interface
 *
 * @section S1 Introduction
 * Connectivity Engine Observer provides contextual information regarding
 * network characteritics, battery status, feature status to the client. In order to
 * obtain this information, the client needs to create appropriate context
 * using the \c CneFactory. Network context information is available via \c
 * ICneNetworkObserver , battery context information is available via
 * \c ICneBatteryObserver  and feature status is available via \c ICneFeatureObserver.
 * The client can also register with
 * appropriate signal handler at time of creation of such an observer, if it
 * is interested in receiving asynchronous notifications of certain changes in
 * these contexts. The signal handlers need to be implemented by the client
 * and are available as \c ICneNetworkObserverNotifier , \c
 * ICneBatteryObserverNotifier & \c ICneFeatureObserverNotifier abstract classes.
 *
 * @section S2 Connectivity Engine Network Observer
 * Connectivity Engine Network Observer allows user to query for network
 * characteristics such as: <ul> <li> Active Network Configuration <li> Active
 * Active Network Dormancy characteristics <li> Active Network Bitrate Estimate
 * <li> Latency Estimate for a network or towards a destination </ul> It is
 * created by calling \c CneFactory::CreateCneNetworkObserver. During creation
 * of \c ICneNetworkObserver a client may pass an instance pointer of the form
 * \c ICneNetworkObserverNotifier. If the notifier is null, then the user will
 * not be notified asynchronously of any changes to any network
 * characterisctics. Once it is no longer needed, the client shall perform
 * appropriate clean up by calling
 * \c CneFactory::DestroyCneNetworkObserver.
 *
 * @subsection SS21 Connectivity Engine Network Observer Notifier
 * Connectivity Engine Network Observer Notifier is an abstract class that the
 * client should extend from and implement individual signal handlers. Signals
 * are available via \c ICneNetworkObserver for: <ul> <li> Network Configuration
 * Changes <li> Network Dormancy Changes <li> Network Bitrate Measurements
 * <li> Network Latency Measurements </ul> An instance of this class needs to be
 * passed while creation of \c ICneNetworkObserver if the client wishes to
 * receive asynchronous signals. If it is not passed then the client will not
 * receive any signals. The client needs to ensure proper clean up of this
 * notifier class if is no longer needed.
 *
 * @section S3 Connectivity Engine Battery Observer
 * Connectivity Engine Battery Observer allows user to querry for battery
 * charging status. It is created by calling
 * \c CneFactory::CreateCneBatteryObserver. During creation of
 * \c ICneBatteryObserver a client may pass an instance pointer of the form
 * \c ICneBatteryObserverNotifier. If the notifier is null, then the user will
 * not be notified asynchronously of any battery charging status changes. Once
 * it is no longer needed, the user shall perform appropriate cleanup by
 * calling \c CneFactory::DestroyCneBatteryObserver.
 *
 * @subsection SS31 Connectivity Engine Battery Observer Notifier
 * Connectivity Engine Battery Observer Notifier is an abstract class that the
 * client should extend from and implement individual signal handlers. Signals
 * are available via \c ICneBatteryObserver for battery charging status
 * changes. An instance of this class needs to be passed while creation of
 * \c ICneBatteryObserver. If it is not passed, then the client will not
 * receive any signals. The client needs to ensure proper cleanup of this
 * notifier class when it is no longer needed.
 *
 * @section S4 Connectivity Engine Feature Observer
 * Connectivity Engine Feature Observer allows user to query for
 * states of specific features:
 * <ul>
 * <li> Wifi Quality Estimation (WQE) state: inactive or active
 * <li> Interworking WLAN (IWLAN) user preference: unknown, inactive or active
 *</ul>
 * It is created by calling
 * \c CneFactory::CreateCneFeatureObserver. During creation of
 * \c ICneFeatureObserver a client may pass an instance pointer of the form
 * \c ICneFeatureObserverNotifier. If the notifier is null, then the user will
 * not be notified asynchronously of feature status changes. Once
 * it is no longer needed, the user shall perform appropriate cleanup by
 * calling \c CneFactory::DestroyCneFeatureObserver.
 *
 * @subsection SS41 Connectivity Engine Feature Observer Notifier
 * Connectivity Engine Feature Observer Notifier is an abstract class that the
 * client should extend from and implement individual signal handlers. Signals
 * are available via \c ICneFeatureObserver for feature status
 * changes. An instance of this class needs to be passed while creation of
 * \c ICneFeatureObserver. If it is not passed, then the client will not
 * receive any signals. The client needs to ensure proper cleanup of this
 * notifier class when it is no longer needed.
 *
 * @subsection S5 Certificate Request
 * Certificate Request allows user to query for CA Certificates matching a
 * specified DN. It is created by calling
 * \c CneFactory::CreateCertificateRequest.
 *
 * @subsection SS51 Certificate Callback
 * Certificate Callback is an abstract class that the client should extend
 * from and implement the callback method. The callback will be invoked
 * asynchronously once a requested certificate is ready. The client needs to
 * ensure proper cleanup of this Callback when it is no longer needed. The
 * transactionId will be passed in the Callback to identify the associated
 * Certificate Request. A single Callback may be used for multiple Certificate
 * Requests and for multiple queries.

 *
 * @defgroup coi_api Connectivity Engine Observer Factory Interface
 * This section explains APIs provided by Connectivity Engine Observer Factory
 * Interface. Detailed description is provided below.
 *
 * @defgroup coi_ds Connectivity Engine Observer Data Types
 * This section defines the various enumerated constants and data structers used
 * by \c ICneFactory \c ICneNetworkObserver \c ICneBatteryObserver and
 * \c ICneFeatureObserver
 *
 * @defgroup cbo_api Connectivity Engine Battery Observer APIs
 * This section explains APIs provided by Connectivity Engine Battery
 * Observer. Detailed description is provided below.
 *
 * @defgroup cbo_ds Connectivity Engine Battery Observer Data Types
 * This section defines the various enumerated constants and data structures
 * used by \c ICneBatteryObserver.
 *
 * @defgroup cno_api Connectivity Engine Network Observer APIs
 * This section explains APIs provided by Connectivity Engine Network
 * Observer. Detailed description is provided below.
 *
 * @defgroup cno_ds Connectivity Engine Network Observer Data Types
 * This section defines the various enumerated constants and data structures
 * used by \c ICneNetworkObserver.
 *
 * @defgroup cfo_api Connectivity Engine Feature Observer APIs
 * This section explains APIs provided by Connectivity Engine Network
 * Observer. Detailed description is provided below.
 *
 * @defgroup cfo_ds Connectivity Engine Feature Observer Data Types
 * This section defines the various enumerated constants and data structures
 * used by \c ICneFeatureObserver.
 *
 * @defgroup cr_api Certificate Request APIs
 * This section explains APIs provided by Connectivity Engine Certificate
 * Request. Detailed description is provided below.
 *
 * @defgroup cr_ds Connectivity Engine Certificate Request Data Types
 * This section defines the various enumerated constants and data structures
 * used by \c ICertificateRequest.

 */

#include "ICneNetworkObserver.h"
#include "ICneNetworkObserverNotifier.h"
#include "ICneFeatureObserver.h"
#include "ICneFeatureObserverNotifier.h"
#include "ICneNetworkRequest.h"
#include "ICertificateCallback.h"
#include "ICertificateRequest.h"

#include <memory>

/**
 * @brief
 * The Connectivity Engine Observer factory. The user of this class shall use
 * it to create and destroy \c ICneNetworkObserver \c ICneBatteryObserver
 * \c ICneFeatureObserver and \c ICertificateRequest interface.
 */
class CneFactory
{
  public:
  /**
   * @ingroup coi_api
   * @{ */
  /**
  @brief
  Creates a Connectivity Engine Network Observer (CNO)

  The user must call all CNO methods on the instance returned by this method.

  @param[in] cnoNotifier An object pointer of class
        \c ICneNetworkObserverNotifier.

  @dependencies
  None

  @return One of the following
          <ul>
            <li> An instance of ICneNetworkObserver
            <li> null if failed
          </ul>

  @sa
  ICneNetworkObserverNotifier, CneFactory::DestroyCneNetworkObserver
  */
  static ICneNetworkObserver* CreateCneNetworkObserver(ICneNetworkObserverNotifier* cnoNotifier);
 /**
   * @ingroup coi_api
   * @{ */
  /**
  @brief
  Creates a Connectivity Engine Network Observer (CNO) for a particular profile
  type.

  The user must call all CNO methods on the instance returned by this method.

  @param[in] cnoNotifier An object pointer of class
        \c ICneNetworkObserverNotifier.
  @param[in] profileTypeName a character string to represent the profile type.
  @dependencies
  None

  @return One of the following
          <ul>
            <li> An instance of ICneNetworkObserver
            <li> null if failed
          </ul>

  @sa
  ICneNetworkObserverNotifier, CneFactory::DestroyCneNetworkObserver
  */
  static ICneNetworkObserver* CreateCneNetworkObserver(
        ICneNetworkObserverNotifier* cnoNotifier,
        const char* profile);
  /**
  @brief
  Destroys the Connectivity Engine Network Observer (CNO)

  Performs appropriate clean up and destroys the CNO. The client must call this
  method once no longer needs the Connectivity Engine Network Observer service.

  @param[in] cno An object pointer of class \c ICneNetworkObserver

  @dependencies
  ICneNetworkObserver must be created.

  @return One of the following codes
          <ul>
            <li> 0 on success
            <li> -1 if failed to clean up
          </ul>

  @sa
  CneFactory::CreateCneNetworkObserver
  */
  static int DestroyCneNetworkObserver(ICneNetworkObserver* cno);

  /**
  @brief
  Creates a Connectivity Engine Feature Observer (CFO)

  The user must call all CFO methods on the instance returned by this method.

  @param[in] cfoNotifier An object pointer of class
        \c ICneFeatureObserverNotifier

  @dependencies
  None

  @return One of the following:
          <ul>
            <li> An instance of ICneFeatureObserver
            <li> null if failed
          </ul>

  @sa
  ICneFeatureObserverNotifier, CneFactory::DestroyCneFeatureObserver
  */
  static ICneFeatureObserver* CreateCneFeatureObserver(ICneFeatureObserverNotifier* cfoNotifier);

  /**
  @brief
  Destroys the Connectivity Engine Feature Observer (CFO)

  Performs appropriate clean up and destroys the CFO. The client must call this
  method once no longer needs the Connectivity Engine Feature Observer service.

  @param[in] cfo An object pointer of class \c ICneFeatureObserver.

  @dependencies
  None

  @return One of the following codes
          <ul>
            <li> 0 on success
            <li> -1 on failure
          </ul>

  @sa
  CneFactory::CreateCneFeatureObserver
  */
  static int DestroyCneFeatureObserver(ICneFeatureObserver* cfo);

  /**
  @brief
  Creates a Connectivity Engine Network Request (CNR)

  The user must call all CNR methods on the instance returned by this method.

  @param[in] cnoNotifier An object pointer of class
        \c ICneNetworkObserverNotifier.

  @dependencies
  None

  @return One of the following
          <ul>
            <li> An instance of ICneNetworkRequest
            <li> null if failed
          </ul>

  @sa
  ICneNetworkObserverNotifier, CneFactory::DestroyCneNetworkRequest
  */
  static ICneNetworkRequest* CreateCneNetworkRequest(
         CnoNetType network,
         ICneNetworkObserverNotifier* cnoNotifier,
         CnoSimSlotIdxType slotidx = SIM_SLOT_UNSPECIFIED);

  /**
  @brief
  Destroys the Connectivity Engine Network Request (CNR)

  Performs appropriate clean up and destroys the CNR. The client must call this
  method once no longer needs the Connectivity Engine Network Request service.

  @param[in] cno An object pointer of class \c ICneNetworkRequest

  @dependencies
  ICneNetworkObserver must be created.

  @return One of the following codes
          <ul>
            <li> 0 on success
            <li> -1 if failed to clean up
          </ul>

  @sa
  CneFactory::CreateCneNetworkRequest
  */
  static int DestroyCneNetworkRequest(ICneNetworkRequest* cnr);

  /**
  @brief
  Creates a Certificate Request

  The user must call the query method on the instance to initiate the request

  @dependencies
  None

  @return One of the following
          <ul>
            <li>An instance of ICertificateRequest
            <li>nullptr if failed
          </ul>
  */
  static std::unique_ptr<ICertificateRequest> CreateCertificateRequest();

  /**
   * @} End of coi_api
   */

  private:

  /**
  @brief
  Constructor
  */
  CneFactory ();

  /**
  @brief
  Destructor
  */
  ~CneFactory ();

};

#endif /* _CNE_FACTORY_H_ */
