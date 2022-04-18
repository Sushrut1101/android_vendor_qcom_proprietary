/*
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc. 
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Not a Contribution.
 * Apache license notifications and license are retained
 * for attribution purposes only.
 */
/*
 * Copyright (C) 2011, The Android Open Source Project
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
/*
 * Contributed by: Giesecke & Devrient GmbH.
 */

package org.simalliance.openmobileapi.service;

import android.content.Context;
import android.content.pm.PackageInfo;

import java.lang.reflect.Method;
import java.util.LinkedList;
import java.util.List;

public class AddonTerminal extends Terminal {

    private Object mInstance = null;

    private Method mIsCardPresent = null;

    private Method mInternalConnect = null;

    private Method mInternalDisconnect = null;

    private Method mInternalTransmit = null;

    private Method mInternalOpenLogicalChannel = null;

    private Method mInternalOpenLogicalChannelAID = null;

    private Method mInternalCloseLogicalChannel = null;

    private Method mGetName = null;

    private Method mGetAtr = null;

    private Method mGetSelectResponse = null;

    private Method mInternalOpenBasicChannel = null;

    private Method mInternalOpenBasicChannelAID = null;

    private Method mSetsHandle = null;

    private Method mGetsHandle = null;

    private Method mInternalOpenSession = null;

    private Method mInternalGetSelectResponse = null;

    private Method mInternalCloseSession = null;

    public static String[] getPackageNames(Context context) {
        List<String> packageNameList = new LinkedList<String>();
        List<PackageInfo> pis = context.getPackageManager().getInstalledPackages(0);
        for (PackageInfo p : pis) {
            if (p.packageName.startsWith("org.simalliance.openmobileapi.service.terminals.")
                    || p.packageName.startsWith("org.simalliance.openmobileapi.cts")) {
                packageNameList.add(p.packageName);
            }
        }
        String[] rstrings = new String[packageNameList.size()];
        packageNameList.toArray(rstrings);
        return rstrings;
    }

    public AddonTerminal(Context context, String packageName, String className) {
        super("Addon", context);

        try {
            Context ctx = context.createPackageContext(packageName, Context.CONTEXT_IGNORE_SECURITY
                    | Context.CONTEXT_INCLUDE_CODE);
            ClassLoader cl = ctx.getClassLoader();
            Class<?> cls = cl.loadClass(className);
            mInstance = cls.getConstructor(new Class[] {
                Context.class
            }).newInstance(new Object[] {
                context
            });
            if (mInstance != null) {
                mGetAtr = mInstance.getClass().getDeclaredMethod("getAtr", (Class<?>[]) null);
                mGetName = mInstance.getClass().getDeclaredMethod("getName", (Class<?>[]) null);
                mIsCardPresent = mInstance.getClass().getDeclaredMethod("isCardPresent",
                        (Class<?>[]) null);
                mInternalConnect = mInstance.getClass().getDeclaredMethod("internalConnect",
                        (Class<?>[]) null);
                mInternalDisconnect = mInstance.getClass().getDeclaredMethod("internalDisconnect",
                        (Class<?>[]) null);
                mInternalTransmit = mInstance.getClass().getDeclaredMethod("internalTransmit",
                        new Class[] {
                            byte[].class
                        });
                mInternalOpenLogicalChannel = mInstance.getClass().getDeclaredMethod(
                        "internalOpenLogicalChannel", (Class<?>[]) null);
                mInternalOpenLogicalChannelAID = mInstance.getClass().getDeclaredMethod(
                        "internalOpenLogicalChannel", new Class[] {
                            byte[].class, byte.class
                        });
                mInternalCloseLogicalChannel = mInstance.getClass().getDeclaredMethod(
                        "internalCloseLogicalChannel", new Class[] {
                            int.class
                        });
                mGetSelectResponse = mInstance.getClass().getDeclaredMethod("getSelectResponse",
                        (Class<?>[]) null);
                mGetsHandle = mInstance.getClass().getDeclaredMethod("getsHandle", (Class<?>[]) null);
                mSetsHandle= mInstance.getClass().getDeclaredMethod("setsHandle", new Class[] {
                            int.class
                        });
                mInternalOpenSession = mInstance.getClass().getDeclaredMethod("internalOpenSession",(Class<?>[]) null);
                mInternalCloseSession = mInstance.getClass().getDeclaredMethod("internalCloseSession", new Class[] {
                            int.class
                        });
                mInternalOpenBasicChannel = mInstance.getClass().getDeclaredMethod(
                        "internalOpenBasicChannel", (Class<?>[]) null);
                mInternalOpenBasicChannelAID = mInstance.getClass().getDeclaredMethod(
                        "internalOpenBasiclChannel", new Class[] {
                            byte[].class
                        });
                mInternalGetSelectResponse= mInstance.getClass().getDeclaredMethod("internalGetSelectResponse",
                        (Class<?>[]) null);
            }
        } catch (Exception e) {
            throw new IllegalStateException("plugin internal error: " + e);
        }
    }

    /**
     * Returns the ATR of the connected card or null if the ATR is not
     * available.
     *
     * @return the ATR of the connected card or null if the ATR is not
     *         available.
     */
    public byte[] getAtr() {
        if (mGetAtr == null) {
            throw new IllegalStateException("plugin error: Function String getAtr() not found");
        }
        try {
            byte[] resp = (byte[]) mGetAtr.invoke(mInstance, (Object[]) null);
            return resp;
        } catch (Exception e) {
            throw new IllegalStateException("plugin internal error: getAtr() execution: "
                    + e.getCause());
        }
    }

    public String getName() {
        if (mGetName == null) {
            throw new IllegalStateException("plugin error: Function String getName() not found");
        }
        try {
            String s = (String) mGetName.invoke(mInstance, (Object[]) null);
            return s;
        } catch (Exception e) {
            throw new IllegalStateException("plugin internal error: getName() execution: "
                    + e.getCause());
        }
    }

    public boolean isCardPresent() throws CardException {
        if (mIsCardPresent == null) {
            throw new IllegalStateException(
                    "plugin error: Function String isCardPresent() not found");
        }
        try {
            Boolean v = (Boolean) mIsCardPresent.invoke(mInstance, (Object[]) null);
            return v.booleanValue();
        } catch (Exception e) {
            throw new CardException("plugin internal error: isCardPresent() execution: "
                    + e.getCause());
        }
    }

    protected void internalConnect() throws CardException {
        if (mInternalConnect == null) {
            throw new IllegalStateException(
                    "plugin error: Function String internalConnect() not found");
        }
        try {
            mInternalConnect.invoke(mInstance, (Object[]) null);
            mIsConnected = true;
        } catch (Exception e) {
            throw new CardException("plugin internal error: internalConnect() execution: "
                    + e.getCause());
        }
    }

    protected void internalDisconnect() throws CardException {
        if (mInternalDisconnect == null) {
            throw new IllegalStateException(
                    "plugin error: Function String internalDisconnect() not found");
        }
        try {
            mInternalDisconnect.invoke(mInstance, (Object[]) null);
            mIsConnected = false;
        } catch (Exception e) {
            throw new CardException("plugin internal error: internalDisconnect() execution");
        }
    }

    protected byte[] internalTransmit(byte[] command) throws CardException {
        if (mInternalTransmit == null) {
            throw new IllegalStateException(
                    "plugin error: Function String internalTransmit() not found");
        }
        try {
            byte[] resp = (byte[]) mInternalTransmit.invoke(mInstance, new Object[] {
                command
            });
            return resp;
        } catch (Exception e) {
            throw new CardException("plugin internal error: internalTransmit() execution: "
                    + e.getCause());
        }
    }

    protected int internalOpenLogicalChannel() throws Exception {
        if (mInternalOpenLogicalChannel == null) {
            throw new IllegalStateException(
                    "plugin error: Function String internalOpenLogicalChannel() not found");
        }
        try {
            Integer channel = (Integer) mInternalOpenLogicalChannel.invoke(mInstance,
                    (Object[]) null);
            return channel.intValue();
        } catch (Exception e) {
            throw (Exception) e.getCause();
        }
    }

    protected int internalOpenLogicalChannel(byte[] aid, byte p2) throws CardException {
        if (mInternalOpenLogicalChannelAID == null) {
            throw new IllegalStateException(
                    "plugin error: Function internalOpenLogicalChannelAID() not found");
        }
        try {
            Integer channel = (Integer) mInternalOpenLogicalChannelAID.invoke(mInstance,
                    new Object[] {
                        aid, p2
                    });
            mSelectResponse = (byte[]) mGetSelectResponse.invoke(mInstance, (Object[]) null);
            return channel.intValue();
        } catch (Exception e) {
            throw new CardException(
                    "plugin internal error: internalOpenLogicalChannel() execution: "
                            + e.getCause());
        }
    }

    protected void internalCloseLogicalChannel(int channelNumber) throws CardException {
        if (mInternalCloseLogicalChannel == null) {
            throw new IllegalStateException(
                    "plugin error: Function internalCloseLogicalChannel not found");
        }
        try {
            mInternalCloseLogicalChannel.invoke(mInstance, new Object[] {
                channelNumber
            });
        } catch (Exception e) {
            throw new CardException(
                    "plugin internal error: internalOpenLogicalChannel() execution: "
                            + e.getCause());
        }
    }

    public int getsHandle() {
        if (mGetsHandle == null) {
            throw new IllegalStateException("plugin error: Function String getsHandle() not found");
        }
        try {
            int sHandle = (int) mGetsHandle.invoke(mInstance, (Object[]) null);
            return sHandle;
        } catch (Exception e) {
            throw new IllegalStateException("plugin internal error: getsHandle() execution: "
                    + e.getCause());
        }
    }

        public void setsHandle(int sessionHandle) {
        if (mSetsHandle == null) {
            throw new IllegalStateException("plugin error: Function String mSetsHandle() not found");
        }
        try {
            mSetsHandle.invoke(mInstance, new Object[] {
                sessionHandle
            });
        } catch (Exception e) {
            throw new IllegalStateException("plugin internal error: getcHandle() execution: "
                    + e.getCause());
        }
    }

    public void internalCloseSession(int sessionHandle){
        if (mInternalCloseSession == null) {
            throw new IllegalStateException("plugin error: Function String InternalCloseSession() not found");
        }
        try {
            mInternalCloseSession.invoke(mInstance, new Object[] {
                sessionHandle
            });
        } catch (Exception e) {
            throw new IllegalStateException("plugin internal error: getcHandle() execution: "
                    + e.getCause());
        }
    }

    public void internalOpenSession(){
        if (mInternalOpenSession == null) {
            throw new IllegalStateException("plugin error: Function String InternalOpenSession() not found");
        }
        try {
            mInternalCloseSession.invoke(mInstance, (Object[]) null);
        } catch (Exception e) {
            throw new IllegalStateException("plugin internal error: getcHandle() execution: "
                    + e.getCause());
        }
    }

    protected void internalOpenBasicChannel() throws Exception {
        if (mInternalOpenBasicChannel == null) {
            throw new IllegalStateException(
                    "plugin error: Function String internalOpenLogicalChannel() not found");
        }
        try {
            Integer channel = (Integer) mInternalOpenBasicChannel.invoke(mInstance,
                    (Object[]) null);

        } catch (Exception e) {
            throw (Exception) e.getCause();
        }
    }

    protected void internalOpenBasicChannel(byte[] aid) throws Exception {
        if (mInternalOpenBasicChannelAID == null) {
            throw new IllegalStateException(
                    "plugin error: Function internalOpenBasicChannel() not found");
        }
        try {
            Integer channel = (Integer) mInternalOpenBasicChannel.invoke(mInstance,
                    new Object[] {
                        aid
                    });
            mSelectResponse = (byte[]) mInternalOpenBasicChannel.invoke(mInstance, (Object[]) null);

        } catch (Exception e) {
            throw (Exception) e.getCause();
        }
    }

    @Override
    protected byte[] internalGetSelectResponse() throws Exception {
        if (mInternalGetSelectResponse == null) {
            throw new IllegalStateException(
                    "plugin error: Function internalCloseLogicalChannel not found");
        }
        try {
            byte[] resp = (byte[]) mInternalGetSelectResponse.invoke(mInstance,
                    (Object[]) null);

                return resp;

        } catch (Exception e) {
            throw new CardException(
                    "plugin internal error: internalOpenLogicalChannel() execution: "
                            + e.getCause());
        }
    }
}
