#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// BUBBLE SORT SIMPLE
void bubbleSortSimple(std::vector<float> &A) { // O(n^2)
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
            }
        }
    }
}

// BUBBLE SORT MEJORADO
void bubbleSortMejorado(std::vector<float> &A) { // O(n^2)
    int n = A.size();
    bool flag;
    for (int i = 0; i < n - 1; i++) {
        flag = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
                flag = true; 
            }
        }
        if (!flag) {
            break;
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

    // Bubble Sort
    dataCopy = data;
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSortSimple(dataCopy);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Bubble Sort Simple: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos." << std::endl;
    
    // Bubble Sort Mejorado
    dataCopy = data;
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSortMejorado(dataCopy);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Bubble Sort Mejorado: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos." << std::endl;
    
    return 0;
}