#include <iostream>
#include <stack>

using namespace std;

class MinStackV1 {
public:
    MinStackV1() {

    }

    void push(int x) {
        values_.push(x);
        if (!min_values_.empty()) {
            auto curMin = min_values_.top();
            min_values_.push(min(curMin, x));
        } else {
            min_values_.push(x);
        }
    }

    void pop() {
        values_.pop();
        min_values_.pop();
    }

    int top() {
        return values_.top();
    }

    int getMin() {
        return min_values_.top();
    }

private:
    stack<int> values_;
    stack<int> min_values_;
};

class MinStackV2 {
public:
    MinStackV2() {

    }

    void push(int x) {
        if (values_.empty()) {
            values_.push({x, x});
        } else {
            values_.push({x, min(values_.top().second, x)});
        }
    }

    void pop() {
        values_.pop();
    }

    int top() {
        return values_.top().first;
    }

    int getMin() {
        return values_.top().second;
    }

private:
    stack<pair<int, int>> values_;
};

class MinStackV3 {
public:
    MinStackV3() {

    }

    void push(int x) {
        if (x <= min_) {
            values_.push(min_);
            min_ = x;
        }
        values_.push(x);
    }

    void pop() {
        if (values_.top() == min_) {
            values_.pop();
            min_ = values_.top();
            values_.pop();
        } else {
            values_.pop();
        }
    }

    int top() {
        return values_.top();
    }

    int getMin() {
        return min_;
    }

private:
    stack<int> values_;
    int min_ = numeric_limits<int>::max();
};

int main() {
    MinStackV3 s;
    s.push(5);
    s.push(2);
    s.push(-5);
    s.push(1);
    cout << s.getMin() << endl;
    return 0;
}
