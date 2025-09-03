#include "array.h"
#include <iostream>

int main(){
    int it[] = {1,2,3};
    Array<int> arr(3, it);
    arr.printArray();
    int newit[] = {1,2,3,4};
    arr.resizeArray(4, newit);
    arr.printArray();
    return 0;
}