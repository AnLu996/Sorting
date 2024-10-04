#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// HEAP SORT
void heapify(std::vector<float> &A, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        std::swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(std::vector<float> &A) { // O(n log n)
    int n = A.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(A[0], A[i]);
        heapify(A, i, 0);
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
  
    // Heap Sort
    dataCopy = data;
    start = std::chrono::high_resolution_clock::now();
    heapSort(dataCopy);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Heap Sort: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos." << std::endl;

    return 0;
}