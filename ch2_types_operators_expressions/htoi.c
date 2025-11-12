/*
 * htoi(s): convert a string of hexa decimal digits (including optional 0x or 0X) into its equivalent integer value
 * the allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>

long int htoi(char *s, int len);
long int power(int, int);
long int atoi(char c);

int main(void)
{
    char hex[] = "0xA";
    printf("%s : %ld\n", hex, htoi(hex, sizeof(hex) / sizeof(hex[0]) - 1));
    return 0;
}

long int htoi(char *s, int len)
{
    if (len <= 0)
        return 0;
    int result = 0;
    int minIteration = 0;
    if (s[0] == '0' && len > 1)
    {
        if ((s[1] == 'x' || s[1] == 'X'))
            minIteration = 2;
    }
    else
        minIteration = 0;
    for (int i = len - 1; i >= minIteration; --i)
            result += atoi(s[i]) * power(16, len - 1 - i);
    return result;
}

long int atoi(char c)
{
    if (c <= '9' && c >= '0')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 0;
}

long int power(int base, int n)
{
    int result = 1;
    int num = n >= 0 ? n : -n;
    for (int i = 1; i <= num; i++)
        result *= base;
    if (n < 0)
        result = 1 / result;
    return result;
}