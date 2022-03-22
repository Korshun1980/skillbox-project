#include <iostream>

int main() {
    int numbers[] = {114,111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};
    int startNumber = 105;
    startNumber --;
    int storageNumber1;
    int storageNumber2 = startNumber;

    for (;;) {
        storageNumber1 = numbers[storageNumber2 - startNumber];
        numbers[storageNumber2 - startNumber] = storageNumber2;
        if (storageNumber1 == startNumber + 15){
            std::cout << "No repeats\n";
            break;
        }
        storageNumber2 = numbers[storageNumber1 - startNumber];
        numbers[storageNumber1 - startNumber] = storageNumber1;
        if (storageNumber1 == storageNumber2) {
            std::cout << storageNumber1 << "\n";
            break;
        }
    }
}