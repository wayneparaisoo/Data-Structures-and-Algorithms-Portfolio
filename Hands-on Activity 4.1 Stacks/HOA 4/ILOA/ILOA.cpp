#include <iostream>


const size_t maxCap = 100;
int stack[maxCap];
int top = -1, newData, elements;

bool isFull();
bool isEmpty();
void push();
void pop();
void Top();
void displayAll();

int main(){
    int choice;

    std::cout<<"Enter the number of maximum elements for the new stack (max = 100): ";
    std::cin >> elements;
    elements--;

    while(true){

        std::cout << "Stack Operations: "<<std::endl;
        std::cout << "1. Push\n2. Pop\n3. Top\n4. isEmpty\n5. isFull\n6. displayAll"<<std::endl;
        std::cin >> choice;

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout<< isEmpty()<< std::endl;
            break;
            case 5: std::cout << isFull()<<std::endl;
            break;
            case 6: displayAll();
            break;
            default: std::cout<< "Invalid Choice"<<std::endl;
            break;
        }
    }

    return 0;

}

bool isEmpty(){
    if(top == -1){
        std::cout<<"Stack Underflow"<<std::endl;
        return true;
    };
    return false;
    }

bool isFull(){
    if(top >= elements){
        std::cout<<"Stack Overflow"<<std::endl;
        return true;
    }
    return false;
}

void push(){

    if(isFull()) return;

    std::cout << "What value do you want to add to the stack?: ";
    std::cin >> newData;
    stack[++top] = newData;
}

void pop(){
    if(isEmpty()) return;

    std::cout<<"Popping: " << stack[top] << std::endl;

    top--;
}

void Top(){
    if(isEmpty()) return;

    std::cout << "The top element is: "<< stack[top] << std::endl;
}

void displayAll(){
    if(isEmpty()) return;

    std::cout<< "The elements inside the stack are: "<< std::endl;
    for(int i = top; i >= 0; i--){  
        std::cout << stack[i] << std::endl;
    }
}