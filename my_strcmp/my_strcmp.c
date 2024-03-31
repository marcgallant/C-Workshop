#include "my_strcmp.h"

#include <stdio.h>

int my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            break;
        i++;
    }

    return s1[i] - s2[i];
}