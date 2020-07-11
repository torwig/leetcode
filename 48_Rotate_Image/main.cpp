#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (auto& v : matrix) {
        reverse(v.begin(), v.end());
    }
}

int main() {
    vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    rotate(matrix);

    for (auto& v : matrix) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
