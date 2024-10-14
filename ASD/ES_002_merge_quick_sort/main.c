#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int compare_int(const void *a, const void *b)
{
    int va = **(int **)a;
    int vb = **(int **)b;
    return (va - vb);
}

void stampa_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    int array[] = {5, 1, 13, 9};
    int n = 4;
    void *ptrs[n];

    for (int i = 0; i < n; i++)
    {
        ptrs[i] = &array[i];
    }

    printf("Array iniziale: ");
    stampa_array(array, n);

    merge_sort(ptrs, n, compare_int);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(int *)ptrs[i]);
    }
    printf("\n");

    return 0;
}