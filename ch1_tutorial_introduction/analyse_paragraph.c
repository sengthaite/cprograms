/*
* A simple program to count words, lines, tabs, and newlines from the input
* ctrl + d: to end the program
*/

#include <stdio.h>

int main(void) 
{
    int isStillInWord, c, wc, nl, nt, nc;
    isStillInWord = wc = nt = nc = 0;
    nl = 1;

    while((c = getchar()) != EOF)
    {
        int isChar =  c != '\n' && c != '\t' && c != ' ';
        if (isChar)
            nc++;
            if (!isStillInWord) 
                wc++;
        if (c == '\t')
            nt++;
        if (c == '\n')
            nl++;
        isStillInWord = isChar;
    }

    printf("Number of words: %d\n", wc);
    printf("Number of lines: %d\n", nl);
    printf("Number of tabs: %d\n", nt);
    printf("Number of characters: %d\n", nc);
    printf("Number of whitespaces: %d\n", nt + nl);

    return 0;
}