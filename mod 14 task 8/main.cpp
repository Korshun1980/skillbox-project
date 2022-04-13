#include <iostream>
#include <cmath>

void allShip (bool field [][10]) {
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (i == 0 && j == 0) {
                std::cout << " " << " ";
            } else if (i == 0) {
                std::cout << j << " ";
            } else if (j == 0) {
                std::cout << i << " ";
            } else if (field[i-1][j-1]) {
                std::cout << "X" << " ";
            } else
                std::cout << " " << " ";
        }
        std::cout << std::endl;
    }
}

void addShips (bool field [][10], int player) {

    int deck = 1;
    int startX, startY, endX, endY;
    for (int allShip = 1; allShip < 11; ++allShip) {
        std::cout << "\nPlayer " << player << " enter the coordinates of "<< deck <<" deck ship:\n";

        int counter = 0;
        bool overlayCheck;
        int minX;
        int maxX;
        int minY;
        int maxY;

        do {
            if (counter > 0) std::cout << "ERROR!!! try again:\n";
            std::cin >> startX >> startY;
            if (deck == 1) {
                endX = startX;
                endY = startY;
            } else std::cin >> endX >> endY;
            --startX;
            --startY;
            --endX;
            --endY;

            minX = fmin (startX, endX);
            maxX = fmax (startX, endX);
            minY = fmin (startY, endY);
            maxY = fmax (startY, endY);

            overlayCheck = false;

            for (int i = minX; i <= maxX; ++i) {
                if (field[i][minY]) {
                    overlayCheck = true;
                }
            }
            for (int i = minY + 1; i <= maxY; ++i) {
                if (field[minX][i]) {
                    overlayCheck = true;
                }
            }
            ++counter;
        } while (startX < 0 || startY < 0 || endX < 0 || endY < 0 || startX > 9 || startY > 9 || endX > 9 || endY > 9 ||
               (overlayCheck) || (startX != endX && startY != endY) ||
               ((maxX - minX) != (deck - 1) && (maxY - minY) != (deck - 1)));

        for (int i = minX; i <= maxX; ++i) {
            field[i][minY] = true;
        }
        for (int i = minY + 1; i <= maxY; ++i) {
            field[minX][i] = true;
        }
        if (allShip == 4) ++deck;
        if (allShip == 7) ++deck;
        if (allShip == 9) ++deck;
    }
}

int attacks (bool field [][10], int player, int hitOfMark) {
    int counter = 0;
    int X, Y;
    while (counter == 0) {
        std::cout << "\nPlayer " << player << " enter attack coordinates:\n";
        counter = 0;
        do {
            if (counter > 0) std::cout << "ERROR!!! try again:\n";
            std::cin >> X >> Y;
            --X;
            --Y;

            if (field [X][Y]) {
                std::cout << "Exactly!!!\n";
                field[X][Y] = false;
                ++hitOfMark;
                if (hitOfMark == 20) {
                    std::cout << "\n" << hitOfMark << " EXACTLY!!!\n";
                    std::cout << "Player "<< player <<" won!!!\n";
                    allShip(field);
                    exit(0);
                }
                --counter;
            } else std::cout << "Off target\n";
            ++counter;
        } while (X < 0 || Y < 0 || X > 9 || Y > 9);
    } std::cout << "\n" << hitOfMark << " EXACTLY!!!\n";
    return hitOfMark;
}

int main() {

    bool field1 [10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            field1[i][j] = false;
        }
    }

    bool field2 [10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            field2[i][j] = false;
        }
    }

    addShips (field1, 1);
    allShip (field1);
    addShips (field2, 2);
    allShip (field2);

    int hitOfMark1 = 0;
    int hitOfMark2 = 0;

    while (true) {
        hitOfMark1 = attacks (field2, 1, hitOfMark1);
        allShip(field2);
        hitOfMark2 = attacks (field1, 2, hitOfMark2);
        allShip(field1);
    }
}
