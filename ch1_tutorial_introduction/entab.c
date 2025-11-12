/*
 * Entab program to replace spaces with tabs and spaces.
 */

#include <stdio.h>

#define TABSTOP 4

int main()
{
    int c;
    int numSpaceInput = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            numSpaceInput++;
            if (numSpaceInput == TABSTOP)
            {
                putchar('#');
                numSpaceInput = 0;
            }
        }
        else
        {
            if (numSpaceInput > 0)
            {
                while (numSpaceInput > 0)
                {
                    putchar(' ');
                    numSpaceInput--;
                }
            }
            if (numSpaceInput == 0)
                putchar(c);
        }
    }
    return 0;
}