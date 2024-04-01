#include "Controller.h"


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
int Controller::getTick() const{
    return this->field->getTick();
}
void Controller::saveInFIle(const std::string& fileName){
    std::ofstream output (fileName);
    output << "#Life 1.06\n#N " << getName() << std::endl;
    output << "#R B";
    for (int x : getNeighboursToBirth()){
        output << x;
    }
    output << "/S";
    for (int x : getNeighboursToSurvive()){
        output << x << std::endl;
    }
    for (std::pair<int, int> x : getAliveCells()){
        output << x.first << ' ' << x.second << std::endl;
    }
}
std::string Controller::getName() const {
    return this->field->getName();
}
std::set<int> Controller::getNeighboursToBirth() const {
    return this->field->getNeighboursToBirth();
}
std::set<int> Controller::getNeighboursToSurvive() const {
    return this->field->getNeighboursToSurvive();
}
const std::vector<std::pair<int, int>>& Controller::getAliveCells() const {
    return this->field->getAliveCells();
}
