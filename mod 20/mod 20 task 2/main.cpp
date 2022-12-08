#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    std::ofstream pic("C:\\Users\\korsh\\skillbox-project\\mod 20\\mod 20 task 2\\pic.txt");
        if (!(pic.is_open())){
        std::cout << "ERROR!!! Input valid directory\n";
        return 0;
    }
    std::cout << "Input image width and height: \n";
    int width = 0;
    int height = 0;
    std::cin >> width >> height;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pic << std::rand()%2;
        }
        pic << "\n";
    }
    pic.close();
    return 0;
}
