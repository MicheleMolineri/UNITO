#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "ordered_array.h"

int *precedes_int(void *arg1, void *arg2)
{
    // per poter utilizzare i valoir void li devo castare
    int *i1 = (int *)arg1;
    int *i2 = (int *)arg2;

    return (*i1 < *i2);
}

int i1, i2, i3;
OrderedArray *ordered_array_int;

void setUp(void)
{
    i1 = -12;
    i2 = 0;
    i3 = 4;
    ordered_array_int = ordered_array_create(precedes_int(i1, i2));
}

void test_ordered_array_is_empty_zero_el(void)
{
    TEST_ASSERT_TRUE(ordered_array_is_empty(ordered_array_int));
}

void test_ordered_array_is_empty_one_el(void)
{
    ordered_array_add(ordered_array_int, 1);
    TEST_ASSERT_FALSE(array_is_empty(ordered_array_int));
}