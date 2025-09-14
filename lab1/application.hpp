#include <iostream>
#include <ncurses.h>
#include "array.hpp"
#include <locale.h>

class Application{
    private:
        int cursePosition = 1;
        Array<int> arr {3};
    public:
        Application(){
            // arr(3);
            setlocale(LC_ALL, "");
            initscr();
        }

        ~Application(){
            endwin();
        }

        bool printMenu(){
            clear();
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

            for(int i = 1; i <= 8; i++){
                printw("%s", menu[i-1]);
                if(i == cursePosition){
                    printw("    <--");
                }
                printw("\n");
            }

            return menuNav();
        }

        bool menuNav(){
            int key = getch();
            if(key == 27){
                key = getch();
                if(key == 91){
                    key = getch();
                    if(key == 65){
                        cursePosition--;
                        if(cursePosition < 1){
                            cursePosition = 8;
                        }
                    }
                    if(key == 66){
                        cursePosition++;
                        if(cursePosition > 8){
                            cursePosition = 1;
                        }
                    }
                }
                if (key == 27){
                    return false;
                }
            }else if(key == 49){
                getItemsFromConsole();
            }else if(key == 50){
                calculatesAveargeVals();
            }

            return true;
        }

        void flushInput() {
            // std::cin.clear(); // сброс флагов ошибок
            while (std::cin.get() != '\n' && !std::cin.eof()) {
                // читаем и выбрасываем символы до конца строки
            }
        }


        void getItemsFromConsole(){
            // endwin();
            // system("clear");
            // flushInput();
            // std::cout << "Максимальная длина массива: " << arr.getArrayMaxLength() << std::endl;
            // std::cout << "Записано элементов: " << arr.getArrayItemsCount() << std::endl;
            // std::cout << "Введите элементы массива (CTRL+D в конце после ENTER)" << std::endl;
            // std::cin >> arr;
            // initscr();

            clear();
            printw("Максимальная длина массива: %d", arr.getArrayMaxLength());
            printw("Записано элементов: %d", arr.getArrayItemsCount());
            printw("Введите элементы массива\n");
            // std::cin >> arr;
        }

        void calculatesAveargeVals(){
            // endwin();
            // system("clear");
            // std::cout << "Среднее значение элементов массива: " << arr.arrayAverage() << std::endl;
            // std::cout << "СКО элементов массива: " << arr.arrayAverageSqrt() << std::endl;
            // std::cout << "CTRL+D для выхода в меню";
            // // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // // std::cin.get();
            // // std::cin.get();
            // flushStdin();
            // std::cin.get();
            clear();
            printw("Среднее значение элементов массива: %d\n", arr.arrayAverage());
            printw("СКО элементов массива: %d\n", arr.arrayAverageSqrt());
            printw("Для выхода в меню нажмите любую кнопку");
            getch();
        }

        void printArray(){
            std::cout << arr;
        }


};