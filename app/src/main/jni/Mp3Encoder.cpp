//
// Created by dzj on 2019-07-28.
//
#include <stdio.h>

#include "com_eddie_mp3encoder_Mp3Encoder.h"

#include "mp3_encoder.h"
#include "CommonTools.h"

// 引入log头文件
#include  <android/log.h>

#define LOG_TAG "Mp3Encoder"

Mp3Encoder* encoder = NULL;

JNIEXPORT jint JNICALL Java_com_eddie_mp3encoder_Mp3Encoder_init
  (JNIEnv * env, jobject obj, jstring pcmPathParam, jint channels, jint bitRate,
			jint sampleRate, jstring mp3PathParam) {
	const char* pcmPath = env->GetStringUTFChars(pcmPathParam, NULL);
	const char* mp3Path = env->GetStringUTFChars(mp3PathParam, NULL);
	LOGI("mp3Path is %s...", mp3Path);
	encoder = new Mp3Encoder();
	jint ret = encoder->Init(pcmPath, mp3Path, sampleRate, channels, bitRate);
	env->ReleaseStringUTFChars(mp3PathParam, mp3Path);
	env->ReleaseStringUTFChars(pcmPathParam, pcmPath);
	return ret;
}

JNIEXPORT void JNICALL Java_com_eddie_mp3encoder_Mp3Encoder_encode(JNIEnv * env, jobject obj) {
    LOGI("嘿嘿嘿，我开始 encode 了");
	if(NULL != encoder) {
		encoder->Encode();
	}
}

JNIEXPORT void JNICALL Java_com_eddie_mp3encoder_Mp3Encoder_destroy(JNIEnv * env, jobject obj) {
	if(NULL != encoder) {
		encoder->Destory();
		delete encoder;
		encoder = NULL;
	}
}
