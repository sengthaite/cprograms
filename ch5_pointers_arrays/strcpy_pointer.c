#include <stdio.h>
#define MAXSIZE 1000

void strcpy(char *s, char *t);
void strncpy(int, char *s, char *t);

int main(void)
{
    char s[MAXSIZE];
    char ns[MAXSIZE];
    char *t = "What is your name?";
    strcpy(s, t);
    strncpy(4, ns, t);
    printf("after copied s = %s\n", s);
    printf("copy %d char from t to ns, result: %s\n", 4, ns);
    return 0;
}

void strcpy(char *s, char *t)
{
    while(*s++ = *t++);
}

void strncpy(int l, char *s, char * t)
{
    while (l-- > 0)
        *s++ = *t++;
}