#include <stdio.h>

#define _POSIX_C_SOURCE 200809L

int merge_files(const char *file_1, const char *file_2)
{
    if (!file_1 || !file_2)
        return -1;

    FILE *f2 = fopen(file_2, "r");
    if (!f2)
        return -1;

    FILE *f1 = fopen(file_1, "a");
    if (!f1)
    {
        fclose(f2);
        return -1;
    }

    int c;
    while ((c = fgetc(f2)) != EOF)
    {
        if (fputc(c, f1) == -1)
        {
            fclose(f1);
            fclose(f2);
            return -1;
        }
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
