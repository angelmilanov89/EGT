#pragma once
class FSMState;

class FSM
{
public:
	FSM();
	FSMState* getCurrentState() const;
	void update(int frame);
	// This is where the magic happens
	void setState(FSMState& newState);

private:
	FSMState* currentState;
};

