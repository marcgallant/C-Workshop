#include "array_max_min.h"

#include <stdio.h>
#include <stdlib.h>

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    if (tab && len != 0)
    {
        *min = tab[0];
        *max = tab[0];
        for (size_t i = 1; i < len; i++)
        {
            if (*(tab + i) < *min)
                *min = *(tab + i);

            if (*(tab + i) > *max)
                *max = *(tab + i);
        }
    }
}
