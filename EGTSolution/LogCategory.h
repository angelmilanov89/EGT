#pragma once
#include "LogEnums.h"
#include <string>

class LogCategory
{
public:
	LogCategory()
		:m_MinLogLevel(LogLevelsEnum::DEBUG)
	{};

	LogCategory(LogLevelsEnum minLogLevel)
		:m_MinLogLevel(minLogLevel)
	{};

	const LogLevelsEnum getMinLogLevel() const;

private:
	LogLevelsEnum m_MinLogLevel;
};

