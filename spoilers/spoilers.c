#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(STDERR_FILENO, "Invalid number of arguments\n", 28);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Could not open file\n", 20);
        return 1;
    }

    lseek(fd, -1, SEEK_END);
    size_t count = 0;

    char res[3] = { 0, 0, '\n' };
    char buf[1] = { 0 };

    while (read(fd, buf, 1) != -1 && count != 2)
    {
        if (!isspace(buf[0]))
        {
            res[1 - count] = buf[0];
            count++;
        }
        if (lseek(fd, -2, SEEK_CUR) == -1)
        {
            break;
        }
    }

    close(fd);

    if (count != 2)
    {
        write(STDERR_FILENO, "File is not long enough\n", 24);
        return 1;
    }

    write(STDOUT_FILENO, res, 3);
    return 0;
}
