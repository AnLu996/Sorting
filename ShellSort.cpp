#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// SHELL SORT
void shellSort(std::vector<float> &A) { // O(n^(3/2))
    int n = A.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            float temp = A[i];
            int j;
            
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            
            A[j] = temp;
        }
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

    // Shell Sort
    dataCopy = data;
    start = std::chrono::high_resolution_clock::now();
    shellSort(dataCopy);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Shell Sort: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos." << std::endl;

    return 0;
}