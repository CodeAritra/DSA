#include <stdio.h>

// Function to partition the array around the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choose the first element as pivot
    int i = low + 1;      // Index of the smaller element
    int j = high;         // Index for elements larger than the pivot

    while (i <= j) {
        // Find an element greater than the pivot from the left
        while (i <= j && arr[i] <= pivot)
            i++;

        // Find an element smaller than the pivot from the right
        while (i <= j && arr[j] > pivot)
            j--;

        // Swap elements at i and j if needed
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place the pivot in its correct position
    arr[low] = arr[j];
    arr[j] = pivot;

    return j; // Return the partition index
}

// Recursive function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}
