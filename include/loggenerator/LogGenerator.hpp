#pragma once

#include <string>
#include <memory>

namespace loggenerator
{

namespace handler
{
class LogHandler;
}

class LogGenerator
{
public:
    explicit LogGenerator(const std::string& iFileName);
    ~LogGenerator() = default;

    std::ofstream initiateAndGenerateLog();

private:
    void separateInputToNameAndType(std::string& oFileName, std::string& oFileType);
    std::unique_ptr<loggenerator::handler::LogHandler> filterOutUnsupportedTypesAndComposeNewHandler(
        const std::string& aFileName,
        const std::string& iFileType);

private:
    const std::string& _file;
};

}