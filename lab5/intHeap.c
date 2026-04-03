/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 100

static int heap[MAX_HEAP_SIZE];
static int heapSize = 0;

void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parent]) {
        // Swap with parent
        int temp = heap[index];
        heap[index] = heap[parent];
        heap[parent] = temp;
        // Move up to parent
        index = parent;
        parent = (index - 1) / 2;
    }
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete(){
    if (heapSize == 0) {
        printf("Error: Heap is empty\n");
        exit(EXIT_FAILURE);
    }

    int deleted = heap[0];
    heap[0] = heap[--heapSize];
    heapifyUp(0);
    return deleted;
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add){
	if (heapSize >= MAX_HEAP_SIZE) {
        printf("Error: Heap is full\n");
        exit(EXIT_FAILURE);
		}
    heap[heapSize++] = thing2add;
    heapifyUp(heapSize - 1);
}


/**
 * heapSize() returns the number of items in the Heap.
 *
 */
 //heapSize renamed to getHeapSize
int getHeapSize() {
  return heapSize;  
}
