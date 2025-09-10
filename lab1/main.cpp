#include "array.hpp"
#include <iostream>

int main(){
    // int it[] = {1,2,3};
    // Array<int> arr(3);
    // arr.resizeArray()
    // arr.printArray();
    // std::cout << arr;
    // int newit[] = {1,2,3,4};
    // arr.resizeArray(4, newit);
    // arr.printArray();s

    Array<int> arr(3);
    // arr.resizeArray()
    std::cin >> arr;
    std::cout << arr;
    
    return 0;
}