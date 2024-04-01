#pragma once

#include <exception>
#include <string>



class WrongFileFormat : std::exception{
private:
    std::string err;

public:
    WrongFileFormat(std::string err);
    const char* what() const noexcept override;
    const int returnCode() const noexcept;

};