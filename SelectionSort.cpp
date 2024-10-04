#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// SELECTION SORT
void selectionSort(std::vector<float> &A) { // O(n^2)
    int n = A.size();
    for (int i = 0; i < n-1; i++) {
        int posMin = i;
        for (int j = i+1; j < n; j++) {
            if (A[posMin] > A[j]) {
                posMin = j;
            }
        }
        std::swap(A[posMin], A[i]);
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

    // Selection Sort
    dataCopy = data;
    start = std::chrono::high_resolution_clock::now();
    selectionSort(dataCopy);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Selection Sort: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos." << std::endl;

    return 0;
}