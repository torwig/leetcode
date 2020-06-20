#include <iostream>
#include <vector>

using namespace std;

int climbStairsV1(int n) {
    if (n == 1) return 1;

    vector<int> v;
    v.reserve(n + 1);
    v[1] = 1;
    v[2] = 2;

    for (int i = 3; i <= n; ++i) {
        v[i] = v[i - 1] + v[i - 2];
    }
    return v[n];
}

int climbStairsV2(int n) {
    if (n == 1) return 1;

    int first = 1;
    int second = 2;

    for (int i = 3; i <= n; ++i) {
        int third = first + second;
        first = second;
        second = third;
    }

    return second;
}

int main() {
    cout << "for n=1 stairs: " << climbStairsV1(1) << endl;
    cout << "for n=5 stairs: " << climbStairsV1(5) << endl;

    cout << "for n=1 stairs: " << climbStairsV2(1) << endl;
    cout << "for n=5 stairs: " << climbStairsV2(5) << endl;
    return 0;
}
