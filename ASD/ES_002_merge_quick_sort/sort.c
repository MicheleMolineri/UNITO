#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void copy_array(void **dest, void **src, size_t l, size_t r)
{
    printf("Copy array\n");
    size_t k = 0;
    for (size_t i = l; i <= r; i++)
    {
        dest[k] = src[i];
        k++;
    }
}

void merge(void **base, size_t l, size_t m, size_t r, int (*compar)(const void *, const void *))
{
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    void **L = (void **)malloc(n1 * sizeof(void *));
    void **R = (void **)malloc(n2 * sizeof(void *));

    copy_array(L, base, l, m);
    copy_array(R, base, m + 1, r);

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (compar(&L[i], &R[j]) <= 0)
        {
            base[k] = L[i];
            i++;
        }
        else
        {
            base[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        base[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        base[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort_rec(void **base, size_t l, size_t r, int (*compar)(const void *, const void *))
{
    if (l < r)
    {
        size_t m = l + (r - l) / 2;
        merge_sort_rec(base, l, m, compar);
        merge_sort_rec(base, m + 1, r, compar);
        merge(base, l, m, r, compar);
    }
}

void merge_sort(void **base, size_t nitems, int (*compar)(const void *, const void *))
{
    printf("Merge sort\n");
    printf("N items: %ld\n", nitems);
    merge_sort_rec(base, 0, nitems - 1, compar);
}
