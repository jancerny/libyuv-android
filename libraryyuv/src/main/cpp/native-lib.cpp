//
// Created by DELL on 2018/3/26.
//

#include <jni.h>
#include <string>
#include "libyuv.h"

extern "C" {

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_ARGBToNV21(
        JNIEnv *env, jclass *jcls,
        jbyteArray src_frame, jint src_stride_frame,
        jint width, jint height,
        jbyteArray yBuffer, jbyteArray uvBuffer) {

    uint8_t *srcFrame = (uint8_t *) env->GetByteArrayElements(src_frame, 0);

    uint8_t *dst_y = (uint8_t *) env->GetByteArrayElements(yBuffer, 0);
    uint8_t *dst_uv = (uint8_t *) env->GetByteArrayElements(uvBuffer, 0);


    libyuv::ARGBToNV21(srcFrame, src_stride_frame,
                       dst_y, width,
                       dst_uv, width, width, height);

    //remember release
    env->ReleaseByteArrayElements(src_frame, (jbyte *) srcFrame, 0);
    env->ReleaseByteArrayElements(yBuffer, (jbyte *) dst_y, 0);
    env->ReleaseByteArrayElements(uvBuffer, (jbyte *) dst_uv, 0);
}

JNIEXPORT void
JNICALL
Java_org_android_opensource_libraryyuv_Libyuv_NV21ToARGB(
        JNIEnv *env, jclass *jcls,
        jbyteArray yBuffer, jint y_stride,
        jbyteArray uvBuffer, jint uv_stride,
        jbyteArray dstARGB, jint dst_stride_argb,
        jint width, jint height) {

    uint8_t *src_y = (uint8_t *) env->GetByteArrayElements(yBuffer, 0);
    uint8_t *src_uv = (uint8_t *) env->GetByteArrayElements(uvBuffer, 0);
    uint8_t *dst_argb = (uint8_t *) env->GetByteArrayElements(dstARGB, 0);

    libyuv::NV21ToARGB(src_y, y_stride, src_uv, uv_stride, dst_argb, dst_stride_argb, width,
                       height);

    //remember release
    env->ReleaseByteArrayElements(dstARGB, (jbyte *) dst_argb, 0);
    env->ReleaseByteArrayElements(yBuffer, (jbyte *) src_y, 0);
    env->ReleaseByteArrayElements(uvBuffer, (jbyte *) src_uv, 0);

}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_RGBAToARGB(
        JNIEnv *env, jclass *jcls,
        jbyteArray srcBuffer, jint src_stride_frame,
        jbyteArray dstBuffer, jint dst_stride_argb,
        jint width, jint height) {

    uint8_t *src_frame = (uint8_t *) env->GetByteArrayElements(srcBuffer, 0);
    uint8_t *dst_argb = (uint8_t *) env->GetByteArrayElements(dstBuffer, 0);

    libyuv::RGBAToARGB(src_frame, src_stride_frame, dst_argb, dst_stride_argb, width, height);

    //remember release
    env->ReleaseByteArrayElements(srcBuffer, (jbyte *) src_frame, 0);
    env->ReleaseByteArrayElements(dstBuffer, (jbyte *) dst_argb, 0);
}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_I420ToNV21(
        JNIEnv *env, jclass *jcls,
        jbyteArray src_y_Buffer, jint src_stride_y,
        jbyteArray src_u_Buffer, jint src_stride_u,
        jbyteArray src_v_Buffer, jint src_stride_v,
        jbyteArray dst_y_Buffer, jint dst_stride_y,
        jbyteArray dst_vu_Buffer, jint dst_stride_vu,
        jint width, jint height) {

    uint8_t *src_y_frame = (uint8_t *) env->GetByteArrayElements(src_y_Buffer, 0);
    uint8_t *src_u_frame = (uint8_t *) env->GetByteArrayElements(src_u_Buffer, 0);
    uint8_t *src_v_frame = (uint8_t *) env->GetByteArrayElements(src_v_Buffer, 0);
    uint8_t *dst_y_frame = (uint8_t *) env->GetByteArrayElements(dst_y_Buffer, 0);
    uint8_t *dst_vu_frame = (uint8_t *) env->GetByteArrayElements(dst_vu_Buffer, 0);

    libyuv::I420ToNV21(
            src_y_frame, src_stride_y,
            src_u_frame, src_stride_u,
            src_v_frame, src_stride_v,
            dst_y_frame, dst_stride_y,
            dst_vu_frame, dst_stride_vu,
            width, height
            );

    //remember release
    env->ReleaseByteArrayElements(src_y_Buffer, (jbyte *) src_y_frame, 0);
    env->ReleaseByteArrayElements(src_u_Buffer, (jbyte *) src_u_frame, 0);
    env->ReleaseByteArrayElements(src_v_Buffer, (jbyte *) src_v_frame, 0);
    env->ReleaseByteArrayElements(dst_y_Buffer, (jbyte *) dst_y_frame, 0);
    env->ReleaseByteArrayElements(dst_vu_Buffer, (jbyte *) dst_vu_frame, 0);
}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_I420ToARGB(
        JNIEnv *env, jclass *jcls,
        jbyteArray src_y_Buffer, jint src_stride_y,
        jbyteArray src_u_Buffer, jint src_stride_u,
        jbyteArray src_v_Buffer, jint src_stride_v,
        jbyteArray dst_Buffer, jint dst_stride,
        jint width, jint height) {

    uint8_t *src_y_frame = (uint8_t *) env->GetByteArrayElements(src_y_Buffer, 0);
    uint8_t *src_u_frame = (uint8_t *) env->GetByteArrayElements(src_u_Buffer, 0);
    uint8_t *src_v_frame = (uint8_t *) env->GetByteArrayElements(src_v_Buffer, 0);
    uint8_t *dst_frame = (uint8_t *) env->GetByteArrayElements(dst_Buffer, 0);

    libyuv::I420ToARGB(
            src_y_frame, src_stride_y,
            src_u_frame, src_stride_u,
            src_v_frame, src_stride_v,
            dst_frame, dst_stride,
            width, height
    );

    //remember release
    env->ReleaseByteArrayElements(src_y_Buffer, (jbyte *) src_y_frame, 0);
    env->ReleaseByteArrayElements(src_u_Buffer, (jbyte *) src_u_frame, 0);
    env->ReleaseByteArrayElements(src_v_Buffer, (jbyte *) src_v_frame, 0);
    env->ReleaseByteArrayElements(dst_Buffer, (jbyte *) dst_frame, 0);
}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_I420ToBGRA(
        JNIEnv *env, jclass *jcls,
        jbyteArray src_y_Buffer, jint src_stride_y,
        jbyteArray src_u_Buffer, jint src_stride_u,
        jbyteArray src_v_Buffer, jint src_stride_v,
        jbyteArray dst_Buffer, jint dst_stride,
        jint width, jint height) {

    uint8_t *src_y_frame = (uint8_t *) env->GetByteArrayElements(src_y_Buffer, 0);
    uint8_t *src_u_frame = (uint8_t *) env->GetByteArrayElements(src_u_Buffer, 0);
    uint8_t *src_v_frame = (uint8_t *) env->GetByteArrayElements(src_v_Buffer, 0);
    uint8_t *dst_frame = (uint8_t *) env->GetByteArrayElements(dst_Buffer, 0);

    libyuv::I420ToBGRA(
            src_y_frame, src_stride_y,
            src_u_frame, src_stride_u,
            src_v_frame, src_stride_v,
            dst_frame, dst_stride,
            width, height
    );

    //remember release
    env->ReleaseByteArrayElements(src_y_Buffer, (jbyte *) src_y_frame, 0);
    env->ReleaseByteArrayElements(src_u_Buffer, (jbyte *) src_u_frame, 0);
    env->ReleaseByteArrayElements(src_v_Buffer, (jbyte *) src_v_frame, 0);
    env->ReleaseByteArrayElements(dst_Buffer, (jbyte *) dst_frame, 0);
}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_I420ToABGR(
        JNIEnv *env, jclass *jcls,
        jbyteArray src_y_Buffer, jint src_stride_y,
        jbyteArray src_u_Buffer, jint src_stride_u,
        jbyteArray src_v_Buffer, jint src_stride_v,
        jbyteArray dst_Buffer, jint dst_stride,
        jint width, jint height) {

    uint8_t *src_y_frame = (uint8_t *) env->GetByteArrayElements(src_y_Buffer, 0);
    uint8_t *src_u_frame = (uint8_t *) env->GetByteArrayElements(src_u_Buffer, 0);
    uint8_t *src_v_frame = (uint8_t *) env->GetByteArrayElements(src_v_Buffer, 0);
    uint8_t *dst_frame = (uint8_t *) env->GetByteArrayElements(dst_Buffer, 0);

    libyuv::I420ToABGR(
            src_y_frame, src_stride_y,
            src_u_frame, src_stride_u,
            src_v_frame, src_stride_v,
            dst_frame, dst_stride,
            width, height
    );

    //remember release
    env->ReleaseByteArrayElements(src_y_Buffer, (jbyte *) src_y_frame, 0);
    env->ReleaseByteArrayElements(src_u_Buffer, (jbyte *) src_u_frame, 0);
    env->ReleaseByteArrayElements(src_v_Buffer, (jbyte *) src_v_frame, 0);
    env->ReleaseByteArrayElements(dst_Buffer, (jbyte *) dst_frame, 0);
}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_I420ToRGBA(
        JNIEnv *env, jclass *jcls,
        jbyteArray src_y_Buffer, jint src_stride_y,
        jbyteArray src_u_Buffer, jint src_stride_u,
        jbyteArray src_v_Buffer, jint src_stride_v,
        jbyteArray dst_Buffer, jint dst_stride,
        jint width, jint height) {

    uint8_t *src_y_frame = (uint8_t *) env->GetByteArrayElements(src_y_Buffer, 0);
    uint8_t *src_u_frame = (uint8_t *) env->GetByteArrayElements(src_u_Buffer, 0);
    uint8_t *src_v_frame = (uint8_t *) env->GetByteArrayElements(src_v_Buffer, 0);
    uint8_t *dst_frame = (uint8_t *) env->GetByteArrayElements(dst_Buffer, 0);

    libyuv::I420ToRGBA(
            src_y_frame, src_stride_y,
            src_u_frame, src_stride_u,
            src_v_frame, src_stride_v,
            dst_frame, dst_stride,
            width, height
    );

    //remember release
    env->ReleaseByteArrayElements(src_y_Buffer, (jbyte *) src_y_frame, 0);
    env->ReleaseByteArrayElements(src_u_Buffer, (jbyte *) src_u_frame, 0);
    env->ReleaseByteArrayElements(src_v_Buffer, (jbyte *) src_v_frame, 0);
    env->ReleaseByteArrayElements(dst_Buffer, (jbyte *) dst_frame, 0);
}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_I420ToRGB565(
        JNIEnv *env, jclass *jcls,
        jbyteArray src_y_Buffer, jint src_stride_y,
        jbyteArray src_u_Buffer, jint src_stride_u,
        jbyteArray src_v_Buffer, jint src_stride_v,
        jbyteArray dst_Buffer, jint dst_stride,
        jint width, jint height) {

    uint8_t *src_y_frame = (uint8_t *) env->GetByteArrayElements(src_y_Buffer, 0);
    uint8_t *src_u_frame = (uint8_t *) env->GetByteArrayElements(src_u_Buffer, 0);
    uint8_t *src_v_frame = (uint8_t *) env->GetByteArrayElements(src_v_Buffer, 0);
    uint8_t *dst_frame = (uint8_t *) env->GetByteArrayElements(dst_Buffer, 0);

    libyuv::I420ToRGB565(
            src_y_frame, src_stride_y,
            src_u_frame, src_stride_u,
            src_v_frame, src_stride_v,
            dst_frame, dst_stride,
            width, height
    );

    //remember release
    env->ReleaseByteArrayElements(src_y_Buffer, (jbyte *) src_y_frame, 0);
    env->ReleaseByteArrayElements(src_u_Buffer, (jbyte *) src_u_frame, 0);
    env->ReleaseByteArrayElements(src_v_Buffer, (jbyte *) src_v_frame, 0);
    env->ReleaseByteArrayElements(dst_Buffer, (jbyte *) dst_frame, 0);
}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_I420ToRAW(
        JNIEnv *env, jclass *jcls,
        jbyteArray src_y_Buffer, jint src_stride_y,
        jbyteArray src_u_Buffer, jint src_stride_u,
        jbyteArray src_v_Buffer, jint src_stride_v,
        jbyteArray dst_Buffer, jint dst_stride,
        jint width, jint height) {

    uint8_t *src_y_frame = (uint8_t *) env->GetByteArrayElements(src_y_Buffer, 0);
    uint8_t *src_u_frame = (uint8_t *) env->GetByteArrayElements(src_u_Buffer, 0);
    uint8_t *src_v_frame = (uint8_t *) env->GetByteArrayElements(src_v_Buffer, 0);
    uint8_t *dst_frame = (uint8_t *) env->GetByteArrayElements(dst_Buffer, 0);

    libyuv::I420ToRAW(
            src_y_frame, src_stride_y,
            src_u_frame, src_stride_u,
            src_v_frame, src_stride_v,
            dst_frame, dst_stride,
            width, height
    );

    //remember release
    env->ReleaseByteArrayElements(src_y_Buffer, (jbyte *) src_y_frame, 0);
    env->ReleaseByteArrayElements(src_u_Buffer, (jbyte *) src_u_frame, 0);
    env->ReleaseByteArrayElements(src_v_Buffer, (jbyte *) src_v_frame, 0);
    env->ReleaseByteArrayElements(dst_Buffer, (jbyte *) dst_frame, 0);
}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_Android420ToI420(
        JNIEnv *env, jclass *jcls,
        jobject src_y_Buffer, jint src_stride_y,
        jobject src_u_Buffer, jint src_stride_u,
        jobject src_v_Buffer, jint src_stride_v,
        jint pixel_stride_uv,
        jbyteArray dst_y_Buffer, jint dst_stride_y,
        jbyteArray dst_u_Buffer, jint dst_stride_u,
        jbyteArray dst_v_Buffer, jint dst_stride_v,
        jint width, jint height) {

    uint8_t* const y_src =
            +      reinterpret_cast<uint8_t*>(env->GetDirectBufferAddress(src_y_Buffer));
    uint8_t* const u_src =
            +      reinterpret_cast<uint8_t*>(env->GetDirectBufferAddress(src_u_Buffer));
    uint8_t* const v_src =
            +      reinterpret_cast<uint8_t*>(env->GetDirectBufferAddress(src_v_Buffer));

    uint8_t *dst_y_frame = (uint8_t *) env->GetByteArrayElements(dst_y_Buffer, 0);
    uint8_t *dst_u_frame = (uint8_t *) env->GetByteArrayElements(dst_u_Buffer, 0);
    uint8_t *dst_v_frame = (uint8_t *) env->GetByteArrayElements(dst_v_Buffer, 0);

    libyuv::Android420ToI420(
            y_src, src_stride_y,
            u_src, src_stride_u,
            v_src, src_stride_v,
            pixel_stride_uv,
            dst_y_frame, dst_stride_y,
            dst_u_frame, dst_stride_u,
            dst_v_frame, dst_stride_v,
            width, height
    );

    //remember release
    env->ReleaseByteArrayElements(dst_y_Buffer, (jbyte *) dst_y_frame, 0);
    env->ReleaseByteArrayElements(dst_u_Buffer, (jbyte *) dst_u_frame, 0);
    env->ReleaseByteArrayElements(dst_v_Buffer, (jbyte *) dst_v_frame, 0);
}
}