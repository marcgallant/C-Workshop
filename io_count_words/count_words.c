#include <stdio.h>

int in_delim(char c)
{
    return c == ' ' || c == '\n' || c == '\t';
}

int count_words(const char *file_in)
{
    if (!file_in)
        return -1;

    FILE *f = fopen(file_in, "r");
    if (!f)
        return -1;

    int count = 0;
    int inword = 0;
    char c;
    while ((c = fgetc(f)) != EOF)
    {
        if (in_delim(c))
        {
            if (inword)
                inword = 0;
        }
        else
        {
            if (!inword)
            {
                inword = 1;
                count++;
            }
        }
    }
    fclose(f);
    return count;
}
