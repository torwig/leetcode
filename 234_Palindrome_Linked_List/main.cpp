#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindromeV1(ListNode* head) {
    if (!head || !head->next) return true;

    stack<int> values;
    for (auto p = head; p; p = p->next) {
        values.push(p->val);
    }

    auto it = head;
    while (it) {
        if (it->val != values.top()) return false;
        values.pop();
        it = it->next;
    }

    return true;
}

bool isPalindromeV2(ListNode* head) {
    if (!head || !head->next) return true;

    auto slow = head;
    auto fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast) slow = slow->next; // if odd, move one step forward

    // Reverse second half
    ListNode* prev = nullptr;
    auto cur = slow;

    while (cur) {
        auto next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    // Compare first half with reversed second half
    while (prev) {
        if (prev->val != head->val) return false;
        prev = prev->next;
        head = head->next;
    }

    return true;
}

int main() {
    return 0;
}
