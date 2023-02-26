/*
* Convert string to integer
*/

#include <stdio.h>

int atoi(char s[]);
int _atoi(char *);

int main(int argc, char **argv)
{
    printf("atoi(\"10\") = %d\n", _atoi("10"));
    return 0;
}

int _atoi(char *s)
{
    int n;
    for (n = 0; *s; n = 10 * n  + (*s - '0'), s++)
        ;
    return n;
}

int atoi(char s[])
{
    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n  + (s[i] - '0');
    
    return n;
}