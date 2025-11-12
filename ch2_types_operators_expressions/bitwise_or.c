#include <stdio.h>

int main()
{
    // Inclusive OR
    // 2 | 3
    // 2 => 10
    // 3 => 11
    // 2 | 3 => 10 | 11 => 11 (3)
    printf("2 | 3 = %d\n", 2 | 3);

    // Exclusive OR
    // 2 ^ 3
    // 2 ^ 3 => 10 ^ 11 => 01 (1)
    printf("2 ^ 3 = %d\n", 0x2 ^ 3);
    return 0;
}