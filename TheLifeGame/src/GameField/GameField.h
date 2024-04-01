#pragma once

#include "../Cell/"
#include <vector>
#include <fstream>
#include <map>


class GameField{
private:
    std::string universeName;
    std::set<int> neighboursToBirth;
    std::set<int> neighboursToSurvive;

    std::vector<std::vector<Cell*>> aliveCells; /// Хранятся ТОЛЬКО живые клетки
    /// в fieldSize векторах.
    /// Номер вектора - одна из координат,
    /// из-за чего поиск приятнее.
    int aliveCellsCount; /// Нигде не возвращается,
    /// можно будет использовать вдруг для дебага и тд.

    int fieldSize;
    int currentTick;


    void setSize(int size);
    void setTick(int tick);
    void setName(const std::string& name);
    void setNeighboursToBirth(const std::set<int>& toBirth);
    void setNeighboursToSurvive(const std::set<int>& toSurvive);
    void setAliveCells(const std::vector<std::pair<int, int>>& cells);

    inline std::pair<int, int>
    coordinatesByFieldSizeModule(std::pair<int, int> coordinates) const; /// Используется для приведения координат к значениям по модулю размера поля.
    inline int bySizeModule(int x) const; /// То же самое, только для чисел, вызывается в предыдущей функции.
    inline bool findInToBirth(int x); /// Поиск числа в правиле рождения.
    inline bool findInToSurvive(int x); /// Поиск числа в правиле выживания.

    void changeFieldForNextTick(); /// Изменяет поле для следующего тика.
    void killNotSurvivors(); /// Убивает все клетки, которые не выживут после смены тика.
    void killCell(std::vector<Cell*>::iterator iter); /// Убивает клетку, убирает из aliveCells.
    bool cellIsAlive(std::pair<int, int> coordinates); /// Определяет, жива ли клетка, использует findByCoordinates.
    bool findByCoordinates(std::pair<int, int> coordinates); /// Ищет клетку с координатами в aliveCells.
    void bornNewCells(std::map<std::pair<int, int>, int>* criticalCells); /// Рождает новые клетки,
    /// которые появятся на следующем тике,
    /// добавляет в aliveCells.
    void bornCell(std::pair<int, int> coordinates); /// Рождает клетку, добавляет в aliveCells.
    void makeHimNeighbour(Cell* cell); /// Добавляет рождающейся клетке соседей.
    bool isNeighbours(Cell* cell1, Cell* cell2); /// true <=> cell1 и cell2 соседи.
public:

    GameField();
    GameField(const std::string& name,
              const std::set<int>& toBirth,
              const std::set<int>& toSurvive,
              const std::vector<std::pair<int, int>>& cells,
              int size,
              int tick);
    [[nodiscard]] int getSize();
    [[nodiscard]] int getCurrentTickNumber() const;
    [[nodiscard]] std::string getNameInField() const;
    [[nodiscard]] std::set<int> getNeighboursToBirthInField() const;
    [[nodiscard]] std::set<int> getNeighboursToSurviveInField() const;
    [[nodiscard]] const std::vector<std::vector<Cell*>>& getAliveCells() const;

    void setField(const std::string& name,
                  const std::set<int>& toBirth,
                  const std::set<int>& toSurvive,
                  const std::vector<std::pair<int, int>>& cells,
                  int size,
                  int tick);  /// Записывает в поле игру,
    /// вызывается, когда TheLifeGameCreator создаёт игру.
    /// Стоит поместить все эти данные в конструктор, позже.
    void nextTick();
};

