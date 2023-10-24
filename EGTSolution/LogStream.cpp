#include "LogStream.h"


LogStream::~LogStream()
{
    flush();
}

LogStream& LogStream::operator<<(ManipFn manip) /// endl, flush, setw, setfill, etc.
{
    manip(m_Stream);

    if (manip == static_cast<ManipFn>(std::flush)
        || manip == static_cast<ManipFn>(std::endl))
        this->flush();

    return *this;
}

LogStream& LogStream::operator<<(FlagsFn manip) /// setiosflags, resetiosflags
{
    manip(m_Stream);
    return *this;
}

LogStream& LogStream::operator()(LogCategoriesEnum category, LogLevelsEnum level)
{
    m_LogLevel = level;
    m_LogCategory = category;
    return *this;
}

void LogStream::flush()
{


    std::string message = "["+ categoryToString(m_LogCategory) +"]"+ "[" + levelToString(m_LogLevel) + "]["+ currentDateTime() + "]: " + m_Stream.str();
    m_Stream.clear();

    Logger::GetInstance()->addLog(m_LogCategory, m_LogLevel, message);
 
}



std::string LogStream::levelToString(LogLevelsEnum level)
{
    switch (level)
    {
        case LogLevelsEnum::DEBUG:
        {
            return "DEBUG";
        }
        break;
        case LogLevelsEnum::INFO:
        {
            return "INFO";
        }
        break;
        case LogLevelsEnum::WARNING:
        {
            return "WARNING";
        }
            break;
        case LogLevelsEnum::ERROR:
        {
            return "ERROR";
        }
            break;
        default:
        {
            return "";
        }
            break;
    }
}

std::string LogStream::categoryToString(LogCategoriesEnum category)
{
    switch (category)
    {
        case LogCategoriesEnum::GAME:
        {
            return "GAME";
        }
        break;
        case LogCategoriesEnum::RESOURCES:
        {
            return "RESOURCES";
        }
        break;
        case LogCategoriesEnum::SYSTEM:
        {
            return "SYSTEM";
        }
        break;
        default:
        {
            return "";
        }
        break;
    }

}

const std::string LogStream::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    localtime_s(&tstruct, &now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}