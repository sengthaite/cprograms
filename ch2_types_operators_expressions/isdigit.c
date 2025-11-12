/*
* Check if input is digit
*/

#include <stdio.h>

int is_digit(int d);

int main()
{
    printf("is_digit(2) : %s\n", is_digit('2') ? "true" : "false");
    return 0;
}

int is_digit(int d)
{
    return d >= '0' && d <= '9';
}