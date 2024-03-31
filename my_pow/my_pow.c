#include <stdio.h>

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;

    int tmp = my_pow(a, b / 2);

    if (b % 2 == 0)
        return tmp * tmp;

    return tmp * tmp * a;
}
