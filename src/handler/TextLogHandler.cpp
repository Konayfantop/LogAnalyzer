#include <iostream>
#include <loggenerator/handler/TextLogHandler.hpp>

#include "loggenerator/handler/LogHandler.hpp"

namespace loggenerator::handler
{

TextLogHandler::TextLogHandler(const std::string& iFilePath) : LogHandler(iFilePath) {}

void TextLogHandler::start()
{
    std::string aa;
    while(std::getline(_file, aa))
    {
        std::cout << aa << std::endl;
    }
}

void TextLogHandler::parseFileAndFillMap()
{

}
    
void TextLogHandler::emprintIntoFile()
{

}

}