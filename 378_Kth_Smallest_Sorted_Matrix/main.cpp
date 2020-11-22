#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int kthSmallestV1(const vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;

    if (matrix.size() == 1) return matrix.front().front();

    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];

    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

struct compare
{
    bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b)
    {
        return a.first > b.first;
    }
};

int kthSmallestV2(const vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;

    if (matrix.size() == 1) return matrix.front().front();

    int n = matrix.size();
    int m = matrix[0].size();

    priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, compare > p;

    for (int i = 0; i < n; ++i) {
        p.push(make_pair(matrix[i][0], make_pair(i, 0)));
    }

    int x = k;
    int result;

    while (x--) {
        int e = p.top().first;
        int i = p.top().second.first;
        int j = p.top().second.second;

        result = e;
        p.pop();

        if (j != m - 1) {
            p.push(make_pair(matrix[i][j + 1], make_pair(i, j + 1)));
        }
    }

    return result;
}

int main() {

    return 0;
}
