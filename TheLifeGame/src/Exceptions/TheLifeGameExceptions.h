#pragma once
#include <string>
#include <utility>


/// Различные исключения, позже доработаю и раскидаю по проекту.

class TheLifeGameException : public std::exception{
private:
    std::string message_ {};
public:
    ~TheLifeGameException() override = default;
    explicit TheLifeGameException(std::string  message) : message_(std::move(message)) {}
    virtual const char* what() const noexcept{
        return message_.c_str();
    }
    explicit TheLifeGameException() = default;

};

class CellException : public TheLifeGameException{
public:
    explicit CellException(std::string message) : TheLifeGameException (std::move(message)){}
    CellException() = default;
};
class LifeCreatorException : public TheLifeGameException{
public:
    explicit LifeCreatorException(std::string message) : TheLifeGameException (std::move(message)){}
    LifeCreatorException() = default;
};
class ControllerException : public TheLifeGameException{
public:
    explicit ControllerException(std::string message) : TheLifeGameException (std::move(message)){}
    ControllerException() = default;
};
class ViewerException : public TheLifeGameException{
public:
    explicit ViewerException(std::string message) : TheLifeGameException (std::move(message)){}
    ViewerException() = default;
};
class GameFieldException : public TheLifeGameException{
public:
    explicit GameFieldException(std::string message) : TheLifeGameException (std::move(message)){}
    GameFieldException() = default;
};
class SaveFileException : public LifeCreatorException{
public:
    explicit SaveFileException(std::string message) : LifeCreatorException (std::move(message)){}
    SaveFileException() = default;
};
class ReadingSaveFileException : public SaveFileException{
public:
    explicit ReadingSaveFileException(std::string message) : SaveFileException (std::move(message)){}
    ReadingSaveFileException() = default;
};
class CommandExecutingException : public ControllerException{
public:
    explicit CommandExecutingException(std::string message) : ControllerException (std::move(message)){}
    CommandExecutingException() = default;
};
class ShallContinueException : public CommandExecutingException{
public:
    explicit ShallContinueException(std::string message) : CommandExecutingException (std::move(message)){}
    ShallContinueException() = default;
};
class ExitException : public CommandExecutingException{
public:
    explicit ExitException(std::string message) : CommandExecutingException (std::move(message)){}
    ExitException() = default;
};