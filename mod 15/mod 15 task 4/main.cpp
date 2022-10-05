#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<int> vec{-100,-50, -5, 1, 10, 15};
    while (vec[0] < 0){
        for (int i = 0; i < vec.size(); ++i){
            if (abs(vec[i]) > abs (vec[i+1])) {
                int temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;
            }
        }
    }
    for (int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
}
