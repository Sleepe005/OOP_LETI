#pragma once
#include <iostream>

template <typename T>
class DynamicArray{
    private:
        T *array;
        int maxCapacity = 0;
        int currentLength = 0;

        void moveItemsRight(int firstItem_ind){
            if(currentLength+1 > maxCapacity){resizeArray();}
            for(int i = currentLength; i >= firstItem_ind; i--){
                array[i+1] = array[i];
            }
        }

        void moveItemsLeft(int firstItem_pos, int lastItem_pos){
            for(int i = firstItem_pos; i <= lastItem_pos; i++){
                array[i-1] = array[i];
            }
        }

        void copyToNewArray(T *dist_arr, const T *src_arr, int len){
            if(src_arr != nullptr){
                for(int i = 0; i < len; ++i){
                    dist_arr[i] = src_arr[i];
                }
            }
        }

        void resizeArray(){
            int newCapacity = (maxCapacity == 0 ? 2 : maxCapacity * 2);
            T *newArray = new T[newCapacity];

            copyToNewArray(newArray, array, currentLength);

            delete[] array;
            array = newArray;
            maxCapacity = newCapacity;
        }


    public:
        DynamicArray(){
            array = nullptr;
        }

        ~DynamicArray(){
            delete[] array;
        }

        DynamicArray(int len){
            maxCapacity = len;
            array = new T[maxCapacity];
        }

        DynamicArray(int len, const T *src_arr, int src_len){
            maxCapacity = len;
            this->array = new T[maxCapacity];
            for(int i = 0; i < src_len; ++i){
                pushBack(src_arr[i]);
            }            
        }

        void pushBack(T item){
            if(currentLength >= maxCapacity){resizeArray();}
            array[currentLength++] = item;
        }

        void pushBack(T *items, int len){
            for(int i = 0; i < len; ++i){
                pushBack(items[i]);
            }
        }

        void pushFront(T item){
            moveItemsRight(0);
            array[0] = item;
            currentLength++;
        }

        // TODO: ошибка при вставке в последнюю позицию
        void insert(T item, int position){
            if(position > currentLength){
                throw "array out of";
            }
            
            moveItemsRight(position);
            array[position] = item;
            currentLength++;
        }

        void popBack(){
            currentLength--;
        }

        void popFront(){
            currentLength--;
            moveItemsLeft(1, currentLength);
        }

        void deleteItem(int position){
            moveItemsLeft(position+1, currentLength);
            currentLength--;
        }

        int length(){
            return currentLength;
        }

        void printArray(){
            for(int i = 0; i < currentLength; ++i){
                // printf("%d ", array[i]);
                std::cout << array[i] << ' ';
            }
            // printf("\n");
            std::cout << std::endl;
        }

        // int& opeartor[](size_t index){
            
        // } 
       T& operator[](size_t index){
            if(index > currentLength){throw "Error";}
            return array[index];
       }
};