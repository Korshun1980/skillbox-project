#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int amount;
    int number;

    std::cout << "Input the amount of elements in the vector: \n";
    std::cin >> amount;
    std::cout << "Input " << amount << " numbers: \n";

    while (vec.size() < amount) {
        std::cin >> number;
        vec.push_back(number);
    }
    std::cout << "What value to remove from the vector? \n";
    std::cin >> number;
    for (int i = vec.size()-1; i >= 0; --i) {
        if (vec[i] == number) {
            for (int c = i; c < vec.size() - 1; ++c)
                vec[c] = vec[c+1];
            vec.pop_back();
        }
    }
    if (vec.empty()) std::cout << "No numbers left!!!\n";
    for (int i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
}