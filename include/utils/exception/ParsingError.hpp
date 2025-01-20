#pragma once

#include <stdexcept>

namespace utils::exception
{
class ParsingError : public std::runtime_error
{
public:
    explicit ParsingError(const std::string& iMessage) : std::runtime_error(iMessage) {}
    explicit ParsingError(const char* iMessage) : std::runtime_error(iMessage) {}

    const char* whatsWrong() const noexcept
    {
        return std::runtime_error::what();
    }
};
}