#include "BitArray/BitArray.h"


int main(){

    auto a {BitArray(0)};

    for (int i {}; i < 5; ++i){
        a.pushBack(true);
    }
    std::cout << a.toString() << std::endl;
    a.clear();
    std::cout << a.toString() << a.getSize();

    return 0;
}
