unsigned char rol(unsigned char value, unsigned char roll)
{
    roll %= 8;
    value = (value << roll) | (value >> (8 - roll));

    return value;
}
