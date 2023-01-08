#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itoa(int n, char s[], int padding);

int main(void)
{
    char result[1000];
    printf("INT_MIN = %d\n", INT_MIN);
    itoa(INT_MIN, result, 16);
    printf("itoa(INT_MIN) = %s\n", result);
    return 0;
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

void itoa(int n, char s[], int padding)
{
    int i;
    unsigned int number = n >= 0 ? n : -n;

    i = 0;
    do {
        s[i++] = number % 10 + '0';
    } while((number /= 10) > 0);

    if (n < 0)
        s[i++] = '-';

    while(i < padding)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}
