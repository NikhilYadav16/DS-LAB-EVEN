#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next)
        return true;

    std::stack<int> st;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the length is odd, skip the middle element
    if (fast)
        slow = slow->next;

    while (slow) {
        if (slow->val != st.top())
            return false;
        st.pop();
        slow = slow->next;
    }

    return true;
}
