

#include "Viewer.h"
#include "../Cell/Cell.h"
#include "../GameField/GameField.h"
#include <iostream>
#include <utility>
#include <ctime>
#include <chrono>
#include <thread>


void Viewer::drawField(){
    int fieldSize = this->viewingField->getSize();
    std::vector<std::vector<bool>> fieldToDraw
            (fieldSize, std::vector<bool>(fieldSize, false));

    const std::vector<std::vector<Cell*>>& aliveCells {this->viewingField->getAliveCells()};

    std::pair<int, int> coordinates;
    for (const auto & aliveCell : aliveCells){
        for (auto it2 : aliveCell){
            coordinates = it2->getCoordinates();
            fieldToDraw[coordinates.first][coordinates.second] = true;

        }
    }

    for (auto it1 = fieldToDraw.begin(); it1 < fieldToDraw.end(); ++it1){
        for (auto it2 = (*it1).begin(); it2 < (*it1).end(); ++it2){
            if (*it2){
                std::cout << '0';
            }else{
                std::cout << '.';
            }
        }
        std::cout << std::endl;
    }


    std::cout << "================\n";
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
Viewer::Viewer(std::shared_ptr<GameField> field){
    this->viewingField = std::move(field);
}