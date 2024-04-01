#include "TheLifeGameCreator.h"
#include "../Exceptions/TheLifeGameExceptions.h"
#include <memory>
#include <string>
#include <iostream>
#include <fstream>


void TheLifeGameCreator::getUniverse(const std::string& life){
    std::fstream saveFile(life);

    if (!saveFile.is_open()){
        throw SaveFileException("Save file isn't open.");
    }
    std::string firstString;
    std::getline(saveFile, firstString, '\n');

    if (firstString != "#Life 1.06"){
        throw ReadingSaveFileException("File isn't #Life 1.06 format.");
    }

    for (int i {}; i < 2 && readNameOrRules(saveFile); ++i);
    readCellsCoordinates(saveFile);
    calculateAndSetFieldSize();

    ///дальше нужно будет прочитать из открытого файла и записать в this->....
}
void TheLifeGameCreator::readCellsCoordinates(std::fstream& saveFile){
    int x;
    int y;

    this->aliveCells.clear();
    while (saveFile >> x >> y){
        this->aliveCells.emplace_back(x, y);
    }
}
bool TheLifeGameCreator::readNameOrRules(std::fstream& saveFile){
    std::streampos currentPosition = saveFile.tellg();
    std::string otherString1;
    std::getline(saveFile, otherString1, ' ');

    try{
        if (std::isdigit(otherString1[0])){
            throw ReadingSaveFileException();
        }
    }catch (ReadingSaveFileException& exc){
        saveFile.seekg(currentPosition);
        return false;
    }

    std::string otherString2;
    if (otherString1[1] == 'N'){
        std::getline(saveFile, otherString2, '\n');
        this->universeName = otherString2;
    }else if (otherString1[1] == 'R'){
        std::getline(saveFile, otherString2, '/');
        if (otherString2[0] != 'B'){
            throw ReadingSaveFileException("Wrong #parameter in file.");
        }
        this->neighboursToBirth.clear();
        for (int i = 1; i < otherString2.size(); ++i){
            this->neighboursToBirth.insert(otherString2[i] - '0');
        }
        std::getline(saveFile, otherString2, '\n');
        if (otherString2[0] != 'S'){
            throw ReadingSaveFileException("Wrong #parameter in file.");
        }
        this->neighboursToSurvive.clear();
        for (int i = 1; i < otherString2.size(); ++i){
            this->neighboursToSurvive.insert(otherString2[i] - '0');
        }
    }else{
        throw ReadingSaveFileException("Unknown save file error, kys.");
    }


    return true;
}
std::shared_ptr<Controller> TheLifeGameCreator::createGame(){
    return std::make_shared<Controller>(this->universeName,
                                        this->neighboursToBirth,
                                        this->neighboursToSurvive,
                                        this->aliveCells,
                                        this->fieldSize,
                                        this->currentTick);
}
void TheLifeGameCreator::makeCoordinatesByFieldSizeModule(){
    int greatestMinusX = INT_MAX;
    int greatestMinusY = INT_MAX;
    for (auto& x : this->aliveCells){
        greatestMinusX = x.first < greatestMinusX ? x.first : greatestMinusY;
        greatestMinusY = x.second < greatestMinusY ? x.second : greatestMinusY;
    }
    std::cerr << "greatestMinusX: " << greatestMinusX << std::endl;
    std::cerr << "greatestMinusY: " << greatestMinusY << std::endl;
    bool xLowerThenZero = greatestMinusX < 0;
    bool yLowerThenZero = greatestMinusY < 0;

    greatestMinusX = - greatestMinusX;
    greatestMinusY = - greatestMinusY;

    for (auto& x : this->aliveCells){
        if (xLowerThenZero){
            x.first += greatestMinusX;
        }
        if (yLowerThenZero){
            x.second += greatestMinusY;
        }
    }
}
TheLifeGameCreator::TheLifeGameCreator(){}
void TheLifeGameCreator::printAllInfo() {
    std::cout << "ALL SAVE INFO:" << std::endl;
    std::cout << "#Life 1.06" << std::endl;
    std::cout << "#N " + this->universeName << std::endl;
    std::cout << "#R B";
    for (auto& x : this->neighboursToBirth){
        std::cout << x;
    }
    std::cout << "/S";
    for (auto& x : this->neighboursToSurvive){
        std::cout << x;
    }
    std::cout << std::endl;
    for (auto& x : this->aliveCells){
        std::cout << x.first << ' ' << x.second << std::endl;
    }
    std::cout << "=======================" << std::endl;
}
void TheLifeGameCreator::calculateAndSetFieldSize(){
    int greatestX = INT_MIN;
    int greatestY = INT_MIN;
    int lowestX = INT_MAX;
    int lowestY = INT_MAX;

    for (auto& x : this->aliveCells){
        greatestX = x.first > greatestX ? x.first : greatestX;
        greatestY = x.second > greatestY ? x.second : greatestY;

        lowestX = x.first < lowestX ? x.first : lowestX;
        lowestY = x.second < lowestY ? x.second : lowestY;
    }

    int yDifference = greatestY - lowestY;
    int xDifference = greatestX - lowestX;
    int greatestCoordinatesDifference = xDifference > yDifference ? xDifference : yDifference;
    this->fieldSize = greatestCoordinatesDifference + 10;
}
TheLifeGameCreator::TheLifeGameCreator(const std::string& save){
    getUniverse(save);
}
void TheLifeGameCreator::loadGame(std::shared_ptr<Controller>* controller) {
    std::string command;
    std::cout << "Enter save file." << std::endl;
    std::cin >> command;
    try{
        getUniverse(command);
    }catch (ReadingSaveFileException &exception){
        std::cerr << exception.what() << std::endl;
        std::cout << "File doesn't match the format, "
                     "enter \"load\" again and enter another file." << std::endl;
        throw ShallContinueException();
    }catch (SaveFileException &exception){
        std::cerr << exception.what() << std::endl;
        std::cout << "File doesn't match the format, "
                     "enter \"load\" again and enter another file." << std::endl;
        throw ShallContinueException();
    }catch (std::exception &exception){
        throw;
    }
    *controller = createGame();
}