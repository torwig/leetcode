#include <limits>
#include <cassert>

using namespace std;

int reverse(int x) {
    if (x == 0) return 0;

    int result = 0;

    while (x != 0) {
        int number = x % 10;

        if (x > 0) {
            if (result > (numeric_limits<int>::max() - number) / 10) return 0;
        } else {
            if (result < (numeric_limits<int>::min() - number) / 10) return 0;
        }

        result = result * 10 + number;

        x /= 10;
    }

    return result;
}

int reverseV2(int x) {
    long long res = 0;

    while (x != 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }

    return ( res < numeric_limits<int>::min() || res > numeric_limits<int>::max() ) ? 0 : res;
}


int main() {
    assert(reverse(123) == 321);
    assert(reverse(0) == 0);
    assert(reverse(120) == 21);
    assert(reverse(-12345) == -54321);

    return 0;
}
