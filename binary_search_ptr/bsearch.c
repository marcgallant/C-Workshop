#include "bsearch.h"

#include <stdio.h>
#include <stdlib.h>

int *binary_search(int *begin, int *end, int elt)
{
    if (begin == end)
        return begin;

    size_t pivot = (end - begin - 1) / 2;

    if (begin[pivot] == elt)
    {
        return begin + pivot;
    }
    else if (begin[pivot] > elt)
    {
        return binary_search(begin, end - pivot - 1, elt);
    }
    else
    {
        return binary_search(begin + pivot + 1, end, elt);
    }
}
