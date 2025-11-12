#include <stdio.h>

// p and n are positive
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main()
{
    // (123, 5, 2) => 01[11]1011 => 11 (3)
    printf("getbits(123, 5, 2) = %d\n", getbits(123, 5, 2));
    /*
    (01111011 >> (5 + 1 - 2)) & ~(~0 << 2)
    01111011 >> 4 & ~(11111111 << 2)
    00000111 & ~(11111100)
    00000111 & 00000011
    00000011
    */
    return 0;
}