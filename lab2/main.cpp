// #include "array.hpp"
#include "application.hpp"
#include <iostream>

int main(){
    Application app;
    Array arr(3);

    // bool work = true;
    while(app.printMenu(arr));
    
    return 0;
}
