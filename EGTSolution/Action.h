#pragma once
class Action
{
public:
	virtual bool doAction() = 0;

	int getId();
private:
	int m_Id;
};

