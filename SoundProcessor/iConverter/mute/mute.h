#pragma once

#include "../IConverter.h"

#include <string>


class Mute : public IConverter{
private:
    int startTime;
    int endTime;
    unsigned char indexWawFile;
    bool checkTime(int curSec);

public:
    void initParams(std::string params) override;
    void change(short samplesOnOneSecByMainInputFile[44100], ReturnerSamples& returnerSamples, int curSec) override;
    void info() override;

};