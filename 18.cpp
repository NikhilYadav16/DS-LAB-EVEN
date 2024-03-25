#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Insertion at a position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 0 || !head) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < position - 1 && current->next; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Deletion at a position
    void deleteFromPosition(int position) {
        if (!head) {
            return;
        }
        Node* temp = head;
        if (position == 0) {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 0; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            return;
        }
        Node* nextNode = temp->next->next;
        delete temp->next;
        temp->next = nextNode;
    }

    // Display the linked list
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtPosition(1, 0);
    list.insertAtPosition(3, 1);
    list.insertAtPosition(2, 1);
    list.display(); // Output: 1 2 3
    list.deleteFromPosition(1);
    list.display(); // Output: 1 3
    return 0;
}
