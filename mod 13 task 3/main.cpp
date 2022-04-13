#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec(20);
    int totalVal = 0;
    int number = 0;
    bool control = false;
    std::cout << "Input the value of the vector element: \n";
    std::cin >> number;
    while (number != -2) {
        if (number == -1) {
            for (int i = totalVal; i < vec.size() && control; ++i)
                std::cout << vec[i] << " ";
            for (int i = 0; i < totalVal; ++i)
                std::cout << vec[i] << " ";
        } else {
            vec[totalVal] = number;
            ++totalVal;
            if (totalVal == 20) {
                totalVal = 0;
                control = true;
            }
        }
        std::cin >> number;
    }
}




    /*while (vec.size() < totalVal) {
        std::cin >> number;
        if (number == -1) break;
        vec.push_back(number);
    }
    while (number != -1){
        std::cin >> number;
        if (number == -1) break;
        for (int i = 0; i < totalVal - 1;)
            vec[i++] = vec[i+1];
        vec[totalVal - 1] = number;
    }
    for (int i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
}*/