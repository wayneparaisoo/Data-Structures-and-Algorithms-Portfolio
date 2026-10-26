#ifndef LISTSTACK_H
#define LISTSTACK_H

#include <iostream>
#include <string>

template <typename T>
class Node{
    public:
        T data;
        Node<T>* next = nullptr;


};

template <typename T>
Node<T>* head = nullptr;

template <typename T>
void push(T newData){
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}


template <typename T>
T pop(){
    if(isEmpty<T>()){
        std::cout<<"Stack Underflow"<<std::endl;
    }

    Node<T>* temp = head<T>;
    T tempData = temp->data;

    head<T> = head<T>->next;

    delete temp;

    return tempData;
}

template <typename T>
void Top(){
    if(isEmpty<T>()) return;

    std::cout<<"The top is: " << head<T>->data <<std::endl;
}

template <typename T>
void traverseStack(){
    if(head<T> == nullptr){
        std::cout<<"The stack is empty"<<std::endl;
    }
    while(head<T> != nullptr){
        std::cout<< head<T>->data;
        if(head<T>->next != nullptr){
            std::cout<<"->";
        }
        head<T> = head<T>->next;
    }


}

bool isMatch(char opening, char closing){
    if(opening == '(' && closing == ')') return true;
    if(opening == '{' && closing == '}') return true;
    if(opening == '[' && closing == ']') return true;
    return false;
}

bool isBalanced(const std::string& expr){
    for(size_t i = 0; i < expr.length(); i++){
        char ch = expr[i];

        if(ch == '(' || ch == '{' || ch == '['){
            push<char>(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(isEmpty<char>()){
                return false;
            }
            char opening = pop<char>();
            if(!isMatch(opening, ch)){
                return false;
            }
        }
    }

    return isEmpty<char>();
}

#endif