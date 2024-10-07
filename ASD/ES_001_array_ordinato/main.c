#include <stdlib.h>
#include <stdio.h>
#include "ordered_array.h"

/*
    Realizzare la struttura dati Array Ordinato che mantiene un array ordinato di elementi.
    Gli elementi di ogni array hanno tutti lo stesso tipo, ma la struttura dati deve essere generica (il tipo e il
    numero massimo di elementi non possono essere assunti come noti a priori).
    L’implementazione deve permettere di specificare il criterio secondo cui ordinare gli elementi.
    La struttura dati deve offrire metodi/funzioni per:
         Creare un array ordinato inizialmente vuoto
         Testare se l’array è vuoto
         Recuperare la dimensione dell’array
         Aggiungere un elemento all’array
         Recuperare l’elemento dell’array in posizione i
*/

struct _OrderedArray
{
  // con void* mi riferisco ad un array con dei valori di cui devo conoscere la dim dell'elemnto
  // con void** mi riferisco ad una struttura con puntatori non mi importa della size degli elementi che vado ad inserire
  void **array;
  unsigned long el_num; // i valori saranno da 0 in su
  unsigned long arr_capacity;
  // definisco un puntatore a funzione che mi dice se el1 < el2
  int (*precedes)(void *, void *);
};

OrderedArray *ordered_array_create(int (*precedes)(void *, void *))
{
  if (*precedes == NULL)
  {
    printf("Error : precedes function is NULL!!\n");
    exit(EXIT_FAILURE);
  }

  OrderedArray *ordered_array = (OrderedArray *)malloc(sizeof(OrderedArray));

  if (ordered_array == NULL)
  {
    printf("Error : array is NULL!!\n");
    exit(EXIT_FAILURE);
  }

  ordered_array->array = NULL;
  ordered_array->el_num = 0;
  // alloco capacity metto un valore casuale che verrà incrementato se necessario
  ordered_array->arr_capacity = 10;

  return ordered_array;
}

int ordered_array_is_empty(OrderedArray *ord_array)
{
  if (ord_array == NULL)
  {
    printf("Error : array is NULL!!\n");
    exit(EXIT_FAILURE);
  }

  return (ord_array->el_num == 0);
}
