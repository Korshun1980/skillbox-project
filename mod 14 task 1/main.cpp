#include <iostream>

int main() {
    int cutlery[2][6];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i == 0 && (j == 2 || j == 3)) {
                cutlery[i][j] = 4;
            } else cutlery[i][j] = 3;
        }
    }
    int dishes[2][6];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i == 0 && (j == 2 || j == 3)) {
                dishes[i][j] = 3;
            } else dishes[i][j] = 2;
        }
    }
    int chairs[2][6];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            chairs[i][j] = 1;
        }
    }
    chairs[0][4] += 1;
    cutlery[1][2] -= 1;
    cutlery[0][2] -= 1;
    cutlery[1][2] += 1;
    dishes[0][2] -= 1;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j)
            std::cout << cutlery[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j)
            std::cout << dishes[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j)
            std::cout << chairs[i][j] << " ";
        std::cout << "\n";
    }
}
