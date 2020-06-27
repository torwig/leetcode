#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums, int l, int r) {
    if (l > r) return std::numeric_limits<int>::min();

    int m = l + (r - l) / 2;
    int ml = 0;
    int mr = 0;

    int lmax = maxSubArray(nums, l, m - 1);
    int rmax = maxSubArray(nums, m + 1, r);

    for (int i = m - 1, sum = 0; i >= l; --i) {
        sum += nums[i];
        ml = max(sum, ml);
    }

    for (int i = m + 1, sum = 0; i <= r; ++i) {
        sum += nums[i];
        mr = max(sum, mr);
    }

    return max(max(lmax, rmax), ml + mr + nums[m]);
}

int maxSubArrayV3(vector<int>& nums) {
    return maxSubArray(nums, 0, nums.size() - 1);
}

int maxSubArrayV1(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxSum = nums[0];
    int curSum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > curSum + nums[i]) {
            curSum = nums[i];
        } else {
            curSum += nums[i];
        }

        if (curSum > maxSum) {
            maxSum = curSum;
        }
    }

    return maxSum;
}

int maxSubArrayV2(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxSum = nums[0];
    int curSum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        curSum = max(curSum + nums[i], nums[i]);
        maxSum = max(curSum, maxSum);
    }

    return maxSum;
}

int main() {
    vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(maxSubArrayV3(v1) == 6);
    return 0;
}
