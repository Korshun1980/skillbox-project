#include <iostream>

int main() {
    float speed = 0;
    float speedDelta;
    char speedStr[6];
        do {
        std::cout << "Enter speed delta: ";
        std::cin >> speedDelta;
        speed += speedDelta;
        if(speed > 150.0f) speed = 150.0f;
        std::sprintf(speedStr, "%.1f", speed);
        std::cout << speedStr << "\n";
    } while (speed >= 0.0f + 0.01f);
}