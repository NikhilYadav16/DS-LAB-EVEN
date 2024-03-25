#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the array

void insertAtBeginning(int arr[], int& size, int value) {
    if (size == MAX_SIZE) {
        std::cout << "Array is full. Cannot insert." << std::endl;
        return;
    }

    // Shift elements to the right
    for (int i = size; i > 0; --i) {
        arr[i] = arr[i - 1];
    }

    // Insert new element at the beginning
    arr[0] = value;
    ++size;
}

void deleteFromBeginning(int arr[], int& size) {
    if (size == 0) {
        std::cout << "Array is empty. Cannot delete." << std::endl;
        return;
    }

    // Shift elements to the left
    for (int i = 0; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    --size;
}

int main() {
    int arr[MAX_SIZE] = {2, 3, 4, 5};
    int size = 4;

    // Insertion at the beginning
    insertAtBeginning(arr, size, 1);

    // Display array after insertion
    std::cout << "After insertion: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Deletion at the beginning
    deleteFromBeginning(arr, size);

    // Display array after deletion
    std::cout << "After deletion: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
