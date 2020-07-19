#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int robV1(vector<int>& nums) {
    if (nums.empty()) return 0;

    if (nums.size() == 1) return nums[0];

    vector<int> v(nums.size(), 0);
    v[0] = nums[0];
    v[1] = nums[1];

    for (size_t i = 2; i < nums.size(); ++i) {
        v[i] = max(v[i - 2] + nums[i], v[i - 1]);
    }

    return v[nums.size() - 1];
}

int robV2(vector<int>& nums) {
    int prev2 = 0;
    int prev1 = 0;

    for (int val : nums) {
        int temp = max(prev2 + val, prev1);
        prev2 = prev1;
        prev1 = temp;
    }

    return prev1;
}

int robV3(vector<int>& nums) {
    int it1 = 0;
    int it2 = 0;

    for (int val : nums) {
        it1 = max(it1 + val, it2);
        swap(it1, it2);
    }

    return it2;
}

int robV4(vector<int>& nums) {
    int x = 0;
    int y = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (i & 1) {
            x = max(x + nums[i], y);
        } else {
            y = max(y + nums[i], x);
        }
    }

    return max(x, y);
}

int main() {
    vector<int> v1 = {1, 2, 3, 1};
    assert(robV3(v1) == 4);
    vector<int> v2 = {2, 7, 9, 3, 1};
    assert(robV3(v2) == 12);

    return 0;
}
