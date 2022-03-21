#include <iostream>

bool Winning_combination (std::string str123, std::string xo, int max, int step, int symbol2, int symbol3) {
    bool checkWinnings = false;
    for (int i = 0; i < max; i += step) {
        std::string strField = "";
        strField = strField + str123[i] + str123[i+symbol2] + str123[i+symbol3];
        if (strField == xo) {
            checkWinnings = true;
            break;
        }
    }
    if (checkWinnings == false) {
        std::string strField1;
        std::string strField2;
        strField1 = strField1 + str123[0] + str123[4] + str123[8];
        strField2 = strField2 + str123[2] + str123[4] + str123[6];
        if (strField1 == xo || strField2 == xo) checkWinnings = true;
    }
    return checkWinnings;
}
bool Checking_characters_in_a_string (std::string str){
    bool CheckingStr = true;
    for (int i = 0; i < str.length(); i++){
        if ( str.length() != 3 || str[i] != 'X' && str[i] != 'O' && str[i] != '.') CheckingStr = false;
    }
    return CheckingStr;
}
int main() {
    std::string str1;
    std::string str2;
    std::string str3;
    for (int i = 0; i == 0 || !Checking_characters_in_a_string (str1); i++) {
        if (i > 0) std::cout << "Incorrect\n";
        std::cout << "input the playing field lines 1 (X O)\n";
        std::cin >> str1;
    }
    for (int i = 0; i == 0 || !Checking_characters_in_a_string (str2); i++) {
        if (i > 0) std::cout << "Incorrect\n";
        std::cout << "input the playing field lines 2 (X O)\n";
        std::cin >> str2;
    }
    for (int i = 0; i == 0 || !Checking_characters_in_a_string (str3); i++) {
        if (i > 0) std::cout << "Incorrect\n";
        std::cout << "input the playing field lines 3 (X O)\n";
        std::cin >> str3;
    }
    std::string str123 = str1 + str2 + str3;
    int x = 0;
    int o = 0;
    for (int i = 0; i < str123.length(); i++) {
        if (str123[i] == 'X') x++;
        if (str123[i] == 'O') o++;
    }
    bool strX = ((Winning_combination(str123, "XXX", 7, 3, 1, 2)) || (Winning_combination(str123, "XXX", 3, 1, 3, 6)));
    bool strO = ((Winning_combination(str123, "OOO", 7, 3, 1, 2)) || (Winning_combination(str123, "OOO", 3, 1, 3, 6)));
    if (x > o + 1 || o > x || (x == o && (strX == 1)) || (x > o && (strO == 1)) || strX + strO == 2) {
        std::cout << "Incorrect\n";
    } else if (strX) {
        std::cout << "Petya won.\n";
    } else if (strO) {
        std::cout << "Vanya won.\n";
    } else if (x == 0) {
        std::cout << "The game has not started \n";
    } else if (x < 5) {
        std::cout << "The game is not over \n";
    } else std::cout << "Nobody \n";
}