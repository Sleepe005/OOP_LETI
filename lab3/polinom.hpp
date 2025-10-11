#pragma once
#include "array.hpp"

typedef int number;

class Polinom{
    private:
        int step = 0;
        int an = 0;
        Array korni{};
        Array korni_val{};

        

    public:
        Polinom(){};

        Polinom(int step, int an, int *korni){
            this->step = step;
            this->an = an;

            this->korni.resizeArray(step);
            this->korni_val.resizeArray(step);

            for(int i = 0; i < step; i++){
                this->korni.addItem(korni[i]);
            }

            mathKorniVal();
        }

        void mathKorniVal(){
            for(int i = 0; i < step; i++){
                korni_val.addItem(korni[i]*an);
            }
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

        // void changePolinom(int index, int item){
        //     if(index == 0){this->an = item;}
        //     korni.
        // }

       friend std::ostream& operator<<(std::ostream& out, Polinom& polinom){
            out << "p(x)=" << polinom.an;
            for(int i = 0; i < polinom.step; i++){
                out << "(x-" << polinom.korni[i] << ")"; 
            }
            out << std::endl;
            return out;
       }

       friend std::istream& operator>>(std::istream& in, Polinom& polinom){
            in >> polinom.step;
            in >> polinom.an;
            polinom.korni.resizeArray(polinom.step);
            polinom.korni_val.resizeArray(polinom.step);
            for(int i = 0; i < polinom.step; i++){
                int kor;
                in >> kor;
                polinom.korni.addItem(kor);
            }

            polinom.mathKorniVal();

            return in;
       }
};