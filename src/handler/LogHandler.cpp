#include <ios>
#include <loggenerator/handler/LogHandler.hpp>
#include <utils/exception/FileImportError.hpp>

#include <iostream>
#include <filesystem>

namespace loggenerator::handler{

LogHandler::LogHandler(const std::string& iFilePath)
{
    if(!std::filesystem::exists(iFilePath))
    {
        throw utils::exception::FileImportError("File path provided : " + iFilePath + ", doesn't exist in the repo");
    }

    _file.open(iFilePath, std::ios::in);

    if(!_file.is_open())
    {
        throw utils::exception::FileImportError("Cannot import the file from : " + iFilePath);
    }
}

LogHandler::~LogHandler()
{
    _file.close();
}

}