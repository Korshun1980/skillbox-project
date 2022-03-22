#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int number = 0;
    std::cout << "Input the value of the vector element: \n";
    while (number != -1) {
        std::cin >> number;
        vec.push_back(number);
        if (vec.size() > 21) {
            for (int i = 0; i < vec.size(); ++i) {
                vec[i] = vec[i+1];
            }
            vec.pop_back();
        }
    }
    vec.pop_back();
    for (int i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
}