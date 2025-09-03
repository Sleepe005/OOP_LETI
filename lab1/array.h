#pragma once
#include <iostream>

template <typename T>
class Array{
    private:
        int length = 0;
        T *items;
    public:
        Array();
        Array(int len, T *items);
        void resizeArray(int newLen, T *newItems);
        void printArray();
};

#include "array.tpp"