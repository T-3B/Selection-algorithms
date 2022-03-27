/* ========================================================================= *
 * selectByMedian
 * Implementation of the median of medians selection algorithm
 * By SMAGGHE Clément - https://github.com/T-3B/Selection-algorithms
 * ========================================================================= *
 * Algorithm explanation : divide the array in subArrays of size 5, compute
 * the medians for each subArray and place the medians at its beginning 
 * (= first iteration).
 * Then, multiply the factor by 5 (= the difference between 2 values used to
 * compute the next medians).
 * At the end, the medianOfMedians will be at index [0]. This will be our pivot
 * value, and finally use a threeWayPartition (as quickSort3 does).
 * Repeat the whole process untill k-th value is found.
 * ------------------------------------------------------------------------- */

#include <stddef.h>
#include "Select.h"

static void swap(int *restrict const a, int *restrict const b);
static void median(int *restrict const array, const unsigned char length, const size_t factor);
static void medianOfMedians(int *restrict const array, const size_t length, const size_t factor);
static void selectByMedian(int *restrict const array, const size_t length, const size_t k);


// `type` *restrict const "name" means : the pointer is const (not the data where it points to), and that its data can only be accessed by it (= restricted access).
// So restrict optimize the code by only loading *one* time the pointed int values (and not each time the pointers are used)
static void swap(int *restrict const a, int *restrict const b)
{
    const int c = *a;
    *a = *b;
    *b = c;
}


// compute the median of the array (of size <= 5) by using the insertion sort, and place the median at index [0]
static void median(int *restrict const array, const unsigned char length, const size_t factor)
{
    size_t i = length * factor;
    while ((i -= factor)) // if (i == 0) already sorted
    {
        size_t k = i;
        const int val = array[i];
        while ((k += factor) != length * factor && array[k] < val)
            array[k - factor] = array[k];
        
        array[k - factor] = val;
    }
    swap(array + (length / 2) * factor, array); //swap the median and the first element, no problem if they are the same
}


//the global median will be at index [0]
static void medianOfMedians(int *restrict const array, const size_t length, const size_t factor)
{
    const unsigned char lastSize = length % 5; // size of the last subArray; if == 0 then all subArrays will have size 5
    const size_t nbrMedians = length / 5 + (_Bool) lastSize; // numbers of subArrays (= nbr of medians to compute)
    
    size_t i = nbrMedians;
    if (lastSize)
        median(array + --i * 5, lastSize, factor); // compute the median of a subArray of custom size (< 5)
    
    while (i--)
        median(array + i * 5, 5, factor); // compute the median of a subArray of size 5
    
    if (nbrMedians > 5)
        medianOfMedians(array, nbrMedians, factor * 5);
    else
        median(array, nbrMedians, factor * 5);
}


static void selectByMedian(int *restrict const array, const size_t length, const size_t k)
{
    medianOfMedians(array, length, 1);
    const int pivotVal = array[0];
    size_t i = 1, pivotLow = 0, pivotHigh = length - 1;
    
    while (i <= pivotHigh)
    {
        if (array[i] > pivotVal)
            swap(array + i, array + pivotHigh--); // place the value at the end if greater than pivot
        else {
            if (array[i] < pivotVal)
                swap(array + i, array + pivotLow++); // place the value at the beginning if smaller than pivot
            i++;
        }
    }
    
    if (k < pivotLow)
        selectByMedian(array, pivotLow, k);
    else if (k > pivotHigh++ && length > pivotHigh)
        selectByMedian(array + pivotHigh, length - pivotHigh, k - pivotHigh);
    // if (pivotLow <= k && k >= pivotHigh) nothing is done, since we found the value we wanted. Recursion will end up normally.
}


// could not declare args as 'const' since they are not 'const' in the prototype (in 'Select.h')
int select(int *array, size_t length, size_t k)
{
    selectByMedian(array, length, k);
    return array[k];
}
