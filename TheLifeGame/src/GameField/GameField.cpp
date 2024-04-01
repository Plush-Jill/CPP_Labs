#include "GameField.h"




int GameField::getTick() const{
    return this->currentTick;
}
std::string GameField::getName() const{
    return this->universeName;
}
std::set<int> GameField::getNeighboursToBirth() const{
    return this->neighboursToBirth;
}
std::set<int> GameField::getNeighboursToSurvive() const{
    return this->neighboursToSurvive;
}
const std::vector<std::pair<int, int>>& GameField::getAliveCells() const{
    return this->aliveCells;
}
void GameField::setField(const std::string& name,
                         const std::set<int>& toBirth,
                         const std::set<int>& toSurvive,
                         const std::vector<std::pair<int, int>> &cells,
                         int size,
                         int tick){

    this->fieldSize = size;
    this->currentTick = tick;
    setName(name);
    setNeighboursToBirth(toBirth);
    setNeighboursToSurvive(toSurvive);
    setAliveCells(cells);

}
void GameField::setTick(int tick){
    this->currentTick = tick;
}
void GameField::setName(const std::string &name) {
    this->universeName = name;
}
void GameField::setNeighboursToBirth(const std::set<int>& toBirth) {
    this->neighboursToBirth = toBirth;
}
void GameField::setNeighboursToSurvive(const std::set<int>& toSurvive) {
    this->neighboursToSurvive = toSurvive;
}
void GameField::setAliveCells(const std::vector<std::pair<int, int>>& cells) {
    this->aliveCells = cells;
}

void GameField::setSize(int size) {
    this->fieldSize = size;
}


