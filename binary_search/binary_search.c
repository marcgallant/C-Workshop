#include <stdio.h>
#include <stdlib.h>

int binary_search(const int vec[], int size, int elt)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int pivot = (end + start) / 2;

        if (vec[pivot] == elt)
            return pivot;
        else
        {
            if (vec[pivot] < elt)
                start = pivot + 1;
            else
                end = pivot - 1;
        }
    }
    return -1;
}
