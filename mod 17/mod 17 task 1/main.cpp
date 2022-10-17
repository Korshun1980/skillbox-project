#include <iostream>

void swap (int* px, int* py) {
    *px += *py;
    *py = *px - *py;
    *px -= *py;
}

int main() {
    int x = 10;
    int y = 20;
    swap(&x, &y);
    std::cout << x << " " << y;
}
