/************************************
 * Struttura dati degli alberi k-ari
 ************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define SEPARATOR "#<ab@17943918#@>#"

struct kTreeVertex
{
    int key;
    struct kTreeVertex *child;
    struct kTreeVertex *sibling;
};

typedef struct kTreeVertex *kTree;

kTree consTree(int k, kTree c, kTree s)
{
    kTree t = malloc(sizeof(struct kTreeVertex));
    t->key = k;
    t->child = c;
    t->sibling = s;
    return t;
}

kTree leaf(int k, kTree s)
{
    return consTree(k, NULL, s);
}

kTree root(int k, kTree c)
{
    return consTree(k, c, NULL);
}

// post: stampa indentata dell'albero t con margine
//       iniziale di n tab
void printTree(kTree t, int d)
{
    if (t != NULL)
        for (int i = 0; i < d; ++i)
            printf("   ");
    printf("%d\n", t->key);
    kTree cl = t->child;
    while (cl != NULL)
    {
        printTree(cl, d + 1);
        cl = cl->sibling;
    }
}
