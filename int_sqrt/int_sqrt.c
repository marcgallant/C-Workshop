int int_sqrt(int n)
{
    if (n < 0)
        return -1;

    int i = 1;
    for (; i * i <= n; i++)
    {
        continue;
    }
    return i - 1;
}
