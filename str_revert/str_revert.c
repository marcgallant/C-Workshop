#include "str_revert.h"

#include <stdio.h>
#include <stdlib.h>

void str_revert(char arr[])
{
    size_t n = 0;
    while (arr[n] != '\0')
    {
        n++;
    }

    for (size_t i = 0; i < n / 2; i++)
    {
        char tmp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = tmp;
    }
}
