#include <iostream>
#include "polinom.hpp"
#include "DynamicArray.hpp"

int main(){
    int kor[] = {5};
    Polinom pol{};
    std::cin >> pol;
    std::cout << pol;
    std::cout << pol.calculatePolinom(2) << std::endl;
    return 0;
}