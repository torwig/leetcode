#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>& vv) {
    cout << "[" << endl;
    for (auto& v : vv) {
        cout << "[";
        for (auto e : v) {
            cout << e << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

void subsets_helper(vector<vector<int>>& result, vector<int>& sub, size_t i, vector<int>& nums) {
    result.push_back(sub);
    for (size_t j = i; j < nums.size(); ++j) {
        sub.push_back(nums[j]);
        subsets_helper(result, sub, j + 1, nums);
        sub.pop_back();
    }
}

vector<vector<int>> subsetsV1(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    vector<int> sub;
    subsets_helper(result, sub, 0, nums);
    return result;
}

vector<vector<int>> subsetsV2(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    for (auto n : nums) {
        size_t sz = result.size();
        for (size_t i = 0; i < sz; ++i) {
            vector<int> tmp(result[i]);
            tmp.push_back(n);
            result.push_back(tmp);
        }
    }
    return result;
}

int main() {
    vector<int> data1;
    auto result1 = subsetsV2(data1);
    print(result1);
    cout << "-----" << endl;
    vector<int> data2 = {1, 2, 3};
    auto result2 = subsetsV2(data2);
    print(result2);
    return 0;
}
