#include <iostream>
#include "nodesupp.h"
#include "searchAlgoSupp.h"

// Builds a singly linked list from an array, preserving order.
template <typename T>
Node<T>* buildLinkedList(T arr[], int size){
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    for(int i = 0; i < size; i++){
        Node<T>* n = new_node(arr[i]);
        if(head == nullptr){
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    return head;
}

int main(){
    //Problem 1 & 2
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    Node<int>* head = buildLinkedList(arr, arrSize);

    std::cout << "Problem 1: Sequential Search for key '18'\n";

    std::cout << "Array-based Sequential Search\n";
    linearSearchArr(arrSize, 18, arr);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout <<"Linked-List-based Sequential Search\n";
    linearSearchLL(head, 18);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Problem 2: Count of repeating instances\n";

    std::cout << std::endl;

    std::cout << "Array: count of '18'\n";
    countSearchArr(arrSize, 18, arr);

    std::cout << std::endl;

    std::cout << "Linked List: count of '18'\n";
    countSearchLL(head, 18);

    std::cout << std::endl;

    std::cout << "Array: count of '14'\n";
    countSearchArr(arrSize, 14, arr);

    std::cout << std::endl;

    std::cout << "Array: count of '19'\n";
    countSearchArr(arrSize, 19, arr);

    std::cout << std::endl;

    std::cout << "Array: count of '0'\n";
    countSearchArr(arrSize, 0, arr);

    std::cout << std::endl;

    //Problem 3 & 4
    int sortedArr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int sortedSize = sizeof(sortedArr) / sizeof(sortedArr[0]);

    std::cout << "Problem 3: Iterative Binary Search for key '8'\n";

    binarySearchArr(sortedSize, 8, sortedArr);

    std::cout << std::endl;

    std::cout << "Problem 4: Recursive Binary Search for key '8'\n";

    binarySearchArrRecursive(sortedArr, 8, 0, sortedSize - 1);

    std::cout << std::endl;

    return 0;
}
