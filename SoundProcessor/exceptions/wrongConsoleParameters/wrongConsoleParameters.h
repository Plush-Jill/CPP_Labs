#pragma once

#include <exception>
#include <string>



class WrongConsoleParameters : std::exception{
private:
    std::string err;

public:
    WrongConsoleParameters(std::string err);
    const char* what() const noexcept override;
    const int returnCode() const noexcept;

};