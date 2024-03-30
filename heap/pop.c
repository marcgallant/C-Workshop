#include <assert.h>
#include <stdlib.h>

#include "heap.h"

void pop_rec(struct heap *heap, size_t i)
{
    if (2 * i + 1 < heap->size)
    {
        size_t max_i = 2 * i + 1;
        if (2 * i + 2 < heap->size
            && heap->array[2 * i + 2] > heap->array[2 * i + 1])
        {
            max_i = 2 * i + 2;
        }

        if (heap->array[i] < heap->array[max_i])
        {
            int tmp = heap->array[i];
            heap->array[i] = heap->array[max_i];
            heap->array[max_i] = tmp;

            pop_rec(heap, max_i);
        }
    }
}

int pop(struct heap *heap)
{
    if (heap->size == 0)
        assert(0);

    int res = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->array[heap->size - 1] = 0;

    heap->size--;

    pop_rec(heap, 0);
    if (heap->size < heap->capacity / 2 && heap->capacity != 8)
    {
        heap->capacity /= 2;
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
    }

    return res;
}
