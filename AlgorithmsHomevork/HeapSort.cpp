#include <iostream>
#include <vector>

void heapifyArray(std::vector<int>& data, int totalElements, int currentIndex) {
    int largestIndex = currentIndex;
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;

    if (leftChildIndex < totalElements && data[leftChildIndex] > data[largestIndex])
        largestIndex = leftChildIndex;

    if (rightChildIndex < totalElements && data[rightChildIndex] > data[largestIndex])
        largestIndex = rightChildIndex;

    if (largestIndex != currentIndex) {
        std::swap(data[currentIndex], data[largestIndex]);
        heapifyArray(data, totalElements, largestIndex);
    }
}

void constructMaxHeap(std::vector<int>& data, int totalElements) {
    for (int i = totalElements / 2 - 1; i >= 0; i--) {
        heapifyArray(data, totalElements, i);
    }
}

void executeHeapSort(std::vector<int>& data, int totalElements) {
    constructMaxHeap(data, totalElements);

    for (int i = totalElements - 1; i > 0; i--) {
        std::swap(data[0], data[i]);
        heapifyArray(data, i, 0);
    }
}

void displayArray(const std::vector<int>& data) {
    for (const int& value : data)
        std::cout << value << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = { 12, 11, 13, 5, 6, 7 };

    std::cout << "Unsorted array: ";
    displayArray(data);

    int totalElements = data.size();
    executeHeapSort(data, totalElements);

    std::cout << "Sorted array: ";
    displayArray(data);

    return 0;
}
