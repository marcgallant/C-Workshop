#include "my_strcasecmp.h"

#include <stdio.h>
#include <stdlib.h>

char lowcase(char c)
{
    return (c >= 'A' && c <= 'Z') ? c |= 32 : c;
}

int my_strcasecmp(const char *s1, const char *s2)
{
    size_t i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (lowcase(s1[i]) != lowcase(s2[i]))
            break;
        i++;
    }

    return lowcase(s1[i]) - lowcase(s2[i]);
}
