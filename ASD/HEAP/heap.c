#include <stdio.h>

// Funzione per calcolare l'indice del figlio sinistro
int left(int i, int hd)
{
    return (2 * i + 1 <= hd) ? 2 * i + 1 : i;
}

// Funzione per calcolare l'indice del figlio destro
int right(int i, int hd)
{
    return (2 * i + 2 <= hd) ? 2 * i + 2 : i;
}

// Funzione per scambiare due elementi di un array
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Funzione per mantenere la proprietà di heap massimo
void maxHeapify(int H[], int i, int hd)
{
    // ottengo gli indici del nodi a destra e sinistra
    int l = left(i, hd);
    int r = right(i, hd);
    int largest = i;

    // controllo la validita di left e se è maggiore del current
    if (l <= hd && H[l] > H[largest])
    {
        largest = l;
    }
    // controllo se il right è maggiore del left/current
    if (r <= hd && H[r] > H[largest])
    {
        largest = r;
    }

    // se ho trovato un valore maggiore allora faccio lo swap e ripristino maxheap
    // altrimenti ho finito
    if (largest != i)
    {
        swap(H, i, largest);
        maxHeapify(H, largest, hd);
    }
}

// Funzione per costruire uno heap massimo
void buildMaxHeap(int A[], int hd)
{
    for (int i = hd / 2; i >= 0; i--)
    {
        maxHeapify(A, i, hd);
    }
}

// Funzione per ordinare un array in modo non decrescente usando HeapSort
void heapSort(int A[], int dim)
{
    int hd = dim - 1;

    // Costruire uno heap massimo
    buildMaxHeap(A, hd);

    // Estrarre elementi dallo heap uno alla volta
    for (int i = hd; i > 0; i--)
    {
        // Spostare il massimo alla fine dell'array
        swap(A, 0, i);
        hd--;                 // Ridurre la dimensione dello heap
        maxHeapify(A, 0, hd); // Ricostruire lo heap massimo
    }
}

// Funzione main per testare il programma
int main()
{
    // Array di esempio da ordinare
    int A[] = {4, 10, 3, 5, 1, 7, 8, 2, 9, 6};
    int dim = sizeof(A) / sizeof(A[0]);

    printf("Array originale: ");
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Ordinare l'array
    heapSort(A, dim);

    printf("Array ordinato: ");
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}