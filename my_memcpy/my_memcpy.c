#include "my_memcpy.h"

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char *tmp_dest = dest;
    const char *tmp_source = source;

    for (size_t i = 0; i < num; i++)
    {
        tmp_dest[i] = tmp_source[i];
    }

    return tmp_dest;
}
