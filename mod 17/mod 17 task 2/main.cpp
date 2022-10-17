#include <iostream>

void reverse (int* px) {
    for (int i = 0; i < 5; ++i) {
        int temporary = *(px+i);
        *(px + i) = *(px + (9 - i));
        *(px + (9 - i)) = temporary;
    }
}

int main() {
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    reverse(x);
    for (int i = 0; i < 10; ++i) {
        std::cout << x[i] << " ";
    }
    return 0;
}
