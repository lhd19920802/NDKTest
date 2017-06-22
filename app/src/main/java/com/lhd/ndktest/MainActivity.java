package com.lhd.ndktest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;

public class MainActivity extends AppCompatActivity
{

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        JNIS jnis = new JNIS();
        String result = jnis.helloJNI();
        Log.e("TAG", "result=" + result);
        int sum = jnis.sum(4, 5);
        Log.e("TAG", "sum==" + sum);

        String str = jnis.sayHello("go to hell");
        Log.e("TAG", "str==" + str);

        int[] arr = {1, 2, 3};
        int[] arrs = jnis.increaseArrayEles(arr);

        for (int a : arrs)
        {
            Log.e("TAG", "arrs="+a);
        }

        int num = jnis.checkPwd("123456");
        if(num==200) {
            Log.e("TAG", "密码正确");
        }
        else
        {
            Log.e("TAG", "密码错误");
        }


    }
}
