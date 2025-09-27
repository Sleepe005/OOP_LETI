#include "application.hpp"
#include <iostream>
#include <windows.h>

int main() {
    Application app;
    Array arr(3);  

    while (app.printMenu(arr)); 
    return 0;
}
