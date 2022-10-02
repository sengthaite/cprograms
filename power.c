/*
 * Power program
 */

#include <stdio.h>

int power(int base, int exponent);

int main(void)
{
    printf("3^3 = %d", power(3, 3));
    return 0;
}

int power(int base, int exponent)
{
    int result = 1;
    for (int i = exponent-1; result *= base, i > 0; i--);
    return result;
}
