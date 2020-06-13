#include <iostream>
#include <unordered_set>
#include <cassert>

using namespace std;

int sumDigitSquares(int n) {
    if (n == 0 || n == 1) return n;

    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        sum += digit*digit;
        n = n / 10;
    }
    return sum;
}

bool isHappyV1(int n) {
    if (n == 0 || n == 1) return true;

    unordered_set<int> alreadySeen;

    while (alreadySeen.find(n) == alreadySeen.end()) {
        alreadySeen.insert(n);
        n = sumDigitSquares(n);
        if (n == 1) return true;
    }

    return false;
}

bool isHappyV2(int n) {
    if (n == 0 || n == 1) return true;

    int slow = n;
    int fast = sumDigitSquares(n);
    while (slow != fast) {
        slow = sumDigitSquares(slow);
        fast = sumDigitSquares(sumDigitSquares(fast));

    }

    return slow == 1;
}

bool isHappyV3(int n) {
    if (n == 0 || n == 1) return true;

    while (true) {
        int sum = sumDigitSquares(n);
        if (1 <= sum && sum <= 9) {
            if (sum == 1 || sum == 7) return true;
            return false;
        }
        n = sum;
    }
}

int main() {
    assert(isHappyV1(19));
    assert(!isHappyV1(20));

    assert(isHappyV2(19));
    assert(!isHappyV2(20));

    assert(isHappyV3(19));
    assert(!isHappyV3(20));
    return 0;
}
