#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
        return 1;

    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n - i - 1; j++)
            putchar(' ');

        for (unsigned int j = 0; j < 1 + 2 * i; j++)
            putchar('*');

        putchar('\n');
    }

    for (unsigned int i = 0; i < n / 2; i++)
    {
        for (unsigned int j = 0; j < n - 1; j++)
            putchar(' ');

        putchar('*');
        putchar('\n');
    }
    return 0;
}
