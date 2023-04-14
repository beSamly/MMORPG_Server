#pragma once
#include "ILogger.h"

class Logger : ILogger
{
	virtual void Error() override;
	virtual void Info() override;
	virtual void Debug() override;
};

