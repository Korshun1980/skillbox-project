#include <iostream>
#include <vector>

int main() {
    int i, j;
    std::vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    int sum = 0;
    for (int i = 0; i<vec.size(); ++i) {
        sum += vec[i];
    }
    int controlSum = 0;
    for (j = 0; j<vec.size() && controlSum != sum; ++j) {
        controlSum += vec[j];
    }
    controlSum = 0;
    for (i = vec.size()-1; i>=0 && controlSum != sum; --i) {
        controlSum += vec[i];
    }
    std::cout << i << " " << j << std::endl;
}
