#include <iostream>

std::string encrypt_caesar (std::string str, int x) {
    std::string result;
    for (int i = 0; i < str.length(); ++i) {
        int strI = (int)str[i];
        int x2 = x;
        if (str[i] == ' ') {
            result += ' ';
        } else if (strI > 64 && strI < 91) {
            for (;strI + x2 > 90;) {
                x2 -= 26;
            }
            for (;strI + x2 < 65;) {
                x2 += 26;
            }
        } else if (strI > 96 && strI < 123) {
            for (;strI + x2 > 122;) {
                x2 -= 26;
            }
            for (;strI + x2 < 97;) {
                x2 += 26;
            }
        } else (x2 = 0);
        if (str[i] != ' ') {
            strI = strI + x2;
            result += (char) strI;
        }
    }
    return result;
}

std::string decrypt_caesar (std::string str, int x) {
    return encrypt_caesar(str, -x);
}


int main() {
    std::string str;
    std::string str2;
    std::string str3;
    std::getline(std::cin, str);
    int x;
    std::cin >> x;

    str2 = encrypt_caesar(str, x);

    str3 = decrypt_caesar(str2, x);

    std::cout << str2 << std::endl;

    std::cout << str3 << std::endl;
}