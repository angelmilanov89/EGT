#include <thread>
#include "Task.h"
#include "Action.h"
#include "LogStream.h"


void Task::startTask()
{
    setState(TaskStatesEnum::Started);
    auto startWork = [&]()
    {
        while (!m_Actions.empty())
        {
            Action* action = m_Actions.front();
            if (action->doAction())
            {
                m_Actions.pop();
            }
            else
            {
                setState(TaskStatesEnum::Failed);
                ERROR(LogCategoriesEnum::SYSTEM) << "Action Id:" << action->getId() << " Failed ";
            }
            
        }

        setState(TaskStatesEnum::Completed);
    };

    std::thread workerThread(startWork);
    workerThread.detach();
}

void Task::setState(TaskStatesEnum state)
{
    m_State = state;
}

TaskStatesEnum Task::getState()
{
   return m_State;
}

int Task::getOwnerId()
{
    return m_OwnerId;
}

int Task::getId()
{
    return m_Id;
}


std::string Task::getTaskStatusString()
{
    switch (m_State)
    {
    case TaskStatesEnum::Completed:
    {
        return "Completed";
    }
    break;
    case TaskStatesEnum::Failed:
    {
        return "Failed";
    }
    break;
    case TaskStatesEnum::InQueue:
    {
        return "InQueue";
    }
    break;    
    break;
    case TaskStatesEnum::Started:
    {
        return "Started";
    }
    break;
    case TaskStatesEnum::Rejected:
    {
        return "Rejected";
    }
    break;
    default:
    {
        return "";
    }
    break;
    }

}
