#include <iostream>

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    ListNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(int value) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void display() {
        ListNode* temp = head;
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
