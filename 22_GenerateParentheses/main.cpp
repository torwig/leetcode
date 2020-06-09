#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generate_(vector<string>& result, string input, int open, int close, int n) {
    if (open == n) {
        if (close != n) {
            input += string(n - close, ')' );
        }
        result.push_back(input);
        return;
    }
    if (open > close) {
        generate_(result, input + "(", open + 1, close, n);
        generate_(result, input + ")", open, close + 1, n);
    } else if (open == close) {
        generate_(result, input + "(", open + 1, close, n);
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    generate_(result, "(", 1, 0, n);
    return result;
}

int main() {
    auto result = generateParentheses(3);
    for (auto& s : result) {
        cout << s << endl;
    }
    return 0;
}
