#include <iostream>
#include <fstream>

int main() {
    std::ifstream words;
    std::string directory;
    char buffer[50];
    std::cout << "Input valid directory\n";
    //std::cin >> directory;
    directory = "C:\\Users\\korsh\\skillbox-project\\words2.txt";
    words.open(directory, std::ios::binary);
    //bool loginVerification = words.is_open();
    while (!(words.is_open())) {
        //words.close();
        std::cout << "ERROR!!! Input valid directory\n";
        std::cin >> directory;
        words.open(directory, std::ios::binary);
    }
    while (!words.eof()){
        //std::cout << words.tellg() << "!!!!!!!!!!!!!!!!!!!!!";
        words.read(buffer, sizeof(buffer));
        //words.seekg(0);
        if (words.eof()) {
            for (int i = 0; i < 34; ++i) {
                std::cout << buffer[i];
            }
            //words.seekg(0);
            //buffer[30];

            //words.read(buffer, sizeof(buffer));
            break;
        }
        std::cout << buffer;
    }
    std::cout << "\n\n\n" << buffer;
    /*for (int i = 0; i < 10; ++i) {
        std::cout << buffer[i];
    }*/
    words.close();
    return 0;
}