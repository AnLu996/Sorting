#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// INSERTION SORT
void insertionSort(std::vector<float> &A) { // O(n^2)
    int n = A.size();
    for (int i = 1; i < n; i++) {
        float key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
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

    // Insertion Sort
    dataCopy = data;
    start = std::chrono::high_resolution_clock::now();
    insertionSort(dataCopy);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Insertion Sort: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos." << std::endl;

    return 0;
}