#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string countSort(const string& s) {
    int counter[26] = {0};

    for (char c : s) {
        ++counter[c - 'a'];
    }

    string t;
    for (int c = 0; c < 26; ++c) {
        t += string(counter[c], c + 'a');
    }

    return t;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> tmp;

    for (const auto& s : strs) {
        tmp[countSort(s)].push_back(s);
    }

    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        result.push_back(move(it->second));
    }

    return result;
}

int main() {
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = groupAnagrams(v);
    for (const auto& group : res) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
