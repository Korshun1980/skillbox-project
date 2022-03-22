#include <iostream>

int main() {
    std::cout << "Input 15 fractional numbers: \n";
    float max = 0;
    float numbers[15];
    for (int i = 0; i < 15; i++) {
        std::cin >> numbers[i];
        for (int k = i; k > 0 ; k--) {
            if (numbers[k] > numbers[k - 1]) {
                max = numbers[k];
                numbers[k] = numbers[k - 1];
                numbers[k - 1] = max;
            }
        }
    }
    for (int i = 0; i < 15; i++) {
        std::cout << numbers[i] << ", ";
    }
}
