#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    int res = 0;
    for (size_t i = 0; i < len; i++)
    {
        res = func(res, array[i]);
        array[i] = res;
    }
    return res;
}
