/* ========================================================================= *
 * SelectByHeapsort
 * Implementation of the medianOfMedians algorithm.
 * The idea behind the code is to compute the median on sub-array of length 5,
 * then put them at the beginning of the array and reitering.
 * Therefore the algorithm does not use additional array
 *   (the only mem used is for function calls stack).
 * By SMAGGHE Clément - https://github.com/T-3B/Selection-algorithms
 * ========================================================================= */

#include <stddef.h>
#include "Select.h"

static void swap(int *restrict const a, int *restrict const b);
static void median(int *restrict const array, const unsigned char length, int *restrict const dest);
static int medianpivot(int *restrict const array, const size_t length);


static void swap(int *restrict const a, int *restrict const b) {
    const int c = *a;
    *a = *b;
    *b = c;
}

// compute the median of the array (of size <= 5) by using the insertion sort, and swap the median with dest
static void median(int *restrict const array, const unsigned char length, int *restrict const dest) {
    size_t i = length;
    while (--i) { // if (i == 0) already sorted
        size_t k = i;
        const int val = array[i];
        while (++k != length && array[k] < val)
            array[k - 1] = array[k];
        
        array[k - 1] = val;
    }
    swap(array + length / 2, dest);
}

static int medianpivot(int *restrict const array, const size_t length) {
    size_t m = (length + 4) / 5;
    
    for (size_t i = 0; i < length / 5; i++)
        median(array + 5 * i, 5, array + i);
    
    if (length % 5)
        median(array + 5 * (m - 1), length % 5, array + m - 1);

    return select(array, m, m/2);
}

int select(int *restrict const array, const size_t length, const size_t k) {
	if (length == 1 && !k)
        return array[0];
    
    const int pivotVal = medianpivot(array, length);

    size_t i = 0, pivotLow = 0, pivotHigh = length - 1;
    
    while (i <= pivotHigh) {
        if (array[i] > pivotVal)
            swap(array + i, array + pivotHigh--); // place the value at the end if greater than pivot
        else {
            if (array[i] < pivotVal)
                swap(array + i, array + pivotLow++); // place the value at the beginning if smaller than pivot
            i++;
        }
    }
    
    if (k < pivotLow)
        return select(array, pivotLow, k);
    else if (k > pivotHigh++ && length > pivotHigh)
        return select(array + pivotHigh, length - pivotHigh, k - pivotHigh);
    else
        return pivotVal;
}
