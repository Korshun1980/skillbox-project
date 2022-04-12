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
    int c = 0;
    for (int i = 0; i < amount; ++i) {
        while (vec[i+c] == number) {
            ++c;
            --amount;
        }
        vec[i] = vec[i + c];
    }
    vec.resize(amount);
    if (vec.empty()) std::cout << "No numbers left!!!\n";
    for (int i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
}