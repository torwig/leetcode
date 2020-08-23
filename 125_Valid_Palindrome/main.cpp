#include <cassert>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindromeV1(string s) {
    auto endIt = remove_if(s.begin(), s.end(), [](char c) {
        return !isalnum(c);
    });

    size_t sz = distance(s.begin(), endIt);
    if (sz == 0) return true;
    size_t i = 0;
    size_t j = sz - 1;

    while (i < j) {
        if (tolower(s[i]) != tolower(s[j])) return false;
        ++i;
        --j;
    }

    return true;
}

bool isPalindromeV2(string s) {
    if (s.empty()) return true;

    size_t left = 0;
    size_t right = s.size() - 1;

    while (left < right) {
        if (!isalnum(s[left])) left++;
        else if (!isalnum(s[right])) right--;
        else if (tolower(s[left]) != tolower(s[right])) return false;
        else { ++left; --right; }
    }

    return true;
}

int main() {
    assert(isPalindromeV2(" "));
    assert(isPalindromeV2("A man, a plan, a canal: Panama"));
    return 0;
}
