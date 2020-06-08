#include <vector>
#include <cassert>
#include <limits>

using namespace std;

int maxProfit(vector<int>& prices) {
    int min_price = numeric_limits<int>::max();
    int max_profit = 0;
    for (auto p : prices) {
        if (p < min_price) {
            min_price = p;
        } else if (p - min_price > max_profit) {
            max_profit = p - min_price;
        }
    }
    return max_profit;
}

int main() {
    vector<int> v1 = {7, 1, 5, 3, 6, 4};
    auto rv1 = maxProfit(v1);
    assert(rv1 == 5);

    vector<int> v2 = {7, 6, 4, 3, 1};
    auto rv2 = maxProfit(v2);
    assert(rv2 == 0);

    vector<int> v3 = {7, 6, 4, 3, 1, 9};
    auto rv3 = maxProfit(v3);
    assert(rv3 == 8);

    vector<int> v4 = {};
    auto rv4 = maxProfit(v4);
    assert(rv4 == 0);

    vector<int> v5 = {7};
    auto rv5 = maxProfit(v5);
    assert(rv5 == 0);

    vector<int> v6 = {7, 9};
    auto rv6 = maxProfit(v6);
    assert(rv6 == 2);

    vector<int> v7 = {7, 5};
    auto rv7 = maxProfit(v7);
    assert(rv7 == 0);

    vector<int> v8 = {2, 8, 4, 9, 7, 5};
    auto rv8 = maxProfit(v8);
    assert(rv8 == 7);

    vector<int> v9 = {2, 1, 2, 1, 0, 1, 2};
    auto rv9 = maxProfit(v9);
    assert(rv9 == 2);

    vector<int> v10 = {3, 3, 5, 0, 0, 3, 1, 4};
    auto rv10 = maxProfit(v10);
    assert(rv10 == 4);

    return 0;
}
