#include <iostream>

int main() {
    char xo[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            if (i % 2 != 0) {
                if (j % 2 != 0){
                    xo[i][j] = '+';
                } else xo[i][j] = '-';
            } else if (j % 2 != 0) {
                xo[i][j] = '|';
            } else xo[i][j] = ' ';
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            std::cout << xo[i][j] << " ";
        std::cout << "\n";
    }
    char x_or_o = ' ';
    for (int k = 0;; ++k) {
        if (k == 0 || k % 2 == 0) {
            x_or_o = 'X';
        } else x_or_o = 'O';
        std::cout << "Enter coordinates:";
        int i;
        int j;

        do {
            std::cin >> i >> j;
            i = (i - 1) * 2;
            j = (j - 1) * 2;

            if (xo[i][j] != ' ' || i > 5 || j > 5 || i < 0 || j < 0)
                std::cout << "ERROR!!! Re-enter coordinates:";
        } while (xo[i][j] != ' ' || i > 5 || j > 5 || i < 0 || j < 0);

        xo[i][j] = x_or_o;

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j)
                std::cout << xo[i][j] << " ";
            std::cout << "\n";
        }
            if (k > 3 && ((xo[i][0] == xo[i][2] && xo[i][2] == xo[i][4]) || (xo[0][j] == xo[2][j] && xo[2][j] == xo[4][j])
            // Плюс диагонали!!! Ниже попробовал через цикл но наверное не правильно т.к. цикл у меня получился хуже чем if.
                    || (xo[0][0] == xo[2][2] && xo[2][2] == xo[4][4]) || (xo[0][4] == xo[2][2] && xo[2][2] == xo[4][0]))) {
                std::cout << "Won " << x_or_o << "\n";
                break;
       }
        //????????????????????????????
        /*int checkboxI = 0;
        int checkboxJ = 0;
        for (int n = 0; n < 5; n += 2) {
            if (xo[i][n] == x_or_o) ++checkboxI;
            if (xo[n][j] == x_or_o) ++checkboxJ;
        }
        if (checkboxI == 3 || checkboxJ == 3) {
            std::cout << "Won " << x_or_o << "\n";
            break;
        }*/

        if (k == 8) {
            std::cout << "No winner \n";
            break;
        }
    }
}
