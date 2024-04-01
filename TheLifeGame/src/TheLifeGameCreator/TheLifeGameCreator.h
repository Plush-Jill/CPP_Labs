#pragma once
#include "../Controller/Controller.h"
#include <memory>
#include <set>
#include <vector>


class Controller;

///Класс, читающий из файла вселенную, хранящий в себе сохранение и создающий игру с такими данными.
class TheLifeGameCreator{
private:
    std::string universeName = "Unnamed Standard Game";
    std::set<int> neighboursToBirth = {3};
    std::set<int> neighboursToSurvive = {2, 3};
    std::vector<std::pair<int, int>> aliveCells = {{0, 2}, {0, 3}, {1, 3}, {2, 0}, {3, 0}, {3, 1}};

    //std::vector<std::pair<int, int>> aliveCells = {{0, 1}, {1, 1}, {2, 1}};

    int currentTick = 0;

    void makeCoordinatesByFieldSizeModule();
    bool readNameOrRules(std::fstream& saveFile);
    void readCellsCoordinates(std::fstream& saveFile);
    void calculateAndSetFieldSize();
public:
    int fieldSize = 8;
    void printAllInfo();
    TheLifeGameCreator();
    explicit TheLifeGameCreator(const std::string& save);
    void getUniverse(const std::string& life); /// Получает сохранение и записывает в this.
    std::shared_ptr<Controller> createGame(); /// Создаёт поле, контроллер и viewer.
    /// Даёт пользователю указатель на контроллер.
    void loadGame(std::shared_ptr<Controller>* controller);
};