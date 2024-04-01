#pragma once
#include "../TheLifeGameCreator/TheLifeGameCreator.h"
#include "../GameField/GameField.h"
#include "../Viewer/Viewer.h"



class Controller{
private:
    std::shared_ptr<GameField> field;
    std::shared_ptr<Viewer> viewer;

    void nextTick();
    void saveGame(std::string& saveFile);
    void printAliveCells(std::ofstream& save) const;
public:


    Controller();
    Controller(const std::string& universeName,
               const std::set<int>& neighboursToBirth,
               const std::set<int>& neighboursToSurvive,
               const std::vector<std::pair<int, int>>& aliveCells,
               int fieldSize,
               int currentTick);
    Controller(const std::shared_ptr<GameField>& field, const std::shared_ptr<Viewer>& viewer);

    void setField(const std::string& universeName,
                  const std::set<int>& neighboursToBirth,
                  const std::set<int>& neighboursToSurvive,
                  const std::vector<std::pair<int, int>>& aliveCells,
                  int fieldSize,
                  int currentTick); ///Записывает в поле игру,
    /// вызывается, когда TheLifeGameCreator создаёт игру.
    /// Стоит поместить все эти данные в конструктор, позже.

    void saveInFIle(std::string& fileName) const; /// Сохранение в файл, ещё не реализовано.

    [[nodiscard]] int getCurrentTickNumber() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::set<int> getNeighboursToBirth() const;
    [[nodiscard]] std::set<int> getNeighboursToSurvive() const;
    [[nodiscard]] const std::vector<std::vector<Cell*>>& getAliveCells() const;
    [[nodiscard]] std::string getRulesString();

    void drawField(); /// Вызывается, чтобы пнуть viewer, чтобы тот отрисовал поле.
    void getTicksWithDraw(int nTicks); ///Высчитывает и отрисовывает nTicks тиков игры.
    void getTicksWithoutDraw(int nTicks);
    void executeCommand(std::string& command);
    void printHelp();
};


