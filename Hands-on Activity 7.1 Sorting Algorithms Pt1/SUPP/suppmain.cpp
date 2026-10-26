#include <iostream>
#include <string>
#include "suppsorting.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    srand(static_cast<unsigned int>(time(0)));

    const int SIZE = 101;
    int dataset[SIZE];

    const int NUM_CANDIDATES = 5;
    std::string candidateNames[NUM_CANDIDATES + 1] = {
        "",
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    generateRandomArray(dataset, SIZE, 1, 5);
    
    std::cout << "Unsorted dataset (" << SIZE << " elements):" << std::endl;
    printArray(dataset, SIZE);

    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout << "Sorted Votes (Lowest to Highest): " << std::endl;
    insertionSort(dataset, SIZE);
    printArray(dataset, SIZE);

    std::cout<<std::endl;
    std::cout<<std::endl;

    int counts[NUM_CANDIDATES + 1] = {0};
 
    for (int i = 0; i < SIZE; i++) {
        counts[dataset[i]]++;
    }
 
    std::cout << "Vote tally:" << std::endl;
    for (int candidate = 1; candidate <= NUM_CANDIDATES; candidate++) {
        std::cout << "Candidate " << candidate << " (" << candidateNames[candidate] << "): "
                   << counts[candidate] << " votes" << std::endl;
    }
    std::cout << std::endl;

    int winner = 1;
    for (int candidate = 2; candidate <= NUM_CANDIDATES; candidate++) {
        if (counts[candidate] > counts[winner]) {
            winner = candidate;
        }
    }
 
    std::cout << "Winning candidate: " << candidateNames[winner]
               << " with " << counts[winner] << " votes" << std::endl;
 
}