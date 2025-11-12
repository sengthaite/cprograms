#include <stdio.h>
#include <stddef.h>

size_t strlen(char *s);

int main(void)
{
    printf("size of the string \"hello world\" is %zu\n", strlen("hello world"));
    return 0;
}

size_t strlen(char *s)
{
    char *p = s; // point to the first char of the string
    while(*p++ != '\0')
        ;
    return (size_t) (p - s);
}