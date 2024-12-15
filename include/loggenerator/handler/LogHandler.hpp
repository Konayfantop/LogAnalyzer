#pragma once

#include <chrono>
#include <fstream>
#include <string>
#include <map>

namespace loggenerator::handler{

class LogHandler
{
public:
    LogHandler() = delete;
    explicit LogHandler(const std::string& iFilePath);
    virtual ~LogHandler();

protected:
    virtual void parseFileAndFillMap() = 0;
    virtual void emprintIntoFile() = 0;
private:
    std::map<std::chrono::system_clock::time_point, std::string> _timeToLog;
    std::ifstream _file;
};
}