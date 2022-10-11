#include <string>
#include <sstream>
#include <iostream>

int main() {
    std::string buffer;
    std::cin >> buffer;
    std::stringstream bufferStream;
    bufferStream << buffer;
    double a;
    char operation;
    double b;
    bufferStream >> a >> operation >> b;
    std::cout << a << operation << b << '=';
    double results;
    if (operation == '+') results = a + b;
    if (operation == '-') results = a - b;
    if (operation == '*') results = a * b;
    if (operation == '/') results = a / b;
    std::cout << results << '\n';
}
