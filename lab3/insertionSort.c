#include "mySort.h"

/* Implementation of the mySort function using Insertion Sort */
void mySort(int array[], unsigned int first, unsigned int last) {
    unsigned int i, j;
    int key;

    // Nothing to sort?
    if (first == last) {
        return;
    }

    /* Iterate through the array, starting from the second element */
    for (i = first + 1; i <= last; i++) {
        key = array[i];
        j = i - 1;

        /* Move elements greater than key to one position ahead */
        while (j >= first && myCompare(array[j], key) > 0) {
            myCopy(&array[j], &array[j + 1]);
            j = j - 1;
        }

        /* Place key in its correct position in the sorted portion */
        myCopy(&key, &array[j + 1]);
    }
}

