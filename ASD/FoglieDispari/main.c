#include <stdio.h>
#include <stdbool.h>
#include "kTree.c"

bool isDispari(int n)
{
    return (n % 2 == 0 ? false : true);
}

bool FatherChildOdd(kTree t)
{
    // controllo se in nodo è pari o dispari
    bool tutti_dispari = isDispari(t->key);
    printf("nodo : %d\n", t->key);
    printf("Dispari : %d\n", tutti_dispari);

    // se ha figli li controllo andando sul figlio e scorrendo i fratelli
    kTree c = t->child;
    while (c != NULL && tutti_dispari)
    {
        // controllo che l'etichetta del figlio sia dispari
        printf("nodo figlio : %d\n", c->key);
        tutti_dispari &= isDispari(c->key);
        printf("Dispari Figlio : %d\n", tutti_dispari);
        // se il figlio x non ha figli pari allora controllo il fratello
        if (tutti_dispari)
        {
            printf("controllo fratm\n");
            tutti_dispari &= FatherChildOdd(c);
            c = c->sibling;
        }
    }

    return tutti_dispari;
}

int main()
{
    // test 1
    kTree t = root(1, consTree(3, consTree(5, leaf(7, NULL), leaf(9, NULL)), leaf(11, NULL)));
    /* t in forma indentata:
          1
        3   11
       5 9
      7

    */
    printf("Albero dato:\n");
    printTree(t, 0);
    bool dispari = FatherChildOdd(t);
    printf("\nTutti dispari: %d \n", dispari);
}
