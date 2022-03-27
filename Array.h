/* ========================================================================= *
 * Array generator
 * ========================================================================= */

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stddef.h>


/* ------------------------------------------------------------------------- *
 * Create a sorted array of integers.
 *
 * The array must later be deleted by calling free().
 *
 * PARAMETERS
 * length       Number of elements in the array (pre-condition: 0 < length)
 *
 * RETURN
 * array        A new array of integers, or NULL in case of error
 * ------------------------------------------------------------------------- */
int* createSortedArray(size_t length);


/* ------------------------------------------------------------------------- *
 * Create a decreasing array of integers.
 *
 * The array must later be deleted by calling free().
 *
 * PARAMETERS
 * length       Number of elements in the array (pre-condition: 0 < length)
 *
 * RETURN
 * array        A new array of integers, or NULL in case of error
 * ------------------------------------------------------------------------- */
int* createDecreasingArray(size_t length);


/* ------------------------------------------------------------------------- *
 * Create a random array of integers (from 0 to length-1).
 *
 * The array must later be deleted by calling free().
 *
 * PARAMETERS
 * length       Number of elements in the array (pre-condition: 0 < length)
 *
 * RETURN
 * array        A new array of integers, or NULL in case of error
 * ------------------------------------------------------------------------- */
int* createRandomArray(size_t length);


#endif // !_ARRAY_H_
