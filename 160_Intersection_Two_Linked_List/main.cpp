#include <cassert>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNodeV1(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    unordered_set<ListNode*> s;

    while (headA) {
        s.insert(headA);
        headA = headA->next;
    }

    while (headB) {
        if (s.find(headB) != s.end()) return headB;

        headB= headB->next;
    }

    return nullptr;
}

ListNode* getIntersectionNodeV2(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    auto it1 = headA;
    auto it2 = headB;

    while (it1 && it2 && it1 != it2) {
        it1 = it1->next;
        it2 = it2->next;

        if (it1 == it2) return it1;

        if (!it1) it1 = headB;

        if (!it2) it2 = headA;
    }

    return it1;
}

ListNode* getIntersectionNodeV3(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    auto it1 = headA;
    auto it2 = headB;

    int lenA = 0;
    int lenB = 0;

    while (it1) {
        ++lenA;
        it1 = it1->next;
    }

    while (it2) {
        ++lenB;
        it2 = it2->next;
    }

    int diff = abs(lenA - lenB);

    if (lenB > lenA) swap(headA, headB);

    while (diff-- > 0) {
        headA = headA->next;
    }

    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

int main() {
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode c1(4);
    ListNode c2(5);
    ListNode b1(-1);
    ListNode b2(-2);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &c1;
    c1.next = &c2;
    b1.next = &b2;
    b2.next = &c1;

    assert(getIntersectionNodeV3(&a1, &b1) == &c1);

    return 0;
}
