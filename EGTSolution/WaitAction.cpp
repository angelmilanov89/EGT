#include <chrono>
#include <thread>
#include "WaitAction.h"

bool WaitAction::doAction()
{
	std::this_thread::sleep_for(std::chrono::seconds(m_Seconds));
	return true;
}
