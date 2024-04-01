cmake_minimum_required(VERSION 3.23)
project(SoundProcessor)

set(CMAKE_CXX_STANDARD 20)

add_executable(SoundProcessor main.cpp
        applyConverters/applyConverters.cpp applyConverters/applyConverters.h
        createConverter/createConverter.h
        createConverter/createMute/createMute.cpp createConverter/createMute/createMute.h
        createConverter/createMix/createMix.cpp createConverter/createMix/createMix.h
        createConverter/createCensorship/createCensorship.cpp createConverter/createCensorship/createCensorship.h
        editor/wawEditor.cpp editor/wawEditor.h
        exceptions/failedOpenFile/failedOpenFile.cpp exceptions/failedOpenFile/failedOpenFile.h
        exceptions/wrongConfig/wrongConfig.cpp exceptions/wrongConfig/wrongConfig.h
        exceptions/wrongConsoleParameters/wrongConsoleParameters.cpp exceptions/wrongConsoleParameters/wrongConsoleParameters.h
        exceptions/wrongFileFormat/wrongFileFormat.cpp exceptions/wrongFileFormat/wrongFileFormat.h
        iConverter/IConverter.cpp iConverter/IConverter.h
        iConverter/mute/mute.cpp iConverter/mute/mute.h
        iConverter/mix/mix.cpp iConverter/mix/mix.h
        iConverter/censorship/censorship.cpp iConverter/censorship/censorship.h
        parserInputWawFile/parserInputWawFile.cpp parserInputWawFile/parserInputWawFile.h
        returnerSamples/returnerSamples.cpp returnerSamples/returnerSamples.h
        writeOutFile/writeOutFile.cpp writeOutFile/writeOutFile.h
        modeEnum.h wawFileHeader.h)
