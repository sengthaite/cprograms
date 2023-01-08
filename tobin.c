/*
* A program convert decimal to binary
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENRESULT 1000

int char_to_int(char *s);
char *to_bin(int);
char *reverse(char *s);

int main()
{
    char input[1000], c;
    int i = 0;
    while((c = getchar()) != EOF) {
        if (c != '\n') {
            input[i++] = c;
        }
    }
    input[i] = '\0';
    int num = char_to_int(input);
    printf("%d to bin: %s\n", num, to_bin(num));
    return 0;
}

int char_to_int(char *s)
{
    int result = 0, mul = 1, len = strlen(s) - 1;
    while (len >= 0) {
        if (s[len] == '-')
            return -result;
        result = (s[len] - '0') * mul + result;
        mul *= 10;
        len--;
    }
    return result;
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