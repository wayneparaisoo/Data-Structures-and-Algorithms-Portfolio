#ifndef QUEUELL_H
#define QUEUELL_H

template<typename T>
class qNode{
    public:
        T data;
        qNode<T>* next;
};

template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template<typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    qNode<T>* newNode = new_node(newData);

    if((*frontPtr) == nullptr && (*backPtr)==nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }

    (*backPtr)->next = newNode;
    (*backPtr) = newNode; 
}

template<typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    qNode<T>* deleteNode = nullptr;
    deleteNode = (*frontPtr);

    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;

}

template<typename T>
void checkFront(qNode<T>* frontPtr){
    if(frontPtr== nullptr){
        std::cout<< "Queue is empty"<<std::endl;
        return;
    }
    std::cout<<"The Front of the queue is: " << frontPtr->data<<std::endl;
}

template<typename T>
void checkBack(qNode<T>* backPtr){
    if(backPtr== nullptr){
        std::cout<< "Queue is empty"<<std::endl;
        return;
    }
    std::cout<< "The back of the queue is: " << backPtr->data<<std::endl;
}

template<typename T>
void display(qNode<T>* frontPtr){
    if(frontPtr == nullptr){
        std::cout<< "Queue is empty"<<std::endl;
        return;
    }
    qNode<T>* displayNode = nullptr;
    displayNode = frontPtr;

    std::cout<< "Queue List: "<< std::endl;

    while(displayNode != nullptr){
        std::cout<<displayNode->data;
        displayNode = displayNode->next;
    }
    std::cout<< std::endl;
    displayNode = nullptr;
    delete displayNode;
}
#endif