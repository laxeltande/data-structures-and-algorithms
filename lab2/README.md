
# Lab 2 – Towers of Hanoi

## Overview

This project implements a recursive solution to the Towers of Hanoi problem. It demonstrates how complex problems can be solved by breaking them into smaller subproblems.

---

## Implementation

The recursive function moves disks between towers using an auxiliary tower:

- Move n-1 disks to auxiliary tower
- Move largest disk to destination
- Move n-1 disks to destination

---

## Technical Explanation

The recurrence relation for the number of moves is:

T(n) = 2T(n-1) + 1

Solving this gives:

T(n) = 2^n - 1

This represents the minimum number of moves required.

---

## Time Complexity

- Time Complexity: **O(2^n)**
- Space Complexity: **O(n)** (recursion stack)

---

## Key Insight

The number of operations grows exponentially, making the algorithm impractical for large values of n.

Example:
- n = 8 → 255 moves

---

## How to Run

```bash
gcc towersMain.c towers.c -o towers
./towers 5 1 3
