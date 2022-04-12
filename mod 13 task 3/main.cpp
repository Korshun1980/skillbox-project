#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int totalVal = 20;
    int number = 0;
    std::cout << "Input the value of the vector element: \n";
    while (vec.size() < totalVal) {
        std::cin >> number;
        if (number == -1) break;
        vec.push_back(number);
    }
    while (number != -1){
        std::cin >> number;
        if (number == -1) break;
        for (int i = 0; i < vec.size() - 1; ++i)
            vec[i] = vec[i+1];
        vec[totalVal - 1] = number;
    }
    for (int i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
}