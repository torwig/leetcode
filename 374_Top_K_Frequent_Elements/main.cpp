#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct NumberFreq {
    NumberFreq(int n, int f) : number(n), freq(f) {}
    int number;
    int freq;
};

bool operator<(const NumberFreq& nf1, const NumberFreq& nf2) {
    return nf1.freq > nf2.freq;
}

vector<int> topKFrequentV1(vector<int>& nums, int k) {
    vector<int> result;
    result.reserve(k);

    unordered_map<int, int> m;
    for (auto e : nums) {
        ++m[e];
    }

    if (m.size() <= k) {
        for (auto& p : m) {
            result.push_back(p.first);
        }
        return result;
    }


    priority_queue<NumberFreq> q;

    for (auto& [n, f] : m) {
        if (q.size() == k) {
            if (q.top().freq < f) {
                q.pop();
                q.emplace(n, f);
            }
        } else {
            q.emplace(n, f);
        }
    }

    while (!q.empty()) {
        result.push_back(q.top().number);
        q.pop();
    }

    return result;
}

vector<int> topKFrequentV2(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto e : nums) {
        ++m[e];
    }

    vector<int> result;
    result.reserve(m.size());

    for (auto& p : m) {
        result.push_back(p.first);
    }

    nth_element(result.begin(), result.begin() + k - 1, result.end(),
            [&m](int l, int r) {
        return m[l] > m[r];
    });
    result.resize(k);

    return result;
}

vector<int> topKFrequentV3(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto e : nums) {
        ++m[e];
    }

    vector<vector<int>> buckets(nums.size() + 1);
    for (auto p : m) {
        buckets[p.second].push_back(p.first);
    }

    vector<int> result;
    result.reserve(k);

    for (size_t i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
        for (int e : buckets[i]) {
            result.push_back(e);
            if (result.size() == k) break;
        }
    }

    return result;
}

int main() {
    vector<int> v1 = {5, 7, 4, 3, 2, 1, 3, 4, 5, 6, 2, 4, 3, 7, 5, 1, 3, 9, 2, 3, 7, 5, 4, 6, 4};
    auto result1 = topKFrequentV3(v1, 3);
    for (auto e : result1) {
        cout << e << endl;
    }
    return 0;
}
