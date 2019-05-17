package org.android.opensource.libraryyuv;

public class Libyuv {

    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("yuv");
    }

    public native static void ARGBToNV21(byte[] src_frame,int src_stride,
                                  int width, int height, byte[] yBuffer, byte[] uvBuffer);

    public native static void NV21ToARGB(byte[] yBuffer,int y_stride,
                                         byte[] uvBuffer,int uv_stride,
                                         byte[] dstARGB,int dst_stride_argb,
                                         int width, int height);

    public native static void RGBAToARGB(byte[] srcBuffer,int src_stride_frame,
                                         byte[] dstBuffer, int dst_stride_argb,
                                         int width, int height);


    public native static void I420ToNV21(
            byte[] src_y_Buffer,int src_stride_y,
            byte[] src_u_Buffer,int src_stride_u,
            byte[] src_v_Buffer,int src_stride_v,
            byte[] dst_y_Buffer,int dst_stride_y,
            byte[] dst_uv_Buffer,int dst_stride_uv,
            int width, int height);

    public native static void I420ToARGB(
            byte[] src_y_Buffer,int src_stride_y,
            byte[] src_u_Buffer,int src_stride_u,
            byte[] src_v_Buffer,int src_stride_v,
            byte[] dst_Buffer,int dst_stride,
            int width, int height);

    public native static void I420ToRAW(
            byte[] src_y_Buffer,int src_stride_y,
            byte[] src_u_Buffer,int src_stride_u,
            byte[] src_v_Buffer,int src_stride_v,
            byte[] dst_Buffer,int dst_stride,
            int width, int height);

    public native static void Android420ToI420(
            Object src_y_Buffer,int src_stride_y,
            Object src_u_Buffer,int src_stride_u,
            Object src_v_Buffer,int src_stride_v,
            int pixel_stride_uv,
            byte[] dst_y_Buffer,int dst_stride_y,
            byte[] dst_u_Buffer,int dst_stride_u,
            byte[] dst_v_Buffer,int dst_stride_v,
            int width, int height);
}
