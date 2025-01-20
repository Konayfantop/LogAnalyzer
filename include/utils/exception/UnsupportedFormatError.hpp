#pragma once

#include <stdexcept>

namespace utils::exception
{
class UnsupportedFormatError : public std::runtime_error
{
public:
    explicit UnsupportedFormatError(const std::string& iMessage) : std::runtime_error(iMessage) {}
    explicit UnsupportedFormatError(const char* iMessage) : std::runtime_error(iMessage) {}

    const char* whatsWrong() const noexcept
    {
        return std::runtime_error::what();
    }
};
}