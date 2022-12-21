#include <stdio.h>

int main(void)
{
    // 10 => 1010
    // 2 => 10
    // 10 & 2 => 1010 & 0010 => 0010 (2)
    printf("bitwise_and 10 & 2 = %d\n",  10 & 2);
    return 0;
}