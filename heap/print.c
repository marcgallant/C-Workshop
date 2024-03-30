#include <stdio.h>

#include "heap.h"

void print_heap_rec(const struct heap *heap, size_t i)
{
    if (i > heap->size - 1)
        return;

    if (i != 0)
        puts(" ");

    printf("%d", heap->array[i]);
    print_heap_rec(heap, 2 * i + 1);
    print_heap_rec(heap, 2 * i + 2);

}

void print_heap(const struct heap *heap)
{
    print_heap_rec(heap, 0);
    printf("\n");
}
