#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingp.h"

const int maxSize = 100;

void displayAll(int arr[]);
void copyArr(int source[], int destination[]);

int main() {
    int unsortedArr[maxSize];
    int copiedArr[maxSize];
    srand(time(0));
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 100;
    }

    std::cout << "Unsorted Array: ";
    displayAll(unsortedArr);

    std::cout << "\nShell Sort: ";
    copyArr(unsortedArr, copiedArr);
    shellSort(copiedArr, maxSize);
    displayAll(copiedArr);

    std::cout << "\nMerge Sort: ";
    copyArr(unsortedArr, copiedArr);
    mergeSort(copiedArr,0 , maxSize - 1);
    displayAll(copiedArr);

    std::cout << "\nQuick Sort: ";
    copyArr(unsortedArr, copiedArr);
    quickSort(copiedArr,0 , maxSize - 1);
    displayAll(copiedArr);


    return 0;
}


void displayAll(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void copyArr(int source[], int destination[]){
    for(int i = 0; i < maxSize; i++){
        destination[i] = source[i];
    }
}