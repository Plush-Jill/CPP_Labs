#include "editor/wawEditor.h"
#include "applyConverters/applyConverters.h"
#include "exceptions/wrongConfig/wrongConfig.h"
#include "exceptions/wrongConsoleParameters/wrongConsoleParameters.h"
#include "exceptions/failedOpenFile/failedOpenFile.h"
#include "exceptions/wrongFileFormat/wrongFileFormat.h"
#include "modeEnum.h"

#include <iostream>
#include <vector>
#include <string>



int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cerr << "not enough arguments\n";
        return 0;
    }
    std::vector<std::string> arguments(argv, argv + argc);
    try{
        WawEditor editor {arguments};
    }
    catch(WrongConsoleParameters& err){
        std::cerr << err.what() << std::endl;
        return err.returnCode();
    }
    catch (FailedOpenFile& err){
        std::cerr << err.what() << std::endl;
        return err.returnCode();
    }
    catch (WrongConfig& err){
        std::cerr << err.what() << std::endl;
        return err.returnCode();
    }
    catch (WrongFileFormat& err){
        std::cerr << err.what() << std::endl;
        return err.returnCode();
    }
    WawEditor editor{arguments};
    if (editor.returnMode() == EMode::applyConverter){
        try{
            ApplyConverters {editor.allFile(), editor.convOperations()};
        }
        catch (FailedOpenFile& err){
            std::cerr << err.what() << std::endl;
            return err.returnCode();
        }
    }
    return 0;
}