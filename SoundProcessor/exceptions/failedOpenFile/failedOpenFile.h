#pragma once

#include <exception>
#include <string>



class FailedOpenFile : std::exception{
private:
    std::string err;

public:
    FailedOpenFile(std::string err);
    const char* what() const noexcept override;
    const int returnCode() const noexcept;

};