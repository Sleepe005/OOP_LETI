#pragma once
// #include "array.hpp"
#include "DynamicArray.hpp"

typedef int number;

class Polinom{
    private:
        int step = 0;
        int an = 0;
        // Array korni{};
        // Array korni_val{};

        DynamicArray<int> korni{};
        DynamicArray<int> korni_val{};

        void mathKorniVal(){
            for(int i = 0; i < step; i++){
                korni_val.pushBack(korni[i]*an);
            }
        }

    public:
        Polinom(){};

        Polinom(int step, int an, int *korni){
            this->step = step;
            this->an = an;
            for(int i = 0; i < step; i++){
                this->korni.pushBack(korni[i]);
            }

            mathKorniVal();
        }

        // копируем массива корней и массив, заданный пользователем
        const void getKorni(int *&korni){
            for(int i = 0; i < step; i++){
                korni[i] = this->korni[i];
            }
        }

        // вычисляем значения полинома в точке x
        int calculatePolinom(int x){
            int res = an;
            for(int i = 0; i < step; i++){
                res *= (x - korni[i]);
            }
            return res;
        }

        //TODO: перегрузка оператора ввода (рабтает на пустом полиноме)
       friend std::ostream& operator<<(std::ostream& out, Polinom& polinom){
            out << "p(x)=" << polinom.an;
            for(int i = 0; i < polinom.step; i++){
                out << "(x-" << polinom.korni[i] << ")"; 
            }
            out << std::endl;
            return out;
       }
};

// std::ostream& operator<<(std::ostream& out, const Polinom& polinom) {
//     // int *pol_korni = new int[polinom.step];
//     // polinom.getKorni(pol_korni);

//     out << "p(x)=" << polinom.an;
//     for(int i = 0; i < polinom.step; i++){
//         out << "(x-" << polinom.korni[i] << ")"; 
//     }
//     return out;
// }