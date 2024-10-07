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
int ordered_array_is_empty(OrderedArray *array);