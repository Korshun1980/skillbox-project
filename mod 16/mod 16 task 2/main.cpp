#include <iostream>

int main() {
    std::string integer;
    std::string fractional;
    std::cout << "Input the integer part of the number: " << std::endl;
    std::cin >> integer;
    std::cout << "Input the fractional part of the number: " << std::endl;
    std::cin >> fractional;
    double number = std::stod(integer + '.' + fractional);
    std::cout << number << std::endl;
}
