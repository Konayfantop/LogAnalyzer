#include <exception>
#include <iostream>
#include <array>
#include <sstream>
#include "loggenerator/LogGenerator.hpp"
#include "utils/exception/UnsupportedFormatError.hpp"

// cmake ..
// cmake --build



int main(int argc, char** argv)
{
    std::cout << "Welcome to log analyzer !" << std::endl;
    std::cout << "An initiation from Kostas, simply to learn stuff !" << std::endl;

    //will try to extract the type of the file passed. By default .txt
    std::string firstLog;
    if(argc == 1)
    {
        firstLog = "[ERROR] : No arguments passed. Nothing to show, will close\n";
    }
    else if(argc > 2)
    {
        firstLog = "[WARNING]: More arguments passed than expected, will ignore and take into account the first one\n";
    }
    else
    {
        const std::string aFileNameWithExtension = argv[1];
        const std::size_t index = aFileNameWithExtension.find('.');
        if(index != std::string::npos)
        {
            std::array<std::string, 2> aTypeAndFileName;
            std::istringstream ss{aFileNameWithExtension};
            std::getline(ss, aTypeAndFileName[0], '.');
            std::getline(ss, aTypeAndFileName[1], '.');

            loggenerator::LogGenerator aLogGen(aTypeAndFileName[0], aTypeAndFileName[1]);
            try
            {
                aLogGen.initiate();
            }
            catch(utils::exception::UnsupportedFormatError& e)
            {
                std::cout << "Problem during parsing because of : " << e.whatsWrong() << std::endl;
            }
        }
    }

    return 0;
}