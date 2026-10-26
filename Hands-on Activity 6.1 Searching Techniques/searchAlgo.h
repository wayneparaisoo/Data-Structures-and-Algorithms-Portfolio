#include "node.h"

#ifndef SEARCHALGO_H
#define SEARCHALGO_H

template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[]){

    int i = 0;

    while(i < arrSize){
        if(dataFind == list[i]){
            std::cout<< "Searching is successful, \n";
            return;
        }
        i++;
    }

    std::cout<< "Searching is Unsuccessful" << std::endl;
}

template <typename T>
void linearSearchLL(Node<T>* head, T dataFind){
    while(head != nullptr){
        if(head->data == dataFind){
            std::cout<<"Searching is Successful. \n";
            return;
        }
        head = head->next;
    }
    std::cout<< "Searching is Unsuccessful" << std::endl;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){

    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){

        //move slow one step
        slow = slow->next;

        //move fast two steps
        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){

    Node<T>* last = nullptr;

    while(start != last){
        Node<T>* mid = getMiddle(start, last);

        if(mid == nullptr){
            return;
        }

        if(mid->data == dataFind){
            std::cout << "Searching is Successful. \n";
            return;
        } else if(mid->data < dataFind){
            start = mid->next;
        } else {
            last = mid;
        }
    }

        std::cout << "Searching is Unsuccessful" << std::endl;
}

template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]){

    int low = 0;
    int high = arrSize - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(list[mid] == dataFind){
            std::cout << "Searching is successful, \n";
            return;
        } else if(list[mid] < dataFind){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << "Searching is Unsuccessful" << std::endl;
}
#endif