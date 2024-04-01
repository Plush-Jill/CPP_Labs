#include "wrongFileFormat.h"



WrongFileFormat::WrongFileFormat(std::string err) {
    this->err = err;
}
const char* WrongFileFormat::what() const noexcept {
    return err.data();
}
const int WrongFileFormat::returnCode() const noexcept {
    return 4;
}