#include "array.h"
#include <iostream>

int main(){
    int it[] = {1,2,3};
    Array<int> arr(3, it);
    arr.printArray();

    return 0;
}