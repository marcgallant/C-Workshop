#include "heap_sort.h"

#include <stddef.h>
#include <stdio.h>

void heapify_rec(int *array, size_t size, size_t i)
{
    size_t max_i = i;

    if (2 * i + 1 < size && array[2 * i + 1] > array[max_i])
        max_i = 2 * i + 1;

    if (2 * i + 2 < size && array[2 * i + 2] > array[max_i])
        max_i = 2 * i + 2;

    if (max_i != i)
    {
        int tmp = array[i];
        array[i] = array[max_i];
        array[max_i] = tmp;

        heapify_rec(array, size, max_i);
    }
}

void heapify(int *array, size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify_rec(array, size, i);
}

void heap_sort(int *array, size_t size)
{
    heapify(array, size);

    for (size_t i = 0; i < size; i++)
    {
        int tmp = array[0];
        array[0] = array[size - i - 1];
        array[size - i - 1] = tmp;

        heapify(array, size - i - 1);
    }
}
