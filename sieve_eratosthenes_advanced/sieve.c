#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;

    int *arr = calloc(sizeof(int), n);

    int c = n - 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i * i < n; i++)
    {
        if (arr[i] != -1)
        {
            for (int j = i * i; j < n; j += i)
            {
                if (arr[j] != -1)
                {
                    arr[j] = -1;
                    c--;
                }
            }
        }
    }
    printf("%d\n", c - 1);

    free(arr);
}
