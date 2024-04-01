#include "../Controller/Controller.h"
#include "../Exceptions/TheLifeGameExceptions.h"
#include "../Cell/Cell.h"
#include <iostream>
#include <memory>
#include <string>



void Controller::setField(const std::string& universeName,
                          const std::set<int>& neighboursToBirth,
                          const std::set<int>& neighboursToSurvive,
                          const std::vector<std::pair<int, int>>& aliveCells,
                          int fieldSize,
                          int currentTick){

    this->field->setField(universeName,
                          neighboursToBirth,
                          neighboursToSurvive,
                          aliveCells,
                          fieldSize,
                          currentTick);
}
int Controller::getCurrentTickNumber() const{
    return this->field->getCurrentTickNumber();
}
void Controller::saveInFIle(std::string& fileName) const{
    std::ofstream output (fileName);
    output << "#Life 1.06\n#N " << getName() << std::endl;
    output << "#R B";
    for (int x : getNeighboursToBirth()){
        output << x;
    }
    output << "/S";
    for (int x : getNeighboursToSurvive()){
        output << x;
    }
    output << std::endl;

    printAliveCells(output);
}
std::string Controller::getName() const{
    return this->field->getNameInField();
}
std::set<int> Controller::getNeighboursToBirth() const{
    return this->field->getNeighboursToBirthInField();
}
std::set<int> Controller::getNeighboursToSurvive() const{
    return this->field->getNeighboursToSurviveInField();
}
void Controller::getTicksWithDraw(int nTicks){
    for (int i {}; i < nTicks; ++i){
        std::cout << this->getCurrentTickNumber() << "'th tick: " << std::endl;
        nextTick();
        //system("cls");
        this->viewer->drawField();
    }
}
void Controller::getTicksWithoutDraw(int nTicks){
    for (int i {}; i < nTicks; ++i){
        nextTick();
    }
}
const std::vector<std::vector<Cell*>>& Controller::getAliveCells() const{
    return this->field->getAliveCells();
}
void Controller::nextTick(){
    this->field->nextTick();
}
Controller::Controller() = default;
Controller::Controller(const std::shared_ptr<GameField>& field, const std::shared_ptr<Viewer>& viewer){
    this->field = std::make_shared<GameField>();
    this->viewer = std::make_shared<Viewer>(this->field);
}
void Controller::drawField(){
    this->viewer->drawField();
}

Controller::Controller(const std::string &universeName,
                       const std::set<int> &neighboursToBirth,
                       const std::set<int> &neighboursToSurvive,
                       const std::vector<std::pair<int, int>> &aliveCells,
                       int fieldSize,
                       int currentTick){
    this->field = std::make_shared<GameField>(universeName,
                                              neighboursToBirth,
                                              neighboursToSurvive,
                                              aliveCells,
                                              fieldSize,
                                              currentTick);
    this->viewer = std::make_shared<Viewer>(this->field);
}
void Controller::executeCommand(std::string &command){
    //std::cout << "Executing command." << std::endl;
    if (command.find("tick") != std::string::npos){
        //std::cout << "Executing tick." << std::endl;
        if (!command.substr(4, command.size() - 4).empty()){
            std::cout << std::stoi((command.substr(4, command.size() - 4))) << std::endl;
            getTicksWithDraw(std::stoi((command.substr(4, command.size() - 4))));
        }
    }else if (command == "save"){
        command.clear();
        std::cout << "Enter save file." << std::endl;
        std::cin >> command;
        saveInFIle(command);
    }else if (command.find("saveTicks") != std::string::npos && (!command.substr(5, command.size() - 4).empty())) {
        getTicksWithoutDraw(std::stoi((command.substr(9, command.size() - 4))));
        std::cout << "Enter save file." << std::endl;
        std::cin >> command;
        saveInFIle(command);
    }else if (command.find("saveTicks") != std::string::npos){
        std::cout << "Enter save file." << std::endl;
        std::cin >> command;
        saveInFIle(command);
    }else if (command == "help"){
        printHelp();
    }else if (command == "exit"){
        throw (ExitException());
    }else if (command == "clear"){
        system("cls");
    }
}
void Controller::printHelp(){
    std::cout << "HELP:" << std::endl;
    std::cout << "load - load game from file which you shall enter later." << std::endl;
    std::cout << "createStandardGame - create game with standard field." << std::endl;
    std::cout << "tick<integer number N> - calculate and drawing N ticks." << std::endl;
    std::cout << "save - saving game into save file." << std::endl;
    std::cout << "saveTicks<integer number N> - calculate and save game after N ticks." << std::endl;
    std::cout << "help - print help." << std::endl;
    std::cout << "exit - exit game." << std::endl;

}
void Controller::saveGame(std::string &saveFile){
    std::ofstream save(saveFile, std::fstream::out);

    save << "#Life 1.06" << std::endl;
    save << "#N " << getName() << std::endl;
    save << "#R " << getRulesString() << std::endl;
    printAliveCells(save);

    save.close();
}
std::string Controller::getRulesString() {
    std::string rules {"B"};
    for (auto x : getNeighboursToBirth()){
        rules += std::to_string(x);
    }
    rules += "/S";
    for (auto x : getNeighboursToSurvive()){
        rules += std::to_string(x);
    }

    return rules;
}
void Controller::printAliveCells(std::ofstream &save) const{
    for (auto& x : getAliveCells()){
        for (auto& y : x){
            std::pair<int, int> coordinates = y->getCoordinates();
            save << coordinates.first << ' ' << coordinates.second << std::endl;
        }
    }
}