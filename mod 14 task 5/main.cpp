#include <iostream>
#include <cmath>

int main() {
    int x = 12;
    int y = 12;
    int pop = x * y;

    bool field[x][y];
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            field[i][j] = true;
        }
    }
    while (pop >= 0) {
        std::cout << "\n";
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (field[i][j]) {
                    std::cout << 'O' << " ";
                } else std::cout << 'X' << " ";
            }
            std::cout << "\n";
        }
        if (pop == 0) break;

        int startX = 0, startY = 0, endX = 0, endY = 0;

        do {
            std::cout << "Enter coordinates of the beginning of the region and the end of the rectangular region:\n";
            std::cin >> startX >> startY >> endX >> endY;
            if (startX < 1 || startY < 1 || endX < 1 || endY < 1 || startX > 12 || startY > 12 || endX > 12 || endY > 12)
                std::cout << "ERROR!!!\n";
        } while (startX < 1 || startY < 1 || endX < 1 || endY < 1 || startX > 12 || startY > 12 || endX > 12 || endY > 12);

        for (int i = fmin(startX, endX) - 1; i <= fmax(startX, endX) - 1; ++i) {
            for (int j = fmin(startY, endY) - 1; j <= fmax(startY, endY) - 1; ++j) {
                if (field[i][j] == true) {
                    std::cout << "Pop!" << " ";
                    --pop;
                    field[i][j] = false;
                }
            }
        }
    }
}