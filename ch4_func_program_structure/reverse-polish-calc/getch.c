/*
* To get and unget number from input (work with getop)
* e.g. 123 as input
*/

#include <stdio.h>
#include "cal.h"

#define MAXBUF 100

static char buf[MAXBUF];
static int bufp = 0;

char getch()
{
   return bufp > 0 ? buf[bufp--] : getchar();
}

void setch(char ch)
{
    if (bufp >= MAXBUF)
        printf("Error: too many character to hold in buf. max 99\n");
    else
        buf[bufp++] = ch;
}