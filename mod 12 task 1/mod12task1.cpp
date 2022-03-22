#include <iostream>
#include <string>

int main() {
    std::string surname [10];
    std::cout << "Input the surnames of the residents\n";
    for (int i = 0; i < 10; i++) std::cin >> surname[i];
    std::cout << "Input three apartment numbers\n";
    int apartment[3];
    for (int i = 0; i < 3; i++) {
        do {
            std::cin >> apartment[i];
            if (apartment[i] > 10 || apartment[i] < 1)
                std::cout << "ERROR!!!\n";
        } while (apartment[i] > 10 || apartment[i] < 1);
    }
    for (int i = 0; i < 3; i++)
        std::cout << "In apartment " << apartment[i] << " lives: " << surname[apartment[i] - 1] << "\n";
}
