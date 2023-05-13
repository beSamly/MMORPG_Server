#pragma once
#include "pch.h"
#include "LogMacro.h"

using std::chrono::steady_clock;

class TimeUtil
{
public:
    static steady_clock::time_point GetNow() { return steady_clock::now(); }
    static float GetElapsedInMsec(steady_clock::time_point from) { return std::chrono::duration_cast<std::chrono::microseconds>(GetNow() - from).count(); }
    static float GetElapsedInSec(steady_clock::time_point from) { return GetElapsedInMsec(from) / 1000000.0f; }

    static void LogElapsedTime(string prefix, function<void()> func)
    {
        /*if (off)
        {
            func();
            return;
        }*/

        steady_clock::time_point t1 = GetNow();
        func();
        float elpasedInSec = GetElapsedInSec(t1);
        LOG_INFO(std::to_string(elpasedInSec) + " elapsed Time : " + prefix);
    }
}; // namespace TimeUtil
