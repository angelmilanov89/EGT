#pragma once
#include <mutex>
#include "FSMState.h"
class FSM;

class FSMState2 : public FSMState
{
public:
	void enter(FSM* fms);
	void update(FSM* fms, int frame);
	void exit(FSM* fms);
	static FSMState2* getInstance();

	FSMState2(const FSMState2& other) = delete;
	FSMState2& operator=(const FSMState2& other) = delete;
private:
	FSMState2() {}

	static FSMState2* pinstance_;
	static std::mutex m_FSMState2Mutex;
};
