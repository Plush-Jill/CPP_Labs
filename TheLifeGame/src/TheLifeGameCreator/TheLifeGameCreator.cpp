#include "TheLifeGameCreator.h"

void TheLifeGameCreator::getUniverse(const std::string& life){
    std::ifstream saveFile (life);
    ///дальше нужно будет прочитать из открытого файла и записать в this->....







}

std::shared_ptr<Controller> TheLifeGameCreator::createGame(){
    std::shared_ptr<Controller> game {new Controller()};
    game->setField(this->universeName,
                   this->neighboursToBirth,
                   this->neighboursToSurvive,
                   this->aliveCells,
                   this->fieldSize,
                   this->currentTick);
    return game;
}
