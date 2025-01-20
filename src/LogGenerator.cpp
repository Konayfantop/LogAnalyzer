#include "loggenerator/LogGenerator.hpp"
#include "loggenerator/handler/LogHandler.hpp"
#include "loggenerator/handler/TextLogHandler.hpp"
#include "utils/exception/ParsingError.hpp"
#include "utils/exception/UnsupportedFormatError.hpp"

//std
#include <filesystem>
#include <fstream>
#include <memory>
#include <string>
#include <unordered_set>
#include <sstream>

namespace loggenerator
{
LogGenerator::LogGenerator(const std::string& iFileName) : _file(iFileName) {}

std::ofstream LogGenerator::initiateAndGenerateLog()
{
    std::string aFileName, aFileType;
    separateInputToNameAndType(aFileName, aFileType);
    std::unique_ptr<loggenerator::handler::LogHandler> aHandler = filterOutUnsupportedTypesAndComposeNewHandler(aFileName, aFileType);

    aHandler->start();
}

void LogGenerator::separateInputToNameAndType(std::string& oFileName, std::string& oFileType)
{
    const std::size_t index = _file.find('.');
    if(index == std::string::npos)
    {
        throw utils::exception::ParsingError("Could not find the \".\" separator, no parsing will be taken place");
    }

    if(index != std::string::npos)
    {
        std::istringstream ss{_file};
        std::getline(ss, oFileName, '.');
        std::getline(ss, oFileType, '.');
    }
}

std::unique_ptr<loggenerator::handler::LogHandler> LogGenerator::filterOutUnsupportedTypesAndComposeNewHandler(
    const std::string& iFileName,
    const std::string& iFileType)
{
    static const std::unordered_set<std::string> kSupportedFileTypes{"txt"};

    const std::unordered_set<std::string>::const_iterator aSupportedFileTypeIter = kSupportedFileTypes.find(iFileType);
    if(aSupportedFileTypeIter == kSupportedFileTypes.end())
    {
        throw utils::exception::UnsupportedFormatError(
            "Wrong file type or the content is not compliant with the file type which in the end it's not supported either");
    }

    // WE SHOULD ALSO OPEN THE FILE IN READ MODE AND CHECK THE ACTUAL FORMAT CAUSE SOMETHING IT MAY COME WITH .txt BUT IT MAY BE JSON FOR INSTANCE
    // TODO : WHEN I WILL HAVE WILLINGNESS TO STUDY THE VARIOUS FORMATS
    // FOR THE MOMENT IT WILL BE EQUAL WITH THE EXTENSION OF THE FILE WE FOUND
    // const std::string aIsFileFormatSameAsParsedType = *aSupportedFileTypeIter == checkFileFormat();

    // set-up properly the system's dir path
    std::filesystem::path aPath = std::filesystem::current_path();
    aPath = aPath.parent_path();

    if(*aSupportedFileTypeIter == "txt")
    {
        std::unique_ptr<loggenerator::handler::LogHandler> aTextHandler
            = std::make_unique<loggenerator::handler::TextLogHandler>((aPath.string() + "/" + iFileName + "." + iFileType));
        return aTextHandler;
    }

    return std::unique_ptr<loggenerator::handler::LogHandler>{};
}

}