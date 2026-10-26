#ifndef SUPPSORTING_H
#define SUPPSORTING_H

#include <iostream>
#include <cstdlib>
#include <ctime>


void generateRandomArray(int arr[], int size, int minVal = 0, int maxVal = 1000) {
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + (rand() % (maxVal - minVal + 1));
    }
}

template <typename T>
void insertionSort(T arr[], int arrSize) {
    int K = 1, J;
    T temp;
 
    while (K < arrSize) {
        temp = arr[K];
        J = K - 1;
 
        while (J >= 0 && temp <= arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
        K++;
    }
}


#endif