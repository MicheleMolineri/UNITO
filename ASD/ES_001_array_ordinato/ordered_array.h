// definisco che il tipo di chiama OrderedArray e si riferisce alla struttura _OrderedArray
typedef struct _OrderedArray OrderedArray;

/*
    FUNCTION : create a new empty struct
    @return : indirizzo del array o NULL
*/
OrderedArray *ordered_array_create(int (*precedes)(void *, void *));

/*
    Function : verify if an array is empty
    @return : bool value true --> empty false--> !empty
*/
int ordered_array_is_empty(OrderedArray *);

/*
    Function : get array dimention
    @param : *ord_array -> pointer to the array
    @return : size of the array (int)
 */

unsigned long ordered_array_size(OrderedArray *ord_array);

/*
    Function : add a value to the array
    @param : *ord_array -> pointer to the array
    @param : num -> element to add
 */
void ordered_array_add(OrderedArray *ord_array, void *el);

/*
    Function : get elem at index i
    @param : *ord_array
    @param : i
    @return :void* elem
 */
void *ordered_array_get(OrderedArray *ord_array, int i);

// It accepts as input a pointer to an ordered array and
// it frees the memory allocated to store the ordered array.
// It does not free the memory allocated to store the array elements,
// since freing that memory is responsibility of the function where
// the ordered array was created.
// The input parameters cannot be NULL.
void ordered_array_free_memory(OrderedArray *);
