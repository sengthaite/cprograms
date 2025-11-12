/*
itob(n, s, b)
=> convert int n to a number base b character representing in the string s
e.g. itob(n, s, 16) format s as a hexadecimal interger in s
*/

#include <stdio.h>
#include <string.h>

void reverse(char *s);
void itob(int n, char *s, unsigned int b);

int main(void)
{
    char bin[1000];
    itob(-56, bin, 2);
    printf("itob(-56, bin, 2) = %s\n", bin);
    return 0;
}

void itob(int n, char *s, unsigned int b)
{
    unsigned int num = n >= 0 ? n : -n;
    int i = 0;
    do {
        s[i++] = num % b + '0';
    } while ((num /= b) > 0);
    if (n < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char *s)
{
    int i, j;
    char tmp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        tmp = s[i], s[i] = s[j], s[j] = tmp;

}