#include "my_atoi_base.h"

#include <stdio.h>
#include <stdlib.h>

int my_atoi_base(const char *str, const char *base)
{
    int n = 0;
    while (base[n] != '\0')
    {
        n++;
    }

    int i = 0;
    while (str[i] == ' ')
        i++;

    int neg = 0;
    if (str[i] == '-' || *str == '+')
    {
        neg = str[i] == '-';
        i++;
    }

    int res = 0;
    while (str[i] != '\0')
    {
        int j = 0;
        while (base[j] != '\0')
        {
            if (base[j] == str[i])
            {
                res *= n;
                res += j;
                break;
            }
            j++;
        }

        if (base[j] == '\0')
            return 0;
        i++;
    }

    return neg ? -res : res;
}
