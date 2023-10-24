#include "Logger.h"
#include <iostream>
#include <fstream>

const int g_LOG_FLUSH_LIMIT = 10;

Logger* Logger::pinstance_{ nullptr };
std::mutex Logger::m_LoggerMutex;
std::mutex Logger::m_CategoryMutex;
std::mutex Logger::m_LogsQueueMutex;

Logger* Logger::GetInstance()
{
    std::lock_guard<std::mutex> lock(m_LoggerMutex);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Logger();
        pinstance_->setCategory(LogCategoriesEnum::GAME, LogCategory());
        pinstance_->setCategory(LogCategoriesEnum::SYSTEM, LogCategory());
        pinstance_->setCategory(LogCategoriesEnum::RESOURCES, LogCategory());

    }
    return pinstance_;
}

void Logger::setCategory(LogCategoriesEnum category, const LogCategory& config)
{
    std::lock_guard<std::mutex> lock(m_CategoryMutex);
    m_LogCategoriesMap[category] = config;
}

const LogCategory Logger::getCategory(LogCategoriesEnum category)
{
    std::lock_guard<std::mutex> lock(m_CategoryMutex);
    auto configItr = m_LogCategoriesMap.find(category);
    if (configItr != m_LogCategoriesMap.end())
    {
        return configItr->second;
    }
    else
    {
        return LogCategory();
    }
}


void Logger::addLog(LogCategoriesEnum category, LogLevelsEnum level, std::string message)
{
    const LogCategory categoryConfig = getCategory(category);

    if (level >= categoryConfig.getMinLogLevel())
    {
        std::lock_guard<std::mutex> lock(m_LogsQueueMutex);
        std::cout << message << std::endl;

        m_LogsQueue.push(message);
        if (m_LogsQueue.size() >= g_LOG_FLUSH_LIMIT)
        {
            std::ofstream logFile("log.txt", std::fstream::app);
            while (!m_LogsQueue.empty())
            {
                logFile << m_LogsQueue.front() << std::endl;
                m_LogsQueue.pop();
            }

            logFile.close();
        }
    }
    

}
