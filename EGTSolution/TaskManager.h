#pragma once
#include <list>
#include <mutex>
#include "Task.h"


class TaskManager
{
public:
	TaskManager(TaskManager& other) = delete;
	void operator=(const TaskManager&) = delete;

	static TaskManager* GetInstance();
	void update();
	void addTask(int owerID, int taskID, std::queue<Action*> m_Actions);
	void notifyOwner(std::string messaage);

private:
	TaskManager() {}

	std::list<Task> m_TasksList;

	static TaskManager* pinstance_;
	static std::mutex m_TaskManagerMutex;
	static std::mutex m_TasksMutex;
};

