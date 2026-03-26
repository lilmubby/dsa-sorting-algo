#include <stdio.h>

// Algorithm: Selection Sort
// Time Complexity: O(n^2) in the worst and average case, O(n^2) in the best case (when the array is already sorted)
// Space Complexity: O(1) - Selection Sort is an in-place sorting algorithm, meaning it requires only a constant amount of additional space for temporary variables during the sorting process.
// Stability: Selection Sort is not a stable sorting algorithm, meaning that it does not preserve the relative order of equal elements in the sorted output.
// Use Cases: Selection Sort is a simple sorting algorithm that is easy to understand and implement. It is often used for educational purposes to teach the concept of sorting. However, it is not efficient for large datasets and is generally not used in practice for sorting large arrays due to its poor performance compared to more advanced sorting algorithms like Quick Sort, Merge Sort, or Heap Sort.
// In summary, Selection Sort is a straightforward sorting algorithm that is easy to implement and understand, but it is not efficient for large datasets and is primarily used for educational purposes to illustrate the concept of sorting.

// This function implements the selection sort algorithm to sort an array of integers in ascending order
// Parameters:
// - arr: an array of integers to be sorted
// - n: the number of elements in the array
void selection_sort(int arr[], int n);

// Main function to demonstrate the selection sort algorithm
// It initializes an array of integers, calculates its length, calls the selection_sort function to sort it, and then prints the sorted array
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

    // Call the selection_sort function to sort the array
    selection_sort(arr, lengthOfArray);

    printf("Sorted array: ");

    // Print the sorted array
    int i;
    for (i = 0; i < lengthOfArray; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Step by step implementation of the selection sort algorithm
// for each element in the array, find the minimum element from the remaining unsorted portion and swap it with the current element
// continue this process until all elements are in their correct positions

// Pseudo code for selection sort algorithm:
// function selectionSort(arr):
//     n = length of arr
//     for i from 0 to n-1:
//         minIndex = i
//         for j from i+1 to n-1:
//             if arr[j] < arr[minIndex]:
//                 minIndex = j
//         swap arr[i] and arr[minIndex]

void selection_sort(int arr[], int lengthOfArray) {
    // initialize variables for loop counters
    int i, j;
    int minIndex;

    // Perform selection sort algorithm
    // Outer loop to traverse through all elements
    for (i = 0; i < lengthOfArray-1; i++) {
        // Initialize minIndex as current element index
        minIndex = i;

        // Inner loop to find minimum element from remaining unsorted portion
        for (j = i+1; j < lengthOfArray; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap current element with minimum element found
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}