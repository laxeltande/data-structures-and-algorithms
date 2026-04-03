# Lab 1 – Insertion Sort and Command-Line Input

## Overview

This project implements insertion sort in C and processes integer inputs provided through the command line. The goal is to understand how sorting works at a low level and how to design reusable functions.

---

## Implementation

The sorting logic is implemented using a function that operates on a subarray:

```c

betterSort(data, first, last);
```

## Technical Explanation

Insertion sort maintains two regions within the array:

- A **sorted region** on the left
- An **unsorted region** on the right

At each step:

1. The first element of the unsorted region is selected
2. It is compared with elements in the sorted region
3. Elements are shifted to the right until the correct position is found
4. The element is inserted into its correct position

This process repeats until the entire array is sorted.

---

## Time Complexity

- Best Case: **O(n)**
- Worst Case: **O(n^2)**
- Average Case: **O(n^2)**

Insertion sort performs well for small or nearly sorted datasets but scales poorly for large inputs.

---

## Design Notes

- Sorting using index bounds improves flexibility
- The algorithm is **in-place** (no extra memory required)
- The algorithm is **stable** (preserves order of equal elements)
