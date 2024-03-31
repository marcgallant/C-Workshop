#include "palindrome.h"

#include <stdio.h>
#include <stdlib.h>

int check(char c)
{
    return (c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9');
}

int palindrome(const char *s)
{
    if (!s)
        return 0;

    size_t n = 0;
    while (s[n] != '\0')
    {
        n++;
    }

    if (n == 0)
        return 1;

    for (size_t i = 0, j = n - 1; i < j; i++, j--)
    {
        while (!check(s[i]))
        {
            i++;
        }

        while (!check(s[j]))
        {
            j--;
        }

        if (s[i] != s[j])
            return 0;
    }
    return 1;
}
