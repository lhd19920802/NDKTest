package com.lhd.ndktest;

/**
 * Created by lihuaidong on 2017/6/21 16:20.
 * 微信：lhd520ssp
 * QQ:414320737
 * 作用：
 */
public class JNIS
{

    static
    {
        System.loadLibrary("HelloJni");
    }

    public native String helloJNI();

}
