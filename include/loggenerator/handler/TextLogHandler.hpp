#pragma once

#include <loggenerator/handler/LogHandler.hpp>

namespace loggenerator::handler
{
class TextLogHandler : public LogHandler
{
public:
    TextLogHandler(const std::string& iFilePath);
    virtual ~TextLogHandler() = default;
protected:
    virtual void parseFileAndFillMap() override;
    virtual void emprintIntoFile() override;
};

}