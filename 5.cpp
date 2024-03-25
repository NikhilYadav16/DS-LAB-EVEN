#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the array

void insertAtEnd(int arr[], int& size, int value) {
    if (size == MAX_SIZE) {
        std::cout << "Overflow! Array is full. Cannot insert." << std::endl;
        return;
    }

    arr[size] = value; // Insert new element at the end
    ++size;
}

void deleteFromEnd(int arr[], int& size) {
    if (size == 0) {
        std::cout << "Underflow! Array is empty. Cannot delete." << std::endl;
        return;
    }

    --size; // Simply decrease the size to "delete" the last element
}

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4};
    int size = 4;

    // Insertion at the end
    insertAtEnd(arr, size, 5);

    // Display array after insertion
    std::cout << "After insertion: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Deletion at the end
    deleteFromEnd(arr, size);

    // Display array after deletion
    std::cout << "After deletion: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
