#include <stdio.h>
#include <stdlib.h>

void rot_x(char *s, int x)
{
    if (!s)
        return;

    x = (x % 26 + 26) % 26;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = (s[i]  + x - 'a') % 26 + 'a';
        }

        if (s[i] >= 'A' && s[i]  <= 'Z')
        {
            s[i] = (s[i]  + x - 'A') % 26 + 'A';
        }
    }
}
