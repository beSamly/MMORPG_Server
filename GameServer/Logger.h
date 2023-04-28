#pragma once
#include <spdlog/spdlog.h>
#include <string>
#include <format>

using std::string;

class Logger
{
private:
	string filePath;

public:
	Logger(string paramfilePath) : filePath(paramfilePath) {}

	void Info(string str) { spdlog::info(str); }

	void Error(string str)
	{
		spdlog::error(str);
	}
};
