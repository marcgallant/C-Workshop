#include "functional_programming_advanced.h"

bool any(int *array, size_t len, bool (*func)(int))
{
    for (size_t i = 0; i < len; i++)
    {
        if (func(array[i]))
            return true;
    }
    return false;
}
