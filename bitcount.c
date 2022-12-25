#include <stdio.h>

int bitcount(unsigned x);
int bitcount_two_complement(unsigned x);

int main(void)
{
    printf("bitcount(10) = %d\n", bitcount(10));
    printf("bitcount_two_complement(10) = %d\n", bitcount_two_complement(10));
    return 0;
}

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 1)
            b++;
    return b;
}

int bitcount_two_complement(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
}