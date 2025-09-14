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
    // arr.sortMinToMax();
    // arr.resizeArray()


    
    std::cout << "длина массива ";
    std::cin >> len;
    
    if (!std::cin || n <= 0) {
        std::cout << "отрицательная длина\n";
        return 1;
    }
    Array<int> arr(len)
    //ввод данных
    int count = 0;
    while (count < len) {
        int value;
        std::cin >> value;
    
        //проверка что-то кроме чисел
        if (!std::cin) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Ошибка: нужно ввести число. Попробуйте снова:\n";
            continue; 
        }
        arr.addItem(value); 
    }
    //излишний ввод
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    




    arr.sortMaxToMin();
    // arr.resizeArray(4);
    // arr.addItem(5);
    std::cout << arr.arrayAverage() << std::endl;
    std::cout << arr.arrayAverageSqrt() << std::endl;
    std::cout << arr;
    
    return 0;
}
