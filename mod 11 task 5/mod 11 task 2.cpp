#include <iostream>

std::string Email_Address_Verification (std::string str) {
    bool coincidence = true;
    int emailCenter;
    std::string part1;
    std::string part2;
    for (int i = 0; i < str.length(); ++i) {
        for (;str[i] != '@';) {
            part1 += str[i];
        }
        for (;str[i] < str.length();) {
            part2 += str[i];
        }
    }
    std::cout << part1 << "\n";
    std::cout << part2 << "\n";



    return (coincidence ? "Yes\n" : "No\n");

}

int main () {
    std::cout << "Input email address \n";
    std::string str;
    std::getline(std::cin, str);

    std::cout << Email_Address_Verification (str);
}