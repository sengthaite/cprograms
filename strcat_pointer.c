#include <stdio.h>

void strcat(char *s, char *t);
void strncat(int, char *, char *);

int main(void)
{
    char s[1000] = "hello";
    char u[1000] = "";
    char *t = " world";
    strcat(s, t);
    strncat(4, u, t);
    printf("after concat: %s\n", s);
    printf("cat 4 chars from t to end of u, result: %s\n", u);
    return 0;
}

void strcat(char *s, char *t)
{
    while(*s != '\0')
        s++;
    while(*s++ = *t++);
}

void strncat(int n, char *s, char *t)
{
    while(*s != '\0')
        s++;
    while(n-- > 0)
        *s++ = *t++;
    *s = '\0';
}