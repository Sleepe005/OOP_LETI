#include <iostream>
#include "application.hpp"
#include "polinom.hpp"

int main(){
    Polinom pol{};
    Application app{};

    while (app.printMenu(pol));     

    return 0;
}