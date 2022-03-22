#include <iostream>
#include <vector>

int main() {
    std::vector<float> prices{2.5, 4.25, 3.0, 10.0};
    std::vector<int> shoppingList {1, 1, 0, 3};
    float sum = 0.0f;
    for (int i = 0; i < shoppingList.size(); ++i)
        sum += (float) prices[shoppingList[i]];
    std::cout << "The cost of all goods " << sum << ". \n";
}