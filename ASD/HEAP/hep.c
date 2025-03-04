#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per l'heap
struct heapFrame
{
    int dim;   // Dimensione fisica dell'array
    int hd;    // Dimensione logica dell'heap (numero di elementi effettivi)
    int *keys; // Array delle chiavi
};

typedef struct heapFrame *Heap;

// Funzione per calcolare l'indice del figlio sinistro
int left(Heap H, int i)
{
    int l = 2 * i + 1;
    return (l < H->hd) ? l : -1;
}

// Funzione per calcolare l'indice del figlio destro
int right(Heap H, int i)
{
    int r = 2 * i + 2;
    return (r < H->hd) ? r : -1;
}

// Funzione per calcolare l'indice del genitore
int parent(Heap H, int i)
{
    return (i > 0) ? (i - 1) / 2 : -1;
}

// Funzione per scambiare due elementi
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funzione per ripristinare la proprietà di heap minimo
void heapify(Heap H, int i)
{
    int smallest = i;
    int l = left(H, i);
    int r = right(H, i);

    // Trova il più piccolo tra il nodo corrente, il figlio sinistro e il figlio destro
    if (l != -1 && H->keys[l] < H->keys[smallest])
        smallest = l;
    if (r != -1 && H->keys[r] < H->keys[smallest])
        smallest = r;

    // Se il più piccolo non è il nodo corrente, scambia e ripristina ricorsivamente
    if (smallest != i)
    {
        swap(&H->keys[i], &H->keys[smallest]);
        heapify(H, smallest);
    }
}

// Funzione per costruire un heap minimo
void buildMinHeap(Heap H)
{
    // Parti dall'ultimo nodo non foglia e heapify tutti i nodi
    for (int i = H->hd / 2 - 1; i >= 0; i--)
        heapify(H, i);
}

// Funzione per copiare un array in un heap
void copyArray(int *src, int *dest, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

// Funzione per visualizzare l'heap
void showHeap(Heap H)
{
    printf("Contenuto dello heap: ");
    for (int i = 0; i < H->hd; i++)
        printf("%d ", H->keys[i]);
    printf("\n");
}

// Funzione per diminuire il valore di una chiave
void DecreaseKey(Heap H, int i, int newKey)
{
    // aggiorno la chiave di indice i con valore "newKey"
    H->keys[i] = newKey;

    while (i > 0 && H->keys[i] < H->keys[parent(H, i)])
    {
        // scambio i valori
        int tmp = H->keys[i];
        H->keys[i] = H->keys[parent(H, i)];
        H->keys[parent(H, i)] = tmp;
        // aggiorno l' indice corretto (perché è salito di grados)
        i = parent(H, i);
    }
}

// Funzione principale per testare l'implementazione
int main()
{
    // Dati di esempio
    int A[] = {9, 27, 12, 6, 11, 8, 7, 19, 5};
    int dimA = sizeof(A) / sizeof(int);

    // Creazione e inizializzazione dell'heap
    Heap H1 = (Heap)malloc(sizeof(struct heapFrame));
    H1->dim = dimA;
    H1->hd = dimA;
    H1->keys = (int *)malloc(dimA * sizeof(int));
    copyArray(A, H1->keys, dimA);

    // Mostra l'heap iniziale
    printf("Heap iniziale:\n");
    showHeap(H1);

    // Costruisci l'heap minimo
    buildMinHeap(H1);

    // Mostra l'heap dopo la costruzione
    printf("Heap minimo costruito:\n");
    showHeap(H1);

    // Diminuisci la chiave all'indice 7 da 19 a 1
    DecreaseKey(H1, 7, 1);

    // Mostra l'heap dopo la modifica
    printf("Risultato ottenuto dopo il decremento della chiave 19 a 1:\n");
    showHeap(H1);

    // Libera la memoria
    free(H1->keys);
    free(H1);

    return 0;
}