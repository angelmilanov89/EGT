#include "FSM.h"
#include "FSMState1.h"


FSM::FSM()
{
	currentState = FSMState1::getInstance();
}

void FSM::setState(FSMState& newState)
{
	currentState->exit(this);  // do something before we change state
	currentState = &newState;  // actually change states now
	currentState->enter(this); // do something after we change state
}

void FSM::update(int frame)
{
	// Delegate the task of determining the next state to the current state
	currentState->update(this,frame);
}