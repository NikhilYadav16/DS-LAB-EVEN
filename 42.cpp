#include <iostream>

using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (!isFull()) {
            arr[++top] = value;
            cout << "Pushed " << value << " into the stack." << endl;
        } else {
            cout << "Stack overflow! Cannot push " << value << " into the stack." << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
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
