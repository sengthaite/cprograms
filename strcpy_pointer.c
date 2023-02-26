#include <stdio.h>
#define MAXSIZE 1000

void strcpy(char *s, char *t);

int main(void)
{
    char s[MAXSIZE];
    char *t = "What is your name?";
    strcpy(s, t);
    printf("after copied s = %s\n", s);
    return 0;
}

void strcpy(char *s, char *t)
{
    while(*s++ = *t++);
}