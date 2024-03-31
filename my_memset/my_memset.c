#include "my_memset.h"

void *my_memset(void *s, int c, size_t n)
{
    char *tmp = s;
    for (size_t i = 0; i < n; i++)
    {
        tmp[i] = c;
    }
    return tmp;
}
