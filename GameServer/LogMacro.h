#pragma once
#include "Logger.h"

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define LOG_DEBUG(str) Logger::GetInstance().Debug(str);
#define LOG_ERROR(str) Logger::GetInstance().Error(str);
#define LOG_INFO(str) Logger::GetInstance().Info(str);

