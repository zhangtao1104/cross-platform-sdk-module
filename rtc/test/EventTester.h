#ifndef EventTester_h
#define EventTester_h

#include "../callback/rtcChannnelCallback/RtcChannelEventHandlerBase.h"
#include "../callback/rtcEngineCallback/RtcEngineEventHandlerBase.h"
#include "../include/IAgoraRtcChannel.h"
#include "../include/IAgoraRtcEngine.h"
#include <string>

namespace agora {
namespace common {

// -- Tester for RtcEngineEventHandlerBase
void BeginRtcEngineEventTest(const char *caseFilePath,
                             RtcEngineEventHandlerBase *eventHandler);
void CompareAndDumpRtcEngineEventTestResult(
    const char *caseFilePath, const char *dumpFilePath,
    RtcEngineEventHandlerBase *eventHandler);

void BeginRtcEngineEventTestWithString(const char *testCase,
                                       RtcEngineEventHandlerBase *eventHandler);
std::string CompareAndDumpRtcEngineEventTestResultWithSring(
    const char *testCase, RtcEngineEventHandlerBase *eventHandler);

void LogEngineEventCase(const char *eventType, const char *parameter);

// -- Tester for RtcChannelEventHandlerBase
void BeginChannelEventTest(const char *caseFilePath,
                           agora::rtc::IChannel *rtcChannel,
                           RtcChannelEventHandlerBase *eventHandler);
void CompareAndDumpChannelEventTestResult(
    const char *caseFilePath, const char *dumpFilePath,
    agora::rtc::IChannel *rtcChannel, RtcChannelEventHandlerBase *eventHandler);

void BeginChannelEventTestWithString(const char *testCase,
                                     agora::rtc::IChannel *rtcChannel,
                                     RtcChannelEventHandlerBase *eventHandler);
std::string CompareAndDumpChannelEventTestResultWithString(
    const char *testCase, agora::rtc::IChannel *rtcChannel,
    RtcChannelEventHandlerBase *eventHandler);

void LogChannelEventCase(const char *eventType, const char *parameter);

} // namespace common
} // namespace agora

#endif /* EventTester_hpp */
