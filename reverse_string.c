#include <stdio.h>
#define MAXLINE 1000

void reversep(char *s);

int main(void)
{
    int c, i = 0;
    char line[MAXLINE];
    while((c = getchar()) != EOF)
    {
        line[i] = c;
        ++i;
    }
    for (int j = i-1; j>=0; j--)
        putchar(line[j]);
    return 0; 
}

// void reversep(char *s)
// {
//     char *p = s;
//     char *q = (char *)(&)
// }