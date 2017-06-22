package com.lhd.ndktest;

/**
 * Created by lihuaidong on 2017/6/21 16:20.
 * 微信：lhd520ssp
 * QQ:414320737
 * 作用：包含所有native方法
 */
public class JNIS
{

    static
    {
        System.loadLibrary("HelloJni");
    }

    public native String helloJNI();
    public native int sum(int x, int y);
    public native String sayHello(String s);
    public native int[] increaseArrayEles(int[] intArray);
    /*
 * 应用: 检查密码是否正确, 如果正确返回200, 否则返回400
		"123456"
 */
    public native int checkPwd(String pwd);

}
