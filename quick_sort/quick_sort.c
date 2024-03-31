#include <stdio.h>
#include <stdlib.h>

int partition(int *tab, int begin, int end)
{
    int pivot = tab[end];
    int i = (begin - 1);

    for (int j = begin; j < end; j++)
    {
        if (tab[j] < pivot)
        {
            i++;
            int tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
        }
    }

    int tmp = tab[i + 1];
    tab[i + 1] = tab[end];
    tab[end] = tmp;

    return (i + 1);
}

void quicksort_rec(int *tab, int begin, int end)
{
    if (begin < end)
    {
        int pivot = partition(tab, begin, end);
        quicksort_rec(tab, begin, pivot - 1);
        quicksort_rec(tab, pivot + 1, end);
    }
}

void quicksort(int *tab, int len)
{
    quicksort_rec(tab, 0, len - 1);
}
