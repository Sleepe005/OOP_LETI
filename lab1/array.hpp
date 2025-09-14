#pragma once
#include <iostream>
#include <algorithm>  //для сортировки


template <typename T>
class Array {
private:
    int length = 0;
    T* items;
    int it_point = 0;
public:
    Array() {
        length = 0;
        items = nullptr;
    }
    ~Array() {
        delete[] this->items;
        delete this->length;
    }

    Array(int len) {
        this->length = len;
        this->items = new T[this->length];
    }

    Array(int len, T* items) {
        this->length = len;
        this->items = new T[this->length];
        for (int i = 0; i < length; ++i) {
            this->items[i] = items[i];
            ++it_point;
        }
    }
//заменила две резаписи на одну с копированием старых значений
    void resizeArray(int newLen) {
        newSizeArray = new T[newLen];
        for (int i = 0; i < length; ++i) {
            newSizeArray[i] = this->items[i];
        }
        delete this->items;
        this->items = newSizeArray;
    }

    void printArray() {
        for (int i = 0; i < length; ++i) {
            std::cout << items[i] << std::endl;
        }
    }

    void addItem(T item) {
        *(items + it_point) = item;
        ++it_point;
    }

//ско
    void arrayAverage() {
        int aver = 0;
        if (lenght != 0) {
            for (int i = 0; i < length; i++) {
                aver += this->items[i];
            }
            aver /= it_point;
        }
        return aver;
    }

    void arrayAverageSqrt() {
        int averSqrt = 0;
        if (lenght != 0) {
            for (int i = 0; i < length; i++) {
                averSqrt += (this->items[i] - arrayAvarage())**2;
            }
            averSqrt = sqrt(averSqrt / it_point);
        }
        return averSqrt
    }

//сортировка
    void sortMinToMax() {
        sortArray = new T[this->length];
        sortArray = std::sort(this->items, this->items + length);
        delete this->items;
        this->items = sortArray;
    }
    
    void sortMaxToMin() {
        sortArray = new T[this->length];
        sortArray = std::sort(this->items, this->items + length, std::greater<int>());
        delete this->items;
        this->items = sortArray;
    }

    template <typename U>
    friend std::ostream& operator<< (std::ostream& out, const Array<U>& array);

    template <typename U>
    friend std::istream& operator>> (std::istream& in, Array<U>& array);
};

template <typename U>
std::ostream& operator<< (std::ostream& out, const Array<U>& array) {
    for (int i = 0; i < array.length; ++i) {
        out << array.items[i] << " ";
    }
    return out;
}

template <typename U>
std::istream& operator>>(std::istream& in, Array<U>& array) {
    U it;
    while (in >> it) {
        array.addItem(it);
    }
    return in;
}
