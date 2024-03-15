unsigned long fibo_iter(unsigned long n)
{
    unsigned long a = 0;
    unsigned long b = 1;
    unsigned long c;

    while (n-- > 0)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return a;
}
