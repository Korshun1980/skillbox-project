#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {2, 7, 11, 15};
    int num;
    std::cout << "Enter the number: ";
    std::cin >> num;
    int i, j;
    for (i = 0; i < vec.size(); ++i){
        for (j = i+1; j < vec.size(); ++j){
            if (vec[i] + vec[j] == num) {
                std::cout << vec[i] << " and " << vec[j] << std::endl;
                return 0;
            }
        }
    }
}
