/*
 * Word counting program
 */

#include <stdio.h>

int main(void)
{
    int wc = 0;
    int c;
    printf("Print each word perline and show number of word count\n\n");
    while ((c = getchar()) != EOF)
        if (c == '\n' || c == '\t' || c == ' ') {
            wc++;
            putchar('\n');
        }
        else {
            putchar(c);
        }

    printf("number of word count: %d\n", wc);
    
    return 0;
}
