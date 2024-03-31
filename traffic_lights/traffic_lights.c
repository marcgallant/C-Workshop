#include "traffic_lights.h"

void init(unsigned char *lights)
{
    *lights = *lights << 8;
}

void turn_on(unsigned char *lights, unsigned char light_num)
{
    unsigned char mask = 1 << (light_num - 1);
    *lights |= mask;
}

void turn_off(unsigned char *lights, unsigned char light_num)
{
    unsigned char mask = ~(1 << (light_num - 1));
    *lights &= mask;
}

unsigned char is_set(unsigned char *lights)
{
    unsigned int mask = 1 << 3;

    return (*lights & mask) == mask;
}

void next_step(unsigned char *lights)
{
    unsigned char r = is_set(lights);
    *lights = (*lights << 1) + r;

    turn_off(lights, 5);
}

void reverse(unsigned char *lights)
{
    *lights = ~(*lights);
}

void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    if (*lights_1 != *lights_2)
    {
        *lights_1 ^= *lights_2;
        *lights_2 ^= *lights_1;
        *lights_1 ^= *lights_2;
    }
}
