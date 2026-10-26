#include <iostream>

int main(){
    int temp;
    int x = 19;
    int y = 20;
    temp = x;
    x = y;
    y = temp;

    std::cout<< "X = " << x << std::endl<< "Y = " << y;
}