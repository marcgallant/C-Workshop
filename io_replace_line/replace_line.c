#define _POSIX_C_SOURCE 200809L

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    if (!content || !file_in || !file_out)
        return -1

    FILE *f1 = fopen(file_in, "r");
    if (!f1)
        return -1;

    FILE *f2 = fopen(file_out, "w+");
    if (!f2)
    {
        fclose(f1);
        return -1;
    }

    int i = 0;
    char *line = NULL;
    size_t size = 80;

    while (i < n && getline(&line, &size, f1) != -1)
    {
        fputs(line, f2);
        i++;
    }

    getline(&line, &size, f1);
    if (i < n)
    {
        fputs(line, f2);
        fclose(f1);
        fclose(f2);
        free(line);
        return 1;
    }

    fputs(content, f2);

    while (getline(&line, &size, f1) != -1)
    {
        fputs(line, f2);
    }

    fclose(f1);
    fclose(f2);
    free(line);
    return 0;
}
