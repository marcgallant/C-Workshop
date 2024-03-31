#include "null_terminated_arrays.h"

#include <stddef.h>

void reverse_matrix(const char ***matrix)
{
    if (matrix)
    {
        size_t i = 0;
        while (matrix[i])
        {
            size_t n = 0;
            while (matrix[i][n])
            {
                n++;
            }

            for (size_t j = 0; j < n / 2; j++)
            {
                const char *s = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = s;
            }
            i++;
        }
        size_t n = 0;
        while (matrix[n])
        {
            n++;
        }

        for (size_t i = 0; i < n / 2; i++)
        {
            const char **s = matrix[i];
            matrix[i] = matrix[n - i - 1];
            matrix[n - i - 1] = s;
        }
    }
}
