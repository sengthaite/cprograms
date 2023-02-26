#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 1000
char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
float getfloat(float *pn);

int main(void)
{
    float num;
    getfloat(&num);
    printf("num = %f\n", num);
    return 0;
}

float getfloat(float *pn)
{
    int c;
    float sign;
    float dividebyten = 1;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    if (c == '.' || dividebyten > 1)
            dividebyten *= 10;
    sign = (c == '-') ? -1.0 : 1.0;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c) || c == '.'; c = getch()) {
        if (isdigit(c))
            *pn = (dividebyten > 1 ? 1 : 10) * *pn + ((c - '0') / dividebyten);
        if (c == '.' || dividebyten > 1)
            dividebyten *= 10;
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("error: too many characters\n");
    else
        buf[bufp++] = c;
}