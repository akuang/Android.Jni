//
// Created by akuang on 2/11/2018.
//

#include <jni.h>

// TODO:
// From https://docs.oracle.com/javase/1.5.0/docs/guide/jni/spec/invocation.html:
// The JNI interface pointer (JNIEnv) is valid only in the current thread. Should another thread
// need to access the Java VM, it must first call AttachCurrentThread() to attach itself to the
// VM and obtain a JNI interface pointer. Once attached to the VM, a native thread works just like
// an ordinary Java thread running inside a native method. The native thread remains attached to
// the VM until it calls DetachCurrentThread() to detach itself.

jstring
Java_com_example_akuang_androidjni_SampleJni_nativeStringFromJNI(JNIEnv *env, jobject obj) {
    char* hello = "Hello from C";
    return (*env)->NewStringUTF(env, hello);
}

jstring
Java_com_example_akuang_androidjni_SampleJni_nativeStringFromJAVA(JNIEnv *env, jobject obj) {

    // Example of calling a Java method from C++

    jclass sampleJinClass = (*env)->GetObjectClass(env, obj);

    if (sampleJinClass == 0) {
        return (*env)->NewStringUTF(env, "[SampleJni.c] GetObjectClass failed!");
    }

    jfieldID javaField = (*env)->GetFieldID(env, sampleJinClass, "javaString", "Ljava/lang/String;");

    if (javaField == 0) {
        return (*env)->NewStringUTF(env, "[SampleJni.c] GetFieldID failed!");
    }

    jstring javaString = (jstring)(*env)->GetObjectField(env, obj, javaField);

    if (javaString == NULL) {
        return (*env)->NewStringUTF(env, "[SampleJni.c] GetObjectField failed!");
    }

    const char* cstr = (*env)->GetStringUTFChars(env, javaString, NULL);

    return (*env)->NewStringUTF(env, cstr);
}
