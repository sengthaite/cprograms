#include <stdio.h>

int main()
{
    // ~5 => ~0101 => 1010  |1: signed bit|0|1|0
    // 1 signed bit means negative; 0 means positive
    // 1011: 2's complement: -1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 1 * 2^0 = -8 + 0 + 2 + 0 = -6
    printf("~5 = %d\n", ~5);

    // ~12 => ~01100 => 10011
    // 10011: -16 + 2 + 1 = -13
    printf("~12 = %d\n", ~12);
    return 0;
}