package com.example.akuang.androidjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

// Create Hello-CMake with Android Studio
// Google CodeLab: https://codelabs.developers.google.com/codelabs/android-studio-cmake/

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        // Example of calling C native methods in a Java class
        SampleJni sample = new SampleJni();

        // Calling C method from Java
        String cstr = sample.stringFromJni();

        // Calling Java field from C
        String jstr = sample.stringFromJava();

        TextView tvJni = (TextView) findViewById(R.id.sample_jni_text);
        tvJni.setText(cstr + " AND " + jstr);
    }

    // Sample method for calling Java from C++
    public String stringFromJava()
    {
        return "Hello from Java!";
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
