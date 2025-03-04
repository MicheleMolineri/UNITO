#include <stdio.h>

// Funzione di swap preimplementata
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Funzione per stampare l'array
void printarray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Funzione da completare
int countBubbleSort(int A[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (A[i] > A[j])
            {
                swap(A, i, j);
                        }
            count++;
        }
    }
    return count;
}

int main()
{
    int A[] = {4, 1, 6, 7, 9, 3, 2, 8, 10, 6};
    int n = sizeof(A) / sizeof(int);

    printf("Array dato: \n");
    printarray(A, n);

    int ntest = countBubbleSort(A, n);

    printf("Array ordinato: \n");
    printarray(A, n);

    printf("Numero dei test = %d\n", ntest);

    return 0;
}