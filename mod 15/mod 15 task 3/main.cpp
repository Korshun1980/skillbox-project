#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    std::cout << "Enter numbers:";
    int num = 0;
    while (num != -2) {
        std::cin >> num;
        if (num == -1) {
            if (vec.size() < 5) {
                std::cout << "Not enough digits entered, enter numbers:";
            } else std::cout << vec[4] << "\n";
        } else {
            vec.push_back(num);
            for (int i = vec.size() - 1; i > 0; --i) {
                if (i < vec.size() && vec[i] < vec[i-1]) {
                    int temp = vec[i-1];
                    vec[i-1] = vec[i];
                    vec[i] = temp;
                }
                if (vec.size() > 5) vec.pop_back();
            }
        }
    }
}
