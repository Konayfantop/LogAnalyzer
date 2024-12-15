#include <ios>
#include <loggenerator/handler/LogHandler.hpp>

#include <iostream>

namespace loggenerator::handler{

LogHandler::LogHandler(const std::string& iFilePath)
{
    _file.open(iFilePath, std::ios::in);
    if(!_file.is_open())
    {
        std::cout << "Couldn't import the file from : " << iFilePath << ", file content won't be analyzed" << std::endl;
        throw std::ios_base::failure("Cannot open file: " + iFilePath);
    }
}

LogHandler::~LogHandler()
{
    _file.close();
}

}