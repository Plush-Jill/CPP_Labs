#include <vector>
#include <string>
#include <fstream>
#include <set>


class GameField {
private:
    std::string universeName;
    std::set<int> neighboursToBirth;
    std::set<int> neighboursToSurvive;
    std::vector<std::pair<int, int>> aliveCells;

    int fieldSize;
    int currentTick;


    void setSize(int size);
    void setTick(int tick);
    void setName(const std::string& name);
    void setNeighboursToBirth(const std::set<int>& toBirth);
    void setNeighboursToSurvive(const std::set<int>& toSurvive);
    void setAliveCells(const std::vector<std::pair<int, int>>& cells);
public:
    [[nodiscard]] int getTick() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::set<int> getNeighboursToBirth() const;
    [[nodiscard]] std::set<int> getNeighboursToSurvive() const;
    [[nodiscard]] const std::vector<std::pair<int, int>>& getAliveCells() const;

    void setField(const std::string& name,
                  const std::set<int>& toBirth,
                  const std::set<int>& toSurvive,
                  const std::vector<std::pair<int, int>>& cells,
                  int size,
                  int tick);
};


