#include "my_strlowcase.h"

#include <stdio.h>

void my_strlowcase(char *str)
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && 'Z' >= str[i])
            str[i] |= 32;
        i++;
    }
}
