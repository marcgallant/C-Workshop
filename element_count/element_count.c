#include "element_count.h"

size_t element_count(int *begin, int *end)
{
    if (!begin || !end)
        return 0;
    return end - begin;
}
