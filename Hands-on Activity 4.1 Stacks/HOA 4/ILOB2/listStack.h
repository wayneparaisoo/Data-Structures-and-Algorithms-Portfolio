#ifndef LISTSTACK_H
#define LISTSTACK_H

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

#endif