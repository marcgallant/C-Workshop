#include "int_vector_insert_sort.h"

#include <stdio.h>
#include <stdlib.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;

    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    size_t i = 1;
    while (i < vec.size)
    {
        size_t j = i;

        while (j > 0 && vec.data[j - 1] > vec.data[j])
        {
            vec = swap(vec, j, j - 1);
            j--;
        }
        i++;
    }

    return vec;
}
