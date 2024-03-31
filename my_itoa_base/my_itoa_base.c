#include "my_itoa_base.h"

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

char *my_itoa_base(int value, char *s, const char *base)
{
    if (value == 0)
    {
        s[0] = base[0];
        s[1] = '\0';
        return s;
    }

    int n = 0;
    while (base[n] != '\0')
    {
        n++;
    }

    int neg = 0;
    if (value < 0)
    {
        if (n == 10)
            neg = 1;
        value = -value;
    }

    int j = 0;
    while (value != 0)
    {
        s[j++] = base[value % n];
        value /= n;
    }

    if (neg)
        s[j++] = '-';

    s[j] = '\0';
    str_revert(s, j);

    return s;
}
