#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* findNthFromEnd(ListNode* head, int n) {
    if (!head)
        return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast pointer n nodes ahead
    for (int i = 0; i < n; ++i) {
        if (!fast)
            return nullptr; // List is not long enough
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
