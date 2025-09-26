#include <iostream>
#include "array.hpp"
#include <locale.h>
#include <string>

class Application{
    private:
        Array<int> arr {3};
    public:
        Application(){
            setlocale(LC_ALL, "");
            // arr.addItem(1);
            // arr.addItem(2);
            // arr.addItem(3);
        }

        bool printMenu(){
            system("clear");
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

            for(int i = 0; i < 8; i++){
                std::cout << menu[i] << std::endl;
            }

            return menuNav();
        }

        bool menuNav(){
            // flushInput();
            // int key = getchar();
            std::string input;
            std::getline(std::cin, input);
            char key = input[0];
            if(key == 49){
                getItemsFromConsole();
            }else if(key == 50){
                calculatesAveargeVals();
            }else if(key == 51){
                sortMinToMax();
            }else if(key == 52){
                sortMaxToMin();
            }else if(key == 53){
                resizeArray();
            }else if(key == 54){
                changeItem();
            }else if(key == 55){
                printArray();
            }else if(key == 56){
                return false;
            }

            return true;
        }

        void getItemsFromConsole(){
            system("clear");
            std::cout << "Максимальная длина массива: " << arr.getArrayMaxLength() << std::endl;
            std::cout << "Записано элементов: " << arr.getArrayItemsCount() << std::endl;
            std::cout << "Введите элементы массива (CTRL+D в конце после ENTER)" << std::endl;
            std::cin >> arr;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }

        void calculatesAveargeVals(){
            system("clear");
            std::cout << "Среднее значение элементов массива: " << arr.arrayAverage() << std::endl;
            std::cout << "СКО элементов массива: " << arr.arrayAverageSqrt() << std::endl;
            std::cout << "CTRL+D для выхода в меню";
            std::cin.get();
        }

        void sortMinToMax(){
            system("clear");
            arr.sortMinToMax();
            std::cout << "Массив отсортирван по возрастанию" << std::endl;;
            std::cout << arr;
            std::cin.get();
        }

        void sortMaxToMin(){
            system("clear");
            arr.sortMaxToMin();
            std::cout << "Массив отсортирван по убыванию" << std::endl;;
            std::cout << arr;
            std::cin.get();
        }

        void resizeArray(){
            system("clear");
            std::cout << "Введите новый размер массива: ";
            int newLen;
            std::cin >> newLen;
            arr.resizeArray(newLen);
        }

        void changeItem(){
            system("clear");
            if(arr.getArrayItemsCount() == 0){
                std::cout << "Массивещё пустой" << std::endl;
            }else{
                std::cout << arr;
                std::cout << "Выберите элемент массива: ";
                int index;
                std::cin >> index;
                if(index >= arr.getArrayItemsCount()){
                    std::cout << "Такого элемента нет";
                }else{
                    std::cout << "Введите новый элемент массива: ";
                //TODO
                int newItem;
                std::cin >> newItem;
                arr.changeItem(index, newItem);
                }
            }
        }

        void printArray(){
            system("clear");
            if(arr.getArrayItemsCount() == 0){
                std::cout << "Массив пустой";
            }else{
                std::cout << arr << std::endl;
            }
            std::cin.get();
        }
};
