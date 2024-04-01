#include <memory>
#include "../GameField/GameField.h"
#include "../Viewer/Viewer.h"



class Controller{
private:
    std::unique_ptr<GameField> field;
    std::unique_ptr<Viewer> view;


public:
    void setField(const std::string& universeName,
                  const std::set<int>& neighboursToBirth,
                  const std::set<int>& neighboursToSurvive,
                  const std::vector<std::pair<int, int>>& aliveCells,
                  int fieldSize,
                  int currentTick);
    void saveInFIle(const std::string& fileName);

    [[nodiscard]] int getTick() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::set<int> getNeighboursToBirth() const;
    [[nodiscard]] std::set<int> getNeighboursToSurvive() const;
    [[nodiscard]] const std::vector<std::pair<int, int>>& getAliveCells() const;
};



