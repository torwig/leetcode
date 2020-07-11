#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";

    string prev = countAndSay(n - 1);

    int count = 1;
    char val = prev[0];
    string result;

    for (size_t i = 1; i < prev.size(); ++i) {
        if (prev[i] != val) {
            result += to_string(count);
            result += val;
            count = 1;
            val = prev[i];
        } else {
            ++count;
        }
    }
    result += to_string(count);
    result += val;

    return result;
}

int main() {
    for (int i  = 1; i < 30; ++i) {
        cout << countAndSay(i) << endl;
    }
    return 0;
}
