#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

void printArrayRecursiveHelper(const std::vector<int>& arr, size_t index) {
    if (index >= arr.size()) {
        return;
    }
    std::cout << std::setw(4) << arr[index];
    printArrayRecursiveHelper(arr, index + 1);
}

void printArray(const std::vector<int>& arr) {
    std::cout << "[ ";
    printArrayRecursiveHelper(arr, 0);
    std::cout << " ]" << std::endl;
}

int findMinIndexRecursive(const std::vector<int>& arr, size_t index, int currentMinIdx) {
    if (index >= arr.size()) {
        return currentMinIdx;
    }

    int newMinIdx = currentMinIdx;
    if (arr[index] < arr[currentMinIdx]) {
        newMinIdx = index;
    }

    return findMinIndexRecursive(arr, index + 1, newMinIdx);
}

int findMaxIndexRecursive(const std::vector<int>& arr, size_t index, int currentMaxIdx) {
    if (index >= arr.size()) {
        return currentMaxIdx;
    }

    int newMaxIdx = currentMaxIdx;
    if (arr[index] > arr[currentMaxIdx]) {
        newMaxIdx = index;
    }

    return findMaxIndexRecursive(arr, index + 1, newMaxIdx);
}

bool swapMinMaxRecursive(std::vector<int>& arr) {
    if (arr.empty()) return false;

    int minIdx = findMinIndexRecursive(arr, 1, 0);
    int maxIdx = findMaxIndexRecursive(arr, 1, 0);

    if (minIdx != maxIdx) {
        std::swap(arr[minIdx], arr[maxIdx]);
        return true;
    }
    return false;
}

int main() {
    std::vector<int> myArray = { 10, 3, 99, -15, 2, 50 };

    std::cout << "--- RECURSIVE METHOD ---" << std::endl;

    std::cout << "Original array: ";
    printArray(myArray);

    bool isChanged = swapMinMaxRecursive(myArray);

    if (isChanged) {
        std::cout << "Modified array: ";
        printArray(myArray);
    }
    else {
        std::cout << "Array was not modified." << std::endl;
    }

    return 0;
}