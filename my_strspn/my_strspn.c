#include "my_strspn.h"

#include <stdio.h>

size_t my_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        size_t j = 0;
        while (accept[j] != '\0')
        {
            if (accept[j] == s[i])
                break;
            j++;
        }
        if (accept[j] == '\0')
            return i;
        i++;
    }
    return i;
}
