# DSA Sorting Algorithms

A collection of classic sorting algorithms implemented in C, written as part of a Data Structures and File Processing assignment (CSC706, University of Lagos).

## Algorithms

| Algorithm | File | Time Complexity (Best/Avg/Worst) | Space | Stable |
|---|---|---|---|---|
| Bubble Sort | `bubble-sort.c` | O(n) / O(n²) / O(n²) | O(1) | Yes |
| Insertion Sort | `insertion-sort.c` | O(n) / O(n²) / O(n²) | O(1) | Yes |
| Selection Sort | `selection-sort.c` | O(n²) / O(n²) / O(n²) | O(1) | No |
| Quick Sort | `quick-sort.c` | O(n log n) / O(n log n) / O(n²) | O(log n) | No |
| Merge Sort | `merge-sort.c` | O(n log n) / O(n log n) / O(n log n) | O(n) | Yes |

## Compiling and Running

Each file is self-contained with its own `main` function. Compile and run individually:

```bash
gcc bubble-sort.c -o bubble-sort && ./bubble-sort
gcc insertion-sort.c -o insertion-sort && ./insertion-sort
gcc selection-sort.c -o selection-sort && ./selection-sort
gcc quick-sort.c -o quick-sort && ./quick-sort
gcc merge-sort.c -o merge-sort && ./merge-sort
```

Each program sorts the test array `{64, 34, 25, 12, 22, 11, 90}` and prints the original and sorted output.
