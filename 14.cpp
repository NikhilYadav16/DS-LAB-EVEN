#include <iostream>

int findFloor(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    int floorIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key) {
            floorIndex = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }
    return floorIndex;
}

int findCeil(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    int ceilIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key) {
            ceilIndex = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }
    return ceilIndex;
}

int findPeak(int arr[], int size) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid] >= arr[mid - 1]) &&
            (mid == size - 1 || arr[mid] >= arr[mid + 1]))
            return mid;
        else if (mid > 0 && arr[mid - 1] > arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1; // No peak found
}

int findMinimum(int arr[], int size) {
    int low = 0, high = size - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[high])
            high = mid;
        else
            low = mid + 1;
    }

    return arr[low];
}

int main() {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int floorIndex = findFloor(arr, size, key);
    int ceilIndex = findCeil(arr, size, key);
    int peakIndex = findPeak(arr, size);
    int minimum = findMinimum(arr, size);

    std::cout << "Floor of " << key << " is at index: " << floorIndex << std::endl;
    std::cout << "Ceil of " << key << " is at index: " << ceilIndex << std::endl;
    std::cout << "Peak is at index: " << peakIndex << std::endl;
    std::cout << "Minimum element in the rotated array: " << minimum << std::endl;

    return 0;
}
