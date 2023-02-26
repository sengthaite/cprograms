#include <stdio.h>

void strcat(char *s, char *t);

int main(void)
{
    char s[1000] = "hello";
    char *t = " world";
    strcat(s, t);
    printf("after concat: %s\n", s);
    return 0;
}

void strcat(char *s, char *t)
{
    while(*s != '\0')
        s++;
    while(*s++ = *t++);
}