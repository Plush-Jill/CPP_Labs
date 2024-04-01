#pragma once
#include <string>
#include <set>
#include <memory>
#include <fstream>

class Cell{
private:
    int x;
    int y;

    std::set<Cell*> neighbours;
    bool willDieOnNextTick = false;
    void disconnectNeighbour(Cell* cell);
public:
    Cell();
    explicit Cell(std::pair<int, int> coords);
    ~Cell();

    std::pair<int, int> getCoordinates();
    int getX() const;
    int getY() const;
    void kill(); /// Отстоединяет клетку от соседей, чтобы на неё больше никто не ссылался.
    int getNeighboursCount();
    void addNeighbour(Cell* cell); /// Добавляет ссылку на соседа.
    bool doYouWantDie() const; /// Хочешь умереть на следующем тике?
    void makeWillDie(); /// После таких приколов клетка получит депрессию
    /// и не захочет быть живой в следующем тике.


    std::string getCoordinatesString() const; /// Получить строку координат в виде (x, y).
    void printCoordinates(std::ofstream& stream) const; /// Вывести её.
    void printCoordinates() const; /// Вывести её.
    void printNeighboursCoordinates(std::ofstream& stream); /// Вывести координаты всех соседей, дебажил этим.
    bool isNeighbour(Cell *cell, int fieldSize) const;
};