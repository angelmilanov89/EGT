#pragma once
#include <queue>
#include <string>

class Action;

enum class TaskStatesEnum
{
	Rejected,
	InQueue,
	Started,
	Completed,
	Failed
};

class Task
{
public:
	Task(int ownerId, int taskId, std::queue<Action*> actions) :m_OwnerId(ownerId), m_Id(taskId), m_State(TaskStatesEnum::InQueue),m_Actions(actions) {};

	void startTask();
	
	void setState(TaskStatesEnum state);
	TaskStatesEnum getState();
	std::string getTaskStatusString();
	int getOwnerId();
	int getId();

private:
	int m_OwnerId;
	int m_Id;
	std::queue<Action*> m_Actions;
	TaskStatesEnum m_State;


};

