#include <iostream>

template <typename T>
Array<T>::Array(){
    length = 0;
    items = nullptr;
}

template<typename T>
Array<T>::Array(int len, T *items){
    this->length=len;
    this->items = new T[this->length];
    for(int i = 0; i < length; ++i){
        this->items[i]=items[i];
    }
}

template <typename T>
void Array<T>::printArray(){
    for(int i = 0; i < length; ++i){
        std::cout << items[i] << std::endl;
    }
}