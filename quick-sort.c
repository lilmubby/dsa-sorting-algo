#include <stdio.h>

// Algorithm: Quick Sort
// Time Complexity: O(n log n) in the best and average case, O(n^2) in the worst case (when the pivot is always the smallest or largest element)
// Space Complexity: O(log n) - Quick Sort is an in-place sorting algorithm, but it uses O(log n) space on the call stack due to recursion.
// Stability: Quick Sort is not a stable sorting algorithm, meaning that it does not preserve the relative order of equal elements in the sorted output.
// Use Cases: Quick Sort is one of the most efficient general-purpose sorting algorithms. It is widely used in practice due to its average-case O(n log n) performance and low constant factors. It is particularly effective for large datasets and is often the algorithm of choice when memory usage is a concern, as it sorts in-place.
// In summary, Quick Sort is a highly efficient divide-and-conquer sorting algorithm that performs well in practice, though it requires careful pivot selection to avoid worst-case performance.

// This function implements the quick sort algorithm to sort an array of integers in ascending order
// Parameters:
// - arr: an array of integers to be sorted
// - low: the starting index of the subarray to be sorted
// - high: the ending index of the subarray to be sorted
void quick_sort(int arr[], int low, int high);

// Main function to demonstrate the quick sort algorithm
// It initializes an array of integers, calculates its length, calls the quick_sort function to sort it, and then prints the sorted array
int main() {
    // Initialize an array of integers to be sorted
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate the length of the array
    int lengthOfArray = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int k = 0; k < lengthOfArray; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    // Call the quick_sort function to sort the array
    quick_sort(arr, 0, lengthOfArray - 1);

    printf("Sorted array: ");

    // Print the sorted array
    int i;
    for (i = 0; i < lengthOfArray; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Step by step implementation of the quick sort algorithm
// choose a pivot element, partition the array around the pivot so that elements less than the pivot are on the left and elements greater are on the right
// recursively apply the same process to the left and right subarrays

// Pseudo code for quick sort algorithm:
// function quickSort(arr, low, high):
//     if low < high:
//         pivotIndex = partition(arr, low, high)
//         quickSort(arr, low, pivotIndex - 1)
//         quickSort(arr, pivotIndex + 1, high)
//
// function partition(arr, low, high):
//     pivot = arr[high]
//     i = low - 1
//     for j from low to high - 1:
//         if arr[j] <= pivot:
//             i = i + 1
//             swap arr[i] and arr[j]
//     swap arr[i + 1] and arr[high]
//     return i + 1

// Helper function to partition the array around a pivot element
// Places the pivot in its correct sorted position and returns the pivot index
int partition(int arr[], int low, int high) {
    // Choose the last element as the pivot
    int pivot = arr[high];

    // Index of the smaller element, tracks the boundary of elements <= pivot
    int i = low - 1;

    int j;
    for (j = low; j < high; j++) {
        // If current element is less than or equal to pivot, move it to the left partition
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position by swapping with element at i+1
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the left subarray (elements less than pivot)
        quick_sort(arr, low, pivotIndex - 1);

        // Recursively sort the right subarray (elements greater than pivot)
        quick_sort(arr, pivotIndex + 1, high);
    }
}
