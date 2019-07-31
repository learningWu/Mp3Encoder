LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES=./Mp3Encoder.cpp
LOCAL_SRC_FILES+=./mp3_encoder.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/3rdparty/lame/include

LOCAL_LDFLAGS += $(LOCAL_PATH)/3rdparty/lame/lib/libmp3lame.a

LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog
LOCAL_LDLIBS += -lz
LOCAL_LDLIBS += -landroid
LOCAL_LDLIBS += -L$(LOCAL_PATH)/3rdparty/lame/lib -lmp3lame

LOCAL_MODULE:=libaudioencoder

include $(BUILD_SHARED_LIBRARY)
include $(call all-makefiles-under,$(LOCAL_PATH))