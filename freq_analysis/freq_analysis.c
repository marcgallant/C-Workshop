#include <stdio.h>

int ge_val(int hist[], int val)
{
    int sup = 0;

    for (int i = 0; i < 26; i++)
    {
        if ((hist[i] == hist[val] && (i < val)) || hist[i] > hist[val])
            sup++;
    }
    return sup;
}

void freq_analysis(const char text[], const char table[])
{
    int hist[26] = { 0 };

    int i = 0;

    while (*(text + i) != '\0')
    {
        hist[text[i] - 'A']++;
        i++;
    }

    for (i = 0; i < 26; i++)
    {
        if (hist[i] != 0)
        {
            int sup = ge_val(hist, i);

            printf("%c %c\n", i + 'A', table[sup]);
        }
    }
}

int main(void)
{
    const char text[] = "FXOWFFOWOFF";
    const char table[] = "ABCD";

    freq_analysis(text, table);

    return 0;
}
