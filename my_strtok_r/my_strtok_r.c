#define _POSIX_C_SOURCE 2

#include "my_strtok_r.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in_str(char c, const char *delim)
{
    int i = 0;
    while (delim[i] != '\0')
    {
        if (c == delim[i])
            return 1;
        i++;
    }
    return 0;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (!str)
    {
        if (*saveptr)
            str = *saveptr;
        else
            return NULL;
    }

    size_t i = 0;
    while (str[i] != '\0' && (in_str(str[i], delim)))
    {
        i++;
    }

    if (str[i] == '\0')
    {
        *(saveptr) = NULL;
        return NULL;
    }

    size_t j = i;
    while (str[j] != '\0' && !(in_str(str[j], delim)))
    {
        j++;
    }

    if (str[j] != '\0')
    {
        str[j] = '\0';
        j++;
        *saveptr = str + j;
    }
    else
    {
        *saveptr = NULL;
    }

    return str + i;
}
