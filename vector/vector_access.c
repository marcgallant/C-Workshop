#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (v)
    {
        v->data = realloc(v->data, n * sizeof(int));
        if (n < v->size)
            v->size = n;

        for (size_t i = v->capacity; i < n; i++)
        {
            v->data[i] = 0;
        }

        v->capacity = n;
    }
    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (v)
    {
        v->size++;
        if (v->size > v->capacity)
        {
            v->capacity *= 2;
            v->data = realloc(v->data, v->capacity * sizeof(int));
        }
        v->data[v->size - 1] = elt;
    }
    return v;
}

void vector_print(const struct vector *v)
{
    if (v && v->size > 0)
    {
        printf("%d", v->data[0]);

        for (size_t i = 1; i < v->size; i++)
        {
            printf(",%d", v->data[i]);
        }
    }
    printf("\n");
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v || i > v->size)
        return NULL;

    if (i == v->size)
        return vector_append(v, elt);
    else
    {
        int tmp = v->data[v->size - 1];
        for (size_t j = v->size - 1; j > i; j--)
        {
            v->data[j] = v->data[j - 1];
        }
        v->data[i] = elt;
        return vector_append(v, tmp);
    }
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v || i >= v->size)
        return NULL;

    for (size_t j = i; j < v->size - 1; j++)
    {
        v->data[j] = v->data[j + 1];
    }
    v->data[v->size - 1] = 0;
    v->size--;

    if (v->size < v->capacity / 2)
    {
        v = vector_resize(v, v->capacity / 2);
    }

    return v;
}
