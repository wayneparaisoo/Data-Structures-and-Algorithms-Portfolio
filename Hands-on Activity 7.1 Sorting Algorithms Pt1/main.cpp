#include <iostream>
#include "sorting.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int SIZE = 100;
    int dataset[SIZE];

    generateRandomArray(dataset, SIZE, 0, 10);

    std::cout << "Unsorted dataset (" << SIZE << " elements):" << std::endl;
    printArray(dataset, SIZE);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Bubble sort: " << std::endl;
    bubbleSort(dataset, SIZE);
    printArray(dataset, SIZE);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Selection sort: " << std::endl;
    selectionSort(dataset, SIZE);
    printArray(dataset, SIZE);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Insertion sort: " << std::endl;
    insertionSort(dataset, SIZE);
    printArray(dataset, SIZE);

    return 0;
}