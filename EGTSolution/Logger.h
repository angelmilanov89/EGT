#pragma once
#include <mutex>
#include <queue>
#include <map>

#include "LogEnums.h"
#include "LogCategory.h"

class Logger
{
    /**
     *Singleton Logger
     */
private:
    static Logger* pinstance_;
    static std::mutex m_LoggerMutex;
    static std::mutex m_CategoryMutex;
    static std::mutex m_LogsQueueMutex;

    std::queue<std::string> m_LogsQueue;
    std::map<LogCategoriesEnum, LogCategory> m_LogCategoriesMap;

    Logger() {}

public:

    Logger(Logger& other) = delete;
    void operator=(const Logger&) = delete;
  
    static Logger* GetInstance();

    void setCategory(LogCategoriesEnum category, const LogCategory& catgory);
    const LogCategory getCategory(LogCategoriesEnum category);
    void addLog(LogCategoriesEnum category, LogLevelsEnum level, std::string message);
};
