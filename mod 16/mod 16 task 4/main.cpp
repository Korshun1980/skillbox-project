#include <string>
#include <iostream>
enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main()
{
    std::string melody;

    for (short i = 0; i < 13; ++i) {
        std::cout << "Enter the notes of the " << i << "st chord, notes (1 to 7):\n";
        std::string chord;
        std::cin >> chord;
        melody += chord + '/';
    }

    for (short i = 0; i < melody.size(); ++i) {
        if (melody[i] == '/') {
            std::cout << "\n";
        } else {
            int shiftNote = melody[i] - '1';
            if (1 << shiftNote & DO) {
                std::cout << "DO ";
            } else if (1 << shiftNote & RE) {
                    std::cout << "RE ";
                } else if (1 << shiftNote & MI) {
                        std::cout << "MI ";
                    } else if (1 << shiftNote & FA) {
                            std::cout << "FA ";
                        } else if (1 << shiftNote & SOL) {
                                std::cout << "SOL ";
                            } else if (1 << shiftNote & LA) {
                                    std::cout << "LA ";
                                } else if (1 << shiftNote & SI) {
                                        std::cout << "SI ";
                                    }
        }
    }
    return 0;
}