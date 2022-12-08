#include <iostream>
#include <fstream>

int main() {
    std::ifstream fishRiver ("C:\\Users\\korsh\\skillbox-project\\mod 20\\mod 20 task 3\\river.txt");
    if (!(fishRiver.is_open())){
        std::cout << "ERROR!!! Input valid directory\n";
        return 0;
    }
    std::string fishInRiver;
    std::string fish;
    std::cout << "Input the name of the fish you will be catching\n";
    std::cin >> fish;
    int caughtFishInt = 0;

    while (!fishRiver.eof()){
        fishRiver >> fishInRiver;

        if (fishInRiver == fish) {
            std::ofstream caughtFish("C:\\Users\\korsh\\skillbox-project\\mod 20\\mod 20 task 3\\basket.txt", std::ios::app);
            if (!(caughtFish.is_open())){
                std::cout << "ERROR!!! Input valid directory\n";
                return 0;
            }
            caughtFish << fish << "\n";
            ++caughtFishInt;
            caughtFish.close();
        }
    }
    fishRiver.close();
    std::cout << "You caught "  << caughtFishInt << " fish!\n";

    return 0;
}
