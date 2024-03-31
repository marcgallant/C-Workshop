#include <stdlib.h>

#include "vector.h"

struct vector *vector_init(size_t n)
{
    struct vector *res = calloc(1, sizeof(struct vector));
    res->capacity = n;
    res->data = calloc(n, sizeof(int));

    return res;
}

void vector_destroy(struct vector *v)
{
    free(v->data);
    free(v);
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    v->capacity = n;
    v->size = 0;
    v->data = realloc(v->data, n * sizeof(struct vector));

    for (size_t i = 0; i < v->capacity; i++)
    {
        v->data[i] = 0;
    }

    return v;
}
