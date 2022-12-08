#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

short totalChar (std::string directory, short* p_banknoteDenominations) {
    std::ifstream aTMInt (directory);
    while (!(aTMInt.is_open())){
        std::cout << "\nERROR!!! Input valid directory\n";
        getline(std::cin, directory);
        aTMInt.open(directory);
    }
    short totalBanknotes = -1;
    while (!aTMInt.eof()) {
        char banknotes = ' ';
        aTMInt >> banknotes;
        for (short i = 0; i < 6; ++i) {
            if (banknotes-48 == i) ++p_banknoteDenominations[i];
        }
        ++totalBanknotes;
    }
    aTMInt.close();
    return totalBanknotes;
}

void addingBanknotes(std::string directory, short totalBanknotes) {
    if (totalBanknotes != 1000) {
        std::srand(std::time(nullptr));
        std::ofstream aTMof(directory, std::ios::app);
        while (!(aTMof.is_open())){
            std::cout << "\nERROR!!! Input valid directory\n";
            getline(std::cin, directory);
            aTMof.open(directory, std::ios::app);
        }
        for (short i = 0; i < 1000 - totalBanknotes; ++i) {
            aTMof << std::rand() % 6;
        }
        aTMof.close();
        std::cout << "Ok!!! ATM topped up!\n";
    } else std::cout << "The ATM is already full!\n";
}

void removalBanknotes(std::string directory, short* p_banknoteDenominations) {
    std::cout << "Enter the amount you want to withdraw:\n";
    int sum = 100;
    short nominations[6] = {100, 200, 500, 1000, 2000, 5000};
    while (sum != 0) {
        short i = 5;
        std::cin >> sum;
        while (sum > 0 && i >= 0)  {
            while (sum >= nominations[i] && p_banknoteDenominations[i] > 0) {
                sum -= nominations[i];
                --p_banknoteDenominations[i];
            }
            --i;
        }
        if (i < 0 && sum != 0) {
            std::cout << "Sorry!!! The ATM cannot dispense this amount. Enter another amount\n";
            for (short i = 0; i < 6; ++i) {
                p_banknoteDenominations[i] = 0;
            }
            totalChar(directory, p_banknoteDenominations);
        } else {
            std::ofstream aTMof(directory);
            while (!(aTMof.is_open())){
                std::cout << "\nERROR!!! Input valid directory\n";
                getline(std::cin, directory);
                aTMof.open(directory);
            }
            for (short i = 0; i < 6; ++i) {
                for (short j = 0; j < p_banknoteDenominations[i]; ++j) {
                    aTMof << i;
                }
            }
            aTMof.close();
            std::cout << "Ok!!! Take the money!\n";
            break;
        }
    }
}

int main() {
    std::string directory = "C:\\Users\\korsh\\skillbox-project\\mod 20\\mod 20 task 4\\ATM.bin";
    short banknoteDenominations[6] = {0, 0, 0, 0, 0, 0};
    short totalBanknotes = totalChar(directory, banknoteDenominations);

    std::cout << "Top up an ATM or withdraw money? (+ or -):";
    std::string correctString;
    std::cin >> correctString;
    while (correctString.size() > 1 || (correctString != "+" &&  correctString != "-")){
        std::cout << "\nERROR!!! Input correct data (+ or -): \n";
        std::cin >> correctString;
    }
    if (correctString == "+") {
        addingBanknotes(directory, totalBanknotes);
    } else removalBanknotes(directory, banknoteDenominations);

    return 0;
}