#include <iostream>

int main() {
    int numbers[] = {114,111, 106, 107, 108, 105, 115,  117, 110, 109, 112, 113, 116, 117, 118};
    int min = 0;
    for (int i = 0; i < 15; i++) {
        for (int k = i; k > 0 ; k--) {
            if (numbers[k] == numbers[k - 1]) {
                std::cout << numbers[k] << "\n";
                return 0;
            }
            if (numbers[k] < numbers[k - 1]) {
                min = numbers[k];
                numbers[k] = numbers[k - 1];
                numbers[k - 1] = min;
            }
        }
    }
}