#include "hill_array.h"

#include <stdio.h>

int check(int i, int j)
{
    return i >= 0 && j >= 0 && j >= i;
}

int top_of_the_hill(int tab[], size_t len)
{
    size_t i = 0;
    size_t tmp = 0;

    while (i < len - 1 && check(tab[i], tab[i + 1]))
    {
        if (tab[i] < tab[i + 1])
            tmp = i + 1;
        i++;
    }

    while (i < len - 1 && check(tab[i + 1], tab[i]))
    {
        i++;
    }

    if (i != len - 1)
        return -1;

    return tmp;
}
