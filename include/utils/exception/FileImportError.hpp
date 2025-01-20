#pragma once

#include <stdexcept>

namespace utils::exception
{
class FileImportError : public std::runtime_error
{
public:
    explicit FileImportError(const std::string& iMessage) : std::runtime_error(iMessage) {}
    explicit FileImportError(const char* iMessage) : std::runtime_error(iMessage) {}

    const char* whatsWrong() const noexcept
    {
        return std::runtime_error::what();
    }
};
}