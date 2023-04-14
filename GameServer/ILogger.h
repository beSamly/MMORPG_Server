#pragma once
class ILogger
{
public:
	virtual void Error() abstract;
	virtual void Info() abstract;
	virtual void Debug() abstract;
};

