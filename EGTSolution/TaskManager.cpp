#include "TaskManager.h"
#include "LogStream.h"

TaskManager* TaskManager::pinstance_{ nullptr };
std::mutex TaskManager::m_TaskManagerMutex;
std::mutex TaskManager::m_TasksMutex;

TaskManager* TaskManager::GetInstance()
{
	std::lock_guard<std::mutex> lock(m_TaskManagerMutex);
	if (pinstance_ == nullptr)
	{
		pinstance_ = new TaskManager();

	}
	return pinstance_;

}

void TaskManager::update()
{
	std::lock_guard<std::mutex> lock(m_TasksMutex);
	for (auto& task : m_TasksList) {
		if (task.getState() == TaskStatesEnum::InQueue)
		{
			task.startTask();
			notifyOwner("Owner id:" + std::to_string(task.getOwnerId()) + " Task " + std::to_string(task.getId()) + " " + task.getTaskStatusString());
		}	
	}
	m_TasksList.remove_if([&](Task task) {
		if (task.getState() == TaskStatesEnum::Completed || task.getState() == TaskStatesEnum::Failed)
		{
			notifyOwner("Owner id:" + std::to_string(task.getOwnerId()) + " Task " + std::to_string(task.getId()) + " " + task.getTaskStatusString());
			return true;
		}
		else
		{
			return false;
		}
		 });
}

void TaskManager::addTask(int ownerId, int taskId, std::queue<Action*> m_Actions)
{
	std::lock_guard<std::mutex> lock(m_TasksMutex);
	if(m_Actions.empty() || ownerId < 0 || taskId < 0)
	{
		notifyOwner("Owner id:" + std::to_string(ownerId) + " Task " + std::to_string(taskId) + " " + " Rejected");
		WARNING(LogCategoriesEnum::SYSTEM) << "Owner id:" << ownerId << " Task " << taskId << " Rejected";
	}
	m_TasksList.push_back(Task(ownerId, taskId, m_Actions));
}

void TaskManager::notifyOwner(std::string messaage)
{
	INFO(LogCategoriesEnum::RESOURCES) << messaage;
}
