#include "is_set.h"

#include <stdio.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int mask = 1 << (n - 1);

    return (value & mask) == mask;
}
