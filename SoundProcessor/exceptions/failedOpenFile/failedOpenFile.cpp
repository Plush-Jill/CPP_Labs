#include "failedOpenFile.h"



FailedOpenFile::FailedOpenFile(std::string err) {
    this->err = err;
}
const char* FailedOpenFile::what() const noexcept {
    return err.data();
}
const int FailedOpenFile::returnCode() const noexcept {
    return 3;
}