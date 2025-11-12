/*
* invert(x, p, n): invert bit from p within n bits
*/

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x >> (p + 1) << (p + 1)) | (~(~0 >> (p - n + 1) << (p - n + 1))) | (y << (p - n + 1));
}

unsigned invert(unsigned x, int p, int n)
{
    return setbits(x, p, n, ~((~0 >> (p - n + 1) << (p - n + 1)) | getbits(x, p, n)));
}

int main()
{
    printf("invert(87, 5, 3) = %d\n", invert(87, 5, 3));
    return 0;
}