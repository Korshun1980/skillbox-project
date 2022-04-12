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
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] != number)
            vec[c++] = vec[i];
    }
    vec.resize(c);
    if (vec.empty()) std::cout << "No numbers left!!!\n";
    for (int i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
}

/*int main() {
    std::vector<int> v = {1,2,3,3,5,3,5,7,3};
    int value = 3;

    int j = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != value)
            v[j++] = v[i];
    }
    v.resize(j);

    for (int i = 0; i < v.size(); ++i) std::cout<<v[i]<<std::endl;
}*/