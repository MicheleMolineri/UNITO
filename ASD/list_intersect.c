#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per la lista
struct listE1
{
    int info;
    struct listE1 *next;
};

typedef struct listE1 *list;
// Funzione di utilità per stampare una lista
void printList(list l)
{
    printf("\n");
    while (l != NULL)
    {
        printf("%d ", l->info);
        l = l->next;
    }
    printf("\n");
}
// Funzione per creare un nuovo elemento della lista
list Cons(int x, list xs)
{
    list newElement = (list)malloc(sizeof(struct listE1));
    newElement->info = x;
    newElement->next = xs;
    return newElement;
}
list reverse_rec(list l, list app)
{
    // caso base l = NULL
    if (l == NULL)
    {
        return app;
    }

    app = Cons(l->info, app);

    return reverse_rec(l->next, app);
}

list reverse(list l)
{
    return reverse_rec(l, NULL);
}

// Funzione per l'intersezione di due liste ordinate
list intersect(list l, list m)
{
    list res = NULL;

    while (l && m)
    {
        // caso m == l
        if (m->info == l->info)
        {
            printf("\nl == m , %d == %d", l->info, m->info);
            res = Cons(l->info, res);
            l = l->next;
            m = m->next;
        }
        else if (l->info < m->info)
        {
            // scorro l
            l = l->next;
        }
        else
        {
            // scorro m
            m = m->next;
        }
    }
    printList(res);
    return reverse(res);
}

list insert(list l, list x)
{
    if (l == NULL || l->info >= x->info)
    {
        x->next = l;
        return x;
    }
    l->next = insert(l->next, x);
    return l;
}

// funzione per ordinare una lista
list sort(list l)
{
    list sorted = NULL;
    while (l)
    {
        list temp = l;
        l = l->next;
        sorted = insert(sorted, temp);
    }
    return sorted;
}

// Funzione principale per testare l'implementazione
int main()
{
    // Creazione delle liste di esempio
    list l0 = Cons(2, Cons(3, Cons(8, NULL)));
    list m0 = Cons(0, Cons(2, Cons(4, Cons(5, Cons(7, Cons(8, NULL))))));

    printList(l0);
    printList(m0);
    // Calcolo dell'intersezione
    list intersection = intersect(l0, m0);

    // Stampa del risultato
    printList(intersection);

    return 0;
}