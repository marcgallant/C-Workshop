#include "simple_fnmatch.h"

int fnmatch_rec(const char *pattern, const char *string)
{
    if (pattern[0] == '\0')
        return string[0] == '\0';

    switch (pattern[0])
    {
    case '*':
        return fnmatch_rec(pattern + 1, string)
            || fnmatch_rec(pattern, string + 1)
            || fnmatch_rec(pattern + 1, string + 1);
    case '\\':
        if (pattern[1] == '\0')
            return string[0] == '\0';
        return pattern[1] == string[0]
        && fnmatch_rec(pattern + 2, string + 1);
    case '?':
        return fnmatch_rec(pattern + 1, string + 1);
    default:
        return pattern[0] == string[0]
            && fnmatch_rec(pattern + 1, string + 1);
    }
}

int simple_fnmatch(const char *pattern, const char *string)
{
    return !fnmatch_rec(pattern, string);
}
