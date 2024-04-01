
#include "Cell.h"
#include <iostream>


std::pair<int, int> Cell::getCoordinates(){
    return {this->x, this->y};
}
void Cell::kill(){
    for (auto neighbour : this->neighbours){
        neighbour->disconnectNeighbour(this);
    }
    delete this;
}
void Cell::disconnectNeighbour(Cell* cell){
    this->neighbours.erase(cell);
}
int Cell::getX() const{
    return this->x;
}
int Cell::getY() const{
    return this->y;
}
int Cell::getNeighboursCount(){
    return static_cast<int>(this->neighbours.size());
}
void Cell::addNeighbour(Cell* cell){
    if (this->neighbours.size() == 8){
        throw std::exception();
    }
    this->neighbours.insert(cell);
}
std::string Cell::getCoordinatesString() const{
    std::string coordinates = "(";
    coordinates += std::to_string(this->x) + ", " + std::to_string(this->y) + ')';
    return coordinates;
}
void Cell::printCoordinates(std::ofstream& stream) const{
    stream << getCoordinatesString();
}
void Cell::printNeighboursCoordinates(std::ofstream& stream){
    printCoordinates(stream);
    stream << "'s neighbours: ";
    for (auto i : this->neighbours){
        i->printCoordinates(stream);
        stream << ' ';
    }
    stream << std::endl;
}
bool Cell::doYouWantDie() const{
    return this->willDieOnNextTick;
}
void Cell::makeWillDie(){
    this->willDieOnNextTick = true;
}
bool Cell::isNeighbour(Cell *cell, int fieldSize) const{
    int differenceInX = std::abs(this->x - cell->x);
    int differenceInY = std::abs(this->y - cell->y);

    bool isNeighbor = (differenceInY == 0 && (differenceInX == 1 || differenceInX == fieldSize - 1)) ||
                      (differenceInX == 0 && (differenceInY == 1 || differenceInY == fieldSize - 1)) ||
                      (differenceInX == 1 || differenceInX == fieldSize - 1) && (differenceInY == 1 || differenceInY == fieldSize - 1);

    return isNeighbor;
}
Cell::Cell(std::pair<int, int> coords){
    this->x = coords.first;
    this->y = coords.second;
}
Cell::Cell(){
    x = 0;
    y = 0;
}
void Cell::printCoordinates() const{
    std::cout << getCoordinatesString();
}
Cell::~Cell() = default;