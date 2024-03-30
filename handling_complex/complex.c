#include "complex.h"

#include <stdio.h>

void print_complex(struct complex a)
{
    if (a.img <= 0)
        printf("complex(%.2f - %.2fi)\n", a.real, -a.img);
    else
        printf("complex(%.2f + %.2fi)\n", a.real, a.img);
}

struct complex neg_complex(struct complex a)
{
    struct complex res = { -a.real, -a.img };
    return res;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex res = { a.real + b.real, a.img + b.img };
    return res;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex res = { a.real - b.real, a.img - b.img };
    return res;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex res = { a.real * b.real - a.img * b.img, //
                           a.real * b.img + a.img * b.real };
    return res;
}

struct complex div_complex(struct complex a, struct complex b)
{
    float real = (a.real * b.real + a.img * b.img) //
        / (b.real * b.real + b.img * b.img);
    float img = (a.img * b.real - a.real * b.img) //
        / (b.real * b.real + b.img * b.img);

    struct complex res = { real, img };
    return res;
}
