#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include "tcomplex.hpp"

typedef int number;

class Array {
private:
    int length = 0;
    number* items;
    int it_point = 0;

public:
    Array() {
        items = nullptr;
    }

    ~Array() {
        delete[] this->items;
    }

    Array(int len) {
        this->length = len;
        this->items = new number[this->length];
    }

    Array(int len, number* items) {
        this->length = len;
        this->items = new number[this->length];
        for (int i = 0; i < length; ++i) {
            this->items[i] = items[i];
            ++it_point;
        }
    }

    int getArrayMaxLength() {
        return length;
    }

    int getArrayItemsCount() {
        return it_point;
    }

    void resizeArray(int newLen) {
        number* newSizeArray = new number[newLen];
        for (int i = 0; i < length && i < newLen; ++i) {
            newSizeArray[i] = this->items[i];
        }
        delete[] this->items;

        this->items = newSizeArray;
        this->length = newLen;
        if (it_point > newLen) it_point = newLen;
    }

    void printArray() {
        for (int i = 0; i < length; ++i) {
            std::cout << items[i] << std::endl;
        }
    }

    void addItem(number item) {
        if (it_point < length) {
            items[it_point] = item;
            ++it_point;
        }
    }

    void changeItem(int itemIndex, number newItem) {
        if (itemIndex >= 0 && itemIndex < it_point) {
            this->items[itemIndex] = newItem;
        }
    }

    // Среднее значение (возвращает комплексное число)
    number arrayAverage() {
        number sum(0, 0);
        if (it_point != 0) {
            for (int i = 0; i < it_point; i++) {
                sum = sum + items[i];
            }
            return sum / (double)it_point;
        }
        return sum;
    }

    // Среднеквадратичное отклонение (возвращает double)
    double arrayAverageSqrt() {
        double result = 0.0;
        if (it_point != 0) {
            number avg = arrayAverage();
            for (int i = 0; i < it_point; i++) {
                number diff = items[i] - avg;
                result += diff.magnitude() * diff.magnitude();
            }
            result = std::sqrt(result / it_point);
        }
        return result;
    }

    void sortMinToMax() {
        std::sort(this->items, this->items + this->it_point,
                  [](const number& a, const number& b) {
                      return a.magnitude() < b.magnitude();
                  });
    }

    void sortMaxToMin() {
        std::sort(this->items, this->items + this->it_point,
                  [](const number& a, const number& b) {
                      return a.magnitude() > b.magnitude();
                  });
    }

    friend std::ostream& operator<<(std::ostream& out, const Array& array);
    friend std::istream& operator>>(std::istream& in, Array& array);
};

inline std::ostream& operator<<(std::ostream& out, const Array& array) {
    for (int i = 0; i < array.it_point; ++i) {
        out << array.items[i] << " ";
    }
    return out;
}

inline std::istream& operator>>(std::istream& in, Array& array) {
    number it;
    int maxWrite = array.getArrayMaxLength() - array.getArrayItemsCount();
    for (int i = 0; i < maxWrite; ++i) {
        if (!(in >> it)) break;
        array.addItem(it);
    }
    return in;
}
