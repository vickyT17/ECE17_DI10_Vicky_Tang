#include <iostream>
#include "CustomLinkedList.h"
#include <chrono>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

int getRandomNumber(int min, int max) {
    std::random_device rd; // Seed for the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator
    std::uniform_int_distribution<int> distribution(min, max); // Uniform distribution

    return distribution(gen);
}

int main() {
    // Linear Search
    UnsortedLinkedList<int> uList;
    SortedLinkedList<int> sList;

    int list[] = {1, 9,2, 8, 3, 7, 4,
                  6, 5, 4,6, 3, 7, 2,
                  8, 1, 9, 0, 10};

    int maxVal = 1000000000;
//    std::vector<int> list = vector<int>();
//    for (int i = 0; i < maxVal; ++i){
//        list.push_back(i);
//    }

    for (int i = 0; i < 19; ++i){
        uList.append(list[i]);
        sList.insertSorted(list[i]);
    }
    uList.printList();
    sList.printList();

    cout << "Searching for 1: "  << (uList.linearSearch(1) ? "Found" : "Not Found") << endl
         << "Searching for 10: " << (uList.linearSearch(10) ? "Found" : "Not Found") << endl
         << "Searching for 11: " << (uList.linearSearch(11) ? "Found" : "Not Found") << endl << endl;

    cout << "Searching for 1: "  << (sList.binarySearch(1) ? "Found" : "Not Found") << endl
         << "Searching for 10: " << (sList.binarySearch(10) ? "Found" : "Not Found") << endl
         << "Searching for 11: " << (sList.binarySearch(11) ? "Found" : "Not Found") << endl;

    // Timing Runs:
    const int numIterations = 1000;
    const int findVal = maxVal;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, maxVal);


    auto startTimeLinear = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numIterations; ++i) {
        uList.linearSearch(findVal);
    }
    auto endTimeLinear = std::chrono::high_resolution_clock::now();

    auto startTimeBinary = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numIterations; ++i) {
        sList.binarySearch(findVal);
    }
    auto endTimeBinary = std::chrono::high_resolution_clock::now();

    auto durationLinear = std::chrono::duration_cast<std::chrono::microseconds>(endTimeLinear - startTimeLinear);
    auto durationBinary = std::chrono::duration_cast<std::chrono::microseconds>(endTimeBinary - startTimeBinary);
    // Print the average time per iteration
    std::cout << "Average time per iteration for Linear: " << durationLinear.count() / double(numIterations) << " microseconds" << std::endl;
    std::cout << "Average time per iteration for Binary: " << durationBinary.count() / double(numIterations) << " microseconds" << std::endl;
}
