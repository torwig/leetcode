#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> result(digits.size(), 0);

    bool carry = true;
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (carry) {
            if (digits[i] == 9) {
                result[i] = 0;
            } else {
                result[i] = ++digits[i];
                carry = false;
            }
        } else {
            result[i] = digits[i];
        }
    }

    if (carry) {
        result.insert(result.begin(), 1);
    }

    return result;
}

vector<int> plusOneV2(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != 9) {
            ++digits[i];
            break;
        }
        digits[i] = 0;
    }

    if (digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

vector<int> plusOneV3(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != 9) {
            ++digits[i];
            break;
        }
        digits[i] = 0;
    }

    if (digits[0] == 0) {
        digits[0] = 1;
        digits.push_back(0);
    }

    return digits;
}

vector<int> plusOneV4(vector<int>& digits) {
    int pos = digits.size() - 1;
    while (pos >= 0 && digits[pos] == 9) {
        digits[pos] = 0;
        --pos;
    }
    if (pos == -1) {
        digits[0] = 1;
        digits.push_back(0);
    } else {
        ++digits[pos];
    }
    return digits;
}

int main() {
    vector<int> v = {9, 9, 9};
    auto res = plusOneV2(v);
    for (auto e : res) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
