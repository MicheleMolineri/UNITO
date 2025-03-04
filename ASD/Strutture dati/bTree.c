/************************************
*  Struttura per gli alberi binari
*  (senza puntatore al padre)
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define SEPARATOR "#<ab@17943918#@>#"

struct BtreeNd {
    int             key;
    struct BtreeNd* left;
    struct BtreeNd* right;
};

typedef struct BtreeNd* btree;

btree ConsTree(int k, btree l, btree r) {
    btree rootnode = malloc(sizeof(struct BtreeNd));
    rootnode->key = k;
    rootnode->left = l;
    rootnode->right = r;
    return rootnode;
}

// post: stampa indentata dell'albero bt in preordine sinistro, con margine
//       iniziale di n tab, senza visualizzare i puntatori a nil
void printtree(btree bt, int n) {
    if (bt != NULL) {
        for (int i = 0; i < n; i++) 
            printf("   ");
        printf("%d\n", bt->key);
        printtree(bt->left, n + 1);
        printtree(bt->right, n + 1);
    }
}

// post: stampa indentata dell'albero bt in preordine sinistro, con margine
//       iniziale di n tab, visualizzando i puntatori a nil
void printtree2(btree bt, int n) {
    for (int i = 0; i < n; i++) 
            printf("   ");
    if (bt == NULL) 
        printf("nil\n");
    else {
        printf("%d\n", bt->key);
        printtree2(bt->left, n + 1);
        printtree2(bt->right, n + 1);
    }
}

int main()
{

    btree bt =
        ConsTree(20,
            ConsTree(35,
                ConsTree(9, NULL, NULL),
                ConsTree(1, NULL, NULL)
            ),
            ConsTree(5, NULL, ConsTree(3, NULL, NULL))
        );

    printf("Albero dato (senza nil):\n");
    printtree(bt, 0);
    printf("Albero dato (incluso nil):\n");
    printtree2(bt, 0);

    return 0;
}