#include <stdio.h>

// Definizione del tipo enumerato
enum color {rosso, bianco, verde};
typedef enum color Color;

void swap(Color A[], int i, int j) {
    Color temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
// Funzione per stampare l'array
void printBandiera(Color B[], int n) {
    for(int i = 0; i < n; i++) {
        switch(B[i]) {
            case rosso:
                printf("rosso ");
                break;
            case bianco:
                printf("bianco ");
                break;
            case verde:
                printf("verde ");
                break;
        }
    }
    printf("\n");
}

// Funzione da completare
void Bandiera(Color B[], int n) {
    // TODO: Implementare la funzione secondo le specifiche
    // creo tre indici i(V), j(B) e k(R)
    int i = 0, j = 0, k = n-1;

    while (j <= k) {
        switch(B[j]) {
            case verde:
                swap(B, i, j);
                i++;
                j++;
                break;
            case bianco:
                j++;
                break;
            case rosso:
                swap(B, j, k);
                k--;
                break;
        }
    }

}

int main() {
    Color B[] = {rosso, verde, rosso, bianco, verde, bianco};
    int n = sizeof(B)/sizeof(Color);
    
    printf("Array iniziale: \n");
    printBandiera(B, n);
    
    Bandiera(B, n);
    
    printf("Array finale: \n");
    printBandiera(B, n);
    
    return 0;
}