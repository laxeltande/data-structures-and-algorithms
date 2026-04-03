
# Lab 4 – Permutations and State Simulation

## Overview

This project focuses on generating permutations and exploring different system states. The goal is to understand how to systematically enumerate all possible configurations of a dataset.

---

## Implementation

The program generates permutations by recursively swapping elements.

At each recursive level:
- One element is fixed in position
- The remaining elements are permuted

This continues until all possible arrangements are generated.

---

## Technical Explanation

The number of permutations of n elements is:

n!

This means the number of possible configurations grows very quickly as n increases.

The recursive structure ensures that all permutations are explored without duplication.

---

## Time Complexity

- Time Complexity: **O(n!)**
- Space Complexity: **O(n)** (recursion depth)

---

## Key Insight

Permutation problems are computationally expensive due to factorial growth.

Even small increases in input size lead to large increases in runtime.

---

## How to Run

```bash
make
./permute
