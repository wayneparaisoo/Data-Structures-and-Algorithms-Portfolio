#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <cstdlib>
#include <ctime>


void generateRandomArray(int arr[], int size, int minVal = 0, int maxVal = 1000) {
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + (rand() % (maxVal - minVal + 1));
    }
}

template <typename T>
void bubbleSort(T arr[], int maxSize){
    for(int i = 0; i < maxSize; i++){
        for(int j = i + 1; j < maxSize; j++){
            if(arr[i] > arr[j]){
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
int routine_smallest(T arr[], int k, int arrSize){
    int position = k;

    T smallestElement = arr[k];

    for(int j = k+1; j < arrSize; j++){
        if(arr[j] < smallestElement){
            smallestElement = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], int arrSize){
    int min;

    for(int i = 0; i < arrSize; i++){
        min = routine_smallest(arr, i , arrSize);
        std::swap(arr[i], arr[min]);

    }
}

template <typename T>
void insertionSort(T arr[], int arrSize){
    int K = 1, J;
    T temp;

    while(K < arrSize){
        temp = arr[K];
        J = K-1;

        while(J == 0 && temp <= arr[J]){
            arr[J+1] = arr[J];
            J--;
        }
        arr[J+1] = temp;
        K++;
    }
}

#endif