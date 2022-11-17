#include <iostream>
#include <fstream>

int main() {
    std::ifstream words;
    words.open("C:\\Users\\korsh\\skillbox-project\\mod 19\\mod 19 task 1\\words.txt");
    std::string word;
    std::string searchWord;
    std::cin >> searchWord;
    int counter = 0;
    while (!words.eof()){
        words >> word;
        if (searchWord == word){
            ++counter;
        }
    }
    std::cout << counter;
    return 0;
}
