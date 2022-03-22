#include <iostream>

int main() {
    int numbers[15] = {114,111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};

    int n = 15;
    int min = numbers[0];
    int sum = 0;

    for(int i = 0; i < n; ++i)
    {
        if(min > numbers[i])
            min = numbers[i];

        sum += numbers[i];
    }

    for(int i = min; i < min + n - 1; ++i)
        sum -= i;

    std::cout << sum;
    return 0;
}

    /*int numbers[] = {114,111, 106, 107, 108, 105, 115,  117, 110, 109, 112, 113, 116, 117, 118};
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
}*/