#include "com_lhd_ndktest_JNIS.h"
jstring Java_com_lhd_ndktest_JNIS_helloJNI
        (JNIEnv * env, jobject jobj) {
    return (*env)->NewStringUTF(env, "Hello from C");
}