#include "my_itoa.h"

#include <stdio.h>
#include <stdlib.h>

void str_revert(char *arr, size_t n)
{
    for (size_t i = 0; i < n / 2; i++)
    {
        char tmp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = tmp;
    }
}

char *my_itoa(int value, char *s)
{
    if (value == 0)
        return "0";

    int neg = 0;
    if (value < 0)
    {
        neg = 1;
        value = -value;
    }

    size_t i = 0;
    while (value != 0)
    {
        s[i++] = value % 10 + '0';
        value /= 10;
    }

    if (neg)
        s[i++] = '-';

    s[i] = '\0';
    str_revert(s, i);

    return s;
}
