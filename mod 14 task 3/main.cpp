#include <iostream>

int main() {
    int matrixSize = 4;
    bool equal = true;
    int a [matrixSize][matrixSize];
    int b [matrixSize][matrixSize];

    std::cout << "Enter the elements of the matrix A:\n";
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j){
            std::cin >> a[i][j];
        }
    }
    std::cout << "Enter the elements of the matrix B:\n";
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j){
            std::cin >> b[i][j];
        }
    }
    for (int i = 0; i < matrixSize && equal; ++i) {
        for (int j = 0; j < matrixSize; ++j){
            if (a[i][j] != b[i][j]) {
                std::cout << "Matrices are not equal.";
                equal = false;
                break;
            }
        }
    }
    if (equal) {
        std::cout << "Matrices are equal.\n";
        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j){
                if (i != j) a[i][j] = 0;
                    std::cout << a[i][j];
            } std::cout << std::endl;
        }
    }
}

