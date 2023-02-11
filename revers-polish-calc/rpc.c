#include <stdio.h>

#define MAXVAL 100

int main(void)
{
    char c;
    char s[MAXVAL];
    while ((c = getop(s)) != EOF)
    {
        switch (c)
        {
        case '+':
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        default:
            break;
        }
    }
}