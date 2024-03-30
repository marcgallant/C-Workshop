#include "int_vector_print.h"

#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    for (size_t i = 0; i < vec.size - 1; i++)
    {
        printf("%d ", vec.data[i]);
    }

    if (vec.size != 0)
        printf("%d", vec.data[vec.size - 1]);
    printf("\n");
}

int main(void)
{
    struct int_vector vec = { .size = 6, .data = { 0, 1, 2, 3, 4, 5 } };

    int_vector_print(vec);
}
