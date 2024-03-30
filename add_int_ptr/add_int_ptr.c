int *add_int_ptr(int *a, int *b)
{
    if (a && b)
        *a += *b;

    return a;
}
