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

typedef int Type;

// coda di el. di tipo T, ossia di puntatori a kTreeVertex

struct queueEl
{
    Type info;
    struct queueEl *next;
};

struct queueFrame
{
    struct queueEl *front; // primo el. della coda
    struct queueEl *rear;  // ultimo el. della coda
};

typedef struct queueFrame *queue;

// post: alloca e ritorna una coda vuota
queue NewQueue()
{
    queue q = malloc(sizeof(struct queueFrame));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// post: ritorna true se la coda è vuota, false altrimenti
bool isEmptyQueue(queue q)
{
    return q->front == NULL;
}

// post: accoda t come ultimo elemento di q
void EnQueue(Type t, queue q)
{
    struct queueEl *newEl = malloc(sizeof(struct queueEl));
    newEl->info = t;
    newEl->next = NULL;
    if (q->front == NULL)
        q->front = q->rear = newEl;
    else // q->front != NULL implica q->rear != NULL
    {
        q->rear->next = newEl;
        q->rear = newEl;
    }
}

// pre:  q non è vuota
// post: ritorna il primo el. di q SENZA rimuoverlo da q
Type First(queue q)
{
    return q->front->info;
}

// pre:  q non è vuota
// post: ritorna il primo el. di q RIMUOVENDOLO da q
Type DeQueue(queue q)
{
    Type t = q->front->info;
    struct queueEl *oldFirst = q->front;
    if (q->front == q->rear) // la coda ha un solo el.
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    free(oldFirst);
    return t;
}

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

int max(int n1, int n2)
{
    return (n1 >= n2 ? n1 : n2);
}

// funzine per controllare la profondità dell'albero
int depthKTree(kTree t)
{
    int dpt = 0;
    // se non esiste t
    if (t == NULL)
        return -1;

    // ottengo suo figlio e scorro i fratelli
    kTree child = t->child;
    while (child)
    {
        // ottengo il valore della depth del figlio e prendo il maggiore
        dpt = max(dpt, depthKTree(child));
        child = child->sibling;
    }

    return dpt + 1;
}

// funzione che conta la somma delle foglie
int countSumLeafs(kTree t)
{
    // caso t NULL
    if (t == NULL)
    {
        return -1;
    }

    int sum = 0;
    kTree child = t->child;
    if (!child)
        return t->key;

    while (child)
    {
        sum += countSumLeafs(child);
        child = child->sibling;
    }

    return sum;
}

// funzione che conta le non foglie
int countNonLeafs(kTree t)
{
    // caso t NULL
    if (t == NULL)
        return -1;

    if (t->child == NULL)
        return 0;
    // scorrere figli/fratelli
    kTree child = t->child;
    int nonLeafs = 0;
    while (child != NULL)
    {
        // ottengo il numero di foglie di child
        nonLeafs += countNonLeafs(child);
        child = child->sibling;
    }

    return nonLeafs + 1;
}

// funzione che conta le foglie
int countLeafs(kTree t)
{
    // caso t NULL
    if (t == NULL)
        return -1;

    if (t->child == NULL)
        return 1;
    // scorrere figli/fratelli
    kTree child = t->child;
    int leafs = 0;
    while (child != NULL)
    {
        // ottengo il numero di foglie di child
        leafs += countLeafs(child);
        child = child->sibling;
    }

    return leafs;
}

// funzione che conta i

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

int main()
{
    // Creazione radice
    kTree root = consTree(1, NULL, NULL);

    // Primo livello di figli (3 nodi)
    kTree child1 = consTree(2, NULL, NULL);
    kTree child2 = consTree(3, NULL, NULL);
    kTree child3 = consTree(4, NULL, NULL);
    child1->sibling = child2;
    child2->sibling = child3;
    root->child = child1;

    // Figli di child1 (2 foglie)
    kTree child11 = consTree(5, NULL, NULL);
    kTree child12 = consTree(6, NULL, NULL);
    child11->sibling = child12;
    child1->child = child11;

    // Figli di child2 (2 foglie)
    kTree child21 = consTree(7, NULL, NULL);
    kTree child22 = consTree(8, NULL, NULL);
    child21->sibling = child22;
    child2->child = child21;

    // Figli di child3 (3 foglie)
    kTree child31 = consTree(9, NULL, NULL);
    kTree child32 = consTree(10, NULL, NULL);
    kTree child33 = consTree(11, NULL, NULL);
    child31->sibling = child32;
    child32->sibling = child33;
    child3->child = child31;

    // Calcolo e stampa profondità
    int dpt = depthKTree(root);
    printf("Profondità dell'albero: %d\n", dpt);

    // Stampa dell'albero
    printTree(root, 0);

    // Calcolo e stampa foglie
    int sumLeaf = countSumLeafs(root);
    printf("Somma foglie dell'albero: %d\n", sumLeaf);

    // conto le foglie
    int nleafs = countLeafs(root);
    printf("N foglie dell'albero: %d\n", nleafs);

    return 0;
}
