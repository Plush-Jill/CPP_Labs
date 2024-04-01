#pragma once

#include <memory>
#include "../GameField/GameField.h"



class Viewer{
private:
    std::shared_ptr<GameField> viewingField;

public:
    explicit Viewer(std::shared_ptr<GameField> field);
    void drawField(); /// Отрисовывает поле.
};