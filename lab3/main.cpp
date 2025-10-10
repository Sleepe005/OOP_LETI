#include <iostream>
#include "polinom.hpp"
#include "DynamicArray.hpp"

int main(){
    int kor[] = {5};
    Polinom pol{1, 1, kor};
    std::cout << pol;
    std::cout << pol.calculatePolinom(2) << std::endl;
    return 0;
}