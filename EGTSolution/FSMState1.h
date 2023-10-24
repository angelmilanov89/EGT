#pragma once
#include <mutex>
#include "FSMState.h"
class FSM;


class FSMState1 : public FSMState
{
public:
	void enter(FSM* fms);
	void update(FSM* fms, int frame);
	void exit(FSM* fms);
	static FSMState1* getInstance();

	FSMState1(const FSMState1& other) = delete;
	FSMState1& operator=(const FSMState1& other) = delete;
private:
	FSMState1() {}

	static FSMState1* pinstance_;
	static std::mutex m_FSMState1Mutex;
};