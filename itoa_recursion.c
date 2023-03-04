#include <stdio.h>
#define MAXCHAR 1000

char* itoa(int num);

int main(void)
{
    printf("final result: %s\n", itoa(-1234567890));
    return 0;
}

char* itoa(int num)
{
    static int i = 0;
    static char result[MAXCHAR];

    if (num < 0) {
        result[i++] = '-';
        num = -num;
    }
    if (num / 10) 
        itoa(num / 10);
    result[i++] = num % 10 + '0';
    result[i] = '\0';
    return result;
}