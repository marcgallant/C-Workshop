#include <stdio.h>
#include <stdlib.h>

#include "functional_programming_advanced.h"

bool is_even(int a)
{
    return !(a % 2);
}

void print_int(int *a)
{
    printf("%d\n", *a);
}

void map(int *array, size_t len, void (*func)(int *))
{
    for (size_t i = 0; i < len; i++)
    {
        func(array + i);
    }
}

void print_even(int *array, size_t len)
{
    int **out_array = calloc(1, sizeof(int *));

    size_t out_len = filter(array, len, out_array, is_even);
    map(*out_array, out_len, print_int);

    free(*out_array);
    free(out_array);
}
