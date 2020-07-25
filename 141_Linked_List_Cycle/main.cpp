#include <iostream>
#include <cassert>

struct ListNode {
     int val;
     ListNode *next;
     explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static bool hasCycleV1(ListNode *head) {
        if (!head || !head->next || !head->next->next) return false;

        auto it1 = head;
        auto it2 = head->next->next;

        while (it1 && it2) {
            if (it1 == it2) return true;

            it1 = it1->next;
            if (!it2->next) return false;
            it2 = it2->next->next;
        }

        return false;
    }

    static bool hasCycleV2(ListNode *head) {
        auto it1 = head;
        auto it2 = head;

        while (it2 && it2->next) {
            it1 = it1->next;
            it2 = it2->next->next;

            if (it1 == it2) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    assert(!Solution::hasCycleV2(&node1));
    node4.next = &node2;
    assert(Solution::hasCycleV2(&node1));
    return 0;
}
