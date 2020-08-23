#include <cassert>

int trailingZeroes(int n) {
    int res = 0;

    while (n) {
        n /= 5;
        res += n;
    }

    return res;
}

int main() {
    assert(trailingZeroes(0) == 0);
    assert(trailingZeroes(3) == 0);
    assert(trailingZeroes(5) == 1);
    assert(trailingZeroes(4617) == 1151);

    return 0;
}
