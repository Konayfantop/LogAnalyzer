#pragma once

#include <string>

namespace loggenerator
{

class LogGenerator
{
public:
    LogGenerator(const std::string& iPath, const std::string& iType);
    ~LogGenerator() = default;

    void initiate();

private:
    const std::string& _inputType;
    const std::string& _path;
};

}