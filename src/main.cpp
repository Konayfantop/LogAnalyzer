#include <fstream>
#include <iostream>
#include "loggenerator/LogGenerator.hpp"
#include "utils/exception/UnsupportedFormatError.hpp"
#include "utils/exception/FileImportError.hpp"

// cmake ..
// cmake --build

int main(int argc, char** argv)
{
    std::cout << "Welcome to log analyzer !" << std::endl;

    // TODO : we need to compose the firstLog even if we didn't manage to parse anything, we should present the error message
    // will try to extract the type of the file passed. By default .txt
    std::string firstLog;
    if(argc == 1)
    {
        firstLog = "[ERROR] : No arguments passed. Nothing to show, will close\n";
        // COMPOSE ERROR
    }
    else if(argc > 2)
    {
        firstLog = "[WARNING]: More arguments passed than expected, will ignore and take into account the first one\n";
        // COMPOSE WARNING
    }
    else
    {
        std::cout << "KSEFTILARA_1 : " << argv[1] << std::endl;

        // TODO : Not nice way to take the argument
        const std::string& aFileName = argv[1];
        loggenerator::LogGenerator aLogGen(aFileName);
        try
        {
            std::ofstream generatedLog = aLogGen.initiateAndGenerateLog();
        }
        catch(const utils::exception::UnsupportedFormatError& e)
        {
            std::cout << "Problem during parsing because of : " << e.whatsWrong() << std::endl;
            // COMPOSE ERROR e.whatsWrong()
        }
        catch(const utils::exception::FileImportError& e)
        {
            std::cout << "Problem at file opening: " << e.whatsWrong() << std::endl;
            // COMPOSE ERROR e.whatsWrong()
        }
    }

    return 0;
}