
int my_round(float n)
{
    int r = n;

    if (n >= 0.0)
        return n - r >= 0.5 ? r + 1 : r;

    return n - r <= -0.5 ? r - 1 : r;
}
