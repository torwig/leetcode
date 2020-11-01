#include <cassert>
#include <iostream>

using namespace std;

int mySqrtV1(int x) {
    if (x == 0 || x == 1) return x;

    long left = 1;
    long right = x;

    while (left < right - 1) {
        long middle = left + (right - left) / 2;
        if (x > middle*middle) {
            left = middle;
        } else if (x < middle*middle) {
            right = middle;
        } else {
            return middle;
        }
    }

    return left;
}

int mySqrtV2(int x) {
    long r = x;

    while (r*r > x)
        r = (r + x/r) / 2;

    return r;
}

int mySqrtV3(int x) {
    int res = 0;

    for (int mask = 1 << 15; mask != 0; mask >>= 1) {
        int next = res | mask; //set bit
        if (next <= x / next) res = next;
    }

    return res;
}

int main() {
    assert(mySqrtV3(25) == 5);
    assert(mySqrtV3(8) == 2);
    assert(mySqrtV3(225) == 15);
    assert(mySqrtV3(2) == 1);
    assert(mySqrtV3(1) == 1);
    assert(mySqrtV3(2147395599) == 46339);

    return 0;
}
