#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
        return;

    if (width % 2 == 0)
        width++;

    for (int i = 0; i < (width + 1) / 2; i++)
    {
        if (i == 0 || i == width / 2)
        {
            for (int j = 0; j < width; j++)
                putchar('*');
        }
        else
        {
            putchar('*');
            for (int j = 0; j < width - 2; j++)
                putchar(' ');
            putchar('*');
        }
        putchar('\n');
    }
}
