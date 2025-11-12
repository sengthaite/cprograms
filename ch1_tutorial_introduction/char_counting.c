/*
 * Count characters in input
 */

#include <stdio.h>

int main(void)
{
    long nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
    
    return 0;
}
