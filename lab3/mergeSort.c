

#include "mySort.h"

/* Function to merge two subarrays of data[] */
static void merge(int data[], unsigned int left, unsigned int mid, unsigned int right) {
    unsigned int i, j, k;
    unsigned int n1 = mid - left + 1;
    unsigned int n2 = right - mid;

    /* Create temporary arrays */
    int L[n1], R[n2];

    /* Copy data to temporary arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        myCopy(&data[left + i], &L[i]);
    for (j = 0; j < n2; j++)
        myCopy(&data[mid + 1 + j], &R[j]);

    /* Merge the temporary arrays back into data[left..right] */
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (myCompare(L[i], R[j]) <= 0) {
            myCopy(&L[i], &data[k]);
            i++;
        } else {
            myCopy(&R[j], &data[k]);
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) {
        myCopy(&L[i], &data[k]);
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) {
        myCopy(&R[j], &data[k]);
        j++;
        k++;
    }
}

/* Recursive function to sort an array using merge sort */
void mySort(int data[], unsigned int left, unsigned int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        unsigned int mid = left + (right - left) / 2;

        // Sort first and second halves
        mySort(data, left, mid);
        mySort(data, mid + 1, right);

        // Merge the sorted halves
        merge(data, left, mid, right);
    }
}

