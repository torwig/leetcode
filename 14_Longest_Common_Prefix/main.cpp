#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefixV1(vector<string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];

    size_t prefix_len = 0;
    for (; prefix_len < strs[0].size(); ++prefix_len) {
        auto c = strs[0][prefix_len];
        if (!all_of(strs.begin() + 1, strs.end(), [c, prefix_len](string& s) {
            return prefix_len < s.size() && s[prefix_len] == c;
        })) {
            break;
        }
    }

    if (prefix_len == 0) return "";

    return strs[0].substr(0, prefix_len);
}

string longestCommonPrefixV2(vector<string>& strs) {
    if (strs.empty()) return "";

    for (size_t i = 0; i < strs[0].size(); ++i)
        for (size_t j = 0; j < strs.size(); ++j)
            if ( !( i < strs[j].size() && strs[0][i] == strs[j][i]) )
                return strs[0].substr(0, i);

    return strs[0];
}

int main() {
    vector<string> v1 = {"flower", "dog", "racecar"};
    assert(longestCommonPrefixV2(v1) == "");
    return 0;
}
