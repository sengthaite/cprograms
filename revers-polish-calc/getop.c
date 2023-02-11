/*
* To get operator or operand
*/
#include <stdio.h>
#include <ctype.h> // isdigit

char getop(char s[])
{
    char c;
    int i;
    // ignore white-spaces or tabs
    while((c = getch()) == ' ' || c == '\t')
        ;
    // check if c is not operand
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    
    // set the character into buffer
    if (c != EOF)
        setch(c);
}