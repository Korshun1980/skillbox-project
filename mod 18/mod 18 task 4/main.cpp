#include <iostream>

void evendigits (long long n, int& ans) {
    if (n > 0 && (n % 10) % 2 == 0) {
        ans++;
    }
    if (n > 0) evendigits(n / 10, ans);
}

int main() {
    long long n = 9223372036854775806;
    int ans = 0;
    if (n == 0) {
        ++ans;
    } else evendigits(n, ans);
    std::cout << ans;
}
