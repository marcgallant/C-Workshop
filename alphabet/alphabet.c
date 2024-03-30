#include <stdio.h>

int main(void)
{
    for (char c = 'a'; c < 'z'; c++)
    {
        putchar(c);
        putchar(' ');
    }

    putchar('z');
    putchar('\n');

    return 0;
}
