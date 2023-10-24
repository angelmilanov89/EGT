#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Logger.h"

#define DEBUG(category) LogStream(category, LogLevelsEnum::DEBUG)
#define INFO(category) LogStream(category, LogLevelsEnum::INFO)
#define WARNING(category) LogStream(category, LogLevelsEnum::WARNING)
#define ERROR(category) LogStream(category, LogLevelsEnum::ERROR)


class LogStream
{
public:
    typedef std::ostream& (*ManipFn)(std::ostream&);
    typedef std::ios_base& (*FlagsFn)(std::ios_base&);

    LogStream() : m_LogLevel(LogLevelsEnum::DEBUG), m_LogCategory(LogCategoriesEnum::GAME){}
    LogStream(LogCategoriesEnum category, LogLevelsEnum level ) :m_LogCategory(category), m_LogLevel(level) {}
    ~LogStream();

    template<class T>
    LogStream& operator<<(const T& output)
    {
        m_Stream << output;
        return *this;
    }

    LogStream& operator<<(ManipFn manip); /// endl, flush, setw, setfill, etc.
    LogStream& operator<<(FlagsFn manip); /// setiosflags, resetiosflags
    LogStream& operator()(LogCategoriesEnum category, LogLevelsEnum );
    void flush();

private:
    std::stringstream  m_Stream;
    LogLevelsEnum      m_LogLevel;
    LogCategoriesEnum  m_LogCategory;

    std::string levelToString(LogLevelsEnum level);
    std::string categoryToString(LogCategoriesEnum category);
    const std::string currentDateTime();
};