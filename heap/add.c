#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, heap->capacity * sizeof(int));
    }

    heap->array[heap->size] = val;

    int i = heap->size;
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i])
    {
        int tmp = heap->array[(i - 1) / 2];
        heap->array[(i - 1) / 2] = heap->array[i];
        heap->array[i] = tmp;

        i = (i - 1) / 2;
    }
    heap->size++;
}
