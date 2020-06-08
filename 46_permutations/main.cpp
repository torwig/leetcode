#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        doPermutation(result, nums, 0);
        return result;
    }

private:
    void doPermutation(vector<vector<int>>& result, vector<int>& nums, size_t pos) {
        if (nums.size() == pos) {
            result.push_back(nums);
            return;
        }

        for (std::size_t i = pos; i < nums.size(); ++i) {
            swap(nums[i], nums[pos]);
            doPermutation(result, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }
};

int main() {
    vector<int> input = {1, 2, 3};
    auto result = Solution().permute(input);
    for (auto& v : result) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
