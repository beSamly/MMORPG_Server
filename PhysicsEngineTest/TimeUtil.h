#pragma once
#include "pch.h"

using std::chrono::steady_clock;

class TimeUtil
{
public:
	static steady_clock::time_point GetNow() { return steady_clock::now(); }
	static float GetElapsedInMicroSec(steady_clock::time_point from) { return std::chrono::duration_cast<std::chrono::microseconds>(GetNow() - from).count(); }
	static float GetElapsedInMiilliSec(steady_clock::time_point from) { return GetElapsedInMicroSec(from) / 1000.0f; }
	static float GetElapsedInSec(steady_clock::time_point from) { return GetElapsedInMiilliSec(from) / 1000.0f; }

	static void LogElapsedTime(string prefix, function<void()> func)
	{
		steady_clock::time_point t1 = GetNow();
		func();
		float elpasedInSec = GetElapsedInSec(t1);
		spdlog::info("{} elasepd Second for {}", elpasedInSec, prefix);
	}

	static void LogElapsedTimeInMilliSec(string prefix, function<void()> func)
	{
		steady_clock::time_point t1 = GetNow();
		func();
		float elpasedInSec = GetElapsedInMiilliSec(t1);
		spdlog::info("{} elasepd MilliSecond for {}", elpasedInSec, prefix);
	}
}; // namespace TimeUtil
