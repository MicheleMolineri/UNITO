#include <stdio.h>

// post: ritorna la lista delle etichette (chiavi) di t visitato in ampiezza
list kTreeBFS(kTree t)
{
    // caso t vuoto
    if (t == NULL)
    {
        return NULL;
    }

    // creo una lista l e una coda q
    queue q = CreateQueue();
    list l = NULL;

    // aggiungo il primo elemento nella q e l
    enQueue(t->info, q);
    Cons(t->info, l);

    // fino a quando la queue è vuota scorro i figli
    while (!isEmptyQueue(q))
    {
        // tolgo
        DeQueue(t->info);
        kTree child = t->child;
        while (child)
        {
            // aggiungo il figlio alla coda
            EnQueue(child, q);
            // aggiungo child a l
            l->next = child->info;
            // scorro al prossimo child
            child = child->sibling;
        }
    }

    return l;
}