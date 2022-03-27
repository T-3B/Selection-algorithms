/* ========================================================================= *
 * SelectByHeapsort
 * Implementation of the selection algorithm using heapsort
 * By SMAGGHE Clément - https://github.com/T-3B/Selection-algorithms
 * ========================================================================= */

#include <stddef.h>
#include "Select.h"

static void swap(int *restrict const a, int *restrict const b);
static void heapify(int *restrict const array, const size_t root, const size_t end);
static void heapSort(int *restrict const array, const size_t length);


// `type` *restrict const "name" means : the pointer is const (not the data where it points to), and that its data can only be accessed by it (= restricted access).
// So restrict optimize the code by only loading *one* time the pointed int values (and not each time the pointers are used)
static void swap(int *restrict const a, int *restrict const b)
{
    const int c = *a;
    *a = *b;
    *b = c;
}

// will sort the tree recursively, starting with the root (= first index)
static void heapify(int *restrict const array, const size_t root, const size_t end)
{
    size_t largest = root; // for example array[0] has childs at [1] and [2]
    const size_t left = 2 * root + 1; // left child
    const size_t right = left + 1; // right child = 2 * root + 2
    
    // find the child with the greatest value
    if (left < end && array[left] > array[largest])
        largest = left;
    
    if (right < end && array[right] > array[largest])
        largest = right;
    
    
    if (largest != root) {
        swap(array + root, array + largest);
        
        // heapify the sub-tree
        heapify(array, largest, end);
    }
}


static void heapSort(int *restrict const array, const size_t length)
{
    // build heap (rearrange array)
    size_t i = length / 2;
    while (i--)
        heapify(array, i, length);
 
    
    i = length;
    while (--i) { // if i == 0 : already sorted
        // swap root (greatest value) to the end
        swap(array, array + i);
        
        heapify(array, 0, i);
    }
}


// could not declare args as 'const' since they are not 'const' in the prototype (in 'Select.h')
int select(int *array, size_t length, size_t k)
{
    heapSort(array, length);
    return array[k];
}
