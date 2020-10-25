#include <string>
#include <cassert>
#include <vector>

using namespace std;

// Return the index of the first occurrence of needle in haystack,
// or -1 if needle is not part of haystack.
// For the purpose of this problem, we will return 0 when needle is an empty string.

int strStrV1(string haystack, string needle) {
    if (needle.empty()) return 0;

    if (needle.size() > haystack.size()) return -1;

    int i = 0;

    while (i < haystack.size() && (i + needle.size() <= haystack.size())) {
        int j = 0;
        int k = i;

        while (j < needle.size() && k < haystack.size() && needle[j] == haystack[k]) {
            ++j;
            ++k;
        }

        if (j == needle.size()) return i;

        ++i;
    }

    return -1;
}

int strStrV2(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();

    for (int i = 0; i <= m - n; ++i) {
        int j = 0;

        for (; j < n; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }

        if (j == n) {
            return i;
        }
    }

    return -1;
}
vector<int> kmpProcess(string needle) {
    int n = needle.size();

    vector<int> lps(n, 0);

    for (int i = 1, len = 0; i < n;) {
        if (needle[i] == needle[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    return lps;
}

int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();

    if (n == 0) {
        return 0;
    }

    vector<int> lps = kmpProcess(needle);
    for (int i = 0, j = 0; i < m;) {
        if (haystack[i] == needle[j]) {
            i++, j++;
        }

        if (j == n) {
            return i - j;
        }

        if (i < m && haystack[i] != needle[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    
    return -1;
}

int main() {
    assert(strStr("hello", "") == 0);
    assert(strStr("hello", "ell") == 1);
    assert(strStr("hello", "helloi") == -1);
    assert(strStr("abrakadabra", "ball") == -1);
    assert(strStr("a", "a") == 0);
    assert(strStr("abc", "c") == 2);

    return 0;
}
