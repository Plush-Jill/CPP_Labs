

#include "../Headers/GameField.h"
#include <map>
#include <iostream>



int GameField::getCurrentTickNumber() const{
    return this->currentTick;
}
std::string GameField::getNameInField() const{
    return this->universeName;
}
std::set<int> GameField::getNeighboursToBirthInField() const{
    return this->neighboursToBirth;
}
std::set<int> GameField::getNeighboursToSurviveInField() const{
    return this->neighboursToSurvive;
}
const std::vector<std::vector<Cell*>>& GameField::getAliveCells() const{
    return this->aliveCells;
}
void GameField::setField(const std::string& name,
                         const std::set<int>& toBirth,
                         const std::set<int>& toSurvive,
                         const std::vector<std::pair<int, int>> &cells,
                         int size,
                         int tick){
    setSize(size);
    setTick(tick);
    setName(name);
    setNeighboursToBirth(toBirth);
    setNeighboursToSurvive(toSurvive);
    setAliveCells(cells);
}
void GameField::setTick(int tick){
    this->currentTick = tick;
}
void GameField::setName(const std::string &name){
    this->universeName = name;
}
void GameField::setNeighboursToBirth(const std::set<int>& toBirth){
    this->neighboursToBirth = toBirth;
}
void GameField::setNeighboursToSurvive(const std::set<int>& toSurvive){
    this->neighboursToSurvive = toSurvive;
}
void GameField::setAliveCells(const std::vector<std::pair<int, int>>& cells){
    this->aliveCells = std::vector<std::vector<Cell*>>(this->fieldSize, std::vector<Cell*>(0));
    for (auto x : cells){
        std::pair<int, int> xByModule = coordinatesByFieldSizeModule(x);
        Cell* cell = new Cell(xByModule);
        ///this->aliveCells[x.first].push_back((new Cell(x)));
        this->aliveCells[xByModule.first].push_back(cell);
        makeHimNeighbour(cell);
        ++this->aliveCellsCount;
    }
}
void GameField::setSize(int size){
    this->fieldSize = size;
}
void GameField::nextTick(){
    changeFieldForNextTick();
    ++this->currentTick;
}
void GameField::changeFieldForNextTick(){
    std::map<std::pair<int, int>, int> criticalCells;

    std::pair<int, int> coordinates;
    for (const auto& x : this->aliveCells){
        for (const auto& y : x) {
            coordinates = y->getCoordinates();

            for (int i = -1; i <= 1; ++i){
                for (int j = -1; j <= 1; ++j){
                    if (i == 0 && j == 0){
                        continue;
                    }
                    ++criticalCells[coordinatesByFieldSizeModule({coordinates.first + i, coordinates.second + j})];
                }
            }
        }
    }

    for (auto it = criticalCells.begin(); it != criticalCells.end();){
        bool alive = cellIsAlive(it->first);
        if (alive){
            criticalCells.erase(it++);
        }else{
            ++it;
        }
    }

    killNotSurvivors();
    bornNewCells(&criticalCells);
}
inline std::pair<int, int> GameField::coordinatesByFieldSizeModule(std::pair<int, int> coordinates) const{
    return {bySizeModule(coordinates.first), bySizeModule(coordinates.second)};
}
inline int GameField::bySizeModule(int x) const{
    if (x < 0){
        return x + this->fieldSize;
    }else if (x >= this->fieldSize){
        return x % this->fieldSize;
    }else{
        return x;
    }
}
inline bool GameField::findInToBirth(int x){
    for (auto v : this->neighboursToBirth){
        if (v == x){
            return true;
        }
    }
    return false;
}
inline bool GameField::findInToSurvive(int x){
    for (auto v : this->neighboursToSurvive){
        if (v == x){
            return true;
        }
    }
    return false;
}
bool GameField::cellIsAlive(std::pair<int, int> coordinates){
    return findByCoordinates(coordinates);
}
bool GameField::findByCoordinates(std::pair<int, int> coordinates){
    int y = coordinates.second;
    for (const auto& a : this->aliveCells[coordinates.first]){
        if (a->getY() == y){
            return true;
        }
    }
    return false;
}
void GameField::killNotSurvivors(){
    for (auto& aliveCell : this->aliveCells){
        for (auto& it2 : aliveCell){
            if (!findInToSurvive(it2->getNeighboursCount())){
                it2->makeWillDie();
                continue;
            }
        }
    }

    for (auto& x : this->aliveCells){
        for (auto it2 = x.begin(); it2 < x.end();){
            if ((*it2)->doYouWantDie()){
                killCell(it2);
            }else{
                ++it2;
            }
        }
    }
}
void GameField::killCell(std::vector<Cell*>::iterator iter){
    int x = (*iter)->getX();
    (*iter)->kill();
    this->aliveCells[x].erase(iter);
    --this->aliveCellsCount;
}
int GameField::getSize(){
    return this->fieldSize;
}
void GameField::makeHimNeighbour(Cell *cell){
    for (int i = 0; i < this->fieldSize; ++i){
        for (auto alreadyAliveCell : this->aliveCells[i]){
            if (isNeighbours(cell, alreadyAliveCell)){
                alreadyAliveCell->addNeighbour(cell);
                cell->addNeighbour(alreadyAliveCell);
            }
        }
    }
}
void GameField::bornNewCells(std::map<std::pair<int, int>, int>* criticalCells){
    for (auto x : *criticalCells){
        if (findInToBirth(x.second)){
            bornCell(x.first);
        }
    }
}
void GameField::bornCell(std::pair<int, int> coordinates){
    Cell* cell = new Cell(coordinates);
    this->aliveCells[coordinates.first].push_back(cell);
    makeHimNeighbour(cell);
}
bool GameField::isNeighbours(Cell *cell1, Cell *cell2){
    int differenceInX = std::abs(cell1->getX() - cell2->getX());
    int differenceInY = std::abs(cell1->getY() - cell2->getY());

    bool isNeighbor = (differenceInY == 0 && (differenceInX == 1 || differenceInX == fieldSize - 1)) ||
                      (differenceInX == 0 && (differenceInY == 1 || differenceInY == fieldSize - 1)) ||
                      (differenceInX == 1 || differenceInX == fieldSize - 1) && (differenceInY == 1 || differenceInY == fieldSize - 1);

    return isNeighbor;
}

GameField::GameField(const std::string &name,
                     const std::set<int> &toBirth,
                     const std::set<int> &toSurvive,
                     const std::vector<std::pair<int, int>> &cells,
                     int size,
                     int tick){
    this->universeName = name;
    this->neighboursToBirth = toBirth;
    this->neighboursToSurvive = toSurvive;
    this->fieldSize = size;
    this->currentTick = tick;
    setAliveCells(cells);
}

GameField::GameField() = default;