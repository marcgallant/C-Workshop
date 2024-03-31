#include "vigenere.h"

#include <stdio.h>
#include <stdlib.h>

int is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

int is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}

void cipher(const char *key, const char *msg, char *res)
{
    size_t n = 0;
    while (key[n] != '\0')
    {
        n++;
    }

    size_t i = 0;
    size_t j = 0;
    while (msg[i] != '\0')
    {
        char c1 = msg[i];

        if (is_lower(c1))
            c1 = c1 - 'a' + 'A';

        if (!is_upper(c1))
            res[i] = c1;
        else
        {
            if (j == n)
                j = 0;

            char c2 = key[j];
            if (is_lower(c2))
                c2 = c2 - 'a' + 'A';

            res[i] = 'A' + (c1 - 'A' + c2 - 'A') % 26;
            j++;
        }
        i++;
    }
    res[i] = '\0';
}

void decipher(const char *key, const char *msg, char *res)
{
    size_t n = 0;
    while (key[n] != '\0')
    {
        n++;
    }

    size_t i = 0;
    size_t j = 0;
    while (msg[i] != '\0')
    {
        char c1 = msg[i];

        if (is_lower(c1))
        {
            c1 = c1 - 'a' + 'A';
        }

        if (!is_upper(c1))
            res[i] = c1;
        else
        {
            if (j == n)
                j = 0;

            char c2 = key[j];

            if (is_lower(c2))
            {
                c2 = c2 - 'a' + 'A';
            }

            res[i] = 'A' + ((c1 - c2) % 26 + 26) % 26;
            j++;
        }
        i++;
    }
    res[i] = '\0';
}
