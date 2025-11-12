/*
* setbits(x, p, n, y): return x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	x = x >> (p + 1) << (p + 1);
	printf("x: %d\n", x);
	unsigned filter = ~(~0 >> (p - n + 1) << (p - n + 1));
	printf("filter: %d\n", filter);
	y = y << (p - n + 1);
	printf("y: %d\n", y);
	return x | y | filter;
	// return (x >> (p + 1) << (p + 1)) | (~(~0 >> (p - n + 1) << (p - n + 1))) | (y << (p - n + 1));
}

int main()
{
    unsigned x, y;
    int p, n;
    x = 127;
    y = 0;
    p = 5;
    n = 5;
    printf("setbits(%d, %d, %d, %d) => %d\n", x, p, n, y, setbits(x, p, n, y));
    return 0;
}