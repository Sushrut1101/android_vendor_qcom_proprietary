/*******************************************************************************
    Copyright (c) 2010,2011 Qualcomm Technologies, Inc.  All Rights Reserved.
    Qualcomm Technologies Proprietary and Confidential.
*******************************************************************************/

package com.qualcomm.atfwd;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Vector;

import javax.net.ssl.HandshakeCompletedListener;

import android.app.Service;
import android.app.Instrumentation;
import android.content.ComponentName;
import android.content.Context;
import android.content.ServiceConnection;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.IBinder;
import android.os.Message;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.os.SystemClock;
import android.os.SystemService;
import android.util.Log;
import android.view.KeyCharacterMap;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.hardware.input.InputManager;
import android.view.InputDevice;

public class AtCtsaCmdHandler extends AtCmdBaseHandler {

    private static final String LOG_TAG = "AtCtsaCmdHandler";

    private static final int EVT_CTSA_CMD = 0;

    // Default times (in milliseconds)
    private static final int DEFAULT_PRESS_TIME = 200;
    private static final int DEFAULT_PAUSE_TIME = 400;
    private static final int MOVE_UP_PAUSE_TIME = 100;
    private static final int MOVE_MOVE_PAUSE_TIME = 50;


    private LinkedList<ParsedCtsaCmd> mEventQ;
    private HandlerThread mInjectThread;
    private Handler mInjectHandler;
    private int mDepressX, mDepressY;
    private boolean mDepressFlag = false;
    private Instrumentation mInstrumentation;


    private class ParsedCtsaCmd {
        private static final int CTSA_ACTION_RELEASE = 0;
        private static final int CTSA_ACTION_DEPRESS = 1;
        private static final int CTSA_ACTION_TAP = 2;
        private static final int CTSA_ACTION_DBL_TAP = 3;
        // Not in TS 27.007 (Android-specific)
        private static final int CTSA_ACTION_LNG_TAP = 4; // Long press

        private static final long PRESS_TIME = 200;
        private static final long LNG_PRESS_TIME = 1500;
        private AtCmd mOriginalCommand;

        private Vector<Object> mEvents;

        public ParsedCtsaCmd(AtCmd cmd) throws AtCmdParseException {
            mOriginalCommand = cmd;
            mEvents = new Vector<Object>();
            parse_cmd();
        }

        public AtCmd getOriginalCommand() {
            return mOriginalCommand;
        }

        private void parse_cmd() throws AtCmdParseException {
            int ctsaAction = -1;
            long time = SystemClock.uptimeMillis();
            String tokens[] = mOriginalCommand.getTokens();
            float x, y;
            long presstime = PRESS_TIME;
            MotionEvent evt;
            int releaseX, releaseY;
            float middleFloatX, middleFloatY;

            // Must have at least one token, and at most 3
            // AT+CTSA=<action>,<x>,<y>
            // action can be:
            //    0: release
            //    1: Depress
            //    2: Tap
            //    3: Double tap
            if (tokens == null || tokens.length != 3)
                throw new AtCmdParseException("Must provide three tokens");

            try {
                ctsaAction = Integer.parseInt(tokens[0]);

                x = Float.parseFloat(tokens[1]);
                y = Float.parseFloat(tokens[2]);

                switch (ctsaAction) {
                case CTSA_ACTION_RELEASE:
                   if ( mDepressFlag == true ) {
                        releaseX = Integer.parseInt(tokens[1]);
                        releaseY = Integer.parseInt(tokens[2]);
                        middleFloatX = (float)( releaseX - ( releaseX - mDepressX )/2 );
                        middleFloatY = (float)( releaseY - ( releaseY - mDepressY )/2 );
                        evt = MotionEvent.obtain(time, time,
                                MotionEvent.ACTION_MOVE, middleFloatX, middleFloatY, 0);
                        mEvents.add(evt);
                        mEvents.add(new PauseEvent(MOVE_MOVE_PAUSE_TIME));
                        time = SystemClock.uptimeMillis();
                        mDepressFlag = false;

                        evt = MotionEvent.obtain(time, time,
                                MotionEvent.ACTION_MOVE, x, y, 0);
                        mEvents.add(evt);
                        mEvents.add(new PauseEvent(MOVE_UP_PAUSE_TIME));
                        time = SystemClock.uptimeMillis();
                     }

                    evt = MotionEvent.obtain(time, time,
                            MotionEvent.ACTION_UP, x, y, 0);
                    mEvents.add(evt);
                    break;
                case CTSA_ACTION_DEPRESS:
                    mDepressX = Integer.parseInt(tokens[1]);
                    mDepressY = Integer.parseInt(tokens[2]);
                    mDepressFlag = true;

                    evt = MotionEvent.obtain(time, time,
                            MotionEvent.ACTION_DOWN, x, y, 0);
                    mEvents.add(evt);
                    break;
                case CTSA_ACTION_LNG_TAP:
                    presstime = LNG_PRESS_TIME;
                    // Fall-through
                case CTSA_ACTION_TAP:
                    addClick(x, y, presstime);
                    mDepressFlag = false;
                    break;
                case CTSA_ACTION_DBL_TAP:
                    // First tap
                    addClick(x, y, presstime);
                    // Second tap
                    addClick(x, y, presstime);
                    mDepressFlag = false;
                    break;
                }

            } catch (NumberFormatException e) {
                throw new AtCmdParseException(e);
            }
        }

        private void addClick(float x, float y, long presstime) {
            MotionEvent evt;

            evt = MotionEvent.obtain(0, 0,
                    MotionEvent.ACTION_DOWN, x, y, 0);
            mEvents.add(evt);

            mEvents.add(new PauseEvent(presstime));

            evt = MotionEvent.obtain(evt);
            evt.setAction(MotionEvent.ACTION_UP);
            mEvents.add(evt);
        }

        public Vector<Object>getEvents() {
            return mEvents;
        }
    }
    public AtCtsaCmdHandler(Context c) throws AtCmdHandlerInstantiationException {
        super(c);
        mEventQ = new LinkedList<ParsedCtsaCmd>();
        mInstrumentation = new Instrumentation();

        mInjectThread = new HandlerThread("CTSA Inject Thread",
                android.os.Process.THREAD_PRIORITY_URGENT_DISPLAY) {
        };
        mInjectThread.start();
        mInjectHandler = new Handler(mInjectThread.getLooper()) {
            public void handleMessage(Message msg) {
                switch(msg.what) {
                case EVT_CTSA_CMD:
                    ParsedCtsaCmd cmd = (ParsedCtsaCmd) msg.obj;
                    Log.d(LOG_TAG, "Command de-queued: " + cmd);
                    if (cmd == null) return;

                    for (Object obj : cmd.getEvents()) {
                        if (obj instanceof PauseEvent) {
                            PauseEvent evt = (PauseEvent) obj;
                            try {
                                Thread.sleep(evt.getTime());
                                continue;
                            } catch (InterruptedException e) {
                                Log.d(LOG_TAG, "PauseEvent interrupted", e);
                            }
                        }

                        if (!(obj instanceof MotionEvent)) {
                            Log.d(LOG_TAG, "Ignoring unkown event of type " + obj.getClass().getName());
                            continue;
                        }

                        // Touch Event
                        long time = SystemClock.uptimeMillis();

                        MotionEvent oev = (MotionEvent) obj;
                        MotionEvent ev = MotionEvent.obtain(time,
                                time,
                                oev.getAction(),
                                oev.getX(), oev.getY(),
                                oev.getMetaState());
                        oev.recycle();
                        injectPointerEvent(ev , false);
                        // TODO: Add callbacks to provide support for unsolicited TS codes
                    }
                }
            }
        };
    }

    public AtCmdResponse handleCommand(AtCmd cmd) {
        ParsedCtsaCmd valid = null;
        boolean dead = false;
        String result = null;
        boolean isAtCmdRespOK = false;

        Log.d(LOG_TAG, "handleCommand: " + cmd);
        Log.d(LOG_TAG, "OpCode: " + cmd.getOpcode());

        switch (cmd.getOpcode()) {
            case AtCmd.ATCMD_OPCODE_NA_EQ_QU:
                // AT+CTSA=?
                // We support all five actions.
                isAtCmdRespOK = true;
                result = getCommandName() + ": (0-4)";
                break;

            case AtCmd.ATCMD_OPCODE_NA_EQ_AR:
                // AT+CTSA=<action>,<x>,<y>
                dead = !mInjectThread.isAlive();
                if (!dead) {
                    // According to TS 27.007 8.7:
                    // "This command should be accepted (OK returned) before
                    // "actually emulating the touch screen action
                    // Thus we validate first before queuing for execution
                    try {
                        valid = new ParsedCtsaCmd(cmd);
                        isAtCmdRespOK = true;
                        Log.d(LOG_TAG, "Queuing command");
                        Message.obtain(mInjectHandler, EVT_CTSA_CMD, valid).sendToTarget();
                        Log.d(LOG_TAG, "Command queued");
                    } catch (AtCmdParseException e) {
                        Log.d(LOG_TAG, "Error parsing command " + cmd);
                        result = cmd.getAtCmdErrStr(AtCmd.AT_ERR_INVALID_CHARS);
                    }
                } else {
                    result = cmd.getAtCmdErrStr(AtCmd.AT_ERR_NO_CONN_TO_PHONE);
                }
                break;

            default:
                // CTSA supports only control command and test command
                Log.d(LOG_TAG, "CTSA OpCode Error");
                result = cmd.getAtCmdErrStr(AtCmd.AT_ERR_OP_NOT_SUPP);
                break;
        }

        return isAtCmdRespOK ? new AtCmdResponse(AtCmdResponse.RESULT_OK, result) :
            new AtCmdResponse(AtCmdResponse.RESULT_ERROR, result);
    }

    public String getCommandName() {
        return "+CTSA";
    }

    /**
     * Inject a pointer (touch) event into the UI.
     * Even when sync is false, this method may block while waiting for current
     * input events to be dispatched.
     */
    private void injectPointerEvent(MotionEvent event, boolean sync) {
        event.setSource(InputDevice.SOURCE_TOUCHSCREEN);
        Log.i("Input", "InjectPointerEvent: " + event);
        //Using a synchronous API should be fine because it'll be invoked from a separate
        //thread(mInjectThread).
        mInstrumentation.sendPointerSync(event);
    }
}
