#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Function to insert an element at a given position in the array
void insertElement(int arr[], int& size, int element, int position) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert element." << endl;
        return;
    }

    if (position < 0 || position > size) {
        cout << "Invalid position. Element cannot be inserted." << endl;
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > position; --i) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the given position
    arr[position] = element;

    // Increment the size of the array
    size++;
}

// Function to delete an element from a given position in the array
void deleteElement(int arr[], int& size, int position) {
    if (size <= 0 || position < 0 || position >= size) {
        cout << "Invalid position. Element cannot be deleted." << endl;
        return;
    }

    // Shift elements to the left to fill the gap created by deletion
    for (int i = position; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    // Decrement the size of the array
    size--;
}

// Function to display the array
void displayArray(const int arr[], int size) {
    cout << "Array Elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // Insert elements into the array
    insertElement(arr, size, 10, 0);
    insertElement(arr, size, 20, 1);
    insertElement(arr, size, 30, 2);
    insertElement(arr, size, 40, 3);
    insertElement(arr, size, 50, 4);

    // Display the array
    displayArray(arr, size);

    // Delete an element from the array
    deleteElement(arr, size, 2);

    // Display the array after deletion
    displayArray(arr, size);

    return 0;
}
