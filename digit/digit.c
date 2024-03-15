unsigned int digit(int n, int k)
{
    if (k <= 0 || n <= 0)
        return 0;

    for (int i = 0; i < k - 1; i++)
    {
        n /= 10;
    }
    return n % 10;
}
