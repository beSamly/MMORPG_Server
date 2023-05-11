#pragma once
#include "pch.h"
#include "LogMacro.h"

using std::chrono::steady_clock;

namespace TimeUtil
{
    steady_clock::time_point GetNow() { return steady_clock::now(); }
    float GetElapsedInMsec(steady_clock::time_point from) { return std::chrono::duration_cast<std::chrono::microseconds>(GetNow() - from).count(); }
    float GetElapsedInSec(steady_clock::time_point from) { return GetElapsedInMsec(from) / 1000000.0f; }

    void LogElapsedTime(string prefix, function<void()> func)
    {
        steady_clock::time_point t1 = GetNow();
        func();
        float elpasedInSec = GetElapsedInSec(t1);
        LOG_INFO(prefix  + " elapsed Time : " + std::to_string(elpasedInSec));
    }

} // namespace TimeUtil