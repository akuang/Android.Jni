package com.example.akuang.androidjni;

/**
 * Created by akuang on 2/11/2018.
 */

public class SampleJni {

    // Sample field for calling Java from C
    private String javaString = "Hello from Java field!";

    // Sample method calling C method which calls back to Java field
    public String stringFromJava()
    {
        return nativeStringFromJAVA();
    }

    // Sample method calling C from Java
    public String stringFromJni()
    {
        return nativeStringFromJNI();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    private native String nativeStringFromJNI();
    private native String nativeStringFromJAVA();
}
