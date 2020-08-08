#include <iostream>
#include <vector>

using namespace std;

void mergeV1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    size_t it1 = 0;
    size_t it2 = 0;
    size_t mergedLen = m;

    while (it1 < mergedLen && it2 < n) {
        if (nums1[it1] <= nums2[it2]) {
            ++it1;
            continue;
        }

        for (size_t i = mergedLen; i > it1; --i) {
            nums1[i] = nums1[i - 1];
        }

        nums1[it1] = nums2[it2];

        ++it1;
        ++it2;
        ++mergedLen;
    }

    for (size_t i = it2; i < n; ++i) {
        nums1[it1] = nums2[i];
        ++it1;
    }
}

void mergeV2(vector<int>& nums1, int m, const vector<int>& nums2, int n)
{
    size_t write = n + m - 1;

    --m;
    --n;

    while (n >= 0 && m >= 0) {
        if (nums1[m] > nums2[n]) {
            nums1[write] = nums1[m];
            --m;
        } else {
            nums1[write] = nums2[n];
            --n;
        }
        --write;
    }

    while (n >= 0) {
        nums1[write] = nums2[n];
        --n;
        --write;
    }
}

int main() {
    vector<int> v1 = {1, 3, 5, 0, 0, 0};
    vector<int> v2 = {2, 4, 8};
    mergeV2(v1, 3, v2, 3);
    for (auto e : v1) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
