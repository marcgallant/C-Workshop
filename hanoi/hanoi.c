#include <stdio.h>

void rec_hanoi(unsigned n, char D, char A, char I)
{
    if (n != 0)
    {
        rec_hanoi(n - 1, D, I, A);
        printf("%c->%c\n", D, A);
        rec_hanoi(n - 1, I, A, D);
    }
}

void hanoi(unsigned n)
{
    rec_hanoi(n, '1', '3', '2');
}
