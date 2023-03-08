#include <stdio.h>

int main(void)
{
    char *s = "testing";
    char *p = s;
    s += 2;
    printf("After point to %ld index: \"%s\"\n", s - p + 1, s);
    return 0;
}