#include <iostream>
#include <stack>

int main(){
    std::stack<int> newStack;


    std::cout<<"is the stack empty? " << newStack.empty() << std::endl;

    newStack.push(6);
    newStack.push(5);
    newStack.push(4);
    newStack.push(3);
    newStack.push(2);
    newStack.push(1);

    std::cout<<"Size of the stack is: " << newStack.size() << std::endl;


    while(newStack.empty() == 0){

        std::cout<< newStack.top()<<std::endl;
        newStack.pop();
    }

    std::cout<<"is the stack empty? " << newStack.empty() << std::endl;
    
    return 0;
}