#include <stdio.h>
#include <ctype.h>

#define BUFSIZE  100
char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getint(char* sign_char, int *pn);

int main(void)
{
    int t;
    char sign;
    getint(&sign, &t);
    if (sign)
        printf("%c\n", sign);
    else
        printf("input: %d\n", t);
    return 0;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int ch)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = ch;
}

int getint(char* sign_char, int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        if (!isdigit(c = getch())) {
            *sign_char = sign == -1 ? '-' : '+';
            pn = NULL;
            return 0;
        }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}