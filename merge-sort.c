#include <stdio.h>

// Algorithm: Merge Sort
// Time Complexity: O(n log n) in the best, average, and worst case
// Space Complexity: O(n) - Merge Sort requires additional space proportional to the size of the input array for the temporary arrays used during merging.
// Stability: Merge Sort is a stable sorting algorithm, meaning that it preserves the relative order of equal elements in the sorted output. If two elements are equal, they will maintain their original order in the sorted array.
// Use Cases: Merge Sort is a highly efficient and stable sorting algorithm. It is particularly useful when sorting linked lists, external sorting (sorting data that does not fit in memory), and when stability is required. Its guaranteed O(n log n) performance makes it preferable over Quick Sort when worst-case performance matters.
// In summary, Merge Sort is a reliable divide-and-conquer sorting algorithm with consistent O(n log n) performance, though it requires extra memory compared to in-place algorithms like Quick Sort.

// This function implements the merge sort algorithm to sort an array of integers in ascending order
// Parameters:
// - arr: an array of integers to be sorted
// - left: the starting index of the subarray to be sorted
// - right: the ending index of the subarray to be sorted
void merge_sort(int arr[], int left, int right);

// Main function to demonstrate the merge sort algorithm
// It initializes an array of integers, calculates its length, calls the merge_sort function to sort it, and then prints the sorted array
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

    // Call the merge_sort function to sort the array
    merge_sort(arr, 0, lengthOfArray - 1);

    printf("Sorted array: ");

    // Print the sorted array
    int i;
    for (i = 0; i < lengthOfArray; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Step by step implementation of the merge sort algorithm
// divide the array into two halves, recursively sort each half, then merge the two sorted halves back together
// the merge step combines two sorted subarrays into a single sorted subarray

// Pseudo code for merge sort algorithm:
// function mergeSort(arr, left, right):
//     if left < right:
//         mid = (left + right) / 2
//         mergeSort(arr, left, mid)
//         mergeSort(arr, mid + 1, right)
//         merge(arr, left, mid, right)
//
// function merge(arr, left, mid, right):
//     create temp arrays leftArr and rightArr
//     copy arr[left..mid] into leftArr
//     copy arr[mid+1..right] into rightArr
//     merge leftArr and rightArr back into arr[left..right] in sorted order

// Helper function to merge two sorted subarrays arr[left..mid] and arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    // Calculate sizes of the two subarrays to be merged
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Create temporary arrays to hold the two subarrays
    int leftArr[leftSize], rightArr[rightSize];

    // Copy data into temporary arrays
    int i, j;
    for (i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the two temporary arrays back into arr[left..right]
    i = 0;       // Initial index of left subarray
    j = 0;       // Initial index of right subarray
    int k = left; // Initial index of merged subarray

    while (i < leftSize && j < rightSize) {
        // Pick the smaller element from the two subarrays and place it in arr
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArr into arr
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArr into arr
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point to divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively sort the left half
        merge_sort(arr, left, mid);

        // Recursively sort the right half
        merge_sort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}
