double pi_generator_rec(int precision, double i)
{
    if (precision <= 0)
        return 1;

    return (1 + i / (i * 2 + 1) * pi_generator_rec(precision - 1, i + 1));
}

double pi_generator(int precision)
{
    return 2 * pi_generator_rec(precision, 1);
}
