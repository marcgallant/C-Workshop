int int_palindrome(int n)
{
    int res = 0;
    int tmp = n;

    while (tmp != 0)
    {
        res = res * 10 + tmp % 10;
        tmp /= 10;
    }

    return res == n;
}
