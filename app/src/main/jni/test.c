#include "com_lhd_ndktest_JNIS.h"
#include "string.h"
jstring Java_com_lhd_ndktest_JNIS_helloJNI
        (JNIEnv * env, jobject jobj) {
    return (*env)->NewStringUTF(env, "Hello from C");
}
jint Java_com_lhd_ndktest_JNIS_sum
        (JNIEnv *env, jobject jobj, jint x, jint y)
{
    return x+y;
}
/**
 * 工具函数
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char* _JString2CStr(JNIEnv* env, jstring jstr) {

    char* rtn;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}
jstring Java_com_lhd_ndktest_JNIS_sayHello
        (JNIEnv *env, jobject jobj, jstring str){
    char *str1 = _JString2CStr(env,str);
    char *str2 = " haha";
    char *string = strcat(str1, str2);
    return (*env)->NewStringUTF(env,string);
}
//JNIEXPORT jstring JNICALL Java_com_lhd_ndktest_JNIS_sayHello
//        (JNIEnv * env, jobject jobj, jstring str) {
//    char *str1 = _JString2CStr(env, str);
//    char *str2 = " hahaha";
//
//    char *result = strcat(str1, str2);
//    return (*env)->NewStringUTF(env, result);
//}

JNIEXPORT jintArray JNICALL Java_com_lhd_ndktest_JNIS_increaseArrayEles
        (JNIEnv *env, jobject jobj, jintArray jarray) {
    //得到数组的长度
    jsize length = (*env)->GetArrayLength(env,jarray);
    //得到数组
    jint *array = (*env)->GetIntArrayElements(env,jarray,JNI_FALSE);
    int i;
    for (i = 0; i < length; i++) {
        *(array+i)+=10;
    }
    return jarray;
}

JNIEXPORT jintArray JNICALL Java_com_lhd_ndktest_JNIS_checkPwd
        (JNIEnv *env, jobject jobj, jstring str)
{
    //将jstring转换成char*
    char *pwd1 = _JString2CStr(env, str);
    char *pwd2 = "123456";
    //比较
    int result = strcmp(pwd1, pwd2);
    if (result == 0) {
        return 200;
    }
    return 400;
}