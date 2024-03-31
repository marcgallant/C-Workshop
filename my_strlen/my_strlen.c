#include "my_strlen.h"

#include <stdlib.h>

size_t my_strlen(const char *s)
{
    size_t i = 0;
    if (s)
    {
        while (s[i] != '\0')
        {
            i++;
        }
    }

    return i;
}
