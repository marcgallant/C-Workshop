#include "lakes.h"

#include <stdio.h>
#include <stdlib.h>

void check_lakes(char **map, int i, int j)
{
    map[i][j] = '#';

    if (map[i - 1][j] == '.')
        check_lakes(map, i - 1, j);

    if (map[i][j - 1] == '.')
        check_lakes(map, i, j - 1);

    if (map[i + 1][j] == '.')
        check_lakes(map, i + 1, j);

    if (map[i][j + 1] == '.')
        check_lakes(map, i, j + 1);
}

int lakes(char **map, int width, int height)
{
    int c = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == '.')
            {
                check_lakes(map, i, j);
                c++;
            }
        }
    }
    return c;
}
