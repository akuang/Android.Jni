#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_akuang_androidjni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject obj) {
    std::string hello = "Hello from C++";

    // Example of calling a Java method from C++

    jclass mainActivityClass = env->GetObjectClass(obj);

    if (mainActivityClass == 0) {
       return env->NewStringUTF("GetObjectClass failed!");
    }

    jmethodID javaMethod = env->GetMethodID(mainActivityClass, "stringFromJava", "()Ljava/lang/String;");

    if (javaMethod == 0) {
        return env->NewStringUTF("GetMethodID failed!");
    }

    jstring javaString = (jstring)env->CallObjectMethod(obj, javaMethod);

    if (javaString == NULL) {
        return env->NewStringUTF("CallObjectMethod failed!");
    }

    const char* cstr = env->GetStringUTFChars(javaString, NULL);

    hello.append(" AND ");
    hello.append(cstr);

    return env->NewStringUTF(hello.c_str());
}
