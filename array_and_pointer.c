#include <stdio.h>

int main(void)
{
    int *p;
    int *j;
    int array[] = {1, 2, 3};
    p = array;
    j = &array[0];
    printf("address of p: %p\n", &p);
    printf("address of j: %p\n", &j);
    if (p == j) {
        printf("same value: %d\n", *p);
    }
    printf("array[2] = %d\n", array[2]);
    printf("*(p+2) = %d\n", *(p + 2));
    return 0;
}