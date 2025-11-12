/*
 * A simple program to count digits, whitespaces, and others
 */

#include <stdio.h>

int main(void)
{
    int digits[10], white, other;

    for (int i = 0; i < 10; i++)
        digits[i] = 0;
    white = 0;
    other = 0;

    int c;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t')
            ++white;
        else if (c >= '0' && c <= '9')
            ++digits[c - '0'];
        else
            ++other;

    // print number of digits
    printf("number of digits: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", digits[i]);
    
    printf("\n");
    printf("num whitespace: %d\n", white);
    printf("num others: %d\n", other);

    return 0;
}
