#include <iostream>


int allCombinations(int n, int& counterComb) {
    if(n==0){
        counterComb++;
    }
    else {
        for (int i = 3; i >= 1; i--){
            if (n - i >= 0) allCombinations(n - i, counterComb);
        }
    }
    return counterComb;
}

int main() {
    int n;
    int counterComb = 0;
    while (true){
        std::cin >> n;
        if (n > 0) break;
        std::cout << "ERROR!!! Invalid data entered!\n";
    }
    std::cout << "Number of ways = " << allCombinations(n, counterComb);
}