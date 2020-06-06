#include <vector>
#include <cassert>

using namespace std;

int missingNumberBitManipulation(vector<int>& nums) {
    int result = nums.size();
    for (size_t i = 0; i < nums.size(); ++i) {
        result ^= i;
        result ^= nums[i];
    }
    return result;
}

int main() {
    vector<int> v1 = {0, 2, 1};
    auto rv1 = missingNumberBitManipulation(v1);
    assert(rv1 == 3);

    vector<int> v2 = {4, 1, 3, 0};
    auto rv2 = missingNumberBitManipulation(v2);
    assert(rv2 == 2);

    vector<int> v3;
    auto rv3 = missingNumberBitManipulation(v3);
    assert(rv3 == 0);

    return 0;
}
