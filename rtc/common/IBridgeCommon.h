//
// Created by 张涛 on 2020-08-10.
//

#pragma once

#include "../include/IAgoraRtcEngine.h"
#include <string>

namespace agora {
namespace common {
#if defined(_WIN32)
#define CROSS_PLATFORM_EXPORT extern "C" __declspec(dllexport)
#elif defined(__APPLE__)
#define CROSS_PLATFORM_EXPORT __attribute__((visibility("default"))) extern "C"
#elif defined(__ANDROID__) || defined(__linux__)
#define CROSS_PLATFORM_EXPORT extern "C" __attribute__((visibility("default")))
#else
#define CROSS_PLATFORM_EXPORT extern "C"
#endif

#define CHECK_RET_ERROR(ret)                                                   \
  if (ret < 0) {                                                               \
    return ret;                                                                \
  }

#define CHECK_PARSE_DOCUMENT(doc, ret)                                         \
  if (doc.HasParseError()) {                                                   \
    ret = ERROR_CODE::ERROR_PARSE_PARAMETER;                                   \
    return ret;                                                                \
  }

#define CHECK_PARSE_DOCUMENT_CHAR(doc)                                         \
  if (doc.HasParseError()) {                                                   \
    return "-102";                                                             \
  }

#define CHECK_RET_ERROR_NULL(ret)                                              \
  if (ret < 0) {                                                               \
    return;                                                                    \
  }

#define CHECK_RET_ERROR_CHAR(ret)                                              \
  if (ret < 0) {                                                               \
    return "";                                                                 \
  }

enum API_TYPE {
  INITIALIZE = 0,
  RELEASE = 1,
  SET_CHANNEL_PROFILE = 2,
  SET_CLIENT_ROLE = 3,
  JOIN_CHANNEL = 4,
  SWITCH_CHANNEL = 5,
  LEAVE_CHANNEL = 6,
  RE_NEW_TOKEN = 7,
  REGISTER_LOCAL_USER_ACCOUNT = 8,
  JOIN_CHANNEL_WITH_USER_ACCOUNT = 9,
  GET_USER_INFO_BY_USER_ACCOUNT = 10,
  GET_USER_INFO_BY_UID = 11,
  START_ECHO_TEST = 12,
  START_ECHO_TEST_2 = 13,
  STOP_ECHO_TEST = 14,
  ENABLE_VIDEO = 15,
  DISABLE_VIDEO = 16,
  SET_VIDEO_PROFILE = 17,
  SET_VIDEO_ENCODER_CONFIGURATION = 18,
  SET_CAMERA_CAPTURER_CONFIGURATION = 19,
  SET_UP_LOCAL_VIDEO = 20,
  SET_UP_REMOTE_VIDEO = 21,
  START_PREVIEW = 22,
  SET_REMOTE_USER_PRIORITY = 23,
  STOP_PREVIEW = 24,
  ENABLE_AUDIO = 25,
  ENABLE_LOCAL_AUDIO = 26,
  DISABLE_AUDIO = 27,
  SET_AUDIO_PROFILE = 28,
  MUTE_LOCAL_AUDIO_STREAM = 29,
  MUTE_ALL_REMOTE_AUDIO_STREAMS = 30,
  SET_DEFAULT_MUTE_ALL_REMOTE_AUDIO_STREAMS = 31,
  ADJUST_USER_PLAYBACK_SIGNAL_VOLUME = 32,
  MUTE_REMOTE_AUDIO_STREAM = 33,
  MUTE_LOCAL_VIDEO_STREAM = 34,
  ENABLE_LOCAL_VIDEO = 35,
  MUTE_ALL_REMOTE_VIDEO_STREAMS = 36,
  SET_DEFAULT_MUTE_ALL_REMOTE_VIDEO_STREAMS = 37,
  MUTE_REMOTE_VIDEO_STREAM = 38,
  SET_REMOTE_VIDEO_STREAM_TYPE = 39,
  SET_REMOTE_DEFAULT_VIDEO_STREAM_TYPE = 40,
  ENABLE_AUDIO_VOLUME_INDICATION = 41,
  START_AUDIO_RECORDING = 42,
  START_AUDIO_RECORDING2 = 43,
  STOP_AUDIO_RECORDING = 44,
  ENABLE_FACE_DETECTION = 62,
  SET_REMOTE_VOICE_POSITIONN = 73,
  SET_LOG_FILE = 79,
  SET_LOG_FILTER = 80,
  SET_LOG_FILE_SIZE = 81,
  SET_LOCAL_RENDER_MODE = 82,
  SET_LOCAL_RENDER_MODE_2 = 83,
  SET_REMOTE_RENDER_MODE = 84,
  SET_REMOTE_RENDER_MODE_2 = 85,
  SET_LOCAL_VIDEO_MIRROR_MODE = 86,
  ENABLE_DUAL_STREAM_MODE = 87,
  ADJUST_RECORDING_SIGNAL_VOLUME = 93,
  ADJUST_PLAYBACK_SIGNAL_VOLUME = 94,
  ENABLE_WEB_SDK_INTEROPER_ABILITY = 95,
  SET_VIDEO_QUALITY_PARAMETERS = 96,
  SET_LOCAL_PUBLISH_FALLBACK_OPTION = 97,
  SET_REMOTE_SUBSCRIBE_FALLBACK_OPTION = 98,
  SWITCH_CAMERA = 99,
  SWITCH_CAMERA_2 = 100,
  SET_DEFAULT_AUDIO_ROUTE_SPEAKER_PHONE = 101,
  SET_ENABLE_SPEAKER_PHONE = 102,
  ENABLE_IN_EAR_MONITORING = 103,
  SET_IN_EAR_MONITORING_VOLUME = 104,
  IS_SPEAKER_PHONE_ENABLED = 105,
  SET_AUDIO_SESSION_OPERATION_RESTRICTION = 106,
  ENABLE_LOOP_BACK_RECORDING = 107,
  START_SCREEN_CAPTURE_BY_DISPLAY_ID = 108,
  START_SCREEN_CAPTURE_BY_SCREEN_RECT = 109,
  START_SCREEN_CAPTURE_BY_WINDOW_ID = 110,
  SET_SCREEN_CAPTURE_CONTENT_HINT = 111,
  UPDATE_SCREEN_CAPTURE_PARAMETERS = 112,
  UPDATE_SCREEN_CAPTURE_REGION = 113,
  STOP_SCREEN_CAPTURE = 114,
  GET_CALL_ID = 117,
  RATE = 118,
  COMPLAIN = 119,
  GET_VERSION = 120,
  ENABLE_LAST_MILE_TEST = 121,
  DISABLE_LAST_MILE_TEST = 122,
  START_LAST_MILE_PROBE_TEST = 123,
  STOP_LAST_MILE_PROBE_TEST = 124,
  GET_ERROR_DESCRIPTION = 125,
  SET_ENCRYPTION_SECTRT = 126,
  SET_ENCRYPTION_MODE = 127,
  REGISTER_PACKET_OBSERVER = 128,
  CREATE_DATA_STREAM = 129,
  SEND_STREAM_MESSAGE = 130,
  ADD_PUBLISH_STREAM_URL = 131,
  REMOVE_PUBLISH_STREAM_URL = 132,
  SET_LIVE_TRANSCODING = 133,
  ADD_VIDEO_WATER_MARK = 134,
  ADD_VIDEO_WATER_MARK_2 = 135,
  CLEAR_VIDEO_WATER_MARKS = 136,
  SET_BEAUTY_EFFECT_OPTIONS = 137,
  ADD_INJECT_STREAM_URL = 138,
  START_CHANNEL_MEDIA_RELAY = 139,
  UPDATE_CHANNEL_MEDIA_RELAY = 140,
  STOP_CHANNEL_MEDIA_RELAY = 141,
  REMOVE_INJECT_STREAM_URL = 142,
  GET_CONNECTION_STATE = 143,
  REGISTER_MEDIA_META_DATA_OBSERVER = 144,
  SET_PARAMETERS = 145,
  SET_PLAYBACK_DEVICE_VOLUME = 146,
  PUBLISH = 147,
  UNPUBLISH = 148,
  CHANNEL_ID = 149,
  SEND_METADATA = 150,
  SET_MAX_META_SIZE = 151,
  PUSH_AUDIO_FRAME = 152,
  PUSH_AUDIO_FRAME_2 = 153,
  PULL_AUDIO_FRAME = 154,
  SET_EXTERN_VIDEO_SOURCE = 155,
  PUSH_VIDEO_FRAME = 156,
  ENABLE_ENCRYPTION = 157,
  SEND_CUSTOM_REPORT_MESSAGE = 158,
  REGISTER_VIDEO_FRAME_OBSERVER = 159
};

enum API_TYPE_AUDIO_EFFECT {
  START_AUDIO_MIXING = 45,
  STOP_AUDIO_MIXING = 46,
  PAUSE_AUDIO_MIXING = 47,
  RESUME_AUDIO_MIXING = 48,
  SET_HIGH_QUALITY_AUDIO_PARAMETERS = 49,
  ADJUST_AUDIO_MIXING_VOLUME = 50,
  ADJUST_AUDIO_MIXING_PLAYOUT_VOLUME = 51,
  GET_AUDIO_MIXING_PLAYOUT_VOLUME = 52,
  ADJUST_AUDIO_MIXING_PUBLISH_VOLUME = 53,
  GET_AUDIO_MIXING_PUBLISH_VOLUME = 54,
  GET_AUDIO_MIXING_DURATION = 55,
  GET_AUDIO_MIXING_CURRENT_POSITION = 56,
  SET_AUDIO_MIXING_POSITION = 57,
  SET_AUDIO_MIXING_PITCH = 58,
  GET_EFFECTS_VOLUME = 59,
  SET_EFFECTS_VOLUME = 60,
  SET_VOLUME_OF_EFFECT = 61,
  PLAY_EFFECT = 63,
  STOP_EFFECT = 64,
  STOP_ALL_EFFECTS = 65,
  PRE_LOAD_EFFECT = 66,
  UN_LOAD_EFFECT = 67,
  PAUSE_EFFECT = 68,
  PAUSE_ALL_EFFECTS = 69,
  RESUME_EFFECT = 70,
  RESUME_ALL_EFFECTS = 71,
  ENABLE_SOUND_POSITION_INDICATION = 72,
  SET_LOCAL_VOICE_PITCH = 74,
  SET_LOCAL_VOICE_EQUALIZATION = 75,
  SET_LOCAL_VOICE_REVERB = 76,
  SET_LOCAL_VOICE_CHANGER = 77,
  SET_LOCAL_VOICE_REVERB_PRESET = 78,
  SET_EXTERNAL_AUDIO_SOURCE = 88,
  SET_EXTERNAL_AUDIO_SINK = 89,
  SET_RECORDING_AUDIO_FRAME_PARAMETERS = 90,
  SET_PLAYBACK_AUDIO_FRAME_PARAMETERS = 91,
  SET_MIXED_AUDIO_FRAME_PARAMETERS = 92,
};

enum API_TYPE_DEVICE_MANAGER {
  GET_COUNT = 151,
  GET_DEVICE = 152,
  GET_CURRENT_DEVICE = 153,
  GET_CURRENT_DEVICE_INFO = 154,
  SET_DEVICE = 155,
  SET_DEVICE_VOLUME = 156,
  GET_DEVICE_VOLUME = 157,
  SET_DEVICE_MUTE = 158,
  GET_DEVICE_MUTE = 159,
  START_DEVICE_TEST = 160,
  STOP_DEVICE_TEST = 161,
  START_AUDIO_DEVICE_LOOP_BACK_TEST = 162,
  STOP_AUDIO_DEVICE_LOOP_BACK_TEST = 163
};

enum ERROR_CODE {
  ERROR_OK = 0,
  ERROR_INVALID_API_TYPE = -100,
  ERROR_INVALID_PARAM = -101,
  ERROR_PARSE_PARAMETER = -102,
  ERROR_NO_CURRENT_PARAMETER = -103,
  ERROR_NOT_SUPPORT_API = -4,
  ERROR_NOT_INITIALIZE_OBSERVER = -104,
  ERROR_NO_DEVICE = -105,
  ERROR_ENGINE_EXIST = -106,
  ERROR_NO_ENGINE = -107
};
} // namespace common
} // namespace agora
