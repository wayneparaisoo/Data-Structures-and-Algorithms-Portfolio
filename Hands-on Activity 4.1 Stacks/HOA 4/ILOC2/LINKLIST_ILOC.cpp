#include <iostream>
#include <string>
#include "singlyStack.h"

int main(){
    std::string expression;
    std::cout << "Enter Expression: ";
    std::cin >> expression;

    if(isBalanced(expression))
        std::cout << "Balanced" << std::endl;
    else
        std::cout << "Unbalanced" << std::endl;
}