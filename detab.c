/*
Detab: replace tabs in the input with the proper number blanks to space to the next tab stop.
*/

#include <stdio.h>

#define TABLEN 4

int main(void)
{
    int c;
    int pos = 0;
    while((c = getchar()) != EOF)
    {
        if (c != '\t')
        {
            pos = c == '\n' ? 0 : pos + 1;
            putchar(c);
        }
        else
        {
            int tabSpaceLeft = TABLEN - pos % TABLEN;
            pos += tabSpaceLeft;
            for (int i = 0; i < tabSpaceLeft; i++)
                putchar(' ');
        }
    }
    return 0;
}