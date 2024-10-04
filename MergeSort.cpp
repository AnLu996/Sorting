#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// MERGE SORT
void merge(std::vector<float> &A, int p, int m, int q) {
    int size = q - p + 1;
    std::vector<float> tmp(size);
    int i = p;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= q) {
        if (A[i] <= A[j]) {
            tmp[k++] = A[i++];
        } else {
            tmp[k++] = A[j++];
        }
    }

    while (i <= m) tmp[k++] = A[i++];
    while (j <= q) tmp[k++] = A[j++];

    for (int i = 0; i < size; i++) {
        A[p + i] = tmp[i];
    }
}

void mergeSort(std::vector<float> &A, int p, int q) {
    if (p < q) {
        int m = (p + q) / 2;
        mergeSort(A, p, m);
        mergeSort(A, m + 1, q);
        merge(A, p, m, q);
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

    // Merge Sort
    dataCopy = data;
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(dataCopy, 0, dataCopy.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Merge Sort: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos." << std::endl;

    return 0;
}