#include "int_vector_vice_max.h"

#include <stdio.h>

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int vice = vec.data[1];

    if (max < vice)
    {
        int tmp = vice;
        vice = max;
        max = tmp;
    }

    for (size_t i = 2; i < vec.size; i++)
    {
        if (max < vec.data[i])
            max = vec.data[i];
        else if (vice < vec.data[i])
            vice = vec.data[i];
    }
    return vice;
}
