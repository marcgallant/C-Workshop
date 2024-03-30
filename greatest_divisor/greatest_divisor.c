unsigned int greatest_divisor(unsigned int n)
{
    for (unsigned int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return n / i;
    }
    return 1;
}
