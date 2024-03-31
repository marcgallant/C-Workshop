#include "levenshtein.h"

#include <stdio.h>

size_t levenshtein(const char *s1, const char *s2)
{
    size_t n1 = 0;
    while (*(s1 + n1) != '\0')
    {
        n1++;
    }

    size_t n2 = 0;
    while (*(s2 + n2) != '\0')
    {
        n2++;
    }

    if (n1 == 0)
        return n2;

    if (n2 == 0)
        return n1;

    if (*s1 == *s2)
        return levenshtein((s1 + 1), (s2 + 1));

    size_t rec1 = levenshtein((s1 + 1), s2);
    size_t rec2 = levenshtein(s1, (s2 + 1));
    size_t rec3 = levenshtein((s1 + 1), (s2 + 1));

    if (rec1 < rec2)
    {
        if (rec1 < rec3)
            return 1 + rec1;
        else
            return 1 + rec3;
    }
    else
    {
        if (rec2 < rec3)
            return 1 + rec2;
        else
            return 1 + rec3;
    }
}
