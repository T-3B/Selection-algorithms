/* ========================================================================= *
 * Array generator
 * Implementation of the Array generator interface
 * ========================================================================= */

#include <stdlib.h>
#include <stddef.h>
#include "Array.h"

static const int MAX_START = 1001;
static const int UPPER_BOUND = 1001;

int* createSortedArray(size_t length)
{
    int* array = (int*) malloc(length * sizeof(int));
    if (!array)
        return NULL;

    int shift = rand() % MAX_START;
    for (size_t i = 0; i < length; i++)
    {
        array[i] = shift + i;
    }

    return array;
}

int* createDecreasingArray(size_t length)
{
    int* array = createSortedArray(length);
    if (!array)
        return NULL;

    int tmp;
    size_t i = 0, j = length-1;
    while (i < j)
    {
        // Swap array[i] and array[j]
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;

        i++;
        j--;
    }
    return array;
}

int* createRandomArray(size_t length)
{
    int* array = (int*) malloc(length * sizeof(int));
    if (!array)
        return NULL;

    for (size_t i = 0; i < length; i++)
        array[i] = rand() % UPPER_BOUND;

    return array;
}

