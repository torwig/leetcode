#include <stack>
#include <string>
#include <cassert>

using namespace std;

bool isValidV1(string s) {
    if (s.empty()) return true;

    stack<char> tmp;

    for (auto c : s) {
        if (tmp.empty()) {
            tmp.push(c);
            continue;
        }

        auto prev = tmp.top();
        switch (c) {
            case ')':
                if (prev != '(') return false;
                tmp.pop();
                break;
            case ']':
                if (prev != '[') return false;
                tmp.pop();
                break;
            case '}':
                if (prev != '{') return false;
                tmp.pop();
                break;
            default:
                tmp.push(c);
        }
    }

    return tmp.empty();
}

bool isValidV2(string s) {
    if (s.empty()) return true;

    stack<char> tmp;

    for (auto c : s) {
        if (c == '('|| c == '{' || c == '[') {
            tmp.push(c);
        } else {
            if (tmp.empty()) return false;

            if (c == ')' && tmp.top() != '(') return false;

            if (c == '}' && tmp.top() != '{') return false;

            if (c == ']' && tmp.top() != '[') return false;

            tmp.pop();
        }
    }

    return tmp.empty();
}

int main() {
    assert(isValidV2(""));
    assert(isValidV2("()"));
    assert(isValidV2("[]"));
    assert(isValidV2("{}"));
    assert(isValidV2("{[()]}"));
    assert(isValidV2("([])"));
    assert(isValidV2("()[]{}"));
    assert(!isValidV2("([)]"));
    return 0;
}
