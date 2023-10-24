#include "FSMState2.h"
#include "FSMState1.h"
#include "FSMState3.h"
#include "FSM.h"
#include "LogStream.h"

FSMState2* FSMState2::pinstance_{ nullptr };
std::mutex FSMState2::m_FSMState2Mutex;

void FSMState2::enter(FSM* fms)
{
}

void FSMState2::update(FSM* fms, int frame)
{
    if (frame == 2)
    {
        fms->setState(*FSMState3::getInstance());
        INFO(LogCategoriesEnum::GAME) << "Changed state from FSMState2 to FSMState3 at frame " << frame + 1;
    }
    else if (frame == 6)
    {
        fms->setState(*FSMState1::getInstance());
        INFO(LogCategoriesEnum::GAME) << "Changed state from FSMState2 to FSMState1 at frame " << frame + 1;
    }
}

void FSMState2::exit(FSM* fms)
{
}

FSMState2* FSMState2::getInstance()
{
    std::lock_guard<std::mutex> lock(m_FSMState2Mutex);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new FSMState2();


    }
    return pinstance_;
}
