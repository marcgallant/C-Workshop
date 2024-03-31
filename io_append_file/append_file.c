#include <stdio.h>

#define _POSIX_C_SOURCE 200809L

int append_file(const char *file_in, const char *content)
{
    if (!file_in)
        return -1;

    FILE *f = fopen(file_in, "a");
    if (!f)
        return -1;

    if (fprintf(f, "%s", content) < -1)
    {
        fclose(f);
        return -1;
    }

    fclose(f);
    return 0;
}
