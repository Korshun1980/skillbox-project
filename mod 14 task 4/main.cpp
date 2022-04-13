#include <iostream>
#include <vector>

int main() {
    int size = 4;
    std::vector<float> vec(size);
    std::vector<float> newVec(size);
    float matrix[size][size];

    std::cout << "Enter vector elements:\n";
    for (int i = 0; i < size; ++i)
        std::cin >> vec[i];

    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            std::cin >> matrix[i][j];
            matrix[i][j] *= vec[j];
            newVec[j] += matrix[i][j];
        }
    }
    for (int i = 0; i < size; ++i)
        std::cout << newVec[i] << " ";
}
