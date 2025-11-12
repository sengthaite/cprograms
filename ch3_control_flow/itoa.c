#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itoa(int n, char s[]);
void itoap(int n, char *s);

int main(void)
{
    char result[1000];
    printf("INT_MAX = %d\n", INT_MAX);
    // itoa(INT_MAX, result);
    // printf("itoa(INT_MAX) = %s\n", result);
    itoap(INT_MAX, result);
    printf("result: %s\n", result);
    return 0;
}

void reverse(char s[])
{
    int c, i, j;
    printf("strlen s = %d\n", strlen(s));
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

void itoa(int n, char s[])
{
    int i;
    unsigned int number = n >= 0 ? n : -n;

    i = 0;
    do {
        s[i++] = number % 10 + '0';
    } while((number /= 10) > 0);

    if (n < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void itoap(int n, char *s) {
    char *p = s;
    int is_negative = 0;
    if (n < 0) {
        n = -n;
        is_negative = 1;
    }
    while (n > 0) {
        *s++ = n % 10 + '0';
        n /= 10;
    }
    if (is_negative)
        *s++ = '-';
    *s = '\0';
    reverse(p);
}