#include "LogAction.h"
#include "LogStream.h"

bool LogAction::doAction()
{
    INFO(LogCategoriesEnum::RESOURCES) << m_Message;
    return true;
}
