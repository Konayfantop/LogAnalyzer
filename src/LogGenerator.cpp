#include "loggenerator/LogGenerator.hpp"
#include "loggenerator/handler/LogHandler.hpp"
#include "loggenerator/handler/TextLogHandler.hpp"
#include "utils/exception/UnsupportedFormatError.hpp"

//std
#include <memory>
#include <unordered_set>

namespace loggenerator
{
static const std::unordered_set<std::string> kSupportedFileTypes{"txt"};

LogGenerator::LogGenerator(const std::string& iTestPath, const std::string& iType) : _path(iTestPath), _inputType(iType) {}

void LogGenerator::initiate()
{
    const std::unordered_set<std::string>::const_iterator aSupportedFileTypeIter = kSupportedFileTypes.find(_inputType);
    // TODO : Among other things we should also include the fact that
    if(aSupportedFileTypeIter == kSupportedFileTypes.end())
    {
        throw utils::exception::UnsupportedFormatError(
            "Wrong file type or the content is not compliant with the file type which in the end it's not supported either");
        return;
    }

    std::unique_ptr<handler::LogHandler> aLogHandler;
    if(*aSupportedFileTypeIter == "txt")
    {
        aLogHandler = std::make_unique<handler::TextLogHandler>(_path);
    }
}

}