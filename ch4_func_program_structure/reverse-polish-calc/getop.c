/*
* To get operator or operand
*/
#include <stdio.h>
#include <ctype.h> // isdigit
#include "cal.h"

char getop(char s[])
{
    char c;
    int i;
    // ignore white-spaces or tabs
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;

    if (isalpha(c)) {
        while(isalpha(s[++i] = c = getch()))
            ;

        s[i] = '\0';

        if (c != EOF)
            setch(c);

        return VARIABLE;
    }

    // check if c is not operand
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    if (isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if (c == '.' || c == '-')
        while(isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    
    // set the character into buffer
    if (c != EOF)
        setch(c);

    return NUMBER;
}