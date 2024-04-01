#include <iostream>

using namespace std;

// Define a node structure for the linked list
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        // Create a new node
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        // Update the top pointer
        top = newNode;
        cout << "Pushed " << value << " into the stack." << endl;
    }

    int pop() {
        if (!isEmpty()) {
            // Get the data from the top node
            int value = top->data;
            // Update the top pointer to the next node
            Node* temp = top;
            top = top->next;
            // Delete the old top node
            delete temp;
            return value;
        } else {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return top->data;
        } else {
            cout << "Stack is empty. No top element to peek." << endl;
            return -1;
        }
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top of the stack: " << stack.peek() << endl;

    while (!stack.isEmpty()) {
        cout << "Popped item: " << stack.pop() << endl;
    }

    return 0;
}
