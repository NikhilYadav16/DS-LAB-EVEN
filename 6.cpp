#include <iostream>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; // Return index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int arr[] = {5, 8, 3, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    int index = linearSearch(arr, size, key);

    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}

