#include <stdio.h>
#define is(t) (t == 0 ? "false" : "true")

// return 1 if string t found at the end of string s
int strend(char *s, char *t);

int main(void)
{
    char *s = "hello wworld";
    char *t = "world";
    int contain = strend(s, t);
    printf("\"%s\" contain \"%s\": %s\n", s, t, is(contain));
    return 0;
}

int strcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int strend(char *s, char *t)
{
    // search for the first occurance of first char of t in s backward
    while(*s++ != '\0')
        if (*s == *t)
            if (strcmp(s, t) == 0)
                return 1;
    return 0;
}