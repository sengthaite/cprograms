/*
* A program convert decimal to binary
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLENRESULT 1000

char *to_bin(int);
char *reverse(char *s);

int main()
{
    int c;
    int decimal = 128;
    printf("%d to bin: %s\n", decimal, to_bin(decimal));
    return 0;
}

char *to_bin(int num)
{
    int c, i;
    int tmp = num;
    char *s = (char *)malloc(MAXLENRESULT);
    i = 0;
    while(tmp > 0)
    {
        s[i] = tmp % 2 + '0';
        tmp /= 2;
        ++i;
    }
    s[i] = '\0';
    s = reverse(s);
    return s;
}

char *reverse(char *s) {
    int i = 0;
    while(s[i] != '\0')
        i++;
    // reverse by swap
    int middle = i / 2;
    char tmp;
    for (int j = 0; j < middle; ++j)
    {
        tmp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = tmp;
    }
    return s;
}