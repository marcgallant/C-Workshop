#include "check_alphabet.h"

#include <stdio.h>
#include <stdlib.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet)
    {
        size_t i = 0;
        while (*(alphabet + i) != '\0')
        {
            size_t j = 0;
            while (*(str + j) != '\0' && *(alphabet + i) != *(str + j))
            {
                j++;
            }

            if (*(str + j) == '\0')
                return 0;
            i++;
        }
    }
    return 1;
}
