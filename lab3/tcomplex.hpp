#pragma once

#include <iostream>
#include <cmath>

class TComplex {
private:
    double re; // действительная часть
    double im; // мнимая часть

public:
    
    TComplex(double r = 0.0, double i = 0.0) {
        this->re = r;
        this->im = i;
    }

    // Геттеры/сеттеры (если вдруг пригодятся)
    double real() const { return re; }
    double imag() const { return im; }
    void setReal(double r) { re = r; }
    void setImag(double i) { im = i; }

    // перегрузка операторов
    TComplex operator+(const TComplex& other) const {
        return TComplex(re + other.re, im + other.im);
    }

    TComplex operator-(const TComplex& other) const {
        return TComplex(re - other.re, im - other.im);
    }

    TComplex operator*(const TComplex& other) const {
        return TComplex(re * other.re - im * other.im,
            re * other.im + im * other.re);
    }

    TComplex operator/(const TComplex& other) const {
        double denom = other.re * other.re + other.im * other.im;
        return TComplex((re * other.re + im * other.im) / denom,
            (im * other.re - re * other.im) / denom);
    }

    // деление на число (double)
    TComplex operator/(double val) const {
        return TComplex(re / val, im / val);
    }

    // модул
    double magnitude() const {
        return std::sqrt(re * re + im * im);
    }

    // сортировки по модулю
    bool operator<(const TComplex& other) const {
        return this->magnitude() < other.magnitude();
    }
    bool operator>(const TComplex& other) const {
        return this->magnitude() > other.magnitude();
    }

    // Потоковый ввод/вывод
    friend std::istream& operator>>(std::istream& in, TComplex& c) {
        std::cout << "Введите действительную и мнимую часть: ";
        in >> c.re >> c.im;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const TComplex& c) {
        out << c.re;
        if (c.im >= 0) out << "+";
        out << c.im << "i";
        return out;
    }
};
