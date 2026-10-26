#include "nodesupp.h"
#include <iostream>

#ifndef SEARCHALGOSUPP_H
#define SEARCHALGOSUPP_H

template <typename T>
int linearSearchArr(int arrSize, T dataFind, T list[]){

    int comparisons = 0;
    int i = 0;

    while(i < arrSize){
        comparisons++;
        if(dataFind == list[i]){
            std::cout << "Searching is successful. Found '" << dataFind
                       << "' at index " << i << " using "
                       << comparisons << " comparison(s).\n";
            return comparisons;
        }
        i++;
    }

    std::cout << "Searching is Unsuccessful after "
               << comparisons << " comparison(s)." << std::endl;
    return comparisons;
}


template <typename T>
int linearSearchLL(Node<T>* head, T dataFind){

    int comparisons = 0;
    int position = 0;

    while(head != nullptr){
        comparisons++;
        if(head->data == dataFind){
            std::cout << "Searching is Successful. Found '" << dataFind
                       << "' at position " << position << " using "
                       << comparisons << " comparison(s).\n";
            return comparisons;
        }
        head = head->next;
        position++;
    }

    std::cout << "Searching is Unsuccessful after "
               << comparisons << " comparison(s)." << std::endl;
    return comparisons;
}


template <typename T>
int countSearchArr(int arrSize, T dataFind, T list[]){

    int comparisons = 0;
    int occurrences = 0;

    for(int i = 0; i < arrSize; i++){
        comparisons++;
        if(list[i] == dataFind){
            occurrences++;
        }
    }

    std::cout << "'" << dataFind << "' occurs " << occurrences
               << " time(s) in the array (checked with "
               << comparisons << " comparison(s)).\n";
    return occurrences;
}

template <typename T>
int countSearchLL(Node<T>* head, T dataFind){

    int comparisons = 0;
    int occurrences = 0;

    while(head != nullptr){
        comparisons++;
        if(head->data == dataFind){
            occurrences++;
        }
        head = head->next;
    }

    std::cout << "'" << dataFind << "' occurs " << occurrences
               << " time(s) in the linked list (checked with "
               << comparisons << " comparison(s)).\n";
    return occurrences;
}


template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){

    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){
        slow = slow->next;
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
            break;
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
int binarySearchArr(int arrSize, T dataFind, T list[]){

    int low = 0;
    int high = arrSize - 1;
    int iteration = 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        std::cout << "Iteration " << iteration
                   << ": low=" << low  << " (val=" << list[low]  << "), "
                   << "high=" << high << " (val=" << list[high] << "), "
                   << "mid="  << mid  << " (val=" << list[mid]  << ")\n";

        if(list[mid] == dataFind){
            std::cout << "  --> Match! Searching is successful. Found '"
                       << dataFind << "' at index " << mid
                       << " in " << iteration << " iteration(s).\n";
            return mid;
        } else if(list[mid] < dataFind){
            std::cout << "  --> " << list[mid] << " < " << dataFind
                       << "  =>  search RIGHT half\n";
            low = mid + 1;
        } else {
            std::cout << "  --> " << list[mid] << " > " << dataFind
                       << "  =>  search LEFT half\n";
            high = mid - 1;
        }
        iteration++;
    }

    std::cout << "Searching is Unsuccessful" << std::endl;
    return -1;
}


template <typename T>
int binarySearchArrRecursive(T list[], T dataFind, int low, int high, int iteration = 1){

    if(low > high){
        std::cout << "Searching is Unsuccessful" << std::endl;
        return -1;
    }

    int mid = low + (high - low) / 2;

    std::cout << "Iteration " << iteration
               << ": low=" << low  << " (val=" << list[low]  << "), "
               << "high=" << high << " (val=" << list[high] << "), "
               << "mid="  << mid  << " (val=" << list[mid]  << ")\n";

    if(list[mid] == dataFind){
        std::cout << "  --> Match! Searching is successful. Found '"
                   << dataFind << "' at index " << mid
                   << " in " << iteration << " iteration(s).\n";
        return mid;
    } else if(list[mid] < dataFind){
        std::cout << "  --> " << list[mid] << " < " << dataFind
                   << "  =>  search RIGHT half\n";
        return binarySearchArrRecursive(list, dataFind, mid + 1, high, iteration + 1);
    } else {
        std::cout << "  --> " << list[mid] << " > " << dataFind
                   << "  =>  search LEFT half\n";
        return binarySearchArrRecursive(list, dataFind, low, mid - 1, iteration + 1);
    }
}

#endif
