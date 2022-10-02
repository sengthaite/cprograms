/* 
 * A program to replace blank spaces with a sigle blank space from its input
 */

#include <stdio.h>

int main(void)
{
    int numSpace = 0;
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ')
        {
            numSpace++;
        }
        else {
            numSpace = 0;
        }
        if (numSpace <= 1)
        {
            putchar(c);
        }
    }

    return 0;
}
