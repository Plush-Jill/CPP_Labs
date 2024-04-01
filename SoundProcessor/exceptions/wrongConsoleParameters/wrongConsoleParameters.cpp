#include "wrongConsoleParameters.h"



WrongConsoleParameters::WrongConsoleParameters(std::string err) {
    this->err = err;
}
const char* WrongConsoleParameters::what() const noexcept {
    return err.data();
}
const int WrongConsoleParameters::returnCode() const noexcept {
    return 2;
}