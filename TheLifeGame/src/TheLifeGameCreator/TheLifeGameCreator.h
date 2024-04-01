#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <memory>
#include "../Controller/Controller.h"



class TheLifeGameCreator{
    std::string universeName = "Unnamed Standard Game";
    std::set<int> neighboursToBirth = {2};
    std::set<int> neighboursToSurvive = {2, 3};
    std::vector<std::pair<int, int>> aliveCells = {{0, 2}, {0, 3}, {1, 3},
                                                   {2, 0}, {3, 0}, {3, 1}};

    int fieldSize = 100;
    int currentTick = 0;


    void getUniverse(const std::string& life);
    std::shared_ptr<Controller> createGame();
};


