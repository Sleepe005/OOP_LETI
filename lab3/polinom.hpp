#pragma once
#include "array.hpp"

typedef TComplex number;

class Polinom{
    private:
        int step = 0;
        int an = 0;
        Array solutions{};
        Array solutions_coef{};

    public:
        Polinom(){};

        Polinom(int step, int an, number *solutions){
            this->step = step;
            this->an = an;

            this->solutions.resizeArray(step);
            this->solutions_coef.resizeArray(step);

            for(int i = 0; i < step; i++){
                this->solutions.addItem(solutions[i]);
            }

            calcSolutions_coef();
        }

        void calcSolutions_coef(){
            for(int i = 0; i < step; i++){
                solutions_coef.addItem(solutions[i]*an);
            }
        }

        // копируем массива корней и массив, заданный пользователем
        const void getSolutions(number *&solutions){
            for(int i = 0; i < step; i++){
                solutions[i] = this->solutions[i];
            }
        }

        // вычисляем значения полинома в точке x
        number calculatePolinom(number x){
            number res = an;
            for(int i = 0; i < step; i++){
                res = res * (x - solutions[i]);
            }
            return res;
        }

        void changePolinom(int index, number item){
            if(index == 0){this->an = item.real();}
            solutions.changeItem(index-1, item);
        }

       friend std::ostream& operator<<(std::ostream& out, Polinom& polinom){
            out << "p(x)=" << polinom.an;
            for(int i = 0; i < polinom.step; i++){
                out << "(x-" << polinom.solutions[i] << ")"; 
            }
            out << std::endl;
            return out;
       }

       friend std::istream& operator>>(std::istream& in, Polinom& polinom){
            in >> polinom.step;
            in >> polinom.an;
            polinom.solutions.resizeArray(polinom.step);
            polinom.solutions_coef.resizeArray(polinom.step);
            for(int i = 0; i < polinom.step; i++){
                number kor;
                in >> kor;
                polinom.solutions.addItem(kor);
            }

            polinom.calcSolutions_coef();

            return in;
       }
};