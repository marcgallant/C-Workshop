#include "insertion_sort.h"

#include <stddef.h>

void insertion_sort(void **array, f_cmp comp)
{
    if (array && array[0])
    {
        int i = 1;
        while (array[i])
        {
            void *key = array[i];
            int j = i - 1;

            while (j >= 0 && comp(array[j], key) > 0)
            {
                array[j + 1] = array[j];
                j--;
            }

            array[j + 1] = key;
            i++;
        }
    }
}
