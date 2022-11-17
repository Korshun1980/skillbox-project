#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream words;
    std::string directory;
    char buffer[50];
    std::cout << "Input valid directory\n";
    getline(std::cin, directory);
    //directory = "C:\\Users\\korsh\\skillbox-project\\mod 19\\mod 19 task 2\\words.txt";
    words.open(directory, std::ios::binary);
    while (!(words.is_open())) {
        std::cout << "ERROR!!! Input valid directory\n";
        getline(std::cin, directory);
        words.open(directory, std::ios::binary);
    }
     while (!words.eof()){
        words.read(buffer, sizeof(buffer));
        if (words.eof()) {
            for (int i = 0; i < words.gcount(); ++i) {
                std::cout << buffer[i];
            }
        } else std::cout << buffer;
    }
    words.close();
    return 0;
}