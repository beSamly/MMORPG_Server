#pragma once
#include <spdlog/spdlog.h>
#include <string>

using std::string;

class Logger
{
private:
    string filePath;

public:
    Logger(string paramfilePath) : filePath(paramfilePath) {}

    template <typename... Args>
    using format_string_t = fmt::format_string<Args...>;

    template <typename... Args>
    void Info(format_string_t<Args...> fmt, Args&&... args)
    {
        spdlog::error(fmt, std::forward<Args>(args)...);
        //spdlog::info(fmt, std::forward<Args>(args)...);
    };

    template <typename... Args>
    void Error(format_string_t<Args...> fmt, Args&&... args)
    {
        //spdlog::info(fmt, std::forward<Args>(args)...);

        // spdlog::error(fmt, std::forward<Args>(args)...);

        // spdlog::error(fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void Debug(format_string_t<Args...> fmt, Args&&... args)
    {
        // spdlog::debug(fmt, std::forward<Args>(args)...);
    }
};
