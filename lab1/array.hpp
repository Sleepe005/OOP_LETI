#pragma once
#include <iostream>

template <typename T>
class Array{
    private:
        int length = 0;
        T *items;
        int it_point = 0;
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

        template <typename U>
        friend std::ostream &operator<< (std::ostream &out, const Array<U> &array);

};

template <typename U>
std::ostream &operator<< (std::ostream &out, const Array<U> &array){
    for(int i = 0; i < array.length; ++i){
        out << array.items[i] << " ";
    }
    return out;
}
