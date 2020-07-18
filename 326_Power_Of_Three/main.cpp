#include <cassert>
#include <cmath>

using namespace std;

bool isPowerOfThreeV1(int n) {
    if (n == 0) return false;

    if (n == 1) return true;

    if (n == 3) return true;

    if (n % 3 == 0) {
        return isPowerOfThreeV1(n / 3);
    }

    return false;
}

bool isPowerOfThreeV2(int n) {
    if (n == 0) return false;

    if (n == 1) return true;

    if (n == 3) return true;

    while (n % 3 == 0) {
        n = n /3;
        if (n == 3) return true;
    }

    return false;
}

bool isPowerOfThreeV3(int n) {
    return fmod(log10(n)/log10(3), 1) == 0;
}

int main() {
    assert(isPowerOfThreeV3(0) == false);
    assert(isPowerOfThreeV3(1) == true);
    assert(isPowerOfThreeV3(3) == true);
    assert(isPowerOfThreeV3(9) == true);
    assert(isPowerOfThreeV3(8) == false);
    assert(isPowerOfThreeV3(27) == true);

    return 0;
}
