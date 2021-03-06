include $(CLEAR_VARS)
$(warning "${MAIN_LOCAL_PATH}")

LOCAL_PATH = .
LOCAL_MODULE := game
LOCAL_EXPORT_C_INCLUDES := $(MAIN_LOCAL_PATH) \
	$(MAIN_LOCAL_PATH)/libs/cocos2dx
LOCAL_SRC_FILES := ${MAIN_LOCAL_PATH}/include/libgame.so
include $(PREBUILT_SHARED_LIBRARY)

LOCAL_PATH := ${MAIN_LOCAL_PATH}
include $(CLEAR_VARS)
LOCAL_MODULE := bt1p0

LOCAL_CPPFLAGS := -std=c++14
LOCAL_CFLAGS := -Wno-error=format-security -fpermissive -Wc++14-extensions -Wno-absolute-value
LOCAL_CFLAGS += -fno-rtti -fno-exceptions

LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH) \
	$(MAIN_LOCAL_PATH)/libs/cocos2dx

LOCAL_SRC_FILES := src/main.cpp \
	libs/hook/inlineHook.c \
	libs/hook/relocate.c \

LOCAL_LDLIBS := -llog
LOCAL_SHARED_LIBRARIES = game
include $(BUILD_SHARED_LIBRARY)