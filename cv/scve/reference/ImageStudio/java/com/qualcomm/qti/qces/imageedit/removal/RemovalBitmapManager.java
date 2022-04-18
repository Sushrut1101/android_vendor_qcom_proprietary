/*
 * Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
package com.qualcomm.qti.qces.imageedit.removal;

import java.io.FileNotFoundException;
import java.io.InputStream;
import java.lang.ref.WeakReference;
import java.util.HashMap;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.net.Uri;
import android.util.Log;

import com.qualcomm.qti.qces.util.ImageUtils;

/**
 * This class manages set of {@link Bitmap}s for segmentation operations. It is a singleton object,
 * and is able to manage multiple image sets simultaneously.
 */
/* package */class RemovalBitmapManager {
    /**
     * This class represents the working set of {@link Bitmap}s. It is the fundamental unit of a
     * {@link RemovalBitmapManager}. After the owner is finished with it,
     * {@link BitmapSet#release()} should be invoked.
     */
    public class BitmapSet {
        public final int width;
        public final int height;
        public final Bitmap source;
        public final Bitmap mask;

        private int refCount = 1;

        private BitmapSet(Bitmap source) {
            width = source.getWidth();
            height = source.getHeight();
            this.source = source;
            mask = Bitmap.createBitmap(width, height, Config.ARGB_8888);

        }

        private void acquire() {
            if (refCount <= 0) {
                throw new RuntimeException("Cannot acquire a fully released BitmapSet");
            }

            ++refCount;
        }

        /**
         * The owner of this {@link BitmapSet} should call {@link #release()} when it is no longer
         * in use. When all owners have {@link #release()}'d the {@link BitmapSet}, the
         * {@link Bitmap}s will be recycled and the {@link BitmapSet} destroyed.
         */
        public void release() {
            if (refCount <= 0) {
                throw new RuntimeException("Release called more times than expected");
            }

            if (--refCount == 0) {
                source.recycle();
                mask.recycle();
            }

            synchronized (RemovalBitmapManager.this) {
                bitmapSets.values().remove(this);
            }
        }
    }

    private static final String TAG = RemovalBitmapManager.class.getSimpleName();

    private static WeakReference<RemovalBitmapManager> instance;

    private final Context context;
    private final HashMap<Uri, BitmapSet> bitmapSets = new HashMap<Uri, BitmapSet>();

    private RemovalBitmapManager(Context context) {
        if (context == null) {
            throw new IllegalArgumentException("context cannot be null");
        }

        this.context = context;
    }

    /**
     * Get the singleton {@link RemovalBitmapManager} instance
     * @param context the application {@link Context}
     * @return the singleton {@link RemovalBitmapManager} instance
     */
    public static RemovalBitmapManager getInstance(Context context) {
        RemovalBitmapManager localRef = null;

        if (instance != null) {
            localRef = instance.get();
        }

        if (localRef == null) {
            localRef = new RemovalBitmapManager(context);
            instance = new WeakReference<RemovalBitmapManager>(localRef);
        }

        return localRef;
    }

    /**
     * Acquire a {@link BitmapSet} for the specified {@link Uri}. If the {@link BitmapSet} already
     * exists, it will be reused. Otherwise, the {@link Bitmap} for the given {@link Uri} will be
     * loaded and a new {@link BitmapSet} object created.
     * @param uri A {@link Uri} describing a {@link Bitmap} to load. The {@link Bitmap} will be
     *        loaded on the calling thread.
     * @return a {@link BitmapSet} corresponding to the provided {@link Uri}, or null if a
     *         {@link BitmapSet} could not be created for the provided {@link Uri}
     * @throws IllegalArgumentException if uri is null
     */
    public synchronized BitmapSet acquire(Uri uri, Boolean isFullMP) {
        if (uri == null) {
            throw new IllegalArgumentException("uri cannot be null");
        }

        BitmapSet set = bitmapSets.get(uri);
        if (set != null) {
            set.acquire();
            return set;
        }

        InputStream input;
        try {
            input = context.getContentResolver().openInputStream(uri);
        } catch (FileNotFoundException e) {
            Log.e(TAG, "Uri [" + uri + "] not resolvable");
            return null;
        }

        Bitmap b = ImageUtils.loadImage(context, uri, input, isFullMP);
        if (b == null) {
            Log.e(TAG, "Failed to decode bitmap from [" + uri + "]");
            return null;
        }

        set = new BitmapSet(b); // Implicitly acquire()'s the BitmapSet
        bitmapSets.put(uri, set);
        return set;
    }
}
