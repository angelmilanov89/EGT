#include "FSMState1.h"
#include "FSMState2.h"
#include "FSM.h"
#include "LogStream.h"

FSMState1* FSMState1::pinstance_{ nullptr };
std::mutex FSMState1::m_FSMState1Mutex;

void FSMState1::enter(FSM* fms)
{
}

void FSMState1::update(FSM* fms, int frame)
{
    if (frame == 1)
    {
        fms->setState(*FSMState2::getInstance());
        INFO(LogCategoriesEnum::GAME)<< "Changed state from FSMState1 to FSMState2 at frame " << frame+1;
    }

}

void FSMState1::exit(FSM* fms)
{
}

FSMState1* FSMState1::getInstance()
{
    std::lock_guard<std::mutex> lock(m_FSMState1Mutex);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new FSMState1();

    }
    return pinstance_;
}

