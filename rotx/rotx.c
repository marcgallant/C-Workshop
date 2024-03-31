#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
        return 0;

    char key = (atoi(argv[1]) % 26 + 26) % 26;
    char key_int = (atoi(argv[1]) % 10 + 10) % 10;;

    char buf[1] = { 0 };
    ssize_t i = 1;
    while ((i = read(STDIN_FILENO, buf, sizeof(char))) > 0)
    {
        if (*buf >= 'a' && *buf <= 'z')
        {
            *buf = (*buf + key - 'a') % 26 + 'a';
        }
        else if (*buf >= 'A' && *buf <= 'Z')
        {
            *buf = (*buf + key - 'A') % 26 + 'A';
        }
        else if (*buf >= '0' && *buf <= '9')
        {
            *buf = (*buf + key_int - '0') % 10 + '0';
        }

        if (write(STDOUT_FILENO, buf, sizeof(char)) == -1)
            return 1;
    }

    if (i == -1)
        return 1;
    return 0;
}
