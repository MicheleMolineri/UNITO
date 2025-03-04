#include <stdio.h>

#define MAX_SIZE 100

// Funzione per calcolare l'indice del figlio sinistro
int left(int i)
{
    return 2 * i + 1;
}

// Funzione per calcolare l'indice del figlio destro
int right(int i)
{
    return 2 * i + 2;
}

// Funzione per calcolare l'indice del genitore
int parent(int i)
{
    return (i - 1) / 2;
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
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= hd && H[l] > H[largest])
    {
        largest = l;
    }
    if (r <= hd && H[r] > H[largest])
    {
        largest = r;
    }

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

// Funzione per inserire un elemento nello heap
int insert(int H[], int *hd, int value)
{
    if (*hd >= MAX_SIZE - 1)
    {
        printf("Errore: Heap pieno\n");
        return -1;
    }

    // aumento la sua grandezza
    (*hd)++;
    // inserisco il nuovo valore nell'ultimo nodo dell'heap
    H[*hd] = value;
    int i = *hd;

    // Ripristinare la proprietà di heap massimo
    // scorro i parent del nodo in cui mi trovo e
    // MAX heap se parent è minore allora swap
    // MIN heap se parent è maggiore allora swap
    while (i > 0 && H[parent(i)] < H[i])
    {
        // scambio il parent con il current node
        swap(H, i, parent(i));
        // aggiorno lindice al nuovo nodo in cui si trova l'elemento
        i = parent(i);
    }
    return 0;
}

// Funzione per cercare un elemento nello heap
int search(int H[], int hd, int value)
{
    for (int i = 0; i <= hd; i++)
    {
        if (H[i] == value)
        {
            return i;
        }
    }
    return -1; // Non trovato
}

// Funzione per eliminare un elemento dallo heap
int delete(int H[], int *hd, int value)
{
    // per eliminare un elemento pecifico prima controllo che sia presente
    // e successivamente lo rimuovo

    int index = search(H, *hd, value);
    if (index == -1)
    {
        printf("Errore: Elemento non trovato\n");
        return -1;
    }

    // Sostituire l'elemento da eliminare con l'ultimo elemento
    H[index] = H[*hd];
    (*hd)--;

    // Ripristinare la proprietà di heap massimo
    maxHeapify(H, index, *hd);
    return 0;
}
// funzione per eliminare il massimo elemento
int remove(int H[], int *hd)
{
    if (*hd < 0)
    {
        // Caso con heap piena
        return -1;
    }

    // Salvo il massimo elemento
    int maxElement = H[0];

    // Scambio l'ultimo elemento con il primo
    swap(H, 0, *hd);

    // Abbasso il valore hd
    (*hd)--;

    // Ripristino il max heap
    maxHeapify(H, 0, *hd);

    // Ritorno il massimo elemento rimosso
    return maxElement;
}
// Funzione main per testare il programma
int main()
{
    int H[MAX_SIZE];
    int hd = -1; // Indice dell'ultima posizione nell'heap

    // Inserimento di elementi nello heap
    insert(H, &hd, 10);
    insert(H, &hd, 20);
    insert(H, &hd, 15);
    insert(H, &hd, 30);
    insert(H, &hd, 40);

    printf("Heap dopo inserimenti: ");
    for (int i = 0; i <= hd; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    // Eliminazione di un elemento
    delete (H, &hd, 20);
    printf("Heap dopo eliminazione di 20: ");
    for (int i = 0; i <= hd; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    // Ricerca di un elemento
    int value = 15;
    int index = search(H, hd, value);
    if (index != -1)
    {
        printf("Elemento %d trovato all'indice %d\n", value, index);
    }
    else
    {
        printf("Elemento %d non trovato\n", value);
    }

    return 0;
}