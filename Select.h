/* ========================================================================= *
 * Select
 * ========================================================================= */

#ifndef _SELECT_H_
#define _SELECT_H_

#include <stddef.h>


/* ------------------------------------------------------------------------- *
 * Return the value of the k-th smallest value in an array of integers.
 * The function may permute the element in the array.
 *
 * PARAMETERS
 * array        The array to select from
 * length       Number of elements in the array
 * k            The rank of the element to select
 * 
 * RETURN
 * q            The k-th smallest element in the array
 * ------------------------------------------------------------------------- */
int select(int *restrict const array, const size_t length, const size_t k);


#endif // !_SELECT_H_
