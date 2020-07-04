#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicatesV1(vector<int>& nums) {
    if (nums.empty()) return 0;

    int len = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[len - 1]) {
            swap(nums[i], nums[len]);
            ++len;
        }
    }

    return len;
}

int removeDuplicatesV2(vector<int>& nums) {
    auto it = unique(nums.begin(), nums.end());
    return distance(nums.begin(), it);
}

int removeDuplicatesV3(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0;
    for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] != nums[i]) {
            nums[++i] = nums[j];
        }
    }

    return i + 1;
}

int main() {
    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    auto len = removeDuplicatesV3(v);
    cout << "new len: " << len << endl;
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
