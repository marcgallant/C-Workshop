#define _POSIX_C_SOURCE 200809L

#include <stdio.h>

int reverse_content(const char *file_in, const char *file_out)
{
    if (!file_in || !file_out)
        return -1;

    FILE *f1 = fopen(file_in, "r");
    if (!f1)
        return -1;

    FILE *f2 = fopen(file_out, "w");
    if (!f2)
    {
        fclose(f1);
        return -1;
    }

    fseek(f1, -1, SEEK_END);

    do
    {
        char c = fgetc(f1);
        if (c != EOF)
            fputc(c, f2);
    } while (fseek(f1, -2, SEEK_CUR) != -1);

    fclose(f1);
    fclose(f2);
    return 0;
}
