#include "wawEditor.h"
#include "../createConverter/createMute/createMute.h"
#include "../createConverter/createMix/createMix.h"
#include "../createConverter/createCensorship/createCensorship.h"
#include "../exceptions/wrongConfig/wrongConfig.h"
#include "../exceptions/wrongConsoleParameters/wrongConsoleParameters.h"
#include "../exceptions/failedOpenFile/failedOpenFile.h"
#include "../exceptions/wrongFileFormat/wrongFileFormat.h"

#include <sstream>


WawEditor::WawEditor(std::vector<std::string> arguments){
    initConverters();

    try{
        mode = determineMode(arguments[1]);
    }
    catch (FailedOpenFile& exception){
        throw exception;
    }
    if (mode == EMode::applyConverter){
        std::string config = arguments[2];
        for (int i = 3; i < arguments.size(); ++i){
            if (arguments[i].find("wav") == std::string::npos){
                throw WrongFileFormat{"it's not wav file: " + arguments[i]};
            }
            wawFile.push_back(arguments[i]);
        }
        try {
            readConfig(config);
        }
        catch (FailedOpenFile& err){
            throw err;
        }
        catch (WrongConfig& err){
            throw err;
        }
    }
    else if (mode == EMode::help){
        printInfoConv();
    }

}
void WawEditor::printInfoConv() {
    for (auto conv : creatorConverters){
        conv.second->create()->info();
    }
}
EMode WawEditor::determineMode(std::string mode) const{
    if (mode == "-c") {
        return EMode::applyConverter;
    }
    else if (mode == "-h") {
        return EMode::help;
    }
    else{
        throw WrongConsoleParameters {"wrong mode" };
    }
}
void WawEditor::readConfig(std::string config) {
    std::ifstream file(config);
    if (file.is_open()){
        std::string line;
        while (std::getline(file, line)) {
            try {
                addOperation(line);
            }
            catch(WrongConfig& err) {
                throw err;
            }
        }
        file.close();
    }
    else {
        throw FailedOpenFile {"can't to open the file " + config};
    }
}
void WawEditor::initConverters() {
    creatorConverters["mute"] = std::make_shared<CreateMute>();
    creatorConverters["mix"] = std::make_shared<CreateMix>();
    creatorConverters["censorship"] = std::make_shared<CreateCensorship>();
}
void WawEditor::addOperation(std::string line) {
    std::stringstream ss(line);
    std::string mode;
    std::string param;
    ss >> mode;
    if (mode == "") {
        throw WrongConfig{ "no converter" };
    }
    auto it = creatorConverters.find(mode);
    if (it != creatorConverters.end()){
        try{
            std::shared_ptr<IConverter> converter = it->second->create();
            converter->initParams(line);
            converters.push_back(converter);
        }
        catch (WrongConfig& err) {
            throw err;
        }
    }
    else {
        throw WrongConfig{ "wrong converter " + mode };
    }
}
std::vector<std::shared_ptr<IConverter>>& WawEditor::convOperations()  {
    return converters;
}
std::vector<std::string>& WawEditor::allFile()  {
    return wawFile;
}
EMode WawEditor::returnMode() {
    return mode;
}