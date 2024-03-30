#include "int_vector_hill.h"

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

int int_vector_hill(struct int_vector vec)
{
    if (vec.size == 0)
        return -1;

    return top_of_the_hill(vec.data, vec.size);
}
