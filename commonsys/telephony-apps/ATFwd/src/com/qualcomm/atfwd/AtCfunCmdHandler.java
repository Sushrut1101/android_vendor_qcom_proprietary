/*******************************************************************************
    Copyright (c) 2010,2011 Qualcomm Technologies, Inc.  All Rights Reserved.
    Qualcomm Technologies Proprietary and Confidential.
*******************************************************************************/

package com.qualcomm.atfwd;

import android.content.Context;
import android.os.PowerManager;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.os.HandlerThread;
import android.util.Log;

/**
 * @author jaimel
 *
 */
public class AtCfunCmdHandler extends AtCmdBaseHandler implements AtCmdHandler {

    private static final String TAG = "AtCfunCmdHandler";
    private Context mContext;

    public AtCfunCmdHandler(Context c) throws AtCmdHandlerInstantiationException
    {
        super(c);
        mContext = c;
    }

    @Override
    public String getCommandName() {
        return "+CFUN";
    }

    @Override
    public AtCmdResponse handleCommand(AtCmd cmd) {
        AtCmdResponse ret = null;
        Thread rebootThread;
        String tokens[] = cmd.getTokens();

        if (tokens.length != 2 || !tokens[0].equals("1") || !tokens[1].equals("1")) {
            /* We currently support +CFUN=1,1 only. other values have to be
             * handled elsewhere.
             */
            Log.e(TAG, "+CFUN: Only +CFUN=1,1 supported");
            ret = new AtCmdResponse(AtCmdResponse.RESULT_ERROR, "+CME ERROR: 1");
        } else {
            rebootThread = new Thread() {
                public void run() {
                    PowerManager pm = (PowerManager) mContext.getSystemService(
                        Context.POWER_SERVICE);
                    pm.reboot(null);
                }
            };
            rebootThread.start();
            ret = new AtCmdResponse(AtCmdResponse.RESULT_OK, null);
        }

        return ret;
    }

}
