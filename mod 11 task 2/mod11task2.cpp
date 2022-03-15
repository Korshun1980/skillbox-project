#include <iostream>

std::string Email_Address_Verification (std::string str) {
    bool coincidence = true;
    std::string part1;
    std::string part2;

    int i = 0;
    for (; i < str.length() && str[i] != 64 && i < 65; ++i) {
        int x = str[i]; // (№ ASC2)
        if ((str[i] == '.' && str[i+1] == '.') || x < 33 || x > 126 || x == 34 || x == 40 || x == 41 || x == 44 ||
                (x > 57 && x < 61) || x == 62 || (x > 90 && x < 94)) {
            coincidence = false;
            i = 129;
            break;
        }
        part1 += str[i];
    }

    for (i += 1; i < str.length() && i < 129; ++i) {
        int x = str[i]; // (№ ASC2)
        if ((str[i] == '.' && str[i-1] == '.') || x < 45 || x > 122 || x == 47 || (x > 57 && x < 65) ||
                (x > 90 && x < 97)) {
            coincidence = false;
            break;
        }
        part2 += str[i];
    }

   if (part1.length() < 1 || part1.length() > 63 || part2.length() < 1 || part2.length() > 64
        ||  part1[0] == '.' || part1[part1.length()-1] == '.'  || part2[0] == '.' || part2[part1.length()-1] == '.') coincidence = false;
   return (coincidence ? "Yes\n" : "No\n");
}

int main () {
    std::cout << "Input address \n";
    std::string str;
    std::getline(std::cin, str);

    std::cout << Email_Address_Verification (str);
}