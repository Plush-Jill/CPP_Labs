#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <map>



class ReturnerSamples{
private:
    int sampleRate;
    int blockAlign;
    std::map<int, std::ifstream> openFiles;
    std::map<int, size_t> dataIndex;
    std::map<int, std::string> indexWawFiles;
    void checkOpening(unsigned char indexWawFile);
    void openFile(unsigned char indexWawFile);

public:
    ReturnerSamples(std::vector<std::string>& wawFiles);
    void returnSamples(short samplesOnOneSecSecondInputFile[44100], unsigned char indexWawFile, int curSec);

};