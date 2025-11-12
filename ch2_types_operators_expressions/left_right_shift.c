#include <stdio.h>

int main()
{
    // left and right shift of binary
    // 3 << 1 => 11 << 1 => 110 (6)
    printf("3 << 1 = %d\n", 3 << 1);
    // 3 >> 1 => 11 >> 1 => 1 (1)
    // 12 >> 2 => 1100 >> 2 => 11 (3)
    printf("3 >> 1 = %d\n", 3 >> 1);
    printf("12 >> 2 = %d\n", 12 >> 2);
    return 0;

}