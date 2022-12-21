/*
* rightrot(x, n): return the value of integer x rotate to the right by n bit positions.
*/

#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, unsigned n);

int main(void)
{
    // include signed bit
    //0b000...101 (-> 1) : 0b01....10
    printf("%u\n", rightrot(5, 1));

    printf("%u\n", rightrot(1, 1));
    return 0;
}

/*rightrot:  rotates x to the right by n bit positions */
unsigned rightrot(unsigned x, unsigned n)
{
    for(int i = 0; i < n; i++) {
        // check last bit of x if 1
        x = x & 1 ? ((x >> 1) | ~(~0U >> 1)) : x >> 1;
    }
    return x;
}