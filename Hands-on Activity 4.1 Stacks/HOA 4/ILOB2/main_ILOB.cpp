#include <iostream>
#include "listStack.h"

int main(){


    std::cout<<"------ Pushing 'I' 'C' 'P' 'E' 'P' ------\n";

    push('I');
    push('C');
    push('P');
    push('E');
    push('P');

    Top<char>();

    std::cout<<"------ Inside the Stack ------\n";
    traverseStack<char>();


    std::cout<<"\n------ popping 'P' 'E' 'P' 'C' 'I' ------\n";
    while(!isEmpty<char>()){
        std::cout<<"popping: "<<pop<char>()<<std::endl;
    }

    pop<char>();

    return 0;
}