# Selection-algorithms
Implementation of QuickSort, HeapSort, QuickSelect and MedianOfMedians to select the k-th greatest value in C.

---
Please note that I tried to optimize every thing I could do (in term of time and space).
- QuickSort (the whole array is sorted then we return the k-th greatest value) :
  - sort the shorter sub-array first (complexity space is then `Θ(log(N))`)
  - choose a random pivot (really low proability to have the worst complexity time `Θ(N²)`)
  - use a three-way partition (runs way faster than two-way partition for arrays with few different values)
---
- QuickSelect (same as QuickSort, except that we only sort 1 sub-array, therefore the whole array will **not** be fully sorted)
---
- HeapSort (the whole array is sorted then we return the k-th greatest value).
  Using the array as a complete binary tree. This algorithm will sort the array with the worst complexity time `Θ(log(N))`
---
- MedianOfMedians (the whole array will **not** be fully sorted) :
  Same as QuickSelect, except we compute a better pivot (the median of the medians). Only arrays with length equal (or smaller) to 5 allows to certify that the pivot will be between 30 and 70% of the array. Therefore the worst complexity time is `Θ(N)`.
  The implementation here does not use additional arrays to store medians. Each median of a sub-array will be placed at its beginning. To compute the median of the medians, we simply want a factor 5 (= length between 2 medians). Then to compute the median of the medians of the medians, we need to multiply the factor by 5, and so on.
---
You can use, change, publish or do whatever with the code. Any link to this GitHub page is welcome (but not mandatory), thanks !
