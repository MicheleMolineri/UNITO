#include <stdio.h>

// Funzione che verrà implementata
int find(int A[], int N, int f);

// Funzione di supporto per stampare un array
void printArray(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Funzione di test per verificare se l'array è partizionato correttamente
void printMedianTest(int A[], int N, int f)
{
    printf("Array dato: ");
    printArray(A, N);

    int median = find(A, N, f);
    printArray(A, N);

    printf("Minimo = %d, massimo = %d, mediana = %d\n", A[0], A[N - 1], median);

    // Verifica la correttezza della partizione
    int isCorrect = 1;
    for (int i = 0; i < f; i++)
    {
        if (A[i] > median)
        {
            isCorrect = 0;
            break;
        }
    }
    for (int i = f + 1; i < N; i++)
    {
        if (A[i] < median)
        {
            isCorrect = 0;
            break;
        }
    }

    printf("Array partizionato correttamente rispetto alla mediana?: %s\n",
           isCorrect ? "SI" : "NO");
}

int main()
{
    int A[] = {14, 20, -4, 4, 17, 0, 6};
    int N = sizeof(A) / sizeof(A[0]);
    int f = (N - 1) / 2; // Indice della mediana

    printMedianTest(A, N, f);

    return 0;
}

// Funzione swap (utilizzata per scambiare elementi)
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(int A[], int low, int high)
{
    // ottngo il valore ad high --> pivot
    int pivot = A[high];
    int i = low - 1;

    // scorro gli elementi e se A[j] <= pivot incremento i e chiamo la swap su i e j
    for (int j = 0; j < high; j++)
    {
        if (A[j] <= pivot)
        {
            printf("A[j] : %d , pivot : %d\n", A[j], pivot);
            i++;
            swap(A, i, j);
            printArray(A, high);
        }
    }
    // scambio l'ultimo valore modificato con il pivot
    i++;
    swap(A, i, high);
    return i;
}

int find(int A[], int N, int f)
{
    int low = 0, high = N - 1;

    while (low <= high)
    {
        // Partiziona l'array
        int pivotIndex = partition(A, low, high);

        // Confronta il pivotIndex con f
        if (pivotIndex == f)
        {
            return A[pivotIndex];
        }
        else if (pivotIndex > f)
        {
            high = pivotIndex - 1; // Cerca a sinistra
        }
        else
        {
            low = pivotIndex + 1; // Cerca a destra
        }
    }

    return -1; // Non dovrebbe mai accadere se f è valido
}