/* ========================================================================= *
 * QuickSelect
 * Implementation of the QuickSelect algorithm
 * By SMAGGHE Clément - https://github.com/T-3B/Selection-algorithms
 * ========================================================================= */

#include <stdlib.h> //for both rand() and size_t
#include "Select.h"

static void swap(int *restrict const a, int *restrict const b);
static void threeWayPartition(int *restrict const array, size_t *restrict const pivotLow, size_t *restrict const pivotHigh);
static void quickSort3Select(int *restrict const array, const size_t first, const size_t last, const size_t k);


// `type` *restrict const "name" means : the pointer is const (not the data where it points to), and that its data can only be accessed by it (= restricted access).
// So restrict optimize the code by only loading *one* time the pointed int values (and not each time the pointers are used)
static void swap(int *restrict const a, int *restrict const b)
{
    const int c = *a;
    *a = *b;
    *b = c;
}


static void threeWayPartition(int *restrict const array, size_t *restrict const pivotLow, size_t *restrict const pivotHigh)
{
    size_t i = *pivotLow;
    // take a random element from the array and put it at the beginning
    swap(array + i, array + i + rand() % (*pivotHigh - i + 1)); // no problem if the random element is already the first of the array (= same pointers given to swap())
    const int pivotVal = array[i++];
    while (i <= *pivotHigh)
    {
        if(array[i] > pivotVal)
            swap(array + i, array + (*pivotHigh)--); // place the value at the end if greater than pivot
        else {
            if(array[i] < pivotVal)
                swap(array + i, array + (*pivotLow)++); // place the value at the beginning if smaller than pivot
            i++;
        }
    } //values equal to pivotVal will be found between pivotLow & pivotHigh included
}


static void quickSort3Select(int *restrict const array, const size_t first, const size_t last, const size_t k)
{
    if (first >= last)
        return;
    
    size_t pivotLow = first, pivotHigh = last; // pivots indexes, "splitting" the array in 3 ('<','=','>') using threeWayPartition()
    threeWayPartition(array, &pivotLow, &pivotHigh);
    
    if (k < pivotLow)
        quickSort3Select(array, first, pivotLow - 1, k);
    else if (k > pivotHigh)
        quickSort3Select(array, pivotHigh + 1, last, k);
    // if (pivotLow <= k && k >= pivotHigh) nothing is done, since we found the value we wanted. Recursion will end up normally.
}


int select(int *restrict const array, const size_t length, const size_t k)
{
    quickSort3Select(array, 0, length - 1, k);
    return array[k];
}
