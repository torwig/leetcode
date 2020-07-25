#include <cassert>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int findDuplicateV1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    auto it = adjacent_find(nums.begin(), nums.end());
    if (it != nums.end()) {
        return *it;
    }

    return 0;
}

int findDuplicateV2(vector<int>& nums) {
    unordered_set<int> s;
    for (auto e : nums) {
        if (s.find(e) != s.end()) {
            return e;
        }

        s.insert(e);
    }

    return 0;
}

// Floyd's tortoise and hare
int findDuplicateV3(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[nums[0]];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return fast;
}

int findDuplicateV4(vector<int>& nums) {
    int low = 1;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (auto num : nums) {
            if (num <= mid) ++count;
        }

        if (count > mid) high = mid;
        else low = mid + 1;
    }

    return low;
}

int main() {
    vector<int> v1 = {2, 5, 7, 9, 8, 7, 4, 6, 1, 7};
    assert(findDuplicateV4(v1) == 7);
    return 0;
}
