#include <iostream>
#include "array.hpp"
#include <locale.h>
#include <string>

class Application {
public:
    Application() {
        setlocale(LC_ALL, "");
    }

    bool printMenu(Array<int>& arr) {   
        system("cls");
        char menu[8][75] = {
            "1. Ввести значения массива",
            "2. Рассчтать среднее и СКО",
            "3. Отсортировать массив по возрастанию",
            "4. Отсортировать массив по убыванию",
            "5. Изменить размер массива",
            "6. Изменить выбранный элемент массива",
            "7. Вывести элемента массива",
            "8. Выйти из приложения (ESC x2)",
        };

        for (int i = 0; i < 8; i++) {
            std::cout << menu[i] << std::endl;
        }

        return menuNav(arr);   
    }


    bool menuNav(Array<int>& arr) {
        std::string input;
        std::getline(std::cin, input);
        char key = input[0];
        if (key == '1') {
            getItemsFromConsole(arr);
        }
        else if (key == '2') {
            calculatesAveargeVals(arr);
        }
        else if (key == '3') {
            sortMinToMax(arr);
        }
        else if (key == '4') {
            sortMaxToMin(arr);
        }
        else if (key == '5') {
            resizeArray(arr);
        }
        else if (key == '6') {
            changeItem(arr);
        }
        else if (key == '7') {
            printArray(arr);
        }
        else if (key == '8') {
            return false;
        }
        return true;
    }

    void getItemsFromConsole(Array<int>& arr) {
        system("cls");
        std::cout << "Максимальная длина массива: " << arr.getArrayMaxLength() << std::endl;
        std::cout << "Записано элементов: " << arr.getArrayItemsCount() << std::endl;
        std::cout << "Введите элементы массива (CTRL+D в конце после ENTER)" << std::endl;
        std::cin >> arr;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void calculatesAveargeVals(Array<int>& arr) {
        system("cls");
        std::cout << "Среднее значение элементов массива: " << arr.arrayAverage() << std::endl;
        std::cout << "СКО элементов массива: " << arr.arrayAverageSqrt() << std::endl;
        std::cout << "CTRL+D для выхода в меню";
        std::cin.get();
    }

    void sortMinToMax(Array<int>& arr) {
        system("cls");
        arr.sortMinToMax();
        std::cout << "Массив отсортирван по возрастанию" << std::endl;
        std::cout << arr;
        std::cin.get();
    }

    void sortMaxToMin(Array<int>& arr) {
        system("cls");
        arr.sortMaxToMin();
        std::cout << "Массив отсортирван по убыванию" << std::endl;
        std::cout << arr;
        std::cin.get();
    }

    void resizeArray(Array<int>& arr) {
        system("cls");
        std::cout << "Введите новый размер массива: ";
        int newLen;
        std::cin >> newLen;
        arr.resizeArray(newLen);
    }

    void changeItem(Array<int>& arr) {
        system("cls");
        if (arr.getArrayItemsCount() == 0) {
            std::cout << "Массив ещё пустой" << std::endl;
        }
        else {
            std::cout << arr;
            std::cout << "Выберите элемент массива: ";
            int index;
            std::cin >> index;
            if (index >= arr.getArrayItemsCount()) {
                std::cout << "Такого элемента нет";
            }
            else {
                std::cout << "Введите новый элемент массива: ";
                int newItem;
                std::cin >> newItem;
                arr.changeItem(index, newItem);
            }
        }
    }

    void printArray(Array<int>& arr) {
        system("cls");
        if (arr.getArrayItemsCount() == 0) {
            std::cout << "Массив пустой";
        }
        else {
            std::cout << arr << std::endl;
        }
        std::cin.get();
    }
};
