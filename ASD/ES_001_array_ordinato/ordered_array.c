#include <stdlib.h>
#include <stdio.h>
#include "ordered_array.h"
#define INITIAL_CAPACITY 2

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
static unsigned long get_index_to_insert(OrderedArray *ordered_array, void *element);
static void insert_element(OrderedArray *ordered_array, void *element, unsigned long index);

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

  ordered_array->array = (void **)malloc(INITIAL_CAPACITY * sizeof(void *));
  if (ordered_array->array == NULL)
  {
    fprintf(stderr, "ordered_array_create: unable to allocate memory for the internal array");
    exit(EXIT_FAILURE);
  }
  ordered_array->el_num = 0;
  ordered_array->arr_capacity = INITIAL_CAPACITY;
  ordered_array->precedes = precedes;

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

unsigned long ordered_array_size(OrderedArray *ord_array)
{
  if (ord_array == NULL)
  {
    printf("Error : array is NULL!!\n");
    exit(EXIT_FAILURE);
  }

  return ord_array->el_num;
}

void ordered_array_add(OrderedArray *ord_array, void *el)
{
  if (ord_array == NULL)
  {
    printf("Error : array is NULL!!\n");
    exit(EXIT_FAILURE);
  }

  // controllo se l'array è pieno e se è pieno rialloco la memoria x array e inserisco il valore in maniera ordinata
  if (ord_array->el_num >= ord_array->arr_capacity)
  {
    ord_array->array = (void **)realloc(ord_array->array, 2 * (ord_array->arr_capacity * sizeof(void *)));
    if (ord_array->array == NULL)
    {
      printf("Error : array is NULL!!\n");
      exit(EXIT_FAILURE);
    }
    ord_array->arr_capacity *= 2;
  }

  unsigned long index = get_index_to_insert(ord_array, el);

  insert_element(ord_array, el, index);

  (ord_array->el_num)++;
}

void *ordered_array_get(OrderedArray *ord_array, int i)
{
  // controllo se esiste array e se i è compreso tra 0 e ord_arr->el_num
  if (ord_array == NULL)
  {
    printf("Error : array is NULL!!\n");
    exit(EXIT_FAILURE);
  }
  if (i < 0 || i >= (ord_array->el_num - 1))
  {
    printf("Error : Invalid INDEX!!\n");
    exit(EXIT_FAILURE);
  }

  return ord_array->array[i];
}

void ordered_array_free_memory(OrderedArray *ordered_array)
{
  if (ordered_array == NULL)
  {
    fprintf(stderr, "ordered_array_free_memory: ordered_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  free(ordered_array->array);
  free(ordered_array);
}

// returns the position where the new element must be inserted
static unsigned long get_index_to_insert(OrderedArray *ordered_array, void *element)
{
  unsigned long i = 0;
  int cont = 1;
  while (i < ordered_array->el_num && cont)
  {
    if ((*(ordered_array->precedes))(element, (ordered_array->array)[i]))
    {
      cont = 0;
    }
    else
      i++;
  }

  return (i);
}

// inserts the specified element in the specified ordered array at the specified
// index position
static void insert_element(OrderedArray *ordered_array, void *element, unsigned long index)
{
  for (unsigned long i = ordered_array->el_num; i > index; i--)
  {
    (ordered_array->array)[i] = (ordered_array->array)[i - 1];
  }
  (ordered_array->array)[index] = element;
}
