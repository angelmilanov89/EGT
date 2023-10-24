#pragma once
#include <mutex>
#include "FSMState.h"
class FSM;

class FSMState3 : public FSMState
{
public:
	void enter(FSM* fms);
	void update(FSM* fms, int frame);
	void exit(FSM* fms);
	static FSMState3* getInstance();

	FSMState3(const FSMState3& other) = delete;
	FSMState3& operator=(const FSMState3& other) = delete;
private:
	FSMState3() {}

	static FSMState3* pinstance_;
	static std::mutex m_FSMState3Mutex;
};
