#include <stdio.h>

void swap(int* first, int* second);

int main(void)
{
    int x = 2, y = 7;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

void swap(int* first, int* second)
{
    int tmp = *first;
    *first = *second;
    *second = tmp;
}