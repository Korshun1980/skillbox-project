#include <iostream>

int main() {
    int matrixSize = 5;
    int sequence[matrixSize][matrixSize];
    int n = 0;
    int i = 0;
    while (n < matrixSize * matrixSize){
        for (; i % 2 == 0; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                sequence[i][j] = n;
                ++n;
            }
        }
        for (; i % 2 != 0; ++i){
            for (int j = matrixSize - 1; j >= 0; --j){
                sequence[i][j] = n;
                ++n;
            }
        }
    }
    for (int i = 0; i < matrixSize; ++i){
        for (int j = 0; j < matrixSize; ++j){
            std:: cout << sequence[i][j] << " ";
        }
        std:: cout << "\n";
    }
}
