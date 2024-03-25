#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class CircularLinkedList {
private:
    ListNode* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int value) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            ListNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (!head)
            return;
        ListNode* temp = head;
        do {
            std::cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};
