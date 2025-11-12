#include <stdio.h>

/* return 0 means equal, >0 means longer than, <0 means shorter than */
int strcmp(char *s, char *t);
int strncmp(int, char *, char *);

int main(void)
{
    char *s1 = "hello";
    char *s2 = "hi";
    int result = strcmp(s1, s2);
    // h is equal, e < i
    if (result > 0)
        printf("s1 > s2\n");
    else if (result < 0)
        printf("s1 < s2\n");
    else
        printf("s1 = s2\n");
    printf("%d\n", strncmp(1, s1, s2));
    return 0;
}

int strcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int strncmp(int n, char *s, char *t)
{
    if (n <= 0) return 0;
    while (n-- > 0){
        if (*s != *t)
            return *s - *t;
        s++;
        t++;
    }
    s--;
    t--;
    return *s - *t;
}