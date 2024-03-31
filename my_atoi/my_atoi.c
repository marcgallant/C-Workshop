#include "my_atoi.h"

#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *s)
{
    if (!s)
        return 0;

    size_t i = 0;
    while (s[i] == ' ')
    {
        i++;
    }

    int neg = 0;
    if (s[i] == '-' || s[i] == '+')
    {
        neg = s[i] == '-';
        i++;
    }

    int res = 0;
    while (s[i] >= '0' && s[i] <= '9')
    {
        res *= 10;
        res += s[i] - '0';
        i++;
    }

    if (s[i] != '\0')
        return 0;

    return neg ? -res : res;
}
