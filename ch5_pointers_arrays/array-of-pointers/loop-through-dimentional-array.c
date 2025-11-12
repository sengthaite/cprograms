#include <stdio.h>

int main(void)
{
    int array[2][5] = {
        {1, 2},
        {3, 4}
    };
    char *name[]  = {
        "Illegal month",
        "Jan",
        "Feb",
        "Mar"
    };
    printf("columns of array: %d\n", sizeof(array[0]) / sizeof(int));
    printf("rows of array: %d\n", sizeof(array) / sizeof(array[0]));
    return 0;
}