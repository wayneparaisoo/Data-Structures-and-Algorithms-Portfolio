#include <iostream>
#include <cstdlib>
#include <time.h>
#include "node.h"
#include "searchAlgo.h"

const int max_size = 50;

int main(){
    //generate random values
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand();
    }

    //show your datasets content
    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Linear Search Array Result: "<< std::endl;
    int userInput;
    std::cout<<"What number to number to search?: ";
    std::cin >> userInput;
    linearSearchArr(max_size, userInput, dataset);

    Node<char>* name1 = new_node('W');
    Node<char>* name2 = new_node('A');
    Node<char>* name3 = new_node('Y');
    Node<char>* name4 = new_node('N');
    Node<char>* name5 = new_node('E');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = nullptr;

    std::cout << std::endl;
    std::cout << "Linked list LS Result: "<< std::endl;
    linearSearchLL(name1, 'Y');
    linearSearchLL(name1, 'Z');


    //for binary linked list
    Node<int>* value1 = new_node(2);
    Node<int>* value2 = new_node(7);
    Node<int>* value3 = new_node(9);
    Node<int>* value4 = new_node(11);
    Node<int>* value5 = new_node(16);

    value1->next = value2;
    value2->next = value3;
    value3->next = value4;
    value4->next = value5;
    value5->next = nullptr;

    std::cout << std::endl;
    std::cout << "Linked list BS Result: "<< std::endl;
    binarySearchLL(value1, 11);
    binarySearchLL(value1, 0211);



    //for binary array search

    for(int i = 0; i < max_size - 1; i++){
        for(int j = 0; j < max_size - i - 1; j++){
            if(dataset[j] > dataset[j + 1]){
                int temp = dataset[j];
                dataset[j] = dataset[j + 1];
                dataset[j + 1] = temp;
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Sorted dataset: " << std::endl;
    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Binary Search Array Result: " << std::endl;
    binarySearchArr(max_size, userInput, dataset);

    return 0;
}