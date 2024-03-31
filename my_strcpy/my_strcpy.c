#include <stdio.h>

char *my_strcpy(char *dest, const char *source)
{
    size_t i = 0;
    do
    {
        dest[i] = source[i];
    } while (source[i++] != '\0');
    return dest;
}
