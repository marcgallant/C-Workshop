#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int res = 0;
    for (size_t i = 0; i < len; i++)
    {
        res = func(array[len - i - 1], res);
        array[len - i - 1] = res;
    }

    return res;
}
