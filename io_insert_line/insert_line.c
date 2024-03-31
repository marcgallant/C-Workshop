#define _POSIX_C_SOURCE 200809L

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int count_n(const char *content)
{
    size_t n = 0;
    size_t i = 0;
    while (*(content + i) != '\0')
    {
        if (*(content + i) == '\n')
            n++;
        i++;
    }
    return n;
}

int last_char(const char *content)
{
    size_t i = 0;
    while (*(content + i) != '\0')
    {
        i++;
    }
    if (i != 0)
        return *(content + i - 1);

    return *(content + i);
}

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    if (content)
        return -1;

    FILE *f1 = fopen(file_in, "r");
    FILE *f2 = fopen(file_out, "w");
    if (!f1 || !f2 || !content)
        return -1;

    size_t i = 0;
    char *line = NULL;
    size_t size = 80;
    while (i < n && getline(&line, &size, f1) != -1)
    {
        fputs(line, f2);
        i++;
    }

    while (i < n)
    {
        fputs("\n", f2);
        i++;
    }

    int tmp = 1;
    fputs(content, f2);
    i += count_n(content);

    while (getline(&line, &size, f1) != -1)
    {
        tmp = 0;
        fputs(line, f2);
        i++;
    }

    if (tmp && last_char(content) != '\n')
        i++;

    fclose(f1);
    fclose(f2);
    free(line);
    return i;
}
