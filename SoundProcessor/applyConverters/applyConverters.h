#pragma once

#include <string>
#include <map>

#include "../wawFileHeader.h"
#include "../editor/wawEditor.h"
#include "../returnerSamples/returnerSamples.h"
#include "../writeOutFile/writeOutFile.h"

class ApplyConverters{
private:
    WriteOutFile writeOutFile;
    ReturnerSamples returnerSamples;
    void applyOperations(std::vector<std::string>& wawFiles, std::vector<std::shared_ptr<IConverter>>& converters);


public:

    ApplyConverters(std::vector<std::string>& wawFiles, std::vector<std::shared_ptr<IConverter>>& converters);

};