#include <stdio.h>
#include <stdbool.h>


// Algorithm: Bubble Sort
// Time Complexity: O(n^2) in the worst and average case, O(n) in the best case (when the array is already sorted)
// Space Complexity: O(1) - Bubble Sort is an in-place sorting algorithm, meaning it requires only a constant amount of additional space for temporary variables during the sorting process.
// Stability: Bubble Sort is a stable sorting algorithm, meaning that it preserves the relative order of equal elements in the sorted output. If two elements are equal, they will maintain their original order in the sorted array.
// Use Cases: Bubble Sort is a simple sorting algorithm that is easy to understand and implement. It is often used for educational purposes to teach the concept of sorting. However, it is not efficient for large datasets and is generally not used in practice for sorting large arrays due to its poor performance compared to more advanced sorting algorithms like Quick Sort, Merge Sort, or Heap Sort.
// In summary, Bubble Sort is a straightforward sorting algorithm that is easy to implement and understand, but it is not efficient for large datasets and is primarily used for educational purposes to illustrate the concept of sorting.

// This function implements the bubble sort algorithm to sort an array of integers in ascending order
// Parameters:
// - arr: an array of integers to be sorted
// - n: the number of elements in the array
void bubble_sort(int arr[], int n);

// Main function to demonstrate the bubble sort algorithm
// It initializes an array of integers, calculates its length, calls the bubble_sort function to sort it, and then prints the sorted array

int main() {
    // Initialize an array of integers to be sorted
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate the length of the array
    int lenghtOfArray = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int k = 0; k < lenghtOfArray; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");


    // Call the bubble_sort function to sort the array
    bubble_sort(arr, lenghtOfArray);
    
    printf("Sorted array: ");
    
    // Print the sorted array
    int i;
    for (i = 0; i < lenghtOfArray; i++) {
        printf("%d ", arr[i]);  
    }
    printf("\n");

    return 0;
}

// Step by step implementation of the bubble sort algorithm
// for each element in the array, compare it with the next element and swap if they are in the wrong order
// after each pass, the largest element will be bubbled to the end of the array, so we can reduce the number of comparisons in subsequent passes
// the process is repeated until the entire array is sorted

// Pseudo code for bubble sort algorithm:
// function bubbleSort(arr):
//     n = length of arr
//     for i from 0 to n-1:
//         for j from 0 to n-i-2:
//             if arr[j] > arr[j+1]:
//                 swap arr[j] and arr[j+1]

void bubble_sort(int arr[], int lengthOfArray) {
  // initialize variables for loop counters
    int i, j;
    bool swapped = false;

    // Perform bubble sort algorithm
    // Outer loop to traverse through all elements
    for (i = 0; i < lengthOfArray-1; i++) {
      swapped = false; // reset swapped to false at the beginning of each pass
        // Inner loop to compare adjacent elements
        for (j = 0; j < lengthOfArray-i-1; j++) {
            // check if the current element is greater than the next element
            if (arr[j] > arr[j+1]) {
              // if true, swap the elements
              // bubble up the larger element to the end of the array
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true; // set swapped to true
            }
        }
        if (!swapped) {
            break; // If no swapping occurred, the array is already sorted
        }
    }
}