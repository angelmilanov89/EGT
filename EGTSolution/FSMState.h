#pragma once
#include <mutex>
class FSM;

class FSMState
{
public:
	virtual void enter(FSM* fms) = 0;
	virtual void update(FSM* fms, int frame) = 0;
	virtual void exit(FSM* fms) = 0;
	virtual ~FSMState() {}
};
