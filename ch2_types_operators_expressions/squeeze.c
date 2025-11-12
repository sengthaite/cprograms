/*
* Delete all c from s
*/

#include <stdio.h>

void squeeze(char s[], char c);

int main()
{
    char s[] = "this is some example.";
    squeeze(s, 's');
    squeeze(s, 't');
    printf("Final result: %s\n", s);
    return 0;
}

void squeeze(char s[], char c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i]; // auto increment j
    s[j] = '\0';
}