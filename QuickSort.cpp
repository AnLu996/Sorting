#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// QUICK SORT
int partition(std::vector<float> &A, int low, int high) {
    float pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    
    std::swap(A[i + 1], A[high]);
    return (i + 1);
}

void quickSort(std::vector<float> &A, int low, int high) { // O(n log n)
    if (low < high) {
        int pi = partition(A, low, high);

        quickSort(A, low, pi - 1);  
        quickSort(A, pi + 1, high);
    }
}

int main() {
    std::vector<float> data;
    float number;

    auto start1 = std::chrono::high_resolution_clock::now();
    while (std::cin >> number) {
        data.push_back(number);
    }
    auto end1 = std::chrono::high_resolution_clock::now();

    std::cout << "Tiempo de llenado: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microsegundos." << std::endl;

    std::vector<float> dataCopy;

    // Quick Sort
    dataCopy = data;
    start = std::chrono::high_resolution_clock::now();
    quickSort(dataCopy, 0, dataCopy.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Quick Sort: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos." << std::endl;

    return 0;
}