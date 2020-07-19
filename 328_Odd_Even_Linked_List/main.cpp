struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenListV1(ListNode* head) {
    if (!head ||
        !head->next ||
        !head->next->next) {
        return head;
    }

    auto oddHead = head;
    auto curOdd = head;

    auto evenHead = head->next;
    auto curEven = head->next;

    auto nextNode = head->next->next;
    bool isOdd = true;

    while (nextNode) {
        auto tmp = nextNode->next;
        if (isOdd) {
            curOdd->next = nextNode;
            curOdd = nextNode;
        } else {
            curEven->next = nextNode;
            curEven = nextNode;
        }

        isOdd = !isOdd;
        nextNode = tmp;
    }

    curOdd->next = evenHead;
    curEven->next = nullptr;

    return oddHead;
}

ListNode* oddEvenListV2(ListNode* head) {
    if (!head ||
        !head->next ||
        !head->next->next) {
        return head;
    }

    auto odd = head;
    auto even = head->next;
    auto evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

int main() {

    return 0;
}
