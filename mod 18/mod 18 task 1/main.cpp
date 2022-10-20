#include <iostream>
#include <vector>

void swapvec (std::vector<int>& vec, int* pb) {
    for (int i = 0; i < vec.size(); ++i) {
        int temporary = vec[i];
        vec[i] = *(pb + i);
        *(pb + i) = temporary;
    }
}

int main() {
    std::vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};

    swapvec(a,b);

    for(int i = 0; i < 4; ++i)
        std::cout << a[i];
    std::cout << "\n";
    for(int i = 0; i < 4; ++i)
        std::cout << b[i];
}
