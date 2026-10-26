#ifndef SUPPSORT_H 
#define SUPPSORT_H

#include <utility>

template <typename T>
void insertionSort(T arr[], int arrSize){ 
    int k = 1, j;
    T temp;

    while(k <arrSize){ 
        temp = arr[k];
        j = k - 1;
        
        while(j >= 0 && temp < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }    
        arr[j+1] = temp; 
        k++;
    }
}

template <typename T>
int partition(T arr[], int low, int high){
    T pivot = arr[high];
    int i = low- 1;
    
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]); 
    return i + 1;
}

template <typename T>
void quickSortHybrid(T arr[], int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        insertionSort(arr + low, pivotIndex - low); 
        insertionSort(arr + pivotIndex + 1, high - pivotIndex);
    }
}

#endif