#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> tmp;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = tmp.find(target - nums[i]);
        if (it != tmp.end()) {
            return {it->second, i};
        }
        tmp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> v = {3, 3};
    int target = 6;
    auto res = twoSum(v, target);
    for (auto e : res) {
        cout << e << endl;
    }
    return 0;
}
