#include <iostream>

std::string Integer (std::string strNumber) {
    std::string integer;
    int i = 0;
    while (strNumber[i] == '0' || strNumber[i] == '-') i++;
    for (; i < strNumber.length() && strNumber[i] != '.'; i++) {
        integer += strNumber[i];
    }
    if(integer == "") integer = "0";
    return integer;
}
std::string FractionalNumber (std::string strNumber) {
    std::string fractionalNumber;
    int i = 0;
    for (; i < strNumber.length();) {
        for (; i < strNumber.length() && strNumber[i] != '.'; i++);
        i++;
        for (;i < strNumber.length(); i++) {
            fractionalNumber += strNumber[i];
        }
    }
    return fractionalNumber;
}

bool Real_Numbers (std::string strNumber) {
    bool checkbox = false;
    int repeat = 0;

    for (int counter = 0; counter < strNumber.length(); ++counter) {
        if ((strNumber[counter] < '0' || strNumber[counter] > '9') && strNumber[counter] != '-' && strNumber[counter] != '.') {
            checkbox = true;
            break;
        }
        if (((strNumber[0] == '-' || strNumber[0] == '.') && strNumber.length() < 2 ) ||
            (strNumber[0] == '-' && strNumber[1] == '.' && strNumber.length() < 3)) {
            checkbox = true;
            break;
        }
        if (counter > 0 && strNumber[counter] == '-') {
            checkbox = true;
            break;
        }
        if (strNumber[counter] == '.') ++repeat;
        if (repeat > 1) {
            checkbox = true;
            break;
        }
    }
    return checkbox;
}

int main() {
    std::cout << "Comparison of real numbers.\n";
    std::cout << "=================\n";

    std::string strNumber1;
    std::string strNumber2;
    do {
        if (Real_Numbers (strNumber1)) std::cout << "ERROR!!!\n";
        std::cout << "Input a real number1: \n";
        getline(std::cin, strNumber1);
    } while (Real_Numbers (strNumber1));

    do {
        if (Real_Numbers (strNumber2)) std::cout << "ERROR!!!\n";
        std::cout << "Input a real number2: \n";
        getline(std::cin, strNumber2);
    } while (Real_Numbers (strNumber2));

    std::string integer1 = Integer(strNumber1);
    std::string integer2 = Integer(strNumber2);
    std::string fractionalNumber1 = FractionalNumber(strNumber1);
    std::string fractionalNumber2 = FractionalNumber(strNumber2);

    for (int i = 0 ;i < integer1.length() && i < integer2.length(); ++i) {

        if (strNumber1[0] == '-' && strNumber2[0] != '-' && integer1[0] != '0' || integer1.length() < integer2.length()
                || (integer1.length() == integer2.length() && integer1[i] < integer2[i])) {
            if (strNumber1[0] == '-' && strNumber2[0] == '-') {
                std::cout << "More\n";
            } else std::cout << "Less\n";
            return 0;
        }
        if (strNumber2[0] == '-' && strNumber1[0] != '-' && integer2[0] != '0' || integer2.length() < integer1.length()
                || (integer2.length() == integer1.length() && integer2[i] < integer1[i])) {
            if (strNumber1[0] == '-' && strNumber2[0] == '-') {
                std::cout << "Less\n";
            } else std::cout << "More\n";
            return 0;
        }
    }

    if (fractionalNumber1 == fractionalNumber2) {
        std::cout << "Equal\n";
        return 0;
    }

    while (fractionalNumber1.length() < fractionalNumber2.length()) fractionalNumber1 += '0';
    while (fractionalNumber2.length() < fractionalNumber1.length()) fractionalNumber2 += '0';

    for (int i = 0; i < fractionalNumber1.length() && i < fractionalNumber2.length(); i++) {

        if (fractionalNumber1[i] < fractionalNumber2[i]) {
            if (strNumber1[0] == '-' && strNumber2[0] == '-') {
                std::cout << "More\n";
            } else std::cout << "Less\n";
            return 0;
        }
        if (fractionalNumber2[i] < fractionalNumber1[i]) {
            if (strNumber1[0] == '-' && strNumber2[0] == '-') {
                std::cout << "Less\n";
            } else std::cout << "More\n";
            return 0;
        }
    }
    std::cout << "Equal\n";
}