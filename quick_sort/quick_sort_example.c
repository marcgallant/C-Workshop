#include <stdio.h>

void quicksort(int *tab, int len);

int main(void)
{
    unsigned i = 0;
    int tab[] = { 10, 11, 2, 3, 8, 5, 7, 6, 26, 30, 2, 1, 17, 13, 14 };

    unsigned size = sizeof(tab) / sizeof(int);

    quicksort(tab, size);

    for (; i < size - 1; ++i)
        printf("%d ", tab[i]);
    printf("%d\n", tab[i]);

    return 0;
}
