#pragma once

#include "../wawFileHeader.h"

#include <string>



class WriteOutFile{
public:
    void writeToOutFile(short samplesOnOneSecByMainInputFile[44100], std::string outWawFile);
    void writeHeader(std::string outFile, TWawFileHeader& header);

};