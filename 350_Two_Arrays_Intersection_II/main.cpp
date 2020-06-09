#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, size_t> m1;
    for (auto e : nums1) {
        m1[e] += 1;
    }
    vector<int> result;
    for (auto e : nums2) {
        auto it = m1.find(e);
        if (it != m1.end() && it->second > 0) {
            it->second--;
            result.push_back(e);
        }
    }
    return result;
}

int main() {
    vector<int> v1 = {5, 1, 6, 3, 7, 1, 4};
    vector<int> v2 = {2, 4, 3, 1, 8, 5, 7, 2, 1};
    auto result = intersect(v1, v2);
    for (auto e : result) {
        cout << e << endl;
    }

    return 0;
}
