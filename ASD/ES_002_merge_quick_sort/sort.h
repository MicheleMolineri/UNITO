#include <stdlib.h>

void merge_sort(void **base, size_t nitems, int (*compar)(const void *, const void *));

void quick_sort(void **base, size_t nitems, int (*compar)(const void *, const void *));
