#include <iostream>
#include "polinom.hpp"
#include <locale.h>
#include <string>

class Application {
public:
    Application() {
        setlocale(LC_ALL, "");
    }

    bool printMenu(Polinom& pol) {
        system("clear");
        char menu[5][100] = {
            "1. Создать полином",
            "2. Изменить коэфициенты или корни полинома",
            "3. Вычислить полином",
            "4. Вывести полином",
            "5. Выйти из приложения (ESC x2)",
        };

        for (int i = 0; i < 5; i++) {
            std::cout << menu[i] << std::endl;
        }

        return menuNav(pol);
    }

private:
    bool menuNav(Polinom& pol) {
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) return true;
        char key = input[0];
        if (key == '1') {
            createPolinom(pol);
        }
        else if (key == '2') {
            changePolinom(pol);
        }
        else if (key == '3') {
            calculatePolinon(pol);
        }
        else if (key == '4') {
            system("clear");
            system("cls");
            std::cout << pol;
            getchar();
        }
        else if (key == '5') {
            return false;
        }
        return true;
    }

    void createPolinom(Polinom &pol){
        system("clear");
        system("cls");

        std::cout << "Введите степень полинома, коэффициент an и значения полинома через пробел\n";
        std::cin >> pol;
    }

    void changePolinom(Polinom &pol){
        system("clear");
        system("cls");

        std::cout << "Введите индекс элемента который хотите поменять и значение элемента\n(0 индекс - значение an)\n";
        int index, value;
        std::cin >> index >> value;
        pol.changePolinom(index, value);
    }

    void calculatePolinon(Polinom &pol){
        system("clear");
        system("cls");

        std::cout << "Введите точку, в которой надо посчитать значение полинома\n";
        int x;
        std::cin >> x;
        std::cout << "Значние в точке " << x << " = " << pol.calculatePolinom(x);
        getchar();
        getchar();
    }
};
