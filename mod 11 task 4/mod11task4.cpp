#include <iostream>

std::string Integer (std::string strNumber) {
    std::string integer;
    std::string fractionalNumber;
    int i = 0;
    for (; i < strNumber.length();) {
        for (; i < strNumber.length() && strNumber[i] != '.'; i++) {
            integer += strNumber[i];
        }
        i++;
        for (;i < strNumber.length(); i++) {
            fractionalNumber += strNumber[i];
        }
    }
    return integer;
}
std::string FractionalNumber (std::string strNumber) {
    std::string integer;
    std::string fractionalNumber;
    int i = 0;
    for (; i < strNumber.length();) {
        for (; i < strNumber.length() && strNumber[i] != '.'; i++) {
            integer += strNumber[i];
        }
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

    int i1 = 0;
    int i2 = 0;
    int x1 = 0;
    int x2 = 0;
    bool checkbox1 = true;
    bool checkbox2 = true;

    while (i1 < integer1.length() || i2 < integer2.length()) {
        while (integer1[i1] == '0' && checkbox1) {
            i1++;
            x1++;
        }
        checkbox1 = false;

        while (integer2[i2] == '0' && checkbox2) {
            i2++;
            x2++;
        }
        checkbox2 = false;

        if (integer1[0] == '-' && integer2[0] != '-' || ((integer1[i1] == integer1[integer1.length() - 1 - x1])
                                                         && integer1.length() < integer2.length()) ||
            (integer1.length() == integer2.length() && integer1[i1] < integer2[i2])) {
            std::cout << "Less\n";
            return 0;
        }
        if (integer2[0] == '-' && integer1[0] != '-' || ((integer2[i2] == integer2[strNumber2.length() - 1 - x2])
                                                         && integer2.length() < integer1.length()) ||
            (integer2.length() == integer1.length() && integer2[i2] < integer1[i1])) {
            std::cout << "More\n";
            return 0;
        }
        i1++;
        i2++;
    }

    if (fractionalNumber1 == "" && fractionalNumber2 == "") {
        std::cout << "Equal\n";
        return 0;
    }

    for (int i = 0; i < fractionalNumber1.length() && i < fractionalNumber2.length(); i++) {
        if (fractionalNumber1[0] == '-' && fractionalNumber2[0] != '-' || ((fractionalNumber1[i] == fractionalNumber1[fractionalNumber1.length()-1])
                && fractionalNumber1.length() < fractionalNumber2.length()) || fractionalNumber1[i] < fractionalNumber2[i]) {
            std::cout << "Less\n";
            return 0;
        }
        if (fractionalNumber2[0] == '-' && fractionalNumber1[0] != '-' || ((fractionalNumber2[i] == fractionalNumber2[fractionalNumber2.length()-1])
                && fractionalNumber2.length() < fractionalNumber1.length()) || fractionalNumber2[i] < fractionalNumber1[i]) {
            std::cout << "More\n";
            return 0;
        }
    }
    std::cout << "Equal\n";
}