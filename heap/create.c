#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *res = calloc(1, sizeof(struct heap));
    res->array = calloc(8, sizeof(int));

    return res;
}
