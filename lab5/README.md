
# Lab 5 – Stacks and Heaps

## Overview

This project implements stack and heap data structures from scratch in C. The goal is to understand how these structures manage data and memory.

---

## Implementation

### Stack

The stack follows a Last-In-First-Out (LIFO) structure.

Operations implemented:
- Push (insert element)
- Pop (remove element)
- Peek (view top element)

The stack is implemented using dynamic memory allocation.

---

### Heap

The heap is implemented as a structured tree-based data structure.

It maintains ordering properties such that:
- The root element is either the minimum or maximum
- Insertions and removals preserve this structure

---

## Technical Explanation

Stacks provide constant-time operations and are useful for managing function calls and temporary data.

Heaps are typically implemented using arrays and support efficient insertion and removal while maintaining order.

---

## Time Complexity

### Stack
- Push: **O(1)**
- Pop: **O(1)**
- Peek: **O(1)**

### Heap
- Insert: **O(log n)**
- Remove: **O(log n)**
- Access root: **O(1)**

---

## Key Insight

Correct memory management is critical when implementing data structures in C.

Heaps provide efficient priority-based access, while stacks are ideal for sequential processing.

---

## How to Run

```bash
make
./part1Main
./part2Main
