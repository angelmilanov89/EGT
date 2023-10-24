// EGTSolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LogStream.h"
#include "TaskManager.h"
#include "WaitAction.h"
#include "LogAction.h"
#include "FSM.h"

int main()
{
    Logger::GetInstance()->setCategory(LogCategoriesEnum::GAME, LogCategory(LogLevelsEnum::INFO));
    DEBUG(LogCategoriesEnum::SYSTEM) << "TEST DEBUG " << 1;
    INFO(LogCategoriesEnum::SYSTEM) << "TEST INFO " << 2;
    WARNING(LogCategoriesEnum::SYSTEM) << "TEST WARNING " << 3;
    ERROR(LogCategoriesEnum::SYSTEM) << "TEST ERROR " << 4;

    std::queue<Action*> actionQueue;
    actionQueue.push(new LogAction("Start"));
    actionQueue.push(new WaitAction(3));
    actionQueue.push(new LogAction("Done"));
    TaskManager::GetInstance()->addTask(1, 1, actionQueue);

    std::queue<Action*> actionQueue2;
    actionQueue2.push(new LogAction("Hey"));
    TaskManager::GetInstance()->addTask(2, 2, actionQueue2);

    std::queue<Action*> actionQueue3;
    actionQueue3.push(new LogAction("3"));
    actionQueue3.push(new WaitAction(1));
    actionQueue3.push(new LogAction("2"));
    actionQueue3.push(new WaitAction(1));
    actionQueue3.push(new LogAction("1"));
    actionQueue3.push(new LogAction("BOOM"));
    TaskManager::GetInstance()->addTask(3, 3, actionQueue3);

    TaskManager::GetInstance()->addTask(-1, 4, actionQueue2);
    TaskManager::GetInstance()->addTask(-4, -1, actionQueue2);

    FSM fsm = FSM();
    int frame = 0;
    while (true)
    {
        fsm.update(frame);
        TaskManager::GetInstance()->update();
        ++frame;
    }

}