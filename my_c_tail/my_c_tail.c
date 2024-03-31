#include "my_c_tail.h"

#include <stdlib.h>
#include <unistd.h>

void stdintail(unsigned int n)
{
    if (n > 0)
    {
        char *buf = malloc(sizeof(char) * 10000);
        size_t size = read(STDIN_FILENO, buf, 10000);

        size_t c = 0;
        size_t i = size - 1;

        while (i > 0 && c <= n)
        {
            if (buf[i] == '\n')
                c++;
            i--;
        }

        if (i != 0)
            write(STDOUT_FILENO, buf + i + 2, size - i - 2);
        else
            write(STDOUT_FILENO, buf, size);

        free(buf);
    }
}
