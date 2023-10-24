#pragma once
#include "Action.h"
#include <string>

class LogAction: public Action
{
public:
	LogAction(std::string message) : m_Message(message) {};
	bool doAction();
private:
	std::string m_Message;
};

