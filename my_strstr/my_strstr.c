#include "my_strstr.h"

#include <stdio.h>

int sub_str(const char *haystack, const char *needle)
{
    int i = 0;
    while (haystack[i] != '\0' && needle[i] != '\0'
           && haystack[i] == needle[i])
    {
        i++;
    }

    return needle[i] == '\0';
}

int my_strstr(const char *haystack, const char *needle)
{
    if (needle[0] == '\0')
        return 0;

    int i = 0;
    while (haystack[i] != '\0')
    {
        if (sub_str(haystack + i, needle))
            return i;
        i++;
    }
    return -1;
}
