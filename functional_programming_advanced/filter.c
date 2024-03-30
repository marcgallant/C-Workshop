#include <stdlib.h>

#include "functional_programming_advanced.h"

size_t filter(int *array, size_t len, int **out_array, bool (*func)(int))
{
    int *res = calloc(len, sizeof(int));
    size_t j = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (func(array[i]))
        {
            res[j] = array[i];
            j++;
        }
    }

    *out_array = res;

    return j;
}
