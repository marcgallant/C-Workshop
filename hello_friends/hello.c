#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
        printf("Hello World!\n");
    else
    {
        for (int i = 1; i < argc; i++)
        {
            printf("Hello %s!\n", argv[i]);
        }
    }
}
