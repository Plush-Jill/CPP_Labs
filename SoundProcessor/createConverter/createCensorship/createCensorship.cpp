#include "createCensorship.h"
#include "../../iConverter/censorship/censorship.h"

#include <memory>



std::shared_ptr<IConverter> CreateCensorship::create(){
    return std::make_shared<Censorship>();
}