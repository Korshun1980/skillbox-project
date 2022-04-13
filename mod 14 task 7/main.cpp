#include <iostream>

int main() {

    int field[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << "Enter sector height: (" << i+1 << " : " << j+1 << ") 0 to 10:\n";
            std::cin >> field[i][j];
            while (field[i][j] < 0 || field[i][j] > 10) {
                std::cout << "ERROR!!!\nEnter sector height: (" << i+1 << " : " << j+1 << ") 0 to 10:\n";
                std::cin >> field[i][j];
            }
        }
    }
    int cubField[5][5][10];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int h = 0; h < 10; ++h) {
                if (field[i][j] - h > 0) {
                    cubField[i][j][h] = 1;
                } else cubField[i][j][h] = 0;
            }
        }
    }

    int l = 0;

    do {
        std::cout << "\nwhat level to watch (1 to 10) ?\n";
        std::cin >> l;
        if (l == 100) break;
        if (l < 1 || l > 10) {
            std::cout << "ERROR!!! (level 1 to 10) ?\n";
        } else {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    std::cout << cubField[i][j][l-1] << " ";
                }
                std::cout << "\n";
            }
        }
    } while (l != 100);

    /*for (int h = 0; h < 10; ++h) {
        std::cout << "Level " << h << ":\n";
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                std::cout << cubField[i][j][h] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }*/
}
