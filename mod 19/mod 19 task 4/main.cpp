#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream test;
    std::string directory;
    std::cout << "Input directory\n";
    //getline(std::cin, directory);
    directory = "C:\\Users\\korsh\\skillbox-project\\mod 19\\mod 19 task 4\\screen.png";
    test.open(directory, std::ios::binary);
    while (!(test.is_open())) {
        std::cout << "ERROR!!! Input valid directory\n";
        getline(std::cin, directory);
        test.open(directory, std::ios::binary);
    }
    if (directory.substr(directory.size()-3, 3) != "png"){
        std::cout << "NO!!!";
        return 0;
    }
    char buffer[4];
    test.read(buffer, 4);
    std::string str = buffer;

    if (buffer[0] == int (-119) && str.substr (1,3) == "PNG") {
        std::cout << "YES!!!";
    } else std::cout << "NO!!!";
    test.close();
    return 0;
}
