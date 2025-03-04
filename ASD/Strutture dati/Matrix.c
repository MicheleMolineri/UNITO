/******************************
 * Matrici di interi
*******************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define SEPARATOR "#<ab@17943918#@>#"

// frame d'ingresso di una matrice row x col con entrate
// in un array di row puntatori ad array di col interi
struct MatrixFrame {
    int row, col;
    int** array;
};

// Matrix è il tipo dei puntatori a frame d'ingresso MatrixFrame
typedef struct MatrixFrame* Matrix;

// pre: m,n >= 0
// post: alloca e ritorna una matrice di interi A di dim. m x n inizializzata con tutti 0
Matrix newMatrix(int m, int n) {
    Matrix A = (Matrix) malloc(sizeof(struct MatrixFrame));
    A->row = m;
    A->col = n;
    A->array = (int**) malloc(A->row * sizeof(int*));
    for(int i = 0; i < A->row; i++) {
       A->array[i] = (int*) malloc(A->col * sizeof(int));
       for(int j = 0; j < A->col; j++)
            A->array[i][j] = 0;
    }
    return A;
}

void printMatrix(Matrix A) {
    for(int i = 0; i < A->row; i++) {
        for(int j = 0; j < A->col; j++) 
            printf("%d\t", A->array[i][j]);
        printf("\n");
    }
}

int main() {
    Matrix A = newMatrix(7, 6);
    printMatrix(A);
    return 0;
}