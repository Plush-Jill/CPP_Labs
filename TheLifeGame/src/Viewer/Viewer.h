#include <memory>
#include "../GameField/GameField.h"



class Viewer{
private:
    std::shared_ptr<GameField> viewingField;


public:
    void drowField();
};


