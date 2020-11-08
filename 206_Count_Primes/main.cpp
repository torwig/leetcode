#include <cassert>

using namespace std;

int countPrimes(int n) {
    if (n == 0 || n == 1) return 0;

    bool primes[n];
    for (int i = 0; i < n; ++i) {
        primes[i] = false;
    }

    for (int i = 2; i * i < n; ++i) {
        if (!primes[i]) {
            for (int j = i * i; j < n; j += i) {
                primes[j] = true;
            }
        }
    }

    int count = 0;

    for (int i = 2; i < n; ++i) {
        if (!primes[i]) ++count;
    }

    return count;
}

int main() {
    assert(countPrimes(0) == 0);
    assert(countPrimes(1) == 0);
    assert(countPrimes(3) == 1);
    assert(countPrimes(10) == 4);

    return 0;
}
