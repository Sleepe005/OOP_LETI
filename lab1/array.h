#pragma once
#include <iostream>

template <typename T>
class Array{
    private:
        int length = 0;
        T *items;
    public:
        Array(){
            length = 0;
            items = nullptr;
        }

        Array(int len, T *items){
            this->length=len;
            this->items = new T[this->length];
            for(int i = 0; i < length; ++i){
                this->items[i]=items[i];
            }
        }
        void resizeArray(int newLen, T *newItems){
            this->length = newLen;
            delete this->items;
            this->items = new T[this->length];
            for(int i = 0; i < length; ++i){
                this->items[i]=newItems[i];
            }
        }
        void printArray(){
            for(int i = 0; i < length; ++i){
                std::cout << items[i] << std::endl;
            }
        }
};