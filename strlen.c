/*
* strlen(char s[]): get length of the string
*/

#include <stdio.h>

int strlen(const char s[]);

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    printf("[%s] length is: %d\n", argv[1], strlen(argv[1]));
    return 0;
}

int strlen(const char s[])
{
    int c, len;
    len = 0;
    while(s[len] != '\0')
        len++;
    return len;
}