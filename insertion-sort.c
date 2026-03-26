#include <stdio.h>

// Algorithm: Insertion Sort
// Time Complexity: O(n^2) in the worst and average case, O(n) in the best case (when the array is already sorted)
// Space Complexity: O(1) - Insertion Sort is an in-place sorting algorithm, meaning it requires only a constant amount of additional space for temporary variables during the sorting process.
// Stability: Insertion Sort is a stable sorting algorithm, meaning that it preserves the relative order of equal elements in the sorted output. If two elements are equal, they will maintain their original order in the sorted array.
// Use Cases: Insertion Sort is a simple sorting algorithm that is easy to understand and implement. It is often used for educational purposes to teach the concept of sorting. However, it is not efficient for large datasets and is generally not used in practice for sorting large arrays due to its poor performance compared to more advanced sorting algorithms like Quick Sort, Merge Sort, or Heap Sort.
// In summary, Insertion Sort is a straightforward sorting algorithm that is easy to implement and understand, but it is not efficient for large datasets and is primarily used for educational purposes to illustrate the concept of sorting.

// This function implements the insertion sort algorithm to sort an array of integers in ascending order
// Parameters:
// - arr: an array of integers to be sorted
// - n: the number of elements in the array
void insertion_sort(int arr[], int n);

// Main function to demonstrate the insertion sort algorithm
// It initializes an array of integers, calculates its length, calls the insertion_sort function to sort it, and then prints the sorted array
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

    // Call the insertion_sort function to sort the array
    insertion_sort(arr, lengthOfArray);

    printf("Sorted array: ");

    // Print the sorted array
    int i;
    for (i = 0; i < lengthOfArray; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Step by step implementation of the insertion sort algorithm
// for each element in the array, compare it with the previous element and shift elements if necessary
// continue this process until all elements are in their correct positions

// Pseudo code for insertion sort algorithm:
// function insertionSort(arr):
//     n = length of arr
//     for i from 1 to n-1:
//         key = arr[i]
//         j = i - 1
//         while j >= 0 and arr[j] > key:
//             arr[j + 1] = arr[j]
//             j = j - 1
//         arr[j + 1] = key

void insertion_sort(int arr[], int lengthOfArray) {
    // initialize variables for loop counters
    int i, j;
    int key;

    // Perform insertion sort algorithm
    // Outer loop to traverse through all elements starting from index 1
    for (i = 1; i < lengthOfArray; i++) {
        // Store current element as key
        key = arr[i];

        // Initialize j as index before current element
        j = i - 1;

        // Shift elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Insert key at its correct position
        arr[j + 1] = key;
    }
}