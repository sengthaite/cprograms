/*
* Convert ascii from uppercase to lowercase
*/

#include <stdio.h>

char to_lower(char c);

int main() 
{
    printf("lowercase of G is %c\n", to_lower('G'));
    return 0;
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return c;
}