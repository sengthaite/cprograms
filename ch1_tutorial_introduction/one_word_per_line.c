#include <stdio.h>

int main(void) 
{
    int c;
    while((c = getchar()) != EOF)
        c == '\t' || c == ' ' ? putchar('\n') : putchar(c);
    return 0;
}