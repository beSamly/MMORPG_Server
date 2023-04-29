#pragma once
#include <spdlog/spdlog.h>
#include <string>
#include <format>

using std::string;

// class Logger
//{
// private:
//     string filePath;
//
// public:
//     Logger(string paramfilePath) : filePath(paramfilePath) {}
//
//     static void Info(string str) { spdlog::info(str); }
//
//     static void Error(string str) { spdlog::error(str); }
//
//     static void Debug(string str) { spdlog::debug(str); }
// };

class Logger
{
private:
    Logger(){};
    Logger(const Logger& ref){};
    Logger& operator=(const Logger& ref){};

public:
    ~Logger(){};

    static string filePath;
    static void SetFilaPath(string path) { filePath = path; }

    static const Logger& GetInstance()
    {
        static Logger s;
        return s;
    }

    static void Info(string str) { spdlog::info(str); }

    static void Error(string str) { spdlog::error(str); }

    static void Debug(string str) { spdlog::debug(str); }
};
