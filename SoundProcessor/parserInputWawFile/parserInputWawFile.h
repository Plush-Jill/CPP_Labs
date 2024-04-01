#pragma once

#include "../wawFileHeader.h"

#include <string>



class ParserInputWawFile{
private:
    void fillConstantFields(TWawFileHeader& header);
    void fillFromInputFileFields(std::string inputWawFile, TWawFileHeader& header);
    void defineSubChunk2Size(char subChunk2Size[4], TWawFileHeader& header);
    unsigned long fromCharArrayToInt(char array[4]);
    void defineChunkSize(TWawFileHeader& header);
    void defineByteRate(TWawFileHeader& header);

public:
    TWawFileHeader returnHeader(std::string inputWawFile);
    int defineDate(std::ifstream& file);

};