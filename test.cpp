#include <iostream>

int main(){
    int a[3] = {1,4,3};
    int b[3];
    memcpy(b, a, sizeof(int)*3);

    for(int i = 0; i < 3; ++i){
        std::cout << "a:" << a[i] << "    b:" << b[i] << std::endl;
    }
}