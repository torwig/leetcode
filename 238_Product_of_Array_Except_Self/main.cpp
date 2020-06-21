#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    int p1 = nums[0];
    int p2 = nums[nums.size() - 1];

    for (size_t i = 1; i < nums.size(); ++i) {
        result[i] = p1 * result[i];
        result[nums.size() - 1 - i] = p2 * result[nums.size() - 1 - i];
        p1 = p1 * nums[i];
        p2 = p2 * nums[nums.size() - 1 - i];
    }
    return result;
}

int main() {
    vector<int> v1 = {2, 3, 5, 4};
    auto res1 = productExceptSelf(v1);
    for (auto e : res1) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
