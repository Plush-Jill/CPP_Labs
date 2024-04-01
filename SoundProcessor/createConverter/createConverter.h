#pragma once

#include "../iConverter/IConverter.h"

#include <memory>
#include <string>



class CreateConverter{
public:
    virtual std::shared_ptr<IConverter>  create() = 0;

};