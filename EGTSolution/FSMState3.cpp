#include "FSMState3.h"
#include "FSMState2.h"
#include "FSM.h"
#include "LogStream.h"

FSMState3* FSMState3::pinstance_{ nullptr };
std::mutex FSMState3::m_FSMState3Mutex;

void FSMState3::enter(FSM* fms)
{
}

void FSMState3::update(FSM* fms, int frame)
{
    if (frame == 3)
    {
        fms->setState(*FSMState2::getInstance());
        INFO(LogCategoriesEnum::GAME) << "Changed state from FSMState3 to FSMState2 at frame " << frame + 1;
    }
}

void FSMState3::exit(FSM* fms)
{
}

FSMState3* FSMState3::getInstance()
{
    std::lock_guard<std::mutex> lock(m_FSMState3Mutex);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new FSMState3();


    }
    return pinstance_;
}

