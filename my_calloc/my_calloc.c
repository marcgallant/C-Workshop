#include "my_calloc.h"

#include <stdio.h>
#include <stdlib.h>

void *my_calloc(size_t n, size_t size)
{
    char *ptr = malloc(n * size);

    if (ptr)
    {
        for (size_t i = 0; i < n * size; i++)
            ptr[i] = 0;
    }

    return ptr;
}
