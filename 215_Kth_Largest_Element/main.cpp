#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>

using namespace std;

int findKthLargestV1(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin() + k, nums.end(), greater());
    return nums[k];
}

int findKthLargestV2(vector<int>& nums, int k) {
    partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater());
    return nums[k - 1];
}

// min-heap
int findKthLargestV3(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : nums) {
        pq.push(num);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}

// max-heap
int findKthLargestV4(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i) {
        pq.pop();
    }
    return pq.top();
}

// min-heap
int findKthLargestV5(vector<int>& nums, int k) {
    multiset<int> mset;
    for (int num : nums) {
        mset.insert(num);
        if (mset.size() > k) {
            mset.erase(mset.begin());
        }
    }
    return *mset.begin();
}

// max-heap
int findKthLargestV6(vector<int>& nums, int k) {
    multiset<int, greater<int>> mset(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++) {
        mset.erase(mset.begin());
    }
    return *mset.begin();
}

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int l = left + 1;
    int r = right;

    while (l <= r) {
        if (nums[l] < pivot && nums[r] > pivot) {
            swap(nums[l++], nums[r--]);
        }
        if (nums[l] >= pivot) {
            ++l;
        }
        if (nums[r] <= pivot) {
            --r;
        }
    }
    swap(nums[left], nums[r]);

    return r;
}

int findKthLargestV7(vector<int>& nums, int k) {
    int left = 0;
    int right = nums.size() - 1;
    int kth;

    while (true) {
        int idx = partition(nums, left, right);
        if (idx == k - 1) {
            kth = nums[idx];
            break;
        }

        if (idx < k - 1) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }

    return kth;
}

int findKthLargestV8(vector<int>& nums, int k) {
    const int n = nums.size();
    int left = 0;
    int right = n;

    while (left < right) {
        int i = left;
        int j = right - 1;
        int pivot = nums[left];

        while (i <= j) {
            while (i <= j && nums[i] >= pivot) ++i;
            while (i <= j && nums[j] < pivot) --j;
            if (i < j)
                swap(nums[i++], nums[j--]);
        }

        swap(nums[left], nums[j]);

        if (j == k - 1) return nums[j];
        if (j < k - 1) {
            left = j + 1;
        } else {
            right = j;
        }
    }

    return -1;
}

int main() {

    return 0;
}
