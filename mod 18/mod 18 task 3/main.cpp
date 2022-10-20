#include <iostream>


int allCombinations(int n, int& counterComb, int k = 3) {
    if(n==0){
        counterComb++;
    }
    else {
        for (int i = k; i >= 1; i--){
            if (n - i >= 0) allCombinations(n - i, counterComb);
        }
    }
    return counterComb;
}

int main() {
    int n, k;
    int counterComb = 0;
    while (true){
        std::cin >> n >> k;
        if (n > 0 && k > 0) break;
        std::cout << "ERROR!!! Invalid data entered!\n";
    }
    std::cout << "Number of ways = " << allCombinations(n, counterComb, k);
}