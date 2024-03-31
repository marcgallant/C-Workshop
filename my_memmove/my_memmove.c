#include "my_memmove.h"

void *my_memmove(void *dest, const void *src, size_t n)
{
    char *dest_tmp = dest;
    const char *src_tmp = src;

    if (src > dest)
    {
        for (size_t i = 0; i < n; i++)
        {
            dest_tmp[i] = src_tmp[i];
        }
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            dest_tmp[n - i - 1] = src_tmp[n - i - 1];
        }
    }
    return dest_tmp;
}
