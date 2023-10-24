#pragma once
#include "Action.h"

class WaitAction: public Action
{
public:
	WaitAction(int seconds) : m_Seconds(seconds) {};
	bool doAction();
private:
	int m_Seconds;
};

