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

        Array(int len){
            this->length=len;
            this->items = new T[this->length];
        }

        Array(int len, T *items){
            this->length=len;
            this->items = new T[this->length];
            for(int i = 0; i < length; ++i){
                this->items[i]=items[i];
                ++it_point;
            }
        }
        void resizeArray(int newLen, T *newItems){
            this->length = newLen;
            delete this->items;
            this->items = new T[this->length];
            for(int i = 0; i < length; ++i){
                this->items[i]=newItems[i];
                ++it_point;
            }
        }

        void resizeArray(int newLen){
            this->length = newLen;
            delete this->items;
            this->items = new T[this->length];
            it_point = 0;
        }

        void printArray(){
            for(int i = 0; i < length; ++i){
                std::cout << items[i] << std::endl;
            }
        }

        void addItem(T item){
            *(items + it_point) = item;
            ++it_point;
        }

        template <typename U>
        friend std::ostream &operator<< (std::ostream &out, const Array<U> &array);

        template <typename U>
        friend std::istream &operator>> (std::istream &in, Array<U> &array);
};

template <typename U>
std::ostream &operator<< (std::ostream &out, const Array<U> &array){
    for(int i = 0; i < array.length; ++i){
        out << array.items[i] << " ";
    }
    return out;
} 

template <typename U>
std::istream &operator>>(std::istream &in, Array<U> &array){
    U it;
    while (in >> it) {
        array.addItem(it);
    } 
    return in;
}

